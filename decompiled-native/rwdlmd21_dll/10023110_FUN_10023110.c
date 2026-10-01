// 10023110 FUN_10023110 [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023110(uint *param_1)

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
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  int iVar21;
  uint uVar22;
  uint uVar23;
  ushort *puVar24;
  uint uVar25;
  byte bVar26;
  bool bVar27;
  int local_70;
  ushort *local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  int local_58;
  int local_54;
  uint local_4c;
  uint local_40;
  
  uVar2 = param_1[0xc];
  uVar17 = *param_1;
  uVar19 = param_1[1];
  uVar3 = param_1[3];
  uVar4 = param_1[2];
  uVar5 = param_1[4];
  while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
    uVar17 = uVar17 + uVar3;
    uVar19 = uVar19 + uVar4;
    uVar12 = param_1[0x43];
    uVar13 = param_1[0x45];
    param_1[0x43] = uVar12 + param_1[0x44];
    param_1[0x45] = uVar13 + param_1[0x46];
    local_40 = param_1[0x4b] + param_1[0x4c];
    param_1[0x4b] = local_40;
    local_64 = (int)(uVar12 + param_1[0x44]) / (int)(local_40 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4e] = local_64;
    local_60 = (int)(uVar13 + param_1[0x46]) / (int)(local_40 >> 0x10) <<
               ((byte)param_1[0x4d] & 0x1f);
    param_1[0x4f] = local_60;
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
    iVar15 = (int)uVar19 >> 0x10;
    local_70 = iVar14 - iVar15;
    if (local_70 < 0) {
      uVar22 = 0xdead;
      uVar6 = param_1[0x6f];
      uVar25 = 0xdead;
      uVar20 = 0xdead;
      local_5c = 0xdead;
      local_58 = 0xdead;
      local_54 = 0xdead;
      bVar26 = uVar6 != 0;
      local_4c = uVar18;
      if ((bool)bVar26) {
        local_4c = local_40;
        local_40 = uVar18;
      }
      if (((int)(local_4c - local_40) < 1) && (((local_4c ^ local_40) & 0xffc00000) != 0)) {
        uVar18 = local_64;
        uVar23 = local_60;
        if (uVar6 != 0) {
          uVar18 = uVar12;
          uVar12 = local_64;
          uVar23 = uVar13;
          uVar13 = local_60;
        }
        fVar11 = (float)(int)(local_40 - local_4c) * (float)(int)(local_40 - local_4c) *
                 _DAT_10086108;
        fVar7 = (float)(int)local_40 * (float)-local_70;
        fVar8 = (float)(int)(local_4c - local_40) * fVar7;
        fVar9 = fVar7 * fVar7 + fVar8;
        iVar21 = uVar12 - uVar18;
        bVar27 = false;
        if (uVar12 == uVar18) {
          uVar12 = uVar12 + 1;
          iVar21 = uVar12 - uVar18;
          bVar27 = uVar12 == uVar18;
        }
        if (bVar27 || SBORROW4(uVar12,uVar18) != iVar21 < 0) {
          iVar21 = uVar18 - uVar12;
          bVar26 = bVar26 | 2;
        }
        else {
          iVar21 = uVar12 - uVar18;
        }
        fVar10 = (float)(int)local_4c * fVar7 * (float)iVar21;
        iVar21 = uVar13 - uVar23;
        bVar27 = false;
        if (uVar13 == uVar23) {
          uVar13 = uVar13 + 1;
          iVar21 = uVar13 - uVar23;
          bVar27 = uVar13 == uVar23;
        }
        if (bVar27 || SBORROW4(uVar13,uVar23) != iVar21 < 0) {
          iVar21 = uVar23 - uVar13;
          bVar26 = bVar26 | 4;
        }
        else {
          iVar21 = uVar13 - uVar23;
        }
        fVar7 = (float)(int)local_4c * fVar7 * (float)iVar21;
        fVar8 = -(fVar8 * _DAT_10086108 + fVar11);
        uVar12 = ((int)fVar9 >> 0x17) - 0x7fU & 0xff;
        uVar13 = (uint)fVar9 | 0xff800000;
        uVar22 = uVar13 << 8;
        uVar20 = (uint)*(byte *)(((uVar13 & 0xffffff) >> 0xf) + DAT_10087230);
        iVar21 = uVar12 - (((int)fVar8 >> 0x17) - 0x7fU & 0xff);
        if (iVar21 < 0x20) {
          uVar25 = (((uint)fVar8 | 0xff800000) << 8) >> ((byte)iVar21 & 0x1f);
        }
        else {
          uVar25 = 0;
        }
        iVar21 = uVar12 - (((int)fVar11 >> 0x17) - 0x7fU & 0xff);
        if (iVar21 < 0x20) {
          local_5c = (((uint)fVar11 | 0xff800000) << 8) >> ((byte)iVar21 & 0x1f);
        }
        else {
          local_5c = 0;
        }
        local_58 = DAT_10087234 +
                   ((uint)*(byte *)((((uint)fVar10 & 0x7f8000) >> 0xf) + 0x100 + DAT_10087230) |
                   (((int)fVar10 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
        local_54 = DAT_10087234 +
                   ((uint)*(byte *)((((uint)fVar7 & 0x7f8000) >> 0xf) + 0x100 + DAT_10087230) |
                   (((int)fVar7 >> 0x17) + -0x7f) * 0x100) * -4 + 0x2000 + uVar12 * 0x400;
        local_64 = uVar18;
        local_60 = uVar23;
      }
      else {
        bVar26 = 0x10;
        if (uVar6 == 0) {
          iVar21 = local_64 - uVar12;
          iVar16 = local_60 - uVar13;
        }
        else {
          iVar21 = uVar12 - local_64;
          iVar16 = uVar13 - local_60;
          local_60 = uVar13;
          local_64 = uVar12;
        }
        local_40 = (iVar21 * 0x100) / local_70 << 8;
        local_4c = (iVar16 * 0x100) / local_70 << 8;
      }
      local_60 = local_60 << 0x10;
      local_64 = local_64 << 0x10;
      if ((bVar26 & 0x10) == 0) {
        if (uVar6 == 0) {
          uVar12 = *(uint *)(DAT_1008724c + ((uVar17 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar14 = param_1[5] + iVar15 * 2;
          switch(bVar26) {
          case 0:
            local_68 = (ushort *)(iVar14 + local_70 * 2);
            do {
              uVar22 = uVar22 - uVar25;
              local_64 = local_64 + *(int *)(local_58 + uVar20 * 4);
              local_60 = local_60 + *(int *)(local_54 + uVar20 * 4);
              if (0 < (int)uVar22) {
                uVar22 = uVar22 * 2;
                uVar25 = uVar25 * 2;
                local_5c = local_5c * 2;
                local_58 = local_58 + -0x400;
                local_54 = local_54 + -0x400;
              }
              uVar1 = *(ushort *)
                       (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                         (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
              if (uVar1 != 0) {
                *local_68 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar25 = uVar25 - local_5c;
              uVar20 = (uint)*(byte *)((uVar22 >> 0x17) + DAT_10087230);
              local_68 = local_68 + 1;
              local_70 = local_70 + 1;
            } while (local_70 < 0);
            break;
          case 2:
            local_68 = (ushort *)(iVar14 + local_70 * 2);
            do {
              uVar22 = uVar22 - uVar25;
              local_64 = local_64 - *(int *)(local_58 + uVar20 * 4);
              local_60 = local_60 + *(int *)(local_54 + uVar20 * 4);
              if (0 < (int)uVar22) {
                uVar22 = uVar22 * 2;
                uVar25 = uVar25 * 2;
                local_5c = local_5c * 2;
                local_58 = local_58 + -0x400;
                local_54 = local_54 + -0x400;
              }
              uVar1 = *(ushort *)
                       (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                         (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
              if (uVar1 != 0) {
                *local_68 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
              uVar12 = uVar12 ^ uVar12 >> 6;
              local_68 = local_68 + 1;
              uVar25 = uVar25 - local_5c;
              uVar20 = (uint)*(byte *)((uVar22 >> 0x17) + DAT_10087230);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
            break;
          case 4:
            local_68 = (ushort *)(iVar14 + local_70 * 2);
            do {
              uVar22 = uVar22 - uVar25;
              local_64 = local_64 + *(int *)(local_58 + uVar20 * 4);
              local_60 = local_60 - *(int *)(local_54 + uVar20 * 4);
              if (0 < (int)uVar22) {
                uVar22 = uVar22 * 2;
                uVar25 = uVar25 * 2;
                local_5c = local_5c * 2;
                local_58 = local_58 + -0x400;
                local_54 = local_54 + -0x400;
              }
              uVar1 = *(ushort *)
                       (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                         (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
              if (uVar1 != 0) {
                *local_68 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
              uVar12 = uVar12 ^ uVar12 >> 6;
              local_68 = local_68 + 1;
              uVar25 = uVar25 - local_5c;
              uVar20 = (uint)*(byte *)((uVar22 >> 0x17) + DAT_10087230);
              local_70 = local_70 + 1;
            } while (local_70 < 0);
            break;
          case 6:
            local_68 = (ushort *)(iVar14 + local_70 * 2);
            do {
              uVar22 = uVar22 - uVar25;
              local_64 = local_64 - *(int *)(local_58 + uVar20 * 4);
              local_60 = local_60 - *(int *)(local_54 + uVar20 * 4);
              if (0 < (int)uVar22) {
                uVar22 = uVar22 * 2;
                uVar25 = uVar25 * 2;
                local_5c = local_5c * 2;
                local_58 = local_58 + -0x400;
                local_54 = local_54 + -0x400;
              }
              uVar1 = *(ushort *)
                       (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                         (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
              if (uVar1 != 0) {
                *local_68 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar25 = uVar25 - local_5c;
              uVar20 = (uint)*(byte *)((uVar22 >> 0x17) + DAT_10087230);
              local_68 = local_68 + 1;
              local_70 = local_70 + 1;
            } while (local_70 < 0);
          }
        }
        else {
          uVar12 = *(uint *)(DAT_10087254 + ((uVar19 & 0x70000) >> 0x10) * 4) ^
                   (uint)(byte)param_1[9];
          iVar14 = param_1[5] + iVar14 * 2;
          local_70 = -1 - local_70;
          switch(bVar26) {
          case 1:
            local_68 = (ushort *)(iVar14 + local_70 * 2);
            do {
              uVar22 = uVar22 - uVar25;
              local_64 = local_64 + *(int *)(local_58 + uVar20 * 4);
              local_60 = local_60 + *(int *)(local_54 + uVar20 * 4);
              if (0 < (int)uVar22) {
                uVar22 = uVar22 * 2;
                uVar25 = uVar25 * 2;
                local_5c = local_5c * 2;
                local_58 = local_58 + -0x400;
                local_54 = local_54 + -0x400;
              }
              uVar1 = *(ushort *)
                       (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                         (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
              if (uVar1 != 0) {
                *local_68 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar25 = uVar25 - local_5c;
              uVar20 = (uint)*(byte *)((uVar22 >> 0x17) + DAT_10087230);
              local_68 = local_68 + -1;
              local_70 = local_70 + -1;
            } while (-1 < local_70);
            break;
          case 3:
            local_68 = (ushort *)(iVar14 + local_70 * 2);
            do {
              uVar22 = uVar22 - uVar25;
              local_64 = local_64 - *(int *)(local_58 + uVar20 * 4);
              local_60 = local_60 + *(int *)(local_54 + uVar20 * 4);
              if (0 < (int)uVar22) {
                uVar22 = uVar22 * 2;
                uVar25 = uVar25 * 2;
                local_5c = local_5c * 2;
                local_58 = local_58 + -0x400;
                local_54 = local_54 + -0x400;
              }
              uVar1 = *(ushort *)
                       (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                         (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
              if (uVar1 != 0) {
                *local_68 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
              uVar12 = uVar12 ^ uVar12 >> 6;
              local_68 = local_68 + -1;
              uVar25 = uVar25 - local_5c;
              uVar20 = (uint)*(byte *)((uVar22 >> 0x17) + DAT_10087230);
              local_70 = local_70 + -1;
            } while (-1 < local_70);
            break;
          case 5:
            local_68 = (ushort *)(iVar14 + local_70 * 2);
            do {
              uVar22 = uVar22 - uVar25;
              local_64 = local_64 + *(int *)(local_58 + uVar20 * 4);
              local_60 = local_60 - *(int *)(local_54 + uVar20 * 4);
              if (0 < (int)uVar22) {
                uVar22 = uVar22 * 2;
                uVar25 = uVar25 * 2;
                local_5c = local_5c * 2;
                local_58 = local_58 + -0x400;
                local_54 = local_54 + -0x400;
              }
              uVar1 = *(ushort *)
                       (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                         (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
              if (uVar1 != 0) {
                *local_68 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
              uVar12 = uVar12 ^ uVar12 >> 6;
              local_68 = local_68 + -1;
              uVar25 = uVar25 - local_5c;
              uVar20 = (uint)*(byte *)((uVar22 >> 0x17) + DAT_10087230);
              local_70 = local_70 + -1;
            } while (-1 < local_70);
            break;
          case 7:
            local_68 = (ushort *)(iVar14 + local_70 * 2);
            do {
              uVar22 = uVar22 - uVar25;
              local_64 = local_64 - *(int *)(local_58 + uVar20 * 4);
              local_60 = local_60 - *(int *)(local_54 + uVar20 * 4);
              if (0 < (int)uVar22) {
                uVar22 = uVar22 * 2;
                uVar25 = uVar25 * 2;
                local_5c = local_5c * 2;
                local_58 = local_58 + -0x400;
                local_54 = local_54 + -0x400;
              }
              uVar1 = *(ushort *)
                       (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                         (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
              if (uVar1 != 0) {
                *local_68 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                            (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                            (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
              }
              uVar12 = uVar12 ^ uVar12 >> 6;
              uVar25 = uVar25 - local_5c;
              uVar20 = (uint)*(byte *)((uVar22 >> 0x17) + DAT_10087230);
              local_68 = local_68 + -1;
              local_70 = local_70 + -1;
            } while (-1 < local_70);
          }
        }
      }
      else if (uVar6 == 0) {
        uVar12 = *(uint *)(DAT_1008724c + ((uVar17 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        puVar24 = (ushort *)(param_1[5] + iVar15 * 2 + local_70 * 2);
        do {
          uVar1 = *(ushort *)
                   (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                     (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
          if (uVar1 != 0) {
            *puVar24 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                       (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                       (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
          }
          uVar12 = uVar12 ^ uVar12 >> 6;
          local_60 = local_60 + local_4c;
          local_64 = local_64 + local_40;
          puVar24 = puVar24 + 1;
          local_70 = local_70 + 1;
        } while (local_70 < 0);
      }
      else {
        uVar12 = *(uint *)(DAT_10087254 + ((uVar19 & 0x70000) >> 0x10) * 4) ^ (uint)(byte)param_1[9]
        ;
        local_70 = -1 - local_70;
        puVar24 = (ushort *)(param_1[5] + iVar14 * 2 + local_70 * 2);
        do {
          uVar1 = *(ushort *)
                   (((((int)(char)~((byte)uVar12 ^ 0x55) + (local_64 >> 0x10) & 0xfe00) >> 7 |
                     (int)(char)(byte)uVar12 + (local_60 >> 0x10) & 0xfe00) >> 1) + uVar2);
          if (uVar1 != 0) {
            *puVar24 = (ushort)*(byte *)((uint)((uVar1 & 0x7c0) >> 6) + param_1[0xe]) << 6 |
                       (ushort)*(byte *)((uint)(uVar1 >> 0xb) + param_1[0xd]) << 0xb |
                       (ushort)*(byte *)(param_1[0xf] + (uVar1 & 0x1f));
          }
          uVar12 = uVar12 ^ uVar12 >> 6;
          local_60 = local_60 + local_4c;
          local_64 = local_64 + local_40;
          puVar24 = puVar24 + -1;
          local_70 = local_70 + -1;
        } while (-1 < local_70);
      }
    }
    param_1[5] = param_1[5] + param_1[6];
    param_1[9] = param_1[9] >> 6 ^ param_1[9];
  }
  *param_1 = uVar17;
  param_1[1] = uVar19;
  return;
}


