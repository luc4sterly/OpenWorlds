// 1000f6e0 FUN_1000f6e0 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000f6e0(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  short *psVar12;
  short *psVar13;
  uint uVar14;
  uint uVar15;
  short sVar16;
  int iVar17;
  undefined4 *puVar18;
  float *pfVar19;
  undefined4 *puVar20;
  float *pfVar21;
  undefined4 *puVar22;
  longlong lVar23;
  byte bStack_55;
  uint uStack_54;
  int *piStack_48;
  uint uStack_40;
  int iStack_3c;
  uint uStack_30;
  int *piStack_2c;
  uint auStack_28 [10];
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    iVar5 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    iVar6 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    bVar1 = *(byte *)((int)param_1 + 0x3a);
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      iStack_3c = 0;
      uStack_54 = 0;
      if (bVar1 != 0) {
        piStack_2c = param_1 + 0xf;
        iVar17 = param_1[bVar1 + 0xe];
        bStack_55 = *(byte *)(param_1[bVar1 + 0xe] + 0x48);
        do {
          iVar2 = *piStack_2c;
          bVar1 = *(byte *)(iVar2 + 0x48);
          if ((bVar1 & bStack_55 & 0x3f) == 0) {
            fVar3 = (float)DAT_10042034;
            fVar4 = (float)DAT_10042038;
            (&DAT_10038b78)[uStack_54 * 8] = (float)*(int *)(iVar2 + 0x18) * _DAT_10034610 + fVar3;
            *(float *)(&DAT_10038b7c + uStack_54 * 0x20) =
                 (float)*(int *)(iVar2 + 0x1c) * _DAT_10034610 + fVar4;
            (&DAT_10038b80)[uStack_54 * 8] =
                 (float)(ushort)~*(ushort *)(iVar2 + 0x22) * _DAT_10034614;
            (&DAT_10038b84)[uStack_54 * 8] = 0x3f800000;
            uVar8 = *(uint *)(*param_1 + 8);
            uStack_30 = (uint)*(byte *)(((*(uint *)(iVar2 + 0x58) & 0x1f0000) >> 0xb) +
                                        ((uVar8 & 0xf800) >> 0xb) + DAT_100362d0);
            (&DAT_10038b88)[uStack_54 * 8] =
                 ((*(byte *)(((*(uint *)(iVar2 + 0x5c) & 0x1f0000) >> 0xb) + ((uVar8 & 0x7c0) >> 6)
                            + DAT_100362d0) | 0xffffe000) << 8 | uStack_30 << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar2 + 0x60) & 0x1f0000) >> 0xb) + (uVar8 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar2 + 0x14)) {
              if (*(float *)(iVar2 + 0x14) <= _DAT_10036080) {
                lVar23 = __ftol();
                (&DAT_10038b8c)[uStack_54 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar23 * 4);
              }
              else {
                (&DAT_10038b8c)[uStack_54 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[uStack_54 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[uStack_54 * 8] = 0x3f800000;
            (&DAT_10038b94)[uStack_54 * 8] = 0x3f800000;
            puVar18 = &DAT_10038b78 + uStack_54 * 8;
            puVar20 = &DAT_10038bb8 + uStack_54 * 8;
            for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
              *puVar20 = *puVar18;
              puVar18 = puVar18 + 1;
              puVar20 = puVar20 + 1;
            }
            iVar7 = uStack_54 + 1;
            (&DAT_10038b78)[iVar7 * 8] = (float)*(int *)(iVar17 + 0x18) * _DAT_10034610 + fVar3;
            *(float *)(&DAT_10038b7c + iVar7 * 0x20) =
                 (float)*(int *)(iVar17 + 0x1c) * _DAT_10034610 + fVar4;
            (&DAT_10038b80)[iVar7 * 8] = (float)(ushort)~*(ushort *)(iVar17 + 0x22) * _DAT_10034614;
            (&DAT_10038b84)[iVar7 * 8] = 0x3f800000;
            uVar8 = *(uint *)(*param_1 + 8);
            piStack_48 = (int *)(uint)*(byte *)(((*(uint *)(iVar17 + 0x58) & 0x1f0000) >> 0xb) +
                                                ((uVar8 & 0xf800) >> 0xb) + DAT_100362d0);
            (&DAT_10038b88)[iVar7 * 8] =
                 ((*(byte *)(((*(uint *)(iVar17 + 0x5c) & 0x1f0000) >> 0xb) + ((uVar8 & 0x7c0) >> 6)
                            + DAT_100362d0) | 0xffffe000) << 8 | (int)piStack_48 << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar17 + 0x60) & 0x1f0000) >> 0xb) + (uVar8 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar17 + 0x14)) {
              if (*(float *)(iVar17 + 0x14) <= _DAT_10036080) {
                lVar23 = __ftol();
                (&DAT_10038b8c)[iVar7 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar23 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar7 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar7 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar7 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar7 * 8] = 0x3f800000;
            pfVar19 = (float *)(&DAT_10038b78 + iVar7 * 8);
            pfVar21 = (float *)(&DAT_10038bb8 + iVar7 * 8);
            for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
              *pfVar21 = *pfVar19;
              pfVar19 = pfVar19 + 1;
              pfVar21 = pfVar21 + 1;
            }
            iVar7 = uStack_54 + 2;
            uVar11 = *(int *)(iVar2 + 0x1c) - *(int *)(iVar17 + 0x1c);
            uVar14 = (int)uVar11 >> 0x1f;
            uVar8 = *(int *)(iVar2 + 0x18) - *(int *)(iVar17 + 0x18);
            uVar15 = (int)uVar8 >> 0x1f;
            if ((int)((uVar11 ^ uVar14) - uVar14) < (int)((uVar8 ^ uVar15) - uVar15)) {
              auStack_28[(int)(uStack_54 + ((int)uStack_54 >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar2 + 0x18) < *(int *)(iVar17 + 0x18));
              *(float *)(&DAT_10038b7c + iVar7 * 0x20) =
                   *(float *)(&DAT_10038b7c + iVar7 * 0x20) + _DAT_10034618;
              (&DAT_10038b9c)[iVar7 * 8] = (float)(&DAT_10038b9c)[iVar7 * 8] + _DAT_10034618;
            }
            else {
              auStack_28[(int)(uStack_54 + ((int)uStack_54 >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar17 + 0x1c) < *(int *)(iVar2 + 0x1c));
              (&DAT_10038b78)[iVar7 * 8] = (float)(&DAT_10038b78)[iVar7 * 8] + _DAT_10034618;
              (&DAT_10038b98)[iVar7 * 8] = (float)(&DAT_10038b98)[iVar7 * 8] + _DAT_10034618;
            }
            uStack_54 = uStack_54 + 4;
          }
          piStack_2c = piStack_2c + 1;
          iStack_3c = iStack_3c + 1;
          iVar17 = iVar2;
          bStack_55 = bVar1;
        } while (iStack_3c < (int)(uint)*(byte *)((int)param_1 + 0x3a));
      }
      if ((((int)(iVar5 + uStack_54 * -0x20) < 1) || (iVar6 - (((int)uStack_54 / 2) * 8 + 0x6c) < 1)
          ) && (iVar5 = FUN_10001080(DAT_1003a024), iVar5 == 0)) {
        return 0;
      }
      if (0 < (int)uStack_54) {
        puVar18 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar5 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar18 != &DAT_10038b78) {
          puVar20 = &DAT_10038b78;
          puVar22 = puVar18;
          for (iVar6 = (uStack_54 & 0x7ffffff) << 3; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar22 = *puVar20;
            puVar20 = puVar20 + 1;
            puVar22 = puVar22 + 1;
          }
          for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined1 *)puVar22 = *(undefined1 *)puVar20;
            puVar20 = (undefined4 *)((int)puVar20 + 1);
            puVar22 = (undefined4 *)((int)puVar22 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack_54 * 0x20;
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
        iVar6 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar6) {
          *(int *)(DAT_1003a024 + 0x98) = iVar6;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar6;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar6;
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
        sVar16 = (short)((uint)((int)puVar18 - iVar5) >> 5);
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 10;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar16;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar16;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack_54;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)uStack_54 / 2);
        iVar5 = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar13 = *(short **)(DAT_1003a024 + 0x30);
        if (0 < (int)uStack_54) {
          do {
            uVar8 = auStack_28[(int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2];
            sVar9 = sVar16 + (short)iVar5;
            *psVar13 = sVar9;
            if (uVar8 == 0) {
              psVar13[1] = sVar9 + 2;
              psVar13[2] = sVar9 + 1;
              psVar13[3] = 0x700;
              psVar13[4] = sVar9 + 1;
              psVar13[5] = sVar9 + 2;
              psVar13[6] = sVar9 + 3;
            }
            else {
              psVar13[1] = sVar9 + 1;
              psVar13[2] = sVar9 + 2;
              psVar13[3] = 0x700;
              psVar13[4] = sVar9 + 1;
              psVar13[5] = sVar9 + 3;
              psVar13[6] = sVar9 + 2;
            }
            psVar13[7] = 0x700;
            psVar13 = psVar13 + 8;
            iVar5 = iVar5 + 4;
          } while (iVar5 < (int)uStack_54);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar13;
      }
    }
    else {
      iStack_3c = 0;
      uStack_54 = 0;
      if (bVar1 != 0) {
        piStack_48 = param_1 + 0xf;
        iVar17 = param_1[bVar1 + 0xe];
        bStack_55 = *(byte *)(param_1[bVar1 + 0xe] + 0x48);
        do {
          iVar2 = *piStack_48;
          bVar1 = *(byte *)(iVar2 + 0x48);
          if ((bVar1 & bStack_55 & 0x3f) == 0) {
            fVar3 = (float)DAT_10042034;
            fVar4 = (float)DAT_10042038;
            (&DAT_10038b78)[uStack_54 * 8] = (float)*(int *)(iVar2 + 0x18) * _DAT_10034610 + fVar3;
            *(float *)(&DAT_10038b7c + uStack_54 * 0x20) =
                 (float)*(int *)(iVar2 + 0x1c) * _DAT_10034610 + fVar4;
            auStack_28[0] = ~(int)*(short *)(iVar2 + 0x22) & 0xffff;
            auStack_28[1] = 0;
            (&DAT_10038b80)[uStack_54 * 8] = (float)auStack_28[0] * _DAT_10034614;
            (&DAT_10038b84)[uStack_54 * 8] = 0x3f800000;
            uVar8 = *(uint *)(*param_1 + 8);
            uStack_40 = (uint)*(byte *)(((*(uint *)(iVar2 + 0x58) & 0x1f0000) >> 0xb) +
                                        ((uVar8 & 0xf800) >> 0xb) + DAT_100362d0);
            (&DAT_10038b88)[uStack_54 * 8] =
                 ((*(byte *)(((*(uint *)(iVar2 + 0x5c) & 0x1f0000) >> 0xb) + ((uVar8 & 0x7c0) >> 6)
                            + DAT_100362d0) | 0xffffe000) << 8 | uStack_40 << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar2 + 0x60) & 0x1f0000) >> 0xb) + (uVar8 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar2 + 0x14)) {
              if (*(float *)(iVar2 + 0x14) <= _DAT_10036080) {
                lVar23 = __ftol();
                (&DAT_10038b8c)[uStack_54 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar23 * 4);
              }
              else {
                (&DAT_10038b8c)[uStack_54 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[uStack_54 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[uStack_54 * 8] = 0x3f800000;
            (&DAT_10038b94)[uStack_54 * 8] = 0x3f800000;
            iVar7 = uStack_54 + 1;
            (&DAT_10038b78)[iVar7 * 8] = (float)*(int *)(iVar17 + 0x18) * _DAT_10034610 + fVar3;
            *(float *)(&DAT_10038b7c + iVar7 * 0x20) =
                 (float)*(int *)(iVar17 + 0x1c) * _DAT_10034610 + fVar4;
            auStack_28[0] = ~(int)*(short *)(iVar17 + 0x22) & 0xffff;
            auStack_28[1] = 0;
            (&DAT_10038b80)[iVar7 * 8] = (float)auStack_28[0] * _DAT_10034614;
            (&DAT_10038b84)[iVar7 * 8] = 0x3f800000;
            uVar8 = *(uint *)(*param_1 + 8);
            (&DAT_10038b88)[iVar7 * 8] =
                 ((*(byte *)(((*(uint *)(iVar17 + 0x5c) & 0x1f0000) >> 0xb) + ((uVar8 & 0x7c0) >> 6)
                            + DAT_100362d0) | 0xffffe000) << 8 |
                  (uint)*(byte *)(((*(uint *)(iVar17 + 0x58) & 0x1f0000) >> 0xb) +
                                  ((uVar8 & 0xf800) >> 0xb) + DAT_100362d0) << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar17 + 0x60) & 0x1f0000) >> 0xb) + (uVar8 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar17 + 0x14)) {
              if (*(float *)(iVar17 + 0x14) <= _DAT_10036080) {
                lVar23 = __ftol();
                (&DAT_10038b8c)[iVar7 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar23 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar7 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar7 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar7 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar7 * 8] = 0x3f800000;
            uStack_54 = uStack_54 + 2;
          }
          piStack_48 = piStack_48 + 1;
          iStack_3c = iStack_3c + 1;
          iVar17 = iVar2;
          bStack_55 = bVar1;
        } while (iStack_3c < (int)(uint)*(byte *)((int)param_1 + 0x3a));
      }
      if ((((int)(iVar5 + uStack_54 * -0x20) < 1) || ((int)(iVar6 + (-0x1b - uStack_54) * 4) < 1))
         && (iVar5 = FUN_10001080(DAT_1003a024), iVar5 == 0)) {
        return 0;
      }
      if (0 < (int)uStack_54) {
        puVar18 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar5 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar18 != &DAT_10038b78) {
          puVar20 = &DAT_10038b78;
          puVar22 = puVar18;
          for (iVar6 = (uStack_54 & 0x7ffffff) << 3; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar22 = *puVar20;
            puVar20 = puVar20 + 1;
            puVar22 = puVar22 + 1;
          }
          for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined1 *)puVar22 = *(undefined1 *)puVar20;
            puVar20 = (undefined4 *)((int)puVar20 + 1);
            puVar22 = (undefined4 *)((int)puVar22 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack_54 * 0x20;
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
        iVar6 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar6) {
          *(int *)(DAT_1003a024 + 0x98) = iVar6;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar6;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar6;
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
        sVar16 = (short)((uint)((int)puVar18 - iVar5) >> 5);
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar16;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar16;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack_54;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)uStack_54 / 2);
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar13 = *(short **)(DAT_1003a024 + 0x30);
        iVar5 = 0;
        psVar12 = psVar13;
        if (0 < (int)uStack_54) {
          do {
            sVar9 = sVar16 + (short)iVar5;
            psVar13 = psVar12 + 2;
            *psVar12 = sVar9;
            iVar5 = iVar5 + 2;
            psVar12[1] = sVar9 + 1;
            psVar12 = psVar13;
          } while (iVar5 < (int)uStack_54);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar13;
      }
    }
  }
  return 0;
}


