# Paquetes de mundo reales (para los tests del instalador)

Dos paquetes del servidor de actualizaciones, uno de cada tipo. Los usa
`editor/worldsplayer_source_editor-main/bridge/test/GdkUpCheck.java`: el
gdkup en Java (`NET.worlds.core.GdkUp`) los instala como lo hacía gdkup.exe
en Windows.

| Fichero | Bytes | SHA-256 | Tipo | Origen |
|---|---|---|---|---|
| `Meteor25.exe` | 511 534 | `6af33e4e94a4b5e949616d8ac939c177d603463450c8be2f1e96fb59232c028b` | Wise (WiseMain + PKZIP), Worlds Inc. 2000 | `http://us1.worlds.net/3DCDup/Meteor/Meteor25.exe` |
| `GroundZero37-40.exe` | 168 984 | `f66ea69f2fe96f8d75b2fb2931d05ac193a2ef7cc85a4d09873d421e6e94e1b4` | NSIS 3 Unicode, rehecho por LibreWorlds | `http://us1.worlds.net/3DCDup/GroundZero/GroundZero37-40.exe` |

`us1.worlds.net` es hoy el espejo de LibreWorlds (upgrade.libreworlds.org).

- **Meteor25.exe**: instalación completa de Meteor en `%MAINDIR%\Meteor`, 24
  ficheros. Su guion sube `MaxInstalledWorlds` y se apunta en el primer hueco
  de `[InstalledWorlds]` de `worlds.ini`. Aborta con "You can't install ...
  until you first install Worlds." si `worlds.ini` no tiene
  `[Gamma] UpgradeServer`.
- **GroundZero37-40.exe**: actualización de GroundZero de la versión 37 a
  la 40 (la que ofrece Options → Upgrade Now). Comprueba que existe
  `..\worlds.ini`. Lee `ver.txt` con FileOpen/FileRead/FileClose y le quita el
  fin de línea con una función (Push/Pop/Exch, StrCpy, IntOp, IntCmp). Si no
  es 37, aborta con "This update requires world version 37, but found N.
  Aborting!". Si lo es, borra cinco ficheros viejos (`custom.wse`,
  `custup.wse`, `groundzero.music`, `tex\ws_ftp.log`, `wav\ws_ftp.log`) y
  extrae `groundzero.world` (205 746 bytes, noviembre de 2025) y `ver.txt`
  (`40`).
