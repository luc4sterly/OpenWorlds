// 10012d00 FUN_10012d00 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10012d00(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  byte bVar15;
  short sVar16;
  short *psVar17;
  short *psVar18;
  uint uVar19;
  uint uVar20;
  int *piVar21;
  undefined4 *puVar22;
  float *pfVar23;
  undefined4 *puVar24;
  undefined4 *puVar25;
  float *pfVar26;
  longlong lVar27;
  byte local_55;
  uint local_54;
  short local_50;
  int local_3c;
  int *local_30;
  int local_2c;
  uint local_28 [10];
  
  fVar2 = _DAT_1003461c;
  if ((*(byte *)(*param_1 + 0x30) & 0x40) != 0) {
    fVar2 = _DAT_10034620;
  }
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar6 = FUN_10011c60(param_1);
    return uVar6;
  }
  iVar7 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  iVar8 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
  uVar11 = *(uint *)(*param_1 + 8);
  iVar10 = param_1[0xf];
  iVar12 = ((*(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + ((uVar11 & 0xf800) >> 0xb) + DAT_100362d0
                      ) | 0xffffffe0) << 0x10 |
            (uint)*(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + ((uVar11 & 0x7c0) >> 6) +
                           DAT_100362d0) << 8 |
           (uint)*(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + (uVar11 & 0x1f) + DAT_100362d0)) << 3
  ;
  local_3c = 1;
  uVar11 = (uint)*(byte *)((int)param_1 + 0x3a);
  local_54 = 0;
  local_55 = *(byte *)(iVar10 + 0x48);
  if (1 < *(byte *)((int)param_1 + 0x3a)) {
    piVar21 = param_1 + 0x10;
    bVar15 = *(byte *)(param_1[uVar11 + 0xe] + 0x48);
    do {
      if ((local_55 & bVar15 & 0x3f) == 0) break;
      iVar10 = *piVar21;
      piVar21 = piVar21 + 1;
      local_3c = local_3c + 1;
      bVar15 = local_55;
      local_55 = *(byte *)(iVar10 + 0x48);
    } while (local_3c < (int)uVar11);
  }
  if (*(int *)(DAT_1003a024 + 0x74) == 0) {
    if (local_3c < (int)uVar11) {
      local_2c = uVar11 - local_3c;
      local_30 = param_1 + local_3c + 0xf;
      do {
        iVar1 = *local_30;
        bVar15 = *(byte *)(iVar1 + 0x48);
        if ((bVar15 & local_55 & 0x3f) == 0) {
          fVar3 = (float)DAT_10042034;
          fVar4 = (float)DAT_10042038;
          (&DAT_10038b78)[local_54 * 8] = (float)*(int *)(iVar1 + 0x18) * _DAT_10034610 + fVar3;
          *(float *)(&DAT_10038b7c + local_54 * 0x20) =
               (float)*(int *)(iVar1 + 0x1c) * _DAT_10034610 + fVar4;
          (&DAT_10038b80)[local_54 * 8] =
               (float)(ushort)~*(ushort *)(iVar1 + 0x22) * _DAT_10034614 - fVar2;
          (&DAT_10038b84)[local_54 * 8] = 0x3f800000;
          (&DAT_10038b88)[local_54 * 8] = iVar12;
          if (_DAT_1003607c <= *(float *)(iVar1 + 0x14)) {
            if (*(float *)(iVar1 + 0x14) <= _DAT_10036080) {
              lVar27 = __ftol();
              (&DAT_10038b8c)[local_54 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar27 * 4);
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
          puVar22 = &DAT_10038b78 + local_54 * 8;
          puVar24 = &DAT_10038bb8 + local_54 * 8;
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar24 = *puVar22;
            puVar22 = puVar22 + 1;
            puVar24 = puVar24 + 1;
          }
          iVar9 = local_54 + 1;
          (&DAT_10038b78)[iVar9 * 8] = (float)*(int *)(iVar10 + 0x18) * _DAT_10034610 + fVar3;
          *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
               (float)*(int *)(iVar10 + 0x1c) * _DAT_10034610 + fVar4;
          (&DAT_10038b80)[iVar9 * 8] =
               (float)(ushort)~*(ushort *)(iVar10 + 0x22) * _DAT_10034614 - fVar2;
          (&DAT_10038b84)[iVar9 * 8] = 0x3f800000;
          (&DAT_10038b88)[iVar9 * 8] = iVar12;
          if (_DAT_1003607c <= *(float *)(iVar10 + 0x14)) {
            if (*(float *)(iVar10 + 0x14) <= _DAT_10036080) {
              lVar27 = __ftol();
              (&DAT_10038b8c)[iVar9 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar27 * 4);
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
          pfVar23 = (float *)(&DAT_10038b78 + iVar9 * 8);
          pfVar26 = (float *)(&DAT_10038bb8 + iVar9 * 8);
          for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
            *pfVar26 = *pfVar23;
            pfVar23 = pfVar23 + 1;
            pfVar26 = pfVar26 + 1;
          }
          iVar9 = local_54 + 2;
          uVar14 = *(int *)(iVar1 + 0x18) - *(int *)(iVar10 + 0x18);
          uVar19 = (int)uVar14 >> 0x1f;
          uVar11 = *(int *)(iVar1 + 0x1c) - *(int *)(iVar10 + 0x1c);
          uVar20 = (int)uVar11 >> 0x1f;
          if ((int)((uVar11 ^ uVar20) - uVar20) < (int)((uVar14 ^ uVar19) - uVar19)) {
            local_28[(int)(local_54 + ((int)local_54 >> 0x1f & 3U)) >> 2] =
                 (uint)(*(int *)(iVar1 + 0x18) < *(int *)(iVar10 + 0x18));
            *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
                 *(float *)(&DAT_10038b7c + iVar9 * 0x20) + _DAT_10034618;
            (&DAT_10038b9c)[iVar9 * 8] = (float)(&DAT_10038b9c)[iVar9 * 8] + _DAT_10034618;
          }
          else {
            local_28[(int)(local_54 + ((int)local_54 >> 0x1f & 3U)) >> 2] =
                 (uint)(*(int *)(iVar10 + 0x1c) < *(int *)(iVar1 + 0x1c));
            (&DAT_10038b78)[iVar9 * 8] = (float)(&DAT_10038b78)[iVar9 * 8] + _DAT_10034618;
            (&DAT_10038b98)[iVar9 * 8] = (float)(&DAT_10038b98)[iVar9 * 8] + _DAT_10034618;
          }
          local_54 = local_54 + 4;
        }
        local_2c = local_2c + -1;
        iVar10 = iVar1;
        local_55 = bVar15;
        local_30 = local_30 + 1;
      } while (local_2c != 0);
    }
    if ((((int)(iVar7 + local_54 * -0x20) < 1) || (iVar8 - (((int)local_54 / 2) * 8 + 0x6c) < 1)) &&
       (iVar10 = FUN_10001080(DAT_1003a024), iVar10 == 0)) {
      return 0;
    }
    if (0 < (int)local_54) {
      puVar22 = *(undefined4 **)(DAT_1003a024 + 0x28);
      local_50 = (short)((uint)((int)puVar22 - *(int *)(DAT_1003a024 + 0x24)) >> 5);
      if (puVar22 != &DAT_10038b78) {
        puVar24 = &DAT_10038b78;
        for (iVar10 = (local_54 & 0x7ffffff) << 3; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar22 = *puVar24;
          puVar24 = puVar24 + 1;
          puVar22 = puVar22 + 1;
        }
        for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
          *(undefined1 *)puVar22 = *(undefined1 *)puVar24;
          puVar24 = (undefined4 *)((int)puVar24 + 1);
          puVar22 = (undefined4 *)((int)puVar22 + 1);
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
      iVar10 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar10) {
        *(int *)(DAT_1003a024 + 0x98) = iVar10;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar10;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar10;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = local_50;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = local_50;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)local_54 / 2);
      iVar10 = 0;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar18 = *(short **)(DAT_1003a024 + 0x30);
      if (0 < (int)local_54) {
        do {
          if (local_28[(int)(iVar10 + (iVar10 >> 0x1f & 3U)) >> 2] == 0) {
            sVar16 = local_50 + (short)iVar10;
            *psVar18 = sVar16;
            psVar18[1] = sVar16 + 2;
            psVar18[2] = sVar16 + 1;
            psVar18[3] = 0x700;
            psVar18[4] = sVar16 + 1;
            psVar18[5] = sVar16 + 2;
            psVar18[6] = sVar16 + 3;
          }
          else {
            sVar16 = local_50 + (short)iVar10;
            *psVar18 = sVar16;
            psVar18[1] = sVar16 + 1;
            psVar18[2] = sVar16 + 2;
            psVar18[3] = 0x700;
            psVar18[4] = sVar16 + 1;
            psVar18[5] = sVar16 + 3;
            psVar18[6] = sVar16 + 2;
          }
          psVar18[7] = 0x700;
          psVar18 = psVar18 + 8;
          iVar10 = iVar10 + 4;
        } while (iVar10 < (int)local_54);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar18;
    }
  }
  else {
    if (local_3c < (int)uVar11) {
      piVar21 = param_1 + local_3c + 0xf;
      local_3c = uVar11 - local_3c;
      do {
        iVar1 = *piVar21;
        piVar21 = piVar21 + 1;
        bVar15 = *(byte *)(iVar1 + 0x48);
        if ((bVar15 & local_55 & 0x3f) == 0) {
          fVar3 = (float)DAT_10042034;
          fVar4 = (float)DAT_10042038;
          (&DAT_10038b78)[local_54 * 8] = (float)*(int *)(iVar1 + 0x18) * _DAT_10034610 + fVar3;
          *(float *)(&DAT_10038b7c + local_54 * 0x20) =
               (float)*(int *)(iVar1 + 0x1c) * _DAT_10034610 + fVar4;
          local_28[0] = ~(int)*(short *)(iVar1 + 0x22) & 0xffff;
          local_28[1] = 0;
          (&DAT_10038b80)[local_54 * 8] = (float)local_28[0] * _DAT_10034614 - fVar2;
          (&DAT_10038b84)[local_54 * 8] = 0x3f800000;
          (&DAT_10038b88)[local_54 * 8] = iVar12;
          if (_DAT_1003607c <= *(float *)(iVar1 + 0x14)) {
            if (*(float *)(iVar1 + 0x14) <= _DAT_10036080) {
              lVar27 = __ftol();
              (&DAT_10038b8c)[local_54 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar27 * 4);
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
          iVar9 = local_54 + 1;
          (&DAT_10038b78)[iVar9 * 8] = (float)*(int *)(iVar10 + 0x18) * _DAT_10034610 + fVar3;
          *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
               (float)*(int *)(iVar10 + 0x1c) * _DAT_10034610 + fVar4;
          local_28[0] = ~(int)*(short *)(iVar10 + 0x22) & 0xffff;
          local_28[1] = 0;
          (&DAT_10038b80)[iVar9 * 8] = (float)local_28[0] * _DAT_10034614 - fVar2;
          (&DAT_10038b84)[iVar9 * 8] = 0x3f800000;
          (&DAT_10038b88)[iVar9 * 8] = iVar12;
          if (_DAT_1003607c <= *(float *)(iVar10 + 0x14)) {
            if (*(float *)(iVar10 + 0x14) <= _DAT_10036080) {
              lVar27 = __ftol();
              (&DAT_10038b8c)[iVar9 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar27 * 4);
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
          local_54 = local_54 + 2;
        }
        local_3c = local_3c + -1;
        iVar10 = iVar1;
        local_55 = bVar15;
      } while (local_3c != 0);
    }
    if ((((int)(iVar7 + local_54 * -0x20) < 1) || ((int)(iVar8 + (-0x1b - local_54) * 4) < 1)) &&
       (iVar10 = FUN_10001080(DAT_1003a024), iVar10 == 0)) {
      return 0;
    }
    if (0 < (int)local_54) {
      puVar22 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar10 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar22 != &DAT_10038b78) {
        puVar24 = &DAT_10038b78;
        puVar25 = puVar22;
        for (iVar7 = (local_54 & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar25 = *puVar24;
          puVar24 = puVar24 + 1;
          puVar25 = puVar25 + 1;
        }
        for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined1 *)puVar25 = *(undefined1 *)puVar24;
          puVar24 = (undefined4 *)((int)puVar24 + 1);
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
      sVar16 = (short)((uint)((int)puVar22 - iVar10) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar16;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar16;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = local_54;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)local_54 / 2);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      iVar10 = 0;
      psVar18 = *(short **)(DAT_1003a024 + 0x30);
      psVar17 = psVar18;
      if (0 < (int)local_54) {
        do {
          sVar5 = sVar16 + (short)iVar10;
          psVar18 = psVar17 + 2;
          *psVar17 = sVar5;
          iVar10 = iVar10 + 2;
          psVar17[1] = sVar5 + 1;
          psVar17 = psVar18;
        } while (iVar10 < (int)local_54);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar18;
    }
  }
  return 0;
}


