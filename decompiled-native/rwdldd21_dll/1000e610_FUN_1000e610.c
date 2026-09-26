// 1000e610 FUN_1000e610 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000e610(int *param_1,int param_2)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  short *psVar13;
  short *psVar14;
  uint uVar15;
  uint uVar16;
  short sVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  undefined4 *puVar21;
  float *pfVar22;
  undefined4 *puVar23;
  float *pfVar24;
  undefined4 *puVar25;
  longlong lVar26;
  byte local_55;
  uint local_54;
  undefined2 local_50;
  int local_48;
  int *local_44;
  int *local_2c;
  uint local_28 [10];
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar5 = FUN_1000d580(param_1,param_2);
    return uVar5;
  }
  bVar1 = *(byte *)(*param_1 + 0x30);
  if (((bVar1 & 0x80) != 0) || (param_2 == 0)) {
    fVar2 = _DAT_1003461c;
    if ((bVar1 & 0x40) != 0) {
      fVar2 = _DAT_10034620;
    }
    iVar6 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    uVar10 = *(uint *)(*param_1 + 8);
    iVar7 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    iVar9 = ((*(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + ((uVar10 & 0xf800) >> 0xb) +
                       DAT_100362d0) | 0xffffffe0) << 0x10 |
             (uint)*(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + ((uVar10 & 0x7c0) >> 6) +
                            DAT_100362d0) << 8 |
            (uint)*(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + (uVar10 & 0x1f) + DAT_100362d0)) <<
            3;
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      local_48 = 0;
      local_54 = 0;
      if (*(byte *)((int)param_1 + 0x3a) != 0) {
        local_2c = param_1 + 0xf;
        iVar18 = param_1[*(byte *)((int)param_1 + 0x3a) + 0xe];
        local_55 = *(byte *)(param_1[*(byte *)((int)param_1 + 0x3a) + 0xe] + 0x48);
        do {
          iVar20 = *local_2c;
          bVar1 = *(byte *)(iVar20 + 0x48);
          if ((bVar1 & local_55 & 0x3f) == 0) {
            fVar3 = (float)DAT_10042034;
            fVar4 = (float)DAT_10042038;
            (&DAT_10038b78)[local_54 * 8] = (float)*(int *)(iVar20 + 0x18) * _DAT_10034610 + fVar3;
            *(float *)(&DAT_10038b7c + local_54 * 0x20) =
                 (float)*(int *)(iVar20 + 0x1c) * _DAT_10034610 + fVar4;
            (&DAT_10038b80)[local_54 * 8] =
                 (float)(ushort)~*(ushort *)(iVar20 + 0x22) * _DAT_10034614 - fVar2;
            (&DAT_10038b84)[local_54 * 8] = 0x3f800000;
            (&DAT_10038b88)[local_54 * 8] = iVar9;
            if (_DAT_1003607c <= *(float *)(iVar20 + 0x14)) {
              if (*(float *)(iVar20 + 0x14) <= _DAT_10036080) {
                lVar26 = __ftol();
                (&DAT_10038b8c)[local_54 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar26 * 4);
              }
              else {
                (&DAT_10038b8c)[local_54 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[local_54 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[local_54 * 8] = 0x3f800000;
            (&DAT_10038b94)[local_54 * 8] = 0x3f800000;
            puVar21 = &DAT_10038b78 + local_54 * 8;
            puVar23 = &DAT_10038bb8 + local_54 * 8;
            for (iVar11 = 8; iVar11 != 0; iVar11 = iVar11 + -1) {
              *puVar23 = *puVar21;
              puVar21 = puVar21 + 1;
              puVar23 = puVar23 + 1;
            }
            iVar11 = local_54 + 1;
            (&DAT_10038b78)[iVar11 * 8] = (float)*(int *)(iVar18 + 0x18) * _DAT_10034610 + fVar3;
            *(float *)(&DAT_10038b7c + iVar11 * 0x20) =
                 (float)*(int *)(iVar18 + 0x1c) * _DAT_10034610 + fVar4;
            (&DAT_10038b80)[iVar11 * 8] =
                 (float)(ushort)~*(ushort *)(iVar18 + 0x22) * _DAT_10034614 - fVar2;
            (&DAT_10038b84)[iVar11 * 8] = 0x3f800000;
            (&DAT_10038b88)[iVar11 * 8] = iVar9;
            if (_DAT_1003607c <= *(float *)(iVar18 + 0x14)) {
              if (*(float *)(iVar18 + 0x14) <= _DAT_10036080) {
                lVar26 = __ftol();
                (&DAT_10038b8c)[iVar11 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar26 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar11 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar11 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar11 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar11 * 8] = 0x3f800000;
            pfVar22 = (float *)(&DAT_10038b78 + iVar11 * 8);
            pfVar24 = (float *)(&DAT_10038bb8 + iVar11 * 8);
            for (iVar19 = 8; iVar19 != 0; iVar19 = iVar19 + -1) {
              *pfVar24 = *pfVar22;
              pfVar22 = pfVar22 + 1;
              pfVar24 = pfVar24 + 1;
            }
            iVar11 = local_54 + 2;
            uVar12 = *(int *)(iVar20 + 0x18) - *(int *)(iVar18 + 0x18);
            uVar15 = (int)uVar12 >> 0x1f;
            uVar10 = *(int *)(iVar20 + 0x1c) - *(int *)(iVar18 + 0x1c);
            uVar16 = (int)uVar10 >> 0x1f;
            if ((int)((uVar10 ^ uVar16) - uVar16) < (int)((uVar12 ^ uVar15) - uVar15)) {
              local_28[(int)(local_54 + ((int)local_54 >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar20 + 0x18) < *(int *)(iVar18 + 0x18));
              *(float *)(&DAT_10038b7c + iVar11 * 0x20) =
                   *(float *)(&DAT_10038b7c + iVar11 * 0x20) + _DAT_10034618;
              (&DAT_10038b9c)[iVar11 * 8] = (float)(&DAT_10038b9c)[iVar11 * 8] + _DAT_10034618;
            }
            else {
              local_28[(int)(local_54 + ((int)local_54 >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar18 + 0x1c) < *(int *)(iVar20 + 0x1c));
              (&DAT_10038b78)[iVar11 * 8] = (float)(&DAT_10038b78)[iVar11 * 8] + _DAT_10034618;
              (&DAT_10038b98)[iVar11 * 8] = (float)(&DAT_10038b98)[iVar11 * 8] + _DAT_10034618;
            }
            local_54 = local_54 + 4;
          }
          local_2c = local_2c + 1;
          local_48 = local_48 + 1;
          iVar18 = iVar20;
          local_55 = bVar1;
        } while (local_48 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
      }
      local_50 = (undefined2)((int)local_54 / 2);
      if ((((int)(iVar6 + local_54 * -0x20) < 1) || (iVar7 - (((int)local_54 / 2) * 8 + 0x6c) < 1))
         && (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
        return 0;
      }
      if (0 < (int)local_54) {
        puVar21 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar6 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar21 != &DAT_10038b78) {
          puVar23 = &DAT_10038b78;
          puVar25 = puVar21;
          for (iVar7 = (local_54 & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar25 = *puVar23;
            puVar23 = puVar23 + 1;
            puVar25 = puVar25 + 1;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined1 *)puVar25 = *(undefined1 *)puVar23;
            puVar23 = (undefined4 *)((int)puVar23 + 1);
            puVar25 = (undefined4 *)((int)puVar25 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + local_54 * 0x20;
        DAT_10039078 = *(undefined1 **)(DAT_1003a024 + 0x30);
        DAT_10038b70 = 0;
        **(undefined1 **)(DAT_1003a024 + 0x30) = 8;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        if (*(int *)(DAT_1003a024 + 0x84) == 0) {
          *(undefined4 *)(DAT_1003a024 + 0x84) = 1;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
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
        iVar7 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar7) {
          *(int *)(DAT_1003a024 + 0x98) = iVar7;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar7;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar7;
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
        sVar17 = (short)((uint)((int)puVar21 - iVar6) >> 5);
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar17;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar17;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = local_54;
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
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = local_50;
        iVar6 = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar14 = *(short **)(DAT_1003a024 + 0x30);
        if (0 < (int)local_54) {
          do {
            uVar10 = local_28[(int)(iVar6 + (iVar6 >> 0x1f & 3U)) >> 2];
            sVar8 = sVar17 + (short)iVar6;
            *psVar14 = sVar8;
            if (uVar10 == 0) {
              psVar14[1] = sVar8 + 2;
              psVar14[2] = sVar8 + 1;
              psVar14[3] = 0x700;
              psVar14[4] = sVar8 + 1;
              psVar14[5] = sVar8 + 2;
              psVar14[6] = sVar8 + 3;
            }
            else {
              psVar14[1] = sVar8 + 1;
              psVar14[2] = sVar8 + 2;
              psVar14[3] = 0x700;
              psVar14[4] = sVar8 + 1;
              psVar14[5] = sVar8 + 3;
              psVar14[6] = sVar8 + 2;
            }
            psVar14[7] = 0x700;
            psVar14 = psVar14 + 8;
            iVar6 = iVar6 + 4;
          } while (iVar6 < (int)local_54);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar14;
      }
    }
    else {
      iVar18 = 0;
      local_48 = 0;
      if (*(byte *)((int)param_1 + 0x3a) != 0) {
        local_44 = param_1 + 0xf;
        iVar20 = param_1[*(byte *)((int)param_1 + 0x3a) + 0xe];
        local_55 = *(byte *)(param_1[*(byte *)((int)param_1 + 0x3a) + 0xe] + 0x48);
        do {
          iVar11 = *local_44;
          bVar1 = *(byte *)(iVar11 + 0x48);
          if ((bVar1 & local_55 & 0x3f) == 0) {
            fVar3 = (float)DAT_10042034;
            fVar4 = (float)DAT_10042038;
            (&DAT_10038b78)[iVar18 * 8] = (float)*(int *)(iVar11 + 0x18) * _DAT_10034610 + fVar3;
            *(float *)(&DAT_10038b7c + iVar18 * 0x20) =
                 (float)*(int *)(iVar11 + 0x1c) * _DAT_10034610 + fVar4;
            local_28[0] = ~(int)*(short *)(iVar11 + 0x22) & 0xffff;
            local_28[1] = 0;
            (&DAT_10038b80)[iVar18 * 8] = (float)local_28[0] * _DAT_10034614 - fVar2;
            (&DAT_10038b84)[iVar18 * 8] = 0x3f800000;
            (&DAT_10038b88)[iVar18 * 8] = iVar9;
            if (_DAT_1003607c <= *(float *)(iVar11 + 0x14)) {
              if (*(float *)(iVar11 + 0x14) <= _DAT_10036080) {
                lVar26 = __ftol();
                (&DAT_10038b8c)[iVar18 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar26 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar18 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar18 * 8] = 0xff000000;
            }
            iVar19 = iVar18 + 1;
            (&DAT_10038b90)[iVar18 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar18 * 8] = 0x3f800000;
            (&DAT_10038b78)[iVar19 * 8] = (float)*(int *)(iVar20 + 0x18) * _DAT_10034610 + fVar3;
            *(float *)(&DAT_10038b7c + iVar19 * 0x20) =
                 (float)*(int *)(iVar20 + 0x1c) * _DAT_10034610 + fVar4;
            local_28[0] = ~(int)*(short *)(iVar20 + 0x22) & 0xffff;
            local_28[1] = 0;
            (&DAT_10038b80)[iVar19 * 8] = (float)local_28[0] * _DAT_10034614 - fVar2;
            (&DAT_10038b84)[iVar19 * 8] = 0x3f800000;
            (&DAT_10038b88)[iVar19 * 8] = iVar9;
            if (_DAT_1003607c <= *(float *)(iVar20 + 0x14)) {
              if (*(float *)(iVar20 + 0x14) <= _DAT_10036080) {
                lVar26 = __ftol();
                (&DAT_10038b8c)[iVar19 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar26 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar19 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar19 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar19 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar19 * 8] = 0x3f800000;
            iVar18 = iVar18 + 2;
          }
          local_44 = local_44 + 1;
          local_48 = local_48 + 1;
          iVar20 = iVar11;
          local_55 = bVar1;
        } while (local_48 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
      }
      local_28[0] = iVar18 * 0x20;
      if (((iVar6 + iVar18 * -0x20 < 1) || (iVar7 + (-0x1b - iVar18) * 4 < 1)) &&
         (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
        return 0;
      }
      if (0 < iVar18) {
        puVar21 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar6 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar21 != &DAT_10038b78) {
          puVar23 = &DAT_10038b78;
          puVar25 = puVar21;
          for (uVar10 = local_28[0] >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
            *puVar25 = *puVar23;
            puVar23 = puVar23 + 1;
            puVar25 = puVar25 + 1;
          }
          for (uVar10 = local_28[0] & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
            *(undefined1 *)puVar25 = *(undefined1 *)puVar23;
            puVar23 = (undefined4 *)((int)puVar23 + 1);
            puVar25 = (undefined4 *)((int)puVar25 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + local_28[0];
        DAT_10039078 = *(undefined1 **)(DAT_1003a024 + 0x30);
        DAT_10038b70 = 0;
        **(undefined1 **)(DAT_1003a024 + 0x30) = 8;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        if (*(int *)(DAT_1003a024 + 0x84) == 0) {
          *(undefined4 *)(DAT_1003a024 + 0x84) = 1;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
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
        iVar7 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar7) {
          *(int *)(DAT_1003a024 + 0x98) = iVar7;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar7;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar7;
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
        sVar17 = (short)((uint)((int)puVar21 - iVar6) >> 5);
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar17;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar17;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 8) = iVar18;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)(iVar18 / 2);
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar14 = *(short **)(DAT_1003a024 + 0x30);
        iVar6 = 0;
        psVar13 = psVar14;
        if (0 < iVar18) {
          do {
            sVar8 = sVar17 + (short)iVar6;
            psVar14 = psVar13 + 2;
            *psVar13 = sVar8;
            iVar6 = iVar6 + 2;
            psVar13[1] = sVar8 + 1;
            psVar13 = psVar14;
          } while (iVar6 < iVar18);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar14;
      }
    }
  }
  return 0;
}


