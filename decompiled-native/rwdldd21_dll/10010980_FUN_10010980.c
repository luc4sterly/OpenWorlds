// 10010980 FUN_10010980 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10010980(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  short sVar11;
  int iVar12;
  uint uVar13;
  short *psVar14;
  short *psVar15;
  uint uVar16;
  uint uVar17;
  short sVar18;
  int iVar19;
  undefined4 *puVar20;
  float *pfVar21;
  undefined4 *puVar22;
  float *pfVar23;
  undefined4 *puVar24;
  longlong lVar25;
  byte local_59;
  uint local_58;
  int *local_4c;
  uint local_44;
  int local_40;
  uint local_34;
  int *local_2c;
  uint local_28 [10];
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar6 = FUN_1000f6e0(param_1,param_2);
    return uVar6;
  }
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    fVar3 = _DAT_1003461c;
    if ((*(byte *)(*param_1 + 0x30) & 0x40) != 0) {
      fVar3 = _DAT_10034620;
    }
    iVar7 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    iVar8 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    bVar1 = *(byte *)((int)param_1 + 0x3a);
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      local_40 = 0;
      local_58 = 0;
      if (bVar1 != 0) {
        local_2c = param_1 + 0xf;
        iVar19 = param_1[bVar1 + 0xe];
        local_59 = *(byte *)(param_1[bVar1 + 0xe] + 0x48);
        do {
          iVar2 = *local_2c;
          bVar1 = *(byte *)(iVar2 + 0x48);
          if ((bVar1 & local_59 & 0x3f) == 0) {
            fVar4 = (float)DAT_10042034;
            fVar5 = (float)DAT_10042038;
            (&DAT_10038b78)[local_58 * 8] = (float)*(int *)(iVar2 + 0x18) * _DAT_10034610 + fVar4;
            *(float *)(&DAT_10038b7c + local_58 * 0x20) =
                 (float)*(int *)(iVar2 + 0x1c) * _DAT_10034610 + fVar5;
            (&DAT_10038b80)[local_58 * 8] =
                 (float)(ushort)~*(ushort *)(iVar2 + 0x22) * _DAT_10034614 - fVar3;
            (&DAT_10038b84)[local_58 * 8] = 0x3f800000;
            uVar10 = *(uint *)(*param_1 + 8);
            local_34 = (uint)*(byte *)(((*(uint *)(iVar2 + 0x5c) & 0x1f0000) >> 0xb) +
                                       ((uVar10 & 0x7c0) >> 6) + DAT_100362d0);
            (&DAT_10038b88)[local_58 * 8] =
                 ((*(byte *)(((*(uint *)(iVar2 + 0x58) & 0x1f0000) >> 0xb) +
                             ((uVar10 & 0xf800) >> 0xb) + DAT_100362d0) | 0xffffffe0) << 0x10 |
                  local_34 << 8 |
                 (uint)*(byte *)(((*(uint *)(iVar2 + 0x60) & 0x1f0000) >> 0xb) + (uVar10 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar2 + 0x14)) {
              if (*(float *)(iVar2 + 0x14) <= _DAT_10036080) {
                lVar25 = __ftol();
                (&DAT_10038b8c)[local_58 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar25 * 4);
              }
              else {
                (&DAT_10038b8c)[local_58 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[local_58 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[local_58 * 8] = 0x3f800000;
            (&DAT_10038b94)[local_58 * 8] = 0x3f800000;
            puVar20 = &DAT_10038b78 + local_58 * 8;
            puVar22 = &DAT_10038bb8 + local_58 * 8;
            for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar22 = *puVar20;
              puVar20 = puVar20 + 1;
              puVar22 = puVar22 + 1;
            }
            iVar9 = local_58 + 1;
            (&DAT_10038b78)[iVar9 * 8] = (float)*(int *)(iVar19 + 0x18) * _DAT_10034610 + fVar4;
            *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
                 (float)*(int *)(iVar19 + 0x1c) * _DAT_10034610 + fVar5;
            (&DAT_10038b80)[iVar9 * 8] =
                 (float)(ushort)~*(ushort *)(iVar19 + 0x22) * _DAT_10034614 - fVar3;
            (&DAT_10038b84)[iVar9 * 8] = 0x3f800000;
            uVar10 = *(uint *)(*param_1 + 8);
            local_4c = (int *)(uint)*(byte *)(((*(uint *)(iVar19 + 0x58) & 0x1f0000) >> 0xb) +
                                              ((uVar10 & 0xf800) >> 0xb) + DAT_100362d0);
            (&DAT_10038b88)[iVar9 * 8] =
                 ((*(byte *)(((*(uint *)(iVar19 + 0x5c) & 0x1f0000) >> 0xb) +
                             ((uVar10 & 0x7c0) >> 6) + DAT_100362d0) | 0xffffe000) << 8 |
                  (int)local_4c << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar19 + 0x60) & 0x1f0000) >> 0xb) + (uVar10 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar19 + 0x14)) {
              if (*(float *)(iVar19 + 0x14) <= _DAT_10036080) {
                lVar25 = __ftol();
                (&DAT_10038b8c)[iVar9 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar25 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar9 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar9 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar9 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar9 * 8] = 0x3f800000;
            pfVar21 = (float *)(&DAT_10038b78 + iVar9 * 8);
            pfVar23 = (float *)(&DAT_10038bb8 + iVar9 * 8);
            for (iVar12 = 8; iVar12 != 0; iVar12 = iVar12 + -1) {
              *pfVar23 = *pfVar21;
              pfVar21 = pfVar21 + 1;
              pfVar23 = pfVar23 + 1;
            }
            iVar9 = local_58 + 2;
            uVar13 = *(int *)(iVar2 + 0x1c) - *(int *)(iVar19 + 0x1c);
            uVar16 = (int)uVar13 >> 0x1f;
            uVar10 = *(int *)(iVar2 + 0x18) - *(int *)(iVar19 + 0x18);
            uVar17 = (int)uVar10 >> 0x1f;
            if ((int)((uVar13 ^ uVar16) - uVar16) < (int)((uVar10 ^ uVar17) - uVar17)) {
              local_28[(int)(local_58 + ((int)local_58 >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar2 + 0x18) < *(int *)(iVar19 + 0x18));
              *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
                   *(float *)(&DAT_10038b7c + iVar9 * 0x20) + _DAT_10034618;
              (&DAT_10038b9c)[iVar9 * 8] = (float)(&DAT_10038b9c)[iVar9 * 8] + _DAT_10034618;
            }
            else {
              local_28[(int)(local_58 + ((int)local_58 >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar19 + 0x1c) < *(int *)(iVar2 + 0x1c));
              (&DAT_10038b78)[iVar9 * 8] = (float)(&DAT_10038b78)[iVar9 * 8] + _DAT_10034618;
              (&DAT_10038b98)[iVar9 * 8] = (float)(&DAT_10038b98)[iVar9 * 8] + _DAT_10034618;
            }
            local_58 = local_58 + 4;
          }
          local_2c = local_2c + 1;
          local_40 = local_40 + 1;
          iVar19 = iVar2;
          local_59 = bVar1;
        } while (local_40 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
      }
      if ((((int)(iVar7 + local_58 * -0x20) < 1) || (iVar8 - (((int)local_58 / 2) * 8 + 0x6c) < 1))
         && (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
        return 0;
      }
      if (0 < (int)local_58) {
        puVar20 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar7 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar20 != &DAT_10038b78) {
          puVar22 = &DAT_10038b78;
          puVar24 = puVar20;
          for (iVar8 = (local_58 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar24 = *puVar22;
            puVar22 = puVar22 + 1;
            puVar24 = puVar24 + 1;
          }
          for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined1 *)puVar24 = *(undefined1 *)puVar22;
            puVar22 = (undefined4 *)((int)puVar22 + 1);
            puVar24 = (undefined4 *)((int)puVar24 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + local_58 * 0x20;
        DAT_10039078 = *(undefined1 **)(DAT_1003a024 + 0x30);
        DAT_10038b70 = 0;
        **(undefined1 **)(DAT_1003a024 + 0x30) = 8;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        if (*(int *)(DAT_1003a024 + 0x84) != 0) {
          *(undefined4 *)(DAT_1003a024 + 0x84) = 0;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 1;
        }
        if (*(int *)(DAT_1003a024 + 0x88) != 0) {
          *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 1;
        }
        if (*(int *)(DAT_1003a024 + 0x90) == 0) {
          *(undefined4 *)(DAT_1003a024 + 0x90) = 1;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 7;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0xe;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x17;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 3;
        }
        if (*(int *)(DAT_1003a024 + 0x8c) != 0) {
          *(undefined4 *)(DAT_1003a024 + 0x8c) = 0;
          if (*(int *)(DAT_1003a024 + 0x7c) == 0) {
            **(undefined4 **)(DAT_1003a024 + 0x30) = 0x1b;
          }
          else {
            **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
          }
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 1;
        }
        if (*(int *)(DAT_1003a024 + 0x94) != 0xff) {
          *(undefined4 *)(DAT_1003a024 + 0x94) = 0xff;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 1;
        }
        iVar8 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar8) {
          *(int *)(DAT_1003a024 + 0x98) = iVar8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar8;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar8;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 2;
        }
        **(undefined4 **)(DAT_1003a024 + 0x30) = 1;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        if (*(int *)(DAT_1003a024 + 0x80) == 0) {
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x15;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
        }
        else {
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x15;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 4;
        }
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        DAT_10038b70 = DAT_10038b70 + 2;
        *DAT_10039078 = 8;
        DAT_10039078[1] = 8;
        *(short *)(DAT_10039078 + 2) = (short)DAT_10038b70;
        DAT_10039078 = DAT_10039078 + 4;
        **(undefined1 **)(DAT_1003a024 + 0x30) = 9;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 0x10;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
        sVar18 = (short)((uint)((int)puVar20 - iVar7) >> 5);
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 10;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar18;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar18;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = local_58;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 0xc) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 0x10;
        if (((uint)*(undefined1 **)(DAT_1003a024 + 0x30) & 7) == 0) {
          **(undefined1 **)(DAT_1003a024 + 0x30) = 3;
          *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
          *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        }
        **(undefined1 **)(DAT_1003a024 + 0x30) = 3;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)local_58 / 2);
        iVar7 = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar15 = *(short **)(DAT_1003a024 + 0x30);
        if (0 < (int)local_58) {
          do {
            sVar11 = (short)iVar7 + sVar18;
            *psVar15 = sVar11;
            if (local_28[(int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2] == 0) {
              psVar15[1] = sVar11 + 2;
              psVar15[2] = sVar11 + 1;
              psVar15[3] = 0x700;
              psVar15[4] = sVar11 + 1;
              psVar15[5] = sVar11 + 2;
              psVar15[6] = sVar11 + 3;
            }
            else {
              psVar15[1] = sVar11 + 1;
              psVar15[2] = sVar11 + 2;
              psVar15[3] = 0x700;
              psVar15[4] = sVar11 + 1;
              psVar15[5] = sVar11 + 3;
              psVar15[6] = sVar11 + 2;
            }
            psVar15[7] = 0x700;
            psVar15 = psVar15 + 8;
            iVar7 = iVar7 + 4;
          } while (iVar7 < (int)local_58);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar15;
      }
    }
    else {
      local_40 = 0;
      local_58 = 0;
      if (bVar1 != 0) {
        local_4c = param_1 + 0xf;
        iVar19 = param_1[bVar1 + 0xe];
        local_59 = *(byte *)(param_1[bVar1 + 0xe] + 0x48);
        do {
          iVar2 = *local_4c;
          bVar1 = *(byte *)(iVar2 + 0x48);
          if ((bVar1 & local_59 & 0x3f) == 0) {
            fVar4 = (float)DAT_10042034;
            fVar5 = (float)DAT_10042038;
            (&DAT_10038b78)[local_58 * 8] = (float)*(int *)(iVar2 + 0x18) * _DAT_10034610 + fVar4;
            *(float *)(&DAT_10038b7c + local_58 * 0x20) =
                 (float)*(int *)(iVar2 + 0x1c) * _DAT_10034610 + fVar5;
            local_28[0] = ~(int)*(short *)(iVar2 + 0x22) & 0xffff;
            local_28[1] = 0;
            (&DAT_10038b80)[local_58 * 8] = (float)local_28[0] * _DAT_10034614 - fVar3;
            (&DAT_10038b84)[local_58 * 8] = 0x3f800000;
            uVar10 = *(uint *)(*param_1 + 8);
            local_44 = (uint)*(byte *)(((*(uint *)(iVar2 + 0x5c) & 0x1f0000) >> 0xb) +
                                       ((uVar10 & 0x7c0) >> 6) + DAT_100362d0);
            (&DAT_10038b88)[local_58 * 8] =
                 ((*(byte *)(((*(uint *)(iVar2 + 0x58) & 0x1f0000) >> 0xb) +
                             ((uVar10 & 0xf800) >> 0xb) + DAT_100362d0) | 0xffffffe0) << 0x10 |
                  local_44 << 8 |
                 (uint)*(byte *)(((*(uint *)(iVar2 + 0x60) & 0x1f0000) >> 0xb) + (uVar10 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar2 + 0x14)) {
              if (*(float *)(iVar2 + 0x14) <= _DAT_10036080) {
                lVar25 = __ftol();
                (&DAT_10038b8c)[local_58 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar25 * 4);
              }
              else {
                (&DAT_10038b8c)[local_58 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[local_58 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[local_58 * 8] = 0x3f800000;
            (&DAT_10038b94)[local_58 * 8] = 0x3f800000;
            iVar9 = local_58 + 1;
            (&DAT_10038b78)[iVar9 * 8] = (float)*(int *)(iVar19 + 0x18) * _DAT_10034610 + fVar4;
            *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
                 (float)*(int *)(iVar19 + 0x1c) * _DAT_10034610 + fVar5;
            local_28[0] = ~(int)*(short *)(iVar19 + 0x22) & 0xffff;
            local_28[1] = 0;
            (&DAT_10038b80)[iVar9 * 8] = (float)local_28[0] * _DAT_10034614 - fVar3;
            (&DAT_10038b84)[iVar9 * 8] = 0x3f800000;
            uVar10 = *(uint *)(*param_1 + 8);
            (&DAT_10038b88)[iVar9 * 8] =
                 ((*(byte *)(((*(uint *)(iVar19 + 0x5c) & 0x1f0000) >> 0xb) +
                             ((uVar10 & 0x7c0) >> 6) + DAT_100362d0) | 0xffffe000) << 8 |
                  (uint)*(byte *)(((*(uint *)(iVar19 + 0x58) & 0x1f0000) >> 0xb) +
                                  ((uVar10 & 0xf800) >> 0xb) + DAT_100362d0) << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar19 + 0x60) & 0x1f0000) >> 0xb) + (uVar10 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar19 + 0x14)) {
              if (*(float *)(iVar19 + 0x14) <= _DAT_10036080) {
                lVar25 = __ftol();
                (&DAT_10038b8c)[iVar9 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar25 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar9 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar9 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar9 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar9 * 8] = 0x3f800000;
            local_58 = local_58 + 2;
          }
          local_4c = local_4c + 1;
          local_40 = local_40 + 1;
          iVar19 = iVar2;
          local_59 = bVar1;
        } while (local_40 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
      }
      if ((((int)(iVar7 + local_58 * -0x20) < 1) || ((int)(iVar8 + (-0x1b - local_58) * 4) < 1)) &&
         (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
        return 0;
      }
      if (0 < (int)local_58) {
        puVar20 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar7 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar20 != &DAT_10038b78) {
          puVar22 = &DAT_10038b78;
          puVar24 = puVar20;
          for (iVar8 = (local_58 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar24 = *puVar22;
            puVar22 = puVar22 + 1;
            puVar24 = puVar24 + 1;
          }
          for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined1 *)puVar24 = *(undefined1 *)puVar22;
            puVar22 = (undefined4 *)((int)puVar22 + 1);
            puVar24 = (undefined4 *)((int)puVar24 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + local_58 * 0x20;
        DAT_10039078 = *(undefined1 **)(DAT_1003a024 + 0x30);
        DAT_10038b70 = 0;
        **(undefined1 **)(DAT_1003a024 + 0x30) = 8;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        if (*(int *)(DAT_1003a024 + 0x84) != 0) {
          *(undefined4 *)(DAT_1003a024 + 0x84) = 0;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 1;
        }
        if (*(int *)(DAT_1003a024 + 0x88) != 0) {
          *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 1;
        }
        if (*(int *)(DAT_1003a024 + 0x90) == 0) {
          *(undefined4 *)(DAT_1003a024 + 0x90) = 1;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 7;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0xe;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x17;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 3;
        }
        if (*(int *)(DAT_1003a024 + 0x8c) != 0) {
          *(undefined4 *)(DAT_1003a024 + 0x8c) = 0;
          if (*(int *)(DAT_1003a024 + 0x7c) == 0) {
            **(undefined4 **)(DAT_1003a024 + 0x30) = 0x1b;
          }
          else {
            **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
          }
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 1;
        }
        if (*(int *)(DAT_1003a024 + 0x94) != 0xff) {
          *(undefined4 *)(DAT_1003a024 + 0x94) = 0xff;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 1;
        }
        iVar8 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar8) {
          *(int *)(DAT_1003a024 + 0x98) = iVar8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar8;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar8;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          DAT_10038b70 = DAT_10038b70 + 2;
        }
        **(undefined4 **)(DAT_1003a024 + 0x30) = 1;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        if (*(int *)(DAT_1003a024 + 0x80) == 0) {
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x15;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
        }
        else {
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x15;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 4;
        }
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        DAT_10038b70 = DAT_10038b70 + 2;
        *DAT_10039078 = 8;
        DAT_10039078[1] = 8;
        *(short *)(DAT_10039078 + 2) = (short)DAT_10038b70;
        DAT_10039078 = DAT_10039078 + 4;
        **(undefined1 **)(DAT_1003a024 + 0x30) = 9;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 0x10;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 10;
        sVar18 = (short)((uint)((int)puVar20 - iVar7) >> 5);
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar18;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar18;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = local_58;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 0xc) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 0x10;
        if (((uint)*(undefined1 **)(DAT_1003a024 + 0x30) & 7) == 0) {
          **(undefined1 **)(DAT_1003a024 + 0x30) = 3;
          *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
          *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        }
        **(undefined1 **)(DAT_1003a024 + 0x30) = 2;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 4;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)local_58 / 2);
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar15 = *(short **)(DAT_1003a024 + 0x30);
        iVar7 = 0;
        psVar14 = psVar15;
        if (0 < (int)local_58) {
          do {
            sVar11 = (short)iVar7 + sVar18;
            psVar15 = psVar14 + 2;
            *psVar14 = sVar11;
            iVar7 = iVar7 + 2;
            psVar14[1] = sVar11 + 1;
            psVar14 = psVar15;
          } while (iVar7 < (int)local_58);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar15;
      }
    }
  }
  return 0;
}


