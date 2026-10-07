package java.awt.event;

import java.util.EventListener;

public interface AWTEventListener extends EventListener {
   void eventDispatched(java.awt.AWTEvent event);
}
