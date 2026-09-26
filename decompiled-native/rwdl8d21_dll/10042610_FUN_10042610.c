// 10042610 FUN_10042610 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10042610(uint *param_1)

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
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  ushort uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  byte bVar25;
  bool bVar26;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  int local_60;
  int local_5c;
  uint local_40;
  uint local_3c;
  
  uVar1 = param_1[0xc];
  uVar2 = param_1[0xd];
  uVar17 = *param_1;
  uVar20 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar17 = uVar17 + uVar3;
    uVar20 = uVar20 + uVar4;
    local_78 = param_1[0x10] + param_1[0x11];
    param_1[0x10] = local_78;
    local_74 = param_1[0x1a] + param_1[0x19];
    uVar13 = param_1[0x45];
    param_1[0x19] = local_74;
    uVar14 = param_1[0x43];
    param_1[0x43] = uVar14 + param_1[0x44];
    param_1[0x45] = uVar13 + param_1[0x46];
    local_40 = param_1[0x4b] + param_1[0x4c];
    param_1[0x4b] = local_40;
    uVar12 = (int)(uVar14 + param_1[0x44]) / (int)(local_40 >> 0x10) << ((byte)param_1[0x4d] & 0x1f)
    ;
    param_1[0x4e] = uVar12;
    local_68 = (int)(uVar13 + param_1[0x46]) / (int)(local_40 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    uVar13 = param_1[0x47];
    param_1[0x4f] = local_68;
    uVar14 = param_1[0x49];
    param_1[0x47] = param_1[0x48] + uVar13;
    param_1[0x49] = param_1[0x4a] + uVar14;
    uVar18 = param_1[0x50] + param_1[0x51];
    param_1[0x50] = uVar18;
    uVar13 = (int)(param_1[0x48] + uVar13) / (int)(uVar18 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x53] = uVar13;
    uVar14 = (int)(param_1[0x4a] + uVar14) / (int)(uVar18 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    iVar15 = (int)uVar17 >> 0x10;
    param_1[0x54] = uVar14;
    iVar16 = (int)uVar20 >> 0x10;
    local_70 = iVar15 - iVar16;
    if (local_70 < 0) {
      uVar24 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar23 = 0xdead;
      uVar21 = 0xdead;
      local_64 = 0xdead;
      local_60 = 0xdead;
      local_5c = 0xdead;
      bVar25 = uVar6 != 0;
      local_3c = uVar18;
      if ((bool)bVar25) {
        local_3c = local_40;
        local_40 = uVar18;
      }
      if (((int)(local_3c - local_40) < 1) && (((local_3c ^ local_40) & 0xffc00000) != 0)) {
        local_6c = uVar12;
        uVar18 = uVar14;
        if (uVar6 != 0) {
          local_6c = uVar13;
          uVar18 = local_68;
          uVar13 = uVar12;
          local_68 = uVar14;
        }
        fVar11 = (float)(int)(local_40 - local_3c) * (float)(int)(local_40 - local_3c) *
                 _DAT_10074108;
        fVar7 = (float)(int)local_40 * (float)-local_70;
        fVar8 = (float)(int)(local_3c - local_40) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar22 = uVar13 - local_6c;
        bVar26 = false;
        if (uVar13 == local_6c) {
          uVar13 = uVar13 + 1;
          iVar22 = uVar13 - local_6c;
          bVar26 = uVar13 == local_6c;
        }
        if (bVar26 || SBORROW4(uVar13,local_6c) != iVar22 < 0) {
          iVar22 = local_6c - uVar13;
          bVar25 = bVar25 | 2;
        }
        else {
          iVar22 = uVar13 - local_6c;
        }
        fVar10 = (float)(int)local_3c * fVar7 * (float)iVar22;
        iVar22 = uVar18 - local_68;
        bVar26 = false;
        if (uVar18 == local_68) {
          uVar18 = uVar18 + 1;
          iVar22 = uVar18 - local_68;
          bVar26 = uVar18 == local_68;
        }
        if (bVar26 || SBORROW4(uVar18,local_68) != iVar22 < 0) {
          iVar22 = local_68 - uVar18;
          bVar25 = bVar25 | 4;
        }
        else {
          iVar22 = uVar18 - local_68;
        }
        fVar7 = (float)(int)local_3c * fVar7 * (float)iVar22;
        local_6c = local_6c << 0x10;
        fVar8 = -(fVar8 * _DAT_10074108 + fVar11);
        local_68 = local_68 << 0x10;
        uVar13 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar14 = (uint)fVar9 | 0xff800000;
        uVar24 = uVar14 << 8;
        uVar21 = (uint)*(byte *)(((uVar14 & 0xffffff) >> 0xf) + DAT_10075208);
        iVar22 = uVar13 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar22 < 0x20) {
          uVar23 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar22 & 0x1f);
        }
        else {
          uVar23 = 0;
        }
        iVar22 = uVar13 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar22 < 0x20) {
          local_64 = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar22 & 0x1f);
        }
        else {
          local_64 = 0;
        }
        local_60 = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
        local_5c = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
      }
      else {
        bVar25 = 0x10;
        if (uVar6 == 0) {
          local_40 = (int)((uVar12 - uVar13) * 0x100) / local_70 << 8;
          local_3c = (int)((local_68 - uVar14) * 0x100) / local_70 << 8;
          local_6c = uVar12 << 0x10;
          local_68 = local_68 << 0x10;
        }
        else {
          local_40 = (int)((uVar13 - uVar12) * 0x100) / local_70 << 8;
          local_3c = (int)((uVar14 - local_68) * 0x100) / local_70 << 8;
          local_68 = uVar14 << 0x10;
          local_6c = uVar13 << 0x10;
        }
      }
      if ((bVar25 & 0x10) == 0) {
        if (uVar6 == 0) {
          local_7c = *(uint *)(DAT_10075224 + ((uVar17 & 0x70000) >> 0x10) * 4) ^
                     (uint)(byte)param_1[9];
          iVar15 = param_1[7] + iVar16 * 2;
          iVar16 = param_1[5] + iVar16;
          switch(bVar25) {
          case 0:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c + *(int *)(local_60 + uVar21 * 4);
              local_68 = local_68 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_7c & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar15 + local_70 * 2) < uVar19)
                  ) && (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 |
                                           (local_6c & 0x1e000000) >> 0x19) + uVar1), bVar25 != 0))
              {
                *(undefined1 *)(iVar16 + local_70) =
                     *(undefined1 *)(((local_7c & 0xff) + local_78 & 0xff00) + (uint)bVar25 + uVar2)
                ;
                *(ushort *)(iVar15 + local_70 * 2) = uVar19;
              }
              local_7c = local_7c ^ local_7c >> 6;
              local_78 = local_78 + param_1[0x12];
              local_74 = local_74 + param_1[0x1b];
              uVar23 = uVar23 - local_64;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
            break;
          case 2:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c - *(int *)(local_60 + uVar21 * 4);
              local_68 = local_68 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_7c & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar15 + local_70 * 2) < uVar19)
                  ) && (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 |
                                           (local_6c & 0x1e000000) >> 0x19) + uVar1), bVar25 != 0))
              {
                *(undefined1 *)(iVar16 + local_70) =
                     *(undefined1 *)(((local_7c & 0xff) + local_78 & 0xff00) + (uint)bVar25 + uVar2)
                ;
                *(ushort *)(iVar15 + local_70 * 2) = uVar19;
              }
              local_7c = local_7c ^ local_7c >> 6;
              local_78 = local_78 + param_1[0x12];
              local_74 = local_74 + param_1[0x1b];
              uVar23 = uVar23 - local_64;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
            break;
          case 4:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c + *(int *)(local_60 + uVar21 * 4);
              local_68 = local_68 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_7c & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar15 + local_70 * 2) < uVar19)
                  ) && (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 |
                                           (local_6c & 0x1e000000) >> 0x19) + uVar1), bVar25 != 0))
              {
                *(undefined1 *)(iVar16 + local_70) =
                     *(undefined1 *)(((local_7c & 0xff) + local_78 & 0xff00) + (uint)bVar25 + uVar2)
                ;
                *(ushort *)(iVar15 + local_70 * 2) = uVar19;
              }
              local_7c = local_7c ^ local_7c >> 6;
              local_78 = local_78 + param_1[0x12];
              local_74 = local_74 + param_1[0x1b];
              uVar23 = uVar23 - local_64;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
            break;
          case 6:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c - *(int *)(local_60 + uVar21 * 4);
              local_68 = local_68 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_7c & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar15 + local_70 * 2) < uVar19)
                  ) && (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 |
                                           (local_6c & 0x1e000000) >> 0x19) + uVar1), bVar25 != 0))
              {
                *(undefined1 *)(iVar16 + local_70) =
                     *(undefined1 *)(((local_7c & 0xff) + local_78 & 0xff00) + (uint)bVar25 + uVar2)
                ;
                *(ushort *)(iVar15 + local_70 * 2) = uVar19;
              }
              local_7c = local_7c ^ local_7c >> 6;
              local_78 = local_78 + param_1[0x12];
              local_74 = local_74 + param_1[0x1b];
              uVar23 = uVar23 - local_64;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
          }
        }
        else {
          local_7c = *(uint *)(DAT_1007522c + ((uVar20 & 0x70000) >> 0x10) * 4) ^
                     (uint)(byte)param_1[9];
          iVar16 = param_1[7] + iVar15 * 2;
          iVar15 = iVar15 + param_1[5];
          local_70 = -1 - local_70;
          switch(bVar25) {
          case 1:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c + *(int *)(local_60 + uVar21 * 4);
              local_68 = local_68 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_7c & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar16 + local_70 * 2) < uVar19)
                  ) && (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 |
                                           (local_6c & 0x1e000000) >> 0x19) + uVar1), bVar25 != 0))
              {
                local_80 = (uint)bVar25;
                *(undefined1 *)(iVar15 + local_70) =
                     *(undefined1 *)((local_78 + (local_7c & 0xff) & 0xff00) + local_80 + uVar2);
                *(ushort *)(iVar16 + local_70 * 2) = uVar19;
              }
              local_7c = local_7c ^ local_7c >> 6;
              local_78 = local_78 + param_1[0x12];
              local_74 = local_74 + param_1[0x1b];
              uVar23 = uVar23 - local_64;
              local_70 = local_70 + -1;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
            } while (-1 < local_70);
            break;
          case 3:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c - *(int *)(local_60 + uVar21 * 4);
              local_68 = local_68 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_7c & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar16 + local_70 * 2) < uVar19)
                  ) && (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 |
                                           (local_6c & 0x1e000000) >> 0x19) + uVar1), bVar25 != 0))
              {
                local_80 = (uint)bVar25;
                *(undefined1 *)(iVar15 + local_70) =
                     *(undefined1 *)((local_78 + (local_7c & 0xff) & 0xff00) + local_80 + uVar2);
                *(ushort *)(iVar16 + local_70 * 2) = uVar19;
              }
              local_7c = local_7c ^ local_7c >> 6;
              local_78 = local_78 + param_1[0x12];
              local_74 = local_74 + param_1[0x1b];
              uVar23 = uVar23 - local_64;
              local_70 = local_70 + -1;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
            } while (-1 < local_70);
            break;
          case 5:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c + *(int *)(local_60 + uVar21 * 4);
              local_68 = local_68 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_7c & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar16 + local_70 * 2) < uVar19)
                  ) && (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 |
                                           (local_6c & 0x1e000000) >> 0x19) + uVar1), bVar25 != 0))
              {
                local_80 = (uint)bVar25;
                *(undefined1 *)(iVar15 + local_70) =
                     *(undefined1 *)((local_78 + (local_7c & 0xff) & 0xff00) + local_80 + uVar2);
                *(ushort *)(iVar16 + local_70 * 2) = uVar19;
              }
              local_7c = local_7c ^ local_7c >> 6;
              local_78 = local_78 + param_1[0x12];
              local_74 = local_74 + param_1[0x1b];
              uVar23 = uVar23 - local_64;
              local_70 = local_70 + -1;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
            } while (-1 < local_70);
            break;
          case 7:
            do {
              uVar24 = uVar24 - uVar23;
              local_6c = local_6c - *(int *)(local_60 + uVar21 * 4);
              local_68 = local_68 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar23 = uVar23 * 2;
                local_64 = local_64 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_7c & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar16 + local_70 * 2) < uVar19)
                  ) && (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 |
                                           (local_6c & 0x1e000000) >> 0x19) + uVar1), bVar25 != 0))
              {
                local_80 = (uint)bVar25;
                *(undefined1 *)(iVar15 + local_70) =
                     *(undefined1 *)((local_78 + (local_7c & 0xff) & 0xff00) + local_80 + uVar2);
                *(ushort *)(iVar16 + local_70 * 2) = uVar19;
              }
              local_7c = local_7c ^ local_7c >> 6;
              local_78 = local_78 + param_1[0x12];
              local_74 = local_74 + param_1[0x1b];
              uVar23 = uVar23 - local_64;
              local_70 = local_70 + -1;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10075208);
            } while (-1 < local_70);
          }
        }
      }
      else if (uVar6 == 0) {
        iVar15 = param_1[7] + iVar16 * 2;
        uVar13 = param_1[5];
        local_7c = *(uint *)(DAT_10075224 + ((uVar17 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
        do {
          if ((((local_7c & 0xff) < param_1[10]) &&
              (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar15 + local_70 * 2) < uVar19)) &&
             (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 | (local_6c & 0x1e000000) >> 0x19)
                                + uVar1), bVar25 != 0)) {
            local_80 = (uint)bVar25;
            *(undefined1 *)(uVar13 + iVar16 + local_70) =
                 *(undefined1 *)(((local_7c & 0xff) + local_78 & 0xff00) + local_80 + uVar2);
            *(ushort *)(iVar15 + local_70 * 2) = uVar19;
          }
          local_7c = local_7c ^ local_7c >> 6;
          local_78 = local_78 + param_1[0x12];
          local_74 = local_74 + param_1[0x1b];
          local_6c = local_6c + local_40;
          local_68 = local_68 + local_3c;
          local_70 = local_70 + 1;
        } while (local_70 < 0);
      }
      else {
        iVar16 = param_1[7] + iVar15 * 2;
        local_7c = *(uint *)(DAT_1007522c + ((uVar20 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
        local_70 = -1 - local_70;
        uVar13 = param_1[5];
        do {
          if ((((local_7c & 0xff) < param_1[10]) &&
              (uVar19 = (ushort)(local_74 >> 0x10), *(ushort *)(iVar16 + local_70 * 2) < uVar19)) &&
             (bVar25 = *(byte *)(((local_68 & 0x1e000000) >> 0x15 | (local_6c & 0x1e000000) >> 0x19)
                                + uVar1), bVar25 != 0)) {
            local_80 = (uint)bVar25;
            *(undefined1 *)(uVar13 + iVar15 + local_70) =
                 *(undefined1 *)(((local_7c & 0xff) + local_78 & 0xff00) + local_80 + uVar2);
            *(ushort *)(iVar16 + local_70 * 2) = uVar19;
          }
          local_7c = local_7c ^ local_7c >> 6;
          local_78 = local_78 + param_1[0x12];
          local_74 = local_74 + param_1[0x1b];
          local_6c = local_6c + local_40;
          local_68 = local_68 + local_3c;
          local_70 = local_70 + -1;
        } while (-1 < local_70);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
    param_1[7] = param_1[7] + param_1[8];
  }
  *param_1 = uVar17;
  param_1[1] = uVar20;
  return;
}


