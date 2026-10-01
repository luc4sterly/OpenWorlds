J Solar Server - your own Worlds server
=======================================

What it is
----------
A world server for WorldsPlayer, the 2004 3D chat client that OpenWorlds
plays. Run it on your computer and your friends (with the OpenWorlds
launcher) meet you in the same worlds: they see each other's avatars walk
around, chat, whisper, keep friends lists, and can be VIPs.

Starting it
-----------
  macOS:   JSolarServer.app. It is not signed by Apple: the first time macOS
           blocks it. On macOS 15 (Sequoia) go to System Settings > Privacy
           & Security > "Open Anyway" after the first try; or, in Terminal:
              xattr -dr com.apple.quarantine /path/to/JSolarServer.app
  Windows: JSolarServer\JSolarServer.exe
  Linux:   JSolarServer/bin/JSolarServer

  Portable package (no Java included, needs Java 17 or newer):
           JSolarServer.command (macOS), JSolarServer.bat (Windows),
           JSolarServer.sh (Linux)

The window opens and the server starts. On the left you see whether it is
running and the address to give your friends (for example 192.168.1.20:6650).
They choose "Online" in the OpenWorlds launcher, type that address, and any
name and password: the first time, that makes their account.

Players on the Internet
-----------------------
The address on the left works on your own network. For friends elsewhere,
forward the port (6650, and 6651 for encrypted connections) on your router
to this computer, and give them your public address (search the web for
"what is my IP").

The window
----------
  Players     who is online and where; disconnect, ban or make someone VIP.
  Accounts    every account: new account, new password, VIP, admin, ban,
              delete.
  Chat & log  what happens on the server, and a message for everyone.
  Settings    the server's name and welcome message, who can join (open
              sign-up, guests, how many at once), the ports, and encrypted
              connections.

Encrypted connections
---------------------
Tick "Encrypted connections (TLS)" in Settings: the server then also listens
on port 6651 with its own certificate, made the first time. Players tick
"Encrypted" in the launcher; the first time, the launcher shows the
certificate's fingerprint so they can compare it with the one in your
Settings, and from then on it only trusts that one. Names, passwords and chat
travel encrypted.

Safe on the Internet
--------------------
J Solar Server keeps itself healthy when anyone can reach it: one address
can have 16 connections open at once; after 5 wrong passwords from an
address in 10 minutes, sign-ins from it wait; an address can make 5 new
accounts an hour; a connection that floods the server with packets is
dropped. Passwords are stored hashed, never as they are typed. With
"Encrypted connections" on, names, passwords and chat travel encrypted.

Admins in the game
------------------
Accounts marked admin can type in the game's chat: /say TEXT (to everyone),
/kick NAME, /ban NAME, /unban NAME, /vip NAME. Everyone can use /who,
/where NAME and /help.

Without a window
----------------
  JSolarServer --headless        the server with a command console (type help)
  JSolarServer --help            every option (ports, data folder, accounts...)

Your data
---------
Settings, accounts (passwords are stored hashed, never as they are typed),
the certificate and the logs are in the data folder ("Data folder" button):
  macOS:   ~/Library/Application Support/J Solar Server
  Windows: %LOCALAPPDATA%\J Solar Server
  Linux:   ~/.local/share/j-solar-server
