// 1003fd50 FUN_1003fd50 [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1003fd50(uint *param_1)

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
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  byte bVar27;
  bool bVar28;
  uint local_74;
  uint local_70;
  int local_6c;
  uint local_68;
  uint local_64;
  int local_5c;
  int local_58;
  uint local_44;
  
  uVar2 = param_1[0xc];
  uVar18 = *param_1;
  uVar20 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar18 = uVar18 + uVar3;
    uVar20 = uVar20 + uVar4;
    local_70 = param_1[0x1a] + param_1[0x19];
    param_1[0x10] = param_1[0x10] + param_1[0x11];
    uVar13 = param_1[0x45];
    param_1[0x19] = local_70;
    uVar14 = param_1[0x43];
    param_1[0x45] = uVar13 + param_1[0x46];
    param_1[0x43] = uVar14 + param_1[0x44];
    local_44 = param_1[0x4b] + param_1[0x4c];
    param_1[0x4b] = local_44;
    local_68 = (int)(uVar14 + param_1[0x44]) / (int)(local_44 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4e] = local_68;
    local_64 = (int)(uVar13 + param_1[0x46]) / (int)(local_44 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4f] = local_64;
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
    iVar16 = (int)uVar20 >> 0x10;
    local_6c = iVar15 - iVar16;
    if (local_6c < 0) {
      uVar23 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar24 = 0xdead;
      uVar26 = 0xdead;
      uVar21 = 0xdead;
      local_5c = 0xdead;
      local_58 = 0xdead;
      bVar27 = uVar6 != 0;
      local_74 = uVar19;
      if ((bool)bVar27) {
        local_74 = local_44;
        local_44 = uVar19;
      }
      if (((int)(local_74 - local_44) < 1) && (((local_44 ^ local_74) & 0xffc00000) != 0)) {
        uVar19 = local_68;
        uVar25 = local_64;
        if (uVar6 != 0) {
          uVar19 = uVar13;
          uVar13 = local_68;
          uVar25 = uVar14;
          uVar14 = local_64;
        }
        fVar11 = (float)(int)(local_44 - local_74) * (float)(int)(local_44 - local_74) *
                 _DAT_10074104;
        fVar7 = (float)(int)local_44 * (float)-local_6c;
        fVar8 = (float)(int)(local_74 - local_44) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar22 = uVar13 - uVar19;
        bVar28 = false;
        if (uVar13 == uVar19) {
          uVar13 = uVar13 + 1;
          iVar22 = uVar13 - uVar19;
          bVar28 = uVar13 == uVar19;
        }
        if (bVar28 || SBORROW4(uVar13,uVar19) != iVar22 < 0) {
          iVar22 = uVar19 - uVar13;
          bVar27 = bVar27 | 2;
        }
        else {
          iVar22 = uVar13 - uVar19;
        }
        fVar10 = (float)(int)local_74 * fVar7 * (float)iVar22;
        iVar22 = uVar14 - uVar25;
        bVar28 = false;
        if (uVar14 == uVar25) {
          uVar14 = uVar14 + 1;
          iVar22 = uVar14 - uVar25;
          bVar28 = uVar14 == uVar25;
        }
        if (bVar28 || SBORROW4(uVar14,uVar25) != iVar22 < 0) {
          iVar22 = uVar25 - uVar14;
          bVar27 = bVar27 | 4;
        }
        else {
          iVar22 = uVar14 - uVar25;
        }
        fVar7 = (float)(int)local_74 * fVar7 * (float)iVar22;
        fVar8 = -(fVar8 * _DAT_10074104 + fVar11);
        uVar14 = (uint)fVar9 | 0xff800000;
        uVar23 = uVar14 << 8;
        uVar13 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar21 = (uint)*(byte *)(((uVar14 & 0xffffff) >> 0xf) + DAT_10075208);
        iVar22 = uVar13 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar22 < 0x20) {
          uVar24 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar22 & 0x1f);
        }
        else {
          uVar24 = 0;
        }
        iVar22 = uVar13 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar22 < 0x20) {
          uVar26 = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar22 & 0x1f);
        }
        else {
          uVar26 = 0;
        }
        local_5c = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
        local_58 = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar13 * 0x400;
        local_68 = uVar19;
        local_64 = uVar25;
      }
      else {
        bVar27 = 0x10;
        if (uVar6 == 0) {
          iVar22 = local_68 - uVar13;
          iVar17 = local_64 - uVar14;
        }
        else {
          iVar22 = uVar13 - local_68;
          iVar17 = uVar14 - local_64;
          local_64 = uVar14;
          local_68 = uVar13;
        }
        local_44 = (iVar22 * 0x100) / local_6c << 8;
        local_74 = (iVar17 * 0x100) / local_6c << 8;
      }
      local_64 = local_64 << 0x10;
      local_68 = local_68 << 0x10;
      if ((bVar27 & 0x10) == 0) {
        if (uVar6 == 0) {
          iVar15 = param_1[7] + iVar16 * 2;
          local_74 = *(uint *)(DAT_10075224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^
                     (uint)(byte)param_1[9];
          iVar16 = iVar16 + param_1[5];
          switch(bVar27) {
          case 0:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 + *(int *)(local_5c + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_58 + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_74 & 0xff) < param_1[10]) &&
                  (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar12)
                  ) && (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 |
                                          (local_68 & 0x1e000000) >> 0x19) + uVar2), cVar1 != '\0'))
              {
                *(char *)(iVar16 + local_6c) = cVar1;
                *(ushort *)(iVar15 + local_6c * 2) = uVar12;
              }
              uVar24 = uVar24 - uVar26;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 2:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 - *(int *)(local_5c + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_58 + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_74 & 0xff) < param_1[10]) &&
                  (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar12)
                  ) && (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 |
                                          (local_68 & 0x1e000000) >> 0x19) + uVar2), cVar1 != '\0'))
              {
                *(char *)(iVar16 + local_6c) = cVar1;
                *(ushort *)(iVar15 + local_6c * 2) = uVar12;
              }
              uVar24 = uVar24 - uVar26;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 4:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 + *(int *)(local_5c + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_58 + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_74 & 0xff) < param_1[10]) &&
                  (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar12)
                  ) && (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 |
                                          (local_68 & 0x1e000000) >> 0x19) + uVar2), cVar1 != '\0'))
              {
                *(char *)(iVar16 + local_6c) = cVar1;
                *(ushort *)(iVar15 + local_6c * 2) = uVar12;
              }
              uVar24 = uVar24 - uVar26;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 6:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 - *(int *)(local_5c + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_58 + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_58 = local_58 + -0x400;
                local_5c = local_5c + -0x400;
              }
              if ((((local_74 & 0xff) < param_1[10]) &&
                  (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar12)
                  ) && (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 |
                                          (local_68 & 0x1e000000) >> 0x19) + uVar2), cVar1 != '\0'))
              {
                *(char *)(iVar16 + local_6c) = cVar1;
                *(ushort *)(iVar15 + local_6c * 2) = uVar12;
              }
              uVar24 = uVar24 - uVar26;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
              local_6c = local_6c + 1;
            } while (local_6c < 0);
          }
        }
        else {
          iVar16 = param_1[7] + iVar15 * 2;
          local_74 = *(uint *)(DAT_1007522c + ((uVar20 & 0x70000) >> 0x10) * 4) ^
                     (uint)(byte)param_1[9];
          iVar15 = param_1[5] + iVar15;
          local_6c = -1 - local_6c;
          switch(bVar27) {
          case 1:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 + *(int *)(local_5c + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_58 + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              if ((((local_74 & 0xff) < param_1[10]) &&
                  (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar16 + local_6c * 2) < uVar12)
                  ) && (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 |
                                          (local_68 & 0x1e000000) >> 0x19) + uVar2), cVar1 != '\0'))
              {
                *(char *)(iVar15 + local_6c) = cVar1;
                *(ushort *)(iVar16 + local_6c * 2) = uVar12;
              }
              uVar24 = uVar24 - uVar26;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              local_6c = local_6c + -1;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
            } while (-1 < local_6c);
            break;
          case 3:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 - *(int *)(local_5c + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_58 + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              if ((((local_74 & 0xff) < param_1[10]) &&
                  (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar16 + local_6c * 2) < uVar12)
                  ) && (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 |
                                          (local_68 & 0x1e000000) >> 0x19) + uVar2), cVar1 != '\0'))
              {
                *(char *)(iVar15 + local_6c) = cVar1;
                *(ushort *)(iVar16 + local_6c * 2) = uVar12;
              }
              uVar24 = uVar24 - uVar26;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              local_6c = local_6c + -1;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
            } while (-1 < local_6c);
            break;
          case 5:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 + *(int *)(local_5c + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_58 + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              if ((((local_74 & 0xff) < param_1[10]) &&
                  (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar16 + local_6c * 2) < uVar12)
                  ) && (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 |
                                          (local_68 & 0x1e000000) >> 0x19) + uVar2), cVar1 != '\0'))
              {
                *(char *)(iVar15 + local_6c) = cVar1;
                *(ushort *)(iVar16 + local_6c * 2) = uVar12;
              }
              uVar24 = uVar24 - uVar26;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              local_6c = local_6c + -1;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
            } while (-1 < local_6c);
            break;
          case 7:
            do {
              uVar23 = uVar23 - uVar24;
              local_68 = local_68 - *(int *)(local_5c + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_58 + uVar21 * 4);
              if (0 < (int)uVar23) {
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                uVar26 = uVar26 * 2;
                local_5c = local_5c + -0x400;
                local_58 = local_58 + -0x400;
              }
              if ((((local_74 & 0xff) < param_1[10]) &&
                  (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar16 + local_6c * 2) < uVar12)
                  ) && (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 |
                                          (local_68 & 0x1e000000) >> 0x19) + uVar2), cVar1 != '\0'))
              {
                *(char *)(iVar15 + local_6c) = cVar1;
                *(ushort *)(iVar16 + local_6c * 2) = uVar12;
              }
              uVar24 = uVar24 - uVar26;
              local_70 = local_70 + param_1[0x1b];
              local_74 = local_74 ^ local_74 >> 6;
              local_6c = local_6c + -1;
              uVar21 = (uint)*(byte *)((uVar23 >> 0x17) + DAT_10075208);
            } while (-1 < local_6c);
          }
        }
      }
      else if (uVar6 == 0) {
        iVar15 = param_1[7] + iVar16 * 2;
        uVar13 = param_1[5];
        uVar14 = *(uint *)(DAT_10075224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        do {
          if ((((uVar14 & 0xff) < param_1[10]) &&
              (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar15 + local_6c * 2) < uVar12)) &&
             (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 | (local_68 & 0x1e000000) >> 0x19)
                               + uVar2), cVar1 != '\0')) {
            *(char *)(iVar16 + uVar13 + local_6c) = cVar1;
            *(ushort *)(iVar15 + local_6c * 2) = uVar12;
          }
          local_70 = local_70 + param_1[0x1b];
          local_68 = local_68 + local_44;
          uVar14 = uVar14 ^ uVar14 >> 6;
          local_64 = local_64 + local_74;
          local_6c = local_6c + 1;
        } while (local_6c < 0);
      }
      else {
        iVar16 = param_1[7] + iVar15 * 2;
        uVar13 = param_1[5];
        uVar14 = *(uint *)(DAT_1007522c + ((uVar20 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        local_6c = -1 - local_6c;
        do {
          if ((((uVar14 & 0xff) < param_1[10]) &&
              (uVar12 = (ushort)(local_70 >> 0x10), *(ushort *)(iVar16 + local_6c * 2) < uVar12)) &&
             (cVar1 = *(char *)(((local_64 & 0x1e000000) >> 0x15 | (local_68 & 0x1e000000) >> 0x19)
                               + uVar2), cVar1 != '\0')) {
            *(char *)(uVar13 + iVar15 + local_6c) = cVar1;
            *(ushort *)(iVar16 + local_6c * 2) = uVar12;
          }
          local_70 = local_70 + param_1[0x1b];
          uVar14 = uVar14 ^ uVar14 >> 6;
          local_68 = local_68 + local_44;
          local_64 = local_64 + local_74;
          local_6c = local_6c + -1;
        } while (-1 < local_6c);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[7] = param_1[7] + param_1[8];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar18;
  param_1[1] = uVar20;
  return;
}


