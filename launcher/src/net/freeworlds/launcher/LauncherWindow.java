package net.freeworlds.launcher;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultListModel;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.ListCellRenderer;
import javax.swing.ListSelectionModel;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Desktop;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.geom.Ellipse2D;
import java.awt.geom.RoundRectangle2D;
import java.io.File;

/**
 * The launcher's window, dressed as the logo: the planet turning on the
 * left, and on the right what to play (world and server) and the Play button.
 * The session log is not shown (it is still written to logs/ in the data
 * folder, for bug reports and the CI); the footer carries the update status.
 */
final class LauncherWindow {
   static final String LOCAL_WHIRL = "127.0.0.1:6650";
   private static final int SINGLE = 0;
   private static final int WHIRL = 1;
   private static final int OTHER = 2;

   private final Layout layout;
   private final Settings settings;
   private final String[] args;
   private final Updater updater;
   private final JFrame frame = new JFrame("FreeWorlds");
   private final PlanetView planet = new PlanetView(116);
   private final DefaultListModel<Install.World> worldModel = new DefaultListModel<>();
   private final JList<Install.World> worldList = new JList<>(worldModel);
   private final Ui.Segmented server = new Ui.Segmented("Un jugador", "whirl local", "Otro servidor");
   private final Ui.Field host = new Ui.Field(12, "host:puerto");
   private final Ui.Field user = new Ui.Field(10, "tu nombre");
   private final Ui.Note hint = new Ui.Note("", Theme.regular(11.5f), Theme.MUTED, 376);
   private final Ui.Pill play = new Ui.Pill("Jugar", new Ui.Glyph(Ui.Glyph.Kind.PLAY, 15), Ui.Pill.Kind.PRIMARY, 17f);
   private final JLabel gameStatus = Ui.text(" ", Theme.regular(12f), Theme.MUTED);
   private final JLabel updateLabel = Ui.text(" ", Theme.regular(12f), Theme.MUTED);
   private final Ui.Pill updateNow = new Ui.Pill("Reiniciar y actualizar", new Ui.Glyph(Ui.Glyph.Kind.REFRESH, 12),
      Ui.Pill.Kind.PRIMARY, 12f);
   private final Ui.Ghost settingsButton = new Ui.Ghost("Ajustes", new Ui.Glyph(Ui.Glyph.Kind.GEAR, 14));
   private Session running;
   /** From Play until the session ends (the game process may not exist yet). */
   private boolean busy;
   private boolean stoppedByUser;

   private LauncherWindow(Layout layout, Settings settings, String[] args) {
      this.layout = layout;
      this.settings = settings;
      this.args = args.clone();
      this.updater = new Updater(layout, settings);
   }

   static void open(Layout layout, Settings settings, String[] args) {
      SwingUtilities.invokeLater(() -> {
         try {
            UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
         } catch (Exception ignored) {
            // el look por defecto sirve igual: todo lo visible se pinta aqui
         }
         UIManager.put("ToolTip.background", new Color(0x1d, 0x16, 0x4a));
         UIManager.put("ToolTip.foreground", Theme.TEXT);
         UIManager.put("ToolTip.font", Theme.regular(12f));
         UIManager.put("ToolTip.border", BorderFactory.createCompoundBorder(
            BorderFactory.createLineBorder(Theme.CARD_EDGE), BorderFactory.createEmptyBorder(5, 8, 5, 8)));
         new LauncherWindow(layout, settings, args).build();
      });
   }

   private void build() {
      SpaceBackground root = new SpaceBackground(new BorderLayout(0, 10));
      root.setBorder(BorderFactory.createEmptyBorder(18, 26, 12, 26));

      JPanel body = new JPanel(new GridBagLayout());
      body.setOpaque(false);
      GridBagConstraints c = new GridBagConstraints();
      c.gridy = 0;
      c.gridx = 0;
      c.weightx = 1;
      c.weighty = 1;
      c.fill = GridBagConstraints.BOTH;
      body.add(hero(), c);
      c.gridx = 1;
      c.weightx = 0;
      c.insets = new Insets(0, 18, 0, 0);
      body.add(card(), c);
      root.add(body, BorderLayout.CENTER);
      root.add(footer(), BorderLayout.SOUTH);

      frame.setContentPane(root);
      frame.getRootPane().setDefaultButton(play);
      java.net.URL icon = LauncherWindow.class.getResource("icon.png");
      if (icon != null) {
         frame.setIconImage(new javax.swing.ImageIcon(icon).getImage());
      }
      frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
      frame.addWindowListener(new WindowAdapter() {
         @Override
         public void windowClosing(WindowEvent e) {
            quit();
         }

         @Override
         public void windowIconified(WindowEvent e) {
            planet.setPaused(true);
         }

         @Override
         public void windowDeiconified(WindowEvent e) {
            planet.setPaused(running != null && running.isRunning());
         }
      });
      frame.setMinimumSize(new Dimension(880, 600));
      frame.setSize(new Dimension(960, 640));
      frame.setLocationRelativeTo(null);
      frame.setVisible(true);
      worldList.requestFocusInWindow();

      updater.addListener(s -> SwingUtilities.invokeLater(() -> showUpdate(s)));
      if (settings.autoUpdate) {
         updater.checkInBackground(false);
      }
   }

   // ------------------------------------------------------------ columnas

   private JComponent hero() {
      JPanel hero = new JPanel();
      hero.setOpaque(false);
      hero.setLayout(new BoxLayout(hero, BoxLayout.Y_AXIS));
      hero.add(Box.createVerticalGlue());
      planet.setAlignmentX(Component.CENTER_ALIGNMENT);
      hero.add(planet);
      Ui.Wordmark title = new Ui.Wordmark(46f);
      title.setAlignmentX(Component.CENTER_ALIGNMENT);
      hero.add(title);
      hero.add(Box.createVerticalStrut(2));
      hero.add(centered(Ui.text("Worlds Chat · WorldsPlayer, 1995–2004", Theme.medium(15f), Theme.MUTED)));
      hero.add(Box.createVerticalStrut(4));
      hero.add(centered(Ui.text("El cliente original, preservado y jugable hoy", Theme.regular(12.5f), Theme.FAINT)));
      hero.add(Box.createVerticalGlue());
      return hero;
   }

   private static JComponent centered(JComponent c) {
      c.setAlignmentX(Component.CENTER_ALIGNMENT);
      return c;
   }

   private JComponent card() {
      Ui.Card card = new Ui.Card(new GridBagLayout(), 26);
      card.setBorder(BorderFactory.createEmptyBorder(20, 22, 18, 22));
      card.setPreferredSize(new Dimension(424, 10));
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.gridy = 0;
      c.weightx = 1;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.anchor = GridBagConstraints.WEST;

      card.add(Ui.caption("Mundo"), c);
      c.gridy++;
      c.insets = new Insets(8, 0, 0, 0);
      c.fill = GridBagConstraints.BOTH;
      c.weighty = 1;
      worldList.setOpaque(false);
      worldList.setBackground(new Color(0, 0, 0, 0));
      worldList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
      worldList.setFixedCellHeight(48);
      WorldCell cell = new WorldCell();
      worldList.setCellRenderer(cell);
      worldList.addMouseMotionListener(new MouseAdapter() {
         @Override
         public void mouseMoved(MouseEvent e) {
            int i = worldList.locationToIndex(e.getPoint());
            int hover = i >= 0 && worldList.getCellBounds(i, i).contains(e.getPoint()) ? i : -1;
            if (hover != cell.hover) {
               cell.hover = hover;
               worldList.repaint();
            }
         }
      });
      worldList.addMouseListener(new MouseAdapter() {
         @Override
         public void mouseExited(MouseEvent e) {
            cell.hover = -1;
            worldList.repaint();
         }

         @Override
         public void mouseClicked(MouseEvent e) {
            if (e.getClickCount() == 2 && SwingUtilities.isLeftMouseButton(e) && worldList.isEnabled()) {
               start();
            }
         }
      });
      fillWorlds();
      card.add(Ui.scroll(worldList), c);

      c.gridy++;
      c.weighty = 0;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.insets = new Insets(16, 0, 0, 0);
      card.add(Ui.caption("Servidor"), c);
      c.gridy++;
      c.insets = new Insets(8, 0, 0, 0);
      card.add(server, c);

      JPanel fields = new JPanel(new GridBagLayout());
      fields.setOpaque(false);
      GridBagConstraints f = new GridBagConstraints();
      f.fill = GridBagConstraints.HORIZONTAL;
      f.weightx = 0.56;
      fields.add(host, f);
      f.gridx = 1;
      f.weightx = 0.44;
      f.insets = new Insets(0, 8, 0, 0);
      fields.add(user, f);
      c.gridy++;
      card.add(fields, c);

      c.gridy++;
      c.insets = new Insets(7, 2, 0, 0);
      card.add(hint, c);

      c.gridy++;
      c.insets = new Insets(16, 0, 0, 0);
      play.addActionListener(e -> start());
      card.add(play, c);
      c.gridy++;
      c.insets = new Insets(8, 0, 0, 0);
      gameStatus.setHorizontalAlignment(JLabel.CENTER);
      card.add(gameStatus, c);

      host.setText(settings.customServer.isEmpty() && !settings.server.isEmpty() && !settings.server.equals(LOCAL_WHIRL)
         ? settings.server : settings.customServer);
      user.setText(settings.user);
      server.select(settings.server.isEmpty() ? SINGLE : settings.server.equals(LOCAL_WHIRL) ? WHIRL : OTHER);
      server.onChange(i -> syncServer());
      syncServer();
      return card;
   }

   private JComponent footer() {
      JPanel foot = new JPanel(new BorderLayout());
      foot.setOpaque(false);
      JPanel left = new JPanel(new FlowLayout(FlowLayout.LEFT, 8, 0));
      left.setOpaque(false);
      left.add(updateLabel);
      updateNow.setVisible(false);
      updateNow.addActionListener(e -> restartIntoUpdate());
      left.add(updateNow);
      foot.add(left, BorderLayout.WEST);
      JPanel right = new JPanel(new FlowLayout(FlowLayout.RIGHT, 4, 0));
      right.setOpaque(false);
      settingsButton.addActionListener(e -> SettingsDialog.open(frame, layout, settings, updater));
      Ui.Ghost data = new Ui.Ghost("Carpeta de datos", new Ui.Glyph(Ui.Glyph.Kind.FOLDER, 14));
      data.setToolTipText(layout.dataDir.getPath());
      data.addActionListener(e -> openDir(layout.dataDir));
      right.add(settingsButton);
      right.add(data);
      foot.add(right, BorderLayout.EAST);
      return foot;
   }

   // ------------------------------------------------------------ mundos

   /** (Re)reads the worlds, keeping the selection (a download may have installed one). */
   private void fillWorlds() {
      Install.World sel = worldList.getSelectedValue();
      String want = sel != null ? sel.url : settings.world;
      worldModel.clear();
      for (Install.World w : Install.worlds(layout)) {
         worldModel.addElement(w);
      }
      worldModel.addElement(new Install.World("Pantalla de inicio", "", true));
      int index = 0;
      for (int i = 0; i < worldModel.size(); i++) {
         if (worldModel.get(i).url.equals(want)) {
            index = i;
         }
      }
      worldList.setSelectedIndex(index);
      worldList.ensureIndexIsVisible(index);
   }

   /** A world in the list: status dot, name and one line on what "Play" will do with it. */
   private static final class WorldCell extends JComponent implements ListCellRenderer<Install.World> {
      int hover = -1;
      private Install.World world;
      private boolean selected;
      private boolean hovered;
      private boolean enabled;

      @Override
      public Component getListCellRendererComponent(JList<? extends Install.World> list, Install.World value, int index,
                                                    boolean isSelected, boolean cellHasFocus) {
         world = value;
         selected = isSelected;
         hovered = index == hover;
         enabled = list.isEnabled();
         return this;
      }

      @Override
      protected void paintComponent(Graphics g) {
         Graphics2D g2 = Theme.smooth(g);
         int w = getWidth();
         int h = getHeight();
         RoundRectangle2D row = new RoundRectangle2D.Float(1, 2, w - 4, h - 4, 14, 14);
         if (selected) {
            g2.setColor(Theme.SELECTED);
            g2.fill(row);
            g2.setColor(Theme.alpha(Theme.SEA, enabled ? 130 : 60));
            g2.draw(row);
         } else if (hovered && enabled) {
            g2.setColor(Theme.HOVER);
            g2.fill(row);
         }
         boolean login = world.url.isEmpty();
         Color dot = login ? Theme.MUTED : world.installed ? Theme.LAND : Theme.RING_B;
         g2.setColor(enabled ? dot : Theme.alpha(dot, 110));
         g2.fill(new Ellipse2D.Float(14, h / 2f - 4.5f, 9, 9));
         String sub = login ? "La pantalla de inicio de sesión del juego"
            : world.installed ? "Instalado" : "Se descarga la primera vez (us1.worlds.net)";
         g2.setFont(Theme.semibold(13.5f));
         FontMetrics fm = g2.getFontMetrics();
         g2.setColor(enabled ? Theme.TEXT : Theme.FAINT);
         g2.drawString(fit(world.name, fm, w - 48), 34, h / 2 - 2);
         g2.setFont(Theme.regular(11f));
         g2.setColor(enabled ? Theme.MUTED : Theme.FAINT);
         g2.drawString(fit(sub, g2.getFontMetrics(), w - 48), 34, h / 2 + 13);
         g2.dispose();
      }

      private static String fit(String s, FontMetrics fm, int width) {
         if (fm.stringWidth(s) <= width) {
            return s;
         }
         String t = s;
         while (t.length() > 1 && fm.stringWidth(t + "…") > width) {
            t = t.substring(0, t.length() - 1);
         }
         return t + "…";
      }
   }

   // ------------------------------------------------------------ servidor

   private void syncServer() {
      int mode = server.selected();
      host.setEnabled(!busy && mode == OTHER);
      user.setEnabled(!busy && mode != SINGLE);
      if (mode == WHIRL) {
         host.setText(LOCAL_WHIRL);
      } else if (host.getText().equals(LOCAL_WHIRL)) {
         host.setText(settings.customServer);
      }
      switch (mode) {
         case SINGLE:
            setHint("Sin servidor: el mundo es solo tuyo, y los demás mundos se descargan al visitarlos.", false);
            break;
         case WHIRL:
            setHint(LocalWhirl.available(layout)
               ? "Un servidor whirl en este equipo (127.0.0.1:6650): se arranca solo y se para con el juego."
               : "Hace falta whirl en marcha en 127.0.0.1:6650 (tools/run-whirl.sh): este paquete no lo trae.", false);
            break;
         default:
            setHint("Un servidor de mundos, como host:puerto. El usuario es tu nombre en el chat.", false);
      }
   }

   private void setHint(String text, boolean error) {
      hint.setText(text);
      hint.setForeground(error ? Theme.ERROR : Theme.MUTED);
   }

   /** Settings from the window; false (with the reason under the fields) if something is missing. */
   private boolean collect() {
      Install.World w = worldList.getSelectedValue();
      settings.world = w == null ? settings.world : w.url;
      int mode = server.selected();
      String typed = host.getText().trim();
      if (mode != WHIRL && !typed.equals(LOCAL_WHIRL)) {
         settings.customServer = typed;
      }
      settings.user = user.getText().trim();
      boolean ok = true;
      if (mode == SINGLE) {
         settings.server = "";
      } else if (mode == WHIRL) {
         settings.server = LOCAL_WHIRL;
      } else if (!validHostPort(typed)) {
         setHint("Escribe el servidor como host:puerto (por ejemplo, 127.0.0.1:6650).", true);
         host.requestFocusInWindow();
         ok = false;
      } else {
         settings.server = typed;
      }
      settings.save(layout.settingsFile);
      return ok;
   }

   static boolean validHostPort(String s) {
      int colon = s.lastIndexOf(':');
      if (colon <= 0 || colon == s.length() - 1 || s.contains(" ")) {
         return false;
      }
      try {
         int port = Integer.parseInt(s.substring(colon + 1));
         return port > 0 && port < 65536;
      } catch (NumberFormatException e) {
         return false;
      }
   }

   // ------------------------------------------------------------ partida

   private void start() {
      if (running != null && running.isRunning()) {
         stoppedByUser = true;
         running.stop();
         return;
      }
      if (running != null) {
         return; // aun cerrando la anterior
      }
      if (!collect()) {
         return;
      }
      syncServer();
      Session s = new Session(layout, settings);
      running = s;
      stoppedByUser = false;
      setRunning(true);
      gameStatus.setForeground(Theme.MUTED);
      gameStatus.setText("Arrancando WorldsPlayer…");
      Thread t = new Thread(() -> {
         int code;
         String failure = null;
         try {
            s.start();
            SwingUtilities.invokeLater(() -> gameStatus.setText("WorldsPlayer está en marcha"));
            code = s.waitFor();
         } catch (Exception e) {
            failure = e.getMessage() == null ? e.toString() : e.getMessage();
            code = -1;
         }
         final int exit = code;
         final String why = failure;
         SwingUtilities.invokeLater(() -> finished(exit, why));
      }, "freeworlds-session");
      t.setDaemon(true);
      t.start();
   }

   private void finished(int code, String failure) {
      running = null;
      setRunning(false);
      fillWorlds();
      if (failure != null) {
         gameStatus.setForeground(Theme.ERROR);
         gameStatus.setText("No se pudo arrancar el juego");
         setHint(failure, true);
      } else if (stoppedByUser) {
         gameStatus.setForeground(Theme.MUTED);
         gameStatus.setText("Juego detenido");
      } else if (code != 0) {
         gameStatus.setForeground(Theme.ERROR);
         gameStatus.setText("El juego se cerró con un error (código " + code + ")");
      } else {
         gameStatus.setForeground(Theme.MUTED);
         gameStatus.setText("Hasta la próxima");
      }
      frame.toFront();
   }

   private void setRunning(boolean on) {
      busy = on;
      // con el juego abierto, un Intro perdido en el lanzador no debe pararlo
      frame.getRootPane().setDefaultButton(on ? null : play);
      play.setText(on ? "Detener" : "Jugar");
      play.setIcon(new Ui.Glyph(on ? Ui.Glyph.Kind.STOP : Ui.Glyph.Kind.PLAY, 15));
      play.setKind(on ? Ui.Pill.Kind.QUIET : Ui.Pill.Kind.PRIMARY);
      worldList.setEnabled(!on);
      server.setEnabled(!on);
      syncServer();
      updateNow.setEnabled(!on);
      planet.setPaused(on);
   }

   // ------------------------------------------------------ actualizaciones

   private void showUpdate(Updater.Status s) {
      String own = "FreeWorlds " + Layout.version();
      updateLabel.setToolTipText(null);
      updateNow.setVisible(false);
      updateLabel.setForeground(Theme.MUTED);
      switch (s.phase) {
         case CHECKING:
            updateLabel.setText(own + " · buscando actualizaciones…");
            break;
         case UP_TO_DATE:
            updateLabel.setText(own + " · al día");
            break;
         case DOWNLOADING:
            updateLabel.setText("Descargando FreeWorlds " + s.version + "… " + s.percent + " %");
            break;
         case READY:
            updateLabel.setForeground(Theme.TEXT);
            updateLabel.setText("FreeWorlds " + s.version + " está lista");
            updateNow.setVisible(true);
            updateNow.setEnabled(!busy);
            break;
         case FAILED:
            updateLabel.setText(own + " · sin comprobar actualizaciones");
            updateLabel.setToolTipText(s.detail);
            break;
         default:
            updateLabel.setText(own);
            updateLabel.setToolTipText(s.detail.isEmpty() ? null : s.detail);
      }
   }

   /** Closes this window and hands the start to the downloaded version (Bootstrap), in this same process. */
   private void restartIntoUpdate() {
      if (busy) {
         return;
      }
      collect();
      planet.setPaused(true);
      frame.setVisible(false);
      Thread t = new Thread(() -> {
         boolean ok = Bootstrap.handOff(args, true);
         SwingUtilities.invokeLater(() -> {
            if (ok) {
               frame.dispose();
            } else {
               frame.setVisible(true);
               planet.setPaused(false);
               gameStatus.setForeground(Theme.ERROR);
               gameStatus.setText("La versión nueva no arranca; sigue esta");
            }
         });
      }, "freeworlds-restart");
      t.start();
   }

   // ------------------------------------------------------------ varios

   private void quit() {
      Session s = running;
      if (s != null && s.isRunning()) {
         if (!Ui.ask(frame, "FreeWorlds", "El juego sigue abierto. ¿Cerrarlo y salir?", "Cerrar y salir", "Seguir jugando")) {
            return;
         }
         stoppedByUser = true;
         s.stop();
      }
      collect();
      frame.dispose();
      System.exit(0);
   }

   private void openDir(File dir) {
      dir.mkdirs();
      try {
         Desktop.getDesktop().open(dir);
      } catch (Exception e) {
         Ui.ask(frame, "Carpeta de datos", dir.getPath(), "Vale", null);
      }
   }
}
