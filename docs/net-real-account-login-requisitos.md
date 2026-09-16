# Login con cuenta real en `worlds.worlio.com:6650` — qué hace falta

No ejecutado (regla del proyecto: nunca credenciales inventadas/hardcodeadas,
nunca crear cuentas). Solo lectura del código real (`LoginWizard.java`,
`Galaxy.setAuthInfo`, `AutoServer`/`UserServer`) + lo ya verificado en
sesiones anteriores (`tools/net-probe/README.md`, sección "Servidor
primario") para dejar EXACTAMENTE claro qué tendría que aportar un
humano y cómo pasarlo a la sonda existente.

## 1. Por qué hace falta una cuenta (evidencia)

`worlds.worlio.com:6650` responde al PROPREQ con `#15 = "1"`
(`docs/net-handshake-trace.log`, ya capturado). `AutoServer.
state_XMIT_SI` mapea `#15=1` a `Class.forName("NET.worlds.network.
UserServer").newInstance()` — a diferencia de `AnonRoomServer`
(`#15=4`, el guest), `UserServer` exige autenticación real: no acepta
un `sessionInit` con solo nickname.

`Galaxy.setAuthInfo(username, newUsername, password, newPassword,
serial, mode)` (`NET/worlds/network/Galaxy.java:516`), para
`_serverType == 1` (UserServer), soporta tres modos (switch en la misma
función):

- **mode 1 REGISTER**: usuario nuevo. Usa `username`, `password`,
  `serial` (el `serial` NO se limpia a null en este caso — línea 534
  solo lo limpia para `mode==2`). El `serial` es el "Codeword" que la
  UI real pide tras registrarse por web (`LoginWizard.
  buildRegWaitCommon`, campo `codewordField`).
- **mode 2 AUTHENTICATE**: usuario YA registrado. Usa `username` +
  `password`; `serial` se pone a `null` explícitamente (línea 534).
  Es el modo que usa `LoginWizard.validateKnownUserInfo()`
  (`LoginWizard.java:446-453`) cuando el usuario teclea nombre+password
  conocidos y pulsa Sign-In — y es también el modo que
  `GuestLoginProbe` ya usa hoy (hardcodeado a `mode=2` en su
  `main`, línea 172: `galaxy.setAuthInfo(nick, null, pass, null, null,
  2)`).
- **mode 3**: `password` y `serial` se limpian a `null` — variante sin
  contraseña (recuperación/cambio), no relevante aquí.

## 2. Qué tiene que aportar el humano, en orden

1. **Registrarse en la web real** (no simulable, no hay atajo de
   protocolo): `https://worlds.worlio.com/register` — ya verificado
   accesible en una sesión anterior (`tools/net-probe/README.md`,
   sección "Servidor primario"), y la portada `https://worlds.worlio.
   com/` lo confirma como el flujo de alta. El formulario pide, como
   mínimo, un **email** (verificado). Presumiblemente también
   **nickname** y **password** deseados (formulario web estándar de
   registro; no verificado campo a campo sin rellenarlo de verdad, y
   esta sesión NO lo ha rellenado — sería crear una cuenta, fuera de
   alcance sin permiso explícito del usuario humano).
2. Tras registrarse, el humano tiene: **nickname**, **password**, y
   opcionalmente el **serial/codeword** que la web le muestre (solo
   hace falta si se quisiera ejercitar el modo 1 REGISTER contra el
   servidor por protocolo en vez de por la web; para AUTHENTICATE
   normal, mode 2, el serial no se usa).
3. Ningún fichero `.ini` adicional hace falta: `worlds.ini` real del
   proyecto (`assets/WorldsPlayer/worlds.ini`) ya apunta a
   `RestartAt=home:GroundZero/GroundZero.world` y no tiene
   `WorldServer=` fijado (usa el server que se le pase); el
   `clientVersion` real (`2004080500`) ya es el default de la sonda
   (verificado por `objdump` sobre `gamma.dll`, ver
   `tools/net-probe/README.md`).

## 3. Cómo se pasaría a la sonda existente

`GuestLoginProbe` YA acepta usuario+password reales por argv, sin
ningún cambio de código — están pensados para esto desde que se
escribió (comentario en la cabecera del fichero: "El 4º argv opcional
permite pasar un password SOLO para una cuenta que uno mismo haya
registrado a mano en esa web"):

```
tools/net-probe/run-guest-login.sh <workdir> worlds.worlio.com 6650 <nickname> <password>
```

(`clientVersion`, 6º argumento, se puede omitir — usa el default real
`2004080500`). Con `mode=2` (AUTHENTICATE, ya hardcodeado en la
sonda) y una cuenta ya registrada, el camino esperado por código es
`AutoServer` → `UserServer` → `sessionInit` con `VAR_ERROR=0` → estado
12 MAINLOOP, igual que con el guest pero con `_serverType=1`.

**Si se quisiera además ejercitar el registro por protocolo (mode 1)**
en vez de por la web, `GuestLoginProbe.main` tendría que dejar de
hardcodear `2` en la llamada a `setAuthInfo` (línea 172) y aceptar el
`serial`/modo por argv — cambio de código pequeño y acotado al harness
(no toca `source/`), pero no hecho en esta sesión porque no hay cuenta
con la que probarlo y el objetivo del punto 3 de la tarea era solo
determinar el requisito, no ejecutarlo.

## 4. Lo que esta sesión NO ha hecho (a propósito)

No se ha abierto el formulario de registro, no se ha inventado ningún
nickname/password/email, no se ha creado ninguna cuenta. Esta nota
documenta el camino real leído en el código; ejecutarlo depende de que
el usuario humano registre una cuenta y decida compartir sus
credenciales (vía argv, nunca hardcodeadas en el repo) para una sesión
futura.
