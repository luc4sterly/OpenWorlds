# Game tests: the 2004 original client under the bridge

Session of 2026-09-26. Everything that can be done in the game was tested,
by hand, with the launcher package (`build/dist`, `OpenWorlds --original`)
on Linux: Xvfb 1280×960 without a window manager, Java 21, the mirror enabled
(`us1.worlds.net`, which today is LibreWorlds) and no world server, that
is, in single-user mode ("Single-user mode" in the "Internet
Connection" dialog).

Captures: `docs/renders/universe-map.png`, `blairwitch-cafeteria.png`,
`bowie-bwstreet.png` and `cmp-mug-and-kaleidoscope.png`.

## Travel between worlds

The 2004 installation only includes GroundZero: the other 11 worlds were
downloaded from the mirror. Installing a world follows the original's path. The teleport fails
because the world is not there, and `NetUpdate` requests `upgrades.lst` and offers the
package. With "Yes - download now" it downloads it (the launcher's local server
requests it from the mirror) and then asks "Restart and Upgrade". The
client requests `gdkup.exe updates.lst <pid>` and closes. The Java gdkup
installs the package (Wise or NSIS), records the world in `worlds.ini` and
starts the client again with `world:restart`.

| World | How it was reached | Package | Result |
|---|---|---|---|
| GroundZero | startup | (installed) | ✅ statues with textures thanks to the mirror |
| AvatarGallery | GroundZero's map | AvatarGallery36 (Wise) | ✅ download, installation and restart |
| WorldsChat (Worlds Center, Chat Deck) | map | WorldsChat50 (NSIS) | ✅ download, installation and restart |
| AnimalHouse (house, Club) | map | AnimalHouse33 (Wise) | ✅ |
| lets (Hang, Events) | map | lets62 (Wise) | ✅ |
| Meteor | map | Meteor25 (Wise) | ✅ |
| Dcn | Teleport menu | Dcn10 (NSIS) | ✅ |
| PolyGram (WorldsStore.com) | map, "Store" | PolyGram49 (Wise, 12.6 MB) | ✅ download, installation and restart |
| DressingRoom | Teleport menu | DressingRoom3 (Wise) | ✅; the `kcl.mov` kaleidoscope did not load (fixed) |
| Chaos (David Bowie's world) | WorldsMark → Change Location... | Chaos14 (Wise) | ✅ after fixing the closing of the dialog |
| BWStreet (BowieWorld, "Street Maze") | offered from Chaos, then Change Location | BWStreet3 (Wise) | ✅ download, installation and restart |
| The Blair Witch World (TheBurkittsvilleDiner) | universe map | TheBurkittsvilleDiner14 (Wise) | ✅ the Burkittsville diner; the mug hologram did not load (fixed) |
| GroundZero 37 → 40 | Options → Upgrade Now | GroundZero37-40 (LibreWorlds NSIS) | ✅ after adding 5 NSIS instructions |

Worlds on the universe map that the mirror serves (all of them answer with their
`upgrades.lst`): HansonStage, Aerosmith, AnimalHouse, Hanson World II,
Meteor, BowieWorld II, B.T. Openworld, WWF New York, Centis, Hang,
N.Y. Yankees World (`Stadium`), Avatar Gallery, The Blair Witch World,
Dcn, Worlds Center and Ground Zero. Also the Bowie family (BWStreet,
BWDecade, BWArt, BWAvatar, Bowie, 13 MB) and Chaos.

## Game features

| Feature | Result | Note |
|---|---|---|
| Walking and turning (arrow keys) | ✅ | after quantizing the clock like GetTickCount (before, turning was extremely slow at 600-800 fps) |
| Cameras (Overhead, First-person, Behind) | ✅ | Options → Change Avatar View |
| Chat | ✅ | offline it says there is no connection, like the original |
| Help → About | ✅ | with the versions of the worlds |
| Teleport (with submenus) | ✅ | |
| Actions (gestures) | ✅ | ⚠️ "Sleep" is not visible on the penguin |
| WorldsMark → Add new WorldsMark... | ✅ | the bookmark appears in the menu |
| WorldsMark → Change Location... | ✅ | takes you to the typed URL; before, it froze the whole UI (fixed) |
| WorldsMail | ✅ | To/Subject/body, Send closes the window; the mail goes out over SMTP to the 2004 server (dead) and never arrives |
| VIP → Become a VIP | ✅ | opens `www-dynamic.us.worlds.net/cgi-bin/vip.pl`: the bridge logs the URL and does not open it unless `-Dopenworlds.openUrls=1` is set |
| VIP → Choose Avatar, Saved Avatars, Customize Avatar, Accept Voice Calls, # Visible Users | grayed out | they are VIP-only, as in 2004; without VIP the avatar is changed by clicking the statues in Avatar Gallery |
| Options → Edit Friends (Add, Done) | ✅ | "FRIENDS ONLINE" only lists those who are connected |
| Options → Proxy Server Settings | ✅ | dialog with two fields, Cancel closes it |
| Options → Account Info | ✅ | like Become a VIP (`account.pl`) |
| Options → Upgrade Now | ✅ | checks the installed worlds against the mirror and offers GroundZero 37 → 40 |
| Universe map | ✅ | 16 worlds; those not installed offer the download, the installed ones "Start"; it moves with the arrow keys. Before, it closed the game (fixed) |
| Right click in the 3D view | ✅ | only appears over objects with menu actions (other avatars); on the ground nothing, like the original |
| Quit | ✅ | |
| Sound / Music... | not tested | the container has no sound or MIDI device |
| Delete/Edit WorldsMark, Recorder, Sign In, Reject Whispers, Hide Nametags, Enable Colored Chat | not tested | |

## Bugs found and fixed

1. **Dialogs with a text field froze the UI** (WorldsMark → Change
   Location..., and also Add WorldsMark, Mail, Edit Friends, Proxy...).
   `PolledDialog.mainCallback` is `synchronized` and closes the dialog with
   `setVisible(false)`, `parent.requestFocus()` and `dispose()`. In today's
   Java `dispose()` waits for the event thread. On X11 the input method
   requests client-window notification, so that thread takes the window's
   monitor when the text field is removed. Result: a deadlock, with
   the dialog black forever. It only happens on X11: `XInputMethod`
   calls `enableClientWindowNotification` and the macOS and Windows ones do not.
   Fix: `AwtCompat.closeHoldingLock` makes the three calls on the event
   thread with the monitor released. Test: `bridge/test/UiDisposeCheck.java`,
   which also reproduces the deadlock with the original way of closing.
2. **The universe map closed the game.** The mock of
   `Window.usingMicrosoftVMHacks()` returned `true`, so
   `RenderCanvas.handle` asked the hidden canvas for `getLocationOnScreen` and the
   exception escaped the main loop. In gamma.dll it is `DAT_004891cc == 1`
   (0x0040de40), and it is only set by `doMicrosoftVMHacks` (0x0040de30), which
   `Gamma.main` calls with the Microsoft JVM.
3. **Hologram `tex/mug.cmp` (Blair Witch)**: a frame can span
   several row groups (FUN_00442bc0), and the reader only decoded the
   first one. Now `CmpFrames` walks through all of them and keeps the `esi` row
   across groups and frames, like the single buffer of 0x442750. Sample and
   evidence: `assets/cmp-verified/mug/`; test: `CmpGroupsCheck`.
4. **`kcl.mov` (wardrobe, DressingRoom)**: when byte 13 of the header is
   not 0, gamma.dll also skips the number of colors in the table
   region (0x442963..0x442983). Sample: `assets/cmp-verified/kcl/`.
5. **GroundZero's Upgrade Now**: the 37 → 40 NSIS uses Delete (21),
   Push/Pop/Exch (31), FileClose (54), FileOpen (55) and FileRead (57), which the
   NSIS interpreter did not have. Test: `bridge/test/GdkUpCheck.java`, with the
   real packages in `assets/packages/`.
6. **An installer that aborted left the player without a game**: the Java
   gdkup stopped there. gdkup.exe does not read the exit code of each line
   (0x00401e75, message 0x402). It deletes the package, goes on with the next one and
   restarts at the end. It only stops if the line fails to start (0x00401d52). Now
   it does the same.
7. `tools/local-upgrade-server.py` answered with an empty response (and a traceback) to a path
   outside `/3DCDup/`. Now it returns 404, and with `--mirror` it requests whatever is missing
   from the mirror, like the launcher. `run_gamma.sh` uses it and applies `gdkup.pending`.

## Bugs fixed on 2026-09-29 (new launcher)

Reported by the user while playing with the package, reproduced and tested
on Linux (Xvfb, `xdotool`, mirror enabled):

8. **"The worlds download, and when you hit play after the restart it
   doesn't work".** With a world from the launcher's list not installed yet, the
   client cannot load it, falls back to GroundZero and offers the download from
   there. After installing it, gdkup restarts with `run.exe world:restart`
   (`NetUpdate.getRestartCmd`), which `TeleportAction.toURLString` resolves to
   `[Gamma] RestartAt`: where the pilot was on exit
   (`Gamma.RecordPosition`), that is GroundZero, not the chosen world. Now
   the launcher's session remembers the requested world and, if the update
   has just installed it, restarts in it (`Session.restartWith`). Tested with
   Meteor: Play → GroundZero offers Meteor → download → "Restart and
   Upgrade" → the game comes back directly in Meteor. Superseded on
   2026-09-30: the launcher now installs a world picked in its list before
   the game starts (`WorldInstall`), so this detour no longer happens.
9. **"If you click on a user nothing happens".** Left-clicking another
   user's avatar (`Drone.handle(MouseDownEvent)`) opens their menu
   (add to friends, whisper, mute, actions) with
   `droneMenu.show(console.getRender(), x, y)`, and that menu is attached to the friends
   list, a `Canvas` unrelated to the render canvas. The 2004 Java 1.4.2
   showed it; since Java 6 it throws "origin not in parent's hierarchy" (JDK
   bug 6278745). `AwtCompat.showPopup` opens it from its parent at the same
   point (`PopupShowCheck`). ⚠️ It remains to be seen whether the picking step hits
   the hologram avatars (`HoloDrone`, nearly all of them): an agent is looking into it.
10. **Releasing a world server** (`WorldServer.cleanup`) was cut short by
    `Thread.stop()`, which since Java 20 only throws: the socket was not closed
    and the unhooking did not finish. `JavaCompat.stopThread` (`JavaCompatCheck`).
11. **"The local whirl doesn't work".** The launcher offered "Local whirl" but
    nothing started it and the package did not include it. The apps then
    shipped whirl, started by the launcher. Superseded on 2026-09-30: whirl
    was replaced by J Solar Server, where players do see each other (the
    launcher's "Online", `docs/net-local-server.md`).
12. **"Single player" asked about the connection** ("unable to connect to Worlds
    servers... Single-user mode"): the launcher passes
    `-Dopenworlds.singleUser=true` and the dialog answers by itself
    (`bridge/natives-launcher.patch`). And the game window no longer opens at
    568×424 the first time: it takes two thirds of the screen.

## Open

- `Hologram.setActiveSide` prints "Error ... side 1 of 1" in a loop in
  DressingRoom and in Blair Witch. It is faithful: gamma.dll (0x00413ce0) compares the
  side against `2·n`, not against `n`, and the 2004 Java warns about it and uses side 0.
- Broken data in the Blair Witch world itself: `bench05.cmp` without `tex/` and
  `tex/null.cmp`, which do not exist.
- Chaos lost its slot in `[InstalledWorlds]` when Dcn was installed. It is faithful to
  both scripts: Chaos14's does not raise `MaxInstalledWorlds` and the NSIS one
  writes at `Max+1`. Chaos is still installed and can be loaded.
- The incremental xdelta patches (`%XDZ`) of the old worlds are not
  applied. `GdkUp` treats them as done and moves on.
- The voice chat (`sfmain.exe`, SpeakFreely with GSM) is decompiled but
  not translated.
- When GroundZero starts with the mirror enabled, the Avatar Gallery portal
  offers to download it right away: that is what the original does without that world.
