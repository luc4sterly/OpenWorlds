// 10013dd0 FUN_10013dd0 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10013dd0(int *param_1)

{
  float fVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  short *psVar12;
  short *psVar13;
  uint uVar14;
  uint uVar15;
  short sVar16;
  int iVar17;
  undefined4 *puVar18;
  float *pfVar19;
  undefined4 *puVar20;
  int *piVar21;
  float *pfVar22;
  undefined4 *puVar23;
  longlong lVar24;
  byte bStack_55;
  uint uStack_54;
  uint uStack_48;
  int *piStack_40;
  int *piStack_3c;
  uint uStack_30;
  uint auStack_28 [10];
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  iVar4 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  iVar5 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
  iVar17 = 1;
  uStack_48 = (uint)*(byte *)((int)param_1 + 0x3a);
  uStack_54 = 0;
  iVar7 = param_1[0xf];
  bStack_55 = *(byte *)(iVar7 + 0x48);
  if (1 < *(byte *)((int)param_1 + 0x3a)) {
    piVar21 = param_1 + 0x10;
    bVar11 = *(byte *)(param_1[uStack_48 + 0xe] + 0x48);
    do {
      if ((bStack_55 & bVar11 & 0x3f) == 0) break;
      iVar7 = *piVar21;
      piVar21 = piVar21 + 1;
      iVar17 = iVar17 + 1;
      bVar11 = bStack_55;
      bStack_55 = *(byte *)(iVar7 + 0x48);
    } while (iVar17 < (int)uStack_48);
  }
  if (*(int *)(DAT_1003a024 + 0x74) == 0) {
    if (iVar17 < (int)uStack_48) {
      piStack_3c = (int *)(uStack_48 - iVar17);
      piStack_40 = param_1 + iVar17 + 0xf;
      do {
        iVar17 = *piStack_40;
        bVar11 = *(byte *)(iVar17 + 0x48);
        if ((bVar11 & bStack_55 & 0x3f) == 0) {
          fVar1 = (float)DAT_10042034;
          fVar2 = (float)DAT_10042038;
          (&DAT_10038b78)[uStack_54 * 8] = (float)*(int *)(iVar17 + 0x18) * _DAT_10034610 + fVar1;
          *(float *)(&DAT_10038b7c + uStack_54 * 0x20) =
               (float)*(int *)(iVar17 + 0x1c) * _DAT_10034610 + fVar2;
          (&DAT_10038b80)[uStack_54 * 8] =
               (float)(ushort)~*(ushort *)(iVar17 + 0x22) * _DAT_10034614;
          (&DAT_10038b84)[uStack_54 * 8] = 0x3f800000;
          uVar8 = *(uint *)(*param_1 + 8);
          uStack_30 = (uint)*(byte *)(((*(uint *)(iVar17 + 0x5c) & 0x1f0000) >> 0xb) +
                                      ((uVar8 & 0x7c0) >> 6) + DAT_100362d0);
          (&DAT_10038b88)[uStack_54 * 8] =
               ((*(byte *)(((*(uint *)(iVar17 + 0x58) & 0x1f0000) >> 0xb) +
                           ((uVar8 & 0xf800) >> 0xb) + DAT_100362d0) | 0xffffffe0) << 0x10 |
                uStack_30 << 8 |
               (uint)*(byte *)(((*(uint *)(iVar17 + 0x60) & 0x1f0000) >> 0xb) + (uVar8 & 0x1f) +
                              DAT_100362d0)) << 3;
          if (_DAT_1003607c <= *(float *)(iVar17 + 0x14)) {
            if (*(float *)(iVar17 + 0x14) <= _DAT_10036080) {
              lVar24 = __ftol();
              (&DAT_10038b8c)[uStack_54 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar24 * 4);
            }
            else {
              (&DAT_10038b8c)[uStack_54 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[uStack_54 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[uStack_54 * 8] = 0;
          (&DAT_10038b94)[uStack_54 * 8] = 0;
          puVar18 = &DAT_10038b78 + uStack_54 * 8;
          puVar20 = &DAT_10038bb8 + uStack_54 * 8;
          for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar20 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar20 = puVar20 + 1;
          }
          iVar6 = uStack_54 + 1;
          (&DAT_10038b78)[iVar6 * 8] = (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar1;
          *(float *)(&DAT_10038b7c + iVar6 * 0x20) =
               (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar2;
          (&DAT_10038b80)[iVar6 * 8] = (float)(ushort)~*(ushort *)(iVar7 + 0x22) * _DAT_10034614;
          (&DAT_10038b84)[iVar6 * 8] = 0x3f800000;
          uVar8 = *(uint *)(*param_1 + 8);
          uStack_48 = (uint)*(byte *)(((*(uint *)(iVar7 + 0x5c) & 0x1f0000) >> 0xb) +
                                      ((uVar8 & 0x7c0) >> 6) + DAT_100362d0);
          (&DAT_10038b88)[iVar6 * 8] =
               ((*(byte *)(((*(uint *)(iVar7 + 0x58) & 0x1f0000) >> 0xb) + ((uVar8 & 0xf800) >> 0xb)
                          + DAT_100362d0) | 0xffffffe0) << 0x10 | uStack_48 << 8 |
               (uint)*(byte *)(((*(uint *)(iVar7 + 0x60) & 0x1f0000) >> 0xb) + (uVar8 & 0x1f) +
                              DAT_100362d0)) << 3;
          if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
            if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
              lVar24 = __ftol();
              (&DAT_10038b8c)[iVar6 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar24 * 4);
            }
            else {
              (&DAT_10038b8c)[iVar6 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[iVar6 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[iVar6 * 8] = 0;
          (&DAT_10038b94)[iVar6 * 8] = 0;
          pfVar19 = (float *)(&DAT_10038b78 + iVar6 * 8);
          pfVar22 = (float *)(&DAT_10038bb8 + iVar6 * 8);
          for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
            *pfVar22 = *pfVar19;
            pfVar19 = pfVar19 + 1;
            pfVar22 = pfVar22 + 1;
          }
          iVar6 = uStack_54 + 2;
          uVar10 = *(int *)(iVar17 + 0x18) - *(int *)(iVar7 + 0x18);
          uVar14 = (int)uVar10 >> 0x1f;
          uVar8 = *(int *)(iVar17 + 0x1c) - *(int *)(iVar7 + 0x1c);
          uVar15 = (int)uVar8 >> 0x1f;
          if ((int)((uVar8 ^ uVar15) - uVar15) < (int)((uVar10 ^ uVar14) - uVar14)) {
            auStack_28[(int)(uStack_54 + ((int)uStack_54 >> 0x1f & 3U)) >> 2] =
                 (uint)(*(int *)(iVar17 + 0x18) < *(int *)(iVar7 + 0x18));
            *(float *)(&DAT_10038b7c + iVar6 * 0x20) =
                 *(float *)(&DAT_10038b7c + iVar6 * 0x20) + _DAT_10034618;
            (&DAT_10038b9c)[iVar6 * 8] = (float)(&DAT_10038b9c)[iVar6 * 8] + _DAT_10034618;
          }
          else {
            auStack_28[(int)(uStack_54 + ((int)uStack_54 >> 0x1f & 3U)) >> 2] =
                 (uint)(*(int *)(iVar7 + 0x1c) < *(int *)(iVar17 + 0x1c));
            (&DAT_10038b78)[iVar6 * 8] = (float)(&DAT_10038b78)[iVar6 * 8] + _DAT_10034618;
            (&DAT_10038b98)[iVar6 * 8] = (float)(&DAT_10038b98)[iVar6 * 8] + _DAT_10034618;
          }
          uStack_54 = uStack_54 + 4;
        }
        piStack_3c = (int *)((int)piStack_3c + -1);
        iVar7 = iVar17;
        bStack_55 = bVar11;
        piStack_40 = piStack_40 + 1;
      } while (piStack_3c != (int *)0x0);
    }
    if ((((int)(iVar4 + uStack_54 * -0x20) < 1) || (iVar5 - (((int)uStack_54 / 2) * 8 + 0x6c) < 1))
       && (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
      return 0;
    }
    if (0 < (int)uStack_54) {
      puVar18 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar7 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar18 != &DAT_10038b78) {
        puVar20 = &DAT_10038b78;
        puVar23 = puVar18;
        for (iVar4 = (uStack_54 & 0x7ffffff) << 3; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar23 = *puVar20;
          puVar20 = puVar20 + 1;
          puVar23 = puVar23 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar23 = *(undefined1 *)puVar20;
          puVar20 = (undefined4 *)((int)puVar20 + 1);
          puVar23 = (undefined4 *)((int)puVar23 + 1);
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
      iVar4 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar4) {
        *(int *)(DAT_1003a024 + 0x98) = iVar4;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar4;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar4;
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
      sVar16 = (short)((uint)((int)puVar18 - iVar7) >> 5);
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
      iVar7 = 0;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar13 = *(short **)(DAT_1003a024 + 0x30);
      if (0 < (int)uStack_54) {
        do {
          sVar3 = sVar16 + (short)iVar7;
          *psVar13 = sVar3;
          if (auStack_28[(int)(iVar7 + (iVar7 >> 0x1f & 3U)) >> 2] == 0) {
            psVar13[1] = sVar3 + 2;
            psVar13[2] = sVar3 + 1;
            psVar13[3] = 0x700;
            psVar13[4] = sVar3 + 1;
            psVar13[5] = sVar3 + 2;
            psVar13[6] = sVar3 + 3;
          }
          else {
            psVar13[1] = sVar3 + 1;
            psVar13[2] = sVar3 + 2;
            psVar13[3] = 0x700;
            psVar13[4] = sVar3 + 1;
            psVar13[5] = sVar3 + 3;
            psVar13[6] = sVar3 + 2;
          }
          psVar13[7] = 0x700;
          psVar13 = psVar13 + 8;
          iVar7 = iVar7 + 4;
        } while (iVar7 < (int)uStack_54);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar13;
    }
  }
  else {
    if (iVar17 < (int)uStack_48) {
      uStack_48 = uStack_48 - iVar17;
      piStack_3c = param_1 + iVar17 + 0xf;
      do {
        iVar17 = *piStack_3c;
        bVar11 = *(byte *)(iVar17 + 0x48);
        if ((bVar11 & bStack_55 & 0x3f) == 0) {
          fVar1 = (float)DAT_10042034;
          fVar2 = (float)DAT_10042038;
          (&DAT_10038b78)[uStack_54 * 8] = (float)*(int *)(iVar17 + 0x18) * _DAT_10034610 + fVar1;
          *(float *)(&DAT_10038b7c + uStack_54 * 0x20) =
               (float)*(int *)(iVar17 + 0x1c) * _DAT_10034610 + fVar2;
          auStack_28[0] = ~(int)*(short *)(iVar17 + 0x22) & 0xffff;
          auStack_28[1] = 0;
          (&DAT_10038b80)[uStack_54 * 8] = (float)auStack_28[0] * _DAT_10034614;
          (&DAT_10038b84)[uStack_54 * 8] = 0x3f800000;
          uVar8 = *(uint *)(*param_1 + 8);
          piStack_40 = (int *)(uint)*(byte *)(((*(uint *)(iVar17 + 0x5c) & 0x1f0000) >> 0xb) +
                                              ((uVar8 & 0x7c0) >> 6) + DAT_100362d0);
          (&DAT_10038b88)[uStack_54 * 8] =
               ((*(byte *)(((*(uint *)(iVar17 + 0x58) & 0x1f0000) >> 0xb) +
                           ((uVar8 & 0xf800) >> 0xb) + DAT_100362d0) | 0xffffffe0) << 0x10 |
                (int)piStack_40 << 8 |
               (uint)*(byte *)(((*(uint *)(iVar17 + 0x60) & 0x1f0000) >> 0xb) + (uVar8 & 0x1f) +
                              DAT_100362d0)) << 3;
          if (_DAT_1003607c <= *(float *)(iVar17 + 0x14)) {
            if (*(float *)(iVar17 + 0x14) <= _DAT_10036080) {
              lVar24 = __ftol();
              (&DAT_10038b8c)[uStack_54 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar24 * 4);
            }
            else {
              (&DAT_10038b8c)[uStack_54 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[uStack_54 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[uStack_54 * 8] = 0;
          (&DAT_10038b94)[uStack_54 * 8] = 0;
          iVar6 = uStack_54 + 1;
          (&DAT_10038b78)[iVar6 * 8] = (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar1;
          *(float *)(&DAT_10038b7c + iVar6 * 0x20) =
               (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar2;
          auStack_28[0] = ~(int)*(short *)(iVar7 + 0x22) & 0xffff;
          auStack_28[1] = 0;
          (&DAT_10038b80)[iVar6 * 8] = (float)auStack_28[0] * _DAT_10034614;
          (&DAT_10038b84)[iVar6 * 8] = 0x3f800000;
          uVar8 = *(uint *)(*param_1 + 8);
          (&DAT_10038b88)[iVar6 * 8] =
               ((*(byte *)(((*(uint *)(iVar7 + 0x58) & 0x1f0000) >> 0xb) + ((uVar8 & 0xf800) >> 0xb)
                          + DAT_100362d0) | 0xffffffe0) << 0x10 |
                (uint)*(byte *)(((*(uint *)(iVar7 + 0x5c) & 0x1f0000) >> 0xb) +
                                ((uVar8 & 0x7c0) >> 6) + DAT_100362d0) << 8 |
               (uint)*(byte *)(((*(uint *)(iVar7 + 0x60) & 0x1f0000) >> 0xb) + (uVar8 & 0x1f) +
                              DAT_100362d0)) << 3;
          if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
            if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
              lVar24 = __ftol();
              (&DAT_10038b8c)[iVar6 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar24 * 4);
            }
            else {
              (&DAT_10038b8c)[iVar6 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[iVar6 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[iVar6 * 8] = 0;
          (&DAT_10038b94)[iVar6 * 8] = 0;
          uStack_54 = uStack_54 + 2;
        }
        uStack_48 = uStack_48 + -1;
        iVar7 = iVar17;
        bStack_55 = bVar11;
        piStack_3c = piStack_3c + 1;
      } while (uStack_48 != 0);
    }
    if ((((int)(iVar4 + uStack_54 * -0x20) < 1) || ((int)(iVar5 + (-0x1b - uStack_54) * 4) < 1)) &&
       (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
      return 0;
    }
    if (0 < (int)uStack_54) {
      puVar18 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar7 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar18 != &DAT_10038b78) {
        puVar20 = &DAT_10038b78;
        puVar23 = puVar18;
        for (iVar4 = (uStack_54 & 0x7ffffff) << 3; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar23 = *puVar20;
          puVar20 = puVar20 + 1;
          puVar23 = puVar23 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar23 = *(undefined1 *)puVar20;
          puVar20 = (undefined4 *)((int)puVar20 + 1);
          puVar23 = (undefined4 *)((int)puVar23 + 1);
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
      iVar4 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar4) {
        *(int *)(DAT_1003a024 + 0x98) = iVar4;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar4;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar4;
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
      sVar16 = (short)((uint)((int)puVar18 - iVar7) >> 5);
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
      iVar7 = 0;
      psVar13 = *(short **)(DAT_1003a024 + 0x30);
      psVar12 = psVar13;
      if (0 < (int)uStack_54) {
        do {
          sVar3 = sVar16 + (short)iVar7;
          psVar13 = psVar12 + 2;
          *psVar12 = sVar3;
          iVar7 = iVar7 + 2;
          psVar12[1] = sVar3 + 1;
          psVar12 = psVar13;
        } while (iVar7 < (int)uStack_54);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar13;
    }
  }
  return 0;
}


