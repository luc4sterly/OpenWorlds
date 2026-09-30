package net.openworlds.launcher;

import net.openworlds.injector.Patch;
import net.openworlds.ui.SpaceBackground;
import net.openworlds.ui.Theme;
import net.openworlds.ui.Ui;

import javax.swing.BorderFactory;
import javax.swing.JCheckBox;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Desktop;
import java.awt.Dialog;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;

/**
 * J Worlds Injector: the patches to build into the game, grouped by what
 * they change. The encrypted-connection patch is not listed: the
 * "Encrypted connection" tick of an online server turns it on.
 */
final class PatchesDialog {
   private PatchesDialog() {
   }

   /** Shows the dialog; returns true if the choice changed. */
   static boolean open(JFrame owner, Layout layout, Settings settings) {
      JDialog d = new JDialog(owner, "Patches", Dialog.ModalityType.APPLICATION_MODAL);
      SpaceBackground root = new SpaceBackground(new BorderLayout(0, 14), false);
      root.setBorder(BorderFactory.createEmptyBorder(20, 24, 16, 24));
      JPanel head = new JPanel(new BorderLayout(0, 4));
      head.setOpaque(false);
      head.add(Ui.text("J Worlds Injector", Theme.bold(24f), Theme.TEXT), BorderLayout.NORTH);
      head.add(new Ui.Note("Patches change the 2004 game. The ones you tick are built into it the next time you press Play "
         + "(a few seconds the first time).", Theme.regular(12f), Theme.MUTED, 470), BorderLayout.CENTER);
      root.add(head, BorderLayout.NORTH);

      List<String> on = new ArrayList<>(Arrays.asList(settings.patches.split(",")));
      on.removeIf(String::isEmpty);
      Map<String, List<Patch>> byCategory = new LinkedHashMap<>();
      for (Patch p : Patch.all(Session.userPatches(layout))) {
         if (!p.id.equals("tls")) {
            byCategory.computeIfAbsent(p.category, k -> new ArrayList<>()).add(p);
         }
      }
      Map<String, JCheckBox> boxes = new LinkedHashMap<>();
      JPanel list = new Ui.ScrollPanel(new GridBagLayout());
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.weightx = 1;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.gridy = 0;
      for (Map.Entry<String, List<Patch>> e : byCategory.entrySet()) {
         Ui.Card card = new Ui.Card(new GridBagLayout(), 20);
         card.setBorder(BorderFactory.createEmptyBorder(12, 16, 14, 16));
         GridBagConstraints k = new GridBagConstraints();
         k.gridx = 0;
         k.weightx = 1;
         k.fill = GridBagConstraints.HORIZONTAL;
         k.anchor = GridBagConstraints.WEST;
         k.gridy = 0;
         card.add(Ui.caption(e.getKey()), k);
         for (Patch p : e.getValue()) {
            JCheckBox box = Ui.check(p.name + (p.builtIn ? "" : "  (yours)"));
            box.setSelected(on.contains(p.id));
            boxes.put(p.id, box);
            k.gridy++;
            k.insets = new Insets(10, 0, 0, 0);
            card.add(box, k);
            k.gridy++;
            k.insets = new Insets(2, 30, 0, 0);
            card.add(new Ui.Note(p.description, Theme.regular(11.5f), Theme.MUTED, 420), k);
         }
         c.insets = new Insets(c.gridy == 0 ? 0 : 10, 0, 0, 0);
         list.add(card, c);
         c.gridy++;
      }
      if (boxes.isEmpty()) {
         list.add(Ui.text("No patches found.", Theme.regular(13f), Theme.MUTED), c);
      }
      root.add(Ui.scroll(list), BorderLayout.CENTER);

      JPanel buttons = new JPanel(new BorderLayout());
      buttons.setOpaque(false);
      Ui.Ghost folder = new Ui.Ghost("My patches folder", new Ui.Glyph(Ui.Glyph.Kind.FOLDER, 14));
      folder.setToolTipText(Session.userPatches(layout).getPath());
      folder.addActionListener(e -> openFolder(owner, Session.userPatches(layout)));
      buttons.add(folder, BorderLayout.WEST);
      JPanel right = new JPanel(new FlowLayout(FlowLayout.RIGHT, 8, 0));
      right.setOpaque(false);
      Ui.Pill done = new Ui.Pill("Done", null, Ui.Pill.Kind.PRIMARY, 13.5f);
      right.add(done);
      buttons.add(right, BorderLayout.EAST);
      root.add(buttons, BorderLayout.SOUTH);

      String before = settings.patches;
      done.addActionListener(e -> d.dispose());
      d.setContentPane(root);
      d.getRootPane().setDefaultButton(done);
      d.pack();
      d.setSize(new Dimension(Math.max(560, d.getWidth()), Math.min(Math.max(420, d.getHeight()), 640)));
      d.setLocationRelativeTo(owner);
      d.setVisible(true);

      List<String> chosen = new ArrayList<>();
      for (Map.Entry<String, JCheckBox> e : boxes.entrySet()) {
         if (e.getValue().isSelected()) {
            chosen.add(e.getKey());
         }
      }
      // keep ids of patches that are not listed (e.g. a user patch that was removed): they are ignored anyway
      settings.patches = String.join(",", chosen);
      settings.save(layout.settingsFile);
      return !settings.patches.equals(before);
   }

   /** The names of the chosen patches for the card ("VIP, Walk faster"), or "". */
   static String summary(Layout layout, Settings settings) {
      List<String> names = new ArrayList<>();
      for (Patch p : Patch.pick(Patch.all(Session.userPatches(layout)), settings.patches)) {
         if (!p.id.equals("tls")) {
            names.add(p.name);
         }
      }
      return String.join(", ", names);
   }

   private static void openFolder(JFrame owner, File dir) {
      dir.mkdirs();
      File readme = new File(dir, "README.txt");
      if (!readme.exists()) {
         try {
            Files.write(readme.toPath(), ("Your own J Worlds Injector patches: one folder per patch, with\n"
               + "  patch.properties   name=..., description=..., category=...\n"
               + "  *.diff             unified diffs (diff -u) against the game's source as the\n"
               + "                     OpenWorlds bridge builds it (worldsplayer-src.zip in the\n"
               + "                     app's lib folder), applied in file name order.\n"
               + "See injector/patches in the OpenWorlds repository for examples.\n").getBytes(StandardCharsets.UTF_8));
         } catch (IOException e) {
            // the folder opens anyway
         }
      }
      try {
         Desktop.getDesktop().open(dir);
      } catch (Exception e) {
         Ui.ask(owner, "My patches folder", dir.getPath(), "OK", null);
      }
   }
}
