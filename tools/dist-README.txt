FreeWorlds - Worlds Chat / WorldsPlayer (1995-2004), preservado
=================================================================

Que es
------
Dos formas de volver a entrar en GroundZero:

  1. El CLIENTE ORIGINAL de 2004 (WorldsPlayer), decompilado, con el motor
     RenderWare 2.1 y la DLL gamma.dll traducidos a Java (el "puente
     portable"): la misma logica, la misma interfaz (menus Help, Options,
     Teleport, mapa del universo...) y el mismo dibujo por software, sin
     Windows ni Wine.
  2. El MOTOR NUEVO de FreeWorlds (OpenGL): GroundZero en tercera persona
     con tu avatar animado.

Como se arranca
---------------
  macOS:   FreeWorlds.app (paquete con Java incluido). La primera vez:
           clic derecho > Abrir (no esta firmado por Apple). Si dice que
           "esta danado": xattr -dr com.apple.quarantine FreeWorlds.app
  Windows: FreeWorlds\FreeWorlds.exe
  Linux:   FreeWorlds/bin/FreeWorlds

  Paquete portable (sin Java incluido, necesita Java 17 o mas nuevo):
           FreeWorlds.command (macOS), FreeWorlds.bat (Windows),
           FreeWorlds.sh (Linux)

Se abre un menu: elige "Jugar" (cliente original) o "Explorar" (motor
nuevo). Sin pantalla, o con --tui, el menu sale en la terminal. Todas las
opciones: FreeWorlds --help

Cliente original
----------------
  - Sin servidor: al entrar dice que no puede conectar; pulsa "Single-user
    mode". Se anda con las flechas; los menus son los de 2004.
  - Con servidor: en el lanzador elige "whirl local" u "Otro servidor" y un
    usuario (por ejemplo un whirl en 127.0.0.1:6650, ver server/whirl en el
    repositorio).
  - Tu copia de la instalacion (worlds.ini con amigos, contrasena recordada,
    etc.) y los registros de cada sesion estan en la carpeta de datos
    (boton "Carpeta de datos"):
       macOS:   ~/Library/Application Support/FreeWorlds
       Windows: %LOCALAPPDATA%\FreeWorlds
       Linux:   ~/.local/share/freeworlds
  - Ventana grande = mas pixeles que dibujar por software: el puente usa
    varios hilos (opcion "Hilos de dibujo", 0 = automatico).

Motor nuevo
-----------
  W/S andar, A/D de lado, flechas giran la camara, ESC sale.

Problemas
---------
  Adjunta el registro de la sesion (boton "Registros") al avisar de un
  fallo. Proyecto: docs/worlds-chat-project.md en el repositorio.
