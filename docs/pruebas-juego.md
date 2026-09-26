# Pruebas del juego: el cliente original de 2004 bajo el puente

Sesión del 2026-09-26. Se probó todo lo que se puede hacer en el juego, a
mano, con el paquete del lanzador (`build/dist`, `FreeWorlds --original`)
en Linux: Xvfb 1280×960 sin gestor de ventanas, Java 21, el espejo activado
(`us1.worlds.net`, que hoy es LibreWorlds) y sin servidor de mundos, es
decir, en modo monousuario ("Single-user mode" en el diálogo "Internet
Connection").

Capturas: `docs/renders/mapa-del-universo.png`, `blairwitch-cafeteria.png`,
`bowie-bwstreet.png` y `cmp-taza-y-caleidoscopio.png`.

## Viajes entre mundos

La instalación de 2004 solo trae GroundZero: los otros 11 mundos se
descargaron del espejo. Instalar un mundo sigue el camino del original. El teletransporte falla
porque el mundo no está, y `NetUpdate` pide `upgrades.lst` y ofrece el
paquete. Con "Yes - download now" lo descarga (el servidor local del
lanzador lo pide al espejo) y luego pregunta "Restart and Upgrade". El
cliente pide `gdkup.exe updates.lst <pid>` y se cierra. El gdkup en Java
instala el paquete (Wise o NSIS), apunta el mundo en `worlds.ini` y
arranca otra vez el cliente con `world:restart`.

| Mundo | Cómo se llegó | Paquete | Resultado |
|---|---|---|---|
| GroundZero | arranque | (instalado) | ✅ estatuas con textura gracias al espejo |
| AvatarGallery | mapa de GroundZero | AvatarGallery36 (Wise) | ✅ descarga, instalación y reinicio |
| WorldsChat (Worlds Center, Chat Deck) | mapa | WorldsChat50 (NSIS) | ✅ descarga, instalación y reinicio |
| AnimalHouse (casa, Club) | mapa | AnimalHouse33 (Wise) | ✅ |
| lets (Hang, Events) | mapa | lets62 (Wise) | ✅ |
| Meteor | mapa | Meteor25 (Wise) | ✅ |
| Dcn | menú Teleport | Dcn10 (NSIS) | ✅ |
| PolyGram (WorldsStore.com) | mapa, "Store" | PolyGram49 (Wise, 12,6 MB) | ✅ descarga, instalación y reinicio |
| DressingRoom | menú Teleport | DressingRoom3 (Wise) | ✅; el caleidoscopio `kcl.mov` no cargaba (arreglado) |
| Chaos (el mundo de David Bowie) | WorldsMark → Change Location... | Chaos14 (Wise) | ✅ tras arreglar el cierre del diálogo |
| BWStreet (BowieWorld, "Street Maze") | ofrecido desde Chaos, luego Change Location | BWStreet3 (Wise) | ✅ descarga, instalación y reinicio |
| The Blair Witch World (TheBurkittsvilleDiner) | mapa del universo | TheBurkittsvilleDiner14 (Wise) | ✅ la cafetería de Burkittsville; el holograma de la taza no cargaba (arreglado) |
| GroundZero 37 → 40 | Options → Upgrade Now | GroundZero37-40 (NSIS de LibreWorlds) | ✅ tras añadir 5 instrucciones NSIS |

Mundos del mapa del universo que sirve el espejo (todos responden con su
`upgrades.lst`): HansonStage, Aerosmith, AnimalHouse, Hanson World II,
Meteor, BowieWorld II, B.T. Openworld, WWF New York, Centis, Hang,
N.Y. Yankees World (`Stadium`), Avatar Gallery, The Blair Witch World,
Dcn, Worlds Center y Ground Zero. También la familia Bowie (BWStreet,
BWDecade, BWArt, BWAvatar, Bowie, 13 MB) y Chaos.

## Funciones del juego

| Función | Resultado | Nota |
|---|---|---|
| Andar y girar (flechas) | ✅ | tras cuantizar el reloj como GetTickCount (antes el giro iba lentísimo a 600-800 fps) |
| Cámaras (Overhead, First-person, Behind) | ✅ | Options → Change Avatar View |
| Chat | ✅ | offline dice que no hay conexión, como el original |
| Help → About | ✅ | con las versiones de los mundos |
| Teleport (con submenús) | ✅ | |
| Actions (gestos) | ✅ | ⚠️ "Sleep" no se ve en el pingüino |
| WorldsMark → Add new WorldsMark... | ✅ | el marcador aparece en el menú |
| WorldsMark → Change Location... | ✅ | lleva a la URL escrita; antes congelaba toda la UI (arreglado) |
| WorldsMail | ✅ | To/Subject/cuerpo, Send cierra la ventana; el correo sale por SMTP al servidor de 2004 (muerto) y no llega |
| VIP → Become a VIP | ✅ | abre `www-dynamic.us.worlds.net/cgi-bin/vip.pl`: el puente anota la URL y no la abre salvo con `-Dfreeworlds.openUrls=1` |
| VIP → Choose Avatar, Saved Avatars, Customize Avatar, Accept Voice Calls, # Visible Users | gris | son de VIP, como en 2004; sin VIP el avatar se cambia pinchando las estatuas de Avatar Gallery |
| Options → Edit Friends (Add, Done) | ✅ | "FRIENDS ONLINE" solo lista a los conectados |
| Options → Proxy Server Settings | ✅ | diálogo con dos campos, Cancel lo cierra |
| Options → Account Info | ✅ | como Become a VIP (`account.pl`) |
| Options → Upgrade Now | ✅ | revisa los mundos instalados en el espejo y ofrece GroundZero 37 → 40 |
| Mapa del universo | ✅ | 16 mundos; los no instalados ofrecen la descarga, los instalados "Start"; se mueve con las flechas. Antes cerraba el juego (arreglado) |
| Botón derecho en la vista 3D | ✅ | solo sale sobre objetos con acciones de menú (otros avatares); en el suelo nada, como el original |
| Quit | ✅ | |
| Sonido / Music... | no probado | el contenedor no tiene dispositivo de sonido ni MIDI |
| Delete/Edit WorldsMark, Recorder, Sign In, Reject Whispers, Hide Nametags, Enable Colored Chat | no probado | |

## Fallos encontrados y arreglados

1. **Diálogos con campo de texto congelaban la UI** (WorldsMark → Change
   Location..., y también Add WorldsMark, Mail, Edit Friends, Proxy...).
   `PolledDialog.mainCallback` es `synchronized` y cierra el diálogo con
   `setVisible(false)`, `parent.requestFocus()` y `dispose()`. En el Java de
   hoy `dispose()` espera al hilo de eventos. En X11 el método de entrada
   pide notificación de la ventana cliente, así que ese hilo toma el monitor
   de la ventana al quitar el campo de texto. Resultado: un bloqueo mutuo, con
   el diálogo en negro para siempre. Solo pasa en X11: `XInputMethod`
   llama a `enableClientWindowNotification` y los de macOS y Windows no.
   Arreglo: `AwtCompat.closeHoldingLock` hace las tres llamadas en el hilo
   de eventos con el monitor soltado. Test: `bridge/test/UiDisposeCheck.java`,
   que además reproduce el bloqueo con el cierre original.
2. **El mapa del universo cerraba el juego.** El mock de
   `Window.usingMicrosoftVMHacks()` devolvía `true`, así que
   `RenderCanvas.handle` pedía `getLocationOnScreen` al lienzo oculto y la
   excepción salía del bucle principal. En gamma.dll es `DAT_004891cc == 1`
   (0x0040de40), y solo lo pone `doMicrosoftVMHacks` (0x0040de30), que
   `Gamma.main` llama con la JVM de Microsoft.
3. **Holograma `tex/mug.cmp` (Blair Witch)**: un fotograma puede ir en
   varios grupos de filas (FUN_00442bc0), y el lector solo decodificaba el
   primero. Ahora `CmpFrames` los recorre todos y conserva la fila `esi`
   entre grupos y fotogramas, como el búfer único de 0x442750. Muestra y
   evidencia: `assets/cmp-verified/mug/`; test: `CmpGroupsCheck`.
4. **`kcl.mov` (vestuario, DressingRoom)**: con el byte 13 de la cabecera
   distinto de 0, gamma.dll salta además el número de colores en la región
   de tablas (0x442963..0x442983). Muestra: `assets/cmp-verified/kcl/`.
5. **Upgrade Now de GroundZero**: el NSIS 37 → 40 usa Delete (21),
   Push/Pop/Exch (31), FileClose (54), FileOpen (55) y FileRead (57), que el
   intérprete NSIS no tenía. Test: `bridge/test/GdkUpCheck.java`, con los
   paquetes reales de `assets/packages/`.
6. **Un instalador que abortaba dejaba al jugador sin juego**: el gdkup en
   Java paraba ahí. gdkup.exe no lee el código de salida de cada línea
   (0x00401e75, mensaje 0x402). Borra el paquete, sigue con la siguiente y
   al final reinicia. Solo se para si la línea no arranca (0x00401d52). Ahora
   hace lo mismo.
7. `tools/local-upgrade-server.py` respondía vacío (con traza) a una ruta
   fuera de `/3DCDup/`. Ahora da 404, y con `--mirror` pide al espejo lo que
   falte, como el lanzador. `run_gamma.sh` lo usa y aplica `gdkup.pending`.

## Abierto

- `Hologram.setActiveSide` imprime "Error ... side 1 of 1" en bucle en
  DressingRoom y en Blair Witch. Es fiel: gamma.dll (0x00413ce0) compara el
  lado contra `2·n`, no contra `n`, y el Java de 2004 lo avisa y usa el 0.
- Datos rotos del propio mundo de Blair Witch: `bench05.cmp` sin `tex/` y
  `tex/null.cmp`, que no existen.
- Chaos perdió su hueco en `[InstalledWorlds]` al instalar Dcn. Es fiel a
  los dos guiones: el de Chaos14 no sube `MaxInstalledWorlds` y el NSIS
  apunta en `Max+1`. Chaos sigue instalado y se puede cargar.
- Los parches incrementales xdelta (`%XDZ`) de los mundos viejos no se
  aplican. `GdkUp` los da por terminados y sigue.
- El chat de voz (`sfmain.exe`, SpeakFreely con GSM) está decompilado pero
  no traducido.
- Varios usuarios: no se volvió a probar en esta sesión. La prueba anterior,
  con dos clientes contra `server/whirl`, está en `docs/net-local-whirl.md`.
