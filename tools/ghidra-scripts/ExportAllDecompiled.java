import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import java.io.File;
import java.io.PrintWriter;

/**
 * ExportAllDecompiled — dumps the decompiled C of ALL the program's
 * functions to <outdir>/<addr>_<name>.c + INDEX.txt.
 *
 * Headless usage:
 *   analyzeHeadless <projdir> <projname> -import <binary>
 *     -scriptPath tools/ghidra-scripts
 *     -postScript ExportAllDecompiled.java <outdir>
 *
 * The C is decompiler output (it does not compile as is: native
 * types/headers are missing); it serves as versionable reverse-engineering
 * source, not as a build. Each file cites its address to cross-check with
 * Ghidra.
 */
public class ExportAllDecompiled extends GhidraScript {
   @Override
   public void run() throws Exception {
      String[] args = getScriptArgs();
      if (args.length < 1) {
         println("Usage: ExportAllDecompiled.java <outdir>");
         return;
      }
      String outDir = args[0];
      new File(outDir).mkdirs();
      DecompInterface decomp = new DecompInterface();
      decomp.openProgram(currentProgram);
      PrintWriter index = new PrintWriter(new File(outDir, "INDEX.txt"));
      index.println("# addr file name");
      FunctionIterator fns = currentProgram.getFunctionManager().getFunctions(true);
      int n = 0, failed = 0;
      while (fns.hasNext()) {
         if (monitor.isCancelled()) {
            break;
         }
         Function f = fns.next();
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
            failed++;
         }
         w.close();
         index.println(addr + " " + fname + " " + f.getName());
         n++;
         if (n % 500 == 0) {
            println("exported " + n + " (failures " + failed + ")");
         }
      }
      index.close();
      decomp.dispose();
      println("TOTAL " + n + " functions, failures " + failed);
   }
}
