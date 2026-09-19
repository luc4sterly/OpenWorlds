// 1004dca0 FUN_1004dca0 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1004dca0(uint *param_1)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  ushort uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  uint uVar24;
  ushort *puVar25;
  uint uVar26;
  byte bVar27;
  bool bVar28;
  short *local_74;
  ushort *local_70;
  int local_6c;
  uint local_68;
  short *local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  int local_54;
  int local_50;
  uint local_40;
  
  uVar2 = param_1[0xc];
  uVar18 = *param_1;
  uVar21 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar18 = uVar18 + uVar3;
    uVar21 = uVar21 + uVar4;
    local_68 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = param_1[0x10] + param_1[0x11];
    uVar12 = param_1[0x45];
    param_1[0x19] = local_68;
    uVar13 = param_1[0x43];
    param_1[0x45] = uVar12 + param_1[0x46];
    param_1[0x43] = uVar13 + param_1[0x44];
    local_40 = param_1[0x4b] + param_1[0x4c];
    param_1[0x4b] = local_40;
    local_60 = (int)(uVar13 + param_1[0x44]) / (int)(local_40 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4e] = local_60;
    local_70 = (ushort *)
               ((int)(uVar12 + param_1[0x46]) / (int)(local_40 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f));
    param_1[0x4f] = (uint)local_70;
    uVar12 = param_1[0x47];
    uVar13 = param_1[0x49];
    param_1[0x47] = uVar12 + param_1[0x48];
    uVar19 = param_1[0x51] + param_1[0x50];
    param_1[0x49] = param_1[0x4a] + uVar13;
    param_1[0x50] = uVar19;
    uVar12 = (int)(uVar12 + param_1[0x48]) / (int)(uVar19 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x53] = uVar12;
    uVar13 = (int)(param_1[0x4a] + uVar13) / (int)(uVar19 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x54] = uVar13;
    iVar14 = (int)uVar18 >> 0x10;
    iVar15 = (int)uVar21 >> 0x10;
    local_6c = iVar14 - iVar15;
    if (local_6c < 0) {
      uVar24 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar26 = 0xdead;
      uVar22 = 0xdead;
      local_58 = 0xdead;
      local_54 = 0xdead;
      local_50 = 0xdead;
      bVar27 = uVar6 != 0;
      uVar17 = uVar19;
      if ((bool)bVar27) {
        uVar17 = local_40;
        local_40 = uVar19;
      }
      if (((int)(uVar17 - local_40) < 1) && (((uVar17 ^ local_40) & 0xffc00000) != 0)) {
        uVar19 = uVar12;
        uVar24 = uVar13;
        if (uVar6 != 0) {
          uVar19 = local_60;
          local_60 = uVar12;
          uVar24 = (uint)local_70;
          local_70 = (ushort *)uVar13;
        }
        fVar11 = (float)(int)(local_40 - uVar17) * (float)(int)(local_40 - uVar17) * _DAT_10078114;
        fVar7 = (float)(int)local_40 * (float)-local_6c;
        fVar8 = (float)(int)(uVar17 - local_40) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar23 = uVar19 - local_60;
        bVar28 = false;
        if (uVar19 == local_60) {
          uVar19 = uVar19 + 1;
          iVar23 = uVar19 - local_60;
          bVar28 = uVar19 == local_60;
        }
        if (bVar28 || SBORROW4(uVar19,local_60) != iVar23 < 0) {
          iVar23 = local_60 - uVar19;
          bVar27 = bVar27 | 2;
        }
        else {
          iVar23 = uVar19 - local_60;
        }
        fVar10 = (float)iVar23 * (float)(int)uVar17 * fVar7;
        iVar23 = uVar24 - (int)local_70;
        bVar28 = false;
        if ((ushort *)uVar24 == local_70) {
          uVar24 = uVar24 + 1;
          iVar23 = uVar24 - (int)local_70;
          bVar28 = (ushort *)uVar24 == local_70;
        }
        if (bVar28 || SBORROW4(uVar24,(int)local_70) != iVar23 < 0) {
          iVar23 = (int)local_70 - uVar24;
          bVar27 = bVar27 | 4;
        }
        else {
          iVar23 = uVar24 - (int)local_70;
        }
        fVar7 = (float)iVar23 * (float)(int)uVar17 * fVar7;
        fVar8 = -(fVar8 * _DAT_10078114 + fVar11);
        uVar13 = (uint)fVar9 | 0xff800000;
        uVar24 = uVar13 << 8;
        uVar12 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar22 = (uint)*(byte *)(((uVar13 & 0xffffff) >> 0xf) + DAT_10079208);
        iVar23 = uVar12 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar23 < 0x20) {
          uVar26 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar23 & 0x1f);
        }
        else {
          uVar26 = 0;
        }
        iVar23 = uVar12 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar23 < 0x20) {
          local_58 = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar23 & 0x1f);
        }
        else {
          local_58 = 0;
        }
        local_54 = DAT_1007920c +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10079208) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
        local_50 = DAT_1007920c +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10079208) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
      }
      else {
        bVar27 = 0x10;
        if (uVar6 == 0) {
          iVar23 = local_60 - uVar12;
          iVar16 = (int)local_70 - uVar13;
        }
        else {
          iVar23 = uVar12 - local_60;
          iVar16 = uVar13 - (int)local_70;
          local_70 = (ushort *)uVar13;
          local_60 = uVar12;
        }
        local_40 = (iVar23 * 0x100) / local_6c << 8;
        uVar17 = (iVar16 * 0x100) / local_6c << 8;
      }
      local_5c = (int)local_70 << 0x10;
      local_60 = local_60 << 0x10;
      if ((bVar27 & 0x10) == 0) {
        if (uVar6 == 0) {
          iVar14 = param_1[7] + iVar15 * 2;
          uVar12 = *(uint *)(DAT_10079224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar15 = param_1[5] + iVar15 * 2;
          switch(bVar27) {
          case 0:
            local_64 = (short *)(local_6c * 2 + iVar15);
            local_70 = (ushort *)(local_6c * 2 + iVar14);
            do {
              uVar24 = uVar24 - uVar26;
              local_60 = local_60 + *(int *)(local_54 + uVar22 * 4);
              local_5c = local_5c + *(int *)(local_50 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 * 2;
                local_54 = local_54 + -0x400;
                local_50 = local_50 + -0x400;
              }
              uVar20 = (ushort)(local_68 >> 0x10);
              if ((*local_70 < uVar20) &&
                 (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >> 4) +
                                    uVar2), sVar1 != 0)) {
                *local_64 = sVar1;
                *local_70 = uVar20;
              }
              uVar26 = uVar26 - local_58;
              local_68 = local_68 + param_1[0x1b];
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10079208);
              local_64 = local_64 + 1;
              local_70 = local_70 + 1;
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 2:
            local_64 = (short *)(local_6c * 2 + iVar15);
            local_70 = (ushort *)(local_6c * 2 + iVar14);
            do {
              uVar24 = uVar24 - uVar26;
              local_60 = local_60 - *(int *)(local_54 + uVar22 * 4);
              local_5c = local_5c + *(int *)(local_50 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 * 2;
                local_54 = local_54 + -0x400;
                local_50 = local_50 + -0x400;
              }
              uVar20 = (ushort)(local_68 >> 0x10);
              if ((*local_70 < uVar20) &&
                 (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >> 4) +
                                    uVar2), sVar1 != 0)) {
                *local_64 = sVar1;
                *local_70 = uVar20;
              }
              uVar26 = uVar26 - local_58;
              local_68 = local_68 + param_1[0x1b];
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10079208);
              local_64 = local_64 + 1;
              local_70 = local_70 + 1;
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 4:
            local_64 = (short *)(local_6c * 2 + iVar15);
            local_70 = (ushort *)(local_6c * 2 + iVar14);
            do {
              uVar24 = uVar24 - uVar26;
              local_60 = local_60 + *(int *)(local_54 + uVar22 * 4);
              local_5c = local_5c - *(int *)(local_50 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 * 2;
                local_54 = local_54 + -0x400;
                local_50 = local_50 + -0x400;
              }
              uVar20 = (ushort)(local_68 >> 0x10);
              if ((*local_70 < uVar20) &&
                 (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >> 4) +
                                    uVar2), sVar1 != 0)) {
                *local_64 = sVar1;
                *local_70 = uVar20;
              }
              uVar26 = uVar26 - local_58;
              local_68 = local_68 + param_1[0x1b];
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10079208);
              local_64 = local_64 + 1;
              local_70 = local_70 + 1;
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 6:
            local_64 = (short *)(local_6c * 2 + iVar15);
            local_70 = (ushort *)(local_6c * 2 + iVar14);
            do {
              uVar24 = uVar24 - uVar26;
              local_60 = local_60 - *(int *)(local_54 + uVar22 * 4);
              local_5c = local_5c - *(int *)(local_50 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 * 2;
                local_54 = local_54 + -0x400;
                local_50 = local_50 + -0x400;
              }
              uVar20 = (ushort)(local_68 >> 0x10);
              if ((*local_70 < uVar20) &&
                 (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >> 4) +
                                    uVar2), sVar1 != 0)) {
                *local_64 = sVar1;
                *local_70 = uVar20;
              }
              uVar26 = uVar26 - local_58;
              local_68 = local_68 + param_1[0x1b];
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10079208);
              local_64 = local_64 + 1;
              local_70 = local_70 + 1;
              local_6c = local_6c + 1;
            } while (local_6c < 0);
          }
        }
        else {
          iVar15 = param_1[7] + iVar14 * 2;
          uVar12 = *(uint *)(DAT_1007922c + ((uVar21 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar14 = param_1[5] + iVar14 * 2;
          local_6c = -1 - local_6c;
          switch(bVar27) {
          case 1:
            local_64 = (short *)(iVar14 + local_6c * 2);
            local_70 = (ushort *)(local_6c * 2 + iVar15);
            do {
              uVar24 = uVar24 - uVar26;
              local_60 = local_60 + *(int *)(local_54 + uVar22 * 4);
              local_5c = local_5c + *(int *)(local_50 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 * 2;
                local_54 = local_54 + -0x400;
                local_50 = local_50 + -0x400;
              }
              uVar20 = (ushort)(local_68 >> 0x10);
              if ((*local_70 < uVar20) &&
                 (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >> 4) +
                                    uVar2), sVar1 != 0)) {
                *local_64 = sVar1;
                *local_70 = uVar20;
              }
              uVar26 = uVar26 - local_58;
              local_68 = local_68 + param_1[0x1b];
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10079208);
              local_64 = local_64 + -1;
              local_70 = local_70 + -1;
              local_6c = local_6c + -1;
            } while (-1 < local_6c);
            break;
          case 3:
            local_64 = (short *)(iVar14 + local_6c * 2);
            local_70 = (ushort *)(local_6c * 2 + iVar15);
            do {
              uVar24 = uVar24 - uVar26;
              local_60 = local_60 - *(int *)(local_54 + uVar22 * 4);
              local_5c = local_5c + *(int *)(local_50 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 * 2;
                local_54 = local_54 + -0x400;
                local_50 = local_50 + -0x400;
              }
              uVar20 = (ushort)(local_68 >> 0x10);
              if ((*local_70 < uVar20) &&
                 (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >> 4) +
                                    uVar2), sVar1 != 0)) {
                *local_64 = sVar1;
                *local_70 = uVar20;
              }
              uVar26 = uVar26 - local_58;
              local_68 = local_68 + param_1[0x1b];
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10079208);
              local_64 = local_64 + -1;
              local_70 = local_70 + -1;
              local_6c = local_6c + -1;
            } while (-1 < local_6c);
            break;
          case 5:
            local_64 = (short *)(iVar14 + local_6c * 2);
            local_70 = (ushort *)(local_6c * 2 + iVar15);
            do {
              uVar24 = uVar24 - uVar26;
              local_60 = local_60 + *(int *)(local_54 + uVar22 * 4);
              local_5c = local_5c - *(int *)(local_50 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 * 2;
                local_54 = local_54 + -0x400;
                local_50 = local_50 + -0x400;
              }
              uVar20 = (ushort)(local_68 >> 0x10);
              if ((*local_70 < uVar20) &&
                 (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >> 4) +
                                    uVar2), sVar1 != 0)) {
                *local_64 = sVar1;
                *local_70 = uVar20;
              }
              uVar26 = uVar26 - local_58;
              local_68 = local_68 + param_1[0x1b];
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10079208);
              local_64 = local_64 + -1;
              local_70 = local_70 + -1;
              local_6c = local_6c + -1;
            } while (-1 < local_6c);
            break;
          case 7:
            local_64 = (short *)(iVar14 + local_6c * 2);
            local_70 = (ushort *)(local_6c * 2 + iVar15);
            do {
              uVar24 = uVar24 - uVar26;
              local_60 = local_60 - *(int *)(local_54 + uVar22 * 4);
              local_5c = local_5c - *(int *)(local_50 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 * 2;
                local_54 = local_54 + -0x400;
                local_50 = local_50 + -0x400;
              }
              uVar20 = (ushort)(local_68 >> 0x10);
              if ((*local_70 < uVar20) &&
                 (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >> 4) +
                                    uVar2), sVar1 != 0)) {
                *local_64 = sVar1;
                *local_70 = uVar20;
              }
              uVar26 = uVar26 - local_58;
              local_68 = local_68 + param_1[0x1b];
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10079208);
              local_64 = local_64 + -1;
              local_70 = local_70 + -1;
              local_6c = local_6c + -1;
            } while (-1 < local_6c);
          }
        }
      }
      else if (uVar6 == 0) {
        uVar12 = *(uint *)(DAT_10079224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        local_74 = (short *)(param_1[5] + iVar15 * 2 + local_6c * 2);
        puVar25 = (ushort *)(param_1[7] + iVar15 * 2 + local_6c * 2);
        do {
          uVar20 = (ushort)(local_68 >> 0x10);
          if ((*puVar25 < uVar20) &&
             (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >>
                                 4) + uVar2), sVar1 != 0)) {
            *local_74 = sVar1;
            *puVar25 = uVar20;
          }
          puVar25 = puVar25 + 1;
          local_68 = local_68 + param_1[0x1b];
          local_60 = local_60 + local_40;
          local_74 = local_74 + 1;
          uVar12 = uVar12 ^ uVar12 >> 6;
          local_5c = local_5c + uVar17;
          local_6c = local_6c + 1;
        } while (local_6c < 0);
      }
      else {
        uVar12 = *(uint *)(DAT_1007922c + ((uVar21 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        local_6c = -1 - local_6c;
        puVar25 = (ushort *)(param_1[7] + iVar14 * 2 + local_6c * 2);
        local_74 = (short *)(param_1[5] + iVar14 * 2 + local_6c * 2);
        do {
          uVar20 = (ushort)(local_68 >> 0x10);
          if ((*puVar25 < uVar20) &&
             (sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_60 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_5c >> 0x10) & 0x1e00) >>
                                 4) + uVar2), sVar1 != 0)) {
            *local_74 = sVar1;
            *puVar25 = uVar20;
          }
          puVar25 = puVar25 + -1;
          local_68 = local_68 + param_1[0x1b];
          local_60 = local_60 + local_40;
          local_74 = local_74 + -1;
          uVar12 = uVar12 ^ uVar12 >> 6;
          local_5c = local_5c + uVar17;
          local_6c = local_6c + -1;
        } while (-1 < local_6c);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar18;
  param_1[1] = uVar21;
  return;
}


