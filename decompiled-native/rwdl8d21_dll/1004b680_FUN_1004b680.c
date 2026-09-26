// 1004b680 FUN_1004b680 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1004b680(uint *param_1)

{
  char cVar1;
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
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  byte bVar25;
  bool bVar26;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  int local_5c;
  int local_58;
  int local_54;
  uint local_40;
  uint local_3c;
  
  uVar2 = param_1[0xc];
  uVar18 = *param_1;
  uVar21 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar18 = uVar18 + uVar3;
    uVar21 = uVar21 + uVar4;
    local_70 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = param_1[0x10] + param_1[0x11];
    uVar13 = param_1[0x45];
    param_1[0x19] = local_70;
    uVar14 = param_1[0x43];
    param_1[0x45] = uVar13 + param_1[0x46];
    param_1[0x43] = uVar14 + param_1[0x44];
    local_40 = param_1[0x4b] + param_1[0x4c];
    param_1[0x4b] = local_40;
    local_6c = (int)(uVar14 + param_1[0x44]) / (int)(local_40 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4e] = local_6c;
    local_68 = (int)(uVar13 + param_1[0x46]) / (int)(local_40 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4f] = local_68;
    uVar13 = param_1[0x47];
    uVar14 = param_1[0x49];
    param_1[0x47] = uVar13 + param_1[0x48];
    uVar19 = param_1[0x50] + param_1[0x51];
    param_1[0x49] = param_1[0x4a] + uVar14;
    param_1[0x50] = uVar19;
    uVar13 = (int)(uVar13 + param_1[0x48]) / (int)(uVar19 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x53] = uVar13;
    uVar14 = (int)(param_1[0x4a] + uVar14) / (int)(uVar19 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x54] = uVar14;
    iVar15 = (int)uVar18 >> 0x10;
    iVar16 = (int)uVar21 >> 0x10;
    local_54 = iVar15 - iVar16;
    if (local_54 < 0) {
      uVar24 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar23 = 0xdead;
      uVar22 = 0xdead;
      local_64 = 0xdead;
      local_5c = 0xdead;
      local_58 = 0xdead;
      bVar25 = uVar6 != 0;
      local_3c = uVar19;
      if ((bool)bVar25) {
        local_3c = local_40;
        local_40 = uVar19;
      }
      if (((int)(local_3c - local_40) < 1) && (((local_3c ^ local_40) & 0xffc00000) != 0)) {
        uVar19 = uVar14;
        uVar24 = uVar13;
        if (uVar6 != 0) {
          uVar19 = local_68;
          uVar24 = local_6c;
          local_68 = uVar14;
          local_6c = uVar13;
        }
        fVar11 = (float)(int)(local_40 - local_3c) * (float)(int)(local_40 - local_3c) *
                 _DAT_1007410c;
        fVar7 = (float)(int)local_40 * (float)-local_54;
        fVar8 = (float)(int)(local_3c - local_40) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar20 = uVar24 - local_6c;
        bVar26 = false;
        if (uVar24 == local_6c) {
          uVar24 = uVar24 + 1;
          iVar20 = uVar24 - local_6c;
          bVar26 = uVar24 == local_6c;
        }
        if (bVar26 || SBORROW4(uVar24,local_6c) != iVar20 < 0) {
          iVar20 = local_6c - uVar24;
          bVar25 = bVar25 | 2;
        }
        else {
          iVar20 = uVar24 - local_6c;
        }
        fVar10 = (float)(int)local_3c * fVar7 * (float)iVar20;
        iVar20 = uVar19 - local_68;
        bVar26 = false;
        if (uVar19 == local_68) {
          uVar19 = uVar19 + 1;
          iVar20 = uVar19 - local_68;
          bVar26 = uVar19 == local_68;
        }
        if (bVar26 || SBORROW4(uVar19,local_68) != iVar20 < 0) {
          iVar20 = local_68 - uVar19;
          bVar25 = bVar25 | 4;
        }
        else {
          iVar20 = uVar19 - local_68;
        }
        fVar7 = (float)(int)local_3c * fVar7 * (float)iVar20;
        fVar8 = -(fVar8 * _DAT_1007410c + fVar11);
        uVar14 = (uint)fVar9 | 0xff800000;
        uVar24 = uVar14 << 8;
        uVar13 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar22 = (uint)*(byte *)(((uVar14 & 0xffffff) >> 0xf) + DAT_10075208);
        iVar20 = uVar13 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar20 < 0x20) {
          uVar23 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar20 & 0x1f);
        }
        else {
          uVar23 = 0;
        }
        iVar20 = uVar13 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar20 < 0x20) {
          local_64 = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar20 & 0x1f);
        }
        else {
          local_64 = 0;
        }
        local_5c = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
        local_58 = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
      }
      else {
        bVar25 = 0x10;
        if (uVar6 == 0) {
          iVar20 = local_6c - uVar13;
          iVar17 = local_68 - uVar14;
        }
        else {
          iVar20 = uVar13 - local_6c;
          iVar17 = uVar14 - local_68;
          local_68 = uVar14;
          local_6c = uVar13;
        }
        local_3c = (iVar17 * 0x100) / local_54 << 8;
        local_40 = (iVar20 * 0x100) / local_54 << 8;
      }
      local_68 = local_68 << 0x10;
      local_6c = local_6c << 0x10;
      if ((bVar25 & 0x10) == 0) {
        if (uVar6 == 0) {
          iVar15 = param_1[7] + iVar16 * 2;
          uVar13 = *(uint *)(DAT_10075224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar16 = param_1[5] + iVar16;
          switch(bVar25) {
          case 0:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c + *(int *)(local_5c + uVar22 * 4);
              local_68 = local_68 + *(int *)(local_58 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              uVar12 = (ushort)(local_70 >> 0x10);
              if ((*(ushort *)(iVar15 + local_54 * 2) < uVar12) &&
                 (cVar1 = *(char *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_6c >> 0x10) &
                                      0x1e00) >> 4 |
                                     (int)(char)(byte)uVar13 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                                   uVar2), cVar1 != '\0')) {
                *(char *)(iVar16 + local_54) = cVar1;
                *(ushort *)(iVar15 + local_54 * 2) = uVar12;
              }
              local_70 = local_70 + param_1[0x1b];
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar23 = uVar23 - local_64;
              local_54 = local_54 + 1;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
            } while (local_54 < 0);
            break;
          case 2:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c - *(int *)(local_5c + uVar22 * 4);
              local_68 = local_68 + *(int *)(local_58 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              uVar12 = (ushort)(local_70 >> 0x10);
              if ((*(ushort *)(iVar15 + local_54 * 2) < uVar12) &&
                 (cVar1 = *(char *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_6c >> 0x10) &
                                      0x1e00) >> 4 |
                                     (int)(char)(byte)uVar13 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                                   uVar2), cVar1 != '\0')) {
                *(char *)(iVar16 + local_54) = cVar1;
                *(ushort *)(iVar15 + local_54 * 2) = uVar12;
              }
              local_70 = local_70 + param_1[0x1b];
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar23 = uVar23 - local_64;
              local_54 = local_54 + 1;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
            } while (local_54 < 0);
            break;
          case 4:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c + *(int *)(local_5c + uVar22 * 4);
              local_68 = local_68 - *(int *)(local_58 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              uVar12 = (ushort)(local_70 >> 0x10);
              if ((*(ushort *)(iVar15 + local_54 * 2) < uVar12) &&
                 (cVar1 = *(char *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_6c >> 0x10) &
                                      0x1e00) >> 4 |
                                     (int)(char)(byte)uVar13 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                                   uVar2), cVar1 != '\0')) {
                *(char *)(iVar16 + local_54) = cVar1;
                *(ushort *)(iVar15 + local_54 * 2) = uVar12;
              }
              local_70 = local_70 + param_1[0x1b];
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar23 = uVar23 - local_64;
              local_54 = local_54 + 1;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
            } while (local_54 < 0);
            break;
          case 6:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c - *(int *)(local_5c + uVar22 * 4);
              local_68 = local_68 - *(int *)(local_58 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              uVar12 = (ushort)(local_70 >> 0x10);
              if ((*(ushort *)(iVar15 + local_54 * 2) < uVar12) &&
                 (cVar1 = *(char *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_6c >> 0x10) &
                                      0x1e00) >> 4 |
                                     (int)(char)(byte)uVar13 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                                   uVar2), cVar1 != '\0')) {
                *(char *)(iVar16 + local_54) = cVar1;
                *(ushort *)(iVar15 + local_54 * 2) = uVar12;
              }
              local_70 = local_70 + param_1[0x1b];
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar23 = uVar23 - local_64;
              local_54 = local_54 + 1;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
            } while (local_54 < 0);
          }
        }
        else {
          iVar16 = param_1[7] + iVar15 * 2;
          local_74 = *(uint *)(DAT_1007522c + ((uVar21 & 0x70000) >> 0x10) * 4) ^
                     (uint)(byte)param_1[9];
          iVar15 = param_1[5] + iVar15;
          local_54 = -1 - local_54;
          switch(bVar25) {
          case 1:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c + *(int *)(local_5c + uVar22 * 4);
              local_68 = local_68 + *(int *)(local_58 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              uVar12 = (ushort)(local_70 >> 0x10);
              if (*(ushort *)(iVar16 + local_54 * 2) < uVar12) {
                cVar1 = *(char *)(((((int)(char)~((byte)local_74 ^ 0x55) + (local_6c >> 0x10) &
                                    0x1e00) >> 4 |
                                   (int)(char)(byte)local_74 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                                 uVar2);
                if (cVar1 != '\0') {
                  *(char *)(iVar15 + local_54) = cVar1;
                  *(ushort *)(iVar16 + local_54 * 2) = uVar12;
                }
              }
              uVar23 = uVar23 - local_64;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
              local_54 = local_54 + -1;
            } while (-1 < local_54);
            break;
          case 3:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c - *(int *)(local_5c + uVar22 * 4);
              local_68 = local_68 + *(int *)(local_58 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              uVar12 = (ushort)(local_70 >> 0x10);
              if (*(ushort *)(iVar16 + local_54 * 2) < uVar12) {
                cVar1 = *(char *)(((((int)(char)~((byte)local_74 ^ 0x55) + (local_6c >> 0x10) &
                                    0x1e00) >> 4 |
                                   (int)(char)(byte)local_74 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                                 uVar2);
                if (cVar1 != '\0') {
                  *(char *)(iVar15 + local_54) = cVar1;
                  *(ushort *)(iVar16 + local_54 * 2) = uVar12;
                }
              }
              uVar23 = uVar23 - local_64;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
              local_54 = local_54 + -1;
            } while (-1 < local_54);
            break;
          case 5:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c + *(int *)(local_5c + uVar22 * 4);
              local_68 = local_68 - *(int *)(local_58 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              uVar12 = (ushort)(local_70 >> 0x10);
              if (*(ushort *)(iVar16 + local_54 * 2) < uVar12) {
                cVar1 = *(char *)(((((int)(char)~((byte)local_74 ^ 0x55) + (local_6c >> 0x10) &
                                    0x1e00) >> 4 |
                                   (int)(char)(byte)local_74 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                                 uVar2);
                if (cVar1 != '\0') {
                  *(char *)(iVar15 + local_54) = cVar1;
                  *(ushort *)(iVar16 + local_54 * 2) = uVar12;
                }
              }
              uVar23 = uVar23 - local_64;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
              local_54 = local_54 + -1;
            } while (-1 < local_54);
            break;
          case 7:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c - *(int *)(local_5c + uVar22 * 4);
              local_68 = local_68 - *(int *)(local_58 + uVar22 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              uVar12 = (ushort)(local_70 >> 0x10);
              if (*(ushort *)(iVar16 + local_54 * 2) < uVar12) {
                cVar1 = *(char *)(((((int)(char)~((byte)local_74 ^ 0x55) + (local_6c >> 0x10) &
                                    0x1e00) >> 4 |
                                   (int)(char)(byte)local_74 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                                 uVar2);
                if (cVar1 != '\0') {
                  *(char *)(iVar15 + local_54) = cVar1;
                  *(ushort *)(iVar16 + local_54 * 2) = uVar12;
                }
              }
              uVar23 = uVar23 - local_64;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              uVar22 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
              local_54 = local_54 + -1;
            } while (-1 < local_54);
          }
        }
      }
      else if (uVar6 == 0) {
        uVar13 = param_1[5];
        iVar15 = param_1[7] + iVar16 * 2;
        uVar14 = *(uint *)(DAT_10075224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        do {
          uVar12 = (ushort)(local_70 >> 0x10);
          if ((*(ushort *)(iVar15 + local_54 * 2) < uVar12) &&
             (cVar1 = *(char *)(((((int)(char)~((byte)uVar14 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                  >> 4 | (int)(char)(byte)uVar14 + (local_68 >> 0x10) & 0x1e00) >> 5
                                ) + uVar2), cVar1 != '\0')) {
            *(char *)(uVar13 + iVar16 + local_54) = cVar1;
            *(ushort *)(iVar15 + local_54 * 2) = uVar12;
          }
          local_70 = local_70 + param_1[0x1b];
          local_6c = local_6c + local_40;
          uVar14 = uVar14 ^ uVar14 >> 6;
          local_68 = local_68 + local_3c;
          local_54 = local_54 + 1;
        } while (local_54 < 0);
      }
      else {
        iVar16 = param_1[7] + iVar15 * 2;
        uVar14 = *(uint *)(DAT_1007522c + ((uVar21 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        local_54 = -1 - local_54;
        uVar13 = param_1[5];
        do {
          uVar12 = (ushort)(local_70 >> 0x10);
          if ((*(ushort *)(iVar16 + local_54 * 2) < uVar12) &&
             (cVar1 = *(char *)(((((int)(char)~((byte)uVar14 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                  >> 4 | (int)(char)(byte)uVar14 + (local_68 >> 0x10) & 0x1e00) >> 5
                                ) + uVar2), cVar1 != '\0')) {
            *(char *)(uVar13 + iVar15 + local_54) = cVar1;
            *(ushort *)(iVar16 + local_54 * 2) = uVar12;
          }
          local_70 = local_70 + param_1[0x1b];
          local_6c = local_6c + local_40;
          uVar14 = uVar14 ^ uVar14 >> 6;
          local_68 = local_68 + local_3c;
          local_54 = local_54 + -1;
        } while (-1 < local_54);
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


