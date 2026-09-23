# Red con sesión en local: el cliente original contra whirl

Hito H3 de `docs/roadmap.md`. Dos clientes **originales** (el Java de 2004 bajo
el puente portable, `editor/worldsplayer_source_editor-main/bridge/`) contra el
servidor de terceros `server/whirl`, compilado sin tocar su código, en este Mac.

Medido el 2026-09-23 (`nightly-2024-06-03`, JDK 25, macOS 15.7 Intel).

## Resultado

| Qué | Estado | Evidencia |
|---|---|---|
| whirl en local, solo en 127.0.0.1 | ✅ | `lsof`: `127.0.0.1:6650` y `127.0.0.1:5673` (LISTEN), 0,0 % de CPU |
| El cliente conecta al whirl local | ✅ | mecanismo propio del cliente, `override.ini` `[Runtime] WorldServer=` |
| Handshake con el distributor (AutoServer) | ✅ | `PROPREQ` → `PROPUPD #15=1` → `AutoServer detected server type 1` → `UserServer` |
| Login (LoginWizard → SESSINIT) | ✅ | `SESSINIT (VAR_ERROR=0 ... VAR_SERVERTYPE=1 ...)` |
| Salas: ROOMIDRQ → REDIRID → RoomServer (hub) | ✅ (con un fallo de whirl, ver abajo) | 12 `REDIRID ... -> 127.0.0.1:5673`, `SESSINIT (VAR_ERROR=0 VAR_SERVERTYPE=3 ...)` |
| Dos clientes en la misma sala | ✅ | los dos hacen `TELEPORT ... in 4` (GroundZero, sala de entrada) |
| Chat de A llega a B | ✅ | whirl: `received text from FWTestA: hola desde A` / `broadcasted text to hub`; área de chat de B: `FWTestA> hola desde A` |
| El cliente crea un Drone cuando el servidor lo manda | ✅ | con la orden de prueba `/spawn fuwn` de whirl, A y B: `HoloDrone '!fuwn' en IconViewRoom1a @ 191.0,173.0,0.0` |
| A ve el avatar de B y viceversa | ❌ **falta en whirl** | whirl nunca manda `APPRACTR`/`TELEPORT` de los usuarios reales (ver diferencias) |
| Lista de amigos | ⬜ no probado | whirl solo hace eco de `BUDDYLISTUPDATE` (`hub.rs`/`distributor.rs`) |

## Comandos

```bash
editor/worldsplayer_source_editor-main/build_gamma.sh

# Prueba completa (arranca whirl, B, luego A; A chatea; vuelca y para todo):
tools/net-probe/run-whirl-duo.sh <DIR_SALIDA>
#   <DIR_SALIDA>/srv/.whirl/whirl.log, runA.log, runB.log

# Por partes:
tools/run-whirl.sh <DIR_WHIRL>            # distributor 127.0.0.1:6650 + hub :5673
FREEWORLDS_GAMMA_DIR=<dir> FREEWORLDS_SERVER=127.0.0.1:6650 \
FREEWORLDS_USER=FWTestA FREEWORLDS_LOGIN=fwtest1 FREEWORLDS_NETDEBUG=1253 \
FREEWORLDS_CHAT="15000:hola desde A" JAVA_OPTS="-Xmx512m -Dfreeworlds.dumpChat=30000" \
  editor/worldsplayer_source_editor-main/run_gamma.sh home:GroundZero/groundzero.world
tools/run-whirl.sh --stop <DIR_WHIRL>
```

`tools/run-whirl.sh` (variables `WHIRL_IP`, `WHIRL_PORT`, `WHIRL_HUB_PORT`,
`WHIRL_LOG_LEVEL`, `WHIRL_BIN`):

- Usa el binario ya compilado (`server/whirl/target/debug/whirl`) con
  `run distributor,hub`; la API HTTP no la usa el cliente.
- whirl lee siempre `.whirl/Config.toml` relativo a su cwd
  (`whirl_config/src/lib.rs`) y fija `DATABASE_URL=.whirl/db.sqlite3`
  (`whirl/src/lib.rs`): el script genera el `Config.toml` (a partir de
  `.whirl/Config.example.toml`) en el directorio que se le da y ahí escribe el
  log. **No hacen falta la base de datos ni las migraciones diesel**: fuera de
  `whirl_db` nadie llama a `establish_connection`.
- **Solo 127.0.0.1**: `whirlsplash.ip` es la dirección de `bind` de los dos
  servidores (`whirl_server/src/lib.rs`, `make::distributor/hub`) y además la
  IP que el distributor manda en `REDIRID` (`redirect_id.rs`).
- Deja el prompt de whirl **activado** con un stdin que nunca escribe (un FIFO
  abierto por `tail -f /dev/null`): con el prompt desactivado, `cli.rs` espera
  en `loop { std::thread::sleep(Duration::default()) }`, un sleep de 0 que deja
  un núcleo al 100 %.

`run_gamma.sh` (solo actúa sobre la copia temporal de la instalación):

- `FREEWORLDS_SERVER=host:puerto` añade `WorldServer=worldserver://host:puerto`
  a `[Runtime]` de `override.ini`. Es el mecanismo del propio cliente:
  `NetUpdate.<clinit>` lo lee y `World.setWorldServerURL` sustituye con él
  toda URL `worldserver://www.3dcd.com[:puerto]`, que es
  `World.defaultServerURL` (`World.java:54`), la de GroundZero. No hace falta
  redirigir DNS (`apply_mock.sh` no se ha tocado).
- `FREEWORLDS_USER=nombre` pone `User0=nombre` en la sección `[host:puerto]` de
  `worlds.ini`, la que lee el LoginWizard (`Galaxy.getIniSection`).
- `FREEWORLDS_NETDEBUG=N` pone `netdebug=N`. 1253 = 1 sendText, 4 sessionInit,
  32 tipo de servidor, 64 recv, 128 send, 1024 bytes enviados.
- `FREEWORLDS_LOGIN=contraseña` o `FREEWORLDS_CHAT=...` arrancan por
  `tools/net-probe/LoginDriver.java` en vez de `Gamma` a pelo.

### El arnés `LoginDriver`

Llama al `Gamma.main` real y, en un hilo aparte, hace con la UI AWT lo que
haría una persona; no toca lógica del cliente:

- En el LoginWizard (pantalla HAVE_USERS) escribe la contraseña en el campo con
  eco `*`, **desmarca "Remember password"** y pulsa el `ForwardButton`
  ("Sign In") posteando el `ActionEvent` de un clic.
- `FREEWORLDS_CHAT=MS:texto[;MS:texto]`: escribe en la línea de chat a los MS
  ms de cerrarse el LoginWizard y le entrega el `Event` 1.0 `ACTION_EVENT` de
  Intro (ver "Hallazgos", punto 2).
- `-Dfreeworlds.dumpChat=MS,...` vuelca el área de chat (`[CHAT]`);
  `-Dfreeworlds.dumpDrones=MS,...` lista los `Drone` de todas las salas
  cargadas con su sala y posición (`[DRONES]`).

Las contraseñas y nombres (`FWTestA`, `FWTestB`, `fwtest1`) son de prueba y
solo para el whirl local, que no valida contraseñas (`distributor.rs:78-83`
solo lee `VAR_USERNAME`).

## Intercambio medido (A, `netdebug` 1253, recortado)

```
AutoServer(127.0.0.1:6650): send(PROPREQ 255) / send[3 ff a ]
recv(PROPUPD 255 (#27 worlds3d.com #26 mail.worlds.net:25
  #25 http://www-dynamic.us.worlds.net/cgi-bin #24 http://www-static.us.worlds.net
  #15 1 #3 24 #1 WORLDSMASTER))
AutoServer detected server type 1                       -> UserServer, LoginWizard
send(SESSINIT (VAR_PROTOCOL=24 VAR_CLIENT=2004080500 VAR_USERNAME=FWTestA
  VAR_PASSWORD=fwtest1 VAR_LOGONOFF=1))
recv(SESSINIT (VAR_ERROR=0 VAR_APPNAME=WORLDSMASTER VAR_PROTOCOL=24
  VAR_SERVERTYPE=1 VAR_SERIAL=DWLV000000000000 VAR_PRIV=0 VAR_CHANNEL=dimension-1))
send(PROPSET ""->1[FWTestA] (#5 avatar:pengo.mov))
send(ROOMIDRQ GroundZero#IconViewRoom1Enter<dimension-1>) ... (12 salas)
recv(TEXT WORLDSMASTER: Welcome to Whirlsplash!)
recv(REDIRID GroundZero#IconViewRoom1Enter<dimension-1>==0 -> 127.0.0.1:5673)
  ... Reception<dimension-1>==11
127.0.0.1:5673: send(PROPREQ) / recv(PROPUPD ... #15 3 ...)
send(SESSINIT (VAR_PROTOCOL=24 VAR_CLIENT=2004080500 VAR_AVATARS=24
  VAR_USERNAME=FWTestA VAR_PASSWORD=fwtest1))
recv(SESSINIT (VAR_ERROR=0 VAR_SERVERTYPE=3 VAR_UPDATETIME=1000000 VAR_PROTOCOL=24))
send(SUBSCRIB 11 ... 1) / send(ROOMIDRQ GroundZero#IconViewRoom1Enter) (al hub)
send(TELEPORT 1[FWTestA] <0 >1 in 4 @ 115,162,0,189) / send(SUB-DIST ...)
recv(REGOBJID 0 --> FWTestB (0)) x11 / recv(REGOBJID 1 --> FWTestA (1))
sendText(hola desde A) / recv(TEXT FWTestA: hola desde A)
```

## Diferencias de whirl con el protocolo del cliente (con evidencia)

Quién tiene razón se decide con el código del cliente; whirl no se ha tocado.

1. **Nadie ve a nadie.** El cliente solo crea un `Drone` al recibir
   `APPRACTR` (`appearActorCmd.process` → `Drone.make`) o un `TELEPORT` de un
   objeto que no conoce (`teleportCmd.process`); `LONGLOC` solo mueve un
   `Drone` que ya existe (`longLocCmd.process`). El hub de whirl
   (`hub.rs`) responde al `TELEPORT` del cliente registrando un objeto nuevo y
   difundiendo solo `REGOBJID`; el `APPRACTR` de `SubDist` está construido y
   comentado (`// peer.bytes.get_mut().write_all(&actor)`). El camino del
   cliente sí funciona: con `/spawn fuwn` (bytes fijos de whirl:
   `REGOBJID`+`TELEPORT` con CO=254+`PROPUPD avatar:Vamp.mov`) A y B crean
   `HoloDrone '!fuwn'` en `IconViewRoom1a` y le piden sus propiedades
   (`send(PROPREQ fuwn)`).
2. **Identificadores cortos que chocan con los reservados.** whirl da a cada
   `TELEPORT` el siguiente índice de `object_ids` empezando en 0, y el 1 es
   `CLIENT` (el propio usuario: `RoomServer.buildSessionInitCmd` hace
   `regShortID(1, nombre)`; `net/constants.rs` también lo define). Medido: B
   recibe `REGOBJID 1 --> FWTestA (1)` y a partir de ahí imprime los `LONGLOC`
   con id 1 como `1[FWTestA (1)]`. Además el id largo es `"nombre (n)"`, no el
   nombre de usuario, y cada `TELEPORT` (cambio de sala) crea otro objeto.
3. **`LONGLOC` reenviado con el id del emisor.** El hub difunde el `LONGLOC`
   a todos (también al emisor) con el objId de la trama original, que es 1
   (`CLIENT`) para todos los clientes: el receptor lo toma por sí mismo y, como
   no es un `Drone`, lo ignora.
4. **`SUBSCRIB` repite todos los `REGOBJID`**: A recibe 11 veces
   `REGOBJID 0 --> FWTestB (0)` (un `SUBSCRIB` por sala suscrita).
5. **ID de sala 0.** El distributor numera las salas por su posición en un
   vector **por conexión**, empezando en 0 (`distributor.rs`, `room_ids`). El
   cliente trata el 0 como "sin ID": `Galaxy.regRoomID` solo registra si
   `var1 != 0`. Medido: la primera sala pedida (`IconViewRoom1Enter`) recibe
   `==0` y el cliente la vuelve a pedir al hub, que no contesta `ROOMIDRQ`
   (bloque comentado `TODO: IMPLEMENT` en `hub.rs`). Que los IDs coincidan
   entre A y B es casualidad: los dos piden las mismas salas en el mismo orden.
6. **Chat sin salas.** `TEXT` se difunde a todos los pares del hub, estén en
   la sala que estén, incluido el emisor (A ve su propio `FWTestA: hola desde A`
   por la red). El remitente es el `VAR_USERNAME` del `SESSINIT` del hub.
7. **Propiedades fijas de 2004.** `PROPUPD` del distributor y del hub anuncian
   `#25 http://www-dynamic.us.worlds.net/cgi-bin` y
   `#24 http://www-static.us.worlds.net` (`property/create.rs`): el cliente
   usará esos hosts para scripts (VIP, registro, anuncios), no el servidor
   local.
8. **Tipo de servidor.** El distributor anuncia `#15=1` (`USER_SERVER_DB`),
   igual que el primario real (`docs/net-handshake-trace.log`), así que el
   cliente pide usuario y contraseña (`UserServer`, modo 2 AUTHENTICATE); el
   hub anuncia 3 (`ROOM_SERVER_US`). ✅ el cliente acepta ambos.
9. Menor: whirl malinterpreta el `SUBSCRIB` en su log (coordenadas y
   distancias sin sentido: `SubscribeRoom { room_number: 11, x: -119.0, ... }`
   para `SUBSCRIB 11: 1751cm @ 3721,949,0`); no afecta al cliente porque no
   usa esos valores.

## Hallazgos del lado del cliente

1. **Carrera en `WorldServer`/`WSConnecting` del original** (verificado en el
   bytecode de `assets/worlds.jar` con `javap`): el constructor de
   `WSConnecting` arranca los hilos de conexión (`makeThread(-1)` y
   `makeThread(0..)`, bytes 41-43 y 104-107) antes de volver, y
   `WorldServer.state_Initializing` asigna `_connectThread` **después**
   (`new WSConnecting` / `putfield _connectThread`, bytes 421-433).
   `setSocket`, que llama el hilo de conexión, empieza por
   `getfield _connectThread; invokevirtual getBackupHosts` (bytes 0-4), sin
   sincronización. Con un servidor en la misma máquina la conexión TCP termina
   antes de la asignación y sale
   `NullPointerException ... "this._connectThread" is null` en el hilo `"0"`;
   `_calledBack` ya está a `true`, así que el hilo de timeout tampoco informa y
   ese servidor se queda en el estado 4 (CONNECTING) para siempre. Con la
   latencia de Internet de 1998-2004 no se daba. Medido en este Mac cargado:
   4 veces en ~27 conexiones TCP (14 arranques de cliente). `run-whirl-duo.sh` lo detecta y reintenta el
   cliente (hasta 3 veces) contando los casos. **No se ha parcheado el
   cliente** (ver informe: decisión del coordinador).
2. **Intro en los `TextField` no llega al código 1.0 en el JDK 25 de macOS.**
   Al crear el peer se le añade al `TextField` un `InputMethodListener`, lo que
   pone `Component.newEventsOnly = true`, y `Component.dispatchEventImpl` deja
   de convertir los eventos al modelo 1.0 (`handleEvent`/`action`/`keyDown`)
   que usa todo el cliente. Medido con un `TextField` suelto: `newEventsOnly`
   `false` recién creado, `true` tras `addNotify`, 1 `InputMethodListener`; ni
   un `ActionEvent` ni un `KEY_PRESSED` llegan a `handleEvent`. Un `Button` sí
   funciona. Consecuencia: **una persona no puede enviar chat con Intro** bajo
   el puente (tampoco Intro en la contraseña del LoginWizard, Esc para borrar
   la línea ni Ctrl+letra para animar). El arnés entrega a mano el `Event` 1.0
   equivalente; el arreglo para personas es de la UI (H5).
3. **`Console.encrypt`/`decrypt` (nativos sin traducir).** El login no depende
   de ellos si no hay contraseña guardada (`Password0` vacío →
   `Console.decode` no llama a `decrypt`) y "Remember password" está
   desmarcado (`LoginWizard.setConnected` → `Console.encode(null)` devuelve ""
   sin llamar a `encrypt`). Con la casilla marcada, `encode` llama a `encrypt`,
   el mock devuelve `null` y `setConnected` moriría en
   `encrypt(var0).toCharArray()`.
4. **`www.3dcd.com:6650`** (el `lastError=VarErrorException[#106 ...]` del
   puente sin servidor): es `World.defaultServerURL`; `Console.getServerHost`
   además traduce `209.67.68.214:6650` a ese nombre. Hoy `www.3dcd.com`
   resuelve (76.223.54.146 y 13.248.169.48) pero el 6650 no contesta: a los
   15 s el hilo de timeout de `WSConnecting` pone el error 106
   (`NAK_TIMEOUT`). O sea: sin `FREEWORLDS_SERVER`, el cliente bajo el puente
   intenta conectar con un host de terceros.

## Lo que falta

- Verse entre usuarios reales: necesita que el servidor mande `APPRACTR` o
  `TELEPORT` con ids cortos válidos (≥ 2 y distintos de 253-255) y el nombre
  de usuario como id largo. Es un cambio en whirl (no hecho, regla del
  proyecto) o una prueba contra el servidor real con cuenta.
- Lista de amigos, susurros, cambio de canal: sin probar.
- Frame dump del `Drone`: `fuwn` aparece en `IconViewRoom1a` (la galería),
  no en la sala del piloto, y su avatar (`Vamp.mov`) no está en local.
