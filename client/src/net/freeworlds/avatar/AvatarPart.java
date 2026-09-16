package net.freeworlds.avatar;

import java.util.ArrayList;
import java.util.List;

/**
 * Una "limb" del avatar: lo que PosableShape.getLimb
 * (PosableShape.java:355-470) crea por cada letra de articulacion.
 *
 * createSubparts (PosableShape.java:1091-1108) llama a getLimb 17 veces
 * con (letra, tag, padre) fijos; el tag va al nombre del .bod:
 * "avatar:" + base + tag/10 + tag%10 + ".bod" (PosableShape.java:361).
 * El fichero que se carga de verdad NO lleva los dos digitos:
 * Shape.addRwChildren usa Shape.getBodBase (Shape.java:270-274) para
 * quitarlos, y Shape.getBodPartNum (Shape.java:276-280) usa el numero
 * como identificador de la parte dentro del .bod.
 *
 * Dentro de una limb, los digitos crean SubclumpShape
 * ("system:subclump<n>", PosableShape.java:440-447): cada subclump es un
 * nodo mas con su propio material y sus propios cambios temporizados.
 */
public final class AvatarPart {
   /** Un cambio de material programado en el tiempo (PosableShape.addChange:472-492). */
   public static final class Cambio {
      public final int cuandoMs;
      public final int material;

      Cambio(int cuandoMs, int material) {
         this.cuandoMs = cuandoMs;
         this.material = material;
      }
   }

   /** La limb en si o uno de sus subclumps: cualquier cosa a la que se le pone material. */
   public static final class Nodo {
      /** "limb" o "subclump <n>". */
      public final String tipo;
      /** Indice tal cual aparece en el nombre (-1 para la limb). */
      public int subAbsoluto = -1;
      /**
       * Indice relativo que acaba en la URL: scanInt - subclumps ya creados
       * (PosableShape.java:441). Es relativo porque Shape.extractSubclump
       * (Shape.addRwChildren, Shape.java:286-301) va sacando los subclumps
       * del clump padre segun se piden, asi que la numeracion se desplaza.
       */
      public int subRelativo = -1;
      /** URL que el cliente le asigna (avatar:*.bod o system:subclump<n>). */
      public String url;
      /** Indice del ultimo material aplicado con setMaterial, -1 si ninguno. */
      public int material = -1;
      public float escalaX = 1.0F;
      public float escalaY = 1.0F;
      public float escalaZ = 1.0F;
      /** Secuencia completa de materiales referenciados, en orden. */
      public final List<Integer> materiales = new ArrayList<>();
      /** Cambios temporizados (expresiones faciales). */
      public final List<Cambio> cambios = new ArrayList<>();

      Nodo(String tipo, String url) {
         this.tipo = tipo;
         this.url = url;
      }
   }

   public final char letra;
   public final int tag;
   public final char letraPadre;
   /** Nombre base con el que arranco la limb (heredado del padre si no habia G). */
   public String base;
   /** true si la limb se llego a anadir al arbol; false si getLimb devolvio el padre. */
   public boolean adjunta;
   /** Motivo de descarte cuando adjunta == false. */
   public String motivoDescarte;
   /** Nombre de animacion del token `A`, si lo hubo. */
   public String animacion;
   public final List<Nodo> nodos = new ArrayList<>();

   AvatarPart(char letra, int tag, char letraPadre) {
      this.letra = letra;
      this.tag = tag;
      this.letraPadre = letraPadre;
   }

   public Nodo limb() {
      return nodos.get(0);
   }

   /** URL .bod de la limb, tal cual la pone el cliente. */
   public String bodUrl() {
      return limb().url;
   }

   /** Fichero real: Shape.getBodBase quita los dos digitos y anade ".bod". */
   public String bodFile() {
      String url = bodUrl();
      if (url == null || !url.endsWith(".bod")) {
         return null;
      }
      String name = url.startsWith("avatar:") ? url.substring(7) : url;
      return name.length() >= 6 ? name.substring(0, name.length() - 6) + ".bod" : null;
   }

   /** Numero de parte dentro del .bod (Shape.getBodPartNum). */
   public int bodPartNum() {
      String url = bodUrl();
      if (url == null || !url.endsWith(".bod") || url.length() < 6) {
         return 0;
      }
      char d0 = url.charAt(url.length() - 6);
      char d1 = url.charAt(url.length() - 5);
      return (d0 - '0') * 10 + (d1 - '0');
   }
}
