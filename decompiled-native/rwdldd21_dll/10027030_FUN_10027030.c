// 10027030 FUN_10027030 [Global]
// program: RWDLDD21.DLL

undefined4 * FUN_10027030(int *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  char cVar12;
  char cVar13;
  char cVar14;
  char cVar15;
  char cVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  char cVar21;
  byte *pbVar20;
  char cVar22;
  uint *puVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  bool bVar28;
  char local_34;
  char local_33;
  char local_32;
  char local_31;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  uint local_2c;
  int local_28;
  int local_1c;
  int iStack_18;
  
  if ((*param_1 == 1) && (param_1[0xd] == 0)) {
    return (undefined4 *)0x0;
  }
  iVar19 = param_1[8];
  param_2[7] = param_1[7];
  param_2[8] = iVar19;
  puVar6 = FUN_10024a80(param_2);
  if (puVar6 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  iVar19 = *param_1;
  if (iVar19 == 1) {
    local_2f = '\a';
  }
  else {
    uVar17 = param_1[2];
    if ((uVar17 & 0xffff0000) == 0) {
      if ((char)(uVar17 >> 8) == '\0') {
        local_2f = (&DAT_100457f0)[uVar17] + -1;
      }
      else {
        local_2f = (&DAT_100457f0)[(int)uVar17 >> 8] + '\a';
      }
    }
    else if ((char)(uVar17 >> 0x18) == '\0') {
      local_2f = (&DAT_100457f0)[(int)uVar17 >> 0x10] + '\x0f';
    }
    else {
      local_2f = (&DAT_100457f0)[(int)uVar17 >> 0x18] + '\x17';
    }
  }
  uVar17 = param_1[2] & (~(param_1[2] * 2) | 1U);
  if ((uVar17 & 0xffff0000) == 0) {
    if ((char)(uVar17 >> 8) == '\0') {
      cVar12 = (&DAT_100457f0)[uVar17] + -1;
    }
    else {
      cVar12 = (&DAT_100457f0)[uVar17 >> 8] + '\a';
    }
  }
  else if ((uVar17 & 0xff000000) == 0) {
    cVar12 = (&DAT_100457f0)[uVar17 >> 0x10] + '\x0f';
  }
  else {
    cVar12 = (&DAT_100457f0)[uVar17 >> 0x18] + '\x17';
  }
  cVar12 = local_2f - cVar12;
  uVar17 = puVar6[2];
  if ((uVar17 & 0xffff0000) == 0) {
    if ((char)(uVar17 >> 8) == '\0') {
      cVar13 = (&DAT_100457f0)[uVar17] + -1;
    }
    else {
      cVar13 = (&DAT_100457f0)[(int)uVar17 >> 8] + '\a';
    }
  }
  else if ((char)(uVar17 >> 0x18) == '\0') {
    cVar13 = (&DAT_100457f0)[(int)uVar17 >> 0x10] + '\x0f';
  }
  else {
    cVar13 = (&DAT_100457f0)[(int)uVar17 >> 0x18] + '\x17';
  }
  uVar17 = (~(uVar17 * 2) | 1) & uVar17;
  if ((uVar17 & 0xffff0000) == 0) {
    if ((char)(uVar17 >> 8) == '\0') {
      local_34 = (&DAT_100457f0)[uVar17] + -1;
    }
    else {
      local_34 = (&DAT_100457f0)[uVar17 >> 8] + '\a';
    }
  }
  else if ((uVar17 & 0xff000000) == 0) {
    local_34 = (&DAT_100457f0)[uVar17 >> 0x10] + '\x0f';
  }
  else {
    local_34 = (&DAT_100457f0)[uVar17 >> 0x18] + '\x17';
  }
  local_34 = (cVar13 - cVar12) - local_34;
  local_2f = local_2f - cVar13;
  bVar24 = -1 < (char)local_2f;
  if (!bVar24) {
    local_2f = -local_2f;
  }
  if (iVar19 == 1) {
    local_2e = '\a';
  }
  else {
    uVar17 = param_1[3];
    if ((uVar17 & 0xffff0000) == 0) {
      if ((char)(uVar17 >> 8) == '\0') {
        local_2e = (&DAT_100457f0)[uVar17] + -1;
      }
      else {
        local_2e = (&DAT_100457f0)[(int)uVar17 >> 8] + '\a';
      }
    }
    else if ((char)(uVar17 >> 0x18) == '\0') {
      local_2e = (&DAT_100457f0)[(int)uVar17 >> 0x10] + '\x0f';
    }
    else {
      local_2e = (&DAT_100457f0)[(int)uVar17 >> 0x18] + '\x17';
    }
  }
  uVar17 = param_1[3] & (~(param_1[3] * 2) | 1U);
  if ((uVar17 & 0xffff0000) == 0) {
    if ((char)(uVar17 >> 8) == '\0') {
      cVar13 = (&DAT_100457f0)[uVar17] + -1;
    }
    else {
      cVar13 = (&DAT_100457f0)[uVar17 >> 8] + '\a';
    }
  }
  else if ((uVar17 & 0xff000000) == 0) {
    cVar13 = (&DAT_100457f0)[uVar17 >> 0x10] + '\x0f';
  }
  else {
    cVar13 = (&DAT_100457f0)[uVar17 >> 0x18] + '\x17';
  }
  uVar17 = puVar6[3];
  cVar13 = local_2e - cVar13;
  if ((uVar17 & 0xffff0000) == 0) {
    if ((char)(uVar17 >> 8) == '\0') {
      cVar14 = (&DAT_100457f0)[uVar17] + -1;
    }
    else {
      cVar14 = (&DAT_100457f0)[(int)uVar17 >> 8] + '\a';
    }
  }
  else if ((char)(uVar17 >> 0x18) == '\0') {
    cVar14 = (&DAT_100457f0)[(int)uVar17 >> 0x10] + '\x0f';
  }
  else {
    cVar14 = (&DAT_100457f0)[(int)uVar17 >> 0x18] + '\x17';
  }
  uVar17 = (~(uVar17 * 2) | 1) & uVar17;
  if ((uVar17 & 0xffff0000) == 0) {
    if ((char)(uVar17 >> 8) == '\0') {
      cVar3 = (&DAT_100457f0)[uVar17] + -1;
    }
    else {
      cVar3 = (&DAT_100457f0)[uVar17 >> 8] + '\a';
    }
  }
  else if ((uVar17 & 0xff000000) == 0) {
    cVar3 = (&DAT_100457f0)[uVar17 >> 0x10] + '\x0f';
  }
  else {
    cVar3 = (&DAT_100457f0)[uVar17 >> 0x18] + '\x17';
  }
  local_33 = (cVar14 - cVar3) - cVar13;
  local_2e = local_2e - cVar14;
  bVar25 = -1 < (char)local_2e;
  if (!bVar25) {
    local_2e = -local_2e;
  }
  if (iVar19 == 1) {
    local_2d = '\a';
  }
  else {
    uVar17 = param_1[4];
    if ((uVar17 & 0xffff0000) == 0) {
      if ((char)(uVar17 >> 8) == '\0') {
        local_2d = (&DAT_100457f0)[uVar17] + -1;
      }
      else {
        local_2d = (&DAT_100457f0)[(int)uVar17 >> 8] + '\a';
      }
    }
    else if ((char)(uVar17 >> 0x18) == '\0') {
      local_2d = (&DAT_100457f0)[(int)uVar17 >> 0x10] + '\x0f';
    }
    else {
      local_2d = (&DAT_100457f0)[(int)uVar17 >> 0x18] + '\x17';
    }
  }
  uVar17 = param_1[4] & (~(param_1[4] * 2) | 1U);
  if ((uVar17 & 0xffff0000) == 0) {
    if ((char)(uVar17 >> 8) == '\0') {
      cVar14 = (&DAT_100457f0)[uVar17] + -1;
    }
    else {
      cVar14 = (&DAT_100457f0)[uVar17 >> 8] + '\a';
    }
  }
  else if ((uVar17 & 0xff000000) == 0) {
    cVar14 = (&DAT_100457f0)[uVar17 >> 0x10] + '\x0f';
  }
  else {
    cVar14 = (&DAT_100457f0)[uVar17 >> 0x18] + '\x17';
  }
  uVar17 = puVar6[4];
  cVar14 = local_2d - cVar14;
  cVar22 = (char)(uVar17 >> 8);
  cVar3 = (char)(uVar17 >> 0x18);
  if ((uVar17 & 0xffff0000) == 0) {
    if (cVar22 == '\0') {
      cVar4 = (&DAT_100457f0)[uVar17] + -1;
    }
    else {
      cVar4 = (&DAT_100457f0)[(int)uVar17 >> 8] + '\a';
    }
  }
  else if (cVar3 == '\0') {
    cVar4 = (&DAT_100457f0)[(int)uVar17 >> 0x10] + '\x0f';
  }
  else {
    cVar4 = (&DAT_100457f0)[(int)uVar17 >> 0x18] + '\x17';
  }
  uVar18 = (~(uVar17 * 2) | 1) & uVar17;
  if ((uVar18 & 0xffff0000) == 0) {
    if ((char)(uVar18 >> 8) == '\0') {
      cVar15 = (&DAT_100457f0)[uVar18] + -1;
    }
    else {
      cVar15 = (&DAT_100457f0)[uVar18 >> 8] + '\a';
    }
  }
  else if ((uVar18 & 0xff000000) == 0) {
    cVar15 = (&DAT_100457f0)[uVar18 >> 0x10] + '\x0f';
  }
  else {
    cVar15 = (&DAT_100457f0)[uVar18 >> 0x18] + '\x17';
  }
  local_32 = (cVar4 - cVar15) - cVar14;
  local_2d = local_2d - cVar4;
  bVar26 = -1 < (char)local_2d;
  if (!bVar26) {
    local_2d = -local_2d;
  }
  if (iVar19 == 1) {
    local_30 = '\a';
  }
  else {
    uVar18 = param_1[5];
    if ((uVar18 & 0xffff0000) == 0) {
      if ((char)(uVar18 >> 8) == '\0') {
        local_30 = (&DAT_100457f0)[uVar18] + -1;
      }
      else {
        local_30 = (&DAT_100457f0)[(int)uVar18 >> 8] + '\a';
      }
    }
    else if ((char)(uVar18 >> 0x18) == '\0') {
      local_30 = (&DAT_100457f0)[(int)uVar18 >> 0x10] + '\x0f';
    }
    else {
      local_30 = (&DAT_100457f0)[(int)uVar18 >> 0x18] + '\x17';
    }
  }
  uVar18 = param_1[5] & (~(param_1[5] * 2) | 1U);
  if ((uVar18 & 0xffff0000) == 0) {
    if ((char)(uVar18 >> 8) == '\0') {
      cVar4 = (&DAT_100457f0)[uVar18] + -1;
    }
    else {
      cVar4 = (&DAT_100457f0)[uVar18 >> 8] + '\a';
    }
  }
  else if ((uVar18 & 0xff000000) == 0) {
    cVar4 = (&DAT_100457f0)[uVar18 >> 0x10] + '\x0f';
  }
  else {
    cVar4 = (&DAT_100457f0)[uVar18 >> 0x18] + '\x17';
  }
  uVar18 = puVar6[5];
  cVar4 = local_30 - cVar4;
  cVar21 = (char)(uVar18 >> 8);
  cVar15 = (char)(uVar18 >> 0x18);
  if ((uVar18 & 0xffff0000) == 0) {
    if (cVar21 == '\0') {
      cVar16 = (&DAT_100457f0)[uVar18] + -1;
    }
    else {
      cVar16 = (&DAT_100457f0)[(int)uVar18 >> 8] + '\a';
    }
  }
  else if (cVar15 == '\0') {
    cVar16 = (&DAT_100457f0)[(int)uVar18 >> 0x10] + '\x0f';
  }
  else {
    cVar16 = (&DAT_100457f0)[(int)uVar18 >> 0x18] + '\x17';
  }
  uVar7 = (~(uVar18 * 2) | 1) & uVar18;
  if ((uVar7 & 0xffff0000) == 0) {
    if ((char)(uVar7 >> 8) == '\0') {
      cVar5 = (&DAT_100457f0)[uVar7] + -1;
    }
    else {
      cVar5 = (&DAT_100457f0)[uVar7 >> 8] + '\a';
    }
  }
  else if ((uVar7 & 0xff000000) == 0) {
    cVar5 = (&DAT_100457f0)[uVar7 >> 0x10] + '\x0f';
  }
  else {
    cVar5 = (&DAT_100457f0)[uVar7 >> 0x18] + '\x17';
  }
  local_31 = (cVar16 - cVar5) - cVar4;
  local_2c = CONCAT31(local_2c._1_3_,local_31);
  local_30 = local_30 - cVar16;
  bVar27 = -1 < (char)local_30;
  if (!bVar27) {
    local_30 = -local_30;
  }
  if ((uVar18 & 0xffff0000) == 0) {
    if (cVar21 == '\0') {
      iVar19 = (char)(&DAT_100457f0)[uVar18] + -1;
    }
    else {
      iVar19 = (char)(&DAT_100457f0)[(int)uVar18 >> 8] + 7;
    }
  }
  else if (cVar15 == '\0') {
    iVar19 = (char)(&DAT_100457f0)[(int)uVar18 >> 0x10] + 0xf;
  }
  else {
    iVar19 = (char)(&DAT_100457f0)[(int)uVar18 >> 0x18] + 0x17;
  }
  if ((uVar17 & 0xffff0000) == 0) {
    if (cVar22 == '\0') {
      local_1c = (char)(&DAT_100457f0)[uVar17] + -1;
    }
    else {
      local_1c = (char)(&DAT_100457f0)[(int)uVar17 >> 8] + 7;
    }
  }
  else if (cVar3 == '\0') {
    local_1c = (char)(&DAT_100457f0)[(int)uVar17 >> 0x10] + 0xf;
  }
  else {
    local_1c = (char)(&DAT_100457f0)[(int)uVar17 >> 0x18] + 0x17;
  }
  local_1c = local_1c - iVar19;
  bVar28 = -1 < local_1c;
  if (!bVar28) {
    local_1c = -local_1c;
  }
  if (*(code **)(DAT_100394fc + 0x298) != (code *)0x0) {
    if (((param_1[0x10] & 2U) != 0) &&
       (iVar19 = (**(code **)(DAT_100394fc + 0x298))(param_1), iVar19 == 0)) {
      return (undefined4 *)0x0;
    }
    if (((puVar6[0x10] & 2) != 0) &&
       (iVar19 = (**(code **)(DAT_100394fc + 0x298))(puVar6), iVar19 == 0)) {
      if (((param_1[0x10] & 2U) != 0) && (*(code **)(DAT_100394fc + 0x29c) != (code *)0x0)) {
        (**(code **)(DAT_100394fc + 0x29c))(param_1);
      }
      return (undefined4 *)0x0;
    }
  }
  iVar19 = puVar6[6];
  iVar1 = param_1[6];
  if (*param_1 == 1) {
    iVar2 = param_1[0xd];
    local_28 = 0;
    if (0 < param_1[8]) {
      do {
        pbVar20 = (byte *)(iVar1 + param_1[10] * local_28);
        iStack_18 = 0;
        puVar8 = (uint *)(iVar19 + puVar6[10] * local_28);
        if (0 < param_1[7]) {
          do {
            if (bVar24) {
              uVar17 = (uint)(*(byte *)((uint)*pbVar20 * 3 + iVar2) >> (local_2f & 0x1f)) &
                       puVar6[2];
            }
            else {
              uVar17 = (uint)*(byte *)((uint)*pbVar20 * 3 + iVar2) << (local_2f & 0x1f) & puVar6[2];
            }
            if (bVar25) {
              uVar18 = (uint)(*(byte *)((uint)*pbVar20 * 3 + 1 + iVar2) >> (local_2e & 0x1f)) &
                       puVar6[3];
            }
            else {
              local_2c = (uint)*(byte *)((uint)*pbVar20 * 3 + 1 + iVar2);
              uVar18 = local_2c << (local_2e & 0x1f) & puVar6[3];
            }
            if (bVar26) {
              uVar7 = (uint)(*(byte *)((uint)*pbVar20 * 3 + 2 + iVar2) >> (local_2d & 0x1f)) &
                      puVar6[4];
            }
            else {
              local_2c = (uint)*(byte *)((uint)*pbVar20 * 3 + 2 + iVar2);
              uVar7 = local_2c << (local_2d & 0x1f) & puVar6[4];
            }
            uVar7 = uVar17 | uVar18 | uVar7;
            if (puVar6[5] == 0) {
              if (uVar7 == 0) {
                uVar7 = ~puVar6[4] + 1 & puVar6[4];
              }
            }
            else if ((param_3 & 4) == 0) {
              uVar7 = uVar7 | puVar6[5];
            }
            else {
              if (bVar28) {
                uVar17 = (puVar6[4] & uVar7) >> ((byte)local_1c & 0x1f);
              }
              else {
                uVar17 = (puVar6[4] & uVar7) << ((byte)local_1c & 0x1f);
              }
              uVar7 = uVar7 | uVar17 & puVar6[5];
            }
            puVar9 = puVar8;
            switch(puVar6[1]) {
            case 8:
              *(char *)puVar8 = (char)uVar7;
              puVar9 = (uint *)((int)puVar8 + 1);
              break;
            case 0x10:
              *(short *)puVar8 = (short)uVar7;
              puVar9 = (uint *)((int)puVar8 + 2);
              break;
            case 0x18:
              puVar9 = (uint *)((int)puVar8 + 3);
              *(char *)puVar8 = (char)(uVar7 >> 0x10);
              *(char *)((int)puVar8 + 1) = (char)(uVar7 >> 8);
              *(char *)((int)puVar8 + 2) = (char)uVar7;
              break;
            case 0x20:
              *puVar8 = uVar7;
              puVar9 = puVar8 + 1;
            }
            pbVar20 = pbVar20 + 1;
            iStack_18 = iStack_18 + 1;
            puVar8 = puVar9;
          } while (iStack_18 < param_1[7]);
        }
        local_28 = local_28 + 1;
      } while (local_28 < param_1[8]);
    }
  }
  else {
    local_28 = 0;
    uVar17 = local_2c;
    if (0 < param_1[8]) {
      do {
        iStack_18 = 0;
        if (0 < param_1[7]) {
          puVar8 = (uint *)(iVar19 + puVar6[10] * local_28);
          puVar9 = (uint *)(iVar1 + param_1[10] * local_28);
          do {
            puVar23 = puVar9;
            switch(param_1[1]) {
            case 8:
              local_2c = (uint)(byte)*puVar9;
              puVar23 = (uint *)((int)puVar9 + 1);
              break;
            case 0x10:
              puVar23 = (uint *)((int)puVar9 + 2);
              local_2c = (uint)(ushort)*puVar9;
              break;
            case 0x18:
              puVar23 = (uint *)((int)puVar9 + 3);
              local_2c = (uint)(byte)*puVar9 << 0x10 | (uint)*(byte *)((int)puVar9 + 1) << 8 |
                         (uint)*(byte *)((int)puVar9 + 2);
              break;
            case 0x20:
              local_2c = *puVar9;
              puVar23 = puVar9 + 1;
            }
            if (bVar24) {
              uVar18 = (param_1[2] & local_2c) >> (local_2f & 0x1f);
              uVar7 = uVar18;
            }
            else {
              uVar18 = (param_1[2] & local_2c) << (local_2f & 0x1f);
              uVar7 = uVar18;
            }
            for (; '\0' < local_34; local_34 = local_34 - cVar12) {
              uVar18 = uVar18 | uVar7;
            }
            if (bVar25) {
              uVar7 = (param_1[3] & local_2c) >> (local_2e & 0x1f);
              uVar10 = uVar7;
            }
            else {
              uVar7 = (param_1[3] & local_2c) << (local_2e & 0x1f);
              uVar10 = uVar7;
            }
            for (; '\0' < local_33; local_33 = local_33 - cVar13) {
              uVar7 = uVar7 | uVar10;
            }
            if (bVar26) {
              uVar10 = (param_1[4] & local_2c) >> (local_2d & 0x1f);
              uVar11 = uVar10;
            }
            else {
              uVar10 = (param_1[4] & local_2c) << (local_2d & 0x1f);
              uVar11 = uVar10;
            }
            for (; '\0' < local_32; local_32 = local_32 - cVar14) {
              uVar10 = uVar10 | uVar11;
            }
            if ((param_3 & 8) != 0) {
              if (param_1[5] == 0) {
                uVar17 = (local_2c == 0) - 1;
              }
              else {
                uVar17 = local_2c & param_1[5];
                if (bVar27) {
                  uVar17 = uVar17 >> (local_30 & 0x1f);
                  uVar11 = uVar17;
                }
                else {
                  uVar17 = uVar17 << (local_30 & 0x1f);
                  uVar11 = uVar17;
                }
                for (; '\0' < local_31; local_31 = local_31 - cVar4) {
                  uVar17 = uVar17 | uVar11;
                }
              }
            }
            local_2c = (uVar10 & puVar6[4]) + (puVar6[3] & uVar7) + (puVar6[2] & uVar18);
            uVar18 = puVar6[5];
            if ((param_3 & 8) == 0) {
              if (uVar18 == 0) {
                if (local_2c == 0) {
                  local_2c = ~puVar6[4] + 1 & puVar6[4];
                }
              }
              else if ((param_3 & 4) == 0) {
                local_2c = local_2c | puVar6[5];
              }
              else {
                if (bVar28) {
                  uVar18 = (local_2c & puVar6[4]) >> ((byte)local_1c & 0x1f);
                }
                else {
                  uVar18 = (local_2c & puVar6[4]) << ((byte)local_1c & 0x1f);
                }
                local_2c = local_2c | uVar18 & puVar6[5];
              }
            }
            else if (uVar18 == 0) {
              if (uVar17 == 0) {
                local_2c = 0;
              }
            }
            else {
              local_2c = local_2c + (uVar18 & uVar17);
            }
            puVar9 = puVar8;
            switch(puVar6[1]) {
            case 8:
              *(char *)puVar8 = (char)local_2c;
              puVar9 = (uint *)((int)puVar8 + 1);
              break;
            case 0x10:
              *(short *)puVar8 = (short)local_2c;
              puVar9 = (uint *)((int)puVar8 + 2);
              break;
            case 0x18:
              puVar9 = (uint *)((int)puVar8 + 3);
              *(char *)puVar8 = (char)(local_2c >> 0x10);
              *(char *)((int)puVar8 + 1) = (char)(local_2c >> 8);
              *(char *)((int)puVar8 + 2) = (char)local_2c;
              break;
            case 0x20:
              *puVar8 = local_2c;
              puVar9 = puVar8 + 1;
            }
            iStack_18 = iStack_18 + 1;
            puVar8 = puVar9;
            puVar9 = puVar23;
          } while (iStack_18 < param_1[7]);
        }
        local_28 = local_28 + 1;
      } while (local_28 < param_1[8]);
    }
  }
  if (*(code **)(DAT_100394fc + 0x29c) != (code *)0x0) {
    if ((param_1[0x10] & 2U) != 0) {
      (**(code **)(DAT_100394fc + 0x29c))(param_1);
    }
    if ((puVar6[0x10] & 2) != 0) {
      (**(code **)(DAT_100394fc + 0x29c))(puVar6);
    }
  }
  return puVar6;
}


