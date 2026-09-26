// 1000d580 FUN_1000d580 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000d580(int *param_1,int param_2)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  short *psVar11;
  short *psVar12;
  uint uVar13;
  uint uVar14;
  short sVar15;
  int iVar16;
  int iVar17;
  undefined4 *puVar18;
  float *pfVar19;
  undefined4 *puVar20;
  int iVar21;
  float *pfVar22;
  undefined4 *puVar23;
  longlong lVar24;
  byte bStack_51;
  uint uStack_50;
  undefined2 uStack_4c;
  int iStack_44;
  int *piStack_40;
  int *piStack_2c;
  uint auStack_28 [10];
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    iVar4 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    uVar8 = *(uint *)(*param_1 + 8);
    iVar5 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    iVar7 = ((*(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + ((uVar8 & 0x7c0) >> 6) + DAT_100362d0) |
             0xffffe000) << 8 |
             (uint)*(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + ((uVar8 & 0xf800) >> 0xb) +
                            DAT_100362d0) << 0x10 |
            (uint)*(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + (uVar8 & 0x1f) + DAT_100362d0)) << 3
    ;
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      uStack_50 = 0;
      iStack_44 = 0;
      if (*(byte *)((int)param_1 + 0x3a) != 0) {
        piStack_2c = param_1 + 0xf;
        iVar16 = param_1[*(byte *)((int)param_1 + 0x3a) + 0xe];
        bStack_51 = *(byte *)(param_1[*(byte *)((int)param_1 + 0x3a) + 0xe] + 0x48);
        do {
          iVar21 = *piStack_2c;
          bVar1 = *(byte *)(iVar21 + 0x48);
          if ((bVar1 & bStack_51 & 0x3f) == 0) {
            fVar2 = (float)DAT_10042034;
            fVar3 = (float)DAT_10042038;
            (&DAT_10038b78)[uStack_50 * 8] = (float)*(int *)(iVar21 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + uStack_50 * 0x20) =
                 (float)*(int *)(iVar21 + 0x1c) * _DAT_10034610 + fVar3;
            (&DAT_10038b80)[uStack_50 * 8] =
                 (float)(ushort)~*(ushort *)(iVar21 + 0x22) * _DAT_10034614;
            (&DAT_10038b84)[uStack_50 * 8] = 0x3f800000;
            (&DAT_10038b88)[uStack_50 * 8] = iVar7;
            if (_DAT_1003607c <= *(float *)(iVar21 + 0x14)) {
              if (*(float *)(iVar21 + 0x14) <= _DAT_10036080) {
                lVar24 = __ftol();
                (&DAT_10038b8c)[uStack_50 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar24 * 4);
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
            puVar18 = &DAT_10038b78 + uStack_50 * 8;
            puVar20 = &DAT_10038bb8 + uStack_50 * 8;
            for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
              *puVar20 = *puVar18;
              puVar18 = puVar18 + 1;
              puVar20 = puVar20 + 1;
            }
            iVar9 = uStack_50 + 1;
            (&DAT_10038b78)[iVar9 * 8] = (float)*(int *)(iVar16 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
                 (float)*(int *)(iVar16 + 0x1c) * _DAT_10034610 + fVar3;
            (&DAT_10038b80)[iVar9 * 8] = (float)(ushort)~*(ushort *)(iVar16 + 0x22) * _DAT_10034614;
            (&DAT_10038b84)[iVar9 * 8] = 0x3f800000;
            (&DAT_10038b88)[iVar9 * 8] = iVar7;
            if (_DAT_1003607c <= *(float *)(iVar16 + 0x14)) {
              if (*(float *)(iVar16 + 0x14) <= _DAT_10036080) {
                lVar24 = __ftol();
                (&DAT_10038b8c)[iVar9 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar24 * 4);
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
            pfVar19 = (float *)(&DAT_10038b78 + iVar9 * 8);
            pfVar22 = (float *)(&DAT_10038bb8 + iVar9 * 8);
            for (iVar17 = 8; iVar17 != 0; iVar17 = iVar17 + -1) {
              *pfVar22 = *pfVar19;
              pfVar19 = pfVar19 + 1;
              pfVar22 = pfVar22 + 1;
            }
            iVar9 = uStack_50 + 2;
            uVar10 = *(int *)(iVar21 + 0x18) - *(int *)(iVar16 + 0x18);
            uVar13 = (int)uVar10 >> 0x1f;
            uVar8 = *(int *)(iVar21 + 0x1c) - *(int *)(iVar16 + 0x1c);
            uVar14 = (int)uVar8 >> 0x1f;
            if ((int)((uVar8 ^ uVar14) - uVar14) < (int)((uVar10 ^ uVar13) - uVar13)) {
              auStack_28[(int)(uStack_50 + ((int)uStack_50 >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar21 + 0x18) < *(int *)(iVar16 + 0x18));
              *(float *)(&DAT_10038b7c + iVar9 * 0x20) =
                   *(float *)(&DAT_10038b7c + iVar9 * 0x20) + _DAT_10034618;
              (&DAT_10038b9c)[iVar9 * 8] = (float)(&DAT_10038b9c)[iVar9 * 8] + _DAT_10034618;
            }
            else {
              auStack_28[(int)(uStack_50 + ((int)uStack_50 >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar16 + 0x1c) < *(int *)(iVar21 + 0x1c));
              (&DAT_10038b78)[iVar9 * 8] = (float)(&DAT_10038b78)[iVar9 * 8] + _DAT_10034618;
              (&DAT_10038b98)[iVar9 * 8] = (float)(&DAT_10038b98)[iVar9 * 8] + _DAT_10034618;
            }
            uStack_50 = uStack_50 + 4;
          }
          piStack_2c = piStack_2c + 1;
          iStack_44 = iStack_44 + 1;
          iVar16 = iVar21;
          bStack_51 = bVar1;
        } while (iStack_44 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
      }
      uStack_4c = (undefined2)((int)uStack_50 / 2);
      if ((((int)(iVar4 + uStack_50 * -0x20) < 1) || (iVar5 - (((int)uStack_50 / 2) * 8 + 0x6c) < 1)
          ) && (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < (int)uStack_50) {
        puVar18 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar4 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar18 != &DAT_10038b78) {
          puVar20 = &DAT_10038b78;
          puVar23 = puVar18;
          for (iVar5 = (uStack_50 & 0x7ffffff) << 3; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar23 = *puVar20;
            puVar20 = puVar20 + 1;
            puVar23 = puVar23 + 1;
          }
          for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined1 *)puVar23 = *(undefined1 *)puVar20;
            puVar20 = (undefined4 *)((int)puVar20 + 1);
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
        iVar5 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar5) {
          *(int *)(DAT_1003a024 + 0x98) = iVar5;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar5;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar5;
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
        sVar15 = (short)((uint)((int)puVar18 - iVar4) >> 5);
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar15;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar15;
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
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = uStack_4c;
        iVar4 = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar12 = *(short **)(DAT_1003a024 + 0x30);
        if (0 < (int)uStack_50) {
          do {
            uVar8 = auStack_28[(int)(iVar4 + (iVar4 >> 0x1f & 3U)) >> 2];
            sVar6 = sVar15 + (short)iVar4;
            *psVar12 = sVar6;
            if (uVar8 == 0) {
              psVar12[1] = sVar6 + 2;
              psVar12[2] = sVar6 + 1;
              psVar12[3] = 0x700;
              psVar12[4] = sVar6 + 1;
              psVar12[5] = sVar6 + 2;
              psVar12[6] = sVar6 + 3;
            }
            else {
              psVar12[1] = sVar6 + 1;
              psVar12[2] = sVar6 + 2;
              psVar12[3] = 0x700;
              psVar12[4] = sVar6 + 1;
              psVar12[5] = sVar6 + 3;
              psVar12[6] = sVar6 + 2;
            }
            psVar12[7] = 0x700;
            psVar12 = psVar12 + 8;
            iVar4 = iVar4 + 4;
          } while (iVar4 < (int)uStack_50);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar12;
      }
    }
    else {
      iVar16 = 0;
      iStack_44 = 0;
      if (*(byte *)((int)param_1 + 0x3a) != 0) {
        piStack_40 = param_1 + 0xf;
        iVar21 = param_1[*(byte *)((int)param_1 + 0x3a) + 0xe];
        bStack_51 = *(byte *)(param_1[*(byte *)((int)param_1 + 0x3a) + 0xe] + 0x48);
        do {
          iVar9 = *piStack_40;
          bVar1 = *(byte *)(iVar9 + 0x48);
          if ((bVar1 & bStack_51 & 0x3f) == 0) {
            fVar2 = (float)DAT_10042034;
            fVar3 = (float)DAT_10042038;
            (&DAT_10038b78)[iVar16 * 8] = (float)*(int *)(iVar9 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + iVar16 * 0x20) =
                 (float)*(int *)(iVar9 + 0x1c) * _DAT_10034610 + fVar3;
            auStack_28[0] = ~(int)*(short *)(iVar9 + 0x22) & 0xffff;
            auStack_28[1] = 0;
            (&DAT_10038b80)[iVar16 * 8] = (float)auStack_28[0] * _DAT_10034614;
            (&DAT_10038b84)[iVar16 * 8] = 0x3f800000;
            (&DAT_10038b88)[iVar16 * 8] = iVar7;
            if (_DAT_1003607c <= *(float *)(iVar9 + 0x14)) {
              if (*(float *)(iVar9 + 0x14) <= _DAT_10036080) {
                lVar24 = __ftol();
                (&DAT_10038b8c)[iVar16 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar24 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar16 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar16 * 8] = 0xff000000;
            }
            iVar17 = iVar16 + 1;
            (&DAT_10038b90)[iVar16 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar16 * 8] = 0x3f800000;
            (&DAT_10038b78)[iVar17 * 8] = (float)*(int *)(iVar21 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + iVar17 * 0x20) =
                 (float)*(int *)(iVar21 + 0x1c) * _DAT_10034610 + fVar3;
            auStack_28[0] = ~(int)*(short *)(iVar21 + 0x22) & 0xffff;
            auStack_28[1] = 0;
            (&DAT_10038b80)[iVar17 * 8] = (float)auStack_28[0] * _DAT_10034614;
            (&DAT_10038b84)[iVar17 * 8] = 0x3f800000;
            (&DAT_10038b88)[iVar17 * 8] = iVar7;
            if (_DAT_1003607c <= *(float *)(iVar21 + 0x14)) {
              if (*(float *)(iVar21 + 0x14) <= _DAT_10036080) {
                lVar24 = __ftol();
                (&DAT_10038b8c)[iVar17 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar24 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar17 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar17 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar17 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar17 * 8] = 0x3f800000;
            iVar16 = iVar16 + 2;
          }
          piStack_40 = piStack_40 + 1;
          iStack_44 = iStack_44 + 1;
          iVar21 = iVar9;
          bStack_51 = bVar1;
        } while (iStack_44 < (int)(uint)*(byte *)((int)param_1 + 0x3a));
      }
      auStack_28[0] = iVar16 * 0x20;
      if (((iVar4 + iVar16 * -0x20 < 1) || (iVar5 + (-0x1b - iVar16) * 4 < 1)) &&
         (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < iVar16) {
        puVar18 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar4 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar18 != &DAT_10038b78) {
          puVar20 = &DAT_10038b78;
          puVar23 = puVar18;
          for (uVar8 = auStack_28[0] >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar23 = *puVar20;
            puVar20 = puVar20 + 1;
            puVar23 = puVar23 + 1;
          }
          for (uVar8 = auStack_28[0] & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
            *(undefined1 *)puVar23 = *(undefined1 *)puVar20;
            puVar20 = (undefined4 *)((int)puVar20 + 1);
            puVar23 = (undefined4 *)((int)puVar23 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + auStack_28[0];
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
        iVar5 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar5) {
          *(int *)(DAT_1003a024 + 0x98) = iVar5;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar5;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar5;
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
        sVar15 = (short)((uint)((int)puVar18 - iVar4) >> 5);
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar15;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar15;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 8) = iVar16;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)(iVar16 / 2);
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar12 = *(short **)(DAT_1003a024 + 0x30);
        iVar4 = 0;
        psVar11 = psVar12;
        if (0 < iVar16) {
          do {
            sVar6 = sVar15 + (short)iVar4;
            psVar12 = psVar11 + 2;
            *psVar11 = sVar6;
            iVar4 = iVar4 + 2;
            psVar11[1] = sVar6 + 1;
            psVar11 = psVar12;
          } while (iVar4 < iVar16);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar12;
      }
    }
  }
  return 0;
}


