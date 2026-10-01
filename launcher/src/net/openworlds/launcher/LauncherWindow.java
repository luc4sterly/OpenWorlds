package net.openworlds.launcher;

import net.openworlds.ui.PlanetView;
import net.openworlds.ui.SpaceBackground;
import net.openworlds.ui.Theme;
import net.openworlds.ui.Ui;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultListModel;
import javax.swing.JCheckBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Desktop;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.IOException;
import java.util.concurrent.CancellationException;

/**
 * The launcher's window, dressed as the logo: the planet turning on the
 * left, and on the right what to play (world, server, patches) and the Play
 * button. The session log is not shown (it is still written to logs/ in the
 * data folder, for bug reports and the CI); the footer carries the update
 * status.
 *
 * <p>Play runs, on a worker thread: the certificate check of an encrypted
 * server (the first time, with the player: {@link Trust}), then the session,
 * which installs the chosen world if needed, builds the patches and starts
 * the game ({@link Session}). Until the game ends, Play is Stop.
 */
final class LauncherWindow {
   private static final int SINGLE = 0;
   private static final int ONLINE = 1;

   private final Layout layout;
   private final Settings settings;
   private final String[] args;
   private final Updater updater;
   private final JFrame frame = new JFrame("OpenWorlds");
   private final PlanetView planet = new PlanetView(116);
   private final DefaultListModel<Install.World> worldModel = new DefaultListModel<>();
   private final Ui.Rows<Install.World> worldList = new Ui.Rows<>(worldModel, 48, this::paintWorld);
   private final Ui.Segmented server = new Ui.Segmented("Single player", "Online");
   private final JPanel online = new JPanel(new GridBagLayout());
   private final Ui.Field host = new Ui.Field(14, "server address, e.g. 192.168.1.20");
   private final Ui.Field user = new Ui.Field(10, "your name");
   private final Ui.Secret password = new Ui.Secret(10, "password");
   private final JCheckBox encrypted = Ui.check("Encrypted connection");
   private final Ui.Note hint = new Ui.Note("", Theme.regular(11.5f), Theme.MUTED, 376);
   private final Ui.Ghost patchesButton = new Ui.Ghost("Patches", new Ui.Glyph(Ui.Glyph.Kind.PUZZLE, 14));
   private final JLabel patchesLabel = Ui.text(" ", Theme.regular(12f), Theme.MUTED);
   private final Ui.Pill play = new Ui.Pill("Play", new Ui.Glyph(Ui.Glyph.Kind.PLAY, 15), Ui.Pill.Kind.PRIMARY, 17f);
   private final JLabel gameStatus = Ui.text(" ", Theme.regular(12f), Theme.MUTED);
   private final JLabel updateLabel = Ui.text(" ", Theme.regular(12f), Theme.MUTED);
   private final Ui.Pill updateNow = new Ui.Pill("Restart to update", new Ui.Glyph(Ui.Glyph.Kind.REFRESH, 12),
      Ui.Pill.Kind.PRIMARY, 12f);
   private final Ui.Ghost settingsButton = new Ui.Ghost("Settings", new Ui.Glyph(Ui.Glyph.Kind.GEAR, 14));
   /** The session of this Play, once the worker has made it. */
   private volatile Session running;
   /** From Play until the session ends: certificate check, world install, patches, the game. */
   private volatile boolean busy;
   private volatile boolean stoppedByUser;

   private LauncherWindow(Layout layout, Settings settings, String[] args) {
      this.layout = layout;
      this.settings = settings;
      this.args = args.clone();
      this.updater = new Updater(layout, settings);
   }

   static void open(Layout layout, Settings settings, String[] args) {
      SwingUtilities.invokeLater(() -> {
         Ui.installLookAndFeel();
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
            planet.setPaused(busy);
         }
      });
      frame.setMinimumSize(new Dimension(900, 660));
      frame.setSize(new Dimension(980, 700));
      frame.setLocationRelativeTo(null);
      frame.setVisible(true);
      worldList.requestFocusInWindow();

      updater.addListener(s -> SwingUtilities.invokeLater(() -> showUpdate(s)));
      if (settings.autoUpdate) {
         updater.checkInBackground(false);
      }
   }

   // ------------------------------------------------------------ columns

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
      hero.add(Box.createVerticalStrut(4));
      hero.add(centered(Ui.text("3D chat worlds, open to everyone", Theme.medium(15f), Theme.MUTED)));
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

      card.add(Ui.caption("World"), c);
      c.gridy++;
      c.insets = new Insets(8, 0, 0, 0);
      c.fill = GridBagConstraints.BOTH;
      c.weighty = 1;
      worldList.addMouseListener(new MouseAdapter() {
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
      card.add(Ui.caption("Server"), c);
      c.gridy++;
      c.insets = new Insets(8, 0, 0, 0);
      card.add(server, c);

      online.setOpaque(false);
      GridBagConstraints f = new GridBagConstraints();
      f.fill = GridBagConstraints.HORIZONTAL;
      f.gridx = 0;
      f.gridy = 0;
      f.gridwidth = 2;
      f.weightx = 1;
      online.add(host, f);
      f.gridy = 1;
      f.gridwidth = 1;
      f.weightx = 0.5;
      f.insets = new Insets(8, 0, 0, 0);
      online.add(user, f);
      f.gridx = 1;
      f.insets = new Insets(8, 8, 0, 0);
      online.add(password, f);
      f.gridx = 0;
      f.gridy = 2;
      f.gridwidth = 2;
      f.insets = new Insets(8, 2, 0, 0);
      encrypted.setToolTipText("Names, passwords and chat travel encrypted (TLS). J Solar Server's encrypted port is 6651.");
      online.add(encrypted, f);
      c.gridy++;
      card.add(online, c);

      c.gridy++;
      c.insets = new Insets(7, 2, 0, 0);
      card.add(hint, c);

      JPanel patches = new JPanel(new BorderLayout(10, 0));
      patches.setOpaque(false);
      patchesButton.setToolTipText("J Worlds Injector: patches built into the game when you press Play");
      patchesButton.addActionListener(e -> {
         PatchesDialog.open(frame, layout, settings);
         showPatches();
      });
      patches.add(patchesButton, BorderLayout.WEST);
      patches.add(patchesLabel, BorderLayout.CENTER);
      showPatches();
      c.gridy++;
      c.insets = new Insets(12, -6, 0, 0);
      card.add(patches, c);

      c.gridy++;
      c.insets = new Insets(14, 0, 0, 0);
      play.addActionListener(e -> start());
      card.add(play, c);
      c.gridy++;
      c.insets = new Insets(8, 0, 0, 0);
      gameStatus.setHorizontalAlignment(JLabel.CENTER);
      card.add(gameStatus, c);

      host.setText(settings.customServer.isEmpty() ? settings.server : settings.customServer);
      user.setText(settings.user);
      password.setText(settings.password);
      encrypted.setSelected(settings.encrypted);
      server.select(settings.server.isEmpty() ? SINGLE : ONLINE);
      server.onChange(i -> syncServer());
      encrypted.addItemListener(e -> syncServer());
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
      settingsButton.addActionListener(e -> {
         SettingsDialog.open(frame, layout, settings, updater);
         worldList.repaint(); // "download what is missing" changes what the rows say
      });
      Ui.Ghost data = new Ui.Ghost("Data folder", new Ui.Glyph(Ui.Glyph.Kind.FOLDER, 14));
      data.setToolTipText(layout.dataDir.getPath());
      data.addActionListener(e -> openDir(layout.dataDir));
      right.add(settingsButton);
      right.add(data);
      foot.add(right, BorderLayout.EAST);
      return foot;
   }

   // ------------------------------------------------------------ worlds

   /** (Re)reads the worlds, keeping the selection (a session may have installed one). */
   private void fillWorlds() {
      Install.World sel = worldList.getSelectedValue();
      String want = sel != null ? sel.url : settings.world;
      worldModel.clear();
      for (Install.World w : Install.worlds(layout)) {
         worldModel.addElement(w);
      }
      worldModel.addElement(new Install.World("Login screen", "", true));
      int index = 0;
      for (int i = 0; i < worldModel.size(); i++) {
         if (worldModel.get(i).url.equals(want)) {
            index = i;
         }
      }
      worldList.setSelectedIndex(index);
      worldList.ensureIndexIsVisible(index);
   }

   /** A world in the list: status dot, name and one line on what Play will do with it. */
   private void paintWorld(java.awt.Graphics2D g2, Install.World world, int w, int h, boolean enabled) {
      boolean login = world.url.isEmpty();
      Color dot = login ? Theme.MUTED : world.installed ? Theme.LAND : Theme.RING_B;
      String sub = login ? "The game's own sign-in screen"
         : world.installed ? "Installed"
         : settings.mirror ? "Not installed yet: Play downloads it (us1.worlds.net)"
         : "Not installed (downloading is off in Settings)";
      Ui.drawRow(g2, w, h, dot, world.name, sub, enabled);
   }

   // ------------------------------------------------------------ server

   private void syncServer() {
      boolean isOnline = server.selected() == ONLINE;
      online.setVisible(isOnline);
      if (!isOnline) {
         setHint("No server: the world is all yours.", false);
      } else if (encrypted.isSelected()) {
         setHint("Encrypted with TLS (port 6651 unless you type one). The first time, you confirm the server's "
            + "certificate.", false);
      } else {
         setHint("The address your J Solar Server shows. The first time, any name and password make your account.",
            false);
      }
      online.revalidate();
   }

   private void setHint(String text, boolean error) {
      hint.setText(text);
      hint.setForeground(error ? Theme.ERROR : Theme.MUTED);
   }

   private void showPatches() {
      String names = PatchesDialog.summary(layout, settings);
      patchesLabel.setText(names.isEmpty() ? "None: the game as it was in 2004" : names);
      patchesLabel.setForeground(names.isEmpty() ? Theme.FAINT : Theme.TEXT);
      patchesLabel.setToolTipText(names.isEmpty() ? null : names);
   }

   /** Settings from the window; false (with the reason under the fields) if something is missing. */
   private boolean collect() {
      Install.World w = worldList.getSelectedValue();
      settings.world = w == null ? settings.world : w.url;
      settings.customServer = host.getText().trim();
      settings.user = user.getText().trim();
      settings.password = new String(password.getPassword());
      settings.encrypted = encrypted.isSelected();
      boolean ok = true;
      if (server.selected() == SINGLE) {
         settings.server = "";
      } else {
         String address = Launcher.serverAddress(settings.customServer, settings.encrypted);
         if (address == null) {
            setHint(settings.customServer.isEmpty() ? "Type the address of the server (J Solar Server shows it)."
               : "That is not a server address: type it as host or host:port, e.g. 192.168.1.20.", true);
            host.requestFocusInWindow();
            ok = false;
         } else {
            settings.server = address;
         }
      }
      settings.save(layout.settingsFile);
      return ok;
   }

   // ------------------------------------------------------------ game

   private void start() {
      if (busy) {
         // Stop: the game, or what comes before it (the download of a world...)
         stoppedByUser = true;
         Session s = running;
         if (s != null) {
            s.stop();
         }
         status("Stopping…", false);
         return;
      }
      if (!collect()) {
         return;
      }
      syncServer();
      stoppedByUser = false;
      setRunning(true);
      status("Getting ready…", false);
      Thread t = new Thread(this::runSession, "openworlds-session");
      t.setDaemon(true);
      t.start();
   }

   /** The worker behind Play: certificate, session (world install, patches, game) and its end. */
   private void runSession() {
      int code = -1;
      String failure = null;
      try {
         if (!settings.server.isEmpty() && settings.encrypted && !trusted()) {
            failure = "The server's certificate was not trusted, so the game did not start.";
         } else if (!stoppedByUser) {
            Session s = new Session(layout, settings);
            s.onProgress((text, percent) -> SwingUtilities.invokeLater(() -> {
               if (!stoppedByUser) {
                  status(text, false);
               }
            }));
            running = s;
            if (stoppedByUser) {
               s.stop();
            }
            s.start();
            SwingUtilities.invokeLater(() -> status("WorldsPlayer is running", false));
            code = s.waitFor();
         }
      } catch (CancellationException e) {
         stoppedByUser = true;
      } catch (Exception e) {
         failure = e.getMessage() == null ? e.toString() : e.getMessage();
      }
      final int exit = code;
      final String why = failure;
      SwingUtilities.invokeLater(() -> finished(exit, why));
   }

   /**
    * For an encrypted server: true if its certificate is the one trusted
    * before, or the player trusts it now (the first time, or after it
    * changed). Runs on the worker; the question goes to the event thread.
    */
   private boolean trusted() throws Exception {
      String address = settings.server;
      SwingUtilities.invokeLater(() -> status("Checking " + address + "…", false));
      Trust.Check c;
      try {
         c = Trust.check(layout, address);
      } catch (IOException e) {
         boolean plainPort = address.endsWith(":" + Launcher.PLAIN_PORT);
         throw new IOException(address + " does not answer an encrypted connection (" + e.getMessage() + ")."
            + (plainPort ? " J Solar Server's encrypted port is " + Launcher.TLS_PORT + "." : ""), e);
      }
      if (c.trusted()) {
         return true;
      }
      String message = c.changed()
         ? address + " shows a different certificate than last time:\n\n" + Trust.pretty(c.fingerprint)
            + "\n\nIf the server's owner made a new one, compare this fingerprint with the one J Solar Server shows. "
            + "If they did not, someone may be in the middle: do not connect."
         : "The first encrypted connection to " + address + ". Its certificate's fingerprint is:\n\n"
            + Trust.pretty(c.fingerprint) + "\n\nIt should match the one J Solar Server shows (Settings, Connections). "
            + "If it does, trust it: OpenWorlds remembers it and warns you if it ever changes.";
      boolean[] yes = {false};
      SwingUtilities.invokeAndWait(() -> yes[0] = Ui.ask(frame, c.changed() ? "The certificate changed" : "Check this server",
         message, c.changed() ? "Trust the new one" : "Trust it", "Cancel"));
      if (yes[0]) {
         Trust.remember(layout, address, c.fingerprint);
      }
      return yes[0];
   }

   private void finished(int code, String failure) {
      running = null;
      setRunning(false);
      fillWorlds();
      if (failure != null) {
         status("The game did not start", true);
         setHint(failure, true);
      } else if (stoppedByUser) {
         status("Game stopped", false);
      } else if (code != 0) {
         status("The game closed with an error (code " + code + ")", true);
      } else {
         status("See you next time", false);
      }
      frame.toFront();
   }

   private void status(String text, boolean error) {
      gameStatus.setForeground(error ? Theme.ERROR : Theme.MUTED);
      gameStatus.setText(text);
   }

   private void setRunning(boolean on) {
      busy = on;
      // with the game open, a stray Enter in the launcher must not stop it
      frame.getRootPane().setDefaultButton(on ? null : play);
      play.setText(on ? "Stop" : "Play");
      play.setIcon(new Ui.Glyph(on ? Ui.Glyph.Kind.STOP : Ui.Glyph.Kind.PLAY, 15));
      play.setKind(on ? Ui.Pill.Kind.QUIET : Ui.Pill.Kind.PRIMARY);
      worldList.setEnabled(!on);
      server.setEnabled(!on);
      for (JComponent field : new JComponent[]{host, user, password, encrypted, patchesButton}) {
         field.setEnabled(!on);
      }
      updateNow.setEnabled(!on);
      planet.setPaused(on);
   }

   // ------------------------------------------------------------ updates

   private void showUpdate(Updater.Status s) {
      String own = "OpenWorlds " + Layout.version();
      updateLabel.setToolTipText(null);
      updateNow.setVisible(false);
      updateLabel.setForeground(Theme.MUTED);
      switch (s.phase) {
         case CHECKING:
            updateLabel.setText(own + " · checking for updates…");
            break;
         case UP_TO_DATE:
            updateLabel.setText(own + " · up to date");
            break;
         case DOWNLOADING:
            updateLabel.setText("Downloading OpenWorlds " + s.version + "… " + s.percent + "%");
            break;
         case READY:
            updateLabel.setForeground(Theme.TEXT);
            updateLabel.setText("OpenWorlds " + s.version + " is ready");
            updateNow.setVisible(true);
            updateNow.setEnabled(!busy);
            break;
         case FAILED:
            updateLabel.setText(own + " · could not check for updates");
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
               status("The new version does not start; keeping this one", true);
            }
         });
      }, "openworlds-restart");
      t.start();
   }

   // ------------------------------------------------------------ misc

   private void quit() {
      if (busy) {
         Session s = running;
         boolean playing = s != null && s.isRunning();
         if (!Ui.ask(frame, "OpenWorlds", playing ? "The game is still open. Close it and quit?"
            : "The game is getting ready. Stop and quit?", playing ? "Close and quit" : "Stop and quit", "Keep playing")) {
            return;
         }
         stoppedByUser = true;
         if (s != null) {
            s.stop();
         }
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
         Ui.ask(frame, "Data folder", dir.getPath(), "OK", null);
      }
   }
}
