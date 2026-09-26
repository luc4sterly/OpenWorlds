FreeWorlds - Worlds Chat / WorldsPlayer (1995-2004), preservado
=================================================================

Que es
------
El CLIENTE ORIGINAL de 2004 (WorldsPlayer), decompilado, con el motor
RenderWare 2.1 y la DLL gamma.dll traducidos a Java (el "puente portable"):
la misma logica, la misma interfaz (menus Help, Options, Teleport, mapa del
universo...) y el mismo dibujo por software, sin Windows ni Wine.

Como se arranca
---------------
  macOS:   FreeWorlds.app (paquete con Java incluido). No esta firmado
           por Apple: la primera vez macOS lo bloquea. En macOS 15
           (Sequoia) ve a Ajustes del Sistema > Privacidad y seguridad >
           "Abrir igualmente" tras el primer intento; o, en Terminal:
              xattr -dr com.apple.quarantine /ruta/a/FreeWorlds.app
           (esto tambien arregla el aviso de "esta danado").
  Windows: FreeWorlds\FreeWorlds.exe
  Linux:   FreeWorlds/bin/FreeWorlds

  Paquete portable (sin Java incluido, necesita Java 17 o mas nuevo):
           FreeWorlds.command (macOS), FreeWorlds.bat (Windows),
           FreeWorlds.sh (Linux)

Se abre un menu: elige el mundo y pulsa "Jugar". Sin pantalla, o con
--tui, el menu sale en la terminal. Todas las opciones: FreeWorlds --help

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
  - Otros mundos: la instalacion de 2004 solo trae GroundZero. Los demas
    (Avatar Gallery, Worlds Center, Animal House, Hang, Meteor, The Blair
    Witch World, los de Bowie...) se piden desde el mapa, el menu Teleport
    o el mapa del universo: el juego ofrece descargarlos de us1.worlds.net
    (hoy el espejo de LibreWorlds) y pide reiniciar; el lanzador instala el
    paquete y vuelve a abrir el juego solo. Options > Upgrade Now busca
    actualizaciones de los mundos instalados. Sin red, o con la opcion
    "Contenido" desmarcada (--no-mirror), solo hay GroundZero.
  - Ventana grande = mas pixeles que dibujar por software: el puente usa
    varios hilos (opcion "Hilos de dibujo", 0 = automatico).

Problemas
---------
  Adjunta el registro de la sesion (boton "Registros") al avisar de un
  fallo. Proyecto: docs/worlds-chat-project.md en el repositorio.
