package net.freeworlds.launcher;

import javax.swing.BorderFactory;
import javax.swing.JCheckBox;
import javax.swing.JComponent;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import java.awt.BorderLayout;
import java.awt.Dialog;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/** Ajustes: the options that are not about what to play (drawing threads, content mirror, updates). */
final class SettingsDialog {
   private SettingsDialog() {
   }

   static void open(JFrame owner, Layout layout, Settings settings, Updater updater) {
      JDialog d = new JDialog(owner, "Ajustes", Dialog.ModalityType.APPLICATION_MODAL);
      SpaceBackground root = new SpaceBackground(new BorderLayout(0, 14), false);
      root.setBorder(BorderFactory.createEmptyBorder(20, 24, 16, 24));
      root.add(Ui.text("Ajustes", Theme.bold(24f), Theme.TEXT), BorderLayout.NORTH);

      Ui.Stepper threads = new Ui.Stepper(settings.rasterThreads, 64, "Auto");
      JCheckBox mirror = Ui.check("Descargar de us1.worlds.net los mundos y avatares que falten");
      mirror.setSelected(settings.mirror);
      JCheckBox auto = Ui.check("Buscar actualizaciones al abrir FreeWorlds");
      auto.setSelected(settings.autoUpdate);
      JCheckBox pre = Ui.check("Recibir también las versiones de prueba");
      pre.setSelected(settings.prerelease);
      Ui.Secret token = new Ui.Secret(24, "token de solo lectura");
      token.setText(settings.githubToken);
      JLabel updateState = Ui.text(" ", Theme.regular(12f), Theme.MUTED);
      Ui.Pill checkNow = new Ui.Pill("Buscar ahora", new Ui.Glyph(Ui.Glyph.Kind.REFRESH, 12), Ui.Pill.Kind.QUIET, 12.5f);

      Runnable apply = () -> {
         settings.rasterThreads = threads.get();
         settings.mirror = mirror.isSelected();
         settings.autoUpdate = auto.isSelected();
         settings.prerelease = pre.isSelected();
         settings.githubToken = new String(token.getPassword()).trim();
         settings.save(layout.settingsFile);
      };

      JPanel cards = new JPanel(new GridBagLayout());
      cards.setOpaque(false);
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.weightx = 1;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.gridy = 0;

      Ui.Card game = section("Juego");
      add(game, row(Ui.text("Hilos de dibujo", Theme.medium(13f), Theme.TEXT), threads), 0);
      add(game, note("El puente dibuja por software: más hilos dan más fotogramas en ventanas grandes."), 2);
      add(game, mirror, 12);
      add(game, note("Sin esto solo está GroundZero: el resto de mundos y el vestuario vienen del espejo de LibreWorlds."), 2);
      cards.add(game, c);

      Ui.Card upd = section("Actualizaciones");
      add(upd, auto, 0);
      add(upd, pre, 8);
      add(upd, row(Ui.text("Token de GitHub", Theme.medium(13f), Theme.TEXT), token), 12);
      add(upd, note("Solo mientras el repositorio sea privado: un token «fine-grained» con permiso de solo lectura "
         + "(Contents: Read) sobre él. Se guarda en la carpeta de datos."), 2);
      add(upd, row(checkNow, updateState), 12);
      c.gridy++;
      c.insets = new Insets(12, 0, 0, 0);
      cards.add(upd, c);

      JLabel about = Ui.text("FreeWorlds " + Layout.versionLong() + " · Java " + System.getProperty("java.version")
         + " · " + System.getProperty("os.name"), Theme.regular(11f), Theme.FAINT);
      c.gridy++;
      c.insets = new Insets(12, 4, 0, 0);
      cards.add(about, c);
      root.add(cards, BorderLayout.CENTER);

      JPanel buttons = new JPanel(new FlowLayout(FlowLayout.RIGHT, 8, 0));
      buttons.setOpaque(false);
      Ui.Pill done = new Ui.Pill("Listo", null, Ui.Pill.Kind.PRIMARY, 13.5f);
      buttons.add(done);
      root.add(buttons, BorderLayout.SOUTH);

      Updater.Listener listener = s -> SwingUtilities.invokeLater(() -> {
         updateState.setText(Updater.describe(s).isEmpty() ? " " : Updater.describe(s));
         updateState.setForeground(s.phase == Updater.Phase.FAILED ? Theme.ERROR : Theme.MUTED);
         boolean working = s.phase == Updater.Phase.CHECKING || s.phase == Updater.Phase.DOWNLOADING;
         checkNow.setEnabled(s.phase != Updater.Phase.DISABLED && !working);
      });
      updater.addListener(listener);
      checkNow.addActionListener(e -> {
         apply.run();
         updater.checkInBackground(true);
      });
      Runnable close = () -> {
         apply.run();
         updater.removeListener(listener);
         d.dispose();
      };
      done.addActionListener(e -> close.run());
      d.setDefaultCloseOperation(JDialog.DO_NOTHING_ON_CLOSE);
      d.addWindowListener(new WindowAdapter() {
         @Override
         public void windowClosing(WindowEvent e) {
            close.run();
         }

         @Override
         public void windowOpened(WindowEvent e) {
            done.requestFocusInWindow();
         }
      });
      d.setContentPane(root);
      d.getRootPane().setDefaultButton(done);
      d.pack();
      d.setMinimumSize(d.getSize());
      d.setLocationRelativeTo(owner);
      d.setVisible(true);
   }

   private static Ui.Card section(String title) {
      Ui.Card card = new Ui.Card(new GridBagLayout(), 20);
      card.setBorder(BorderFactory.createEmptyBorder(14, 18, 16, 18));
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.gridy = 0;
      c.weightx = 1;
      c.anchor = GridBagConstraints.WEST;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.insets = new Insets(0, 0, 10, 0);
      card.add(Ui.caption(title), c);
      return card;
   }

   private static void add(Ui.Card card, JComponent comp, int top) {
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.gridy = card.getComponentCount();
      c.weightx = 1;
      c.anchor = GridBagConstraints.WEST;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.insets = new Insets(top, 0, 0, 0);
      card.add(comp, c);
   }

   private static JPanel row(JComponent a, JComponent b) {
      JPanel p = new JPanel(new BorderLayout(12, 0));
      p.setOpaque(false);
      p.add(a, BorderLayout.WEST);
      p.add(b, BorderLayout.CENTER);
      return p;
   }

   private static JComponent note(String text) {
      return new Ui.Note(text, Theme.regular(11.5f), Theme.MUTED, 440);
   }
}
