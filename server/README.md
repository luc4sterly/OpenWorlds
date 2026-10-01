# J Solar Server

A world server for the 2004 WorldsPlayer client, in Java, so OpenWorlds
players meet in the same worlds. Written from the client's own protocol
code (`NET.worlds.network` in the decompiled source) and the LibreWorlds
wiki (`protocol/LibreWorlds-wiki-master/`). The protocol rules it follows,
and why, are in [`docs/net-local-server.md`](../docs/net-local-server.md);
the player-facing guide is [`tools/dist-README-server.txt`](../tools/dist-README-server.txt).

```
server/
  src/net/openworlds/solar/
    SolarServer.java   the engine: sign-in, rooms, who sees whom, chat, whispers, friends, admin actions
    Client.java        one connection: reader and writer threads, per-viewer short ids, flood control
    Packet.java        the wire format: [length][ObjID][command][data], modified UTF-8 strings
    Props.java         property lists (the old and the new form), NAK codes, privilege bits
    Accounts.java      accounts.tsv: PBKDF2 passwords, VIP/admin/banned, friends
    Config.java        server.properties
    Tls.java           the encrypted port: a self-signed EC certificate, made the first time
    AdminWindow.java   the admin window (the launcher's look, in violet)
    Main.java          command line: the window, or --headless with a console
  resources/           the window's icon
  test/net/openworlds/solar/
    SolarProtocolCheck.java   the whole exchange with scripted clients, no game needed (tools/run-checks.sh)
    SolarBot.java             a scripted player that walks and talks, to try the game against
```

It shares the look of the launcher through `ui/` (`Theme.use(Palette.SOLAR)`).

## Running it

```bash
tools/build-dist.sh                                   # build/dist/JSolarServer, and the portable .zip
build/dist/JSolarServer/JSolarServer.sh               # the admin window
build/dist/JSolarServer/JSolarServer.sh --headless    # a console instead (type help)
```

| Option | |
|---|---|
| `--headless` | no window: the log on the terminal and a command console (`status`, `who`, `accounts`, `say`, `kick`, `ban`/`unban`, `vip`/`unvip`, `admin`/`unadmin`, `adduser`, `passwd`, `deluser`, `fingerprint`, `stop`) |
| `--data DIR` | the data folder (default: the system's application data folder, "J Solar Server"; or `JSOLAR_DATA`) |
| `--port N` | the normal port (default 6650) |
| `--tls`, `--tls-port N` | also accept encrypted connections, on port 6651 by default |
| `--no-tls`, `--no-plain` | turn the encrypted or the normal port off |
| `--add-user NAME PASSWORD [--vip] [--admin]` | create an account and exit |
| `--fingerprint` | print the certificate's SHA-256 fingerprint (what players compare) and exit |

The data folder holds `server.properties` (`server.name`, `welcome`,
`port`, `plain.enabled`, `tls.enabled`, `tls.port`, `signup.open`,
`guests.allowed`, `max.users`, `autostart`...), `accounts.tsv`, the
certificate (`tls/server.p12`) and the logs. The admin window edits all of
it.

## Trying it with the game

```bash
build/dist/OpenWorlds/OpenWorlds.sh --original --server 127.0.0.1 --user Alice --password secret
# encrypted: --server 127.0.0.1 --encrypted --trust (the first time, --trust accepts the certificate)
```

or the launcher's window: "Online", address `127.0.0.1`. A second player
without a second game: `SolarBot` (`--name`, `--password`, `--room`, `--x`,
`--y`, `--radius`, `--avatar`, `--say`, `--seconds`), run from the server's
test classes.
