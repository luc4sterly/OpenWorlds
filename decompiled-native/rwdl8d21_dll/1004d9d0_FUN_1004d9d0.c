// 1004d9d0 FUN_1004d9d0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1004d9d0(uint *param_1)

{
  uint uVar1;
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
  int iVar23;
  uint uVar24;
  uint uVar25;
  byte bVar26;
  bool bVar27;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  int local_60;
  int local_5c;
  int local_58;
  uint local_40;
  uint local_3c;
  
  uVar1 = param_1[0xc];
  uVar2 = param_1[0xd];
  uVar18 = *param_1;
  uVar21 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar18 = uVar18 + uVar3;
    uVar21 = uVar21 + uVar4;
    local_74 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = param_1[0x10] + param_1[0x11];
    uVar13 = param_1[0x45];
    param_1[0x19] = local_74;
    uVar14 = param_1[0x43];
    param_1[0x45] = uVar13 + param_1[0x46];
    param_1[0x43] = uVar14 + param_1[0x44];
    uVar19 = param_1[0x4b] + param_1[0x4c];
    param_1[0x4b] = uVar19;
    local_70 = (int)(uVar14 + param_1[0x44]) / (int)(uVar19 >> 0x10) << ((byte)param_1[0x4d] & 0x1f)
    ;
    param_1[0x4e] = local_70;
    local_6c = (int)(uVar13 + param_1[0x46]) / (int)(uVar19 >> 0x10) << ((byte)param_1[0x4d] & 0x1f)
    ;
    param_1[0x4f] = local_6c;
    uVar13 = param_1[0x47];
    uVar14 = param_1[0x49];
    param_1[0x47] = uVar13 + param_1[0x48];
    local_3c = param_1[0x50] + param_1[0x51];
    param_1[0x49] = param_1[0x4a] + uVar14;
    param_1[0x50] = local_3c;
    uVar13 = (int)(uVar13 + param_1[0x48]) / (int)(local_3c >> 0x10) << ((byte)param_1[0x52] & 0x1f)
    ;
    param_1[0x53] = uVar13;
    uVar14 = (int)(param_1[0x4a] + uVar14) / (int)(local_3c >> 0x10) << ((byte)param_1[0x52] & 0x1f)
    ;
    param_1[0x54] = uVar14;
    iVar15 = (int)uVar18 >> 0x10;
    iVar16 = (int)uVar21 >> 0x10;
    local_58 = iVar15 - iVar16;
    if (local_58 < 0) {
      uVar25 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar24 = 0xdead;
      uVar22 = 0xdead;
      local_68 = 0xdead;
      local_60 = 0xdead;
      local_5c = 0xdead;
      bVar26 = uVar6 != 0;
      local_40 = uVar19;
      if ((bool)bVar26) {
        local_40 = local_3c;
        local_3c = uVar19;
      }
      if (((int)(local_3c - local_40) < 1) && (((local_40 ^ local_3c) & 0xffc00000) != 0)) {
        uVar19 = uVar14;
        uVar20 = local_70;
        if (uVar6 != 0) {
          uVar19 = local_6c;
          uVar20 = uVar13;
          uVar13 = local_70;
          local_6c = uVar14;
        }
        fVar11 = (float)(int)(local_40 - local_3c) * (float)(int)(local_40 - local_3c) *
                 _DAT_1007410c;
        fVar7 = (float)(int)local_40 * (float)-local_58;
        fVar8 = (float)(int)(local_3c - local_40) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar23 = uVar13 - uVar20;
        bVar27 = false;
        if (uVar13 == uVar20) {
          uVar13 = uVar13 + 1;
          iVar23 = uVar13 - uVar20;
          bVar27 = uVar13 == uVar20;
        }
        if (bVar27 || SBORROW4(uVar13,uVar20) != iVar23 < 0) {
          iVar23 = uVar20 - uVar13;
          bVar26 = bVar26 | 2;
        }
        else {
          iVar23 = uVar13 - uVar20;
        }
        fVar10 = (float)(int)local_3c * fVar7 * (float)iVar23;
        iVar23 = uVar19 - local_6c;
        bVar27 = false;
        if (uVar19 == local_6c) {
          uVar19 = uVar19 + 1;
          iVar23 = uVar19 - local_6c;
          bVar27 = uVar19 == local_6c;
        }
        if (bVar27 || SBORROW4(uVar19,local_6c) != iVar23 < 0) {
          iVar23 = local_6c - uVar19;
          bVar26 = bVar26 | 4;
        }
        else {
          iVar23 = uVar19 - local_6c;
        }
        fVar7 = (float)(int)local_3c * fVar7 * (float)iVar23;
        fVar8 = -(fVar8 * _DAT_1007410c + fVar11);
        uVar13 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar14 = (uint)fVar9 | 0xff800000;
        uVar25 = uVar14 << 8;
        uVar22 = (uint)*(byte *)(((uVar14 & 0xffffff) >> 0xf) + DAT_10075208);
        iVar23 = uVar13 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar23 < 0x20) {
          uVar24 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar23 & 0x1f);
        }
        else {
          uVar24 = 0;
        }
        iVar23 = uVar13 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar23 < 0x20) {
          local_68 = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar23 & 0x1f);
        }
        else {
          local_68 = 0;
        }
        local_60 = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
        local_5c = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
        local_70 = uVar20;
      }
      else {
        bVar26 = 0x10;
        if (uVar6 == 0) {
          iVar23 = local_70 - uVar13;
          iVar17 = local_6c - uVar14;
        }
        else {
          iVar23 = uVar13 - local_70;
          iVar17 = uVar14 - local_6c;
          local_6c = uVar14;
          local_70 = uVar13;
        }
        local_3c = (iVar17 * 0x100) / local_58 << 8;
        local_40 = (iVar23 * 0x100) / local_58 << 8;
      }
      local_6c = local_6c << 0x10;
      local_70 = local_70 << 0x10;
      if ((bVar26 & 0x10) == 0) {
        if (uVar6 == 0) {
          iVar15 = param_1[7] + iVar16 * 2;
          uVar13 = *(uint *)(DAT_10075224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar16 = iVar16 + param_1[5];
          switch(bVar26) {
          case 0:
            do {
              uVar25 = uVar25 - uVar24;
              local_70 = local_70 + *(int *)(local_60 + uVar22 * 4);
              local_6c = local_6c + *(int *)(local_5c + uVar22 * 4);
              if (0 < (int)uVar25) {
                uVar25 = uVar25 * 2;
                uVar24 = uVar24 * 2;
                local_68 = local_68 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              uVar12 = (ushort)(local_74 >> 0x10);
              if ((*(ushort *)(iVar15 + local_58 * 2) < uVar12) &&
                 (bVar26 = *(byte *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_70 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar13 + (local_6c >> 0x10) & 0x1e00) >> 5) +
                                    uVar1), bVar26 != 0)) {
                *(undefined1 *)(local_58 + iVar16) = *(undefined1 *)(bVar26 + uVar2);
                *(ushort *)(iVar15 + local_58 * 2) = uVar12;
              }
              local_74 = local_74 + param_1[0x1b];
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar24 = uVar24 - local_68;
              local_58 = local_58 + 1;
              uVar22 = (uint)*(byte *)((uVar25 >> 0x17) + DAT_10075208);
            } while (local_58 < 0);
            break;
          case 2:
            do {
              uVar25 = uVar25 - uVar24;
              local_70 = local_70 - *(int *)(local_60 + uVar22 * 4);
              local_6c = local_6c + *(int *)(local_5c + uVar22 * 4);
              if (0 < (int)uVar25) {
                uVar25 = uVar25 * 2;
                uVar24 = uVar24 * 2;
                local_68 = local_68 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              uVar12 = (ushort)(local_74 >> 0x10);
              if ((*(ushort *)(iVar15 + local_58 * 2) < uVar12) &&
                 (bVar26 = *(byte *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_70 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar13 + (local_6c >> 0x10) & 0x1e00) >> 5) +
                                    uVar1), bVar26 != 0)) {
                *(undefined1 *)(local_58 + iVar16) = *(undefined1 *)(bVar26 + uVar2);
                *(ushort *)(iVar15 + local_58 * 2) = uVar12;
              }
              local_74 = local_74 + param_1[0x1b];
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar24 = uVar24 - local_68;
              local_58 = local_58 + 1;
              uVar22 = (uint)*(byte *)((uVar25 >> 0x17) + DAT_10075208);
            } while (local_58 < 0);
            break;
          case 4:
            do {
              uVar25 = uVar25 - uVar24;
              local_70 = local_70 + *(int *)(local_60 + uVar22 * 4);
              local_6c = local_6c - *(int *)(local_5c + uVar22 * 4);
              if (0 < (int)uVar25) {
                uVar25 = uVar25 * 2;
                uVar24 = uVar24 * 2;
                local_68 = local_68 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              uVar12 = (ushort)(local_74 >> 0x10);
              if ((*(ushort *)(iVar15 + local_58 * 2) < uVar12) &&
                 (bVar26 = *(byte *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_70 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar13 + (local_6c >> 0x10) & 0x1e00) >> 5) +
                                    uVar1), bVar26 != 0)) {
                *(undefined1 *)(local_58 + iVar16) = *(undefined1 *)(bVar26 + uVar2);
                *(ushort *)(iVar15 + local_58 * 2) = uVar12;
              }
              local_74 = local_74 + param_1[0x1b];
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar24 = uVar24 - local_68;
              local_58 = local_58 + 1;
              uVar22 = (uint)*(byte *)((uVar25 >> 0x17) + DAT_10075208);
            } while (local_58 < 0);
            break;
          case 6:
            do {
              uVar25 = uVar25 - uVar24;
              local_70 = local_70 - *(int *)(local_60 + uVar22 * 4);
              local_6c = local_6c - *(int *)(local_5c + uVar22 * 4);
              if (0 < (int)uVar25) {
                uVar25 = uVar25 * 2;
                uVar24 = uVar24 * 2;
                local_68 = local_68 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              uVar12 = (ushort)(local_74 >> 0x10);
              if ((*(ushort *)(iVar15 + local_58 * 2) < uVar12) &&
                 (bVar26 = *(byte *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_70 >> 0x10) &
                                       0x1e00) >> 4 |
                                      (int)(char)(byte)uVar13 + (local_6c >> 0x10) & 0x1e00) >> 5) +
                                    uVar1), bVar26 != 0)) {
                *(undefined1 *)(local_58 + iVar16) = *(undefined1 *)(bVar26 + uVar2);
                *(ushort *)(iVar15 + local_58 * 2) = uVar12;
              }
              local_74 = local_74 + param_1[0x1b];
              uVar13 = uVar13 ^ uVar13 >> 6;
              uVar24 = uVar24 - local_68;
              local_58 = local_58 + 1;
              uVar22 = (uint)*(byte *)((uVar25 >> 0x17) + DAT_10075208);
            } while (local_58 < 0);
          }
        }
        else {
          iVar16 = param_1[7] + iVar15 * 2;
          local_78 = *(uint *)(DAT_1007522c + ((uVar21 & 0x70000) >> 0x10) * 4) ^
                     (uint)(byte)param_1[9];
          iVar15 = param_1[5] + iVar15;
          local_58 = -1 - local_58;
          switch(bVar26) {
          case 1:
            do {
              uVar25 = uVar25 - uVar24;
              local_70 = local_70 + *(int *)(local_60 + uVar22 * 4);
              local_6c = local_6c + *(int *)(local_5c + uVar22 * 4);
              if (0 < (int)uVar25) {
                uVar25 = uVar25 * 2;
                uVar24 = uVar24 * 2;
                local_68 = local_68 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              uVar12 = (ushort)(local_74 >> 0x10);
              if (*(ushort *)(iVar16 + local_58 * 2) < uVar12) {
                bVar26 = *(byte *)(((((int)(char)~((byte)local_78 ^ 0x55) + (local_70 >> 0x10) &
                                     0x1e00) >> 4 |
                                    (int)(char)(byte)local_78 + (local_6c >> 0x10) & 0x1e00) >> 5) +
                                  uVar1);
                if (bVar26 != 0) {
                  local_7c = (uint)bVar26;
                  *(undefined1 *)(local_58 + iVar15) = *(undefined1 *)(local_7c + uVar2);
                  *(ushort *)(iVar16 + local_58 * 2) = uVar12;
                }
              }
              uVar24 = uVar24 - local_68;
              local_74 = local_74 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              uVar22 = (uint)*(byte *)((uVar25 >> 0x17) + DAT_10075208);
              local_58 = local_58 + -1;
            } while (-1 < local_58);
            break;
          case 3:
            do {
              uVar25 = uVar25 - uVar24;
              local_70 = local_70 - *(int *)(local_60 + uVar22 * 4);
              local_6c = local_6c + *(int *)(local_5c + uVar22 * 4);
              if (0 < (int)uVar25) {
                uVar25 = uVar25 * 2;
                uVar24 = uVar24 * 2;
                local_68 = local_68 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              uVar12 = (ushort)(local_74 >> 0x10);
              if (*(ushort *)(iVar16 + local_58 * 2) < uVar12) {
                bVar26 = *(byte *)(((((int)(char)~((byte)local_78 ^ 0x55) + (local_70 >> 0x10) &
                                     0x1e00) >> 4 |
                                    (int)(char)(byte)local_78 + (local_6c >> 0x10) & 0x1e00) >> 5) +
                                  uVar1);
                if (bVar26 != 0) {
                  local_7c = (uint)bVar26;
                  *(undefined1 *)(local_58 + iVar15) = *(undefined1 *)(local_7c + uVar2);
                  *(ushort *)(iVar16 + local_58 * 2) = uVar12;
                }
              }
              uVar24 = uVar24 - local_68;
              local_74 = local_74 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              uVar22 = (uint)*(byte *)((uVar25 >> 0x17) + DAT_10075208);
              local_58 = local_58 + -1;
            } while (-1 < local_58);
            break;
          case 5:
            do {
              uVar25 = uVar25 - uVar24;
              local_70 = local_70 + *(int *)(local_60 + uVar22 * 4);
              local_6c = local_6c - *(int *)(local_5c + uVar22 * 4);
              if (0 < (int)uVar25) {
                uVar25 = uVar25 * 2;
                uVar24 = uVar24 * 2;
                local_68 = local_68 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              uVar12 = (ushort)(local_74 >> 0x10);
              if (*(ushort *)(iVar16 + local_58 * 2) < uVar12) {
                bVar26 = *(byte *)(((((int)(char)~((byte)local_78 ^ 0x55) + (local_70 >> 0x10) &
                                     0x1e00) >> 4 |
                                    (int)(char)(byte)local_78 + (local_6c >> 0x10) & 0x1e00) >> 5) +
                                  uVar1);
                if (bVar26 != 0) {
                  local_7c = (uint)bVar26;
                  *(undefined1 *)(local_58 + iVar15) = *(undefined1 *)(local_7c + uVar2);
                  *(ushort *)(iVar16 + local_58 * 2) = uVar12;
                }
              }
              uVar24 = uVar24 - local_68;
              local_74 = local_74 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              uVar22 = (uint)*(byte *)((uVar25 >> 0x17) + DAT_10075208);
              local_58 = local_58 + -1;
            } while (-1 < local_58);
            break;
          case 7:
            do {
              uVar25 = uVar25 - uVar24;
              local_70 = local_70 - *(int *)(local_60 + uVar22 * 4);
              local_6c = local_6c - *(int *)(local_5c + uVar22 * 4);
              if (0 < (int)uVar25) {
                uVar25 = uVar25 * 2;
                uVar24 = uVar24 * 2;
                local_68 = local_68 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              uVar12 = (ushort)(local_74 >> 0x10);
              if (*(ushort *)(iVar16 + local_58 * 2) < uVar12) {
                bVar26 = *(byte *)(((((int)(char)~((byte)local_78 ^ 0x55) + (local_70 >> 0x10) &
                                     0x1e00) >> 4 |
                                    (int)(char)(byte)local_78 + (local_6c >> 0x10) & 0x1e00) >> 5) +
                                  uVar1);
                if (bVar26 != 0) {
                  local_7c = (uint)bVar26;
                  *(undefined1 *)(local_58 + iVar15) = *(undefined1 *)(local_7c + uVar2);
                  *(ushort *)(iVar16 + local_58 * 2) = uVar12;
                }
              }
              uVar24 = uVar24 - local_68;
              local_74 = local_74 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              uVar22 = (uint)*(byte *)((uVar25 >> 0x17) + DAT_10075208);
              local_58 = local_58 + -1;
            } while (-1 < local_58);
          }
        }
      }
      else if (uVar6 == 0) {
        uVar13 = param_1[5];
        iVar15 = param_1[7] + iVar16 * 2;
        uVar14 = *(uint *)(DAT_10075224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        do {
          uVar12 = (ushort)(local_74 >> 0x10);
          if ((*(ushort *)(iVar15 + local_58 * 2) < uVar12) &&
             (bVar26 = *(byte *)(((((int)(char)~((byte)uVar14 ^ 0x55) + (local_70 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar14 + (local_6c >> 0x10) & 0x1e00) >>
                                 5) + uVar1), bVar26 != 0)) {
            local_7c = (uint)bVar26;
            *(undefined1 *)(local_58 + uVar13 + iVar16) = *(undefined1 *)(local_7c + uVar2);
            *(ushort *)(iVar15 + local_58 * 2) = uVar12;
          }
          local_74 = local_74 + param_1[0x1b];
          local_70 = local_70 + local_40;
          uVar14 = uVar14 ^ uVar14 >> 6;
          local_6c = local_6c + local_3c;
          local_58 = local_58 + 1;
        } while (local_58 < 0);
      }
      else {
        iVar16 = param_1[7] + iVar15 * 2;
        uVar14 = *(uint *)(DAT_1007522c + ((uVar21 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        local_58 = -1 - local_58;
        uVar13 = param_1[5];
        do {
          uVar12 = (ushort)(local_74 >> 0x10);
          if ((*(ushort *)(iVar16 + local_58 * 2) < uVar12) &&
             (bVar26 = *(byte *)(((((int)(char)~((byte)uVar14 ^ 0x55) + (local_70 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar14 + (local_6c >> 0x10) & 0x1e00) >>
                                 5) + uVar1), bVar26 != 0)) {
            *(undefined1 *)(local_58 + uVar13 + iVar15) = *(undefined1 *)(bVar26 + uVar2);
            *(ushort *)(iVar16 + local_58 * 2) = uVar12;
          }
          local_74 = local_74 + param_1[0x1b];
          local_70 = local_70 + local_40;
          uVar14 = uVar14 ^ uVar14 >> 6;
          local_6c = local_6c + local_3c;
          local_58 = local_58 + -1;
        } while (-1 < local_58);
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


