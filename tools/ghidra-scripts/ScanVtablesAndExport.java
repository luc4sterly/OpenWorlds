import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.mem.MemoryAccessException;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

/**
 * ScanVtablesAndExport
 *
 * Searches .data/.rdata (DGROUP in Watcom) for runs of >=3 consecutive
 * DWORD pointers that fall inside the .text range (vtable candidates),
 * forces createFunction() on every target that is not a function yet, and
 * exports the decompiled C of ONLY the new functions (same format as
 * ExportAllDecompiled.java).
 *
 * Headless usage:
 *   analyzeHeadless <projdir> <projname> -process gamma.dll -noanalysis
 *     -scriptPath <dir> -postScript ScanVtablesAndExport.java <outdir> <textStartHex> <textEndHex>
 *
 * Outputs in <outdir>:
 *   - <addr>_<name>.c     one per new function (same format as the corpus)
 *   - NEW_INDEX.txt       "addr file name" lines (to merge into INDEX.txt)
 *   - report.txt          summary: candidates, already a function, created, failed
 */
public class ScanVtablesAndExport extends GhidraScript {

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 3) {
            println("Usage: ScanVtablesAndExport.java <outdir> <textStartHex> <textEndHex>");
            return;
        }
        String outDir = args[0];
        long textStart = Long.parseLong(args[1], 16);
        long textEnd = Long.parseLong(args[2], 16);
        new File(outDir).mkdirs();

        Memory mem = currentProgram.getMemory();
        Listing listing = currentProgram.getListing();
        FunctionManager fm = currentProgram.getFunctionManager();

        // 1. Scan initialized non-.text blocks for runs of >=3 pointers into .text
        TreeSet<Long> candidateTargets = new TreeSet<Long>();
        List<long[]> runs = new ArrayList<long[]>(); // {runStartOffset, count}

        for (MemoryBlock b : mem.getBlocks()) {
            if (!b.isInitialized()) continue;
            String bn = b.getName();
            // DGROUP: the data of the Watcom executables (gdkup.exe, sfmain.exe)
            if (!(bn.equals(".data") || bn.equals(".rdata") || bn.equals("DGROUP"))) continue;
            if (!b.isRead()) continue;

            int beforeCount = candidateTargets.size();
            Address start = b.getStart();
            Address end = b.getEnd();
            long startOff = start.getOffset();
            long alignedStartOff = (startOff + 3L) & ~3L;
            if (alignedStartOff < startOff) continue;

            List<Long> curRun = new ArrayList<Long>();
            long off = alignedStartOff;
            long endOff = end.getOffset();
            while (off + 3 <= endOff) {
                Address cur = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(off);
                long val;
                try {
                    val = mem.getInt(cur) & 0xFFFFFFFFL;
                } catch (MemoryAccessException e) {
                    // flush run
                    if (curRun.size() >= 3) {
                        candidateTargets.addAll(curRun);
                    }
                    curRun.clear();
                    off += 4;
                    continue;
                }
                boolean inText = val >= textStart && val < textEnd;
                if (inText) {
                    curRun.add(val);
                } else {
                    if (curRun.size() >= 3) {
                        candidateTargets.addAll(curRun);
                    }
                    curRun.clear();
                }
                off += 4;
            }
            if (curRun.size() >= 3) {
                candidateTargets.addAll(curRun);
            }
            println("BLOCK " + bn + " [" + start + "-" + end + "]: new candidates = " + (candidateTargets.size() - beforeCount));
        }

        println("CANDIDATES (unique targets in runs >=3): " + candidateTargets.size());

        // 2. For each candidate that is not a function yet, force disassemble + createFunction
        int alreadyFn = 0, created = 0, failed = 0, skippedMidFn = 0;
        List<Function> newFunctions = new ArrayList<Function>();
        List<Long> failedAddrs = new ArrayList<Long>();

        for (Long valL : candidateTargets) {
            long val = valL.longValue();
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(val);
            Function existing = fm.getFunctionAt(a);
            if (existing != null) {
                alreadyFn++;
                continue;
            }
            Function containing = fm.getFunctionContaining(a);
            if (containing != null) {
                // the pointer lands inside another function's body (not an entry) - don't create
                skippedMidFn++;
                continue;
            }
            try {
                Instruction ins = listing.getInstructionAt(a);
                if (ins == null) {
                    // clear any conflicting data and disassemble
                    try {
                        clearListing(a, a.add(1));
                    } catch (Exception ignore) {
                    }
                    disassemble(a);
                }
                Function f = createFunction(a, null);
                if (f != null) {
                    created++;
                    newFunctions.add(f);
                } else {
                    failed++;
                    failedAddrs.add(val);
                }
            } catch (Exception e) {
                failed++;
                failedAddrs.add(val);
            }
        }

        println("ALREADY FUNCTIONS: " + alreadyFn);
        println("INSIDE ANOTHER FUNCTION (skipped): " + skippedMidFn);
        println("CREATED: " + created);
        println("FAILED: " + failed);

        // 3. Decompile and export ONLY the new ones
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);
        PrintWriter newIndex = new PrintWriter(new File(outDir, "NEW_INDEX.txt"));
        int n = 0, decompFailed = 0;
        // sort by address
        newFunctions.sort(new Comparator<Function>() {
            public int compare(Function f1, Function f2) {
                return f1.getEntryPoint().compareTo(f2.getEntryPoint());
            }
        });
        for (Function f : newFunctions) {
            if (monitor.isCancelled()) break;
            String c = null;
            try {
                DecompileResults res = decomp.decompileFunction(f, 60, monitor);
                if (res != null && res.getDecompiledFunction() != null) {
                    c = res.getDecompiledFunction().getC();
                }
            } catch (Exception e) {
                c = null;
            }
            String addr = f.getEntryPoint().toString();
            String safeName = f.getName().replaceAll("[^A-Za-z0-9_.$]", "_");
            if (safeName.length() > 80) {
                safeName = safeName.substring(0, 80);
            }
            String fname = addr.replace(':', '_') + "_" + safeName + ".c";
            PrintWriter w = new PrintWriter(new File(outDir, fname));
            w.println("// " + addr + " " + f.getName() + " [" + f.getParentNamespace() + "]");
            w.println("// program: " + currentProgram.getName());
            if (c != null) {
                w.println(c);
            } else {
                w.println("// DECOMPILE FAILED");
                decompFailed++;
            }
            w.close();
            newIndex.println(addr + " " + fname + " " + f.getName());
            n++;
        }
        newIndex.close();
        decomp.dispose();

        println("EXPORTED " + n + " new functions (decompile failures " + decompFailed + ")");

        // 4. report.txt
        PrintWriter rep = new PrintWriter(new File(outDir, "report.txt"));
        rep.println("candidates=" + candidateTargets.size());
        rep.println("already_function=" + alreadyFn);
        rep.println("skipped_inside_another_function=" + skippedMidFn);
        rep.println("created=" + created);
        rep.println("failed=" + failed);
        rep.println("exported=" + n);
        rep.println("decompile_failed=" + decompFailed);
        rep.println("--- addresses where creating a function failed ---");
        for (Long v : failedAddrs) {
            rep.println(String.format("%08x", v));
        }
        // gamma.dll's own check (the animation player's vtable)
        if (currentProgram.getName().equalsIgnoreCase("gamma.dll")) {
            rep.println("--- the 13 entries of the vtable at 0x00475200 ---");
            long[] vt = {0x00432010L,0x00431e90L,0x00432020L,0x00432070L,0x00432090L,0x004320b0L,
                         0x00432550L,0x00432790L,0x004327b0L,0x00432800L,0x00432820L,0x00432830L,0x00432840L};
            for (long v : vt) {
                Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(v);
                Function f = fm.getFunctionAt(a);
                rep.println(String.format("%08x", v) + " -> " + (f != null ? ("function OK: " + f.getName()) : "STILL NOT A FUNCTION"));
            }
        }
        rep.close();

        println("DONE");
    }
}
