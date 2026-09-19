// 10050140 FUN_10050140 [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10050140(uint *param_1)

{
  ushort uVar1;
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
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  byte bVar25;
  bool bVar26;
  ushort *local_7c;
  ushort *local_74;
  ushort *local_70;
  ushort *local_6c;
  uint local_68;
  int local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  int local_50;
  int local_4c;
  uint local_48;
  uint local_3c;
  
  uVar2 = param_1[0xc];
  uVar19 = *param_1;
  uVar21 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar19 = uVar19 + uVar3;
    uVar21 = uVar21 + uVar4;
    local_60 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = param_1[0x10] + param_1[0x11];
    uVar13 = param_1[0x45];
    param_1[0x19] = local_60;
    uVar14 = param_1[0x43];
    param_1[0x43] = uVar14 + param_1[0x44];
    local_3c = param_1[0x4b] + param_1[0x4c];
    param_1[0x45] = uVar13 + param_1[0x46];
    param_1[0x4b] = local_3c;
    local_48 = (int)(uVar14 + param_1[0x44]) / (int)(local_3c >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4e] = local_48;
    local_54 = (int)(uVar13 + param_1[0x46]) / (int)(local_3c >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4f] = local_54;
    uVar13 = param_1[0x47];
    uVar14 = param_1[0x49];
    param_1[0x47] = uVar13 + param_1[0x48];
    param_1[0x49] = param_1[0x4a] + uVar14;
    uVar20 = param_1[0x50] + param_1[0x51];
    param_1[0x50] = uVar20;
    uVar13 = (int)(uVar13 + param_1[0x48]) / (int)(uVar20 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x53] = uVar13;
    uVar14 = (int)(param_1[0x4a] + uVar14) / (int)(uVar20 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x54] = uVar14;
    iVar15 = (int)uVar19 >> 0x10;
    iVar16 = (int)uVar21 >> 0x10;
    local_64 = iVar15 - iVar16;
    if (local_64 < 0) {
      uVar23 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar22 = 0xdead;
      local_68 = 0xdead;
      local_5c = 0xdead;
      local_50 = 0xdead;
      local_4c = 0xdead;
      bVar25 = uVar6 != 0;
      uVar18 = uVar20;
      if ((bool)bVar25) {
        uVar18 = local_3c;
        local_3c = uVar20;
      }
      if (((int)(uVar18 - local_3c) < 1) && (((uVar18 ^ local_3c) & 0xffc00000) != 0)) {
        uVar20 = uVar14;
        uVar23 = uVar13;
        local_5c = local_54;
        if (uVar6 != 0) {
          uVar20 = local_54;
          uVar23 = local_48;
          local_5c = uVar14;
          local_48 = uVar13;
        }
        local_54 = local_5c;
        fVar11 = (float)(int)(local_3c - uVar18) * (float)(int)(local_3c - uVar18) * _DAT_10078114;
        fVar7 = (float)(int)local_3c * (float)-local_64;
        fVar8 = (float)(int)(uVar18 - local_3c) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar24 = uVar23 - local_48;
        bVar26 = false;
        if (uVar23 == local_48) {
          uVar23 = uVar23 + 1;
          iVar24 = uVar23 - local_48;
          bVar26 = uVar23 == local_48;
        }
        if (bVar26 || SBORROW4(uVar23,local_48) != iVar24 < 0) {
          iVar24 = local_48 - uVar23;
          bVar25 = bVar25 | 2;
        }
        else {
          iVar24 = uVar23 - local_48;
        }
        fVar10 = (float)(int)uVar18 * fVar7 * (float)iVar24;
        iVar24 = uVar20 - local_5c;
        bVar26 = false;
        if (uVar20 == local_5c) {
          uVar20 = uVar20 + 1;
          iVar24 = uVar20 - local_5c;
          bVar26 = uVar20 == local_5c;
        }
        if (bVar26 || SBORROW4(uVar20,local_5c) != iVar24 < 0) {
          iVar24 = local_5c - uVar20;
          bVar25 = bVar25 | 4;
        }
        else {
          iVar24 = uVar20 - local_5c;
        }
        fVar7 = (float)(int)uVar18 * fVar7 * (float)iVar24;
        fVar8 = -(fVar8 * _DAT_10078114 + fVar11);
        uVar14 = (uint)fVar9 | 0xff800000;
        uVar23 = uVar14 << 8;
        uVar13 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar22 = (uint)*(byte *)(((uVar14 & 0xffffff) >> 0xf) + DAT_10079208);
        iVar24 = uVar13 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar24 < 0x20) {
          local_68 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar24 & 0x1f);
        }
        else {
          local_68 = 0;
        }
        iVar24 = uVar13 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar24 < 0x20) {
          local_5c = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar24 & 0x1f);
        }
        else {
          local_5c = 0;
        }
        local_50 = DAT_1007920c +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10079208) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
        local_4c = DAT_1007920c +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10079208) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
      }
      else {
        bVar25 = 0x10;
        if (uVar6 == 0) {
          iVar24 = local_48 - uVar13;
          iVar17 = local_54 - uVar14;
        }
        else {
          iVar24 = uVar13 - local_48;
          iVar17 = uVar14 - local_54;
          local_54 = uVar14;
          local_48 = uVar13;
        }
        local_3c = (iVar24 * 0x100) / local_64 << 8;
        uVar18 = (iVar17 * 0x100) / local_64 << 8;
      }
      local_54 = local_54 << 0x10;
      local_58 = local_48 << 0x10;
      if ((bVar25 & 0x10) == 0) {
        if (uVar6 == 0) {
          iVar15 = param_1[7] + iVar16 * 2;
          uVar13 = *(uint *)(DAT_10079224 + ((uVar19 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar16 = param_1[5] + iVar16 * 2;
          switch(bVar25) {
          case 0:
            local_74 = (ushort *)(iVar16 + local_64 * 2);
            local_70 = (ushort *)(iVar15 + local_64 * 2);
            do {
              local_58 = local_58 + *(int *)(local_50 + uVar22 * 4);
              local_54 = local_54 + *(int *)(local_4c + uVar22 * 4);
              uVar23 = uVar23 - local_68;
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                local_68 = local_68 * 2;
                local_5c = local_5c * 2;
                local_50 = local_50 + -0x400;
                local_4c = local_4c + -0x400;
              }
              uVar12 = (ushort)(local_60 >> 0x10);
              if (*local_70 < uVar12) {
                uVar1 = *(ushort *)
                         (((((int)(char)~((byte)uVar13 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                           (int)(char)(byte)uVar13 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
                if (uVar1 != 0) {
                  *local_74 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                              (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                              (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
                  *local_70 = uVar12;
                }
              }
              local_60 = local_60 + param_1[0x1b];
              local_68 = local_68 - local_5c;
              local_74 = local_74 + 1;
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar22 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10079208);
              local_70 = local_70 + 1;
              local_64 = local_64 + 1;
            } while (local_64 < 0);
            break;
          case 2:
            local_74 = (ushort *)(iVar16 + local_64 * 2);
            local_70 = (ushort *)(iVar15 + local_64 * 2);
            do {
              local_58 = local_58 - *(int *)(local_50 + uVar22 * 4);
              local_54 = local_54 + *(int *)(local_4c + uVar22 * 4);
              uVar23 = uVar23 - local_68;
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                local_68 = local_68 * 2;
                local_5c = local_5c * 2;
                local_50 = local_50 + -0x400;
                local_4c = local_4c + -0x400;
              }
              uVar12 = (ushort)(local_60 >> 0x10);
              if (*local_70 < uVar12) {
                uVar1 = *(ushort *)
                         (((((int)(char)~((byte)uVar13 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                           (int)(char)(byte)uVar13 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
                if (uVar1 != 0) {
                  *local_74 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                              (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                              (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
                  *local_70 = uVar12;
                }
              }
              local_60 = local_60 + param_1[0x1b];
              local_68 = local_68 - local_5c;
              local_74 = local_74 + 1;
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar22 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10079208);
              local_70 = local_70 + 1;
              local_64 = local_64 + 1;
            } while (local_64 < 0);
            break;
          case 4:
            local_74 = (ushort *)(iVar16 + local_64 * 2);
            local_70 = (ushort *)(iVar15 + local_64 * 2);
            do {
              local_58 = local_58 + *(int *)(local_50 + uVar22 * 4);
              local_54 = local_54 - *(int *)(local_4c + uVar22 * 4);
              uVar23 = uVar23 - local_68;
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                local_68 = local_68 * 2;
                local_5c = local_5c * 2;
                local_50 = local_50 + -0x400;
                local_4c = local_4c + -0x400;
              }
              uVar12 = (ushort)(local_60 >> 0x10);
              if (*local_70 < uVar12) {
                uVar1 = *(ushort *)
                         (((((int)(char)~((byte)uVar13 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                           (int)(char)(byte)uVar13 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
                if (uVar1 != 0) {
                  *local_74 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                              (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                              (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
                  *local_70 = uVar12;
                }
              }
              local_60 = local_60 + param_1[0x1b];
              local_68 = local_68 - local_5c;
              local_74 = local_74 + 1;
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar22 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10079208);
              local_70 = local_70 + 1;
              local_64 = local_64 + 1;
            } while (local_64 < 0);
            break;
          case 6:
            local_74 = (ushort *)(iVar16 + local_64 * 2);
            local_70 = (ushort *)(iVar15 + local_64 * 2);
            do {
              local_58 = local_58 - *(int *)(local_50 + uVar22 * 4);
              local_54 = local_54 - *(int *)(local_4c + uVar22 * 4);
              uVar23 = uVar23 - local_68;
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                local_68 = local_68 * 2;
                local_5c = local_5c * 2;
                local_50 = local_50 + -0x400;
                local_4c = local_4c + -0x400;
              }
              uVar12 = (ushort)(local_60 >> 0x10);
              if (*local_70 < uVar12) {
                uVar1 = *(ushort *)
                         (((((int)(char)~((byte)uVar13 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                           (int)(char)(byte)uVar13 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
                if (uVar1 != 0) {
                  *local_74 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                              (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                              (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
                  *local_70 = uVar12;
                }
              }
              local_60 = local_60 + param_1[0x1b];
              local_68 = local_68 - local_5c;
              local_74 = local_74 + 1;
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar22 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10079208);
              local_70 = local_70 + 1;
              local_64 = local_64 + 1;
            } while (local_64 < 0);
          }
        }
        else {
          iVar16 = param_1[7] + iVar15 * 2;
          uVar13 = *(uint *)(DAT_1007922c + ((uVar21 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar15 = param_1[5] + iVar15 * 2;
          local_64 = -1 - local_64;
          switch(bVar25) {
          case 1:
            local_74 = (ushort *)(iVar15 + local_64 * 2);
            local_70 = (ushort *)(iVar16 + local_64 * 2);
            do {
              local_58 = local_58 + *(int *)(local_50 + uVar22 * 4);
              local_54 = local_54 + *(int *)(local_4c + uVar22 * 4);
              uVar23 = uVar23 - local_68;
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                local_68 = local_68 * 2;
                local_5c = local_5c * 2;
                local_50 = local_50 + -0x400;
                local_4c = local_4c + -0x400;
              }
              uVar12 = (ushort)(local_60 >> 0x10);
              if (*local_70 < uVar12) {
                uVar1 = *(ushort *)
                         (((((int)(char)~((byte)uVar13 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                           (int)(char)(byte)uVar13 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
                if (uVar1 != 0) {
                  *local_74 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                              (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                              (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
                  *local_70 = uVar12;
                }
              }
              local_60 = local_60 + param_1[0x1b];
              local_68 = local_68 - local_5c;
              local_74 = local_74 + -1;
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar22 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10079208);
              local_70 = local_70 + -1;
              local_64 = local_64 + -1;
            } while (-1 < local_64);
            break;
          case 3:
            local_74 = (ushort *)(local_64 * 2 + iVar15);
            local_70 = (ushort *)(iVar16 + local_64 * 2);
            do {
              local_58 = local_58 - *(int *)(local_50 + uVar22 * 4);
              local_54 = local_54 + *(int *)(local_4c + uVar22 * 4);
              uVar23 = uVar23 - local_68;
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                local_68 = local_68 * 2;
                local_5c = local_5c * 2;
                local_50 = local_50 + -0x400;
                local_4c = local_4c + -0x400;
              }
              uVar12 = (ushort)(local_60 >> 0x10);
              if (*local_70 < uVar12) {
                uVar1 = *(ushort *)
                         (((((int)(char)~((byte)uVar13 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                           (int)(char)(byte)uVar13 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
                if (uVar1 != 0) {
                  *local_74 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                              (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                              (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
                  *local_70 = uVar12;
                }
              }
              local_60 = local_60 + param_1[0x1b];
              local_68 = local_68 - local_5c;
              local_74 = local_74 + -1;
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar22 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10079208);
              local_70 = local_70 + -1;
              local_64 = local_64 + -1;
            } while (-1 < local_64);
            break;
          case 5:
            local_74 = (ushort *)(local_64 * 2 + iVar15);
            local_70 = (ushort *)(iVar16 + local_64 * 2);
            do {
              local_58 = local_58 + *(int *)(local_50 + uVar22 * 4);
              local_54 = local_54 - *(int *)(local_4c + uVar22 * 4);
              uVar23 = uVar23 - local_68;
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                local_68 = local_68 * 2;
                local_5c = local_5c * 2;
                local_50 = local_50 + -0x400;
                local_4c = local_4c + -0x400;
              }
              uVar12 = (ushort)(local_60 >> 0x10);
              if (*local_70 < uVar12) {
                uVar1 = *(ushort *)
                         (((((int)(char)~((byte)uVar13 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                           (int)(char)(byte)uVar13 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
                if (uVar1 != 0) {
                  *local_74 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                              (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                              (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
                  *local_70 = uVar12;
                }
              }
              local_60 = local_60 + param_1[0x1b];
              local_68 = local_68 - local_5c;
              local_74 = local_74 + -1;
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar22 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10079208);
              local_70 = local_70 + -1;
              local_64 = local_64 + -1;
            } while (-1 < local_64);
            break;
          case 7:
            local_74 = (ushort *)(local_64 * 2 + iVar15);
            local_70 = (ushort *)(iVar16 + local_64 * 2);
            do {
              local_58 = local_58 - *(int *)(local_50 + uVar22 * 4);
              local_54 = local_54 - *(int *)(local_4c + uVar22 * 4);
              uVar23 = uVar23 - local_68;
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                local_68 = local_68 * 2;
                local_5c = local_5c * 2;
                local_50 = local_50 + -0x400;
                local_4c = local_4c + -0x400;
              }
              uVar12 = (ushort)(local_60 >> 0x10);
              if (*local_70 < uVar12) {
                uVar1 = *(ushort *)
                         (((((int)(char)~((byte)uVar13 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                           (int)(char)(byte)uVar13 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
                if (uVar1 != 0) {
                  *local_74 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                              (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                              (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
                  *local_70 = uVar12;
                }
              }
              local_60 = local_60 + param_1[0x1b];
              local_68 = local_68 - local_5c;
              local_74 = local_74 + -1;
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar22 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10079208);
              local_70 = local_70 + -1;
              local_64 = local_64 + -1;
            } while (-1 < local_64);
          }
        }
      }
      else if (uVar6 == 0) {
        local_74 = (ushort *)
                   (*(uint *)(DAT_10079224 + ((uVar19 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9]);
        local_7c = (ushort *)(param_1[5] + iVar16 * 2 + local_64 * 2);
        local_6c = (ushort *)(param_1[7] + iVar16 * 2 + local_64 * 2);
        do {
          uVar12 = (ushort)(local_60 >> 0x10);
          if (*local_6c < uVar12) {
            uVar1 = *(ushort *)
                     (((((int)(char)~((byte)local_74 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                       (int)(char)(byte)local_74 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
            if (uVar1 != 0) {
              *local_7c = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                          (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                          (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              *local_6c = uVar12;
            }
          }
          local_60 = local_60 + param_1[0x1b];
          local_74 = (ushort *)((uint)local_74 ^ (uint)local_74 >> 6);
          local_58 = local_58 + local_3c;
          local_54 = local_54 + uVar18;
          local_7c = local_7c + 1;
          local_6c = local_6c + 1;
          local_64 = local_64 + 1;
        } while (local_64 < 0);
      }
      else {
        local_74 = (ushort *)
                   (*(uint *)(DAT_1007922c + ((uVar21 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9]);
        local_64 = -1 - local_64;
        local_6c = (ushort *)(param_1[7] + iVar15 * 2 + local_64 * 2);
        local_7c = (ushort *)(param_1[5] + iVar15 * 2 + local_64 * 2);
        do {
          uVar12 = (ushort)(local_60 >> 0x10);
          if (*local_6c < uVar12) {
            uVar1 = *(ushort *)
                     (((((int)(char)~((byte)local_74 ^ 0x55) + (local_58 >> 0x10) & 0x1e00) >> 4 |
                       (int)(char)(byte)local_74 + (local_54 >> 0x10) & 0x1e00) >> 4) + uVar2);
            if (uVar1 != 0) {
              *local_7c = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                          (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                          (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              *local_6c = uVar12;
            }
          }
          local_60 = local_60 + param_1[0x1b];
          local_74 = (ushort *)((uint)local_74 ^ (uint)local_74 >> 6);
          local_58 = local_58 + local_3c;
          local_54 = local_54 + uVar18;
          local_7c = local_7c + -1;
          local_6c = local_6c + -1;
          local_64 = local_64 + -1;
        } while (-1 < local_64);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar19;
  param_1[1] = uVar21;
  return;
}


