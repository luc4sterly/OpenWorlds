package net.freeworlds.avatar;

import java.util.ArrayList;
import java.util.List;

/** Resultado de decodificar un nombre de avatar (ver AvatarNameDecoder). */
public final class AvatarFigure {
   /** URL pedida, p.ej. "avatar:aura.rwg". */
   public String urlPedida;
   /** Cadena efectivamente parseada (la de permittedList si hubo traduccion). */
   public String cadena;
   /** La misma cadena despues de que findStarts sustituya los tokens C/T por Q<letra>. */
   public String cadenaReescrita;
   /** Nombre base del avatar (el que se usa para los .bod de la raiz). */
   public String base;
   /** true si el nombre pedido se resolvio via permittedHash. */
   public boolean desdePermittedList;
   /** Posicion de arranque de cada letra A..Z (0 = ausente), tal cual findStarts. */
   public final int[] arranques = new int[26];
   public final List<AvatarMaterial> paleta = new ArrayList<>();
   /** Todas las limbs intentadas, en el orden de createSubparts. */
   public final List<AvatarPart> partes = new ArrayList<>();
   /** Anomalias: tokens que el cliente trata como ilegales o fuera de rango. */
   public final List<String> anomalias = new ArrayList<>();
   /** Letras de arranque que createSubparts nunca consume (bloques de paleta u ornamentales). */
   public final List<Character> letrasNoUsadas = new ArrayList<>();
   /** false cuando aparece un `SZZZ` (PosableShape.java:390-392). */
   public boolean prepFigure = true;

   public List<AvatarPart> partesAdjuntas() {
      List<AvatarPart> out = new ArrayList<>();
      for (AvatarPart p : partes) {
         if (p.adjunta) {
            out.add(p);
         }
      }
      return out;
   }
}
