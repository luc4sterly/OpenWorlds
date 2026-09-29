# Real world packages (for the installer tests)

Two packages from the update server, one of each type. They are used by
`editor/worldsplayer_source_editor-main/bridge/test/GdkUpCheck.java`: the
Java gdkup (`NET.worlds.core.GdkUp`) installs them the way gdkup.exe did
on Windows.

| File | Bytes | SHA-256 | Type | Origin |
|---|---|---|---|---|
| `Meteor25.exe` | 511,534 | `6af33e4e94a4b5e949616d8ac939c177d603463450c8be2f1e96fb59232c028b` | Wise (WiseMain + PKZIP), Worlds Inc. 2000 | `http://us1.worlds.net/3DCDup/Meteor/Meteor25.exe` |
| `GroundZero37-40.exe` | 168,984 | `f66ea69f2fe96f8d75b2fb2931d05ac193a2ef7cc85a4d09873d421e6e94e1b4` | NSIS 3 Unicode, remade by LibreWorlds | `http://us1.worlds.net/3DCDup/GroundZero/GroundZero37-40.exe` |

`us1.worlds.net` is today the LibreWorlds mirror (upgrade.libreworlds.org).

- **Meteor25.exe**: full installation of Meteor in `%MAINDIR%\Meteor`, 24
  files. Its script raises `MaxInstalledWorlds` and adds itself to the first
  free slot of `[InstalledWorlds]` in `worlds.ini`. It aborts with "You can't
  install ... until you first install Worlds." if `worlds.ini` does not have
  `[Gamma] UpgradeServer`.
- **GroundZero37-40.exe**: GroundZero update from version 37 to
  40 (the one offered by Options → Upgrade Now). It checks that
  `..\worlds.ini` exists. It reads `ver.txt` with FileOpen/FileRead/FileClose
  and strips the end of line with a function (Push/Pop/Exch, StrCpy, IntOp,
  IntCmp). If it is not 37, it aborts with "This update requires world
  version 37, but found N. Aborting!". If it is, it deletes five old files
  (`custom.wse`, `custup.wse`, `groundzero.music`, `tex\ws_ftp.log`,
  `wav\ws_ftp.log`) and extracts `groundzero.world` (205,746 bytes, November
  2025) and `ver.txt` (`40`).
