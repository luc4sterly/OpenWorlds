# Mapeador de métodos `native` — WorldsPlayer client vs. `gamma.dll`
Generado automáticamente cruzando los métodos `native` del código Java
decompilado (`editor/worldsplayer_source_editor-main/source/`) contra la
tabla de exports de `move/bin/gamma.dll` (372 símbolos JNI).

- Total declaraciones `native` encontradas: **360**
- Con export JNI correspondiente en `gamma.dll`: **358**
- Sin coincidencia (revisar manualmente — nombre mangled distinto, clase interna, o implementado en otra DLL): **2**

## ✅ Coinciden con un export de gamma.dll

| Clase | Método | Firma | Export(s) en gamma.dll |
|---|---|---|---|
| `NET.worlds.console.ActiveX` | `initActiveX` | `void initActiveX()` | `_Java_NET_worlds_console_ActiveX_initActiveX@8` |
| `NET.worlds.console.ActiveX` | `uninitActiveX` | `void uninitActiveX()` | `_Java_NET_worlds_console_ActiveX_uninitActiveX@8` |
| `NET.worlds.console.ActiveX` | `getClassFClsID` | `int getClassFClsID(String var0, String var1)` | `_Java_NET_worlds_console_ActiveX_getClassFClsID@16` |
| `NET.worlds.console.ActiveX` | `getClassFProgID` | `int getClassFProgID(String var0, String var1)` | `_Java_NET_worlds_console_ActiveX_getClassFProgID@16` |
| `NET.worlds.console.ActiveX` | `getClass` | `int getClass(int var0, String var1)` | `_Java_NET_worlds_console_ActiveX_getClass@16`<br>`_Java_NET_worlds_console_ActiveX_getClassFClsID@16`<br>`_Java_NET_worlds_console_ActiveX_getClassFProgID@16` |
| `NET.worlds.console.ActiveX` | `winProc` | `void winProc()` | `_Java_NET_worlds_console_ActiveX_winProc@8` |
| `NET.worlds.console.Cursor` | `getSystemCursorWidth` | `int getSystemCursorWidth()` | `_Java_NET_worlds_console_Cursor_getSystemCursorWidth@8` |
| `NET.worlds.console.Cursor` | `getSystemCursorHeight` | `int getSystemCursorHeight()` | `_Java_NET_worlds_console_Cursor_getSystemCursorHeight@8` |
| `NET.worlds.console.Cursor` | `getSystemCursorDepth` | `int getSystemCursorDepth()` | `_Java_NET_worlds_console_Cursor_getSystemCursorDepth@8` |
| `NET.worlds.console.Cursor` | `loadCursor` | `int loadCursor(String var0)` | `_Java_NET_worlds_console_Cursor_loadCursor@12` |
| `NET.worlds.console.Cursor` | `loadSystemCursor` | `int loadSystemCursor(String var0)` | `_Java_NET_worlds_console_Cursor_loadSystemCursor@12` |
| `NET.worlds.console.Cursor` | `destroyCursor` | `void destroyCursor(int var0)` | `_Java_NET_worlds_console_Cursor_destroyCursor@12` |
| `NET.worlds.console.FileSysDialog` | `nativeRun` | `String nativeRun()` | `_Java_NET_worlds_console_FileSysDialog_nativeRun@8` |
| `NET.worlds.console.IClassFactory` | `nActivate` | `long nActivate(String var1)` | `_Java_NET_worlds_console_IClassFactory_nActivate@12` |
| `NET.worlds.console.IClassFactory` | `nDeactivate` | `void nDeactivate(long var1)` | `_Java_NET_worlds_console_IClassFactory_nDeactivate@16` |
| `NET.worlds.console.IDispatch` | `Invoke` | `void Invoke(String var1)` | `_Java_NET_worlds_console_IDispatch_Invoke@12` |
| `NET.worlds.console.IEWebControlImp` | `nativeInit` | `boolean nativeInit(int var1, boolean var2)` | `_Java_NET_worlds_console_IEWebControlImp_nativeInit@16` |
| `NET.worlds.console.IEWebControlImp` | `nativeDestroy` | `void nativeDestroy()` | `_Java_NET_worlds_console_IEWebControlImp_nativeDestroy@8` |
| `NET.worlds.console.IEWebControlImp` | `nativeSetURL` | `void nativeSetURL(String var1, String var2)` | `_Java_NET_worlds_console_IEWebControlImp_nativeSetURL@16` |
| `NET.worlds.console.IEWebControlImp` | `nativeGoBack` | `void nativeGoBack()` | `_Java_NET_worlds_console_IEWebControlImp_nativeGoBack@8` |
| `NET.worlds.console.IEWebControlImp` | `nativeGoForward` | `void nativeGoForward()` | `_Java_NET_worlds_console_IEWebControlImp_nativeGoForward@8` |
| `NET.worlds.console.IEWebControlImp` | `nativeStop` | `void nativeStop()` | `_Java_NET_worlds_console_IEWebControlImp_nativeStop@8` |
| `NET.worlds.console.IEWebControlImp` | `nativeRefresh` | `void nativeRefresh()` | `_Java_NET_worlds_console_IEWebControlImp_nativeRefresh@8` |
| `NET.worlds.console.IEWebControlImp` | `nativeHome` | `void nativeHome()` | `_Java_NET_worlds_console_IEWebControlImp_nativeHome@8` |
| `NET.worlds.console.IEWebControlImp` | `nativePrint` | `void nativePrint(int var1, int var2)` | `_Java_NET_worlds_console_IEWebControlImp_nativePrint@16` |
| `NET.worlds.console.IEWebControlImp` | `nativeResize` | `void nativeResize(int var1, int var2, int var3, int var4)` | `_Java_NET_worlds_console_IEWebControlImp_nativeResize@24` |
| `NET.worlds.console.IEWebControlImp` | `nativeAddToolbar` | `void nativeAddToolbar()` | `_Java_NET_worlds_console_IEWebControlImp_nativeAddToolbar@8` |
| `NET.worlds.console.IEWebControlImp` | `nativeGetHWND` | `int nativeGetHWND()` | `_Java_NET_worlds_console_IEWebControlImp_nativeGetHWND@8` |
| `NET.worlds.console.INetscapeRegistry` | `RegisterViewer` | `boolean RegisterViewer(String var1, String var2)` | `_Java_NET_worlds_console_INetscapeRegistry_RegisterViewer@16` |
| `NET.worlds.console.INetscapeRegistry` | `RegisterProtocol` | `boolean RegisterProtocol(String var1, String var2)` | `_Java_NET_worlds_console_INetscapeRegistry_RegisterProtocol@16` |
| `NET.worlds.console.IUnknown` | `true_AddRef` | `void true_AddRef()` | `_Java_NET_worlds_console_IUnknown_true_1AddRef@8` |
| `NET.worlds.console.IUnknown` | `QueryInterface` | `int QueryInterface(String var1)` | `_Java_NET_worlds_console_IUnknown_QueryInterface@12` |
| `NET.worlds.console.IUnknown` | `true_Release` | `void true_Release()` | `_Java_NET_worlds_console_IUnknown_true_1Release@8` |
| `NET.worlds.console.IUnknown` | `getPtr` | `int getPtr()` | `_Java_NET_worlds_console_IUnknown_getPtr@8` |
| `NET.worlds.console.IWebBrowserApp` | `put_Visible` | `void put_Visible(boolean var1)` | `_Java_NET_worlds_console_IWebBrowserApp_put_1Visible@12` |
| `NET.worlds.console.IWebBrowserApp` | `put_StatusBar` | `void put_StatusBar(boolean var1)` | `_Java_NET_worlds_console_IWebBrowserApp_put_1StatusBar@12` |
| `NET.worlds.console.IWebBrowserApp` | `put_MenuBar` | `void put_MenuBar(boolean var1)` | `_Java_NET_worlds_console_IWebBrowserApp_put_1MenuBar@12` |
| `NET.worlds.console.IWebBrowserApp` | `Navigate` | `void Navigate(String var1)` | `_Java_NET_worlds_console_IWebBrowserApp_Navigate@12` |
| `NET.worlds.console.IWebBrowserApp` | `Quit` | `void Quit()` | `_Java_NET_worlds_console_IWebBrowserApp_Quit@8` |
| `NET.worlds.console.NSProtocolHandler` | `createLocal` | `int createLocal()` | `_Java_NET_worlds_console_NSProtocolHandler_createLocal@8` |
| `NET.worlds.console.RenderCanvasOverlay` | `nativeMakeChild` | `int nativeMakeChild(long var1, int var3, int var4, boolean var5)` | `_Java_NET_worlds_console_RenderCanvasOverlay_nativeMakeChild@28` |
| `NET.worlds.console.RenderCanvasOverlay` | `nativeKillChild` | `void nativeKillChild(long var1)` | `_Java_NET_worlds_console_RenderCanvasOverlay_nativeKillChild@16` |
| `NET.worlds.console.RenderCanvasOverlay` | `nativeResizeChild` | `void nativeResizeChild(int var1, int var2, int var3)` | `_Java_NET_worlds_console_RenderCanvasOverlay_nativeResizeChild@20` |
| `NET.worlds.console.RightMenu` | `create` | `int create()` | `_Java_NET_worlds_console_RightMenu_create@8` |
| `NET.worlds.console.RightMenu` | `nativeAdd` | `void nativeAdd(String var0, int var1, int var2)` | `_Java_NET_worlds_console_RightMenu_nativeAdd@20` |
| `NET.worlds.console.RightMenu` | `addSeparator` | `void addSeparator(int var0)` | `_Java_NET_worlds_console_RightMenu_addSeparator@12` |
| `NET.worlds.console.RightMenu` | `show` | `void show(int var0, int var1)` | `_Java_NET_worlds_console_RightMenu_show@16` |
| `NET.worlds.console.RightMenu` | `discard` | `void discard(int var0)` | `_Java_NET_worlds_console_RightMenu_discard@12` |
| `NET.worlds.console.RightMenu` | `checkPressed` | `int checkPressed()` | `_Java_NET_worlds_console_RightMenu_checkPressed@8` |
| `NET.worlds.console.ScapePicCanvas` | `bitBlt` | `void bitBlt(int var0, int var1, int var2, int var3, int var4, int var5, int var6, int var7)` | `_Java_NET_worlds_console_ScapePicCanvas_bitBlt@40` |
| `NET.worlds.console.ScapePicImage` | `flush` | `void flush()` | `_Java_NET_worlds_console_ScapePicImage_flush@8` |
| `NET.worlds.console.ScapePicImage` | `loadImage` | `void loadImage(String var1)` | `_Java_NET_worlds_console_ScapePicImage_loadImage@12` |
| `NET.worlds.console.ScapePicImage` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_console_ScapePicImage_nativeInit@8` |
| `NET.worlds.console.Startup` | `synchronizeStartup` | `boolean synchronizeStartup(String var0, boolean var1)` | `_Java_NET_worlds_console_Startup_synchronizeStartup@16` |
| `NET.worlds.console.Startup` | `getVolumeInfo` | `int getVolumeInfo()` | `_Java_NET_worlds_console_Startup_getVolumeInfo@8` |
| `NET.worlds.console.Startup` | `computeVolumeInfo` | `void computeVolumeInfo(String var0)` | `_Java_NET_worlds_console_Startup_computeVolumeInfo@12` |
| `NET.worlds.console.StatMemNode` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_console_StatMemNode_nativeInit@8` |
| `NET.worlds.console.StatMemNode` | `updateMemoryStatus` | `void updateMemoryStatus()` | `_Java_NET_worlds_console_StatMemNode_updateMemoryStatus@8` |
| `NET.worlds.console.VoiceChat` | `terminateVC` | `void terminateVC(int var0)` | `_Java_NET_worlds_console_VoiceChat_terminateVC@12` |
| `NET.worlds.console.WebBrowser` | `browse` | `void browse(String var0, String var1, int var2, int var3, int var4, int var5, int var6)` | `_Java_NET_worlds_console_WebBrowser_browse@36` |
| `NET.worlds.console.WebBrowser` | `openBrowser` | `int openBrowser()` | `_Java_NET_worlds_console_WebBrowser_openBrowser@8` |
| `NET.worlds.console.WebBrowser` | `closeBrowser` | `void closeBrowser(int var0)` | `_Java_NET_worlds_console_WebBrowser_closeBrowser@12` |
| `NET.worlds.console.Window` | `setChatLine` | `void setChatLine(int var0)` | `_Java_NET_worlds_console_Window_setChatLine@12` |
| `NET.worlds.console.Window` | `getVoiceChatWParam` | `int getVoiceChatWParam()` | `_Java_NET_worlds_console_Window_getVoiceChatWParam@8` |
| `NET.worlds.console.Window` | `getVoiceChatLParam` | `int getVoiceChatLParam()` | `_Java_NET_worlds_console_Window_getVoiceChatLParam@8` |
| `NET.worlds.console.Window` | `resetVoiceChatMsg` | `void resetVoiceChatMsg()` | `_Java_NET_worlds_console_Window_resetVoiceChatMsg@8` |
| `NET.worlds.console.Window` | `doMicrosoftVMHacks` | `void doMicrosoftVMHacks()` | `_Java_NET_worlds_console_Window_doMicrosoftVMHacks@8` |
| `NET.worlds.console.Window` | `usingMicrosoftVMHacks` | `boolean usingMicrosoftVMHacks()` | `_Java_NET_worlds_console_Window_usingMicrosoftVMHacks@8` |
| `NET.worlds.console.Window` | `getActivated` | `boolean getActivated()` | `_Java_NET_worlds_console_Window_getActivated@8` |
| `NET.worlds.console.Window` | `isActivated` | `boolean isActivated()` | `_Java_NET_worlds_console_Window_isActivated@8` |
| `NET.worlds.console.Window` | `getGammaProcessID` | `int getGammaProcessID()` | `_Java_NET_worlds_console_Window_getGammaProcessID@8` |
| `NET.worlds.console.Window` | `dispose` | `void dispose()` | `_Java_NET_worlds_console_Window_dispose@8` |
| `NET.worlds.console.Window` | `getHwnd` | `int getHwnd()` | `_Java_NET_worlds_console_Window_getHwnd@8` |
| `NET.worlds.console.Window` | `nativeHideChildWindow` | `void nativeHideChildWindow(int var1)` | `_Java_NET_worlds_console_Window_nativeHideChildWindow@12` |
| `NET.worlds.console.Window` | `nativeShowChildWindow` | `void nativeShowChildWindow(int var1)` | `_Java_NET_worlds_console_Window_nativeShowChildWindow@12` |
| `NET.worlds.console.Window` | `maybeResize` | `void maybeResize(int var1, int var2)` | `_Java_NET_worlds_console_Window_maybeResize@16` |
| `NET.worlds.console.Window` | `setDeltaMode` | `void setDeltaMode(boolean var1)` | `_Java_NET_worlds_console_Window_setDeltaMode@12` |
| `NET.worlds.console.Window` | `getAndResetUserActionCount` | `int getAndResetUserActionCount()` | `_Java_NET_worlds_console_Window_getAndResetUserActionCount@8` |
| `NET.worlds.console.Window` | `getDeltaMode` | `boolean getDeltaMode()` | `_Java_NET_worlds_console_Window_getDeltaMode@8` |
| `NET.worlds.console.Window` | `makeJavaReleaseCapture` | `void makeJavaReleaseCapture()` | `_Java_NET_worlds_console_Window_makeJavaReleaseCapture@8` |
| `NET.worlds.console.Window` | `reShape` | `void reShape(int var1, int var2, int var3, int var4)` | `_Java_NET_worlds_console_Window_reShape@24` |
| `NET.worlds.console.Window` | `fullWidth` | `int fullWidth()` | `_Java_NET_worlds_console_Window_fullWidth@8` |
| `NET.worlds.console.Window` | `fullHeight` | `int fullHeight()` | `_Java_NET_worlds_console_Window_fullHeight@8` |
| `NET.worlds.console.Window` | `findWindow` | `int findWindow(String var0)` | `_Java_NET_worlds_console_Window_findWindow@12` |
| `NET.worlds.console.Window` | `getFrameWindow` | `int getFrameWindow()` | `_Java_NET_worlds_console_Window_getFrameWindow@8` |
| `NET.worlds.console.Window` | `hideCursor` | `void hideCursor()` | `_Java_NET_worlds_console_Window_hideCursor@8` |
| `NET.worlds.console.Window` | `getHiddenCursorDelta` | `int[] getHiddenCursorDelta()` | `_Java_NET_worlds_console_Window_getHiddenCursorDelta@8` |
| `NET.worlds.console.Window` | `setCursor` | `void setCursor(int var0)` | `_Java_NET_worlds_console_Window_setCursor@12` |
| `NET.worlds.console.Window` | `getWindowState` | `int getWindowState(int var0)` | `_Java_NET_worlds_console_Window_getWindowState@12` |
| `NET.worlds.console.Window` | `setWindowState` | `void setWindowState(int var0, int var1)` | `_Java_NET_worlds_console_Window_setWindowState@16` |
| `NET.worlds.console.Window` | `setForegroundWindow` | `void setForegroundWindow(int var0)` | `_Java_NET_worlds_console_Window_setForegroundWindow@12` |
| `NET.worlds.console.Window` | `setVideoMode` | `void setVideoMode(int var0, int var1, int var2)` | `_Java_NET_worlds_console_Window_setVideoMode@20` |
| `NET.worlds.console.Window` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_console_Window_nativeInit@8` |
| `NET.worlds.console.Window` | `install` | `int install(boolean var1)` | `_Java_NET_worlds_console_Window_install@12` |
| `NET.worlds.console.Window` | `nativeIsLastLineVisible` | `int nativeIsLastLineVisible(int var0, int var1, int var2)` | `_Java_NET_worlds_console_Window_nativeIsLastLineVisible@20` |
| `NET.worlds.console.Window` | `nativeFindChildWindow` | `int nativeFindChildWindow(int var0, int var1, int var2, int var3, int var4)` | `_Java_NET_worlds_console_Window_nativeFindChildWindow@28` |
| `NET.worlds.console.Window` | `nativeFindOrMakeChildWindow` | `int nativeFindOrMakeChildWindow(int var0, int var1, int var2, int var3, int var4)` | `_Java_NET_worlds_console_Window_nativeFindOrMakeChildWindow@28` |
| `NET.worlds.console.Window` | `isVideoPlaying` | `boolean isVideoPlaying(int var0)` | `_Java_NET_worlds_console_Window_isVideoPlaying@12` |
| `NET.worlds.console.Window` | `playVideoClip` | `int playVideoClip(String var0, int var1)` | `_Java_NET_worlds_console_Window_playVideoClip@16` |
| `NET.worlds.console.Window` | `hookWinAPIs` | `void hookWinAPIs(String var0)` | `_Java_NET_worlds_console_Window_hookWinAPIs@12` |
| `NET.worlds.console.Window` | `getWindowWidth` | `int getWindowWidth(int var0)` | `_Java_NET_worlds_console_Window_getWindowWidth@12` |
| `NET.worlds.console.Window` | `getWindowHeight` | `int getWindowHeight(int var0)` | `_Java_NET_worlds_console_Window_getWindowHeight@12` |
| `NET.worlds.console.Window` | `allowFGJavaPalette` | `void allowFGJavaPalette(boolean var0)` | `_Java_NET_worlds_console_Window_allowFGJavaPalette@12` |
| `NET.worlds.console.Window` | `getSystemMetrics` | `int getSystemMetrics(int var0)` | `_Java_NET_worlds_console_Window_getSystemMetrics@12` |
| `NET.worlds.core.FastDataInput` | `close` | `void close()` | `_Java_NET_worlds_core_FastDataInput_close@8` |
| `NET.worlds.core.FastDataInput` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_core_FastDataInput_nativeInit@8` |
| `NET.worlds.core.FastDataInput` | `readFully` | `void readFully(byte[] var1, int var2, int var3)` | `_Java_NET_worlds_core_FastDataInput_readFully@20` |
| `NET.worlds.core.FastDataInput` | `skipBytes` | `int skipBytes(int var1)` | `_Java_NET_worlds_core_FastDataInput_skipBytes@12` |
| `NET.worlds.core.FastDataInput` | `readBoolean` | `boolean readBoolean()` | `_Java_NET_worlds_core_FastDataInput_readBoolean@8` |
| `NET.worlds.core.FastDataInput` | `readByte` | `byte readByte()` | `_Java_NET_worlds_core_FastDataInput_readByte@8` |
| `NET.worlds.core.FastDataInput` | `readUnsignedByte` | `int readUnsignedByte()` | `_Java_NET_worlds_core_FastDataInput_readUnsignedByte@8` |
| `NET.worlds.core.FastDataInput` | `readShort` | `short readShort()` | `_Java_NET_worlds_core_FastDataInput_readShort@8` |
| `NET.worlds.core.FastDataInput` | `readUnsignedShort` | `int readUnsignedShort()` | `_Java_NET_worlds_core_FastDataInput_readUnsignedShort@8` |
| `NET.worlds.core.FastDataInput` | `readChar` | `char readChar()` | `_Java_NET_worlds_core_FastDataInput_readChar@8` |
| `NET.worlds.core.FastDataInput` | `readInt` | `int readInt()` | `_Java_NET_worlds_core_FastDataInput_readInt@8` |
| `NET.worlds.core.FastDataInput` | `readLong` | `long readLong()` | `_Java_NET_worlds_core_FastDataInput_readLong@8` |
| `NET.worlds.core.FastDataInput` | `readFloat` | `float readFloat()` | `_Java_NET_worlds_core_FastDataInput_readFloat@8` |
| `NET.worlds.core.FastDataInput` | `readDouble` | `double readDouble()` | `_Java_NET_worlds_core_FastDataInput_readDouble@8` |
| `NET.worlds.core.FastDataInput` | `readUTF` | `String readUTF()` | `_Java_NET_worlds_core_FastDataInput_readUTF@8` |
| `NET.worlds.core.FastDataInput` | `read` | `void read(String var1)` | `_Java_NET_worlds_core_FastDataInput_read@12`<br>`_Java_NET_worlds_core_FastDataInput_readBoolean@8`<br>`_Java_NET_worlds_core_FastDataInput_readByte@8`<br>`_Java_NET_worlds_core_FastDataInput_readChar@8`<br>`_Java_NET_worlds_core_FastDataInput_readDouble@8`<br>`_Java_NET_worlds_core_FastDataInput_readFloat@8`<br>`_Java_NET_worlds_core_FastDataInput_readFully@20`<br>`_Java_NET_worlds_core_FastDataInput_readInt@8`<br>`_Java_NET_worlds_core_FastDataInput_readLong@8`<br>`_Java_NET_worlds_core_FastDataInput_readShort@8`<br>`_Java_NET_worlds_core_FastDataInput_readUTF@8`<br>`_Java_NET_worlds_core_FastDataInput_readUnsignedByte@8`<br>`_Java_NET_worlds_core_FastDataInput_readUnsignedShort@8` |
| `NET.worlds.core.IniFile` | `getIniInt` | `int getIniInt(String var1, int var2)` | `_Java_NET_worlds_core_IniFile_getIniInt@16` |
| `NET.worlds.core.IniFile` | `setIniInt` | `void setIniInt(String var1, int var2)` | `_Java_NET_worlds_core_IniFile_setIniInt@16` |
| `NET.worlds.core.IniFile` | `getIniString` | `String getIniString(String var1, String var2)` | `_Java_NET_worlds_core_IniFile_getIniString@16` |
| `NET.worlds.core.IniFile` | `setIniString` | `void setIniString(String var1, String var2)` | `_Java_NET_worlds_core_IniFile_setIniString@16` |
| `NET.worlds.core.IniFile` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_core_IniFile_nativeInit@8` |
| `NET.worlds.core.RegKey` | `getStringValue` | `String getStringValue(String var1)` | `_Java_NET_worlds_core_RegKey_getStringValue@12` |
| `NET.worlds.core.RegKey` | `setStringValue` | `boolean setStringValue(String var1, String var2, boolean var3)` | `_Java_NET_worlds_core_RegKey_setStringValue@20` |
| `NET.worlds.core.RegKey` | `getIntValue` | `int getIntValue(String var1)` | `_Java_NET_worlds_core_RegKey_getIntValue@12` |
| `NET.worlds.core.RegKey` | `setIntValue` | `boolean setIntValue(String var1, int var2)` | `_Java_NET_worlds_core_RegKey_setIntValue@16` |
| `NET.worlds.core.RegKey` | `close` | `void close()` | `_Java_NET_worlds_core_RegKey_close@8` |
| `NET.worlds.core.RegKey` | `getReservedKey` | `int getReservedKey(int var0)` | `_Java_NET_worlds_core_RegKey_getReservedKey@12` |
| `NET.worlds.core.RegKey` | `openKey` | `int openKey(int var0, String var1, int var2)` | `_Java_NET_worlds_core_RegKey_openKey@20` |
| `NET.worlds.core.RegKey` | `createKey` | `int createKey(int var0, String var1)` | `_Java_NET_worlds_core_RegKey_createKey@16` |
| `NET.worlds.core.RegKey` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_core_RegKey_nativeInit@8` |
| `NET.worlds.core.Std` | `exit` | `void exit()` | `_Java_NET_worlds_core_Std_exit@8` |
| `NET.worlds.core.Std` | `nativeGetMillis` | `int nativeGetMillis()` | `_Java_NET_worlds_core_Std_nativeGetMillis@8` |
| `NET.worlds.core.Std` | `getTimeZero` | `int getTimeZero()` | `_Java_NET_worlds_core_Std_getTimeZero@8` |
| `NET.worlds.core.Std` | `getPerformanceFrequency` | `long getPerformanceFrequency()` | `_Java_NET_worlds_core_Std_getPerformanceFrequency@8` |
| `NET.worlds.core.Std` | `getPerformanceCount` | `long getPerformanceCount()` | `_Java_NET_worlds_core_Std_getPerformanceCount@8` |
| `NET.worlds.core.Std` | `instanceOf` | `boolean instanceOf(Object var0, Class var1)` | `_Java_NET_worlds_core_Std_instanceOf@16` |
| `NET.worlds.core.Std` | `getenv` | `String getenv(String var0)` | `_Java_NET_worlds_core_Std_getenv@12` |
| `NET.worlds.core.Std` | `GetDiskFreeSpace` | `int GetDiskFreeSpace(String var0)` | `?Java_NET_worlds_core_Std_GetDiskFreeSpace__Ljava_lang_String_2@@YGJPAUJNIEnv_@@PAV_jclass@@PAV_jstring@@@Z`<br>`_Java_NET_worlds_core_Std_GetDiskFreeSpace@12` |
| `NET.worlds.core.Std` | `byteArraysEqual` | `boolean byteArraysEqual(byte[] var0, byte[] var1)` | `_Java_NET_worlds_core_Std_byteArraysEqual@16` |
| `NET.worlds.core.Std` | `getBuildInfo` | `String getBuildInfo()` | `_Java_NET_worlds_core_Std_getBuildInfo@8` |
| `NET.worlds.core.Std` | `getVersion` | `int getVersion()` | `_Java_NET_worlds_core_Std_getVersion@8` |
| `NET.worlds.core.Std` | `getClientVersion` | `String getClientVersion()` | `_Java_NET_worlds_core_Std_getClientVersion@8` |
| `NET.worlds.core.Std` | `getBuildYear` | `int getBuildYear()` | `_Java_NET_worlds_core_Std_getBuildYear@8` |
| `NET.worlds.core.Std` | `getBuildMonth` | `int getBuildMonth()` | `_Java_NET_worlds_core_Std_getBuildMonth@8` |
| `NET.worlds.core.Std` | `getBuildDay` | `int getBuildDay()` | `_Java_NET_worlds_core_Std_getBuildDay@8` |
| `NET.worlds.core.Std` | `checkNativeHeap` | `int checkNativeHeap()` | `_Java_NET_worlds_core_Std_checkNativeHeap@8` |
| `NET.worlds.core.SystemInfo` | `GetDiskFreeSpace` | `int GetDiskFreeSpace(String var0)` | `?Java_NET_worlds_core_SystemInfo_GetDiskFreeSpace__Ljava_lang_String_2@@YGJPAUJNIEnv_@@PAV_jclass@@PAV_jstring@@@Z`<br>`_Java_NET_worlds_core_SystemInfo_GetDiskFreeSpace@12` |
| `NET.worlds.core.SystemInfo` | `GetSystemDirectory` | `String GetSystemDirectory()` | `_Java_NET_worlds_core_SystemInfo_GetSystemDirectory@8` |
| `NET.worlds.core.SystemInfo` | `GetCurrentDirectory` | `String GetCurrentDirectory()` | `_Java_NET_worlds_core_SystemInfo_GetCurrentDirectory@8` |
| `NET.worlds.core.SystemInfo` | `GetTotalPhysicalMemory` | `int GetTotalPhysicalMemory()` | `_Java_NET_worlds_core_SystemInfo_GetTotalPhysicalMemory@8` |
| `NET.worlds.core.SystemInfo` | `GetAvailPhysicalMemory` | `int GetAvailPhysicalMemory()` | `_Java_NET_worlds_core_SystemInfo_GetAvailPhysicalMemory@8` |
| `NET.worlds.core.SystemInfo` | `GetTotalPagedMemory` | `int GetTotalPagedMemory()` | `_Java_NET_worlds_core_SystemInfo_GetTotalPagedMemory@8` |
| `NET.worlds.core.SystemInfo` | `GetAvailPagedMemory` | `int GetAvailPagedMemory()` | `_Java_NET_worlds_core_SystemInfo_GetAvailPagedMemory@8` |
| `NET.worlds.core.SystemInfo` | `GetPlatformID` | `String GetPlatformID()` | `_Java_NET_worlds_core_SystemInfo_GetPlatformID@8` |
| `NET.worlds.core.SystemInfo` | `GetNumberOfProcessors` | `int GetNumberOfProcessors()` | `_Java_NET_worlds_core_SystemInfo_GetNumberOfProcessors@8` |
| `NET.worlds.core.SystemInfo` | `GetProcessorType` | `String GetProcessorType()` | `_Java_NET_worlds_core_SystemInfo_GetProcessorType@8` |
| `NET.worlds.network.DDEMLClass` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_network_DDEMLClass_nativeInit@8` |
| `NET.worlds.network.DDEMLClass` | `create` | `boolean create(String var1, String var2)` | `_Java_NET_worlds_network_DDEMLClass_create@16` |
| `NET.worlds.network.DDEMLClass` | `destroy` | `void destroy()` | `_Java_NET_worlds_network_DDEMLClass_destroy@8` |
| `NET.worlds.network.DDEMLClass` | `Request` | `boolean Request(String var1)` | `_Java_NET_worlds_network_DDEMLClass_Request@12` |
| `NET.worlds.network.DDEMLClass` | `Poke` | `boolean Poke(String var1, String var2)` | `_Java_NET_worlds_network_DDEMLClass_Poke@16` |
| `NET.worlds.network.DNSLookup` | `gethostbyname` | `String[] gethostbyname(String var0)` | `_Java_NET_worlds_network_DNSLookup_gethostbyname@12` |
| `NET.worlds.network.NetUpdate` | `CreateProcSpecial` | `boolean CreateProcSpecial(String var0, String var1)` | `_Java_NET_worlds_network_NetUpdate_CreateProcSpecial@16` |
| `NET.worlds.scape.ASFSoundPlayer` | `nativePlay` | `boolean nativePlay(String var0)` | `?Java_NET_worlds_scape_ASFSoundPlayer_nativePlay@@YGEPAUJNIEnv_@@PAV_jclass@@PAV_jstring@@@Z` |
| `NET.worlds.scape.CDPlayerAction` | `getNumDrives` | `int getNumDrives()` | `_Java_NET_worlds_scape_CDPlayerAction_getNumDrives@8` |
| `NET.worlds.scape.CDPlayerAction` | `getDriveLetterOffset` | `int getDriveLetterOffset(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_getDriveLetterOffset@12` |
| `NET.worlds.scape.CDPlayerAction` | `openDrive` | `int openDrive(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_openDrive@12` |
| `NET.worlds.scape.CDPlayerAction` | `closeDrive` | `void closeDrive(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_closeDrive@12` |
| `NET.worlds.scape.CDPlayerAction` | `checkDrive` | `void checkDrive(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_checkDrive@12` |
| `NET.worlds.scape.CDPlayerAction` | `getDriveTrackList` | `CDTrackInfo getDriveTrackList(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_getDriveTrackList@12` |
| `NET.worlds.scape.CDPlayerAction` | `playAudio` | `void playAudio(int var0, int var1, int var2)` | `_Java_NET_worlds_scape_CDPlayerAction_playAudio@20` |
| `NET.worlds.scape.CDPlayerAction` | `stopAudio` | `void stopAudio(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_stopAudio@12` |
| `NET.worlds.scape.CDPlayerAction` | `pauseAudio` | `void pauseAudio(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_pauseAudio@12` |
| `NET.worlds.scape.CDPlayerAction` | `resumeAudio` | `void resumeAudio(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_resumeAudio@12` |
| `NET.worlds.scape.CDPlayerAction` | `isPlaying` | `boolean isPlaying(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_isPlaying@12` |
| `NET.worlds.scape.CDPlayerAction` | `getPosition` | `int getPosition(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_getPosition@12` |
| `NET.worlds.scape.CDPlayerAction` | `setNTAutoPlayCode` | `void setNTAutoPlayCode(int var0)` | `_Java_NET_worlds_scape_CDPlayerAction_setNTAutoPlayCode@12` |
| `NET.worlds.scape.CDPlayerAction` | `launchVolumeControlApp` | `boolean launchVolumeControlApp()` | `_Java_NET_worlds_scape_CDPlayerAction_launchVolumeControlApp@8` |
| `NET.worlds.scape.Camera` | `cameraNativeInit` | `void cameraNativeInit()` | `_Java_NET_worlds_scape_Camera_cameraNativeInit@8` |
| `NET.worlds.scape.Camera` | `nDrawText` | `void nDrawText(String var1, int var2, int var3, int var4, int var5)` | `_Java_NET_worlds_scape_Camera_nDrawText@28` |
| `NET.worlds.scape.Camera` | `renderScene` | `WObject renderScene(int var1, int var2, int var3, int var4, Pilot var5)` | `_Java_NET_worlds_scape_Camera_renderScene@28` |
| `NET.worlds.scape.DirectShow` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_DirectShow_nativeInit@8` |
| `NET.worlds.scape.DirectShow` | `nInit` | `void nInit(int var1)` | `_Java_NET_worlds_scape_DirectShow_nInit@12` |
| `NET.worlds.scape.DirectShow` | `nShutdown` | `void nShutdown()` | `_Java_NET_worlds_scape_DirectShow_nShutdown@8` |
| `NET.worlds.scape.DirectShow` | `nOpen` | `void nOpen(String var1)` | `_Java_NET_worlds_scape_DirectShow_nOpen@12` |
| `NET.worlds.scape.DirectShow` | `nPlay` | `void nPlay(int var1)` | `_Java_NET_worlds_scape_DirectShow_nPlay@12` |
| `NET.worlds.scape.DirectShow` | `nStop` | `void nStop()` | `_Java_NET_worlds_scape_DirectShow_nStop@8` |
| `NET.worlds.scape.DirectShow` | `nPause` | `void nPause()` | `_Java_NET_worlds_scape_DirectShow_nPause@8` |
| `NET.worlds.scape.DirectShow` | `nRenderTo` | `void nRenderTo(int var1, int var2)` | `_Java_NET_worlds_scape_DirectShow_nRenderTo@16` |
| `NET.worlds.scape.DirectShow` | `nTick` | `int nTick()` | `_Java_NET_worlds_scape_DirectShow_nTick@8` |
| `NET.worlds.scape.DroneAnimator` | `init` | `void init(String var0)` | `_Java_NET_worlds_scape_DroneAnimator_init@12` |
| `NET.worlds.scape.DroneAnimator` | `loadconfig` | `void loadconfig(String var0)` | `_Java_NET_worlds_scape_DroneAnimator_loadconfig@12` |
| `NET.worlds.scape.DroneAnimator` | `getnameindex` | `int getnameindex(String var0)` | `_Java_NET_worlds_scape_DroneAnimator_getnameindex@12` |
| `NET.worlds.scape.DroneAnimator` | `getindexgeom` | `String getindexgeom(int var0)` | `_Java_NET_worlds_scape_DroneAnimator_getindexgeom@12` |
| `NET.worlds.scape.DroneAnimator` | `prepFigure` | `void prepFigure(WObject var0, boolean var1)` | `_Java_NET_worlds_scape_DroneAnimator_prepFigure@16` |
| `NET.worlds.scape.DroneAnimator` | `addtype` | `void addtype(int var0)` | `_Java_NET_worlds_scape_DroneAnimator_addtype@12` |
| `NET.worlds.scape.DroneAnimator` | `deltype` | `void deltype(int var0)` | `_Java_NET_worlds_scape_DroneAnimator_deltype@12` |
| `NET.worlds.scape.DroneAnimator` | `endanimations` | `void endanimations()` | `_Java_NET_worlds_scape_DroneAnimator_endanimations@8` |
| `NET.worlds.scape.DroneAnimator` | `moveto` | `void moveto(int var1, short var2, short var3, short var4, short var5, int var6)` | `_Java_NET_worlds_scape_DroneAnimator_moveto@32` |
| `NET.worlds.scape.DroneAnimator` | `moveby` | `void moveby(int var1, short var2, short var3, short var4, int var5)` | `_Java_NET_worlds_scape_DroneAnimator_moveby@28` |
| `NET.worlds.scape.DroneAnimator` | `update` | `void update(WObject var1, WObject var2, int var3, float var4, boolean var5)` | `_Java_NET_worlds_scape_DroneAnimator_update@28` |
| `NET.worlds.scape.DroneAnimator` | `animate` | `float animate(int var1, String var2, int var3)` | `_Java_NET_worlds_scape_DroneAnimator_animate@20` |
| `NET.worlds.scape.DroneAnimator` | `getAnimationTime` | `float getAnimationTime(int var1, String var2)` | `_Java_NET_worlds_scape_DroneAnimator_getAnimationTime@16` |
| `NET.worlds.scape.DroneAnimator` | `CreateRep` | `int CreateRep()` | `_Java_NET_worlds_scape_DroneAnimator_CreateRep@8` |
| `NET.worlds.scape.DroneAnimator` | `DestroyRep` | `void DestroyRep(int var0)` | `_Java_NET_worlds_scape_DroneAnimator_DestroyRep@12` |
| `NET.worlds.scape.EventQueue` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_EventQueue_nativeInit@8` |
| `NET.worlds.scape.EventQueue` | `getNextEvent` | `boolean getNextEvent()` | `_Java_NET_worlds_scape_EventQueue_getNextEvent@8` |
| `NET.worlds.scape.EventQueue` | `getEventCount` | `int getEventCount()` | `_Java_NET_worlds_scape_EventQueue_getEventCount@8` |
| `NET.worlds.scape.EventQueue` | `addEvent` | `void addEvent(char var0, int var1, int var2, int var3, int var4)` | `_Java_NET_worlds_scape_EventQueue_addEvent@28` |
| `NET.worlds.scape.FileTexture` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_FileTexture_nativeInit@8` |
| `NET.worlds.scape.FileTexture` | `dictLookup` | `FileTexture dictLookup(String var0)` | `_Java_NET_worlds_scape_FileTexture_dictLookup@12` |
| `NET.worlds.scape.FileTexture` | `makeTexture` | `void makeTexture(String var1, String var2)` | `_Java_NET_worlds_scape_FileTexture_makeTexture@16` |
| `NET.worlds.scape.Hologram` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Hologram_nativeInit@8` |
| `NET.worlds.scape.Hologram` | `makeTemporarilyInvisible` | `void makeTemporarilyInvisible()` | `_Java_NET_worlds_scape_Hologram_makeTemporarilyInvisible@8` |
| `NET.worlds.scape.Hologram` | `prerender` | `void prerender(Camera var1)` | `_Java_NET_worlds_scape_Hologram_prerender@12` |
| `NET.worlds.scape.Hologram` | `postrender` | `void postrender(Camera var1)` | `_Java_NET_worlds_scape_Hologram_postrender@12` |
| `NET.worlds.scape.ImageConverter` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_ImageConverter_nativeInit@8` |
| `NET.worlds.scape.ImageConverter` | `prepareDIB` | `void prepareDIB(int var1, int var2, int var3, int[] var4)` | `_Java_NET_worlds_scape_ImageConverter_prepareDIB@24` |
| `NET.worlds.scape.ImageConverter` | `setDIBPixelBytes` | `void setDIBPixelBytes(int var1, int var2, int var3, int var4, byte[] var5, int var6, int var7)` | `_Java_NET_worlds_scape_ImageConverter_setDIBPixelBytes@36` |
| `NET.worlds.scape.ImageConverter` | `setDIBPixelInts` | `void setDIBPixelInts(int var1, int var2, int var3, int var4, int[] var5, int var6, int var7)` | `_Java_NET_worlds_scape_ImageConverter_setDIBPixelInts@36` |
| `NET.worlds.scape.ImageConverter` | `convertDIBToTexture` | `int convertDIBToTexture()` | `_Java_NET_worlds_scape_ImageConverter_convertDIBToTexture@8` |
| `NET.worlds.scape.ImageConverter` | `cleanup` | `void cleanup()` | `_Java_NET_worlds_scape_ImageConverter_cleanup@8` |
| `NET.worlds.scape.Light` | `setLightTransform` | `void setLightTransform(int var0, int var1)` | `_Java_NET_worlds_scape_Light_setLightTransform@16` |
| `NET.worlds.scape.Light` | `destroyLight` | `void destroyLight(int var0)` | `_Java_NET_worlds_scape_Light_destroyLight@12` |
| `NET.worlds.scape.MCISoundPlayer` | `nativeVolume` | `void nativeVolume(float var1, float var2)` | `_Java_NET_worlds_scape_MCISoundPlayer_nativeVolume@16` |
| `NET.worlds.scape.MCISoundPlayer` | `nativeStart` | `boolean nativeStart(String var1)` | `_Java_NET_worlds_scape_MCISoundPlayer_nativeStart@12` |
| `NET.worlds.scape.MCISoundPlayer` | `nativeIsFinished` | `boolean nativeIsFinished()` | `_Java_NET_worlds_scape_MCISoundPlayer_nativeIsFinished@8` |
| `NET.worlds.scape.MCISoundPlayer` | `nativeStop` | `void nativeStop()` | `_Java_NET_worlds_scape_MCISoundPlayer_nativeStop@8` |
| `NET.worlds.scape.MCISoundPlayer` | `isActive` | `boolean isActive()` | `_Java_NET_worlds_scape_MCISoundPlayer_isActive@8` |
| `NET.worlds.scape.MCISoundPlayer` | `shutdown` | `void shutdown()` | `_Java_NET_worlds_scape_MCISoundPlayer_shutdown@8` |
| `NET.worlds.scape.Material` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Material_nativeInit@8` |
| `NET.worlds.scape.Material` | `nativeSetTexture` | `void nativeSetTexture(int var1, Texture var2)` | `_Java_NET_worlds_scape_Material_nativeSetTexture@16` |
| `NET.worlds.scape.Material` | `extractTexture` | `Texture extractTexture(int var1)` | `_Java_NET_worlds_scape_Material_extractTexture@12` |
| `NET.worlds.scape.Material` | `closeMaterial` | `void closeMaterial(int var1)` | `_Java_NET_worlds_scape_Material_closeMaterial@12` |
| `NET.worlds.scape.Material` | `makeMaterial` | `int makeMaterial(float var0, float var1, float var2, float var3, int var4, int var5, int var6, boolean var7)` | `_Java_NET_worlds_scape_Material_makeMaterial@40` |
| `NET.worlds.scape.Material` | `paramChange` | `void paramChange()` | `_Java_NET_worlds_scape_Material_paramChange@8` |
| `NET.worlds.scape.PendingCacheDrone` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_PendingCacheDrone_nativeInit@8` |
| `NET.worlds.scape.Pilot` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Pilot_nativeInit@8` |
| `NET.worlds.scape.Point3Temp` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Point3Temp_nativeInit@8` |
| `NET.worlds.scape.Point3Temp` | `times` | `Point3Temp times(Transform var1)` | `?Java_NET_worlds_scape_Point3Temp_times__LNET_worlds_scape_Transform_2@@YGPAV_jobject@@PAUJNIEnv_@@PAV1@1@Z`<br>`_Java_NET_worlds_scape_Point3Temp_times@12` |
| `NET.worlds.scape.Point3Temp` | `vectorTimes` | `Point3Temp vectorTimes(Transform var1)` | `_Java_NET_worlds_scape_Point3Temp_vectorTimes@12` |
| `NET.worlds.scape.Polygon` | `nativeSetVertex` | `void nativeSetVertex(int var1, float var2, float var3, float var4, float var5, float var6)` | `_Java_NET_worlds_scape_Polygon_nativeSetVertex@32` |
| `NET.worlds.scape.Portal` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Portal_nativeInit@8` |
| `NET.worlds.scape.Portal` | `updateVisible` | `void updateVisible()` | `_Java_NET_worlds_scape_Portal_updateVisible@8` |
| `NET.worlds.scape.Portal` | `setTransform` | `void setTransform()` | `_Java_NET_worlds_scape_Portal_setTransform@8` |
| `NET.worlds.scape.Portal` | `prerender` | `void prerender(Camera var1)` | `_Java_NET_worlds_scape_Portal_prerender@12` |
| `NET.worlds.scape.Portal` | `postrender` | `void postrender(Camera var1)` | `_Java_NET_worlds_scape_Portal_postrender@12` |
| `NET.worlds.scape.RenderWare` | `get3DHardwareInUse` | `boolean get3DHardwareInUse()` | `_Java_NET_worlds_scape_RenderWare_get3DHardwareInUse@8` |
| `NET.worlds.scape.RenderWare` | `get3DHardwareAvailable` | `boolean get3DHardwareAvailable()` | `_Java_NET_worlds_scape_RenderWare_get3DHardwareAvailable@8` |
| `NET.worlds.scape.Restorer` | `makeArray` | `Object makeArray(Class var1, int var2)` | `?Java_NET_worlds_scape_Restorer_makeArray@@YGPAV_jobject@@PAUJNIEnv_@@PAV_jclass@@1J@Z` |
| `NET.worlds.scape.Room` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Room_nativeInit@8` |
| `NET.worlds.scape.Room` | `addLight` | `int addLight(int var0, float var1, float var2, float var3, float var4, float var5, float var6)` | `_Java_NET_worlds_scape_Room_addLight@36` |
| `NET.worlds.scape.Room` | `setLightPosition` | `void setLightPosition(int var0, float var1, float var2, float var3)` | `?Java_NET_worlds_scape_Room_setLightPosition__IFFF@@YGXPAUJNIEnv_@@PAV_jclass@@JMMM@Z`<br>`_Java_NET_worlds_scape_Room_setLightPosition@24` |
| `NET.worlds.scape.Room` | `setLightColor` | `void setLightColor(int var0, float var1, float var2, float var3)` | `?Java_NET_worlds_scape_Room_setLightColor__IFFF@@YGXPAUJNIEnv_@@PAV_jclass@@JMMM@Z`<br>`_Java_NET_worlds_scape_Room_setLightColor@24` |
| `NET.worlds.scape.Room` | `createScene` | `void createScene()` | `_Java_NET_worlds_scape_Room_createScene@8` |
| `NET.worlds.scape.Room` | `destroyScene` | `void destroyScene()` | `_Java_NET_worlds_scape_Room_destroyScene@8` |
| `NET.worlds.scape.RoomEnvironment` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_RoomEnvironment_nativeInit@8` |
| `NET.worlds.scape.RoomEnvironment` | `createScene` | `void createScene(Room var1)` | `_Java_NET_worlds_scape_RoomEnvironment_createScene@12` |
| `NET.worlds.scape.RoomEnvironment` | `destroyScene` | `void destroyScene()` | `_Java_NET_worlds_scape_RoomEnvironment_destroyScene@8` |
| `NET.worlds.scape.ScapePicMovie` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_ScapePicMovie_nativeInit@8` |
| `NET.worlds.scape.ScapePicMovie` | `lookupTextures` | `ScapePicTexture[] lookupTextures(String var1, int var2, int var3, int var4)` | `_Java_NET_worlds_scape_ScapePicMovie_lookupTextures@24` |
| `NET.worlds.scape.ScapePicMovie` | `makeTextures` | `ScapePicTexture[] makeTextures(String var1, String var2)` | `_Java_NET_worlds_scape_ScapePicMovie_makeTextures@16` |
| `NET.worlds.scape.ScapePicTexture` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_ScapePicTexture_nativeInit@8` |
| `NET.worlds.scape.ScapePicTexture` | `makeTexture` | `void makeTexture(String var1, String var2)` | `_Java_NET_worlds_scape_ScapePicTexture_makeTexture@16` |
| `NET.worlds.scape.SendURLAction` | `launchViaRegistry` | `boolean launchViaRegistry(String var0)` | `_Java_NET_worlds_scape_SendURLAction_launchViaRegistry@12` |
| `NET.worlds.scape.Shape` | `calcLODDistance` | `float calcLODDistance(float var1)` | `_Java_NET_worlds_scape_Shape_calcLODDistance@12` |
| `NET.worlds.scape.Shape` | `nativeSetMaterial` | `void nativeSetMaterial(Material var1)` | `_Java_NET_worlds_scape_Shape_nativeSetMaterial@12` |
| `NET.worlds.scape.Shape` | `extractSubclump` | `int extractSubclump(int var1)` | `_Java_NET_worlds_scape_Shape_extractSubclump@12` |
| `NET.worlds.scape.Shape` | `addEmptyParentClump` | `int addEmptyParentClump(int var0)` | `_Java_NET_worlds_scape_Shape_addEmptyParentClump@12` |
| `NET.worlds.scape.Shape` | `convertSpecial` | `void convertSpecial(int var0)` | `_Java_NET_worlds_scape_Shape_convertSpecial@12` |
| `NET.worlds.scape.Shape` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Shape_nativeInit@8` |
| `NET.worlds.scape.Shape` | `makeDefaultShape` | `int makeDefaultShape()` | `_Java_NET_worlds_scape_Shape_makeDefaultShape@8` |
| `NET.worlds.scape.Shape` | `releasePendingShape` | `void releasePendingShape()` | `_Java_NET_worlds_scape_Shape_releasePendingShape@8` |
| `NET.worlds.scape.ShapeLoader` | `loadTextFile` | `void loadTextFile(String var1, URL var2)` | `_Java_NET_worlds_scape_ShapeLoader_loadTextFile@16` |
| `NET.worlds.scape.ShapeLoader` | `finishLoadingTextFile` | `int finishLoadingTextFile(String var1)` | `_Java_NET_worlds_scape_ShapeLoader_finishLoadingTextFile@12` |
| `NET.worlds.scape.ShapeLoader` | `loadBodFile` | `int loadBodFile(String var1, int var2)` | `_Java_NET_worlds_scape_ShapeLoader_loadBodFile@16` |
| `NET.worlds.scape.ShapeLoader` | `loadBinaryFile` | `int loadBinaryFile(String var1, URL var2)` | `_Java_NET_worlds_scape_ShapeLoader_loadBinaryFile@16` |
| `NET.worlds.scape.ShapeLoader` | `finishLoadingBinaryFile` | `int finishLoadingBinaryFile(int var1, boolean var2)` | `_Java_NET_worlds_scape_ShapeLoader_finishLoadingBinaryFile@16` |
| `NET.worlds.scape.StringTexture` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_StringTexture_nativeInit@8` |
| `NET.worlds.scape.StringTexture` | `makeStringTexture` | `void makeStringTexture()` | `_Java_NET_worlds_scape_StringTexture_makeStringTexture@8` |
| `NET.worlds.scape.Surface` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Surface_nativeInit@8` |
| `NET.worlds.scape.Surface` | `nativeSetMaterial` | `void nativeSetMaterial()` | `_Java_NET_worlds_scape_Surface_nativeSetMaterial@8` |
| `NET.worlds.scape.Surface` | `uvOutOfRange` | `boolean uvOutOfRange()` | `_Java_NET_worlds_scape_Surface_uvOutOfRange@8` |
| `NET.worlds.scape.Surface` | `addVertex` | `void addVertex(float var1, float var2, float var3, float var4, float var5)` | `_Java_NET_worlds_scape_Surface_addVertex@28` |
| `NET.worlds.scape.Surface` | `addPolygon` | `void addPolygon(int[] var1)` | `_Java_NET_worlds_scape_Surface_addPolygon@12` |
| `NET.worlds.scape.Surface` | `addSubPolys` | `int addSubPolys(int var1, int var2)` | `_Java_NET_worlds_scape_Surface_addSubPolys@16` |
| `NET.worlds.scape.Texture` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Texture_nativeInit@8` |
| `NET.worlds.scape.Texture` | `nativeGetW` | `int nativeGetW(int var0)` | `_Java_NET_worlds_scape_Texture_nativeGetW@12` |
| `NET.worlds.scape.Texture` | `nativeGetH` | `int nativeGetH(int var0)` | `_Java_NET_worlds_scape_Texture_nativeGetH@12` |
| `NET.worlds.scape.Texture` | `nativeCopyFrom` | `void nativeCopyFrom(int var0, int var1, int var2, int var3, int var4, int var5)` | `_Java_NET_worlds_scape_Texture_nativeCopyFrom@32` |
| `NET.worlds.scape.Texture` | `nativeRelease` | `void nativeRelease(int var0)` | `_Java_NET_worlds_scape_Texture_nativeRelease@12` |
| `NET.worlds.scape.TextureSurface` | `nativeInit` | `int nativeInit(int var1, int var2)` | `_Java_NET_worlds_scape_TextureSurface_nativeInit@16` |
| `NET.worlds.scape.TextureSurface` | `nativeMakeDC` | `int nativeMakeDC(int var1, int var2, int var3)` | `_Java_NET_worlds_scape_TextureSurface_nativeMakeDC@20` |
| `NET.worlds.scape.TextureSurface` | `nativeGetDC` | `int nativeGetDC(int var1)` | `_Java_NET_worlds_scape_TextureSurface_nativeGetDC@12` |
| `NET.worlds.scape.TextureSurface` | `nativeReleaseDC` | `void nativeReleaseDC(int var1, int var2)` | `_Java_NET_worlds_scape_TextureSurface_nativeReleaseDC@16` |
| `NET.worlds.scape.TextureSurface` | `nativeDestroyDC` | `void nativeDestroyDC(int var1)` | `_Java_NET_worlds_scape_TextureSurface_nativeDestroyDC@12` |
| `NET.worlds.scape.TextureSurface` | `nativeLeftClick` | `void nativeLeftClick(int var1, int var2, int var3)` | `_Java_NET_worlds_scape_TextureSurface_nativeLeftClick@20` |
| `NET.worlds.scape.Transform` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_Transform_nativeInit@8` |
| `NET.worlds.scape.Transform` | `getX` | `float getX()` | `_Java_NET_worlds_scape_Transform_getX@8` |
| `NET.worlds.scape.Transform` | `getY` | `float getY()` | `_Java_NET_worlds_scape_Transform_getY@8`<br>`_Java_NET_worlds_scape_Transform_getYaw@8` |
| `NET.worlds.scape.Transform` | `getZ` | `float getZ()` | `_Java_NET_worlds_scape_Transform_getZ@8` |
| `NET.worlds.scape.Transform` | `getYaw` | `float getYaw()` | `_Java_NET_worlds_scape_Transform_getYaw@8` |
| `NET.worlds.scape.Transform` | `getPitch` | `float getPitch()` | `_Java_NET_worlds_scape_Transform_getPitch@8` |
| `NET.worlds.scape.Transform` | `getSpin` | `float getSpin(Point3Temp var1)` | `_Java_NET_worlds_scape_Transform_getSpin@12` |
| `NET.worlds.scape.Transform` | `pre` | `Transform pre(Transform var1)` | `_Java_NET_worlds_scape_Transform_pre@12`<br>`_Java_NET_worlds_scape_Transform_premoveBy@20` |
| `NET.worlds.scape.Transform` | `postHelper` | `Transform postHelper(Transform var1)` | `_Java_NET_worlds_scape_Transform_postHelper@12` |
| `NET.worlds.scape.Transform` | `makeIdentity` | `Transform makeIdentity()` | `_Java_NET_worlds_scape_Transform_makeIdentity@8` |
| `NET.worlds.scape.Transform` | `moveBy` | `Transform moveBy(float var1, float var2, float var3)` | `_Java_NET_worlds_scape_Transform_moveBy@20` |
| `NET.worlds.scape.Transform` | `moveTo` | `Transform moveTo(float var1, float var2, float var3)` | `_Java_NET_worlds_scape_Transform_moveTo@20` |
| `NET.worlds.scape.Transform` | `premoveBy` | `Transform premoveBy(float var1, float var2, float var3)` | `_Java_NET_worlds_scape_Transform_premoveBy@20` |
| `NET.worlds.scape.Transform` | `scale` | `Transform scale(float var1, float var2, float var3)` | `?Java_NET_worlds_scape_Transform_scale__FFF@@YGPAV_jobject@@PAUJNIEnv_@@PAV1@MMM@Z`<br>`_Java_NET_worlds_scape_Transform_scale@20` |
| `NET.worlds.scape.Transform` | `postscaleHelper` | `Transform postscaleHelper(float var1, float var2, float var3)` | `_Java_NET_worlds_scape_Transform_postscaleHelper@20` |
| `NET.worlds.scape.Transform` | `spin` | `Transform spin(float var1, float var2, float var3, float var4)` | `?Java_NET_worlds_scape_Transform_spin__FFFF@@YGPAV_jobject@@PAUJNIEnv_@@PAV1@MMMM@Z`<br>`_Java_NET_worlds_scape_Transform_spin@24` |
| `NET.worlds.scape.Transform` | `postspin` | `Transform postspin(float var1, float var2, float var3, float var4)` | `_Java_NET_worlds_scape_Transform_postspin@24` |
| `NET.worlds.scape.Transform` | `nativeFinalize` | `void nativeFinalize()` | `_Java_NET_worlds_scape_Transform_nativeFinalize@8` |
| `NET.worlds.scape.Transform` | `setTransform` | `void setTransform(Transform var1)` | `_Java_NET_worlds_scape_Transform_setTransform@12` |
| `NET.worlds.scape.Transform` | `invert` | `Transform invert()` | `_Java_NET_worlds_scape_Transform_invert@8` |
| `NET.worlds.scape.Transform` | `getGuts` | `float[] getGuts()` | `_Java_NET_worlds_scape_Transform_getGuts@8` |
| `NET.worlds.scape.Transform` | `isTransformEqual` | `boolean isTransformEqual(Transform var1)` | `_Java_NET_worlds_scape_Transform_isTransformEqual@12` |
| `NET.worlds.scape.Transform` | `setGuts` | `void setGuts(float[] var1)` | `_Java_NET_worlds_scape_Transform_setGuts@12` |
| `NET.worlds.scape.VehicleShape` | `nativeAnalyzeShape` | `void nativeAnalyzeShape(int var1, float var2)` | `_Java_NET_worlds_scape_VehicleShape_nativeAnalyzeShape@16` |
| `NET.worlds.scape.VehicleShape` | `nativeGetTirePosX` | `float nativeGetTirePosX(int var1)` | `_Java_NET_worlds_scape_VehicleShape_nativeGetTirePosX@12` |
| `NET.worlds.scape.VehicleShape` | `nativeGetTirePosY` | `float nativeGetTirePosY(int var1)` | `_Java_NET_worlds_scape_VehicleShape_nativeGetTirePosY@12` |
| `NET.worlds.scape.VehicleShape` | `nativeGetTirePosZ` | `float nativeGetTirePosZ(int var1)` | `_Java_NET_worlds_scape_VehicleShape_nativeGetTirePosZ@12` |
| `NET.worlds.scape.VehicleShape` | `nativeGetCogX` | `float nativeGetCogX()` | `_Java_NET_worlds_scape_VehicleShape_nativeGetCogX@8` |
| `NET.worlds.scape.VehicleShape` | `nativeGetCogY` | `float nativeGetCogY()` | `_Java_NET_worlds_scape_VehicleShape_nativeGetCogY@8` |
| `NET.worlds.scape.VehicleShape` | `nativeGetCogZ` | `float nativeGetCogZ()` | `_Java_NET_worlds_scape_VehicleShape_nativeGetCogZ@8` |
| `NET.worlds.scape.VehicleShape` | `nativeGetMoiX` | `float nativeGetMoiX()` | `_Java_NET_worlds_scape_VehicleShape_nativeGetMoiX@8` |
| `NET.worlds.scape.VehicleShape` | `nativeGetMoiY` | `float nativeGetMoiY()` | `_Java_NET_worlds_scape_VehicleShape_nativeGetMoiY@8` |
| `NET.worlds.scape.VehicleShape` | `nativeGetMoiZ` | `float nativeGetMoiZ()` | `_Java_NET_worlds_scape_VehicleShape_nativeGetMoiZ@8` |
| `NET.worlds.scape.WObject` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_WObject_nativeInit@8` |
| `NET.worlds.scape.WObject` | `createClump` | `void createClump()` | `_Java_NET_worlds_scape_WObject_createClump@8` |
| `NET.worlds.scape.WObject` | `nativeInCamSpace` | `boolean nativeInCamSpace(Camera var1, Point3Temp var2)` | `_Java_NET_worlds_scape_WObject_nativeInCamSpace@16` |
| `NET.worlds.scape.WObject` | `voidClump` | `void voidClump()` | `_Java_NET_worlds_scape_WObject_voidClump@8` |
| `NET.worlds.scape.WObject` | `extractClump` | `int extractClump()` | `_Java_NET_worlds_scape_WObject_extractClump@8` |
| `NET.worlds.scape.WObject` | `addChildToClump` | `void addChildToClump(WObject var1)` | `_Java_NET_worlds_scape_WObject_addChildToClump@12` |
| `NET.worlds.scape.WObject` | `setClumpMatrix` | `void setClumpMatrix()` | `_Java_NET_worlds_scape_WObject_setClumpMatrix@8` |
| `NET.worlds.scape.WObject` | `initClumpData` | `void initClumpData()` | `_Java_NET_worlds_scape_WObject_initClumpData@8` |
| `NET.worlds.scape.WObject` | `doneWithEditing` | `void doneWithEditing()` | `_Java_NET_worlds_scape_WObject_doneWithEditing@8` |
| `NET.worlds.scape.WObject` | `getNumVerts` | `int getNumVerts()` | `_Java_NET_worlds_scape_WObject_getNumVerts@8` |
| `NET.worlds.scape.WObject` | `getObjectToWorldMatrix` | `Transform getObjectToWorldMatrix(Transform var1)` | `_Java_NET_worlds_scape_WObject_getObjectToWorldMatrix@12` |
| `NET.worlds.scape.WObject` | `getJointedObjectToWorldMatrix` | `Transform getJointedObjectToWorldMatrix(Transform var1)` | `_Java_NET_worlds_scape_WObject_getJointedObjectToWorldMatrix@12` |
| `NET.worlds.scape.WObject` | `updateHighlight` | `void updateHighlight()` | `_Java_NET_worlds_scape_WObject_updateHighlight@8` |
| `NET.worlds.scape.WObject` | `getClumpBBox` | `void getClumpBBox(Point3Temp var1, Point3Temp var2)` | `?Java_NET_worlds_scape_WObject_getClumpBBox__LNET_worlds_scape_Point3Temp_2LNET_worlds_scape_Point3Temp_2@@YGXPAUJNIEnv_@@PAV_jobject@@11@Z`<br>`_Java_NET_worlds_scape_WObject_getClumpBBox@16` |
| `NET.worlds.scape.WObject` | `updateVisible` | `void updateVisible()` | `_Java_NET_worlds_scape_WObject_updateVisible@8` |
| `NET.worlds.scape.WObject` | `getRoomFromClump` | `Room getRoomFromClump()` | `_Java_NET_worlds_scape_WObject_getRoomFromClump@8` |
| `NET.worlds.scape.WObject` | `inRoomContents` | `boolean inRoomContents()` | `_Java_NET_worlds_scape_WObject_inRoomContents@8` |
| `NET.worlds.scape.WObject` | `getClumpMinXYExtent` | `float getClumpMinXYExtent()` | `_Java_NET_worlds_scape_WObject_getClumpMinXYExtent@8` |
| `NET.worlds.scape.WavSoundPlayer` | `nativeInit` | `void nativeInit()` | `_Java_NET_worlds_scape_WavSoundPlayer_nativeInit@8` |
| `NET.worlds.scape.WavSoundPlayer` | `nativePlay` | `void nativePlay(boolean var1)` | `_Java_NET_worlds_scape_WavSoundPlayer_nativePlay@12` |
| `NET.worlds.scape.WavSoundPlayer` | `nativeVolume` | `void nativeVolume(float var1, float var2)` | `_Java_NET_worlds_scape_WavSoundPlayer_nativeVolume@16` |
| `NET.worlds.scape.WavSoundPlayer` | `nativeStop` | `void nativeStop()` | `_Java_NET_worlds_scape_WavSoundPlayer_nativeStop@8` |
| `NET.worlds.scape.sendURL` | `init` | `int init(String var0)` | `_Java_NET_worlds_scape_sendURL_init@12` |
| `NET.worlds.scape.sendURL` | `get` | `int get(String var0)` | `_Java_NET_worlds_scape_sendURL_get@12` |

## ⚠️ VERIFICAR — sin export directo encontrado en gamma.dll

| Clase | Método | Firma | Prefijo JNI esperado |
|---|---|---|---|
| `NET.worlds.scape.PendingCacheDrone` | `nativeDestroy` | `void nativeDestroy()` | `Java_NET_worlds_scape_PendingCacheDrone_nativeDestroy` |
| `NET.worlds.scape.sendURL` | `silent_get` | `int silent_get(String var0)` | `Java_NET_worlds_scape_sendURL_silent_1get` |
