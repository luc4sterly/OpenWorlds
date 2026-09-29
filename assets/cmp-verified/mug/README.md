# mug.cmp

Holograma de la taza de la cafetería de The Blair Witch World
(`TheBurkittsvilleDiner`, 2000-2001).

- Origen: `http://us1.worlds.net/3DCDup/TheBurkittsvilleDiner/TheBurkittsvilleDiner14.exe`
  (paquete Wise de 1 103 334 bytes que sirve hoy el espejo de LibreWorlds),
  `content.zip` → `tex/mug.cmp`.
- 4 688 bytes, SHA-256 `8e2aea9543a7321a4f35115fc5be7dea6f89a3c2daac3faf729eebf435303ad3`.

Es la primera muestra con **dos grupos de filas en un mismo fotograma**
(FUN_00442bc0): 213×233, 117 pares de filas repartidos en 76 + 41. La tabla
de fotogramas da el primer grupo (offset 943, 2 071 bytes), y su cabecera da
el tamaño del segundo (1 674). 943 + 2 071 + 1 674 = 4 688, el final exacto
del fichero. Cada grupo consume exactamente sus cinco flujos. Antes solo se
decodificaba el primer grupo: al pasar de fila 152 se leía el relleno de
ceros, `CmpStage2` se paraba en el caso `idx == 0` y el juego decía
"Unable to load hologram: rel:home:theburkittsvillediner/tex/mug.cmp".

La cabecera trae 255 colores (byte 12), así que el índice 255 no está en la
paleta y es el transparente del holograma: las cuatro esquinas lo usan.

Lo comprueba `formats/test/net/openworlds/cmp/CmpGroupsCheck.java`.
