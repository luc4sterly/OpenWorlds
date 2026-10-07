package java.awt;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.io.FilenameFilter;
import java.util.Arrays;

/**
 * A modal dialog to pick a file to open or save, as java.awt.FileDialog.
 * Windows had its own common dialog; this one is made of AWT controls: the
 * folder, its folders and files, the file name, and the buttons. As on
 * Windows, the FilenameFilter is kept but not used (the JDK documented
 * that), getDirectory() ends with a separator, and Cancel leaves getFile()
 * null.
 */
public class FileDialog extends Dialog {
   public static final int LOAD = 0;
   public static final int SAVE = 1;

   int mode;
   String dir;
   String file;
   FilenameFilter filter;

   private static int nameCounter;

   private TextField folderField;
   private List entries;
   private TextField nameField;
   private File shown;
   private String[] shownNames = new String[0];

   public FileDialog(Frame parent) {
      this(parent, "", LOAD);
   }

   public FileDialog(Frame parent, String title) {
      this(parent, title, LOAD);
   }

   public FileDialog(Frame parent, String title, int mode) {
      super(parent, title, true);
      setMode(mode);
      build();
   }

   public FileDialog(Dialog parent) {
      this(parent, "", LOAD);
   }

   public FileDialog(Dialog parent, String title) {
      this(parent, title, LOAD);
   }

   public FileDialog(Dialog parent, String title, int mode) {
      super(parent, title, true);
      setMode(mode);
      build();
   }

   String constructComponentName() {
      synchronized (FileDialog.class) {
         return "filedlg" + nameCounter++;
      }
   }

   public int getMode() {
      return mode;
   }

   public void setMode(int mode) {
      switch (mode) {
         case LOAD:
         case SAVE:
            this.mode = mode;
            break;
         default:
            throw new IllegalArgumentException("illegal file dialog mode");
      }
   }

   public String getDirectory() {
      return dir;
   }

   public void setDirectory(String dir) {
      this.dir = (dir != null && dir.equals("")) ? null : dir;
   }

   public String getFile() {
      return file;
   }

   public void setFile(String file) {
      this.file = (file != null && file.equals("")) ? null : file;
   }

   public FilenameFilter getFilenameFilter() {
      return filter;
   }

   public synchronized void setFilenameFilter(FilenameFilter filter) {
      this.filter = filter;
   }

   protected String paramString() {
      String str = super.paramString();
      str += ",dir= " + dir;
      str += ",file= " + file;
      return str + ((mode == LOAD) ? ",load" : ",save");
   }

   // ------------------------------------------------------------- the dialog

   private void build() {
      setLayout(new BorderLayout(4, 4));
      Panel top = new Panel(new BorderLayout(4, 0));
      top.add("West", new Label("Folder:"));
      folderField = new TextField(30);
      top.add("Center", folderField);
      Button up = new Button("Up");
      top.add("East", up);
      add("North", top);
      entries = new List(12, false);
      add("Center", entries);
      Panel bottom = new Panel(new BorderLayout(4, 4));
      Panel name = new Panel(new BorderLayout(4, 0));
      name.add("West", new Label("File name:"));
      nameField = new TextField(30);
      name.add("Center", nameField);
      bottom.add("North", name);
      Panel buttons = new Panel(new FlowLayout(FlowLayout.RIGHT, 6, 0));
      Button ok = new Button(mode == SAVE ? "Save" : "Open");
      Button cancel = new Button("Cancel");
      buttons.add(ok);
      buttons.add(cancel);
      bottom.add("South", buttons);
      add("South", bottom);

      folderField.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            File f = new File(folderField.getText());
            if (f.isDirectory()) {
               showFolder(f);
            }
         }
      });
      up.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            File p = shown != null ? shown.getAbsoluteFile().getParentFile() : null;
            if (p != null) {
               showFolder(p);
            }
         }
      });
      entries.addItemListener(new ItemListener() {
         public void itemStateChanged(ItemEvent e) {
            int i = entries.getSelectedIndex();
            if (i >= 0 && i < shownNames.length && !shownNames[i].endsWith("/")) {
               nameField.setText(shownNames[i]);
            }
         }
      });
      entries.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            int i = entries.getSelectedIndex();
            if (i < 0 || i >= shownNames.length) {
               return;
            }
            String n = shownNames[i];
            if (n.equals("../")) {
               File p = shown.getAbsoluteFile().getParentFile();
               if (p != null) {
                  showFolder(p);
               }
            } else if (n.endsWith("/")) {
               showFolder(new File(shown, n.substring(0, n.length() - 1)));
            } else {
               nameField.setText(n);
               accept();
            }
         }
      });
      ActionListener okAction = new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            accept();
         }
      };
      ok.addActionListener(okAction);
      nameField.addActionListener(okAction);
      cancel.addActionListener(new ActionListener() {
         public void actionPerformed(ActionEvent e) {
            file = null;
            setVisible(false);
         }
      });
      addWindowListener(new WindowAdapter() {
         public void windowClosing(WindowEvent e) {
            file = null;
            setVisible(false);
         }
      });
   }

   /** The chosen name: a folder opens, a file ends the dialog (getDirectory with a separator at the end). */
   private void accept() {
      String n = nameField.getText().trim();
      if (n.length() == 0) {
         return;
      }
      File f = new File(n);
      if (!f.isAbsolute()) {
         f = new File(shown, n);
      }
      if (f.isDirectory()) {
         showFolder(f);
         nameField.setText("");
         return;
      }
      if (mode == LOAD && !f.exists()) {
         return;
      }
      File parentDir = f.getAbsoluteFile().getParentFile();
      String d = parentDir != null ? parentDir.getPath() : "";
      if (!d.endsWith(File.separator)) {
         d += File.separator;
      }
      dir = d;
      file = f.getName();
      setVisible(false);
   }

   private void showFolder(File folder) {
      shown = folder.getAbsoluteFile();
      folderField.setText(shown.getPath());
      String[] names = shown.list();
      if (names == null) {
         names = new String[0];
      }
      Arrays.sort(names, String.CASE_INSENSITIVE_ORDER);
      java.util.ArrayList<String> dirs = new java.util.ArrayList<String>();
      java.util.ArrayList<String> files = new java.util.ArrayList<String>();
      if (shown.getParentFile() != null) {
         dirs.add("../");
      }
      for (String n : names) {
         if (new File(shown, n).isDirectory()) {
            dirs.add(n + "/");
         } else {
            files.add(n);
         }
      }
      dirs.addAll(files);
      shownNames = dirs.toArray(new String[dirs.size()]);
      entries.removeAll();
      for (String n : shownNames) {
         entries.add(n);
      }
   }

   /** Opens on the directory set (or the current one), with the file name set. */
   public void show() {
      String start = dir != null ? dir : System.getProperty("user.dir", ".");
      File f = new File(start);
      if (!f.isDirectory()) {
         f = new File(".");
      }
      showFolder(f);
      nameField.setText(file != null ? file : "");
      if (!isDisplayable() || getWidth() <= 0) {
         Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();
         setSize(Math.min(480, screen.width), Math.min(360, screen.height));
         setLocationRelativeTo(getOwner());
      }
      super.show();
   }
}
