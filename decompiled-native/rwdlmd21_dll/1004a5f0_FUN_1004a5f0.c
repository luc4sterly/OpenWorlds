// 1004a5f0 FUN_1004a5f0 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1004a5f0(uint *param_1)

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
  short *psVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  byte bVar26;
  bool bVar27;
  short *local_70;
  int local_6c;
  uint local_68;
  uint local_64;
  int local_60;
  int local_5c;
  uint local_54;
  uint local_48;
  
  uVar2 = param_1[0xc];
  uVar17 = *param_1;
  uVar20 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar17 = uVar17 + uVar3;
    uVar20 = uVar20 + uVar4;
    uVar12 = param_1[0x43];
    uVar13 = param_1[0x45];
    param_1[0x43] = param_1[0x44] + uVar12;
    param_1[0x45] = uVar13 + param_1[0x46];
    local_48 = param_1[0x4b] + param_1[0x4c];
    param_1[0x4b] = local_48;
    local_68 = (int)(param_1[0x44] + uVar12) / (int)(local_48 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4e] = local_68;
    local_64 = (int)(uVar13 + param_1[0x46]) / (int)(local_48 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4f] = local_64;
    uVar12 = param_1[0x47];
    uVar13 = param_1[0x49];
    param_1[0x47] = uVar12 + param_1[0x48];
    uVar18 = param_1[0x50] + param_1[0x51];
    param_1[0x49] = param_1[0x4a] + uVar13;
    param_1[0x50] = uVar18;
    uVar12 = (int)(uVar12 + param_1[0x48]) / (int)(uVar18 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x53] = uVar12;
    uVar13 = (int)(param_1[0x4a] + uVar13) / (int)(uVar18 >> 0x10) << ((byte)param_1[0x52] & 0x1f);
    param_1[0x54] = uVar13;
    iVar14 = (int)uVar17 >> 0x10;
    iVar15 = (int)uVar20 >> 0x10;
    local_6c = iVar14 - iVar15;
    if (local_6c < 0) {
      uVar24 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar25 = 0xdead;
      uVar23 = 0xdead;
      uVar21 = 0xdead;
      local_60 = 0xdead;
      local_5c = 0xdead;
      bVar26 = uVar6 != 0;
      local_54 = uVar18;
      if ((bool)bVar26) {
        local_54 = local_48;
        local_48 = uVar18;
      }
      if (((int)(local_54 - local_48) < 1) && (((local_54 ^ local_48) & 0xffc00000) != 0)) {
        uVar18 = uVar13;
        uVar24 = uVar12;
        if (uVar6 != 0) {
          uVar18 = local_64;
          uVar24 = local_68;
          local_68 = uVar12;
          local_64 = uVar13;
        }
        fVar11 = (float)(int)(local_48 - local_54) * (float)(int)(local_48 - local_54) *
                 _DAT_1008612c;
        fVar7 = (float)(int)local_48 * (float)-local_6c;
        fVar8 = (float)(int)(local_54 - local_48) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar22 = uVar24 - local_68;
        bVar27 = false;
        if (uVar24 == local_68) {
          uVar24 = uVar24 + 1;
          iVar22 = uVar24 - local_68;
          bVar27 = uVar24 == local_68;
        }
        if (bVar27 || SBORROW4(uVar24,local_68) != iVar22 < 0) {
          iVar22 = local_68 - uVar24;
          bVar26 = bVar26 | 2;
        }
        else {
          iVar22 = uVar24 - local_68;
        }
        fVar10 = (float)(int)local_54 * fVar7 * (float)iVar22;
        iVar22 = uVar18 - local_64;
        bVar27 = false;
        if (uVar18 == local_64) {
          uVar18 = uVar18 + 1;
          iVar22 = uVar18 - local_64;
          bVar27 = uVar18 == local_64;
        }
        if (bVar27 || SBORROW4(uVar18,local_64) != iVar22 < 0) {
          iVar22 = local_64 - uVar18;
          bVar26 = bVar26 | 4;
        }
        else {
          iVar22 = uVar18 - local_64;
        }
        fVar7 = (float)(int)local_54 * fVar7 * (float)iVar22;
        fVar8 = -(fVar8 * _DAT_1008612c + fVar11);
        uVar13 = (uint)fVar9 | 0xff800000;
        uVar24 = uVar13 << 8;
        uVar12 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar21 = (uint)*(byte *)(((uVar13 & 0xffffff) >> 0xf) + DAT_10087230);
        iVar22 = uVar12 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar22 < 0x20) {
          uVar25 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar22 & 0x1f);
        }
        else {
          uVar25 = 0;
        }
        iVar22 = uVar12 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar22 < 0x20) {
          uVar23 = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar22 & 0x1f);
        }
        else {
          uVar23 = 0;
        }
        local_60 = DAT_10087234 +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10087230) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
        local_5c = DAT_10087234 +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10087230) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
      }
      else {
        bVar26 = 0x10;
        if (uVar6 == 0) {
          iVar22 = local_68 - uVar12;
          iVar16 = local_64 - uVar13;
        }
        else {
          iVar22 = uVar12 - local_68;
          iVar16 = uVar13 - local_64;
          local_64 = uVar13;
          local_68 = uVar12;
        }
        local_48 = (iVar22 * 0x100) / local_6c << 8;
        local_54 = (iVar16 * 0x100) / local_6c << 8;
      }
      local_64 = local_64 << 0x10;
      local_68 = local_68 << 0x10;
      if ((bVar26 & 0x10) == 0) {
        if (uVar6 == 0) {
          uVar12 = *(uint *)(DAT_1008724c + ((uVar17 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar14 = iVar15 * 2 + param_1[5];
          switch(bVar26) {
          case 0:
            local_70 = (short *)(iVar14 + local_6c * 2);
            do {
              uVar24 = uVar24 - uVar25;
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar25 = uVar25 * 2;
                uVar23 = uVar23 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >>
                                 4) + uVar2);
              if (sVar1 != 0) {
                *local_70 = sVar1;
              }
              uVar25 = uVar25 - uVar23;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10087230);
              local_70 = local_70 + 1;
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 2:
            local_70 = (short *)(iVar14 + local_6c * 2);
            do {
              uVar24 = uVar24 - uVar25;
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar25 = uVar25 * 2;
                uVar23 = uVar23 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >>
                                 4) + uVar2);
              if (sVar1 != 0) {
                *local_70 = sVar1;
              }
              uVar25 = uVar25 - uVar23;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10087230);
              local_70 = local_70 + 1;
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 4:
            local_70 = (short *)(iVar14 + local_6c * 2);
            do {
              uVar24 = uVar24 - uVar25;
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar25 = uVar25 * 2;
                uVar23 = uVar23 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >>
                                 4) + uVar2);
              if (sVar1 != 0) {
                *local_70 = sVar1;
              }
              uVar25 = uVar25 - uVar23;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10087230);
              local_70 = local_70 + 1;
              local_6c = local_6c + 1;
            } while (local_6c < 0);
            break;
          case 6:
            local_70 = (short *)(iVar14 + local_6c * 2);
            do {
              uVar24 = uVar24 - uVar25;
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar25 = uVar25 * 2;
                uVar23 = uVar23 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >>
                                 4) + uVar2);
              if (sVar1 != 0) {
                *local_70 = sVar1;
              }
              uVar25 = uVar25 - uVar23;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10087230);
              local_70 = local_70 + 1;
              local_6c = local_6c + 1;
            } while (local_6c < 0);
          }
        }
        else {
          uVar12 = *(uint *)(DAT_10087254 + ((uVar20 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar14 = iVar14 * 2 + param_1[5];
          local_6c = -1 - local_6c;
          switch(bVar26) {
          case 1:
            local_70 = (short *)(iVar14 + local_6c * 2);
            do {
              uVar24 = uVar24 - uVar25;
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar25 = uVar25 * 2;
                uVar23 = uVar23 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >>
                                 4) + uVar2);
              if (sVar1 != 0) {
                *local_70 = sVar1;
              }
              uVar25 = uVar25 - uVar23;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10087230);
              local_70 = local_70 + -1;
              local_6c = local_6c + -1;
            } while (-1 < local_6c);
            break;
          case 3:
            local_70 = (short *)(iVar14 + local_6c * 2);
            do {
              uVar24 = uVar24 - uVar25;
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 + *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar25 = uVar25 * 2;
                uVar23 = uVar23 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >>
                                 4) + uVar2);
              if (sVar1 != 0) {
                *local_70 = sVar1;
              }
              uVar25 = uVar25 - uVar23;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10087230);
              local_70 = local_70 + -1;
              local_6c = local_6c + -1;
            } while (-1 < local_6c);
            break;
          case 5:
            local_70 = (short *)(iVar14 + local_6c * 2);
            do {
              uVar24 = uVar24 - uVar25;
              local_68 = local_68 + *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar25 = uVar25 * 2;
                uVar23 = uVar23 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >>
                                 4) + uVar2);
              if (sVar1 != 0) {
                *local_70 = sVar1;
              }
              uVar25 = uVar25 - uVar23;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10087230);
              local_70 = local_70 + -1;
              local_6c = local_6c + -1;
            } while (-1 < local_6c);
            break;
          case 7:
            local_70 = (short *)(iVar14 + local_6c * 2);
            do {
              uVar24 = uVar24 - uVar25;
              local_68 = local_68 - *(int *)(local_60 + uVar21 * 4);
              local_64 = local_64 - *(int *)(local_5c + uVar21 * 4);
              if (0 < (int)uVar24) {
                uVar24 = uVar24 * 2;
                uVar25 = uVar25 * 2;
                uVar23 = uVar23 * 2;
                local_60 = local_60 + -0x400;
                local_5c = local_5c + -0x400;
              }
              sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00)
                                   >> 4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >>
                                 4) + uVar2);
              if (sVar1 != 0) {
                *local_70 = sVar1;
              }
              uVar25 = uVar25 - uVar23;
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar21 = (uint)*(byte *)((uVar24 >> 0x17) + DAT_10087230);
              local_70 = local_70 + -1;
              local_6c = local_6c + -1;
            } while (-1 < local_6c);
          }
        }
      }
      else if (uVar6 == 0) {
        uVar12 = *(uint *)(DAT_1008724c + ((uVar17 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        psVar19 = (short *)(param_1[5] + iVar15 * 2 + local_6c * 2);
        do {
          sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00) >>
                               4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >> 4) +
                            uVar2);
          if (sVar1 != 0) {
            *psVar19 = sVar1;
          }
          uVar12 = uVar12 ^ uVar12 >> 6;
          local_64 = local_64 + local_54;
          local_68 = local_68 + local_48;
          psVar19 = psVar19 + 1;
          local_6c = local_6c + 1;
        } while (local_6c < 0);
      }
      else {
        uVar12 = *(uint *)(DAT_10087254 + ((uVar20 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        local_6c = -1 - local_6c;
        psVar19 = (short *)(param_1[5] + iVar14 * 2 + local_6c * 2);
        do {
          sVar1 = *(short *)(((((int)(char)~((byte)uVar12 ^ 0x55) + (local_68 >> 0x10) & 0x1e00) >>
                               4 | (int)(char)(byte)uVar12 + (local_64 >> 0x10) & 0x1e00) >> 4) +
                            uVar2);
          if (sVar1 != 0) {
            *psVar19 = sVar1;
          }
          uVar12 = uVar12 ^ uVar12 >> 6;
          local_64 = local_64 + local_54;
          local_68 = local_68 + local_48;
          psVar19 = psVar19 + -1;
          local_6c = local_6c + -1;
        } while (-1 < local_6c);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar17;
  param_1[1] = uVar20;
  return;
}


