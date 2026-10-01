# Network on this machine: the original client against J Solar Server

Two **original** clients (the 2004 Java client under the portable bridge,
`editor/worldsplayer_source_editor-main/bridge/`) against J Solar Server
(`server/`), the project's own world server, on one machine. Measured on
2026-09-29/30 (JDK 21, Linux, Xvfb), with the launcher and with the
`SolarBot` test walker.

![Two original clients seeing each other on J Solar Server](renders/solar-two-clients.png)

## Result

| What | State | Evidence |
|---|---|---|
| The client connects to a server on this machine | ✅ | the client's own mechanism: `override.ini` `[Runtime] WorldServer=` (the launcher writes it) |
| Handshake (AutoServer) | ✅ | `PROPREQ` → `PROPUPD #15=1` → `AutoServer detected server type 1` → `UserServer` |
| Sign-in with an account (LoginWizard → SESSINIT) | ✅ | a new name with any password makes the account when sign-up is open; a wrong password is NAK 13 |
| Rooms: ROOMIDRQ → ROOMID on the same connection | ✅ | no REDIRID to other servers: one port does it all |
| Two clients see each other and walk | ✅ | `APPRACTR`/`TELEPORT` with a short id from `REGOBJID`, then `LONGLOC` |
| Chat between them | ✅ | `TEXT` to whoever is in earshot (same room, or a room either one sees) |
| Whispers, friends list (online/offline) | ✅ | `WHISPER` by name; `BUDDYLISTUPDATE` → `BUDDYLISTNOTIFY` |
| Encrypted connection (TLS) | ✅ | port 6651; the client with the injector's "tls" patch: `[tls] encrypted connection to 127.0.0.1:6651 (TLSv1.3, TLS_AES_256_GCM_SHA384)` |
| Upgrade Now and restart while signed in | ✅ | GroundZero 37 → 40, `[gdkup] restart: world:restart`; the client connects again, its sign-in filled in |

## How to run it

```bash
# the server, with its window (or --headless for a console; --tls also opens 6651)
build/dist/JSolarServer/JSolarServer.sh            # after tools/build-dist.sh
java -jar build/dist/JSolarServer/lib/j-solar-server.jar --headless --tls

# a client: the launcher, "Online", address 127.0.0.1 (6650; 6651 if "Encrypted")
build/dist/OpenWorlds/OpenWorlds.sh
# or straight to the game
OpenWorlds --original --server 127.0.0.1 --user Alice --password secret [--encrypted --trust]

# a second avatar without a second game: a scripted walker that chats
java -cp <server test classes> net.openworlds.solar.SolarBot --name Bob --password secret \
   --room "GroundZero#IconViewRoom1Enter" --say "hello" --seconds 60
```

`server/test/net/openworlds/solar/SolarProtocolCheck.java` checks the whole
exchange without a game: sign-in, rooms, seeing each other, movement, chat,
whispers, friends, kicks and bans, guests, TLS (`tools/run-checks.sh` runs
it).

## The protocol as the client needs it

What the 2004 client expects, read in its own code (`NET.worlds.network`)
and the LibreWorlds wiki (`protocol/LibreWorlds-wiki-master/`). Each point
is a rule J Solar Server follows; the third-party server used before
(whirl, see below) broke several of them, which is why nobody could see
anybody.

1. **Server type 1** (`USER_SERVER_DB`) in the properties (`PROPUPD #15`):
   the client asks for a name and password (`UserServer`, AUTHENTICATE),
   as with the real primary server (`docs/net-handshake-trace.log`).
2. **Avatars appear only with `APPRACTR`, or a `TELEPORT` of an object the
   client does not know** (`appearActorCmd.process` / `teleportCmd.process`
   → `Drone.make`). `LONGLOC` only moves a `Drone` that already exists.
   J Solar Server sends `APPRACTR` to a client that subscribes to a room
   where someone already is, and `TELEPORT` (exit/entry types) when someone
   arrives; `TELEPORT` to room 0 or `DISAPPR` takes them away.
3. **Short ids are 2..127, per viewer.** `REGOBJID` gives a player a short
   id in each client; 1 is `CLIENT` (the client itself: `regShortID(1,
   name)`), 253-255 are the current room, CO and PO, and `regObjIDCmd`
   reads the id as a *signed* byte, so ids above 127 come out negative. The
   long id is the user name (the client shows it), not a derived string.
4. **Movement is relayed with the mover's id as each viewer knows it**,
   never with the sender's own objId (1 = `CLIENT`, which every receiver
   would take for itself).
5. **Room numbers are never 0**: `Galaxy.regRoomID` ignores 0 ("no id")
   and asks again. Numbers are global, so two clients agree on them.
6. **Chat is local**: a line reaches whoever is in the same room or in a
   room either one is subscribed to (rooms open onto each other). The
   sender is named by the server (the client sends an empty name).
7. **`VAR_UPDATETIME` is in microseconds** (the client divides by 1000): it
   is the time a `Drone` takes to glide to a reported position; the pilot
   reports about every 0.5 s.
8. The 2004 properties that pointed at Worlds.com's web scripts
   (`#24`/`#25`: `www-static`/`www-dynamic.us.worlds.net`) are still
   announced: the client builds URLs with them (VIP avatar lists, sign-up,
   ads); those hosts no longer exist and the client logs a download error
   and carries on.

## Findings on the client side

1. **A race in `WorldServer`/`WSConnecting`** (checked in the bytecode of
   `assets/worlds.jar` with `javap`): `WSConnecting`'s constructor starts
   the connection threads (`makeThread(-1)` and `makeThread(0..)`, bytes
   41-43 and 104-107) before it returns, and
   `WorldServer.state_Initializing` stores `_connectThread` **afterwards**
   (bytes 421-433). `setSocket`, called by the connection thread, starts
   with `getfield _connectThread; invokevirtual getBackupHosts` (bytes 0-4)
   without synchronization. With a server on the same machine the TCP
   connection finishes before the store: `NullPointerException ...
   "this._connectThread" is null` in thread `"0"`, `_calledBack` is already
   `true` so the timeout thread does not report either, and that server
   stays in state 4 (CONNECTING) forever. With 1998-2004 Internet latency it
   never happened. Measured: 4 times in ~27 TCP connections. **Fixed in the
   bridge** (`natives-java.patch`): `setSocket` first takes `this._state`'s
   lock, which `state_Initializing` holds until it has stored the thread.
2. **Enter in `TextField`s did not reach the 1.0 event code** on modern
   JDKs: the peer adds an `InputMethodListener`, which sets
   `Component.newEventsOnly = true`, and `Component.dispatchEventImpl` stops
   turning events into the 1.0 model (`handleEvent`/`action`/`keyDown`)
   that the whole client uses. Fixed in the bridge (chat with Enter works).
3. **`Console.encrypt`/`decrypt`** (the remembered password): translated
   from gamma.dll (`NativeUiConsole`, 0x0040b7f0); the launcher uses the same
   code to fill in the game's sign-in (`Login.java`).
4. **`www.3dcd.com:6650`** is `World.defaultServerURL`: without a world
   server, the client tries that third-party host and gives up after 15 s
   (error 106, `NAK_TIMEOUT`). The launcher's "Single player" starts the
   client with `-Dopenworlds.singleUser=true` (`natives-launcher.patch`), so
   it does not try.

## History: whirl

Until 2026-09-30 the project tested against **whirl** (Whirlsplash), a
third-party server in Rust vendored in `server/whirl`, compiled without
changes. With it, two original clients could sign in, share a room and
chat, but never saw each other: whirl's hub answered a `TELEPORT` by
registering a new object and broadcasting only `REGOBJID` (its `APPRACTR`
was built and commented out), numbered short ids from 0 (so the second
player got 1, `CLIENT`, the receiver's own id), used `"name (n)"` as the
long id, relayed `LONGLOC` with the sender's objId 1, numbered rooms per
connection from 0, did not answer `ROOMIDRQ` on the hub, and sent chat to
every peer in every room. Its Rust dependencies also carried a long list of
security advisories. J Solar Server replaced it (written from the client's
protocol code, with the rules above), and whirl was removed from the
repository; the details of those measurements are in the git history of
this file (`docs/net-local-whirl.md`).
