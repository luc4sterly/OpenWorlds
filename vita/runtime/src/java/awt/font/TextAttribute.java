package java.awt.font;

/** Present for Toolkit.mapInputMethodHighlight's signature. */
public final class TextAttribute {
   private final String name;

   private TextAttribute(String name) {
      this.name = name;
   }

   public static final TextAttribute FAMILY = new TextAttribute("family");
   public static final TextAttribute WEIGHT = new TextAttribute("weight");
   public static final TextAttribute SIZE = new TextAttribute("size");

   public String toString() {
      return getClass().getName() + "(" + name + ")";
   }
}
