# J Worlds Injector

Patches for the 2004 WorldsPlayer client that players tick in the
OpenWorlds launcher ("Patches") and that are built into the game when it
starts. The decompiled source in the repository is never edited: each patch
is a set of unified diffs, applied to a copy and compiled on the player's
machine.

```
injector/
  src/net/openworlds/injector/   Injector (apply + compile + cache), Patch (loading), UnifiedDiff
  patches/<id>/                   the built-in patches: patch.properties + NN-*.diff
  test/                           InjectorCheck: every patch alone and all together, against the bridge
```

## How it works

1. The launcher (`Session`) picks the patches the player ticked, plus
   `tls` when the server is "Encrypted".
2. `Injector.build` reads each touched file from the client's source **as
   the bridge builds it** — the pristine decompiled source with the
   bridge's own patches applied (`editor/.build-gamma/source` after
   `build_gamma.sh`; in a package, `lib/worldsplayer-src.zip`) — and applies
   the patches' diffs in order: patch by patch, and within a patch in file
   name order (`01-…`, `02-…`).
3. It compiles only the touched files with the Java compiler that comes
   with the app (`javax.tools`, `--release 8`, against
   `worldsplayer.jar`), into `<data folder>/injector/<key>/classes`.
4. The game starts with those classes **before** `worldsplayer.jar` on the
   class path, so the patched classes replace the original ones.

The key is a hash of the game jar and the patches' text: the same choice
starts at once the next time, a new version of the game or of a patch
compiles again. The six newest builds are kept.

If a hunk does not fit (another version of the game, or two patches that
change the same lines) or the result does not compile, the game does not
start and the launcher says which patch failed and why.

## Writing a patch

A folder with:

- `patch.properties`:

  ```properties
  name=Walk faster
  category=Movement
  description=The arrow keys (and driving with the mouse) move you 1.8 times faster. Turning stays the same.
  ```

  `category` groups patches in the launcher's window; `description` is what
  players read before ticking it. The folder name is the patch's id.

- one or more `*.diff` files: unified diffs (`diff -u`, or `git diff`)
  against the client's source as the bridge builds it. Paths are relative
  to the source root (`NET/worlds/...`), with or without the `a/` and `b/`
  prefixes. A new file is a diff from `/dev/null`.

Hunks are matched by their content (the context and removed lines): a hunk
whose lines moved a little is still found, nearest to the line number it
names; one whose lines are not there is refused. Code must compile with
`--release 8` (the client's own level).

To make one, build the bridge, copy the file you want to change, edit it
and diff:

```bash
editor/worldsplayer_source_editor-main/build_gamma.sh
cd editor/.build-gamma/source
cp NET/worlds/console/Console.java /tmp/Console.java     # edit /tmp/Console.java
diff -u NET/worlds/console/Console.java /tmp/Console.java \
  | sed '1s|^--- .*|--- a/NET/worlds/console/Console.java|; 2s|^+++ .*|+++ b/NET/worlds/console/Console.java|' \
  > 01-Console.diff
```

Then put the folder in the `patches` folder of the launcher's data folder
("My patches folder" in the Patches window) and it shows up there, marked
"(yours)". A folder with the id of a built-in patch replaces it.

To ship one with OpenWorlds, add it under `injector/patches/` and run
`tools/run-checks.sh`: `InjectorCheck` applies and compiles every patch
alone and all together. `tools/build-dist.sh` packs the folder with the
launcher (and lists it in `index.txt`).

## The built-in patches

| Id | Name | What it changes |
|---|---|---|
| `vip` | VIP | `Console.vip` is always 2 (full VIP): avatar customisation and saved avatars, chat log, voice chat, VIP avatars, rooms and teleports |
| `faster-walk` | Walk faster | ×1.8 on the walking speed of `SmoothDriver` (keys and mouse); turning unchanged |
| `chat-time` | Time in the chat | `[HH:mm] ` before every chat line (`textCmd.displayText`) |
| `no-filter` | No word filter | `FilthFilter` lets everything through |
| `tls` | Encrypted connection | `WSConnecting` opens the world server connection with `SecureConnect`: TLS, trusting only the certificate whose SHA-256 fingerprint the launcher checked with the player (`-Dopenworlds.tls.pin`). Not listed in the window: the "Encrypted connection" tick turns it on |
