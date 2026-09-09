package net.freeworlds.rwg;

import java.util.ArrayList;
import java.util.List;

/**
 * Parsed .rwg file: object name from the header, the single top-level
 * ATOM found so far (⚠️ VERIFICAR - no real sample demonstrates more than
 * one ATOM per file / any nesting), and the raw undeciphered RALT/TELT/
 * MALT chunk bytes kept for future analysis rather than discarded.
 */
public final class RwgModel {
   public final String name;
   public final RwgAtom atom;
   /** Raw bytes of RALT/TELT/MALT payloads, undeciphered - see docs/rwg-bod-format-reference.md. */
   public final byte[] raltRaw;
   public final byte[] teltRaw;
   public final byte[] maltRaw;
   public final List<String> warnings = new ArrayList<>();

   public RwgModel(String name, RwgAtom atom, byte[] raltRaw, byte[] teltRaw, byte[] maltRaw) {
      this.name = name;
      this.atom = atom;
      this.raltRaw = raltRaw;
      this.teltRaw = teltRaw;
      this.maltRaw = maltRaw;
   }
}
