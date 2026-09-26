// 100495a0 FUN_100495a0 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100495a0(uint *param_1)

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
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
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
  int local_70;
  uint local_6c;
  uint local_68;
  int local_64;
  int local_60;
  uint local_48;
  
  uVar1 = param_1[0xc];
  uVar2 = param_1[0xd];
  uVar18 = *param_1;
  uVar20 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar18 = uVar18 + uVar3;
    uVar20 = uVar20 + uVar4;
    uVar12 = param_1[0x43];
    uVar13 = param_1[0x45];
    param_1[0x43] = uVar12 + param_1[0x44];
    param_1[0x45] = uVar13 + param_1[0x46];
    local_48 = param_1[0x4b] + param_1[0x4c];
    param_1[0x4b] = local_48;
    local_6c = (int)(uVar12 + param_1[0x44]) / (int)(local_48 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4e] = local_6c;
    local_68 = (int)(uVar13 + param_1[0x46]) / (int)(local_48 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4f] = local_68;
    uVar12 = param_1[0x47];
    uVar13 = param_1[0x49];
    param_1[0x47] = uVar12 + param_1[0x48];
    uVar19 = param_1[0x50] + param_1[0x51];
    param_1[0x49] = param_1[0x4a] + uVar13;
    param_1[0x50] = uVar19;
    uVar12 = (int)(uVar12 + param_1[0x48]) / (int)(uVar19 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x53] = uVar12;
    uVar13 = (int)(param_1[0x4a] + uVar13) / (int)(uVar19 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x54] = uVar13;
    iVar14 = (int)uVar18 >> 0x10;
    iVar15 = (int)uVar20 >> 0x10;
    local_70 = iVar14 - iVar15;
    if (local_70 < 0) {
      uVar26 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar23 = 0xdead;
      uVar24 = 0xdead;
      uVar21 = 0xdead;
      local_64 = 0xdead;
      local_60 = 0xdead;
      bVar27 = uVar6 != 0;
      uVar17 = uVar19;
      if ((bool)bVar27) {
        uVar17 = local_48;
        local_48 = uVar19;
      }
      if (((int)(uVar17 - local_48) < 1) && (((uVar17 ^ local_48) & 0xffc00000) != 0)) {
        uVar19 = local_6c;
        uVar25 = local_68;
        if (uVar6 != 0) {
          uVar19 = uVar12;
          uVar12 = local_6c;
          uVar25 = uVar13;
          uVar13 = local_68;
        }
        fVar11 = (float)(int)(local_48 - uVar17) * (float)(int)(local_48 - uVar17) * _DAT_1007410c;
        fVar7 = (float)(int)local_48 * (float)-local_70;
        fVar8 = (float)(int)(uVar17 - local_48) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar22 = uVar12 - uVar19;
        bVar28 = false;
        if (uVar12 == uVar19) {
          uVar12 = uVar12 + 1;
          iVar22 = uVar12 - uVar19;
          bVar28 = uVar12 == uVar19;
        }
        if (bVar28 || SBORROW4(uVar12,uVar19) != iVar22 < 0) {
          iVar22 = uVar19 - uVar12;
          bVar27 = bVar27 | 2;
        }
        else {
          iVar22 = uVar12 - uVar19;
        }
        fVar10 = (float)(int)uVar17 * fVar7 * (float)iVar22;
        iVar22 = uVar13 - uVar25;
        bVar28 = false;
        if (uVar13 == uVar25) {
          uVar13 = uVar13 + 1;
          iVar22 = uVar13 - uVar25;
          bVar28 = uVar13 == uVar25;
        }
        if (bVar28 || SBORROW4(uVar13,uVar25) != iVar22 < 0) {
          iVar22 = uVar25 - uVar13;
          bVar27 = bVar27 | 4;
        }
        else {
          iVar22 = uVar13 - uVar25;
        }
        fVar7 = (float)(int)uVar17 * fVar7 * (float)iVar22;
        fVar8 = -(fVar8 * _DAT_1007410c + fVar11);
        uVar13 = (uint)fVar9 | 0xff800000;
        uVar26 = uVar13 << 8;
        uVar12 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar21 = (uint)*(byte *)(((uVar13 & 0xffffff) >> 0xf) + DAT_10075208);
        iVar22 = uVar12 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar22 < 0x20) {
          uVar23 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar22 & 0x1f);
        }
        else {
          uVar23 = 0;
        }
        iVar22 = uVar12 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar22 < 0x20) {
          uVar24 = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar22 & 0x1f);
        }
        else {
          uVar24 = 0;
        }
        local_64 = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
        local_60 = DAT_1007520c +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10075208) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
        local_6c = uVar19;
        local_68 = uVar25;
      }
      else {
        bVar27 = 0x10;
        if (uVar6 == 0) {
          iVar22 = local_6c - uVar12;
          iVar16 = local_68 - uVar13;
        }
        else {
          iVar22 = uVar12 - local_6c;
          iVar16 = uVar13 - local_68;
          local_68 = uVar13;
          local_6c = uVar12;
        }
        local_48 = (iVar22 * 0x100) / local_70 << 8;
        uVar17 = (iVar16 * 0x100) / local_70 << 8;
      }
      local_68 = local_68 << 0x10;
      local_6c = local_6c << 0x10;
      if ((bVar27 & 0x10) == 0) {
        if (uVar6 == 0) {
          uVar12 = *(uint *)(DAT_10075224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar15 = param_1[5] + iVar15;
          switch(bVar27) {
          case 0:
            do {
              uVar26 = uVar26 - uVar23;
              local_6c = local_6c + *(int *)(local_64 + uVar21 * 4);
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              if (0 < (int)uVar26) {
                uVar26 = uVar26 * 2;
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                local_64 = local_64 + -0x400;
                local_60 = local_60 + -0x400;
              }
              bVar27 = *(byte *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_68 >> 0x10) & 0x1e00) >>
                                 5) + uVar1);
              if (bVar27 != 0) {
                *(undefined1 *)(iVar15 + local_70) = *(undefined1 *)(bVar27 + uVar2);
              }
              uVar23 = uVar23 - uVar24;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar26 >> 0x17) + DAT_10075208);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
            break;
          case 2:
            do {
              uVar26 = uVar26 - uVar23;
              local_6c = local_6c - *(int *)(local_64 + uVar21 * 4);
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              if (0 < (int)uVar26) {
                uVar26 = uVar26 * 2;
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                local_64 = local_64 + -0x400;
                local_60 = local_60 + -0x400;
              }
              bVar27 = *(byte *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_68 >> 0x10) & 0x1e00) >>
                                 5) + uVar1);
              if (bVar27 != 0) {
                *(undefined1 *)(iVar15 + local_70) = *(undefined1 *)(bVar27 + uVar2);
              }
              uVar23 = uVar23 - uVar24;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar26 >> 0x17) + DAT_10075208);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
            break;
          case 4:
            do {
              uVar26 = uVar26 - uVar23;
              local_6c = local_6c + *(int *)(local_64 + uVar21 * 4);
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              if (0 < (int)uVar26) {
                uVar26 = uVar26 * 2;
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                local_64 = local_64 + -0x400;
                local_60 = local_60 + -0x400;
              }
              bVar27 = *(byte *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_68 >> 0x10) & 0x1e00) >>
                                 5) + uVar1);
              if (bVar27 != 0) {
                *(undefined1 *)(iVar15 + local_70) = *(undefined1 *)(bVar27 + uVar2);
              }
              uVar23 = uVar23 - uVar24;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar26 >> 0x17) + DAT_10075208);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
            break;
          case 6:
            do {
              uVar26 = uVar26 - uVar23;
              local_6c = local_6c - *(int *)(local_64 + uVar21 * 4);
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              if (0 < (int)uVar26) {
                uVar26 = uVar26 * 2;
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                local_64 = local_64 + -0x400;
                local_60 = local_60 + -0x400;
              }
              bVar27 = *(byte *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_68 >> 0x10) & 0x1e00) >>
                                 5) + uVar1);
              if (bVar27 != 0) {
                *(undefined1 *)(iVar15 + local_70) = *(undefined1 *)(bVar27 + uVar2);
              }
              uVar23 = uVar23 - uVar24;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar26 >> 0x17) + DAT_10075208);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
          }
        }
        else {
          uVar12 = *(uint *)(DAT_1007522c + ((uVar20 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar14 = param_1[5] + iVar14;
          local_70 = -1 - local_70;
          switch(bVar27) {
          case 1:
            do {
              uVar26 = uVar26 - uVar23;
              local_6c = local_6c + *(int *)(local_64 + uVar21 * 4);
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              if (0 < (int)uVar26) {
                uVar26 = uVar26 * 2;
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                local_64 = local_64 + -0x400;
                local_60 = local_60 + -0x400;
              }
              bVar27 = *(byte *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_68 >> 0x10) & 0x1e00) >>
                                 5) + uVar1);
              if (bVar27 != 0) {
                *(undefined1 *)(iVar14 + local_70) = *(undefined1 *)(bVar27 + uVar2);
              }
              uVar23 = uVar23 - uVar24;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar26 >> 0x17) + DAT_10075208);
              local_70 = local_70 + -1;
            } while (-1 < local_70);
            break;
          case 3:
            do {
              uVar26 = uVar26 - uVar23;
              local_6c = local_6c - *(int *)(local_64 + uVar21 * 4);
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              if (0 < (int)uVar26) {
                uVar26 = uVar26 * 2;
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                local_64 = local_64 + -0x400;
                local_60 = local_60 + -0x400;
              }
              bVar27 = *(byte *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_68 >> 0x10) & 0x1e00) >>
                                 5) + uVar1);
              if (bVar27 != 0) {
                *(undefined1 *)(iVar14 + local_70) = *(undefined1 *)(bVar27 + uVar2);
              }
              uVar23 = uVar23 - uVar24;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar26 >> 0x17) + DAT_10075208);
              local_70 = local_70 + -1;
            } while (-1 < local_70);
            break;
          case 5:
            do {
              uVar26 = uVar26 - uVar23;
              local_6c = local_6c + *(int *)(local_64 + uVar21 * 4);
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              if (0 < (int)uVar26) {
                uVar26 = uVar26 * 2;
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                local_64 = local_64 + -0x400;
                local_60 = local_60 + -0x400;
              }
              bVar27 = *(byte *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_68 >> 0x10) & 0x1e00) >>
                                 5) + uVar1);
              if (bVar27 != 0) {
                *(undefined1 *)(iVar14 + local_70) = *(undefined1 *)(bVar27 + uVar2);
              }
              uVar23 = uVar23 - uVar24;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar26 >> 0x17) + DAT_10075208);
              local_70 = local_70 + -1;
            } while (-1 < local_70);
            break;
          case 7:
            do {
              uVar26 = uVar26 - uVar23;
              local_6c = local_6c - *(int *)(local_64 + uVar21 * 4);
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              if (0 < (int)uVar26) {
                uVar26 = uVar26 * 2;
                uVar23 = uVar23 * 2;
                uVar24 = uVar24 * 2;
                local_64 = local_64 + -0x400;
                local_60 = local_60 + -0x400;
              }
              bVar27 = *(byte *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_6c >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_68 >> 0x10) & 0x1e00) >>
                                 5) + uVar1);
              if (bVar27 != 0) {
                *(undefined1 *)(iVar14 + local_70) = *(undefined1 *)(bVar27 + uVar2);
              }
              uVar23 = uVar23 - uVar24;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar26 >> 0x17) + DAT_10075208);
              local_70 = local_70 + -1;
            } while (-1 < local_70);
          }
        }
      }
      else if (uVar6 == 0) {
        uVar12 = param_1[5];
        uVar13 = *(uint *)(DAT_10075224 + ((uVar18 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        do {
          bVar27 = *(byte *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_6c >> 0x10) & 0x1e00) >>
                               4 | (int)(char)(byte)uVar13 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                            uVar1);
          if (bVar27 != 0) {
            *(undefined1 *)(iVar15 + uVar12 + local_70) = *(undefined1 *)(bVar27 + uVar2);
          }
          uVar13 = uVar13 ^ uVar13 >> 6;
          local_68 = local_68 + uVar17;
          local_6c = local_6c + local_48;
          local_70 = local_70 + 1;
        } while (local_70 < 0);
      }
      else {
        uVar12 = param_1[5];
        uVar13 = *(uint *)(DAT_1007522c + ((uVar20 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        local_70 = -1 - local_70;
        do {
          bVar27 = *(byte *)(((((int)(char)~((byte)uVar13 ^ 0x55) + (local_6c >> 0x10) & 0x1e00) >>
                               4 | (int)(char)(byte)uVar13 + (local_68 >> 0x10) & 0x1e00) >> 5) +
                            uVar1);
          if (bVar27 != 0) {
            local_74 = (uint)bVar27;
            *(undefined1 *)(iVar14 + uVar12 + local_70) = *(undefined1 *)(local_74 + uVar2);
          }
          uVar13 = uVar13 ^ uVar13 >> 6;
          local_68 = local_68 + uVar17;
          local_6c = local_6c + local_48;
          local_70 = local_70 + -1;
        } while (-1 < local_70);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar18;
  param_1[1] = uVar20;
  return;
}


