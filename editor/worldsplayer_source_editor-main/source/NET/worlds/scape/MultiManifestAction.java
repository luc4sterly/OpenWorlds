package NET.worlds.scape;

import NET.worlds.console.Console;
import NET.worlds.network.URL;
import java.io.File;
import java.io.IOException;

public class MultiManifestAction extends Action implements LoadedURLSelf {
   private String _directory;
   private static Object classCookie = new Object();
   private String[] _files;
   private File _dir;
   private int _curFile;
   private String _file;

   public Object properties(int var1, int var2, int var3, Object var4) throws NoSuchPropertyException {
      Object var5 = null;
      switch (var1 - var2) {
         case 0:
            if (var3 == 0) {
               var5 = StringPropertyEditor.make(new Property(this, var1, "Directory"));
            } else if (var3 == 1) {
               if (this._directory == null) {
                  this._directory = new String();
               }

               var5 = new String(this._directory);
            } else if (var3 == 2) {
               this._directory = ((String)var4).trim();
            }
            break;
         default:
            var5 = super.properties(var1, var2 + 1, var3, var4);
      }

      return var5;
   }

   public void saveState(Saver var1) throws IOException {
      var1.saveVersion(0, classCookie);
      super.saveState(var1);
      var1.saveString(this._directory);
   }

   public void restoreState(Restorer var1) throws IOException, TooNewException {
      switch (var1.restoreVersion(classCookie)) {
         case 0:
            super.restoreState(var1);
            this._directory = var1.restoreString();
            return;
         default:
            throw new TooNewException();
      }
   }

   public Persister trigger(Event var1, Persister var2) {
      if (var2 == null) {
         System.out.println("MMAState:starting");
         this._dir = new File(this._directory);
         this._files = this._dir.list(new ExtensionFilter(".world"));
         this._curFile = 0;
         this.startFile();
      }

      return this._curFile >= this._files.length ? null : this;
   }

   public void startFile() {
      if (this._curFile >= this._files.length) {
         System.out.println("MMAState:Done");
      } else {
         this._file = new File(this._dir, this._files[this._curFile]).getAbsolutePath();
         System.out.println("MMAState:Loading: " + this._file);
         World.load(URL.make(this._file), this);
      }
   }

   public void loadedURLSelf(URLSelf var1, URL var2, String var3) {
      if (var3 == null && var1 instanceof World) {
         World var4 = (World)var1;
         String var5 = this._file.substring(0, this._file.lastIndexOf(".world")) + ".mft";
         System.out.println("MMAState:Manifesting: " + var5);

         try {
            Manifest var6 = new Manifest(var5);
            var6.saveProps(var4);
            var6.done();
         } catch (Exception var7) {
            var7.printStackTrace(System.out);
         }

         if (var4 != Pilot.getActive().getWorld()) {
            var4.discard();
         }
      } else {
         if (var3 == null) {
            var3 = Console.message("No-contain-world");
            var1.decRef();
         }

         Console.println(Console.message("Cant-load-remote") + var2 + "' ");
      }

      this._curFile++;
      this.startFile();
   }
}
