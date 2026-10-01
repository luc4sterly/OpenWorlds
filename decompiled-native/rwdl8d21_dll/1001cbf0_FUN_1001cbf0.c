// 1001cbf0 FUN_1001cbf0 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cbf0(uint *param_1)

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
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  ushort uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  byte bVar26;
  bool bVar27;
  uint local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  uint local_68;
  uint local_64;
  int local_60;
  int local_5c;
  uint local_44;
  uint local_40;
  
  uVar2 = param_1[0xc];
  uVar17 = *param_1;
  uVar20 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar17 = uVar17 + uVar3;
    uVar20 = uVar20 + uVar4;
    local_70 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = param_1[0x10] + param_1[0x11];
    uVar12 = param_1[0x45];
    param_1[0x19] = local_70;
    uVar13 = param_1[0x43];
    param_1[0x45] = uVar12 + param_1[0x46];
    param_1[0x43] = uVar13 + param_1[0x44];
    uVar18 = param_1[0x4b] + param_1[0x4c];
    param_1[0x4b] = uVar18;
    local_68 = (int)(uVar13 + param_1[0x44]) / (int)(uVar18 >> 0x10) << ((byte)param_1[0x4d] & 0x1f)
    ;
    param_1[0x4e] = local_68;
    local_64 = (int)(uVar12 + param_1[0x46]) / (int)(uVar18 >> 0x10) << ((byte)param_1[0x4d] & 0x1f)
    ;
    param_1[0x4f] = local_64;
    uVar12 = param_1[0x47];
    uVar13 = param_1[0x49];
    param_1[0x47] = uVar12 + param_1[0x48];
    local_40 = param_1[0x50] + param_1[0x51];
    param_1[0x49] = param_1[0x4a] + uVar13;
    param_1[0x50] = local_40;
    uVar12 = (int)(uVar12 + param_1[0x48]) / (int)(local_40 >> 0x10) << ((byte)param_1[0x52] & 0x1f)
    ;
    param_1[0x53] = uVar12;
    uVar13 = (int)(param_1[0x4a] + uVar13) / (int)(local_40 >> 0x10) << ((byte)param_1[0x52] & 0x1f)
    ;
    param_1[0x54] = uVar13;
    iVar14 = (int)uVar17 >> 0x10;
    iVar15 = (int)uVar20 >> 0x10;
    local_6c = iVar14 - iVar15;
    if (local_6c < 0) {
      uVar23 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar24 = 0xdead;
      uVar22 = 0xdead;
      uVar21 = 0xdead;
      local_60 = 0xdead;
      local_5c = 0xdead;
      bVar26 = uVar6 != 0;
      local_44 = uVar18;
      if ((bool)bVar26) {
        local_44 = local_40;
        local_40 = uVar18;
      }
      if (((int)(local_40 - local_44) < 1) && (((local_44 ^ local_40) & 0xffc00000) != 0)) {
        uVar18 = local_68;
        uVar23 = uVar13;
        if (uVar6 != 0) {
          uVar18 = uVar12;
          uVar23 = local_64;
          local_64 = uVar13;
          uVar12 = local_68;
        }
        fVar11 = (float)(int)(local_44 - local_40) * (float)(int)(local_44 - local_40) *
                 _DAT_100740e8;
        fVar7 = (float)(int)local_44 * (float)-local_6c;
        fVar8 = (float)(int)(local_40 - local_44) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar25 = uVar12 - uVar18;
        bVar27 = false;
        if (uVar12 == uVar18) {
          uVar12 = uVar12 + 1;
          iVar25 = uVar12 - uVar18;
          bVar27 = uVar12 == uVar18;
        }
        if (bVar27 || SBORROW4(uVar12,uVar18) != iVar25 < 0) {
          iVar25 = uVar18 - uVar12;
          bVar26 = bVar26 | 2;
        }
        else {
          iVar25 = uVar12 - uVar18;
        }
        fVar10 = (float)(int)local_40 * fVar7 * (float)iVar25;
        iVar25 = uVar23 - local_64;
        bVar27 = false;
        if (uVar23 == local_64) {
          uVar23 = uVar23 + 1;
          iVar25 = uVar23 - local_64;
          bVar27 = uVar23 == local_64;
        }
        if (bVar27 || SBORROW4(uVar23,local_64) != iVar25 < 0) {
          iVar25 = local_64 - uVar23;
          bVar26 = bVar26 | 4;
        }
        else {
          iVar25 = uVar23 - local_64;
        }
        fVar7 = (float)(int)local_40 * fVar7 * (float)iVar25;
        fVar8 = -(fVar8 * _DAT_100740e8 + fVar11);
        uVar12 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar13 = (uint)fVar9 | 0xff800000;
        uVar23 = uVar13 << 8;
        uVar21 = (uint)*(byte *)(((uVar13 & 0xffffff) >> 0xf) + DAT_10075208);
        iVar25 = uVar12 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar25 < 0x20) {
          uVar24 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar25 & 0x1f);
        }
        else {
          uVar24 = 0;
        }
        iVar25 = uVar12 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar25 < 0x20) {
          uVar22 = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar25 & 0x1f);
        }
        else {
          uVar22 = 0;
        }
        local_60 = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
        local_5c = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
        local_68 = uVar18;
      }
      else {
        bVar26 = 0x10;
        if (uVar6 == 0) {
          iVar25 = local_68 - uVar12;
          iVar16 = local_64 - uVar13;
        }
        else {
          iVar25 = uVar12 - local_68;
          iVar16 = uVar13 - local_64;
          local_64 = uVar13;
          local_68 = uVar12;
        }
        local_40 = (iVar16 * 0x100) / local_6c << 8;
        local_44 = (iVar25 * 0x100) / local_6c << 8;
      }
      local_64 = local_64 << 0x10;
      local_68 = local_68 << 0x10;
      if ((bVar26 & 0x10) == 0) {
        if (uVar6 == 0) {
          iVar14 = param_1[7] + iVar15 * 2;
          local_74 = (uint)(byte)param_1[9];
          local_78 = *(uint *)(DAT_10075224 + ((uVar17 & 0x70000) >> 0x10) * 4) ^ local_74;
          iVar15 = param_1[5] + iVar15;
          switch(bVar26) {
          case 0:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar22 = uVar22 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_78 & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar14 + local_6c * 2) < uVar19)
                  ) && (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) +
                                         uVar2), cVar1 != '\0')) {
                *(char *)(iVar15 + local_6c) = cVar1;
                *(ushort *)(iVar14 + local_6c * 2) = uVar19;
              }
              uVar24 = uVar24 - uVar22;
              local_70 = local_70 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 2:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar22 = uVar22 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_78 & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar14 + local_6c * 2) < uVar19)
                  ) && (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) +
                                         uVar2), cVar1 != '\0')) {
                *(char *)(iVar15 + local_6c) = cVar1;
                *(ushort *)(iVar14 + local_6c * 2) = uVar19;
              }
              uVar24 = uVar24 - uVar22;
              local_70 = local_70 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 4:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar22 = uVar22 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_78 & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar14 + local_6c * 2) < uVar19)
                  ) && (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) +
                                         uVar2), cVar1 != '\0')) {
                *(char *)(iVar15 + local_6c) = cVar1;
                *(ushort *)(iVar14 + local_6c * 2) = uVar19;
              }
              uVar24 = uVar24 - uVar22;
              local_70 = local_70 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 6:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar22 = uVar22 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_78 & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar14 + local_6c * 2) < uVar19)
                  ) && (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) +
                                         uVar2), cVar1 != '\0')) {
                *(char *)(iVar15 + local_6c) = cVar1;
                *(ushort *)(iVar14 + local_6c * 2) = uVar19;
              }
              uVar24 = uVar24 - uVar22;
              local_70 = local_70 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
              local_6c = local_6c + 1;
            } while (local_6c < 0);
          }
        }
        else {
          iVar15 = param_1[7] + iVar14 * 2;
          local_78 = *(uint *)(DAT_1007522c + ((uVar20 & 0x70000) >> 0x10) * 4) ^
                     (uint)(byte)param_1[9];
          iVar14 = iVar14 + param_1[5];
          local_6c = -1 - local_6c;
          switch(bVar26) {
          case 1:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar22 = uVar22 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_78 & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar19)
                  ) && (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) +
                                         uVar2), cVar1 != '\0')) {
                *(char *)(iVar14 + local_6c) = cVar1;
                *(ushort *)(iVar15 + local_6c * 2) = uVar19;
              }
              uVar24 = uVar24 - uVar22;
              local_70 = local_70 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              local_6c = local_6c + -1;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
            } while (-1 < local_6c);
            break;
          case 3:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar22 = uVar22 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_78 & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar19)
                  ) && (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) +
                                         uVar2), cVar1 != '\0')) {
                *(char *)(iVar14 + local_6c) = cVar1;
                *(ushort *)(iVar15 + local_6c * 2) = uVar19;
              }
              uVar24 = uVar24 - uVar22;
              local_70 = local_70 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              local_6c = local_6c + -1;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
            } while (-1 < local_6c);
            break;
          case 5:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar22 = uVar22 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_78 & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar19)
                  ) && (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) +
                                         uVar2), cVar1 != '\0')) {
                *(char *)(iVar14 + local_6c) = cVar1;
                *(ushort *)(iVar15 + local_6c * 2) = uVar19;
              }
              uVar24 = uVar24 - uVar22;
              local_70 = local_70 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              local_6c = local_6c + -1;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
            } while (-1 < local_6c);
            break;
          case 7:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar22 = uVar22 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_78 & 0xff) < param_1[10]) &&
                  (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar19)
                  ) && (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) +
                                         uVar2), cVar1 != '\0')) {
                *(char *)(iVar14 + local_6c) = cVar1;
                *(ushort *)(iVar15 + local_6c * 2) = uVar19;
              }
              uVar24 = uVar24 - uVar22;
              local_70 = local_70 + param_1[0x1b];
              local_78 = local_78 ^ local_78 >> 6;
              local_6c = local_6c + -1;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
            } while (-1 < local_6c);
          }
        }
      }
      else if (uVar6 == 0) {
        iVar14 = param_1[7] + iVar15 * 2;
        uVar12 = param_1[5];
        local_78 = *(uint *)(DAT_10075224 + ((uVar17 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
        do {
          if ((((local_78 & 0xff) < param_1[10]) &&
              (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar14 + local_6c * 2) < uVar19)) &&
             (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) + uVar2),
             cVar1 != '\0')) {
            *(char *)(uVar12 + iVar15 + local_6c) = cVar1;
            *(ushort *)(iVar14 + local_6c * 2) = uVar19;
          }
          local_70 = local_70 + param_1[0x1b];
          local_68 = local_68 + local_44;
          local_78 = local_78 ^ local_78 >> 6;
          local_64 = local_64 + local_40;
          local_6c = local_6c + 1;
        } while (local_6c < 0);
      }
      else {
        iVar15 = param_1[7] + iVar14 * 2;
        uVar12 = param_1[5];
        uVar13 = *(uint *)(DAT_1007522c + ((uVar20 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        local_6c = -1 - local_6c;
        do {
          if ((((uVar13 & 0xff) < param_1[10]) &&
              (uVar19 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar19)) &&
             (cVar1 = *(char *)(((local_64 & 0xfe03ffff) >> 0x12 | local_68 >> 0x19) + uVar2),
             cVar1 != '\0')) {
            *(char *)(uVar12 + iVar14 + local_6c) = cVar1;
            *(ushort *)(iVar15 + local_6c * 2) = uVar19;
          }
          local_70 = local_70 + param_1[0x1b];
          uVar13 = uVar13 ^ uVar13 >> 6;
          local_68 = local_68 + local_44;
          local_64 = local_64 + local_40;
          local_6c = local_6c + -1;
        } while (-1 < local_6c);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar17;
  param_1[1] = uVar20;
  return;
}


