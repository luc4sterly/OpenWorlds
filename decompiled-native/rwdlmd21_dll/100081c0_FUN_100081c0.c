// 100081c0 FUN_100081c0 [Global]
// program: rwdlmd21.dll

undefined4 * FUN_100081c0(int *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  char cVar10;
  char cVar13;
  uint uVar11;
  int iVar12;
  char cVar14;
  char cVar15;
  char cVar16;
  char cVar17;
  int iVar18;
  uint uVar19;
  uint *puVar20;
  uint *puVar21;
  byte *pbVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  char local_38;
  char local_37;
  char local_36;
  char local_35;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  uint local_30;
  uint *puStack_28;
  int local_24;
  int local_20;
  int iStack_18;
  uint uStack_c;
  
  if ((*param_1 == 1) && (param_1[0xd] == 0)) {
    return (undefined4 *)0x0;
  }
  iVar12 = param_1[8];
  param_2[7] = param_1[7];
  param_2[8] = iVar12;
  puVar6 = FUN_1000a460(param_2);
  if (puVar6 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar12 = *param_1;
  if (iVar12 == 1) {
    local_33 = '\a';
  }
  else {
    uVar11 = param_1[2];
    if ((uVar11 & 0xffff0000) == 0) {
      if ((char)(uVar11 >> 8) == '\0') {
        local_33 = (&DAT_1008d7d0)[uVar11] + -1;
      }
      else {
        local_33 = (&DAT_1008d7d0)[(int)uVar11 >> 8] + '\a';
      }
    }
    else if ((char)(uVar11 >> 0x18) == '\0') {
      local_33 = (&DAT_1008d7d0)[(int)uVar11 >> 0x10] + '\x0f';
    }
    else {
      local_33 = (&DAT_1008d7d0)[(int)uVar11 >> 0x18] + '\x17';
    }
  }
  uVar11 = param_1[2] & (~(param_1[2] * 2) | 1U);
  if ((uVar11 & 0xffff0000) == 0) {
    if ((char)(uVar11 >> 8) == '\0') {
      cVar9 = (&DAT_1008d7d0)[uVar11] + -1;
    }
    else {
      cVar9 = (&DAT_1008d7d0)[uVar11 >> 8] + '\a';
    }
  }
  else if ((uVar11 & 0xff000000) == 0) {
    cVar9 = (&DAT_1008d7d0)[uVar11 >> 0x10] + '\x0f';
  }
  else {
    cVar9 = (&DAT_1008d7d0)[uVar11 >> 0x18] + '\x17';
  }
  cVar9 = local_33 - cVar9;
  uVar11 = puVar6[2];
  if ((uVar11 & 0xffff0000) == 0) {
    if ((char)(uVar11 >> 8) == '\0') {
      cVar14 = (&DAT_1008d7d0)[uVar11] + -1;
    }
    else {
      cVar14 = (&DAT_1008d7d0)[(int)uVar11 >> 8] + '\a';
    }
  }
  else if ((char)(uVar11 >> 0x18) == '\0') {
    cVar14 = (&DAT_1008d7d0)[(int)uVar11 >> 0x10] + '\x0f';
  }
  else {
    cVar14 = (&DAT_1008d7d0)[(int)uVar11 >> 0x18] + '\x17';
  }
  uVar11 = (~(uVar11 * 2) | 1) & uVar11;
  if ((uVar11 & 0xffff0000) == 0) {
    if ((char)(uVar11 >> 8) == '\0') {
      local_38 = (&DAT_1008d7d0)[uVar11] + -1;
    }
    else {
      local_38 = (&DAT_1008d7d0)[uVar11 >> 8] + '\a';
    }
  }
  else if ((uVar11 & 0xff000000) == 0) {
    local_38 = (&DAT_1008d7d0)[uVar11 >> 0x10] + '\x0f';
  }
  else {
    local_38 = (&DAT_1008d7d0)[uVar11 >> 0x18] + '\x17';
  }
  local_38 = (cVar14 - cVar9) - local_38;
  local_33 = local_33 - cVar14;
  bVar23 = -1 < (char)local_33;
  if (!bVar23) {
    local_33 = -local_33;
  }
  if (iVar12 == 1) {
    local_32 = '\a';
  }
  else {
    uVar11 = param_1[3];
    if ((uVar11 & 0xffff0000) == 0) {
      if ((char)(uVar11 >> 8) == '\0') {
        local_32 = (&DAT_1008d7d0)[uVar11] + -1;
      }
      else {
        local_32 = (&DAT_1008d7d0)[(int)uVar11 >> 8] + '\a';
      }
    }
    else if ((char)(uVar11 >> 0x18) == '\0') {
      local_32 = (&DAT_1008d7d0)[(int)uVar11 >> 0x10] + '\x0f';
    }
    else {
      local_32 = (&DAT_1008d7d0)[(int)uVar11 >> 0x18] + '\x17';
    }
  }
  uVar11 = param_1[3] & (~(param_1[3] * 2) | 1U);
  if ((uVar11 & 0xffff0000) == 0) {
    if ((char)(uVar11 >> 8) == '\0') {
      cVar14 = (&DAT_1008d7d0)[uVar11] + -1;
    }
    else {
      cVar14 = (&DAT_1008d7d0)[uVar11 >> 8] + '\a';
    }
  }
  else if ((uVar11 & 0xff000000) == 0) {
    cVar14 = (&DAT_1008d7d0)[uVar11 >> 0x10] + '\x0f';
  }
  else {
    cVar14 = (&DAT_1008d7d0)[uVar11 >> 0x18] + '\x17';
  }
  cVar14 = local_32 - cVar14;
  uVar11 = puVar6[3];
  if ((uVar11 & 0xffff0000) == 0) {
    if ((char)(uVar11 >> 8) == '\0') {
      cVar15 = (&DAT_1008d7d0)[uVar11] + -1;
    }
    else {
      cVar15 = (&DAT_1008d7d0)[(int)uVar11 >> 8] + '\a';
    }
  }
  else if ((char)(uVar11 >> 0x18) == '\0') {
    cVar15 = (&DAT_1008d7d0)[(int)uVar11 >> 0x10] + '\x0f';
  }
  else {
    cVar15 = (&DAT_1008d7d0)[(int)uVar11 >> 0x18] + '\x17';
  }
  uVar11 = (~(uVar11 * 2) | 1) & uVar11;
  if ((uVar11 & 0xffff0000) == 0) {
    if ((char)(uVar11 >> 8) == '\0') {
      cVar3 = (&DAT_1008d7d0)[uVar11] + -1;
    }
    else {
      cVar3 = (&DAT_1008d7d0)[uVar11 >> 8] + '\a';
    }
  }
  else if ((uVar11 & 0xff000000) == 0) {
    cVar3 = (&DAT_1008d7d0)[uVar11 >> 0x10] + '\x0f';
  }
  else {
    cVar3 = (&DAT_1008d7d0)[uVar11 >> 0x18] + '\x17';
  }
  local_37 = (cVar15 - cVar3) - cVar14;
  local_32 = local_32 - cVar15;
  bVar24 = -1 < (char)local_32;
  if (!bVar24) {
    local_32 = -local_32;
  }
  if (iVar12 == 1) {
    local_31 = '\a';
  }
  else {
    uVar11 = param_1[4];
    if ((uVar11 & 0xffff0000) == 0) {
      if ((char)(uVar11 >> 8) == '\0') {
        local_31 = (&DAT_1008d7d0)[uVar11] + -1;
      }
      else {
        local_31 = (&DAT_1008d7d0)[(int)uVar11 >> 8] + '\a';
      }
    }
    else if ((char)(uVar11 >> 0x18) == '\0') {
      local_31 = (&DAT_1008d7d0)[(int)uVar11 >> 0x10] + '\x0f';
    }
    else {
      local_31 = (&DAT_1008d7d0)[(int)uVar11 >> 0x18] + '\x17';
    }
  }
  uVar11 = param_1[4] & (~(param_1[4] * 2) | 1U);
  if ((uVar11 & 0xffff0000) == 0) {
    if ((char)(uVar11 >> 8) == '\0') {
      cVar15 = (&DAT_1008d7d0)[uVar11] + -1;
    }
    else {
      cVar15 = (&DAT_1008d7d0)[uVar11 >> 8] + '\a';
    }
  }
  else if ((uVar11 & 0xff000000) == 0) {
    cVar15 = (&DAT_1008d7d0)[uVar11 >> 0x10] + '\x0f';
  }
  else {
    cVar15 = (&DAT_1008d7d0)[uVar11 >> 0x18] + '\x17';
  }
  cVar15 = local_31 - cVar15;
  uVar11 = puVar6[4];
  cVar16 = (char)(uVar11 >> 8);
  cVar3 = (char)(uVar11 >> 0x18);
  if ((uVar11 & 0xffff0000) == 0) {
    if (cVar16 == '\0') {
      cVar10 = (&DAT_1008d7d0)[uVar11] + -1;
    }
    else {
      cVar10 = (&DAT_1008d7d0)[(int)uVar11 >> 8] + '\a';
    }
  }
  else if (cVar3 == '\0') {
    cVar10 = (&DAT_1008d7d0)[(int)uVar11 >> 0x10] + '\x0f';
  }
  else {
    cVar10 = (&DAT_1008d7d0)[(int)uVar11 >> 0x18] + '\x17';
  }
  uVar7 = (~(uVar11 * 2) | 1) & uVar11;
  if ((uVar7 & 0xffff0000) == 0) {
    if ((char)(uVar7 >> 8) == '\0') {
      cVar4 = (&DAT_1008d7d0)[uVar7] + -1;
    }
    else {
      cVar4 = (&DAT_1008d7d0)[uVar7 >> 8] + '\a';
    }
  }
  else if ((uVar7 & 0xff000000) == 0) {
    cVar4 = (&DAT_1008d7d0)[uVar7 >> 0x10] + '\x0f';
  }
  else {
    cVar4 = (&DAT_1008d7d0)[uVar7 >> 0x18] + '\x17';
  }
  local_36 = (cVar10 - cVar4) - cVar15;
  local_31 = local_31 - cVar10;
  bVar25 = -1 < (char)local_31;
  if (!bVar25) {
    local_31 = -local_31;
  }
  if (iVar12 == 1) {
    local_34 = '\a';
  }
  else {
    uVar7 = param_1[5];
    if ((uVar7 & 0xffff0000) == 0) {
      if ((char)(uVar7 >> 8) == '\0') {
        local_34 = (&DAT_1008d7d0)[uVar7] + -1;
      }
      else {
        local_34 = (&DAT_1008d7d0)[(int)uVar7 >> 8] + '\a';
      }
    }
    else if ((char)(uVar7 >> 0x18) == '\0') {
      local_34 = (&DAT_1008d7d0)[(int)uVar7 >> 0x10] + '\x0f';
    }
    else {
      local_34 = (&DAT_1008d7d0)[(int)uVar7 >> 0x18] + '\x17';
    }
  }
  uVar7 = param_1[5] & (~(param_1[5] * 2) | 1U);
  if ((uVar7 & 0xffff0000) == 0) {
    if ((char)(uVar7 >> 8) == '\0') {
      cVar10 = (&DAT_1008d7d0)[uVar7] + -1;
    }
    else {
      cVar10 = (&DAT_1008d7d0)[uVar7 >> 8] + '\a';
    }
  }
  else if ((uVar7 & 0xff000000) == 0) {
    cVar10 = (&DAT_1008d7d0)[uVar7 >> 0x10] + '\x0f';
  }
  else {
    cVar10 = (&DAT_1008d7d0)[uVar7 >> 0x18] + '\x17';
  }
  cVar10 = local_34 - cVar10;
  uVar7 = puVar6[5];
  cVar13 = (char)(uVar7 >> 8);
  cVar4 = (char)(uVar7 >> 0x18);
  if ((uVar7 & 0xffff0000) == 0) {
    if (cVar13 == '\0') {
      cVar17 = (&DAT_1008d7d0)[uVar7] + -1;
    }
    else {
      cVar17 = (&DAT_1008d7d0)[(int)uVar7 >> 8] + '\a';
    }
  }
  else if (cVar4 == '\0') {
    cVar17 = (&DAT_1008d7d0)[(int)uVar7 >> 0x10] + '\x0f';
  }
  else {
    cVar17 = (&DAT_1008d7d0)[(int)uVar7 >> 0x18] + '\x17';
  }
  uVar8 = (~(uVar7 * 2) | 1) & uVar7;
  if ((uVar8 & 0xffff0000) == 0) {
    if ((char)(uVar8 >> 8) == '\0') {
      cVar5 = (&DAT_1008d7d0)[uVar8] + -1;
    }
    else {
      cVar5 = (&DAT_1008d7d0)[uVar8 >> 8] + '\a';
    }
  }
  else if ((uVar8 & 0xff000000) == 0) {
    cVar5 = (&DAT_1008d7d0)[uVar8 >> 0x10] + '\x0f';
  }
  else {
    cVar5 = (&DAT_1008d7d0)[uVar8 >> 0x18] + '\x17';
  }
  local_35 = (cVar17 - cVar5) - cVar10;
  local_30 = CONCAT31(local_30._1_3_,local_35);
  local_34 = local_34 - cVar17;
  bVar26 = -1 < (char)local_34;
  if (!bVar26) {
    local_34 = -local_34;
  }
  if ((uVar7 & 0xffff0000) == 0) {
    if (cVar13 == '\0') {
      iVar12 = (char)(&DAT_1008d7d0)[uVar7] + -1;
    }
    else {
      iVar12 = (char)(&DAT_1008d7d0)[(int)uVar7 >> 8] + 7;
    }
  }
  else if (cVar4 == '\0') {
    iVar12 = (char)(&DAT_1008d7d0)[(int)uVar7 >> 0x10] + 0xf;
  }
  else {
    iVar12 = (char)(&DAT_1008d7d0)[(int)uVar7 >> 0x18] + 0x17;
  }
  if ((uVar11 & 0xffff0000) == 0) {
    if (cVar16 == '\0') {
      local_20 = (char)(&DAT_1008d7d0)[uVar11] + -1;
    }
    else {
      local_20 = (char)(&DAT_1008d7d0)[(int)uVar11 >> 8] + 7;
    }
  }
  else if (cVar3 == '\0') {
    local_20 = (char)(&DAT_1008d7d0)[(int)uVar11 >> 0x10] + 0xf;
  }
  else {
    local_20 = (char)(&DAT_1008d7d0)[(int)uVar11 >> 0x18] + 0x17;
  }
  local_20 = local_20 - iVar12;
  bVar27 = -1 < local_20;
  if (!bVar27) {
    local_20 = -local_20;
  }
  if (*(code **)(DAT_10089de0 + 0x298) != (code *)0x0) {
    if (((param_1[0x10] & 2U) != 0) &&
       (iVar12 = (**(code **)(DAT_10089de0 + 0x298))(param_1), iVar12 == 0)) {
      return (undefined4 *)0x0;
    }
    if (((puVar6[0x10] & 2) != 0) &&
       (iVar12 = (**(code **)(DAT_10089de0 + 0x298))(puVar6), iVar12 == 0)) {
      if (((param_1[0x10] & 2U) != 0) && (*(code **)(DAT_10089de0 + 0x29c) != (code *)0x0)) {
        (**(code **)(DAT_10089de0 + 0x29c))(param_1);
      }
      return (undefined4 *)0x0;
    }
  }
  iVar12 = param_1[6];
  iVar1 = puVar6[6];
  if (*param_1 == 1) {
    local_24 = 0;
    iVar2 = param_1[0xd];
    if (0 < param_1[8]) {
      do {
        iVar18 = 0;
        pbVar22 = (byte *)(iVar12 + param_1[10] * local_24);
        puVar20 = (uint *)(iVar1 + puVar6[10] * local_24);
        if (0 < param_1[7]) {
          do {
            if (bVar23) {
              uVar11 = (uint)(*(byte *)((uint)*pbVar22 * 3 + iVar2) >> (local_33 & 0x1f));
            }
            else {
              uVar11 = (uint)*(byte *)((uint)*pbVar22 * 3 + iVar2) << (local_33 & 0x1f);
            }
            if (bVar24) {
              uVar7 = (uint)(*(byte *)((uint)*pbVar22 * 3 + 1 + iVar2) >> (local_32 & 0x1f));
            }
            else {
              uVar7 = (uint)*(byte *)((uint)*pbVar22 * 3 + 1 + iVar2) << (local_32 & 0x1f);
            }
            if (bVar25) {
              uVar8 = (uint)(*(byte *)((uint)*pbVar22 * 3 + 2 + iVar2) >> (local_31 & 0x1f));
            }
            else {
              uVar8 = (uint)*(byte *)((uint)*pbVar22 * 3 + 2 + iVar2) << (local_31 & 0x1f);
            }
            uVar7 = uVar11 & puVar6[2] | uVar7 & puVar6[3] | uVar8 & puVar6[4];
            uVar11 = puVar6[5];
            if (uVar11 == 0) {
              if (uVar7 == 0) {
                uVar7 = ~puVar6[4] + 1 & puVar6[4];
              }
            }
            else if ((param_3 & 4) == 0) {
              uVar7 = uVar7 | uVar11;
            }
            else {
              if (bVar27) {
                uVar8 = (puVar6[4] & uVar7) >> ((byte)local_20 & 0x1f);
              }
              else {
                uVar8 = (puVar6[4] & uVar7) << ((byte)local_20 & 0x1f);
              }
              uVar7 = uVar7 | uVar8 & uVar11;
            }
            puVar21 = puVar20;
            switch(puVar6[1]) {
            case 8:
              *(char *)puVar20 = (char)uVar7;
              puVar21 = (uint *)((int)puVar20 + 1);
              break;
            case 0x10:
              *(short *)puVar20 = (short)uVar7;
              puVar21 = (uint *)((int)puVar20 + 2);
              break;
            case 0x18:
              puVar21 = (uint *)((int)puVar20 + 3);
              *(char *)puVar20 = (char)(uVar7 >> 0x10);
              *(char *)((int)puVar20 + 1) = (char)(uVar7 >> 8);
              *(char *)((int)puVar20 + 2) = (char)uVar7;
              break;
            case 0x20:
              *puVar20 = uVar7;
              puVar21 = puVar20 + 1;
            }
            pbVar22 = pbVar22 + 1;
            iVar18 = iVar18 + 1;
            puVar20 = puVar21;
          } while (iVar18 < param_1[7]);
        }
        local_24 = local_24 + 1;
      } while (local_24 < param_1[8]);
    }
  }
  else {
    local_24 = 0;
    if (0 < param_1[8]) {
      do {
        iStack_18 = 0;
        puStack_28 = (uint *)(iVar1 + puVar6[10] * local_24);
        if (0 < param_1[7]) {
          puVar20 = (uint *)(iVar12 + param_1[10] * local_24);
          do {
            puVar21 = puVar20;
            switch(param_1[1]) {
            case 8:
              uStack_c = (uint)(byte)*puVar20;
              puVar21 = (uint *)((int)puVar20 + 1);
              break;
            case 0x10:
              puVar21 = (uint *)((int)puVar20 + 2);
              uStack_c = (uint)(ushort)*puVar20;
              break;
            case 0x18:
              puVar21 = (uint *)((int)puVar20 + 3);
              uStack_c = (uint)(byte)*puVar20 << 0x10 | (uint)*(byte *)((int)puVar20 + 1) << 8 |
                         (uint)*(byte *)((int)puVar20 + 2);
              break;
            case 0x20:
              uStack_c = *puVar20;
              puVar21 = puVar20 + 1;
            }
            if (bVar23) {
              uVar11 = (param_1[2] & uStack_c) >> (local_33 & 0x1f);
              uVar7 = uVar11;
            }
            else {
              uVar11 = (param_1[2] & uStack_c) << (local_33 & 0x1f);
              uVar7 = uVar11;
            }
            for (; '\0' < local_38; local_38 = local_38 - cVar9) {
              uVar11 = uVar11 | uVar7;
            }
            if (bVar24) {
              uVar7 = (param_1[3] & uStack_c) >> (local_32 & 0x1f);
              uVar8 = uVar7;
            }
            else {
              uVar7 = (param_1[3] & uStack_c) << (local_32 & 0x1f);
              uVar8 = uVar7;
            }
            for (; '\0' < local_37; local_37 = local_37 - cVar14) {
              uVar7 = uVar7 | uVar8;
            }
            if (bVar25) {
              uVar8 = (param_1[4] & uStack_c) >> (local_31 & 0x1f);
              uVar19 = uVar8;
            }
            else {
              uVar8 = (param_1[4] & uStack_c) << (local_31 & 0x1f);
              uVar19 = uVar8;
            }
            for (; '\0' < local_36; local_36 = local_36 - cVar15) {
              uVar8 = uVar8 | uVar19;
            }
            if ((param_3 & 8) != 0) {
              if (param_1[5] == 0) {
                local_30 = (uStack_c == 0) - 1;
              }
              else {
                uVar19 = uStack_c & param_1[5];
                if (bVar26) {
                  local_30 = uVar19 >> (local_34 & 0x1f);
                  uVar19 = local_30;
                }
                else {
                  local_30 = uVar19 << (local_34 & 0x1f);
                  uVar19 = local_30;
                }
                for (; '\0' < local_35; local_35 = local_35 - cVar10) {
                  local_30 = local_30 | uVar19;
                }
              }
            }
            uVar19 = puVar6[4];
            uStack_c = (puVar6[3] & uVar7) + (puVar6[2] & uVar11) + (uVar19 & uVar8);
            uVar11 = puVar6[5];
            if ((param_3 & 8) == 0) {
              if (uVar11 == 0) {
                if (uStack_c == 0) {
                  uStack_c = ~uVar19 + 1 & uVar19;
                }
              }
              else if ((param_3 & 4) == 0) {
                uStack_c = uStack_c | uVar11;
              }
              else if (bVar27) {
                uStack_c = uStack_c | (uStack_c & uVar19) >> ((byte)local_20 & 0x1f) & uVar11;
              }
              else {
                uStack_c = uStack_c | (uStack_c & uVar19) << ((byte)local_20 & 0x1f) & uVar11;
              }
            }
            else if (uVar11 == 0) {
              if (local_30 == 0) {
                uStack_c = 0;
              }
            }
            else {
              uStack_c = uStack_c + (local_30 & uVar11);
            }
            switch(puVar6[1]) {
            case 8:
              *(char *)puStack_28 = (char)uStack_c;
              puStack_28 = (uint *)((int)puStack_28 + 1);
              break;
            case 0x10:
              *(short *)puStack_28 = (short)uStack_c;
              puStack_28 = (uint *)((int)puStack_28 + 2);
              break;
            case 0x18:
              *(char *)puStack_28 = (char)(uStack_c >> 0x10);
              *(char *)((int)puStack_28 + 1) = (char)(uStack_c >> 8);
              *(char *)((int)puStack_28 + 2) = (char)uStack_c;
              puStack_28 = (uint *)((int)puStack_28 + 3);
              break;
            case 0x20:
              *puStack_28 = uStack_c;
              puStack_28 = puStack_28 + 1;
            }
            iStack_18 = iStack_18 + 1;
            puVar20 = puVar21;
          } while (iStack_18 < param_1[7]);
        }
        local_24 = local_24 + 1;
      } while (local_24 < param_1[8]);
    }
  }
  if (*(code **)(DAT_10089de0 + 0x29c) != (code *)0x0) {
    if ((param_1[0x10] & 2U) != 0) {
      (**(code **)(DAT_10089de0 + 0x29c))(param_1);
    }
    if ((puVar6[0x10] & 2) != 0) {
      (**(code **)(DAT_10089de0 + 0x29c))(puVar6);
    }
  }
  return puVar6;
}


