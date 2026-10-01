OpenWorlds - Worlds Chat / WorldsPlayer, the 3D chat of 1995-2004
==================================================================

What it is
----------
The ORIGINAL 2004 client (WorldsPlayer), decompiled, with its RenderWare
2.1 engine and gamma.dll translated to Java (the "portable bridge"): the
same logic, the same interface (Help, Options, Teleport, the universe
map...) and the same software drawing, without Windows or Wine.

Starting it
-----------
  macOS:   OpenWorlds.app (Java included). It is not signed by Apple, so
           the first time macOS blocks it. On macOS 15 (Sequoia) go to
           System Settings > Privacy & Security > "Open Anyway" after the
           first try; or, in Terminal:
              xattr -dr com.apple.quarantine /path/to/OpenWorlds.app
           (this also fixes the "is damaged" warning).
  Windows: OpenWorlds\OpenWorlds.exe
  Linux:   OpenWorlds/bin/OpenWorlds

  Portable package (no Java included, needs Java 17 or newer):
           OpenWorlds.command (macOS), OpenWorlds.bat (Windows),
           OpenWorlds.sh (Linux)

The launcher opens: pick a world and a server and press "Play". Without a
display, or with --tui, the menu shows in the terminal. Every option:
OpenWorlds --help

Playing
-------
  - Single player (no server): the launcher picks the game's "Single-user
    mode" for you and you go straight in. Walk with the arrow keys; the
    menus are the 2004 ones.
  - Online: type the address of a J Solar Server (the world server that
    comes with OpenWorlds; its window shows the address to give out), your
    name and a password. The first time, any name and password make your
    account there. The game's sign-in comes filled in: press "Sign In".
  - Encrypted connection: tick it when the server has encrypted connections
    on. The first time, the launcher shows the server's certificate
    fingerprint: compare it with the one J Solar Server shows (Settings,
    Connections). OpenWorlds remembers it and warns you if it ever changes.
  - Worlds: the 2004 install only has GroundZero. Pick any other world in
    the list (Avatar Gallery, Worlds Center, Animal House, Hang, Meteor...)
    and Play downloads and installs it first, from us1.worlds.net (today the
    LibreWorlds mirror). Inside the game, the universe map, Teleport and
    the portals offer the others too; the game asks to restart and the
    launcher opens it again by itself. Options > Upgrade Now looks for
    updates of the installed worlds. Without a network, or with "Download
    missing worlds and avatars" off in Settings (--no-mirror), there is
    only what is installed.
  - Patches (J Worlds Injector): small changes to the 2004 game, ticked in
    "Patches" and built into it when you press Play: VIP features, walking
    faster, the time on each chat line, no word filter. Your own patches go
    in the patches folder of the data folder (see the README there).
  - Your copy of the install (worlds.ini with friends, remembered
    passwords...), the logs and the settings are in the data folder ("Data
    folder" button):
       macOS:   ~/Library/Application Support/OpenWorlds
       Windows: %LOCALAPPDATA%\OpenWorlds
       Linux:   ~/.local/share/openworlds
  - A bigger window means more pixels to draw in software: the bridge uses
    several threads (Settings > Drawing threads, Auto by default).

Updates
-------
  When it opens, the launcher looks for a newer version among the
  project's GitHub releases, downloads it checking its SHA-256 and uses it
  after a restart ("Restart to update" button). It is kept in the data
  folder (app/), without touching the installed app. In Settings you can
  turn the check off or also get test builds. By hand: OpenWorlds --update.

Problems
--------
  When reporting a bug, attach the newest file in logs/ in the data folder
  (the last 20 sessions are kept). The project:
  https://github.com/luc4sterly/OpenWorlds
