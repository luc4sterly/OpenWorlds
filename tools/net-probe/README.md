# NetProbe — network probe with the client's real classes

Exercises the REAL network path of the decompiled client without starting the UI
or Gamma's main loop. It does not reimplement the protocol: each step calls the
classes of `editor/worldsplayer_source_editor-main/source` as they are.

## What it tests (4 steps, every failure is reported, nothing is hidden)

1. DNS via `NET.worlds.network.DNSLookup` (the client's own, with its
   `gethostbyname` mocked to a real `InetAddress`).
2. Builds the upgrades URL EXACTLY as `NetUpdate.needUpdate` does:
   `URL.make(uServer + "upgrades.lst").unalias()` with the `upgradeServer`
   from the real `worlds.ini`.
3. HTTP GET with the exact pattern of `CacheEntry.openURL`:
   `DNSLookup.lookup(java.net.URL)` + `openConnection()`, with explicit
   timeouts (15s connect / 20s read).
4. TCP to the WorldServer port (6650) against the IP resolved by `DNSLookup`.

## Usage

The CWD must be a real installation (for the `worlds.ini`), just like
`run_mock.sh`. Compile with `--release 8` (`source/` does not compile with
modern javac because of the bare `yield()` in `netPacketReader.java:89`):

```
cd assets/WorldsPlayer
javac --release 8 -cp ../../editor/worldsplayer_source_editor-main/out \
  -d /tmp/netprobe ../../tools/net-probe/NetProbe.java
java -cp ".:/tmp/netprobe:../../editor/worldsplayer_source_editor-main/out" NetProbe
```

## Result 2026-09-10 (`docs/net-probe-trace.log`)

- DNS OK for both via the real class: `us1.worlds.net` → 172.237.126.108,
  `worlds.worlio.com` → 198.251.80.57.
- The client builds `http://us1.worlds.net/3DCDupupgrades.lst` (WITHOUT a `/`
  between `3DCDup` and `upgrades.lst` — literal concatenation in
  `NetUpdate.java:413`, `URL.make` adds nothing). That URL gives a 404
  (the server responds, `contentLength=158` for the error). A real finding,
  not an assumption: the client's auto-upgrade is broken against the current
  infrastructure because of that detail.
- TCP 6650: `us1.worlds.net` → connection refused (it is only a file
  host); `worlds.worlio.com` → CONNECTED. There is a live WorldServer
  reachable through the client's own DNS path.

## Next step (not done)

Speak the protocol for real against that server (or against a local `whirl` —
it requires the `nightly-2024-06-03` toolchain, not installed; only stable is there)
using the real `WorldServer`/`WSConnecting`. That requires instantiating
`WorldServer` (coupled to console/galaxy), not a bare socket.

## Real handshake (2026-09-10, `NET/worlds/network/HandshakeProbe.java`)

DONE after writing the above: a subclass of `WorldServer` in the
same package (trivial constructor, no UI) that walks the
genuine path — `initInstance` + `state_Initializing` + `WSConnecting` +
`setSocket` + `state_XMIT_PROPREQ` + `perFrame` — against
`worlds.worlio.com:6650`. One connection per run, closed at the
end. It requires X (`Console.<clinit>` creates an AWT Frame) and
`Std.initProductName()` as `Gamma.main` does; with `netdebug=1216` in
`worlds.ini`, `sendNetMsg` itself dumps the bytes (full trace in
`docs/net-handshake-trace.log`):

```
send(PROPREQ 255[worlds.worlio.com:6650]) → bytes 03 ff 0a
recv(PROPUPD 255[...] (#27 ... worlds.worlio.com
  #26 ... worlds.worlio.com:2500
  #25 ... http://files.worlio.com/cgi-bin/
  #15 ... 1 / #3 ... 24 / #1 ... WormMaster))
state 6 RCV_PROPS → 7 XMIT_SI
```

`#3 = 24` matches the client's `_serverProtocolVersion = 24`.
Three walls found and resolved with evidence (see the block in the
master markdown): the packet table requires `initProductName` + X,
`_serverURL` for `sendNetMsg->toString`, and `state_Initializing` to
register shortID 255 (without it, the PROPUPD dies with an NPE in
`ObjectMgr.getObject`). An honest stop at state 7: what comes next
(`XMIT_SI` → `galaxy.addPendingServer`) runs into the galaxy/console
coupling.

## Wall at state 7: a REAL `dAssert(false)` verified in bytecode (2026-09-10)

When the `perFrame` loop is extended beyond 7, `state_XMIT_SI()`
throws `AssertionException` on its first line — and it is NOT an artifact
of the decompiler: `javap -c` on the ORIGINAL `.class` from
`assets/worlds.jar` shows `iconst_0; invokestatic Debug.dAssert(Z)`
as bytecode 0-1 of the method (the same in `state_XMIT_AI`). `dAssert`
really throws (also verified in bytecode) and the exception is
unchecked (`extends RuntimeException`), so it would kill the Main thread →
`Gamma.die()` → `System.exit(0)`.
⚠️ VERIFY open paradox: the real 2004 client did connect, but
this code says that the next tick after `6→7` dies. Clues:
`WorldServer` only receives ticks from `perFrame` if someone called
`incRefCnt` (`Main.register`, `WorldServer.java:169`); the `6→7` is set by
`propertyUpdate` (reads props `#24/#29`→upgrade URL, `#25`→script server,
`#26/#27`→smtp/mail) and the only `setState(8)` lives after the assert.
Left unresolved on purpose: skipping it would be inventing behavior.

## Paradox confirmed end to end (2026-09-10, `handshake7`)

- `javap` on the ORIGINAL `.class` files: `perFrame` case 7 → `state_XMIT_SI`
  (tableswitch verified), its byte 0-1 is a genuine `dAssert(false)`,
  `dAssert` throws (unchecked), `Main.mainLoop` has NO exception table,
  `Gamma.run` DOES (`catch Throwable` → `die()` → `exit(0)`).
- Live experiment: probe registered in `Main` + the genuine `Main.mainLoop`
  in a thread → the thread DIES with `AssertionException` in
  `state_XMIT_SI:810 ← perFrame:586 ← mainCallback:1100 ← mainLoop:31`
  (line numbers from the decompiled code, they match). Predicted chain =
  observed chain.
- Correlation with the mock REJECTED with evidence: the only
  `AssertionException` in `docs/xvfb-runtime-trace.log` is the one in
  `IUnknown.init` (the console's ActiveX), not in `WorldServer` — the mock's exit<1s
  is NOT this assert (the mock does not even reach state 7: local world,
  anonymous galaxy).
- The reader only enqueues (`netPacketReader` → `_msgQ`, drained by nothing but
  `processMsgs` via `perFrame`); `findOrMake` calls `incRefCnt` (registration
  in `Main`) already at the CREATION of the server, before connecting.
One bounded unknown remains, with two halves: if the server is
registered from creation, the tick at 7 kills it (2004 says otherwise);
if it is not, nothing drives 5→6 (the reader only enqueues). Resolving it
requires tracing the real registration/driving flow, not more static analysis.

## PARADOX RESOLVED (2026-09-10, continued): `WorldServer` is
## effectively abstract — the real client never instantiates it bare

**Root cause found by reading the source code directly, not by
speculating**: `WorldServer.state_XMIT_SI()`/`state_XMIT_AI()` are the
"abstract by assert" pattern typical of this 90s code — methods
that MUST be overridden by a concrete subclass, marked with
`Debug.dAssert(false)` as their first line instead of a real
`abstract` keyword. The real client **never instantiates `WorldServer`
directly** for a connection — the harness (`HandshakeProbe`,
`MinimalServerHandler`) did (bare `extends WorldServer`), and
that simplification in the harness was the whole cause of the paradox,
not a bug in the 2004 client:

1. `ServerURL(String)` (read directly): for a normal
   `host:port` URL without an explicit type segment, `_serverType` is
   literally `"AutoServer"` by default.
2. `ServerTracker.findOrMake` instantiates by reflection:
   `Class.forName("NET.worlds.network." + type).newInstance()` — for
   any normal connection, that is `new AutoServer()`, never
   `new WorldServer()`.
3. `AutoServer.state_XMIT_SI()` (read directly, it DOES have real
   logic, not a stub): reads property `#15` from `_propList` (already
   present in the real PROPUPD captured from `worlds.worlio.com` in
   `docs/net-handshake-trace.log`: `#15 [DBSTORE /POSSESS] 1`),
   detects the server type (1 = `UserServer`), creates the concrete
   subclass (`var1 = new UserServer()`), hands the live connection over to it
   (`reuseConnection`) and feeds it the same props again
   (`propertyUpdate`) — and ONLY THEN sets its own state to 17
   (finished: it has already specialized and passed the baton). It never touches the
   `dAssert`.

**Verified live, not just read**: `NET/worlds/network/
AutoServerProbe.java` (a new probe, same discipline as
`HandshakeProbe` but `extends AutoServer` instead of `extends
WorldServer`) really connects to `worlds.worlio.com:6650` and
goes through state 7 **without any `AssertionException`**:

```
state -> 6 RCV_PROPS
state -> 7 XMIT_SI
DEBUG -- a server tried to murder another!          <- benign, see below
...
LWDB: brought up LoginWizard0 in setGalaxyType       <- real login code, past 7
state -> 17 DISCONNECTED
final state=17 DISCONNECTED serverType(from prop #15)=1
```
(full trace in `docs/net-autoserver-trace.log`). `serverType=1`
matches exactly the prediction of `#15="1"` read in the code before
running anything. The message "a server tried to murder another" is a benign
sanity log from `ServerTracker.killServer` (read in its source:
it only prints, it does not throw) — it fires here because this probe, unlike
the real client, never registered in `_serverHash` via `findOrMake`;
it is an artifact of the harness simplification, not of the real client,
and it does not affect execution (it continues cleanly up to state 17).

**Conclusion**: the `dAssert(false)` is real and the earlier bytecode analysis
was correct — but it is genuinely unreachable in the
real 2004 client, as designed: any normal
connection goes through `AutoServer` (or the concrete subclass that `findOrMake`
resolves), never through a bare `WorldServer`. `MinimalServerHandler` is still
useful as an explicit interception when one wants to force the
base path without the auto-detection dance, but it is no longer needed as a
"patch" for a real bug — the real path (`AutoServer`) simply
works, verified live against the production server.

## FULL LOGIN against the real guest server (2026-09-10, `NET/worlds/network/GuestLoginProbe.java`, trace `docs/net-guest-login-trace.log`)

The probe follows the genuine `AutoServer` handoff and then drives the
live subclass with the real `perFrame()`, with the exact `setAuthInfo` that
`LoginWizard` makes when Sign-In is pressed (nick via argv, no UI). Target:
`gippsland.worlio.com:8265`, Worlio's anonymous server (according to
https://worlds.worlio.com/ it "requires no registration, only a valid
nickname" — the only place where a real login is possible without an account).
One connection per run, closed at the end. Xvfb :99, CWD
`assets/WorldsPlayer`, `netdebug=1260` via reflection (harness only).

Result: **full login, state 12 MAINLOOP stable for 12s,
`lastError=null`, clean shutdown**, with this real exchange:

```
send(PROPREQ 255[...]) → bytes 03 ff 0a
recv(PROPUPD ... (#8 1000000 / #25 http://files.worlio.com/cgi-bin/
  #24 http://files.worlio.com/ / #15 4 / #3 24 / #1 Gippsland))
  → AutoServer detects type 4 → creates AnonRoomServer (exact prediction),
    reuseConnection + swapServer + setGalaxyType (brings up LoginWizard0)
send(SESSINIT (VAR_PROTOCOL=24 VAR_CLIENT=2004080500 VAR_AVATARS=24
  VAR_USERNAME=FWProbeGuest2))
  → bytes 25 1 6 3 2 32 34 9 a 32 30 30 34 30 38 30 35 30 30 ... (see trace)
recv(SESSINIT (VAR_ERROR=0 VAR_SERVERTYPE=4 VAR_UPDATETIME=1000000
  VAR_PROTOCOL=24 VAR_CHANNEL=dimension-1))
  → state 8→11→12 + real wizard.setConnected()
recv(TEXT Gippsland: Welcome to WorlioWorlds Gippsland, an anonymous
  free-for-all. Be wary of links, impersonation, and spam. Keep your
  mute buttons greased.)
```

Two obstacles found and resolved with evidence, without inventing anything:

1. `VAR_CLIENT=null` → the server answers `SESSINIT (VAR_ERROR=7
   "Sorry, your client software is out of date...")` (verified live
   2 times). Root cause: the JNI mock returns null from
   `Std.getClientVersion()`; the REAL gamma.dll of our installation
   (`assets/WorldsPlayer/bin/gamma.dll`, build 08/05/04 Rev 1900)
   returns the literal `"2004080500"` (YYYYMMDDHH format of the build
   date). Verified offline: the export
   `_Java_NET_worlds_core_Std_getClientVersion@8` (RVA 0x2ff0) does
   `NewStringUTF(env, 0x46d428)` and at that address there is `2004080500`
   (the same method confirms `getBuildInfo` → `"08/05/04 05:45:33 GMT (Rev
   1900)"`, identical to the genuine `Gamma.Log` — a cross-validation).
   With the real value, `VAR_ERROR=0`. The probe injects it into the
   `protected _clientVersion` field (same package, harness only, 5th argv).
2. `NPE` in `LoginWizard.setConnected` (`setIniString("User0", null)`
   — the mock uses a Hashtable): an ARTIFACT of the harness, not a bug in the
   client — since the UI was skipped, `loginUserName` was left null; in the
   real flow it is never null (`validateKnownUserInfo` requires it before
   `doLogin`). The probe sets it as the UI would (reflection only
   in the harness) and the login finishes cleanly.

## Primary server: an account registered by hand is needed (2026-09-10)

`worlds.worlio.com:6650` announces `#15=1` (UserServer, see
`docs/net-handshake-trace.log`): the `sessionInit` requires mode 1
(REGISTER: user+password+serial from the website) or 2 (AUTHENTICATE:
user+password). Registration is a web form at
https://worlds.worlio.com/register (verified reachable; it asks for an email)
and the front page at https://worlds.worlio.com/ confirms it. **Without an
account created by hand there, the sessionInit on the primary cannot be
passed, and this line of work does NOT invent or hardcode credentials**:
`GuestLoginProbe` accepts nick+password ONLY via argv (3rd/4th), to be used
with one's own account once it exists. The three hostnames
(`worlds.worlio.com`, `worlio.com`, `gippsland.worlio.com`) resolve
to the same IP (198.251.80.57).

## macOS (2026-09-16): reproducible scripts and the first wall of `Gamma.main`

Reproduced on an Intel MacBook without Xvfb (native AWT with Cocoa), with the
JDK in `tools/jdk`. Everything is built in a temporary directory: neither
`source/` nor `assets/WorldsPlayer/` is modified.

- **`tools/net-probe/run-guest-login.sh`** applies the mock to a copy
  of the pristine Java, compiles mock + probes and runs `GuestLoginProbe`
  from a copy of `assets/WorldsPlayer`. Against
  `gippsland.worlio.com:8265`: **state 12 MAINLOOP stable for 12 s,
  `lastError=null`, exit 0**, with the real exchange
  PROPREQ → PROPUPD → SESSINIT and the welcome text (3 runs,
  same result as on Linux on 2026-09-10). Trace:
  `docs/net-guest-login-trace-macos.log`.
- **`tools/net-probe/run-gamma-main.sh`** starts the REAL
  `NET.worlds.console.Gamma` flow with the mock (hard timeout + `jstack`). It loads
  the mock, cache, tables, avatar and room fine; when the scene is built, a
  genuine `Debug.dAssert(false)` fires in `IUnknown.init`: the embedded
  ActiveX/Netscape control, which has no equivalent outside Windows.
  **It is not a mock value that can be fixed but the absence of COM**: a structural
  wall. The client catches it with its own try/catch and exits
  by itself (exit 0, 5-8 s). Trace: `docs/net-gamma-main-trace-macos.log`.
- **`Cache`/`NetUpdate` threads**: `CacheEntry` ("File Downloader N"),
  `NetUpdate` and `BackgroundLoader` run on macOS without hanging. The only
  blocking observed is by design (`URLSelfLoader.syncBackgroundLoad` is
  synchronous on purpose), and the process depends on a `Thread.join()` without
  a timeout in `Gamma.main:221`; nothing macOS-specific. Evidence:
  `docs/net-gamma-cache-netupdate-jstack-macos.txt`.
- **Real account**: exact requirements (web registration with an email, mode 2
  AUTHENTICATE of `LoginWizard.validateKnownUserInfo`, how to pass the nick and
  password via argv to the script) in
  `docs/net-real-account-login.md`. Not executed: there is no account
  and credentials are not invented.
