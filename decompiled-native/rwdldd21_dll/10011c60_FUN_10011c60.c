// 10011c60 FUN_10011c60 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10011c60(int *param_1)

{
  byte bVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  short *psVar15;
  short *psVar16;
  uint uVar17;
  uint uVar18;
  int *piVar19;
  undefined4 *puVar20;
  float *pfVar21;
  undefined4 *puVar22;
  undefined4 *puVar23;
  float *pfVar24;
  longlong lVar25;
  byte bStack_51;
  uint uStack_50;
  short sStack_4c;
  int iStack_38;
  int *piStack_30;
  int iStack_2c;
  uint auStack_28 [10];
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  iVar7 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  iVar8 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
  uVar11 = *(uint *)(*param_1 + 8);
  iVar12 = ((*(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + ((uVar11 & 0x7c0) >> 6) + DAT_100362d0) |
            0xffffe000) << 8 |
            (uint)*(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + ((uVar11 & 0xf800) >> 0xb) +
                           DAT_100362d0) << 0x10 |
           (uint)*(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + (uVar11 & 0x1f) + DAT_100362d0)) << 3
  ;
  iVar10 = param_1[0xf];
  iStack_38 = 1;
  uVar11 = (uint)*(byte *)((int)param_1 + 0x3a);
  uStack_50 = 0;
  auStack_28[0] = CONCAT31(auStack_28[0]._1_3_,*(undefined1 *)(param_1[uVar11 + 0xe] + 0x48));
  bStack_51 = *(byte *)(iVar10 + 0x48);
  if (1 < *(byte *)((int)param_1 + 0x3a)) {
    piVar19 = param_1 + 0x10;
    do {
      if ((bStack_51 & (byte)auStack_28[0] & 0x3f) == 0) break;
      iVar10 = *piVar19;
      piVar19 = piVar19 + 1;
      iStack_38 = iStack_38 + 1;
      auStack_28[0] = CONCAT31(auStack_28[0]._1_3_,bStack_51);
      bStack_51 = *(byte *)(iVar10 + 0x48);
    } while (iStack_38 < (int)uVar11);
  }
  if (*(int *)(DAT_1003a024 + 0x74) == 0) {
    if (iStack_38 < (int)uVar11) {
      iStack_2c = uVar11 - iStack_38;
      piStack_30 = param_1 + iStack_38 + 0xf;
      do {
        iVar2 = *piStack_30;
        bVar1 = *(byte *)(iVar2 + 0x48);
        if ((bVar1 & bStack_51 & 0x3f) == 0) {
          fVar3 = (float)DAT_10042034;
          fVar4 = (float)DAT_10042038;
          (&DAT_10038b78)[uStack_50 * 8] = (float)*(int *)(iVar2 + 0x18) * _DAT_10034610 + fVar3;
          *(float *)(&DAT_10038b7c + uStack_50 * 0x20) =
               (float)*(int *)(iVar2 + 0x1c) * _DAT_10034610 + fVar4;
          (&DAT_10038b80)[uStack_50 * 8] = (float)(ushort)~*(ushort *)(iVar2 + 0x22) * _DAT_10034614
          ;
          (&DAT_10038b84)[uStack_50 * 8] = 0x3f800000;
          (&DAT_10038b88)[uStack_50 * 8] = iVar12;
          if (_DAT_1003607c <= *(float *)(iVar2 + 0x14)) {
            if (*(float *)(iVar2 + 0x14) <= _DAT_10036080) {
              lVar25 = __ftol();
              (&DAT_10038b8c)[uStack_50 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar25 * 4);
            }
            else {
              (&DAT_10038b8c)[uStack_50 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[uStack_50 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[uStack_50 * 8] = 0x3f800000;
          (&DAT_10038b94)[uStack_50 * 8] = 0x3f800000;
          puVar20 = &DAT_10038b78 + uStack_50 * 8;
          puVar22 = &DAT_10038bb8 + uStack_50 * 8;
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar22 = *puVar20;
            puVar20 = puVar20 + 1;
            puVar22 = puVar22 + 1;
          }
          iVar9 = uStack_50 + 1;
          (&DAT_10038b78)[iVar9 * 8] = (float)*(int *)(iVar10 + 0x18) * _DAT_10034610 + fVar3;
          *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
               (float)*(int *)(iVar10 + 0x1c) * _DAT_10034610 + fVar4;
          (&DAT_10038b80)[iVar9 * 8] = (float)(ushort)~*(ushort *)(iVar10 + 0x22) * _DAT_10034614;
          (&DAT_10038b84)[iVar9 * 8] = 0x3f800000;
          (&DAT_10038b88)[iVar9 * 8] = iVar12;
          if (_DAT_1003607c <= *(float *)(iVar10 + 0x14)) {
            if (*(float *)(iVar10 + 0x14) <= _DAT_10036080) {
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
          pfVar24 = (float *)(&DAT_10038bb8 + iVar9 * 8);
          for (iVar13 = 8; iVar13 != 0; iVar13 = iVar13 + -1) {
            *pfVar24 = *pfVar21;
            pfVar21 = pfVar21 + 1;
            pfVar24 = pfVar24 + 1;
          }
          iVar9 = uStack_50 + 2;
          uVar14 = *(int *)(iVar2 + 0x18) - *(int *)(iVar10 + 0x18);
          uVar17 = (int)uVar14 >> 0x1f;
          uVar11 = *(int *)(iVar2 + 0x1c) - *(int *)(iVar10 + 0x1c);
          uVar18 = (int)uVar11 >> 0x1f;
          if ((int)((uVar11 ^ uVar18) - uVar18) < (int)((uVar14 ^ uVar17) - uVar17)) {
            auStack_28[(int)(uStack_50 + ((int)uStack_50 >> 0x1f & 3U)) >> 2] =
                 (uint)(*(int *)(iVar2 + 0x18) < *(int *)(iVar10 + 0x18));
            *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
                 *(float *)(&DAT_10038b7c + iVar9 * 0x20) + _DAT_10034618;
            (&DAT_10038b9c)[iVar9 * 8] = (float)(&DAT_10038b9c)[iVar9 * 8] + _DAT_10034618;
          }
          else {
            auStack_28[(int)(uStack_50 + ((int)uStack_50 >> 0x1f & 3U)) >> 2] =
                 (uint)(*(int *)(iVar10 + 0x1c) < *(int *)(iVar2 + 0x1c));
            (&DAT_10038b78)[iVar9 * 8] = (float)(&DAT_10038b78)[iVar9 * 8] + _DAT_10034618;
            (&DAT_10038b98)[iVar9 * 8] = (float)(&DAT_10038b98)[iVar9 * 8] + _DAT_10034618;
          }
          uStack_50 = uStack_50 + 4;
        }
        iStack_2c = iStack_2c + -1;
        iVar10 = iVar2;
        bStack_51 = bVar1;
        piStack_30 = piStack_30 + 1;
      } while (iStack_2c != 0);
    }
    if ((((int)(iVar7 + uStack_50 * -0x20) < 1) || (iVar8 - (((int)uStack_50 / 2) * 8 + 0x6c) < 1))
       && (iVar10 = FUN_10001080(DAT_1003a024), iVar10 == 0)) {
      return 0;
    }
    if (0 < (int)uStack_50) {
      puVar20 = *(undefined4 **)(DAT_1003a024 + 0x28);
      sStack_4c = (short)((uint)((int)puVar20 - *(int *)(DAT_1003a024 + 0x24)) >> 5);
      if (puVar20 != &DAT_10038b78) {
        puVar22 = &DAT_10038b78;
        for (iVar10 = (uStack_50 & 0x7ffffff) << 3; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar20 = *puVar22;
          puVar22 = puVar22 + 1;
          puVar20 = puVar20 + 1;
        }
        for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
          *(undefined1 *)puVar20 = *(undefined1 *)puVar22;
          puVar22 = (undefined4 *)((int)puVar22 + 1);
          puVar20 = (undefined4 *)((int)puVar20 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack_50 * 0x20;
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
      if (*(int *)(DAT_1003a024 + 0x90) != 0) {
        *(undefined4 *)(DAT_1003a024 + 0x90) = 0;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 7;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0xe;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x17;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 8;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sStack_4c;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sStack_4c;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack_50;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)uStack_50 / 2);
      iVar10 = 0;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar16 = *(short **)(DAT_1003a024 + 0x30);
      if (0 < (int)uStack_50) {
        do {
          uVar11 = auStack_28[(int)(iVar10 + (iVar10 >> 0x1f & 3U)) >> 2];
          sVar6 = sStack_4c + (short)iVar10;
          *psVar16 = sVar6;
          if (uVar11 == 0) {
            psVar16[1] = sVar6 + 2;
            psVar16[2] = sVar6 + 1;
            psVar16[3] = 0x700;
            psVar16[4] = sVar6 + 1;
            psVar16[5] = sVar6 + 2;
            psVar16[6] = sVar6 + 3;
          }
          else {
            psVar16[1] = sVar6 + 1;
            psVar16[2] = sVar6 + 2;
            psVar16[3] = 0x700;
            psVar16[4] = sVar6 + 1;
            psVar16[5] = sVar6 + 3;
            psVar16[6] = sVar6 + 2;
          }
          psVar16[7] = 0x700;
          psVar16 = psVar16 + 8;
          iVar10 = iVar10 + 4;
        } while (iVar10 < (int)uStack_50);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar16;
    }
  }
  else {
    if (iStack_38 < (int)uVar11) {
      piVar19 = param_1 + iStack_38 + 0xf;
      iStack_38 = uVar11 - iStack_38;
      do {
        iVar2 = *piVar19;
        piVar19 = piVar19 + 1;
        bVar1 = *(byte *)(iVar2 + 0x48);
        if ((bVar1 & bStack_51 & 0x3f) == 0) {
          fVar3 = (float)DAT_10042034;
          fVar4 = (float)DAT_10042038;
          (&DAT_10038b78)[uStack_50 * 8] = (float)*(int *)(iVar2 + 0x18) * _DAT_10034610 + fVar3;
          *(float *)(&DAT_10038b7c + uStack_50 * 0x20) =
               (float)*(int *)(iVar2 + 0x1c) * _DAT_10034610 + fVar4;
          auStack_28[0] = ~(int)*(short *)(iVar2 + 0x22) & 0xffff;
          auStack_28[1] = 0;
          (&DAT_10038b80)[uStack_50 * 8] = (float)auStack_28[0] * _DAT_10034614;
          (&DAT_10038b84)[uStack_50 * 8] = 0x3f800000;
          (&DAT_10038b88)[uStack_50 * 8] = iVar12;
          if (_DAT_1003607c <= *(float *)(iVar2 + 0x14)) {
            if (*(float *)(iVar2 + 0x14) <= _DAT_10036080) {
              lVar25 = __ftol();
              (&DAT_10038b8c)[uStack_50 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar25 * 4);
            }
            else {
              (&DAT_10038b8c)[uStack_50 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[uStack_50 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[uStack_50 * 8] = 0x3f800000;
          (&DAT_10038b94)[uStack_50 * 8] = 0x3f800000;
          iVar9 = uStack_50 + 1;
          (&DAT_10038b78)[iVar9 * 8] = (float)*(int *)(iVar10 + 0x18) * _DAT_10034610 + fVar3;
          *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
               (float)*(int *)(iVar10 + 0x1c) * _DAT_10034610 + fVar4;
          auStack_28[0] = ~(int)*(short *)(iVar10 + 0x22) & 0xffff;
          auStack_28[1] = 0;
          (&DAT_10038b80)[iVar9 * 8] = (float)auStack_28[0] * _DAT_10034614;
          (&DAT_10038b84)[iVar9 * 8] = 0x3f800000;
          (&DAT_10038b88)[iVar9 * 8] = iVar12;
          if (_DAT_1003607c <= *(float *)(iVar10 + 0x14)) {
            if (*(float *)(iVar10 + 0x14) <= _DAT_10036080) {
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
          uStack_50 = uStack_50 + 2;
        }
        iStack_38 = iStack_38 + -1;
        iVar10 = iVar2;
        bStack_51 = bVar1;
      } while (iStack_38 != 0);
    }
    if ((((int)(iVar7 + uStack_50 * -0x20) < 1) || ((int)(iVar8 + (-0x1b - uStack_50) * 4) < 1)) &&
       (iVar10 = FUN_10001080(DAT_1003a024), iVar10 == 0)) {
      return 0;
    }
    if (0 < (int)uStack_50) {
      puVar20 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar10 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar20 != &DAT_10038b78) {
        puVar22 = &DAT_10038b78;
        puVar23 = puVar20;
        for (iVar7 = (uStack_50 & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar23 = *puVar22;
          puVar22 = puVar22 + 1;
          puVar23 = puVar23 + 1;
        }
        for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined1 *)puVar23 = *(undefined1 *)puVar22;
          puVar22 = (undefined4 *)((int)puVar22 + 1);
          puVar23 = (undefined4 *)((int)puVar23 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack_50 * 0x20;
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
      if (*(int *)(DAT_1003a024 + 0x90) != 0) {
        *(undefined4 *)(DAT_1003a024 + 0x90) = 0;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 7;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0xe;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x17;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 8;
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
      sVar6 = (short)((uint)((int)puVar20 - iVar10) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar6;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar6;
      *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack_50;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)uStack_50 / 2);
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      iVar10 = 0;
      psVar16 = *(short **)(DAT_1003a024 + 0x30);
      psVar15 = psVar16;
      if (0 < (int)uStack_50) {
        do {
          sVar5 = sVar6 + (short)iVar10;
          psVar16 = psVar15 + 2;
          *psVar15 = sVar5;
          iVar10 = iVar10 + 2;
          psVar15[1] = sVar5 + 1;
          psVar15 = psVar16;
        } while (iVar10 < (int)uStack_50);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar16;
    }
  }
  return 0;
}


