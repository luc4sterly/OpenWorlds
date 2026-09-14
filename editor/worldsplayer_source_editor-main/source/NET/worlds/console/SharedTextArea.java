package NET.worlds.console;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Point;

interface SharedTextArea {
   void validate();

   void enableLogging(String var1, String var2, boolean var3);

   void disableLogging();

   boolean canAddText();

   void println(String var1);

   void scrollToBottom();

   void poll();

   void setBackground(Color var1);

   void repaint();

   Component getComponent();

   void setForeground(Color var1);

   void setFont(Font var1);

   Point getLocationOnScreen();

   Dimension getSize();
}
