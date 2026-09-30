package net.openworlds.solar;

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
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.SwingUtilities;
import javax.swing.Timer;
import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Component;
import java.awt.Desktop;
import java.awt.Dialog;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.Toolkit;
import java.awt.datatransfer.StringSelection;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.NetworkInterface;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Locale;

/**
 * J Solar Server's admin window, in the violet colours of its icon: on the
 * left the planet, whether the server runs, the Start/Stop button and the
 * address to give to friends; on the right the players online, the accounts,
 * the chat and log, and the settings (including encrypted connections).
 * Everything the window does goes through {@link SolarServer}'s public
 * methods, the same the console uses.
 */
final class AdminWindow {
   private static final int PLAYERS = 0;
   private static final int ACCOUNTS = 1;
   private static final int CHAT = 2;
   private static final int SETTINGS = 3;

   private final SolarServer server;
   private final JFrame frame = new JFrame("J Solar Server");
   private final PlanetView planet = new PlanetView(64, PlanetView.Style.SOLAR);
   private final JLabel status = Ui.text(" ", Theme.semibold(14f), Theme.TEXT);
   private final JLabel statusDetail = Ui.text(" ", Theme.regular(12f), Theme.MUTED);
   private final Ui.Pill startStop = new Ui.Pill("Start server", new Ui.Glyph(Ui.Glyph.Kind.POWER, 15), Ui.Pill.Kind.PRIMARY, 16f);
   private final JPanel addresses = new JPanel();
   private final Ui.Segmented tabs = new Ui.Segmented("Players", "Accounts", "Chat & log", "Settings");
   private final CardLayout pages = new CardLayout();
   private final JPanel pageHost = new JPanel(pages);

   private final DefaultListModel<SolarServer.PlayerInfo> playerModel = new DefaultListModel<>();
   private final Ui.Rows<SolarServer.PlayerInfo> playerList;
   private final Ui.Note playersEmpty = new Ui.Note("", Theme.regular(12.5f), Theme.MUTED, 440);
   private final DefaultListModel<SolarServer.AccountInfo> accountModel = new DefaultListModel<>();
   private final Ui.Rows<SolarServer.AccountInfo> accountList;
   private final Ui.Field accountSearch = new Ui.Field(14, "Search accounts");
   private final JTextArea logArea = new JTextArea();
   private final Ui.Field broadcast = new Ui.Field(20, "A message for everyone online");

   private final Timer refresh;
   private final SimpleDateFormat time = new SimpleDateFormat("HH:mm");
   private final SimpleDateFormat day = new SimpleDateFormat("d MMM yyyy", Locale.ENGLISH);

   private AdminWindow(SolarServer server) {
      this.server = server;
      playerList = new Ui.Rows<>(playerModel, 52, (g, p, w, h, on) -> Ui.drawRow(g, w, h, Theme.LAND, p.name,
         (p.room.isEmpty() ? "Signing in" : p.room) + "  ·  " + p.address + "  ·  since " + time.format(new Date(p.since)), on,
         p.guest ? "Guest" : null, p.admin ? "Admin" : null, p.vip ? "VIP" : null, p.secure ? "Encrypted" : null));
      accountList = new Ui.Rows<>(accountModel, 52, (g, a, w, h, on) -> Ui.drawRow(g, w, h,
         a.online ? Theme.LAND : Theme.FAINT, a.name,
         (a.online ? "Online now" : a.lastSeen > 0 ? "Last seen " + day.format(new Date(a.lastSeen)) : "Never signed in")
            + "  ·  since " + day.format(new Date(a.created)), on,
         a.banned ? "Banned" : null, a.admin ? "Admin" : null, a.vip ? "VIP" : null));
      refresh = new Timer(250, e -> refreshNow());
      refresh.setRepeats(false);
   }

   /** Opens the window (and, if set so, starts the server). */
   static void open(SolarServer server) {
      SwingUtilities.invokeLater(() -> {
         Theme.use(Theme.Palette.SOLAR);
         Ui.installLookAndFeel();
         new AdminWindow(server).build();
      });
   }

   private void build() {
      SpaceBackground root = new SpaceBackground(new BorderLayout(0, 10));
      root.setBorder(BorderFactory.createEmptyBorder(18, 26, 12, 26));
      JPanel body = new JPanel(new GridBagLayout());
      body.setOpaque(false);
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.weighty = 1;
      c.fill = GridBagConstraints.BOTH;
      body.add(hero(), c);
      c.gridx = 1;
      c.weightx = 1;
      c.insets = new Insets(0, 18, 0, 0);
      body.add(card(), c);
      root.add(body, BorderLayout.CENTER);
      root.add(footer(), BorderLayout.SOUTH);

      frame.setContentPane(root);
      java.net.URL icon = AdminWindow.class.getResource("icon.png");
      if (icon != null) {
         frame.setIconImage(new javax.swing.ImageIcon(icon).getImage());
      }
      frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
      frame.addWindowListener(new WindowAdapter() {
         @Override
         public void windowClosing(WindowEvent e) {
            quit();
         }
      });
      frame.setMinimumSize(new Dimension(1000, 640));
      frame.setSize(new Dimension(1080, 700));
      frame.setLocationRelativeTo(null);
      frame.setVisible(true);

      for (String line : server.recentLog()) {
         appendLog(line);
      }
      server.addListener(new SolarServer.Listener() {
         @Override
         public void log(String line) {
            SwingUtilities.invokeLater(() -> appendLog(line));
         }

         @Override
         public void changed() {
            SwingUtilities.invokeLater(refresh::restart);
         }
      });
      refreshNow();
      if (server.config.autoStart) {
         startServer();
      }
   }

   // ------------------------------------------------------------ left column

   private JComponent hero() {
      JPanel hero = new JPanel();
      hero.setOpaque(false);
      hero.setLayout(new BoxLayout(hero, BoxLayout.Y_AXIS));
      hero.setPreferredSize(new Dimension(320, 10));
      planet.setAlignmentX(Component.CENTER_ALIGNMENT);
      hero.add(planet);
      Ui.Wordmark title = new Ui.Wordmark("J ", "Solar", " Server", 34f);
      title.setAlignmentX(Component.CENTER_ALIGNMENT);
      hero.add(title);
      hero.add(Box.createVerticalStrut(2));
      hero.add(centered(Ui.text("Your own Worlds server", Theme.medium(13.5f), Theme.MUTED)));
      hero.add(Box.createVerticalStrut(12));
      hero.add(centered(status));
      hero.add(Box.createVerticalStrut(2));
      hero.add(centered(statusDetail));
      hero.add(Box.createVerticalStrut(12));
      startStop.setAlignmentX(Component.CENTER_ALIGNMENT);
      startStop.addActionListener(e -> {
         if (server.isRunning()) {
            stopServer();
         } else {
            startServer();
         }
      });
      hero.add(startStop);
      hero.add(Box.createVerticalStrut(14));
      addresses.setOpaque(false);
      addresses.setLayout(new BoxLayout(addresses, BoxLayout.Y_AXIS));
      addresses.setAlignmentX(Component.CENTER_ALIGNMENT);
      hero.add(addresses);
      hero.add(Box.createVerticalGlue());
      return hero;
   }

   private static JComponent centered(JComponent c) {
      c.setAlignmentX(Component.CENTER_ALIGNMENT);
      return c;
   }

   /** The addresses players type in their launcher, each with a Copy button. */
   private void fillAddresses() {
      addresses.removeAll();
      Ui.Card box = new Ui.Card(new GridBagLayout(), 20);
      box.setBorder(BorderFactory.createEmptyBorder(12, 16, 12, 10));
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.gridy = 0;
      c.gridwidth = 2;
      c.weightx = 1;
      c.anchor = GridBagConstraints.WEST;
      c.fill = GridBagConstraints.HORIZONTAL;
      box.add(Ui.caption("Address for your friends"), c);
      List<String> lines = new ArrayList<>();
      int port = server.isRunning() && server.boundPort() > 0 ? server.boundPort() : server.config.port;
      int tlsPort = server.isRunning() && server.boundTlsPort() > 0 ? server.boundTlsPort() : server.config.tlsPort;
      for (String ip : lanAddresses()) {
         if (server.config.plainEnabled) {
            lines.add(ip + ":" + port);
         }
         if (server.config.tlsEnabled) {
            lines.add(ip + ":" + tlsPort + "  (encrypted)");
         }
      }
      lines.add((server.config.plainEnabled ? "127.0.0.1:" + port : "127.0.0.1:" + tlsPort + "  (encrypted)") + "  (this computer)");
      c.gridwidth = 1;
      for (String line : lines) {
         c.gridy++;
         c.gridx = 0;
         c.weightx = 1;
         c.insets = new Insets(6, 0, 0, 0);
         JLabel l = Ui.text(line, Theme.semibold(13.5f), server.isRunning() ? Theme.TEXT : Theme.FAINT);
         box.add(l, c);
         c.gridx = 1;
         c.weightx = 0;
         Ui.Ghost copy = new Ui.Ghost("", new Ui.Glyph(Ui.Glyph.Kind.COPY, 13));
         copy.setToolTipText("Copy");
         String address = line.split(" ")[0];
         copy.addActionListener(e -> copy(address));
         box.add(copy, c);
      }
      c.gridy++;
      c.gridx = 0;
      c.gridwidth = 2;
      c.insets = new Insets(8, 0, 0, 6);
      box.add(new Ui.Note("Friends type it in the OpenWorlds launcher (Online). Over the Internet, forward port "
         + port + " on your router to this computer.", Theme.regular(11f), Theme.MUTED, 270), c);
      addresses.add(box);
      addresses.revalidate();
      addresses.repaint();
   }

   static List<String> lanAddresses() {
      List<String> out = new ArrayList<>();
      try {
         for (NetworkInterface ni : Collections.list(NetworkInterface.getNetworkInterfaces())) {
            if (!ni.isUp() || ni.isLoopback() || ni.isVirtual()) {
               continue;
            }
            for (InetAddress a : Collections.list(ni.getInetAddresses())) {
               if (a instanceof Inet4Address && !a.isLoopbackAddress() && !a.isLinkLocalAddress()) {
                  out.add(a.getHostAddress());
               }
            }
         }
      } catch (Exception e) {
         // no interfaces to show: only "this computer"
      }
      Collections.sort(out);
      return out;
   }

   private void copy(String text) {
      Toolkit.getDefaultToolkit().getSystemClipboard().setContents(new StringSelection(text), null);
      statusDetail.setText("Copied " + text);
   }

   // ------------------------------------------------------------ right card

   private JComponent card() {
      Ui.Card card = new Ui.Card(new BorderLayout(0, 14), 26);
      card.setBorder(BorderFactory.createEmptyBorder(18, 20, 18, 20));
      card.add(tabs, BorderLayout.NORTH);
      pageHost.setOpaque(false);
      pageHost.add(playersPage(), Integer.toString(PLAYERS));
      pageHost.add(accountsPage(), Integer.toString(ACCOUNTS));
      pageHost.add(chatPage(), Integer.toString(CHAT));
      pageHost.add(settingsPage(), Integer.toString(SETTINGS));
      card.add(pageHost, BorderLayout.CENTER);
      tabs.onChange(i -> pages.show(pageHost, Integer.toString(i)));
      return card;
   }

   private JComponent playersPage() {
      JPanel p = new JPanel(new BorderLayout(0, 10));
      p.setOpaque(false);
      JPanel list = new JPanel(new BorderLayout(0, 8));
      list.setOpaque(false);
      list.add(Ui.scroll(playerList), BorderLayout.CENTER);
      list.add(playersEmpty, BorderLayout.NORTH);
      p.add(list, BorderLayout.CENTER);
      Ui.Ghost kick = new Ui.Ghost("Disconnect", new Ui.Glyph(Ui.Glyph.Kind.CLOSE, 12));
      Ui.Ghost vip = new Ui.Ghost("VIP on/off", new Ui.Glyph(Ui.Glyph.Kind.STAR, 13));
      Ui.Ghost ban = new Ui.Ghost("Ban", new Ui.Glyph(Ui.Glyph.Kind.LOCK, 13));
      Ui.Ghost whisper = new Ui.Ghost("Message everyone", new Ui.Glyph(Ui.Glyph.Kind.CHAT, 14));
      kick.addActionListener(e -> {
         SolarServer.PlayerInfo pl = playerList.getSelectedValue();
         if (pl != null && confirm("Disconnect " + pl.name + "?", "They can sign in again after a minute.", "Disconnect")) {
            server.kick(pl.name, "disconnected by the server's admin");
         }
      });
      vip.addActionListener(e -> {
         SolarServer.PlayerInfo pl = playerList.getSelectedValue();
         if (pl != null) {
            if (pl.guest) {
               info("Guests have no account", "Only players with an account can be VIP.");
            } else {
               server.setVip(pl.name, !pl.vip);
            }
         }
      });
      ban.addActionListener(e -> {
         SolarServer.PlayerInfo pl = playerList.getSelectedValue();
         if (pl != null && !pl.guest && confirm("Ban " + pl.name + "?",
            "They are disconnected and cannot sign in again until you unban them (Accounts).", "Ban")) {
            server.setBanned(pl.name, true);
         }
      });
      whisper.addActionListener(e -> {
         tabs.select(CHAT);
         pages.show(pageHost, Integer.toString(CHAT));
         broadcast.requestFocusInWindow();
      });
      playerList.addListSelectionListener(e -> {
         boolean sel = playerList.getSelectedValue() != null;
         kick.setEnabled(sel);
         vip.setEnabled(sel);
         ban.setEnabled(sel);
      });
      kick.setEnabled(false);
      vip.setEnabled(false);
      ban.setEnabled(false);
      p.add(buttons(whisper, Box.createHorizontalGlue(), vip, ban, kick), BorderLayout.SOUTH);
      return p;
   }

   private JComponent accountsPage() {
      JPanel p = new JPanel(new BorderLayout(0, 10));
      p.setOpaque(false);
      JPanel top = new JPanel(new BorderLayout(10, 0));
      top.setOpaque(false);
      top.add(accountSearch, BorderLayout.CENTER);
      Ui.Pill add = new Ui.Pill("New account", new Ui.Glyph(Ui.Glyph.Kind.PLUS, 12), Ui.Pill.Kind.QUIET, 12.5f);
      add.addActionListener(e -> newAccount());
      top.add(add, BorderLayout.EAST);
      p.add(top, BorderLayout.NORTH);
      p.add(Ui.scroll(accountList), BorderLayout.CENTER);
      accountSearch.getDocument().addDocumentListener(new javax.swing.event.DocumentListener() {
         @Override
         public void insertUpdate(javax.swing.event.DocumentEvent e) {
            refreshNow();
         }

         @Override
         public void removeUpdate(javax.swing.event.DocumentEvent e) {
            refreshNow();
         }

         @Override
         public void changedUpdate(javax.swing.event.DocumentEvent e) {
            refreshNow();
         }
      });
      Ui.Ghost password = new Ui.Ghost("New password", new Ui.Glyph(Ui.Glyph.Kind.KEY, 14));
      Ui.Ghost vip = new Ui.Ghost("VIP on/off", new Ui.Glyph(Ui.Glyph.Kind.STAR, 13));
      Ui.Ghost admin = new Ui.Ghost("Admin on/off", new Ui.Glyph(Ui.Glyph.Kind.USER, 13));
      Ui.Ghost ban = new Ui.Ghost("Ban / unban", new Ui.Glyph(Ui.Glyph.Kind.LOCK, 13));
      Ui.Ghost delete = new Ui.Ghost("Delete", new Ui.Glyph(Ui.Glyph.Kind.TRASH, 13));
      password.addActionListener(e -> {
         SolarServer.AccountInfo a = accountList.getSelectedValue();
         if (a != null) {
            String pw = askPassword("New password for " + a.name);
            if (pw != null) {
               try {
                  server.setPassword(a.name, pw);
                  info("Password changed", a.name + " signs in with the new password from now on.");
               } catch (IllegalArgumentException ex) {
                  info("Not changed", ex.getMessage());
               }
            }
         }
      });
      vip.addActionListener(e -> {
         SolarServer.AccountInfo a = accountList.getSelectedValue();
         if (a != null) {
            server.setVip(a.name, !a.vip);
         }
      });
      admin.addActionListener(e -> {
         SolarServer.AccountInfo a = accountList.getSelectedValue();
         if (a != null && (a.admin || confirm("Make " + a.name + " an admin?",
            "Admins are VIP and can use the admin chat commands (/say, /kick, /ban, /unban, /vip) in the game.", "Make admin"))) {
            server.setAdmin(a.name, !a.admin);
         }
      });
      ban.addActionListener(e -> {
         SolarServer.AccountInfo a = accountList.getSelectedValue();
         if (a != null) {
            server.setBanned(a.name, !a.banned);
         }
      });
      delete.addActionListener(e -> {
         SolarServer.AccountInfo a = accountList.getSelectedValue();
         if (a != null && confirm("Delete the account " + a.name + "?",
            "Its name becomes free again and its friends list is lost. This cannot be undone.", "Delete")) {
            server.deleteAccount(a.name);
         }
      });
      Runnable sync = () -> {
         boolean sel = accountList.getSelectedValue() != null;
         password.setEnabled(sel);
         vip.setEnabled(sel);
         admin.setEnabled(sel);
         ban.setEnabled(sel);
         delete.setEnabled(sel);
      };
      accountList.addListSelectionListener(e -> sync.run());
      sync.run();
      p.add(buttons(password, Box.createHorizontalGlue(), vip, admin, ban, delete), BorderLayout.SOUTH);
      return p;
   }

   private JComponent chatPage() {
      JPanel p = new JPanel(new BorderLayout(0, 10));
      p.setOpaque(false);
      logArea.setEditable(false);
      logArea.setLineWrap(true);
      logArea.setWrapStyleWord(true);
      logArea.setOpaque(false);
      logArea.setFont(Theme.regular(12f));
      logArea.setForeground(Theme.TEXT);
      logArea.setSelectionColor(Theme.alpha(Theme.SEA, 90));
      logArea.setBorder(BorderFactory.createEmptyBorder(6, 8, 6, 8));
      p.add(Ui.scroll(logArea), BorderLayout.CENTER);
      JPanel send = new JPanel(new BorderLayout(10, 0));
      send.setOpaque(false);
      send.add(broadcast, BorderLayout.CENTER);
      Ui.Pill go = new Ui.Pill("Send to everyone", new Ui.Glyph(Ui.Glyph.Kind.SEND, 13), Ui.Pill.Kind.PRIMARY, 12.5f);
      Runnable sendNow = () -> {
         String text = broadcast.getText().trim();
         if (!text.isEmpty()) {
            server.broadcast(text);
            broadcast.setText("");
         }
      };
      go.addActionListener(e -> sendNow.run());
      broadcast.addActionListener(e -> sendNow.run());
      send.add(go, BorderLayout.EAST);
      p.add(send, BorderLayout.SOUTH);
      return p;
   }

   // ------------------------------------------------------------ settings

   private JComponent settingsPage() {
      Config cfg = server.config;
      Ui.Field name = new Ui.Field(18, "My Worlds server");
      name.setText(cfg.name);
      Ui.Field welcome = new Ui.Field(28, "No welcome message");
      welcome.setText(cfg.welcome);
      Ui.Field sender = new Ui.Field(10, "Solar");
      sender.setText(cfg.sender);
      JCheckBox signup = Ui.check("Anyone can make an account by signing in with a new name");
      signup.setSelected(cfg.openSignup);
      JCheckBox guests = Ui.check("Allow guests (no account, a guest-N name)");
      guests.setSelected(cfg.guests);
      Ui.Field maxUsers = new Ui.Field(5, "0");
      maxUsers.setText(Integer.toString(cfg.maxUsers));
      Ui.Field port = new Ui.Field(5, "6650");
      port.setText(Integer.toString(cfg.port));
      JCheckBox plain = Ui.check("Normal connections");
      plain.setSelected(cfg.plainEnabled);
      JCheckBox tls = Ui.check("Encrypted connections (TLS)");
      tls.setSelected(cfg.tlsEnabled);
      Ui.Field tlsPort = new Ui.Field(5, "6651");
      tlsPort.setText(Integer.toString(cfg.tlsPort));
      Ui.Note fingerprint = new Ui.Note(" ", Theme.semibold(11.5f), Theme.TEXT, 480);
      JCheckBox autoStart = Ui.check("Start the server when this window opens");
      autoStart.setSelected(cfg.autoStart);
      Ui.Ghost copyFp = new Ui.Ghost("Copy", new Ui.Glyph(Ui.Glyph.Kind.COPY, 12));
      Ui.Ghost newCert = new Ui.Ghost("New certificate", new Ui.Glyph(Ui.Glyph.Kind.REFRESH, 12));
      Runnable showFp = () -> {
         try {
            fingerprint.setText(server.fingerprint());
         } catch (Exception e) {
            fingerprint.setText("Fingerprint: not available (" + e.getMessage() + ")");
         }
      };
      showFp.run();
      copyFp.addActionListener(e -> {
         try {
            copy(server.fingerprint());
         } catch (Exception ex) {
            info("No certificate", ex.getMessage());
         }
      });
      newCert.addActionListener(e -> {
         if (confirm("Make a new certificate?", "Players who pinned the old one will be warned that it changed "
            + "the next time they connect. The server restarts to use it.", "Make a new one")) {
            try {
               server.regenerateCertificate();
               showFp.run();
               if (server.isRunning()) {
                  stopServer();
                  startServer();
               }
            } catch (Exception ex) {
               info("Could not make it", ex.getMessage());
            }
         }
      });

      JPanel cards = new JPanel(new GridBagLayout());
      cards.setOpaque(false);
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.weightx = 1;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.gridy = 0;

      Ui.Card general = section("Server");
      add(general, labelled("Name", name), 0);
      add(general, labelled("Welcome", welcome), 8);
      add(general, note("{user} becomes the player's name. It comes from \"" + cfg.sender + "\" in the chat:"), 2);
      add(general, labelled("Sender", sender), 4);
      cards.add(general, c);

      Ui.Card who = section("Who can join");
      add(who, signup, 0);
      add(who, note("Their account is made with the name and password they type the first time. "
         + "Turn it off to make accounts yourself (Accounts)."), 2);
      add(who, guests, 8);
      add(who, labelled("Players at once", maxUsers), 8);
      add(who, note("0 means no limit."), 2);
      c.gridy++;
      c.insets = new Insets(10, 0, 0, 0);
      cards.add(who, c);

      Ui.Card net = section("Connections");
      add(net, rowOf(plain, labelled("Port", port)), 0);
      add(net, rowOf(tls, labelled("Port", tlsPort)), 8);
      add(net, note("Encrypted connections protect names, passwords and chat on the way. Players tick "
         + "\"Encrypted\" in their launcher; the first time, it shows this fingerprint so they can check it's really your server:"), 2);
      add(net, fingerprint, 6);
      add(net, Ui.row(4, copyFp, newCert), 4);
      c.gridy++;
      cards.add(net, c);

      Ui.Card app = section("This window");
      add(app, autoStart, 0);
      c.gridy++;
      cards.add(app, c);

      Ui.Pill save = new Ui.Pill("Save", new Ui.Glyph(Ui.Glyph.Kind.CHECK, 13), Ui.Pill.Kind.PRIMARY, 13f);
      JLabel saved = Ui.text(" ", Theme.regular(12f), Theme.MUTED);
      save.addActionListener(e -> {
         int p1;
         int p2;
         int max;
         try {
            max = Integer.parseInt(maxUsers.getText().trim());
            if (max < 0) {
               throw new NumberFormatException();
            }
         } catch (NumberFormatException ex) {
            info("Check the number of players", "Type how many players may be online at once (0 for no limit).");
            return;
         }
         try {
            p1 = Integer.parseInt(port.getText().trim());
            p2 = Integer.parseInt(tlsPort.getText().trim());
            if (p1 < 1 || p1 > 65535 || p2 < 1 || p2 > 65535 || p1 == p2) {
               throw new NumberFormatException();
            }
         } catch (NumberFormatException ex) {
            info("Check the ports", "Ports are numbers from 1 to 65535, and the two must be different.");
            return;
         }
         if (!plain.isSelected() && !tls.isSelected()) {
            info("Nothing to connect to", "Leave normal or encrypted connections (or both) turned on.");
            return;
         }
         boolean restart = server.isRunning() && (p1 != cfg.port || p2 != cfg.tlsPort
            || plain.isSelected() != cfg.plainEnabled || tls.isSelected() != cfg.tlsEnabled);
         cfg.name = name.getText().trim().isEmpty() ? "My Worlds server" : name.getText().trim();
         cfg.welcome = welcome.getText().trim();
         cfg.sender = sender.getText().trim().isEmpty() ? "Solar" : sender.getText().trim();
         cfg.openSignup = signup.isSelected();
         cfg.guests = guests.isSelected();
         cfg.maxUsers = max;
         cfg.port = p1;
         cfg.tlsPort = p2;
         cfg.plainEnabled = plain.isSelected();
         cfg.tlsEnabled = tls.isSelected();
         cfg.autoStart = autoStart.isSelected();
         try {
            cfg.save();
         } catch (Exception ex) {
            info("Could not save", ex.getMessage());
            return;
         }
         showFp.run();
         if (restart) {
            stopServer();
            startServer();
            saved.setText("Saved; the server restarted with the new connections.");
         } else {
            saved.setText("Saved.");
         }
         fillAddresses();
      });
      JPanel bottom = new JPanel(new BorderLayout(12, 0));
      bottom.setOpaque(false);
      bottom.add(saved, BorderLayout.CENTER);
      bottom.add(save, BorderLayout.EAST);
      c.gridy++;
      c.insets = new Insets(12, 0, 0, 0);
      cards.add(bottom, c);
      c.gridy++;
      c.weighty = 1;
      JPanel filler = new JPanel();
      filler.setOpaque(false);
      cards.add(filler, c);
      Ui.ScrollPanel holder = new Ui.ScrollPanel(new BorderLayout());
      holder.setBorder(BorderFactory.createEmptyBorder(0, 0, 0, 10));
      holder.add(cards, BorderLayout.NORTH);
      return Ui.scroll(holder);
   }

   private static Ui.Card section(String title) {
      Ui.Card card = new Ui.Card(new GridBagLayout(), 20);
      card.setBorder(BorderFactory.createEmptyBorder(12, 16, 14, 16));
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.gridy = 0;
      c.weightx = 1;
      c.anchor = GridBagConstraints.WEST;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.insets = new Insets(0, 0, 8, 0);
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

   private static JPanel labelled(String label, JComponent field) {
      JPanel p = new JPanel(new BorderLayout(12, 0));
      p.setOpaque(false);
      JLabel l = Ui.text(label, Theme.medium(13f), Theme.TEXT);
      l.setPreferredSize(new Dimension(118, l.getPreferredSize().height));
      p.add(l, BorderLayout.WEST);
      p.add(field, BorderLayout.CENTER);
      return p;
   }

   private static JPanel rowOf(JComponent a, JComponent b) {
      JPanel p = new JPanel(new BorderLayout(16, 0));
      p.setOpaque(false);
      p.add(a, BorderLayout.CENTER);
      p.add(b, BorderLayout.EAST);
      return p;
   }

   private static JComponent note(String text) {
      return new Ui.Note(text, Theme.regular(11.5f), Theme.MUTED, 520);
   }

   private static JPanel buttons(Component... cs) {
      JPanel p = new JPanel();
      p.setOpaque(false);
      p.setLayout(new BoxLayout(p, BoxLayout.X_AXIS));
      for (Component c : cs) {
         p.add(c);
      }
      return p;
   }

   private JComponent footer() {
      JPanel foot = new JPanel(new BorderLayout());
      foot.setOpaque(false);
      foot.add(Ui.text("J Solar Server " + SolarServer.version() + " · Java " + System.getProperty("java.version"),
         Theme.regular(12f), Theme.MUTED), BorderLayout.WEST);
      Ui.Ghost data = new Ui.Ghost("Data folder", new Ui.Glyph(Ui.Glyph.Kind.FOLDER, 14));
      data.setToolTipText(server.dataDir.getAbsolutePath());
      data.addActionListener(e -> openDir(server.dataDir));
      JPanel right = new JPanel(new FlowLayout(FlowLayout.RIGHT, 4, 0));
      right.setOpaque(false);
      right.add(data);
      foot.add(right, BorderLayout.EAST);
      return foot;
   }

   // ------------------------------------------------------------ actions

   private void startServer() {
      try {
         server.start();
      } catch (Exception e) {
         String why = e.getMessage() == null ? e.toString() : e.getMessage();
         if (why.toLowerCase(Locale.ROOT).contains("address already in use")) {
            why = "Another program (maybe another J Solar Server) already uses port " + server.config.port
               + ". Close it, or choose another port in Settings.";
         }
         info("The server could not start", why);
      }
      refreshNow();
   }

   private void stopServer() {
      server.stop();
      refreshNow();
   }

   private void quit() {
      if (server.isRunning() && server.onlineCount() > 0
         && !Ui.ask(frame, "J Solar Server", server.onlineCount() + " player(s) are online. Stop the server and quit?",
         "Stop and quit", "Keep running")) {
         return;
      }
      server.stop();
      frame.dispose();
      System.exit(0);
   }

   private void refreshNow() {
      boolean running = server.isRunning();
      int online = server.onlineCount();
      status.setText(running ? "Running" : "Stopped");
      status.setIcon(Ui.dot(running ? Theme.LAND : Theme.FAINT, 10));
      status.setIconTextGap(8);
      status.setForeground(running ? Theme.LAND : Theme.MUTED);
      int accounts = server.accountList().size();
      statusDetail.setText(running ? online + (online == 1 ? " player" : " players") + " online · "
         + accounts + (accounts == 1 ? " account" : " accounts") : "Players cannot connect while it is stopped");
      startStop.setText(running ? "Stop server" : "Start server");
      startStop.setKind(running ? Ui.Pill.Kind.QUIET : Ui.Pill.Kind.PRIMARY);
      planet.setPaused(!running);
      fillAddresses();

      SolarServer.PlayerInfo selPlayer = playerList.getSelectedValue();
      playerModel.clear();
      for (SolarServer.PlayerInfo p : server.players()) {
         playerModel.addElement(p);
         if (selPlayer != null && p.name.equals(selPlayer.name)) {
            playerList.setSelectedIndex(playerModel.size() - 1);
         }
      }
      playersEmpty.setText(!running ? "The server is stopped. Press Start server on the left."
         : playerModel.isEmpty() ? "Nobody is online yet. Give your friends the address on the left: they type it in the "
         + "OpenWorlds launcher (Online), with any name and password the first time." : "Select a player to disconnect, ban or make VIP.");

      SolarServer.AccountInfo selAccount = accountList.getSelectedValue();
      String filter = accountSearch.getText().trim().toLowerCase(Locale.ROOT);
      accountModel.clear();
      for (SolarServer.AccountInfo a : server.accountList()) {
         if (filter.isEmpty() || a.name.toLowerCase(Locale.ROOT).contains(filter)) {
            accountModel.addElement(a);
            if (selAccount != null && a.name.equals(selAccount.name)) {
               accountList.setSelectedIndex(accountModel.size() - 1);
            }
         }
      }
   }

   private void appendLog(String line) {
      logArea.append(line + "\n");
      int excess = logArea.getLineCount() - 2000;
      if (excess > 0) {
         try {
            logArea.replaceRange("", 0, logArea.getLineEndOffset(excess - 1));
         } catch (javax.swing.text.BadLocationException ignored) {
            // nothing to trim
         }
      }
      logArea.setCaretPosition(logArea.getDocument().getLength());
   }

   private void newAccount() {
      Ui.Field name = new Ui.Field(14, "2 to 16 letters or digits");
      Ui.Secret pw = new Ui.Secret(14, "at least 4 characters");
      JCheckBox vip = Ui.check("VIP");
      JCheckBox admin = Ui.check("Admin (can use the admin chat commands)");
      JPanel form = new JPanel(new GridBagLayout());
      form.setOpaque(false);
      GridBagConstraints c = new GridBagConstraints();
      c.gridx = 0;
      c.weightx = 1;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.gridy = 0;
      form.add(labelled("Name", name), c);
      c.gridy++;
      c.insets = new Insets(8, 0, 0, 0);
      form.add(labelled("Password", pw), c);
      c.gridy++;
      form.add(vip, c);
      c.gridy++;
      form.add(admin, c);
      while (form(frame, "New account", form, "Create", name)) {
         try {
            server.createAccount(name.getText().trim(), new String(pw.getPassword()), vip.isSelected(), admin.isSelected());
            return;
         } catch (IllegalArgumentException e) {
            info("Not created", e.getMessage());
         }
      }
   }

   private String askPassword(String title) {
      Ui.Secret pw = new Ui.Secret(14, "at least 4 characters");
      JPanel form = new JPanel(new BorderLayout());
      form.setOpaque(false);
      form.add(labelled("Password", pw), BorderLayout.CENTER);
      return form(frame, title, form, "Save", pw) ? new String(pw.getPassword()) : null;
   }

   /** A small modal form in the window's colours; true if confirmed. */
   private static boolean form(Component parent, String title, JComponent content, String ok, JComponent focus) {
      JDialog d = new JDialog(SwingUtilities.getWindowAncestor(parent), title, Dialog.ModalityType.APPLICATION_MODAL);
      boolean[] answer = {false};
      SpaceBackground root = new SpaceBackground(new BorderLayout(0, 16), false);
      root.setBorder(BorderFactory.createEmptyBorder(20, 24, 16, 24));
      root.add(Ui.text(title, Theme.bold(20f), Theme.TEXT), BorderLayout.NORTH);
      root.add(content, BorderLayout.CENTER);
      JPanel buttons = new JPanel(new FlowLayout(FlowLayout.RIGHT, 8, 0));
      buttons.setOpaque(false);
      Ui.Ghost cancel = new Ui.Ghost("Cancel", null);
      cancel.addActionListener(e -> d.dispose());
      Ui.Pill yes = new Ui.Pill(ok, null, Ui.Pill.Kind.PRIMARY, 13f);
      yes.addActionListener(e -> {
         answer[0] = true;
         d.dispose();
      });
      buttons.add(cancel);
      buttons.add(yes);
      root.add(buttons, BorderLayout.SOUTH);
      d.setContentPane(root);
      d.getRootPane().setDefaultButton(yes);
      d.addWindowListener(new WindowAdapter() {
         @Override
         public void windowOpened(WindowEvent e) {
            focus.requestFocusInWindow();
         }
      });
      d.pack();
      d.setMinimumSize(new Dimension(420, d.getHeight()));
      d.setLocationRelativeTo(parent);
      d.setVisible(true);
      return answer[0];
   }

   private boolean confirm(String title, String message, String yes) {
      return Ui.ask(frame, title, title + "\n\n" + message, yes, "Cancel");
   }

   private void info(String title, String message) {
      Ui.ask(frame, title, title + "\n\n" + message, "OK", null);
   }

   private void openDir(File dir) {
      dir.mkdirs();
      try {
         Desktop.getDesktop().open(dir);
      } catch (Exception e) {
         info("Data folder", dir.getAbsolutePath());
      }
   }
}
