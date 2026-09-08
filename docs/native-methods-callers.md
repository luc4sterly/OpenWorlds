# Mapa de llamadas a métodos `native` (previo al mock JNI)

Generado antes de convertir cada `native` en un stub con logging, para saber qué rutas de código realmente los ejercitan en tiempo de ejecución. `(self)` = llamada sin calificar dentro del propio archivo que declara el método.

⚠️ **Limitación conocida, léase antes de sacar conclusiones**: esto es un grep por texto (`Clase.metodo(` calificado, o `metodo(` sin calificar dentro del mismo archivo). No entiende polimorfismo (llamar a través de una interfaz o una referencia de la superclase), ni `this.metodo()` invocado desde una subclase, ni reflection. Con esta heurística, **167 de los 365** métodos salen como "sin llamadas encontradas" — eso NO significa que los 167 sean código muerto, solo que esta herramienta no les encontró un call site de forma trivial. Los únicos dos casos confirmados como código muerto de verdad (`PendingCacheDrone.nativeDestroy`, `Console.getVolumeInfo`) se verificaron aparte, cruzando además contra los exports reales de `gamma.dll` — ver `docs/native-methods-map.md`. Para cualquier otro método de esta lista, "sin llamadas encontradas" es una pista para investigar, no una conclusión.

Total de declaraciones `native`: **365**

### `ASFSoundPlayer.nativePlay`
- ASFThread:27
- ASFThread:74

### `ActiveX.getClass`
- *(sin llamadas encontradas en el código decompilado)*

### `ActiveX.getClassFClsID`
- IUnknown:30
- IUnknown:62

### `ActiveX.getClassFProgID`
- IUnknown:33
- IUnknown:65

### `ActiveX.initActiveX`
- ActiveX:85 (self)

### `ActiveX.uninitActiveX`
- ActiveX:102 (self)

### `ActiveX.winProc`
- ActiveX:35 (self)

### `CDPlayerAction.checkDrive`
- CDAudio:269

### `CDPlayerAction.closeDrive`
- CDAudio:174
- CDPlayerAction:100 (self)
- CDPlayerAction:109 (self)

### `CDPlayerAction.getDriveLetterOffset`
- CDAudio:144

### `CDPlayerAction.getDriveTrackList`
- CDAudio:143
- CDPlayerAction:108 (self)

### `CDPlayerAction.getNumDrives`
- CDAudio:134
- CDPlayerAction:48 (self)

### `CDPlayerAction.getPosition`
- CDAudio:262

### `CDPlayerAction.isPlaying`
- CDAudio:142
- CDAudio:260
- CDPlayerAction:88 (self)

### `CDPlayerAction.launchVolumeControlApp`
- DefaultConsole:1150

### `CDPlayerAction.openDrive`
- CDAudio:141
- CDPlayerAction:85 (self)
- CDPlayerAction:107 (self)

### `CDPlayerAction.pauseAudio`
- *(sin llamadas encontradas en el código decompilado)*

### `CDPlayerAction.playAudio`
- CDAudio:276
- CDAudio:366
- CDPlayerAction:86 (self)

### `CDPlayerAction.resumeAudio`
- *(sin llamadas encontradas en el código decompilado)*

### `CDPlayerAction.setNTAutoPlayCode`
- *(sin llamadas encontradas en el código decompilado)*

### `CDPlayerAction.stopAudio`
- CDAudio:288
- CDAudio:297
- CDAudio:309
- CDAudio:348
- CDPlayerAction:95 (self)

### `Camera.cameraNativeInit`
- Camera:345 (self)

### `Camera.nDrawText`
- *(sin llamadas encontradas en el código decompilado)*

### `Camera.renderScene`
- Camera:103 (self)

### `Console.decrypt`
- Console:607 (self)

### `Console.encrypt`
- Console:580 (self)

### `Console.getVolumeInfo`
- *(sin llamadas encontradas en el código decompilado)*

### `Cursor.destroyCursor`
- Cursor:114 (self)

### `Cursor.getSystemCursorDepth`
- *(sin llamadas encontradas en el código decompilado)*

### `Cursor.getSystemCursorHeight`
- *(sin llamadas encontradas en el código decompilado)*

### `Cursor.getSystemCursorWidth`
- *(sin llamadas encontradas en el código decompilado)*

### `Cursor.loadCursor`
- Cursor:128 (self)

### `Cursor.loadSystemCursor`
- Cursor:101 (self)

### `DDEMLClass.Poke`
- *(sin llamadas encontradas en el código decompilado)*

### `DDEMLClass.Request`
- *(sin llamadas encontradas en el código decompilado)*

### `DDEMLClass.create`
- DDEMLClass:9 (self)

### `DDEMLClass.destroy`
- *(sin llamadas encontradas en el código decompilado)*

### `DDEMLClass.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `DNSLookup.gethostbyname`
- DNSLookup:98 (self)

### `DirectShow.nInit`
- DirectShow:13 (self)
- DirectShow:19 (self)

### `DirectShow.nOpen`
- *(sin llamadas encontradas en el código decompilado)*

### `DirectShow.nPause`
- *(sin llamadas encontradas en el código decompilado)*

### `DirectShow.nPlay`
- *(sin llamadas encontradas en el código decompilado)*

### `DirectShow.nRenderTo`
- DirectShow:29 (self)

### `DirectShow.nShutdown`
- DirectShow:25 (self)

### `DirectShow.nStop`
- DirectShow:24 (self)

### `DirectShow.nTick`
- DirectShow:23 (self)

### `DirectShow.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `DroneAnimator.CreateRep`
- DroneAnimator:55 (self)

### `DroneAnimator.DestroyRep`
- DroneAnimator:59 (self)

### `DroneAnimator.addtype`
- PosableShape:130

### `DroneAnimator.animate`
- *(sin llamadas encontradas en el código decompilado)*

### `DroneAnimator.deltype`
- DroneAnimator:48 (self)

### `DroneAnimator.endanimations`
- *(sin llamadas encontradas en el código decompilado)*

### `DroneAnimator.getActionList`
- PosableShape:1207

### `DroneAnimator.getAnimationTime`
- *(sin llamadas encontradas en el código decompilado)*

### `DroneAnimator.getindexgeom`
- *(sin llamadas encontradas en el código decompilado)*

### `DroneAnimator.getnameindex`
- PosableShape:150
- PosableShape:155

### `DroneAnimator.init`
- DroneAnimator:82 (self)

### `DroneAnimator.loadconfig`
- DroneAnimator:88 (self)
- PendingDrone:192

### `DroneAnimator.moveby`
- *(sin llamadas encontradas en el código decompilado)*

### `DroneAnimator.moveto`
- *(sin llamadas encontradas en el código decompilado)*

### `DroneAnimator.prepFigure`
- PosableShape:132
- PosableShape:1225

### `DroneAnimator.update`
- *(sin llamadas encontradas en el código decompilado)*

### `EventQueue.addEvent`
- EventQueue:77 (self)

### `EventQueue.getEventCount`
- EventQueue:25 (self)

### `EventQueue.getNextEvent`
- EventQueue:85 (self)

### `EventQueue.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.close`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.read`
- FastDataInput:11 (self)

### `FastDataInput.readBoolean`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readByte`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readChar`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readDouble`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readFloat`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readFully`
- FastDataInput:16 (self)
- FastDataInput:17 (self)

### `FastDataInput.readInt`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readLong`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readShort`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readUTF`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readUnsignedByte`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.readUnsignedShort`
- *(sin llamadas encontradas en el código decompilado)*

### `FastDataInput.skipBytes`
- *(sin llamadas encontradas en el código decompilado)*

### `FileSysDialog.nativeRun`
- *(sin llamadas encontradas en el código decompilado)*

### `FileTexture.dictLookup`
- TextureDecoder:44

### `FileTexture.makeTexture`
- FileTexture:10 (self)
- FileTexture:37 (self)

### `FileTexture.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Hologram.makeTemporarilyInvisible`
- Hologram:251 (self)

### `Hologram.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Hologram.postrender`
- *(sin llamadas encontradas en el código decompilado)*

### `Hologram.prerender`
- *(sin llamadas encontradas en el código decompilado)*

### `IClassFactory.nActivate`
- IClassFactory:30 (self)

### `IClassFactory.nDeactivate`
- IClassFactory:43 (self)

### `IDispatch.Invoke`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeAddToolbar`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeDestroy`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeGetHWND`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeGoBack`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeGoForward`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeHome`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativePrint`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeRefresh`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeResize`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeSetURL`
- *(sin llamadas encontradas en el código decompilado)*

### `IEWebControlImp.nativeStop`
- *(sin llamadas encontradas en el código decompilado)*

### `INetscapeRegistry.RegisterProtocol`
- *(sin llamadas encontradas en el código decompilado)*

### `INetscapeRegistry.RegisterViewer`
- *(sin llamadas encontradas en el código decompilado)*

### `IUnknown.QueryInterface`
- IUnknown:90 (self)

### `IUnknown.getPtr`
- *(sin llamadas encontradas en el código decompilado)*

### `IUnknown.true_AddRef`
- IUnknown:144 (self)

### `IUnknown.true_Release`
- IUnknown:111 (self)

### `IWebBrowserApp.Navigate`
- *(sin llamadas encontradas en el código decompilado)*

### `IWebBrowserApp.Quit`
- *(sin llamadas encontradas en el código decompilado)*

### `IWebBrowserApp.put_MenuBar`
- *(sin llamadas encontradas en el código decompilado)*

### `IWebBrowserApp.put_StatusBar`
- *(sin llamadas encontradas en el código decompilado)*

### `IWebBrowserApp.put_Visible`
- *(sin llamadas encontradas en el código decompilado)*

### `ImageConverter.cleanup`
- ImageConverter:49 (self)

### `ImageConverter.convertDIBToTexture`
- ImageConverter:46 (self)

### `ImageConverter.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `ImageConverter.prepareDIB`
- ImageConverter:93 (self)

### `ImageConverter.setDIBPixelBytes`
- ImageConverter:117 (self)

### `ImageConverter.setDIBPixelInts`
- ImageConverter:126 (self)

### `IniFile.getIniInt`
- *(sin llamadas encontradas en el código decompilado)*

### `IniFile.getIniString`
- *(sin llamadas encontradas en el código decompilado)*

### `IniFile.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `IniFile.setIniInt`
- *(sin llamadas encontradas en el código decompilado)*

### `IniFile.setIniString`
- *(sin llamadas encontradas en el código decompilado)*

### `Light.destroyLight`
- Light:17 (self)

### `Light.setLightTransform`
- Light:24 (self)

### `MCISoundPlayer.isActive`
- CDAudio:376
- CDAudio:380

### `MCISoundPlayer.nativeIsFinished`
- *(sin llamadas encontradas en el código decompilado)*

### `MCISoundPlayer.nativeStart`
- *(sin llamadas encontradas en el código decompilado)*

### `MCISoundPlayer.nativeStop`
- *(sin llamadas encontradas en el código decompilado)*

### `MCISoundPlayer.nativeVolume`
- *(sin llamadas encontradas en el código decompilado)*

### `MCISoundPlayer.shutdown`
- MCIThread:38

### `Material.closeMaterial`
- Material:259 (self)

### `Material.extractTexture`
- Material:173 (self)
- Material:235 (self)

### `Material.makeMaterial`
- Material:358 (self)

### `Material.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Material.nativeSetTexture`
- *(sin llamadas encontradas en el código decompilado)*

### `Material.paramChange`
- Material:425 (self)
- Material:430 (self)
- Material:435 (self)
- Material:440 (self)
- Material:445 (self)
- Material:450 (self)
- Material:458 (self)

### `NSProtocolHandler.createLocal`
- NSProtocolHandler:10 (self)

### `NetUpdate.CreateProcSpecial`
- NetUpdate:767 (self)

### `PendingCacheDrone.nativeDestroy`
- *(sin llamadas encontradas en el código decompilado)*

### `PendingCacheDrone.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `PendingCacheDrone.notifySeqLoaded`
- PendingCacheDrone:28 (self)
- PendingCacheDrone:38 (self)
- SeqFile:14

### `Pilot.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Point3Temp.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Point3Temp.times`
- Point3Temp:120 (self)
- Point3Temp:127 (self)

### `Point3Temp.vectorTimes`
- *(sin llamadas encontradas en el código decompilado)*

### `Polygon.nativeSetVertex`
- *(sin llamadas encontradas en el código decompilado)*

### `Portal.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Portal.postrender`
- *(sin llamadas encontradas en el código decompilado)*

### `Portal.prerender`
- *(sin llamadas encontradas en el código decompilado)*

### `Portal.setTransform`
- Portal:97 (self)
- Portal:206 (self)
- Portal:335 (self)
- Portal:418 (self)
- Portal:426 (self)
- Portal:569 (self)

### `Portal.updateVisible`
- Portal:98 (self)
- Portal:207 (self)
- Portal:256 (self)
- Portal:334 (self)
- Portal:570 (self)
- Portal:798 (self)

### `RegKey.close`
- *(sin llamadas encontradas en el código decompilado)*

### `RegKey.createKey`
- RegKey:19 (self)

### `RegKey.getIntValue`
- *(sin llamadas encontradas en el código decompilado)*

### `RegKey.getReservedKey`
- RegKey:14 (self)

### `RegKey.getStringValue`
- *(sin llamadas encontradas en el código decompilado)*

### `RegKey.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `RegKey.openKey`
- RegKey:21 (self)

### `RegKey.setIntValue`
- *(sin llamadas encontradas en el código decompilado)*

### `RegKey.setStringValue`
- *(sin llamadas encontradas en el código decompilado)*

### `RenderCanvasOverlay.nativeKillChild`
- *(sin llamadas encontradas en el código decompilado)*

### `RenderCanvasOverlay.nativeMakeChild`
- *(sin llamadas encontradas en el código decompilado)*

### `RenderCanvasOverlay.nativeResizeChild`
- *(sin llamadas encontradas en el código decompilado)*

### `RenderWare.get3DHardwareAvailable`
- DefaultConsole:911

### `RenderWare.get3DHardwareInUse`
- DefaultConsole:912
- Drone:160

### `Restorer.makeArray`
- Restorer:255 (self)

### `RightMenu.addSeparator`
- RightMenu:73 (self)

### `RightMenu.checkPressed`
- RightMenu:96 (self)

### `RightMenu.create`
- RightMenu:69 (self)

### `RightMenu.discard`
- RightMenu:89 (self)

### `RightMenu.nativeAdd`
- *(sin llamadas encontradas en el código decompilado)*

### `RightMenu.show`
- RightMenu:84 (self)

### `Room.addLight`
- Room:890 (self)
- Room:891 (self)
- RoomEnvironment:37
- RoomEnvironment:38

### `Room.createScene`
- Room:885 (self)

### `Room.destroyScene`
- Room:365 (self)

### `Room.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Room.setLightColor`
- Room:220 (self)
- Room:222 (self)
- Room:226 (self)
- Room:244 (self)
- Room:249 (self)
- Room:252 (self)
- Room:257 (self)
- Room:646 (self)
- Room:821 (self)
- Room:839 (self)
- Room:860 (self)
- RoomEnvironment:53
- RoomEnvironment:57

### `Room.setLightPosition`
- Room:210 (self)
- Room:212 (self)
- Room:216 (self)
- Room:230 (self)
- Room:232 (self)
- Room:235 (self)
- Room:240 (self)
- Room:637 (self)
- Room:820 (self)
- Room:838 (self)
- Room:859 (self)
- RoomEnvironment:43
- RoomEnvironment:47

### `RoomEnvironment.createScene`
- RoomEnvironment:23 (self)

### `RoomEnvironment.destroyScene`
- RoomEnvironment:67 (self)

### `RoomEnvironment.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `ScapePicCanvas.bitBlt`
- ScapePicCanvas:25 (self)
- ScapePicPanel:116

### `ScapePicImage.flush`
- ScapePicImage:26 (self)

### `ScapePicImage.loadImage`
- ScapePicImage:12 (self)

### `ScapePicImage.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `ScapePicMovie.lookupTextures`
- ScapePicMovie:78 (self)

### `ScapePicMovie.makeTextures`
- ScapePicMovie:82 (self)

### `ScapePicMovie.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `ScapePicTexture.makeTexture`
- ScapePicTexture:17 (self)
- ScapePicTexture:77 (self)

### `ScapePicTexture.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `SendURLAction.launchViaRegistry`
- SendURLAction:231 (self)

### `Shape.addEmptyParentClump`
- Shape:298 (self)

### `Shape.calcLODDistance`
- Shape:146 (self)

### `Shape.convertSpecial`
- Shape:399 (self)

### `Shape.extractSubclump`
- Shape:297 (self)

### `Shape.makeDefaultShape`
- Shape:319 (self)

### `Shape.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Shape.nativeSetMaterial`
- *(sin llamadas encontradas en el código decompilado)*

### `Shape.releasePendingShape`
- Shape:161 (self)
- Shape:234 (self)
- Shape:350 (self)
- Shape:364 (self)
- Shape:443 (self)

### `ShapeLoader.finishLoadingBinaryFile`
- ShapeLoader:66 (self)

### `ShapeLoader.finishLoadingTextFile`
- ShapeLoader:60 (self)

### `ShapeLoader.loadBinaryFile`
- ShapeLoader:26 (self)

### `ShapeLoader.loadBodFile`
- ShapeLoader:58 (self)

### `ShapeLoader.loadTextFile`
- ShapeLoader:29 (self)

### `Startup.computeVolumeInfo`
- Gamma:179
- Gamma:181

### `Startup.getVolumeInfo`
- LoginWizard:702

### `Startup.synchronizeStartup`
- Gamma:115

### `StatMemNode.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `StatMemNode.updateMemoryStatus`
- StatMemNode:61 (self)
- StatMemNode:70 (self)
- StatMemNode:86 (self)

### `Std.GetDiskFreeSpace`
- Std:131 (self)
- Std:132 (self)
- Cache:267

### `Std.byteArraysEqual`
- Sharer:374
- Sharer:496
- Sharer:511

### `Std.checkNativeHeap`
- *(sin llamadas encontradas en el código decompilado)*

### `Std.exit`
- Std:17 (self)

### `Std.getBuildDay`
- Std:169 (self)

### `Std.getBuildInfo`
- AboutDialog:60
- LogFile:67

### `Std.getBuildMonth`
- Std:169 (self)

### `Std.getBuildYear`
- Std:169 (self)

### `Std.getClientVersion`
- WorldServer:24

### `Std.getPerformanceCount`
- *(sin llamadas encontradas en el código decompilado)*

### `Std.getPerformanceFrequency`
- *(sin llamadas encontradas en el código decompilado)*

### `Std.getTimeZero`
- EventQueue:77
- EventQueue:86

### `Std.getVersion`
- AboutDialog:62
- DefaultConsole:1041
- DefaultConsole:1043
- LogFile:67
- NetUpdate:235
- NetUpdate:412
- WorldScriptToolkitImp:176

### `Std.getenv`
- *(sin llamadas encontradas en el código decompilado)*

### `Std.instanceOf`
- ObjectSelectorDialog:63

### `Std.nativeGetMillis`
- *(sin llamadas encontradas en el código decompilado)*

### `StringTexture.makeStringTexture`
- StringTexture:24 (self)
- StringTexture:55 (self)

### `StringTexture.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Surface.addPolygon`
- Surface:52 (self)

### `Surface.addSubPolys`
- Surface:54 (self)

### `Surface.addVertex`
- *(sin llamadas encontradas en el código decompilado)*

### `Surface.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Surface.nativeSetMaterial`
- *(sin llamadas encontradas en el código decompilado)*

### `Surface.uvOutOfRange`
- Surface:43 (self)

### `SystemInfo.GetAvailPagedMemory`
- SystemInfo:69 (self)

### `SystemInfo.GetAvailPhysicalMemory`
- SystemInfo:67 (self)

### `SystemInfo.GetCurrentDirectory`
- SystemInfo:59 (self)

### `SystemInfo.GetDiskFreeSpace`
- SystemInfo:81 (self)
- SystemInfo:91 (self)
- SystemInfo:92 (self)

### `SystemInfo.GetNumberOfProcessors`
- SystemInfo:72 (self)

### `SystemInfo.GetPlatformID`
- SystemInfo:74 (self)

### `SystemInfo.GetProcessorType`
- SystemInfo:73 (self)

### `SystemInfo.GetSystemDirectory`
- SystemInfo:58 (self)

### `SystemInfo.GetTotalPagedMemory`
- SystemInfo:68 (self)

### `SystemInfo.GetTotalPhysicalMemory`
- SystemInfo:66 (self)

### `Texture.nativeCopyFrom`
- *(sin llamadas encontradas en el código decompilado)*

### `Texture.nativeGetH`
- *(sin llamadas encontradas en el código decompilado)*

### `Texture.nativeGetW`
- *(sin llamadas encontradas en el código decompilado)*

### `Texture.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Texture.nativeRelease`
- *(sin llamadas encontradas en el código decompilado)*

### `TextureSurface.nativeDestroyDC`
- *(sin llamadas encontradas en el código decompilado)*

### `TextureSurface.nativeGetDC`
- *(sin llamadas encontradas en el código decompilado)*

### `TextureSurface.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `TextureSurface.nativeLeftClick`
- *(sin llamadas encontradas en el código decompilado)*

### `TextureSurface.nativeMakeDC`
- *(sin llamadas encontradas en el código decompilado)*

### `TextureSurface.nativeReleaseDC`
- *(sin llamadas encontradas en el código decompilado)*

### `Transform.getGuts`
- Transform:258 (self)
- Transform:325 (self)

### `Transform.getPitch`
- *(sin llamadas encontradas en el código decompilado)*

### `Transform.getSpin`
- Motion:64
- Motion:90
- MultiMotion:176
- Transform:129 (self)
- Transform:305 (self)

### `Transform.getX`
- HoloPilot:406
- Transform:49 (self)
- Transform:53 (self)

### `Transform.getY`
- HoloPilot:407
- Transform:49 (self)
- Transform:53 (self)

### `Transform.getYaw`
- *(sin llamadas encontradas en el código decompilado)*

### `Transform.getZ`
- HoloPilot:408
- Transform:49 (self)

### `Transform.invert`
- Transform:227 (self)

### `Transform.isTransformEqual`
- *(sin llamadas encontradas en el código decompilado)*

### `Transform.makeIdentity`
- HoloPilot:329
- Motion:149
- Motion:160
- MultiMotion:255
- MultiMotion:266
- Transform:33 (self)
- Transform:39 (self)

### `Transform.moveBy`
- Transform:86 (self)
- Transform:90 (self)
- Transform:141 (self)
- Transform:142 (self)

### `Transform.moveTo`
- HoloPilot:363
- HoloPilot:368
- HoloPilot:373
- HoloPilot:378
- HoloPilot:383
- HoloPilot:386
- HoloPilot:391
- HoloPilot:411
- Motion:151
- Motion:162
- Transform:53 (self)
- Transform:147 (self)
- Transform:148 (self)

### `Transform.nativeFinalize`
- *(sin llamadas encontradas en el código decompilado)*

### `Transform.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Transform.postHelper`
- Transform:125 (self)

### `Transform.postscaleHelper`
- Transform:181 (self)

### `Transform.postspin`
- HoloPilot:412
- Transform:200 (self)
- Transform:201 (self)

### `Transform.pre`
- *(sin llamadas encontradas en el código decompilado)*

### `Transform.premoveBy`
- *(sin llamadas encontradas en el código decompilado)*

### `Transform.scale`
- Motion:150
- Motion:161
- Transform:105 (self)
- Transform:106 (self)
- Transform:157 (self)
- Transform:158 (self)
- Transform:162 (self)
- Transform:191 (self)
- Transform:311 (self)

### `Transform.setGuts`
- Transform:277 (self)
- Transform:290 (self)

### `Transform.setTransform`
- Transform:214 (self)
- Transform:242 (self)

### `Transform.spin`
- Motion:152
- Motion:163
- Motion:164
- MultiMotion:260
- MultiMotion:271
- MultiMotion:272
- Transform:94 (self)
- Transform:98 (self)
- Transform:102 (self)
- Transform:196 (self)
- Transform:197 (self)
- Transform:207 (self)

### `VehicleShape.nativeAnalyzeShape`
- *(sin llamadas encontradas en el código decompilado)*

### `VehicleShape.nativeGetCogX`
- *(sin llamadas encontradas en el código decompilado)*

### `VehicleShape.nativeGetCogY`
- *(sin llamadas encontradas en el código decompilado)*

### `VehicleShape.nativeGetCogZ`
- *(sin llamadas encontradas en el código decompilado)*

### `VehicleShape.nativeGetMoiX`
- *(sin llamadas encontradas en el código decompilado)*

### `VehicleShape.nativeGetMoiY`
- *(sin llamadas encontradas en el código decompilado)*

### `VehicleShape.nativeGetMoiZ`
- *(sin llamadas encontradas en el código decompilado)*

### `VehicleShape.nativeGetTirePosX`
- *(sin llamadas encontradas en el código decompilado)*

### `VehicleShape.nativeGetTirePosY`
- *(sin llamadas encontradas en el código decompilado)*

### `VehicleShape.nativeGetTirePosZ`
- *(sin llamadas encontradas en el código decompilado)*

### `VoiceChat.terminateVC`
- *(sin llamadas encontradas en el código decompilado)*

### `WObject.addChildToClump`
- WObject:314 (self)

### `WObject.createClump`
- WObject:308 (self)

### `WObject.doneWithEditing`
- *(sin llamadas encontradas en el código decompilado)*

### `WObject.extractClump`
- *(sin llamadas encontradas en el código decompilado)*

### `WObject.getClumpBBox`
- WObject:413 (self)
- WObject:416 (self)
- WObject:749 (self)

### `WObject.getClumpMinXYExtent`
- WObject:760 (self)

### `WObject.getJointedObjectToWorldMatrix`
- *(sin llamadas encontradas en el código decompilado)*

### `WObject.getNumVerts`
- *(sin llamadas encontradas en el código decompilado)*

### `WObject.getObjectToWorldMatrix`
- WObject:382 (self)
- WObject:384 (self)
- WObject:390 (self)
- WObject:403 (self)
- WObject:752 (self)
- WObject:811 (self)
- WObject:826 (self)

### `WObject.getRoomFromClump`
- WObject:269 (self)
- WObject:630 (self)
- WObject:638 (self)
- WObject:652 (self)
- WObject:672 (self)
- WObject:1179 (self)

### `WObject.inRoomContents`
- WObject:327 (self)

### `WObject.initClumpData`
- WObject:334 (self)

### `WObject.nativeInCamSpace`
- *(sin llamadas encontradas en el código decompilado)*

### `WObject.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `WObject.setClumpMatrix`
- WObject:249 (self)
- WObject:335 (self)

### `WObject.updateHighlight`
- WObject:250 (self)
- WObject:427 (self)

### `WObject.updateVisible`
- WObject:317 (self)
- WObject:528 (self)

### `WObject.voidClump`
- WObject:285 (self)

### `WavSoundPlayer.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `WavSoundPlayer.nativePlay`
- *(sin llamadas encontradas en el código decompilado)*

### `WavSoundPlayer.nativeStop`
- *(sin llamadas encontradas en el código decompilado)*

### `WavSoundPlayer.nativeVolume`
- *(sin llamadas encontradas en el código decompilado)*

### `WebBrowser.browse`
- WebBrowser:71 (self)
- WebBrowser:92 (self)
- WebBrowser:148 (self)
- WebBrowser:162 (self)

### `WebBrowser.closeBrowser`
- *(sin llamadas encontradas en el código decompilado)*

### `WebBrowser.openBrowser`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.allowFGJavaPalette`
- GammaFrame:43

### `Window.dispose`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.doMicrosoftVMHacks`
- Gamma:112

### `Window.findWindow`
- ClassicSharedTextArea:159
- FileSysDialog:30
- GammaFrameState:220
- NSProtocolHandler:28
- ScapePicCanvas:19
- ScapePicPanel:110
- Window:26 (self)

### `Window.fullHeight`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.fullWidth`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.getActivated`
- InternetExplorer:33

### `Window.getAndResetUserActionCount`
- Console:420
- Console:1107

### `Window.getDeltaMode`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.getFrameWindow`
- FileSysDialog:32

### `Window.getGammaProcessID`
- VoiceChat:186

### `Window.getHiddenCursorDelta`
- ToolBar:132

### `Window.getHwnd`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.getSystemMetrics`
- DefaultConsole:1752

### `Window.getVoiceChatLParam`
- GammaPhoneMonitor:50

### `Window.getVoiceChatWParam`
- GammaPhoneMonitor:49
- GammaPhoneMonitor:50

### `Window.getWindowHeight`
- GammaFrameState:43
- PolledDialog:220

### `Window.getWindowState`
- DefaultConsole:1424
- GammaFrameState:156
- PolledDialog:140

### `Window.getWindowWidth`
- GammaFrameState:43
- PolledDialog:220

### `Window.hideCursor`
- ToolBar:98

### `Window.hookWinAPIs`
- Gamma:146

### `Window.install`
- Window:41 (self)

### `Window.isActivated`
- Gamma:515

### `Window.isVideoPlaying`
- AnimationButton:49

### `Window.makeJavaReleaseCapture`
- DefaultConsole:387

### `Window.maybeResize`
- Window:42 (self)

### `Window.nativeFindChildWindow`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.nativeFindOrMakeChildWindow`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.nativeHideChildWindow`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.nativeInit`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.nativeIsLastLineVisible`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.nativeShowChildWindow`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.playVideoClip`
- AnimationButton:42
- AnimationButton:44
- Window:172 (self)
- Window:175 (self)

### `Window.reShape`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.resetVoiceChatMsg`
- GammaPhoneMonitor:51

### `Window.setChatLine`
- Window:56 (self)

### `Window.setCursor`
- Cursor:59
- Cursor:63

### `Window.setDeltaMode`
- *(sin llamadas encontradas en el código decompilado)*

### `Window.setForegroundWindow`
- NSProtocolHandler:31

### `Window.setVideoMode`
- GammaFrameState:223

### `Window.setWindowState`
- GammaFrameState:225
- NSProtocolHandler:30
- PolledDialog:141

### `Window.usingMicrosoftVMHacks`
- RenderCanvas:162

### `sendURL.get`
- sendURL:36 (self)

### `sendURL.init`
- sendURL:42 (self)

### `sendURL.silent_get`
- sendURL:34 (self)

