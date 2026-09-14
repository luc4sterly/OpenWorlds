package NET.worlds.scape;

import NET.worlds.network.URL;

public interface URLSelf extends Persister {
   void incRef();

   void decRef();

   URL getSourceURL();

   void setSourceURL(URL var1);
}
