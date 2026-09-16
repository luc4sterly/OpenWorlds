# NetProbe — sonda de red con las clases reales del cliente

Ejercita el camino de red REAL del cliente decompilado sin arrancar la UI
ni el main-loop de Gamma. No reimplementa protocolo: cada paso llama a las
clases de `editor/worldsplayer_source_editor-main/source` tal cual.

## Qué prueba (4 pasos, cada fallo se reporta, nada se oculta)

1. DNS via `NET.worlds.network.DNSLookup` (la del cliente, con su
   `gethostbyname` mockeado a `InetAddress` real).
2. Construye la URL de upgrades EXACTO como `NetUpdate.needUpdate`:
   `URL.make(uServer + "upgrades.lst").unalias()` con el `upgradeServer`
   del `worlds.ini` real.
3. HTTP GET con el patrón exacto de `CacheEntry.openURL`:
   `DNSLookup.lookup(java.net.URL)` + `openConnection()`, con timeouts
   explícitos (15s connect / 20s read).
4. TCP al puerto WorldServer (6650) contra la IP resuelta por `DNSLookup`.

## Uso

CWD debe ser una instalación real (para el `worlds.ini`), igual que
`run_mock.sh`. Compilar con `--release 8` (el `source/` no compila con
javac moderno por el `yield()` pelado de `netPacketReader.java:89`):

```
cd assets/WorldsPlayer
javac --release 8 -cp ../../editor/worldsplayer_source_editor-main/out \
  -d /tmp/netprobe ../../tools/net-probe/NetProbe.java
java -cp ".:/tmp/netprobe:../../editor/worldsplayer_source_editor-main/out" NetProbe
```

## Resultado 2026-09-10 (`docs/net-probe-trace.log`)

- DNS OK para ambos via la clase real: `us1.worlds.net` → 172.237.126.108,
  `worlds.worlio.com` → 198.251.80.57.
- El cliente construye `http://us1.worlds.net/3DCDupupgrades.lst` (SIN `/`
  entre `3DCDup` y `upgrades.lst` — concatenación literal en
  `NetUpdate.java:413`, `URL.make` no añade nada). Ese URL da 404
  (el servidor responde, `contentLength=158` del error). Hallazgo real,
  no supuesto: el auto-upgrade del cliente está roto contra la infra
  actual por ese detalle.
- TCP 6650: `us1.worlds.net` → conexión rehusada (es solo host de
  ficheros); `worlds.worlio.com` → CONNECTED. Hay un WorldServer vivo
  alcanzable con el camino DNS del propio cliente.

## Siguiente paso (no hecho)

Hablar protocolo de verdad contra ese servidor (o contra `whirl` local —
requiere toolchain `nightly-2024-06-03`, no instalado; solo hay stable)
usando `WorldServer`/`WSConnecting` reales. Eso exige instanciar
`WorldServer` (acoplado a consola/galaxy), no un socket pelado.

## Handshake real (2026-09-10, `NET/worlds/network/HandshakeProbe.java`)

HECHO después de escribir lo de arriba: subclase de `WorldServer` en el
mismo paquete (constructor trivial, sin UI) que recorre el camino
genuino — `initInstance` + `state_Initializing` + `WSConnecting` +
`setSocket` + `state_XMIT_PROPREQ` + `perFrame` — contra
`worlds.worlio.com:6650`. Una conexión por ejecución, se cierra al
terminar. Requiere X (`Console.<clinit>` crea un Frame AWT) y
`Std.initProductName()` como hace `Gamma.main`; con `netdebug=1216` en
`worlds.ini` el propio `sendNetMsg` vuelca los bytes (trace completo en
`docs/net-handshake-trace.log`):

```
send(PROPREQ 255[worlds.worlio.com:6650]) → bytes 03 ff 0a
recv(PROPUPD 255[...] (#27 ... worlds.worlio.com
  #26 ... worlds.worlio.com:2500
  #25 ... http://files.worlio.com/cgi-bin/
  #15 ... 1 / #3 ... 24 / #1 ... WormMaster))
estado 6 RCV_PROPS → 7 XMIT_SI
```

`#3 = 24` coincide con `_serverProtocolVersion = 24` del cliente.
Tres paredes encontradas y resueltas con evidencia (ver bloque del
markdown maestro): tabla de paquetes exige `initProductName` + X,
`_serverURL` para `sendNetMsg->toString`, y `state_Initializing` para
registrar shortID 255 (sin él, el PROPUPD muere en NPE en
`ObjectMgr.getObject`). Parada honesta en estado 7: lo siguiente
(`XMIT_SI` → `galaxy.addPendingServer`) entra en acoplamiento
galaxy/console.

## Muro en estado 7: `dAssert(false)` REAL verificado en bytecode (2026-09-10)

Al extender el bucle `perFrame` más allá del 7, `state_XMIT_SI()`
lanza `AssertionException` en su primera línea — y NO es un artefacto
del decompilador: `javap -c` sobre el `.class` ORIGINAL de
`assets/worlds.jar` muestra `iconst_0; invokestatic Debug.dAssert(Z)`
como bytecode 0-1 del método (igual en `state_XMIT_AI`). `dAssert`
lanza de verdad (también verificado en bytecode) y la excepción es
unchecked (`extends RuntimeException`), así que mataría el hilo Main →
`Gamma.die()` → `System.exit(0)`.
⚠️ VERIFICAR paradoja abierta: el cliente real de 2004 conectaba, pero
este código dice que el siguiente tick tras `6→7` muere. Pistas:
`WorldServer` solo recibe ticks de `perFrame` si alguien hizo
`incRefCnt` (`Main.register`, `WorldServer.java:169`); el `6→7` lo pone
`propertyUpdate` (lee props `#24/#29`→upgrade URL, `#25`→script server,
`#26/#27`→smtp/mail) y el único `setState(8)` vive tras el assert.
Sin resolver a propósito: saltarlo sería inventar comportamiento.

## Paradoja confirmada de punta a punta (2026-09-10, `handshake7`)

- `javap` sobre `.class` ORIGINALES: `perFrame` case 7 → `state_XMIT_SI`
  (tableswitch verificado), su byte 0-1 es `dAssert(false)` genuino,
  `dAssert` lanza (unchecked), `Main.mainLoop` NO tiene exception table,
  `Gamma.run` SÍ (`catch Throwable` → `die()` → `exit(0)`).
- Experimento en vivo: sonda registrada en `Main` + `Main.mainLoop`
  genuino en un hilo → el hilo MUERE con `AssertionException` en
  `state_XMIT_SI:810 ← perFrame:586 ← mainCallback:1100 ← mainLoop:31`
  (números de línea del decompilado, coinciden). Cadena predicha =
  cadena observada.
- Correlación con el mock RECHAZADA con evidencia: el único
  `AssertionException` de `docs/xvfb-runtime-trace.log` es el de
  `IUnknown.init` (ActiveX de consola), no de `WorldServer` — el exit<1s
  del mock NO es este assert (el mock ni llega a estado 7: mundo local,
  galaxy anónima).
- Lector solo encola (`netPacketReader` → `_msgQ`, nadie más drena que
  `processMsgs` vía `perFrame`); `findOrMake` hace `incRefCnt` (registro
  en `Main`) ya en la CREACIÓN del servidor, antes de conectar.
Queda una incógnita acotada con dos mitades: si el servidor está
registrado desde la creación, el tick en 7 lo mata (2004 contradice);
si no lo está, nada conduce 5→6 (el lector solo encola). Resolverla
exige trazar el flujo real de registro/conducción, no más estática.

## PARADOJA RESUELTA (2026-09-10, continuación): `WorldServer` es
## efectivamente abstracta — el cliente real nunca la instancia a pelo

**Causa raíz encontrada leyendo el código fuente directamente, no
especulando**: `WorldServer.state_XMIT_SI()`/`state_XMIT_AI()` son el
patrón "abstracto por assert" típico de este código de los 90 — métodos
que DEBEN ser sobreescritos por una subclase concreta, marcados con
`Debug.dAssert(false)` como primera línea en vez de una palabra clave
`abstract` de verdad. El cliente real **nunca instancia `WorldServer`
directamente** para una conexión — el harness (`HandshakeProbe`,
`MinimalServerHandler`) sí lo hacía (`extends WorldServer` a pelo), y
esa simplificación del harness era la causa completa de la paradoja,
no un bug del cliente de 2004:

1. `ServerURL(String)` (leído directamente): para una URL normal
   `host:puerto` sin segmento de tipo explícito, `_serverType` queda
   literalmente `"AutoServer"` por defecto.
2. `ServerTracker.findOrMake` instancia por reflexión:
   `Class.forName("NET.worlds.network." + type).newInstance()` — para
   cualquier conexión normal, eso es `new AutoServer()`, nunca
   `new WorldServer()`.
3. `AutoServer.state_XMIT_SI()` (leído directamente, SÍ tiene lógica
   real, no un stub): lee la propiedad `#15` de `_propList` (ya
   presente en el PROPUPD real capturado de `worlds.worlio.com` en
   `docs/net-handshake-trace.log`: `#15 [DBSTORE /POSSESS] 1`),
   detecta el tipo de servidor (1 = `UserServer`), crea la subclase
   concreta (`var1 = new UserServer()`), le transfiere la conexión viva
   (`reuseConnection`) y la re-alimenta con las mismas props
   (`propertyUpdate`) — y SOLO ENTONCES pone su propio estado a 17
   (terminado: ya se especializó y entregó el testigo). Nunca toca el
   `dAssert`.

**Verificado en vivo, no solo leído**: `NET/worlds/network/
AutoServerProbe.java` (nueva sonda, misma disciplina que
`HandshakeProbe` pero `extends AutoServer` en vez de `extends
WorldServer`) conecta contra `worlds.worlio.com:6650` de verdad y
atraviesa el estado 7 **sin ninguna `AssertionException`**:

```
state -> 6 RCV_PROPS
state -> 7 XMIT_SI
DEBUG -- a server tried to murder another!          <- benigno, ver abajo
...
LWDB: brought up LoginWizard0 in setGalaxyType       <- código real de login, más allá de 7
state -> 17 DISCONNECTED
final state=17 DISCONNECTED serverType(from prop #15)=1
```
(trace completo en `docs/net-autoserver-trace.log`). `serverType=1`
coincide exacto con la predicción de `#15="1"` leída en el código antes
de correr nada. El mensaje "a server tried to murder another" es un log
de sanidad benigno de `ServerTracker.killServer` (leído en su fuente:
solo imprime, no lanza) — dispara aquí porque esta sonda, a diferencia
del cliente real, nunca se registró en `_serverHash` vía `findOrMake`;
es un artefacto de la simplificación del harness, no del cliente real,
y no afecta a la ejecución (sigue limpio hasta el estado 17).

**Conclusión**: el `dAssert(false)` es real y el análisis bytecode
anterior era correcto — pero es genuinamente inalcanzable en el
cliente real de 2004, tal y como está diseñado: cualquier conexión
normal pasa por `AutoServer` (o la subclase concreta que `findOrMake`
resuelva), nunca por `WorldServer` a pelo. `MinimalServerHandler` sigue
siendo útil como intercepción explícita cuando se quiere forzar el
camino base sin la danza de auto-detección, pero ya no hace falta como
"parche" para un bug real — el camino real (`AutoServer`) simplemente
funciona, verificado en vivo contra el servidor de producción.

## LOGIN COMPLETO contra el guest real (2026-09-10, `NET/worlds/network/GuestLoginProbe.java`, trace `docs/net-guest-login-trace.log`)

La sonda sigue el handoff genuino de `AutoServer` y después conduce la
subclase viva con `perFrame()` real, con el `setAuthInfo` exacto que el
`LoginWizard` hace al pulsar Sign-In (nick por argv, sin UI). Objetivo:
`gippsland.worlio.com:8265`, el servidor anónimo de Worlio (según
https://worlds.worlio.com/ "requires no registration, only a valid
nickname" — el único sitio donde un login real es posible sin cuenta).
Una conexión por ejecución, se cierra al terminar. Xvfb :99, CWD
`assets/WorldsPlayer`, `netdebug=1260` vía reflexión (solo harness).

Resultado: **login completo, estado 12 MAINLOOP estable 12s,
`lastError=null`, cierre limpio**, con este intercambio real:

```
send(PROPREQ 255[...]) → bytes 03 ff 0a
recv(PROPUPD ... (#8 1000000 / #25 http://files.worlio.com/cgi-bin/
  #24 http://files.worlio.com/ / #15 4 / #3 24 / #1 Gippsland))
  → AutoServer detecta tipo 4 → crea AnonRoomServer (predicción exacta),
    reuseConnection + swapServer + setGalaxyType (levanta LoginWizard0)
send(SESSINIT (VAR_PROTOCOL=24 VAR_CLIENT=2004080500 VAR_AVATARS=24
  VAR_USERNAME=FWProbeGuest2))
  → bytes 25 1 6 3 2 32 34 9 a 32 30 30 34 30 38 30 35 30 30 ... (ver trace)
recv(SESSINIT (VAR_ERROR=0 VAR_SERVERTYPE=4 VAR_UPDATETIME=1000000
  VAR_PROTOCOL=24 VAR_CHANNEL=dimension-1))
  → estado 8→11→12 + wizard.setConnected() real
recv(TEXT Gippsland: Welcome to WorlioWorlds Gippsland, an anonymous
  free-for-all. Be wary of links, impersonation, and spam. Keep your
  mute buttons greased.)
```

Dos obstáculos encontrados y resueltos con evidencia, sin inventar nada:

1. `VAR_CLIENT=null` → el servidor responde `SESSINIT (VAR_ERROR=7
   "Sorry, your client software is out of date...")` (verificado 2
   veces en vivo). Causa raíz: el mock JNI devuelve null en
   `Std.getClientVersion()`; el gamma.dll REAL de nuestra instalación
   (`assets/WorldsPlayer/bin/gamma.dll`, build 08/05/04 Rev 1900)
   devuelve el literal `"2004080500"` (formato AAAAMMDDHH de la fecha
   de build). Verificado offline: la exportación
   `_Java_NET_worlds_core_Std_getClientVersion@8` (RVA 0x2ff0) hace
   `NewStringUTF(env, 0x46d428)` y en esa dirección está `2004080500`
   (mismo método confirma `getBuildInfo` → `"08/05/04 05:45:33 GMT (Rev
   1900)"`, idéntico al `Gamma.Log` genuino — validación cruzada).
   Con el valor real, `VAR_ERROR=0`. La sonda lo inyecta en el campo
   `protected _clientVersion` (mismo paquete, solo harness, argv 5º).
2. `NPE` en `LoginWizard.setConnected` (`setIniString("User0", null)`
   — el mock usa Hashtable): ARTEFACTO del harness, no bug del
   cliente — al saltarse la UI, `loginUserName` quedaba null; en el
   flujo real nunca es null (lo exige `validateKnownUserInfo` antes de
   `doLogin`). La sonda lo deja como lo dejaría la UI (reflexión solo
   en el harness) y el login cierra limpio.

## Servidor primario: hace falta cuenta registrada a mano (2026-09-10)

`worlds.worlio.com:6650` anuncia `#15=1` (UserServer, ver
`docs/net-handshake-trace.log`): el `sessionInit` exige modo 1
(REGISTER: usuario+password+serial de la web) o 2 (AUTHENTICATE:
usuario+password). El registro es un formulario web en
https://worlds.worlio.com/register (verificado accesible; pide email)
y la entrada en https://worlds.worlio.com/ lo confirma. **Sin una
cuenta creada manualmente ahí no se puede pasar del sessionInit en el
primario, y esta línea NO inventa ni hardcodea credenciales**:
`GuestLoginProbe` acepta nick+password SOLO por argv (3º/4º) para usar
con una cuenta propia cuando exista. Los tres hostnames
(`worlds.worlio.com`, `worlio.com`, `gippsland.worlio.com`) resuelven
a la misma IP (198.251.80.57).

## macOS (2026-09-16): scripts reproducibles y primera pared de `Gamma.main`

Reproducido en un MacBook Intel sin Xvfb (AWT nativo con Cocoa), con el
JDK de `tools/jdk`. Todo se construye en un directorio temporal: ni
`source/` ni `assets/WorldsPlayer/` se modifican.

- **`tools/net-probe/run-guest-login.sh`** aplica el mock sobre una copia
  del Java pristino, compila mock + sondas y ejecuta `GuestLoginProbe`
  desde una copia de `assets/WorldsPlayer`. Contra
  `gippsland.worlio.com:8265`: **estado 12 MAINLOOP estable 12 s,
  `lastError=null`, exit 0**, con el intercambio real
  PROPREQ → PROPUPD → SESSINIT y el texto de bienvenida (3 ejecuciones,
  mismo resultado que en Linux el 2026-09-10). Trace:
  `docs/net-guest-login-trace-macos.log`.
- **`tools/net-probe/run-gamma-main.sh`** arranca el flujo REAL
  `NET.worlds.console.Gamma` con el mock (timeout duro + `jstack`). Carga
  bien mock, caché, tablas, avatar y sala; al montar la escena salta un
  `Debug.dAssert(false)` genuino en `IUnknown.init`: el control
  ActiveX/Netscape embebido, que no tiene equivalente fuera de Windows.
  **No es un valor de mock corregible sino la ausencia de COM**: pared
  estructural. El cliente lo captura con su propio try/catch y termina
  solo (exit 0, 5-8 s). Trace: `docs/net-gamma-main-trace-macos.log`.
- **Hilos `Cache`/`NetUpdate`**: `CacheEntry` ("File Downloader N"),
  `NetUpdate` y `BackgroundLoader` corren en macOS sin bloqueos. El único
  bloqueo observado es de diseño (`URLSelfLoader.syncBackgroundLoad` es
  síncrono a propósito) y el proceso depende de un `Thread.join()` sin
  timeout en `Gamma.main:221`; nada específico de macOS. Evidencia:
  `docs/net-gamma-cache-netupdate-jstack-macos.txt`.
- **Cuenta real**: requisitos exactos (registro web con email, modo 2
  AUTHENTICATE de `LoginWizard.validateKnownUserInfo`, cómo pasar nick y
  contraseña por argv al script) en
  `docs/net-real-account-login-requisitos.md`. Sin ejecutar: no hay cuenta
  ni se inventan credenciales.
