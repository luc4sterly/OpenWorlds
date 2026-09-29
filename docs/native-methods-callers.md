# Call map of `native` methods (before the JNI mock)

Generated before converting each `native` into a logging stub, to find out which code paths actually exercise them at run time. `(self)` = unqualified call inside the file that declares the method itself.

⚠️ **Known limitation, read before drawing conclusions**: this is a text grep (`Class.method(` qualified, or `method(` unqualified inside the same file). It does not understand polymorphism (calling through an interface or a superclass reference), nor `this.method()` invoked from a subclass, nor reflection. With this heuristic, **167 of the 365** methods come out as "no calls found" — that does NOT mean that all 167 are dead code, only that this tool did not trivially find a call site for them. The only two cases confirmed as truly dead code (`PendingCacheDrone.nativeDestroy`, `Console.getVolumeInfo`) were verified separately, also cross-checking against the real exports of `gamma.dll` — see `docs/native-methods-map.md`. For any other method in this list, "no calls found" is a lead to investigate, not a conclusion.

Total `native` declarations: **365**

### `ASFSoundPlayer.nativePlay`
- ASFThread:27
- ASFThread:74

### `ActiveX.getClass`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `CDPlayerAction.playAudio`
- CDAudio:276
- CDAudio:366
- CDPlayerAction:86 (self)

### `CDPlayerAction.resumeAudio`
- *(no calls found in the decompiled code)*

### `CDPlayerAction.setNTAutoPlayCode`
- *(no calls found in the decompiled code)*

### `CDPlayerAction.stopAudio`
- CDAudio:288
- CDAudio:297
- CDAudio:309
- CDAudio:348
- CDPlayerAction:95 (self)

### `Camera.cameraNativeInit`
- Camera:345 (self)

### `Camera.nDrawText`
- *(no calls found in the decompiled code)*

### `Camera.renderScene`
- Camera:103 (self)

### `Console.decrypt`
- Console:607 (self)

### `Console.encrypt`
- Console:580 (self)

### `Console.getVolumeInfo`
- *(no calls found in the decompiled code)*

### `Cursor.destroyCursor`
- Cursor:114 (self)

### `Cursor.getSystemCursorDepth`
- *(no calls found in the decompiled code)*

### `Cursor.getSystemCursorHeight`
- *(no calls found in the decompiled code)*

### `Cursor.getSystemCursorWidth`
- *(no calls found in the decompiled code)*

### `Cursor.loadCursor`
- Cursor:128 (self)

### `Cursor.loadSystemCursor`
- Cursor:101 (self)

### `DDEMLClass.Poke`
- *(no calls found in the decompiled code)*

### `DDEMLClass.Request`
- *(no calls found in the decompiled code)*

### `DDEMLClass.create`
- DDEMLClass:9 (self)

### `DDEMLClass.destroy`
- *(no calls found in the decompiled code)*

### `DDEMLClass.nativeInit`
- *(no calls found in the decompiled code)*

### `DNSLookup.gethostbyname`
- DNSLookup:98 (self)

### `DirectShow.nInit`
- DirectShow:13 (self)
- DirectShow:19 (self)

### `DirectShow.nOpen`
- *(no calls found in the decompiled code)*

### `DirectShow.nPause`
- *(no calls found in the decompiled code)*

### `DirectShow.nPlay`
- *(no calls found in the decompiled code)*

### `DirectShow.nRenderTo`
- DirectShow:29 (self)

### `DirectShow.nShutdown`
- DirectShow:25 (self)

### `DirectShow.nStop`
- DirectShow:24 (self)

### `DirectShow.nTick`
- DirectShow:23 (self)

### `DirectShow.nativeInit`
- *(no calls found in the decompiled code)*

### `DroneAnimator.CreateRep`
- DroneAnimator:55 (self)

### `DroneAnimator.DestroyRep`
- DroneAnimator:59 (self)

### `DroneAnimator.addtype`
- PosableShape:130

### `DroneAnimator.animate`
- *(no calls found in the decompiled code)*

### `DroneAnimator.deltype`
- DroneAnimator:48 (self)

### `DroneAnimator.endanimations`
- *(no calls found in the decompiled code)*

### `DroneAnimator.getActionList`
- PosableShape:1207

### `DroneAnimator.getAnimationTime`
- *(no calls found in the decompiled code)*

### `DroneAnimator.getindexgeom`
- *(no calls found in the decompiled code)*

### `DroneAnimator.getnameindex`
- PosableShape:150
- PosableShape:155

### `DroneAnimator.init`
- DroneAnimator:82 (self)

### `DroneAnimator.loadconfig`
- DroneAnimator:88 (self)
- PendingDrone:192

### `DroneAnimator.moveby`
- *(no calls found in the decompiled code)*

### `DroneAnimator.moveto`
- *(no calls found in the decompiled code)*

### `DroneAnimator.prepFigure`
- PosableShape:132
- PosableShape:1225

### `DroneAnimator.update`
- *(no calls found in the decompiled code)*

### `EventQueue.addEvent`
- EventQueue:77 (self)

### `EventQueue.getEventCount`
- EventQueue:25 (self)

### `EventQueue.getNextEvent`
- EventQueue:85 (self)

### `EventQueue.nativeInit`
- *(no calls found in the decompiled code)*

### `FastDataInput.close`
- *(no calls found in the decompiled code)*

### `FastDataInput.nativeInit`
- *(no calls found in the decompiled code)*

### `FastDataInput.read`
- FastDataInput:11 (self)

### `FastDataInput.readBoolean`
- *(no calls found in the decompiled code)*

### `FastDataInput.readByte`
- *(no calls found in the decompiled code)*

### `FastDataInput.readChar`
- *(no calls found in the decompiled code)*

### `FastDataInput.readDouble`
- *(no calls found in the decompiled code)*

### `FastDataInput.readFloat`
- *(no calls found in the decompiled code)*

### `FastDataInput.readFully`
- FastDataInput:16 (self)
- FastDataInput:17 (self)

### `FastDataInput.readInt`
- *(no calls found in the decompiled code)*

### `FastDataInput.readLong`
- *(no calls found in the decompiled code)*

### `FastDataInput.readShort`
- *(no calls found in the decompiled code)*

### `FastDataInput.readUTF`
- *(no calls found in the decompiled code)*

### `FastDataInput.readUnsignedByte`
- *(no calls found in the decompiled code)*

### `FastDataInput.readUnsignedShort`
- *(no calls found in the decompiled code)*

### `FastDataInput.skipBytes`
- *(no calls found in the decompiled code)*

### `FileSysDialog.nativeRun`
- *(no calls found in the decompiled code)*

### `FileTexture.dictLookup`
- TextureDecoder:44

### `FileTexture.makeTexture`
- FileTexture:10 (self)
- FileTexture:37 (self)

### `FileTexture.nativeInit`
- *(no calls found in the decompiled code)*

### `Hologram.makeTemporarilyInvisible`
- Hologram:251 (self)

### `Hologram.nativeInit`
- *(no calls found in the decompiled code)*

### `Hologram.postrender`
- *(no calls found in the decompiled code)*

### `Hologram.prerender`
- *(no calls found in the decompiled code)*

### `IClassFactory.nActivate`
- IClassFactory:30 (self)

### `IClassFactory.nDeactivate`
- IClassFactory:43 (self)

### `IDispatch.Invoke`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeAddToolbar`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeDestroy`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeGetHWND`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeGoBack`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeGoForward`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeHome`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeInit`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativePrint`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeRefresh`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeResize`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeSetURL`
- *(no calls found in the decompiled code)*

### `IEWebControlImp.nativeStop`
- *(no calls found in the decompiled code)*

### `INetscapeRegistry.RegisterProtocol`
- *(no calls found in the decompiled code)*

### `INetscapeRegistry.RegisterViewer`
- *(no calls found in the decompiled code)*

### `IUnknown.QueryInterface`
- IUnknown:90 (self)

### `IUnknown.getPtr`
- *(no calls found in the decompiled code)*

### `IUnknown.true_AddRef`
- IUnknown:144 (self)

### `IUnknown.true_Release`
- IUnknown:111 (self)

### `IWebBrowserApp.Navigate`
- *(no calls found in the decompiled code)*

### `IWebBrowserApp.Quit`
- *(no calls found in the decompiled code)*

### `IWebBrowserApp.put_MenuBar`
- *(no calls found in the decompiled code)*

### `IWebBrowserApp.put_StatusBar`
- *(no calls found in the decompiled code)*

### `IWebBrowserApp.put_Visible`
- *(no calls found in the decompiled code)*

### `ImageConverter.cleanup`
- ImageConverter:49 (self)

### `ImageConverter.convertDIBToTexture`
- ImageConverter:46 (self)

### `ImageConverter.nativeInit`
- *(no calls found in the decompiled code)*

### `ImageConverter.prepareDIB`
- ImageConverter:93 (self)

### `ImageConverter.setDIBPixelBytes`
- ImageConverter:117 (self)

### `ImageConverter.setDIBPixelInts`
- ImageConverter:126 (self)

### `IniFile.getIniInt`
- *(no calls found in the decompiled code)*

### `IniFile.getIniString`
- *(no calls found in the decompiled code)*

### `IniFile.nativeInit`
- *(no calls found in the decompiled code)*

### `IniFile.setIniInt`
- *(no calls found in the decompiled code)*

### `IniFile.setIniString`
- *(no calls found in the decompiled code)*

### `Light.destroyLight`
- Light:17 (self)

### `Light.setLightTransform`
- Light:24 (self)

### `MCISoundPlayer.isActive`
- CDAudio:376
- CDAudio:380

### `MCISoundPlayer.nativeIsFinished`
- *(no calls found in the decompiled code)*

### `MCISoundPlayer.nativeStart`
- *(no calls found in the decompiled code)*

### `MCISoundPlayer.nativeStop`
- *(no calls found in the decompiled code)*

### `MCISoundPlayer.nativeVolume`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `Material.nativeSetTexture`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `PendingCacheDrone.nativeInit`
- *(no calls found in the decompiled code)*

### `PendingCacheDrone.notifySeqLoaded`
- PendingCacheDrone:28 (self)
- PendingCacheDrone:38 (self)
- SeqFile:14

### `Pilot.nativeInit`
- *(no calls found in the decompiled code)*

### `Point3Temp.nativeInit`
- *(no calls found in the decompiled code)*

### `Point3Temp.times`
- Point3Temp:120 (self)
- Point3Temp:127 (self)

### `Point3Temp.vectorTimes`
- *(no calls found in the decompiled code)*

### `Polygon.nativeSetVertex`
- *(no calls found in the decompiled code)*

### `Portal.nativeInit`
- *(no calls found in the decompiled code)*

### `Portal.postrender`
- *(no calls found in the decompiled code)*

### `Portal.prerender`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `RegKey.createKey`
- RegKey:19 (self)

### `RegKey.getIntValue`
- *(no calls found in the decompiled code)*

### `RegKey.getReservedKey`
- RegKey:14 (self)

### `RegKey.getStringValue`
- *(no calls found in the decompiled code)*

### `RegKey.nativeInit`
- *(no calls found in the decompiled code)*

### `RegKey.openKey`
- RegKey:21 (self)

### `RegKey.setIntValue`
- *(no calls found in the decompiled code)*

### `RegKey.setStringValue`
- *(no calls found in the decompiled code)*

### `RenderCanvasOverlay.nativeKillChild`
- *(no calls found in the decompiled code)*

### `RenderCanvasOverlay.nativeMakeChild`
- *(no calls found in the decompiled code)*

### `RenderCanvasOverlay.nativeResizeChild`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `ScapePicCanvas.bitBlt`
- ScapePicCanvas:25 (self)
- ScapePicPanel:116

### `ScapePicImage.flush`
- ScapePicImage:26 (self)

### `ScapePicImage.loadImage`
- ScapePicImage:12 (self)

### `ScapePicImage.nativeInit`
- *(no calls found in the decompiled code)*

### `ScapePicMovie.lookupTextures`
- ScapePicMovie:78 (self)

### `ScapePicMovie.makeTextures`
- ScapePicMovie:82 (self)

### `ScapePicMovie.nativeInit`
- *(no calls found in the decompiled code)*

### `ScapePicTexture.makeTexture`
- ScapePicTexture:17 (self)
- ScapePicTexture:77 (self)

### `ScapePicTexture.nativeInit`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `Shape.nativeSetMaterial`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `Std.getPerformanceFrequency`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `Std.instanceOf`
- ObjectSelectorDialog:63

### `Std.nativeGetMillis`
- *(no calls found in the decompiled code)*

### `StringTexture.makeStringTexture`
- StringTexture:24 (self)
- StringTexture:55 (self)

### `StringTexture.nativeInit`
- *(no calls found in the decompiled code)*

### `Surface.addPolygon`
- Surface:52 (self)

### `Surface.addSubPolys`
- Surface:54 (self)

### `Surface.addVertex`
- *(no calls found in the decompiled code)*

### `Surface.nativeInit`
- *(no calls found in the decompiled code)*

### `Surface.nativeSetMaterial`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `Texture.nativeGetH`
- *(no calls found in the decompiled code)*

### `Texture.nativeGetW`
- *(no calls found in the decompiled code)*

### `Texture.nativeInit`
- *(no calls found in the decompiled code)*

### `Texture.nativeRelease`
- *(no calls found in the decompiled code)*

### `TextureSurface.nativeDestroyDC`
- *(no calls found in the decompiled code)*

### `TextureSurface.nativeGetDC`
- *(no calls found in the decompiled code)*

### `TextureSurface.nativeInit`
- *(no calls found in the decompiled code)*

### `TextureSurface.nativeLeftClick`
- *(no calls found in the decompiled code)*

### `TextureSurface.nativeMakeDC`
- *(no calls found in the decompiled code)*

### `TextureSurface.nativeReleaseDC`
- *(no calls found in the decompiled code)*

### `Transform.getGuts`
- Transform:258 (self)
- Transform:325 (self)

### `Transform.getPitch`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `Transform.getZ`
- HoloPilot:408
- Transform:49 (self)

### `Transform.invert`
- Transform:227 (self)

### `Transform.isTransformEqual`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `Transform.nativeInit`
- *(no calls found in the decompiled code)*

### `Transform.postHelper`
- Transform:125 (self)

### `Transform.postscaleHelper`
- Transform:181 (self)

### `Transform.postspin`
- HoloPilot:412
- Transform:200 (self)
- Transform:201 (self)

### `Transform.pre`
- *(no calls found in the decompiled code)*

### `Transform.premoveBy`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `VehicleShape.nativeGetCogX`
- *(no calls found in the decompiled code)*

### `VehicleShape.nativeGetCogY`
- *(no calls found in the decompiled code)*

### `VehicleShape.nativeGetCogZ`
- *(no calls found in the decompiled code)*

### `VehicleShape.nativeGetMoiX`
- *(no calls found in the decompiled code)*

### `VehicleShape.nativeGetMoiY`
- *(no calls found in the decompiled code)*

### `VehicleShape.nativeGetMoiZ`
- *(no calls found in the decompiled code)*

### `VehicleShape.nativeGetTirePosX`
- *(no calls found in the decompiled code)*

### `VehicleShape.nativeGetTirePosY`
- *(no calls found in the decompiled code)*

### `VehicleShape.nativeGetTirePosZ`
- *(no calls found in the decompiled code)*

### `VoiceChat.terminateVC`
- *(no calls found in the decompiled code)*

### `WObject.addChildToClump`
- WObject:314 (self)

### `WObject.createClump`
- WObject:308 (self)

### `WObject.doneWithEditing`
- *(no calls found in the decompiled code)*

### `WObject.extractClump`
- *(no calls found in the decompiled code)*

### `WObject.getClumpBBox`
- WObject:413 (self)
- WObject:416 (self)
- WObject:749 (self)

### `WObject.getClumpMinXYExtent`
- WObject:760 (self)

### `WObject.getJointedObjectToWorldMatrix`
- *(no calls found in the decompiled code)*

### `WObject.getNumVerts`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `WObject.nativeInit`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `WavSoundPlayer.nativePlay`
- *(no calls found in the decompiled code)*

### `WavSoundPlayer.nativeStop`
- *(no calls found in the decompiled code)*

### `WavSoundPlayer.nativeVolume`
- *(no calls found in the decompiled code)*

### `WebBrowser.browse`
- WebBrowser:71 (self)
- WebBrowser:92 (self)
- WebBrowser:148 (self)
- WebBrowser:162 (self)

### `WebBrowser.closeBrowser`
- *(no calls found in the decompiled code)*

### `WebBrowser.openBrowser`
- *(no calls found in the decompiled code)*

### `Window.allowFGJavaPalette`
- GammaFrame:43

### `Window.dispose`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `Window.fullWidth`
- *(no calls found in the decompiled code)*

### `Window.getActivated`
- InternetExplorer:33

### `Window.getAndResetUserActionCount`
- Console:420
- Console:1107

### `Window.getDeltaMode`
- *(no calls found in the decompiled code)*

### `Window.getFrameWindow`
- FileSysDialog:32

### `Window.getGammaProcessID`
- VoiceChat:186

### `Window.getHiddenCursorDelta`
- ToolBar:132

### `Window.getHwnd`
- *(no calls found in the decompiled code)*

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
- *(no calls found in the decompiled code)*

### `Window.nativeFindOrMakeChildWindow`
- *(no calls found in the decompiled code)*

### `Window.nativeHideChildWindow`
- *(no calls found in the decompiled code)*

### `Window.nativeInit`
- *(no calls found in the decompiled code)*

### `Window.nativeIsLastLineVisible`
- *(no calls found in the decompiled code)*

### `Window.nativeShowChildWindow`
- *(no calls found in the decompiled code)*

### `Window.playVideoClip`
- AnimationButton:42
- AnimationButton:44
- Window:172 (self)
- Window:175 (self)

### `Window.reShape`
- *(no calls found in the decompiled code)*

### `Window.resetVoiceChatMsg`
- GammaPhoneMonitor:51

### `Window.setChatLine`
- Window:56 (self)

### `Window.setCursor`
- Cursor:59
- Cursor:63

### `Window.setDeltaMode`
- *(no calls found in the decompiled code)*

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

