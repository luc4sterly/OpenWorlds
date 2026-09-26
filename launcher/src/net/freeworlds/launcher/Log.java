package net.freeworlds.launcher;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.function.Consumer;

/** One session's log: a file under the data dir plus whoever listens (terminal or window). */
final class Log {
   private final PrintWriter file;
   final File path;
   private final CopyOnWriteArrayList<Consumer<String>> listeners = new CopyOnWriteArrayList<>();

   Log(File dir, String name) {
      PrintWriter w = null;
      File p = null;
      try {
         dir.mkdirs();
         p = new File(dir, name + "-" + new SimpleDateFormat("yyyyMMdd-HHmmss").format(new Date()) + ".log");
         w = new PrintWriter(new OutputStreamWriter(new FileOutputStream(p), StandardCharsets.UTF_8), true);
      } catch (IOException e) {
         System.err.println("[log] no se puede escribir el registro en " + dir + ": " + e);
      }
      this.file = w;
      this.path = p;
   }

   void listen(Consumer<String> l) {
      listeners.add(l);
   }

   void unlisten(Consumer<String> l) {
      listeners.remove(l);
   }

   synchronized void line(String s) {
      if (file != null) {
         file.println(s);
      }
      for (Consumer<String> l : listeners) {
         l.accept(s);
      }
   }

   void close() {
      if (file != null) {
         file.close();
      }
   }
}
