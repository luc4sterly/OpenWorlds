package net.freeworlds.launcher;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSpinner;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.SpinnerNumberModel;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.border.TitledBorder;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Desktop;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.util.function.Consumer;

/** The launcher's window: what to play, with which server and options, and the live log. */
final class LauncherWindow {
   private static final Color BG = new Color(0x14, 0x18, 0x2a);
   private static final Color PANEL = new Color(0x1d, 0x23, 0x3d);
   private static final Color FG = new Color(0xe6, 0xe9, 0xf5);
   private static final Color ACCENT = new Color(0x39, 0x5c, 0xff);
   private static final String[] SERVERS = {"Sin conexion (un jugador)", "whirl local (127.0.0.1:6650)", "Otro servidor..."};

   private final Layout layout;
   private final Settings settings;
   private final JFrame frame = new JFrame("FreeWorlds");
   private final JTextArea logArea = new JTextArea(12, 80);
   private final JLabel status = new JLabel("Listo");
   private final JButton playOriginal = accent(new JButton("Jugar"));
   private final JButton stop = new JButton("Detener");
   private final JComboBox<WorldItem> world = new JComboBox<>();

   /** A world of the install as the combo shows it (GroundZero, not its home: URL). */
   private static final class WorldItem {
      final String url;

      WorldItem(String url) {
         this.url = url;
      }

      @Override
      public String toString() {
         return url.isEmpty() ? "Pantalla de inicio (login)" : Launcher.describeWorld(url) + "   (" + url + ")";
      }
   }
   private final JComboBox<String> server = new JComboBox<>(SERVERS);
   private final JTextField serverHost = new JTextField(16);
   private final JTextField user = new JTextField(12);
   private final JSpinner threads = new JSpinner(new SpinnerNumberModel(0, 0, 64, 1));
   private final JCheckBox fps = new JCheckBox("FPS en el registro");
   private Session running;

   private LauncherWindow(Layout layout, Settings settings) {
      this.layout = layout;
      this.settings = settings;
   }

   static void open(Layout layout, Settings settings) {
      SwingUtilities.invokeLater(() -> {
         try {
            UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
         } catch (Exception ignored) {
            // el look por defecto sirve igual
         }
         new LauncherWindow(layout, settings).build();
      });
   }

   private void build() {
      JPanel root = new JPanel(new BorderLayout(0, 10));
      root.setBackground(BG);
      root.setBorder(BorderFactory.createEmptyBorder(14, 16, 12, 16));

      JPanel head = new JPanel();
      head.setOpaque(false);
      head.setLayout(new BoxLayout(head, BoxLayout.Y_AXIS));
      JLabel title = label("FreeWorlds", 26, Font.BOLD);
      JLabel sub = label("Worlds Chat / WorldsPlayer (1995-2004), preservado  -  version " + Layout.version(), 12, Font.PLAIN);
      head.add(title);
      head.add(sub);
      root.add(head, BorderLayout.NORTH);

      JPanel center = new JPanel();
      center.setOpaque(false);
      center.setLayout(new BoxLayout(center, BoxLayout.Y_AXIS));
      JComponent original = originalPanel();
      // a su altura: lo que sobre de la ventana es para el registro
      original.setMaximumSize(new Dimension(Integer.MAX_VALUE, original.getPreferredSize().height));
      center.add(original);
      center.add(Box.createVerticalStrut(10));
      JScrollPane scroll = new JScrollPane(logArea);
      logArea.setEditable(false);
      logArea.setLineWrap(true);
      logArea.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 11));
      logArea.setBackground(new Color(0x0c, 0x0f, 0x1a));
      logArea.setForeground(new Color(0xb8, 0xc2, 0xe0));
      scroll.setBorder(titled("Registro"));
      scroll.setOpaque(false);
      center.add(scroll);
      root.add(center, BorderLayout.CENTER);

      JPanel foot = new JPanel(new BorderLayout());
      foot.setOpaque(false);
      status.setForeground(FG);
      foot.add(status, BorderLayout.WEST);
      JPanel buttons = new JPanel(new FlowLayout(FlowLayout.RIGHT, 6, 0));
      buttons.setOpaque(false);
      JButton data = new JButton("Carpeta de datos");
      data.addActionListener(e -> openDir(layout.dataDir));
      JButton logs = new JButton("Registros");
      logs.addActionListener(e -> openDir(layout.logDir));
      JButton quit = new JButton("Salir");
      quit.addActionListener(e -> quit());
      stop.setEnabled(false);
      stop.addActionListener(e -> {
         Session s = running;
         if (s != null) {
            s.stop();
         }
      });
      buttons.add(stop);
      buttons.add(data);
      buttons.add(logs);
      buttons.add(quit);
      foot.add(buttons, BorderLayout.EAST);
      root.add(foot, BorderLayout.SOUTH);

      frame.setContentPane(root);
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
      });
      frame.setMinimumSize(new Dimension(720, 560));
      frame.pack();
      frame.setLocationRelativeTo(null);
      frame.setVisible(true);
      append("FreeWorlds " + Layout.version() + "  -  datos de usuario en " + layout.dataDir);
   }

   private JComponent originalPanel() {
      JPanel p = section("Cliente original de 2004 (WorldsPlayer con el puente portable)");
      for (String w : Install.worlds(layout)) {
         world.addItem(new WorldItem(w));
      }
      world.addItem(new WorldItem(""));
      world.setSelectedIndex(0);
      for (int i = 0; i < world.getItemCount(); i++) {
         if (world.getItemAt(i).url.equals(settings.world)) {
            world.setSelectedIndex(i);
         }
      }
      if (settings.server.isEmpty()) {
         server.setSelectedIndex(0);
      } else if (settings.server.equals("127.0.0.1:6650")) {
         server.setSelectedIndex(1);
      } else {
         server.setSelectedIndex(2);
      }
      serverHost.setText(settings.server);
      user.setText(settings.user);
      threads.setValue(settings.rasterThreads);
      fps.setSelected(settings.showFps);
      fps.setOpaque(false);
      fps.setForeground(FG);
      Runnable sync = () -> {
         boolean custom = server.getSelectedIndex() == 2;
         boolean any = server.getSelectedIndex() != 0;
         serverHost.setEnabled(custom);
         user.setEnabled(any);
      };
      server.addActionListener(e -> sync.run());
      sync.run();
      playOriginal.addActionListener(e -> start());
      GridBagConstraints c = gbc();
      row(p, c, "Mundo", world);
      row(p, c, "Servidor", server);
      JPanel hostRow = flow(serverHost, label("Usuario", 12, Font.PLAIN), user);
      row(p, c, "Host:puerto", hostRow);
      JPanel opts = flow(label("Hilos de dibujo (0 = auto)", 12, Font.PLAIN), threads, fps);
      row(p, c, "Opciones", opts);
      c.gridx = 1;
      c.anchor = GridBagConstraints.EAST;
      c.fill = GridBagConstraints.NONE;
      p.add(playOriginal, c);
      return p;
   }

   private void collect() {
      WorldItem w = (WorldItem) world.getSelectedItem();
      settings.world = w == null ? "" : w.url;
      switch (server.getSelectedIndex()) {
         case 0:
            settings.server = "";
            break;
         case 1:
            settings.server = "127.0.0.1:6650";
            break;
         default:
            settings.server = serverHost.getText().trim();
      }
      settings.user = user.getText().trim();
      settings.rasterThreads = (Integer) threads.getValue();
      settings.showFps = fps.isSelected();
      settings.save(layout.settingsFile);
   }

   private void start() {
      if (running != null && running.isRunning()) {
         return;
      }
      collect();
      if (server.getSelectedIndex() == 2 && !settings.server.contains(":")) {
         JOptionPane.showMessageDialog(frame, "Escribe el servidor como host:puerto", "FreeWorlds", JOptionPane.WARNING_MESSAGE);
         return;
      }
      Session s = new Session(layout, settings);
      Consumer<String> sink = this::append;
      s.log.listen(sink);
      running = s;
      setRunning(true, "WorldsPlayer en marcha");
      Thread t = new Thread(() -> {
         int code;
         try {
            s.start();
            code = s.waitFor();
         } catch (Exception e) {
            append("[lanzador] no se pudo arrancar: " + e);
            code = -1;
         }
         final int exit = code;
         SwingUtilities.invokeLater(() -> {
            setRunning(false, "Terminado (codigo " + exit + ")  -  registro: " + s.log.path);
            frame.toFront();
         });
      }, "freeworlds-session");
      t.setDaemon(true);
      t.start();
   }

   private void setRunning(boolean on, String text) {
      playOriginal.setEnabled(!on);
      stop.setEnabled(on);
      status.setText(text);
   }

   private void append(String line) {
      SwingUtilities.invokeLater(() -> {
         logArea.append(line + "\n");
         int excess = logArea.getLineCount() - 2000;
         if (excess > 0) {
            try {
               logArea.replaceRange("", 0, logArea.getLineEndOffset(excess - 1));
            } catch (javax.swing.text.BadLocationException ignored) {
               // se recorta en la siguiente linea
            }
         }
         logArea.setCaretPosition(logArea.getDocument().getLength());
      });
   }

   private void quit() {
      Session s = running;
      if (s != null && s.isRunning()) {
         int r = JOptionPane.showConfirmDialog(frame, "El juego sigue abierto. ¿Cerrarlo y salir?", "FreeWorlds",
            JOptionPane.YES_NO_OPTION);
         if (r != JOptionPane.YES_OPTION) {
            return;
         }
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
         JOptionPane.showMessageDialog(frame, dir.getPath(), "FreeWorlds", JOptionPane.INFORMATION_MESSAGE);
      }
   }

   private static JLabel label(String text, int size, int style) {
      JLabel l = new JLabel(text);
      l.setForeground(FG);
      l.setFont(l.getFont().deriveFont(style, (float) size));
      return l;
   }

   private static JButton accent(JButton b) {
      b.setBackground(ACCENT);
      b.setForeground(Color.WHITE);
      b.setFont(b.getFont().deriveFont(Font.BOLD, 14f));
      b.setFocusPainted(false);
      return b;
   }

   private static TitledBorder titled(String t) {
      TitledBorder b = BorderFactory.createTitledBorder(BorderFactory.createLineBorder(new Color(0x39, 0x44, 0x70)), t);
      b.setTitleColor(FG);
      return b;
   }

   private static JPanel section(String t) {
      JPanel p = new JPanel(new GridBagLayout());
      p.setBackground(PANEL);
      p.setBorder(BorderFactory.createCompoundBorder(titled(t), BorderFactory.createEmptyBorder(4, 8, 8, 8)));
      return p;
   }

   private static JPanel flow(JComponent... cs) {
      JPanel p = new JPanel(new FlowLayout(FlowLayout.LEFT, 6, 0));
      p.setOpaque(false);
      for (JComponent c : cs) {
         p.add(c);
      }
      return p;
   }

   private static GridBagConstraints gbc() {
      GridBagConstraints c = new GridBagConstraints();
      c.insets = new Insets(3, 4, 3, 4);
      c.gridy = 0;
      return c;
   }

   private static void row(JPanel p, GridBagConstraints c, String name, JComponent field) {
      c.gridx = 0;
      c.anchor = GridBagConstraints.WEST;
      c.fill = GridBagConstraints.NONE;
      c.weightx = 0;
      p.add(label(name, 12, Font.BOLD), c);
      c.gridx = 1;
      c.fill = GridBagConstraints.HORIZONTAL;
      c.weightx = 1;
      p.add(field, c);
      c.gridy++;
   }
}
