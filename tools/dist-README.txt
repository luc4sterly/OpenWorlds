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

Se abre el lanzador: elige el mundo y el servidor y pulsa "Jugar". Sin
pantalla, o con --tui, el menu sale en la terminal. Todas las opciones:
FreeWorlds --help

Cliente original
----------------
  - Sin servidor: al entrar dice que no puede conectar; pulsa "Single-user
    mode". Se anda con las flechas; los menus son los de 2004.
  - whirl local: las apps traen whirl (el servidor de Whirlsplash, ver
    server/whirl en el repositorio) y el lanzador lo arranca y lo para con
    el juego. El usuario y una contrasena ya van rellenos: en el juego basta
    con pulsar "Sign In" (whirl no comprueba contrasenas). Con el paquete
    portable hace falta un whirl propio escuchando en 127.0.0.1:6650.
  - Otro servidor: escribelo como host:puerto y pon tu nombre.
  - Tu copia de la instalacion (worlds.ini con amigos, contrasena recordada,
    etc.) esta en la carpeta de datos (boton "Carpeta de datos"):
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
    varios hilos (Ajustes > "Hilos de dibujo", Auto por defecto).

Actualizaciones
---------------
  El lanzador busca al abrirse una version nueva en las releases de GitHub
  del proyecto, la descarga comprobando su SHA-256 y la usa al reiniciar
  (boton "Reiniciar y actualizar"). Se guarda en la carpeta de datos (app/),
  sin tocar la app instalada. Ajustes > Actualizaciones: desactivarlo,
  recibir versiones de prueba o, mientras el repositorio sea privado, poner
  un token de GitHub de solo lectura. A mano: FreeWorlds --update.

Problemas
---------
  Al avisar de un fallo adjunta el ultimo fichero de logs/ de la carpeta de
  datos (se guardan las 20 ultimas sesiones). Proyecto:
  docs/worlds-chat-project.md en el repositorio.
