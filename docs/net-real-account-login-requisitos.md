# Login with a real account on `worlds.worlio.com:6650` — what is needed

Not executed (project rule: never invented/hardcoded credentials,
never create accounts). Only a reading of the real code
(`LoginWizard.java`, `Galaxy.setAuthInfo`, `AutoServer`/`UserServer`) plus
what was already verified in earlier sessions (`tools/net-probe/README.md`,
"Primary server" section) to make EXACTLY clear what a human would have to
provide and how to pass it to the existing probe.

## 1. Why an account is needed (evidence)

`worlds.worlio.com:6650` answers the PROPREQ with `#15 = "1"`
(`docs/net-handshake-trace.log`, already captured). `AutoServer.state_XMIT_SI`
maps `#15=1` to `Class.forName("NET.worlds.network.UserServer").newInstance()`
— unlike `AnonRoomServer` (`#15=4`, the guest), `UserServer` requires real
authentication: it does not accept a `sessionInit` with only a nickname.

`Galaxy.setAuthInfo(username, newUsername, password, newPassword,
serial, mode)` (`NET/worlds/network/Galaxy.java:516`), for
`_serverType == 1` (UserServer), supports three modes (a switch in the same
function):

- **mode 1 REGISTER**: new user. Uses `username`, `password`,
  `serial` (the `serial` is NOT cleared to null in this case — line 534
  only clears it for `mode==2`). The `serial` is the "Codeword" that the
  real UI asks for after registering on the web
  (`LoginWizard.buildRegWaitCommon`, field `codewordField`).
- **mode 2 AUTHENTICATE**: ALREADY-registered user. Uses `username` +
  `password`; `serial` is explicitly set to `null` (line 534).
  It is the mode used by `LoginWizard.validateKnownUserInfo()`
  (`LoginWizard.java:446-453`) when the user types a known name+password
  and presses Sign-In — and it is also the mode that
  `GuestLoginProbe` already uses today (hardcoded to `mode=2` in its
  `main`, line 172: `galaxy.setAuthInfo(nick, null, pass, null, null,
  2)`).
- **mode 3**: `password` and `serial` are cleared to `null` — a
  passwordless variant (recovery/change), not relevant here.

## 2. What the human has to provide, in order

1. **Register on the real website** (cannot be simulated, there is no
   protocol shortcut): `https://worlds.worlio.com/register` — already
   verified as reachable in an earlier session (`tools/net-probe/README.md`,
   "Primary server" section), and the front page `https://worlds.worlio.
   com/` confirms it as the sign-up flow. The form asks for, at a minimum,
   an **email** (verified). Presumably also the desired
   **nickname** and **password** (a standard web registration form;
   not verified field by field without actually filling it in, and
   this session has NOT filled it in — that would be creating an account,
   out of scope without explicit permission from the human user).
2. After registering, the human has: **nickname**, **password**, and
   optionally the **serial/codeword** that the website shows them (only
   needed if one wanted to exercise mode 1 REGISTER against the
   server over the protocol instead of through the web; for a normal
   AUTHENTICATE, mode 2, the serial is not used).
3. No additional `.ini` file is needed: the project's real `worlds.ini`
   (`assets/WorldsPlayer/worlds.ini`) already points to
   `RestartAt=home:GroundZero/GroundZero.world` and has no
   `WorldServer=` set (it uses whichever server it is given); the real
   `clientVersion` (`2004080500`) is already the probe's default
   (verified with `objdump` on `gamma.dll`, see
   `tools/net-probe/README.md`).

## 3. How it would be passed to the existing probe

`GuestLoginProbe` ALREADY accepts a real username+password through argv,
without any code change — they have been meant for this since it was
written (comment in the file header: "The optional 4th argv allows passing
a password ONLY for an account that one has registered by hand on that
website"):

```
tools/net-probe/run-guest-login.sh <workdir> worlds.worlio.com 6650 <nickname> <password>
```

(`clientVersion`, the 6th argument, can be omitted — it uses the real
default `2004080500`). With `mode=2` (AUTHENTICATE, already hardcoded in
the probe) and an already-registered account, the path expected from the
code is `AutoServer` → `UserServer` → `sessionInit` with `VAR_ERROR=0` →
state 12 MAINLOOP, just like with the guest but with `_serverType=1`.

**If one also wanted to exercise registration over the protocol (mode 1)**
instead of through the web, `GuestLoginProbe.main` would have to stop
hardcoding `2` in the call to `setAuthInfo` (line 172) and accept the
`serial`/mode through argv — a small code change, confined to the harness
(it does not touch `source/`), but not made in this session because there
is no account to test it with and the goal of point 3 of the task was only
to determine the requirement, not to execute it.

## 4. What this session has NOT done (on purpose)

The registration form has not been opened, no nickname/password/email has
been invented, no account has been created. This note documents the real
path read from the code; running it depends on the human user registering
an account and deciding to share their credentials (via argv, never
hardcoded in the repo) for a future session.
