package net.freeworlds.world;

import java.io.File;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * TextureActions: cadencia de AnimateAction.trigger con casos a mano, una
 * secuencia sintetica StartupSensor -> SequenceAction(Wait, Animate) y los
 * datos reales de GroundZero. Sale con 1 si algo falla.
 */
public final class TextureActionsCheck {
   private static int failures = 0;

   public static void main(String[] args) throws Exception {
      // AnimateAction.trigger: k = count*t/cycleTime (long), ciclo = k/count,
      // frame = k - ciclo*count; sin bucle, a partir de cycles -> ultimo.
      // Bandera de ReceptionView1: 8 frames, 1000 ms, infinita.
      eq("bandera t=0", TextureActions.frameAt(8, 1000, 0, true, 0), 0);
      eq("bandera t=124", TextureActions.frameAt(8, 1000, 0, true, 124), 0); // 992/1000 = 0
      eq("bandera t=125", TextureActions.frameAt(8, 1000, 0, true, 125), 1); // 1000/1000 = 1
      eq("bandera t=999", TextureActions.frameAt(8, 1000, 0, true, 999), 7); // 7992/1000 = 7
      eq("bandera t=1000", TextureActions.frameAt(8, 1000, 0, true, 1000), 0); // k=8, ciclo 1
      eq("bandera t=2437", TextureActions.frameAt(8, 1000, 0, true, 2437), 3); // k=19 -> 19-16
      // Cartel del probador: 2 frames, 6000 ms -> cambia cada 3 s.
      eq("cartel t=2999", TextureActions.frameAt(2, 6000, 0, true, 2999), 0);
      eq("cartel t=3000", TextureActions.frameAt(2, 6000, 0, true, 3000), 1);
      // Kiosko: 5 frames, 500 ms, 1 ciclo, sin bucle: 100 ms por frame y
      // al llegar a 500 ms se queda en el ultimo.
      eq("kiosko t=99", TextureActions.frameAt(5, 500, 1, false, 99), 0);
      eq("kiosko t=100", TextureActions.frameAt(5, 500, 1, false, 100), 1);
      eq("kiosko t=499", TextureActions.frameAt(5, 500, 1, false, 499), 4);
      eq("kiosko t=500", TextureActions.frameAt(5, 500, 1, false, 500), 4);
      eq("kiosko t=10000", TextureActions.frameAt(5, 500, 1, false, 10000), 4);
      // Sin periodo: ciclo 1e9 -> sin bucle, ultimo frame; con bucle, 0.
      eq("cycleTime 0 sin bucle", TextureActions.frameAt(3, 0, 1, false, 50), 2);
      eq("cycleTime 0 con bucle", TextureActions.frameAt(3, 0, 1, true, 50), 0);

      synthetic();
      groundZero();

      if (failures > 0) {
         System.out.println("TextureActionsCheck: " + failures + " fallos");
         System.exit(1);
      }
      System.out.println("TextureActionsCheck: OK");
   }

   /**
    * Rect con StartupSensor -> SequenceAction(bucle infinito: Wait 1 s,
    * Animate "a b" 400 ms 1 ciclo). Linea de tiempo esperada:
    * t=0 espera (sin material puesto); t=1000 acaba la espera y arranca la
    * animacion en el mismo trigger (frame 0 = "a"); t=1200 k = 2*200/400 = 1
    * -> "b"; t=1400 ciclo 1 -> ultimo ("b") y la animacion devuelve null:
    * la lista se acaba, SequenceActionState.run pone currentAct = 0 y
    * devuelve true SIN llamar aun a la espera; esta arranca en el frame
    * siguiente (t=1401, termina en 2401), y en t=2401 la animacion vuelve
    * a "a".
    */
   private static void synthetic() {
      WNode world = new WNode("NET.worlds.scape.World");
      WNode room = new WNode("NET.worlds.scape.Room");
      WNode rect = new WNode("NET.worlds.scape.Rect");
      WNode sensor = new WNode("NET.worlds.scape.StartupSensor");
      WNode seq = new WNode("NET.worlds.scape.SequenceAction");
      WNode wait = new WNode("NET.worlds.scape.WaitAction");
      WNode anim = new WNode("NET.worlds.scape.AnimateAction");
      anim.animFrameList = "a b";
      anim.animCycleTime = 400;
      anim.animCycles = 1;
      anim.animInfiniteLoop = false;
      wait.waitDuration = 1f;
      seq.seqLoopCount = 1;
      seq.seqLoopInfinite = true;
      seq.actions = new ArrayList<>(Arrays.asList(wait, anim));
      sensor.actions = new ArrayList<>(Arrays.asList(seq));
      rect.handlers = new ArrayList<>(Arrays.asList(sensor));
      rect.actions = new ArrayList<>(Arrays.asList(seq, anim));
      rect.matrix = new float[16];
      room.children.add(rect);
      world.roomsByName.put("R", room);
      TextureActions ta = new TextureActions(world);
      ta.startRoom(room, 0);
      eqs("sintetico t=0", ta.materialOverride.get(rect), null);
      ta.tick(999);
      eqs("sintetico t=999", ta.materialOverride.get(rect), null);
      ta.tick(1000);
      eqs("sintetico t=1000", ta.materialOverride.get(rect), "a");
      ta.tick(1199);
      eqs("sintetico t=1199", ta.materialOverride.get(rect), "a");
      ta.tick(1200);
      eqs("sintetico t=1200", ta.materialOverride.get(rect), "b");
      ta.tick(1400);
      eqs("sintetico t=1400", ta.materialOverride.get(rect), "b");
      ta.tick(1401);
      ta.tick(2400);
      eqs("sintetico t=2400", ta.materialOverride.get(rect), "b");
      ta.tick(2401);
      eqs("sintetico t=2401", ta.materialOverride.get(rect), "a");
      eq("sintetico acciones vivas", ta.runningCount(), 1);
      // Un segundo arranque de la sala no vuelve a disparar el sensor.
      ta.startRoom(room, 2500);
      eq("sintetico sensor una sola vez", ta.runningCount(), 1);
   }

   /** Bandera real de ReceptionView1 (Rect840Flag2, AnimateFlag2). */
   private static void groundZero() throws Exception {
      File wf = null;
      File d = new File(".").getAbsoluteFile();
      while (d != null && wf == null) {
         File f = new File(d, "assets/WorldsPlayer/GroundZero/groundzero.world");
         if (f.isFile()) {
            wf = f;
         }
         d = d.getParentFile();
      }
      if (wf == null) {
         failures++;
         System.out.println("FALLO no encuentro assets/WorldsPlayer/GroundZero/groundzero.world");
         return;
      }
      WNode world = WorldRestorer.parse(Files.readAllBytes(wf.toPath()));
      WNode room = world.roomsByName.get("ReceptionView1");
      TextureActions ta = new TextureActions(world);
      ta.startRoom(room, 0);
      WNode flag = null;
      for (WNode n : ta.materialOverride.keySet()) {
         if ("Rect840Flag2".equals(n.name)) {
            flag = n;
         }
      }
      if (flag == null) {
         failures++;
         System.out.println("FALLO Rect840Flag2 sin material animado tras el arranque");
         return;
      }
      eqs("bandera real t=0", ta.materialOverride.get(flag), "tex/f12h*.mov");
      ta.tick(125);
      eqs("bandera real t=125", ta.materialOverride.get(flag), "tex/f22h*.mov");
      ta.tick(1000 + 7 * 125);
      eqs("bandera real t=1875", ta.materialOverride.get(flag), "tex/f82h*.mov");
      // Los 4 kioscos de Reception: StartupSensor -> SequenceAction con
      // Wait/Animate; todos soportados, ninguno omitido.
      TextureActions tr = new TextureActions(world);
      tr.startRoom(world.roomsByName.get("Reception"), 0);
      eq("Reception acciones vivas", tr.runningCount(), 4);
   }

   private static void eq(String what, int got, int want) {
      if (got != want) {
         failures++;
         System.out.println("FALLO " + what + ": " + got + " (esperado " + want + ")");
      }
   }

   private static void eqs(String what, String got, String want) {
      if (want == null ? got != null : !want.equals(got)) {
         failures++;
         System.out.println("FALLO " + what + ": " + got + " (esperado " + want + ")");
      }
   }
}
