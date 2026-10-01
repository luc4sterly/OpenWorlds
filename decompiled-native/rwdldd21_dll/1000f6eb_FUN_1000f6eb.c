// 1000f6eb FUN_1000f6eb [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000f6eb(void)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  uint uVar9;
  short *psVar10;
  short *psVar11;
  uint uVar12;
  uint uVar13;
  short sVar14;
  int iVar15;
  undefined4 *puVar16;
  float *pfVar17;
  undefined4 *puVar18;
  float *pfVar19;
  undefined4 *puVar20;
  bool in_ZF;
  longlong lVar21;
  byte bVar22;
  uint uStack00000004;
  int *piStack00000010;
  uint uStack00000018;
  int iStack0000001c;
  int iStack00000020;
  int iStack00000024;
  uint uStack00000028;
  int *piStack0000002c;
  uint in_stack_00000030;
  undefined4 in_stack_00000034;
  int *in_stack_0000005c;
  int in_stack_00000060;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*in_stack_0000005c + 0x30) & 0x80) != 0) || (in_stack_00000060 == 0)) {
    iStack00000020 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    iStack00000024 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    bVar22 = *(byte *)((int)in_stack_0000005c + 0x3a);
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      iStack0000001c = 0;
      uStack00000004 = 0;
      if (bVar22 != 0) {
        piStack0000002c = in_stack_0000005c + 0xf;
        iVar15 = in_stack_0000005c[bVar22 + 0xe];
        bVar22 = *(byte *)(in_stack_0000005c[bVar22 + 0xe] + 0x48);
        do {
          uVar6 = uStack00000004;
          iVar5 = *piStack0000002c;
          bVar1 = *(byte *)(iVar5 + 0x48);
          if ((bVar1 & bVar22 & 0x3f) == 0) {
            fVar2 = (float)DAT_10042034;
            fVar3 = (float)DAT_10042038;
            (&DAT_10038b78)[uStack00000004 * 8] =
                 (float)*(int *)(iVar5 + 0x18) * _DAT_10034610 + fVar2;
            iVar4 = uStack00000004 * 8;
            *(float *)(&DAT_10038b7c + uStack00000004 * 0x20) =
                 (float)*(int *)(iVar5 + 0x1c) * _DAT_10034610 + fVar3;
            (&DAT_10038b80)[uStack00000004 * 8] =
                 (float)(ushort)~*(ushort *)(iVar5 + 0x22) * _DAT_10034614;
            (&DAT_10038b84)[uStack00000004 * 8] = 0x3f800000;
            uVar9 = *(uint *)(*in_stack_0000005c + 8);
            uStack00000028 =
                 (uint)*(byte *)(((*(uint *)(iVar5 + 0x58) & 0x1f0000) >> 0xb) +
                                 ((uVar9 & 0xf800) >> 0xb) + DAT_100362d0);
            (&DAT_10038b88)[uStack00000004 * 8] =
                 ((*(byte *)(((*(uint *)(iVar5 + 0x5c) & 0x1f0000) >> 0xb) + ((uVar9 & 0x7c0) >> 6)
                            + DAT_100362d0) | 0xffffe000) << 8 | uStack00000028 << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar5 + 0x60) & 0x1f0000) >> 0xb) + (uVar9 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar5 + 0x14)) {
              if (*(float *)(iVar5 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                (&DAT_10038b8c)[uVar6 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
              }
              else {
                (&DAT_10038b8c)[uStack00000004 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[uStack00000004 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[uVar6 * 8] = 0x3f800000;
            (&DAT_10038b94)[uVar6 * 8] = 0x3f800000;
            puVar16 = &DAT_10038b78 + iVar4;
            puVar18 = &DAT_10038bb8 + uVar6 * 8;
            for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar18 = *puVar16;
              puVar16 = puVar16 + 1;
              puVar18 = puVar18 + 1;
            }
            iVar4 = uStack00000004 + 1;
            (&DAT_10038b78)[iVar4 * 8] = (float)*(int *)(iVar15 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + iVar4 * 0x20) =
                 (float)*(int *)(iVar15 + 0x1c) * _DAT_10034610 + fVar3;
            (&DAT_10038b80)[iVar4 * 8] = (float)(ushort)~*(ushort *)(iVar15 + 0x22) * _DAT_10034614;
            (&DAT_10038b84)[iVar4 * 8] = 0x3f800000;
            uVar6 = *(uint *)(*in_stack_0000005c + 8);
            piStack00000010 =
                 (int *)(uint)*(byte *)(((*(uint *)(iVar15 + 0x58) & 0x1f0000) >> 0xb) +
                                        ((uVar6 & 0xf800) >> 0xb) + DAT_100362d0);
            (&DAT_10038b88)[iVar4 * 8] =
                 ((*(byte *)(((*(uint *)(iVar15 + 0x5c) & 0x1f0000) >> 0xb) + ((uVar6 & 0x7c0) >> 6)
                            + DAT_100362d0) | 0xffffe000) << 8 | (int)piStack00000010 << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar15 + 0x60) & 0x1f0000) >> 0xb) + (uVar6 & 0x1f) +
                                DAT_100362d0)) << 3;
            uStack00000004 = iVar4;
            if (_DAT_1003607c <= *(float *)(iVar15 + 0x14)) {
              if (*(float *)(iVar15 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                (&DAT_10038b8c)[iVar4 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar4 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar4 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar4 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar4 * 8] = 0x3f800000;
            pfVar17 = (float *)(&DAT_10038b78 + iVar4 * 8);
            pfVar19 = (float *)(&DAT_10038bb8 + iVar4 * 8);
            for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
              *pfVar19 = *pfVar17;
              pfVar17 = pfVar17 + 1;
              pfVar19 = pfVar19 + 1;
            }
            iVar4 = uStack00000004 + 1;
            uVar9 = *(int *)(iVar5 + 0x1c) - *(int *)(iVar15 + 0x1c);
            uVar12 = (int)uVar9 >> 0x1f;
            uVar6 = *(int *)(iVar5 + 0x18) - *(int *)(iVar15 + 0x18);
            uVar13 = (int)uVar6 >> 0x1f;
            if ((int)((uVar9 ^ uVar12) - uVar12) < (int)((uVar6 ^ uVar13) - uVar13)) {
              (&stack0x00000030)
              [(int)(uStack00000004 + -1 + ((int)(uStack00000004 + -1) >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar5 + 0x18) < *(int *)(iVar15 + 0x18));
              *(float *)(&DAT_10038b7c + iVar4 * 0x20) =
                   *(float *)(&DAT_10038b7c + iVar4 * 0x20) + _DAT_10034618;
              (&DAT_10038b9c)[iVar4 * 8] = (float)(&DAT_10038b9c)[iVar4 * 8] + _DAT_10034618;
            }
            else {
              (&stack0x00000030)
              [(int)(uStack00000004 + -1 + ((int)(uStack00000004 + -1) >> 0x1f & 3U)) >> 2] =
                   (uint)(*(int *)(iVar15 + 0x1c) < *(int *)(iVar5 + 0x1c));
              (&DAT_10038b78)[iVar4 * 8] = (float)(&DAT_10038b78)[iVar4 * 8] + _DAT_10034618;
              (&DAT_10038b98)[iVar4 * 8] = (float)(&DAT_10038b98)[iVar4 * 8] + _DAT_10034618;
            }
            uStack00000004 = uStack00000004 + 3;
          }
          piStack0000002c = piStack0000002c + 1;
          iStack0000001c = iStack0000001c + 1;
          iVar15 = iVar5;
          bVar22 = bVar1;
        } while (iStack0000001c < (int)(uint)*(byte *)((int)in_stack_0000005c + 0x3a));
      }
      uVar6 = uStack00000004;
      iVar5 = uStack00000004 * 0x20;
      iStack00000020 = iStack00000020 + uStack00000004 * -0x20;
      iVar15 = (int)uStack00000004 / 2;
      iStack00000024 = iStack00000024 - (iVar15 * 8 + 0x6c);
      if (((iStack00000020 < 1) || (iStack00000024 < 1)) &&
         (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < (int)uStack00000004) {
        puVar16 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar4 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar16 != &DAT_10038b78) {
          puVar18 = &DAT_10038b78;
          puVar20 = puVar16;
          for (iVar8 = (uVar6 & 0x7ffffff) << 3; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar20 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar20 = puVar20 + 1;
          }
          for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
            *(undefined1 *)puVar20 = *(undefined1 *)puVar18;
            puVar18 = (undefined4 *)((int)puVar18 + 1);
            puVar20 = (undefined4 *)((int)puVar20 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + iVar5;
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
        sVar14 = (short)((uint)((int)puVar16 - iVar4) >> 5);
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 10;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar14;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar14;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack00000004;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)iVar15;
        iVar15 = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar11 = *(short **)(DAT_1003a024 + 0x30);
        if (0 < (int)uStack00000004) {
          do {
            iVar5 = (&stack0x00000030)[(int)(iVar15 + (iVar15 >> 0x1f & 3U)) >> 2];
            sVar7 = sVar14 + (short)iVar15;
            *psVar11 = sVar7;
            if (iVar5 == 0) {
              psVar11[1] = sVar7 + 2;
              psVar11[2] = sVar7 + 1;
              psVar11[3] = 0x700;
              psVar11[4] = sVar7 + 1;
              psVar11[5] = sVar7 + 2;
              psVar11[6] = sVar7 + 3;
            }
            else {
              psVar11[1] = sVar7 + 1;
              psVar11[2] = sVar7 + 2;
              psVar11[3] = 0x700;
              psVar11[4] = sVar7 + 1;
              psVar11[5] = sVar7 + 3;
              psVar11[6] = sVar7 + 2;
            }
            psVar11[7] = 0x700;
            psVar11 = psVar11 + 8;
            iVar15 = iVar15 + 4;
          } while (iVar15 < (int)uStack00000004);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar11;
      }
    }
    else {
      iStack0000001c = 0;
      uStack00000004 = 0;
      if (bVar22 != 0) {
        piStack00000010 = in_stack_0000005c + 0xf;
        iVar15 = in_stack_0000005c[bVar22 + 0xe];
        bVar22 = *(byte *)(in_stack_0000005c[bVar22 + 0xe] + 0x48);
        do {
          uVar6 = uStack00000004;
          iVar5 = *piStack00000010;
          bVar1 = *(byte *)(iVar5 + 0x48);
          if ((bVar1 & bVar22 & 0x3f) == 0) {
            fVar2 = (float)DAT_10042034;
            fVar3 = (float)DAT_10042038;
            (&DAT_10038b78)[uStack00000004 * 8] =
                 (float)*(int *)(iVar5 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + uStack00000004 * 0x20) =
                 (float)*(int *)(iVar5 + 0x1c) * _DAT_10034610 + fVar3;
            in_stack_00000030 = ~(int)*(short *)(iVar5 + 0x22) & 0xffff;
            in_stack_00000034 = 0;
            (&DAT_10038b80)[uStack00000004 * 8] = (float)in_stack_00000030 * _DAT_10034614;
            (&DAT_10038b84)[uStack00000004 * 8] = 0x3f800000;
            uVar9 = *(uint *)(*in_stack_0000005c + 8);
            uStack00000018 =
                 (uint)*(byte *)(((*(uint *)(iVar5 + 0x58) & 0x1f0000) >> 0xb) +
                                 ((uVar9 & 0xf800) >> 0xb) + DAT_100362d0);
            (&DAT_10038b88)[uStack00000004 * 8] =
                 ((*(byte *)(((*(uint *)(iVar5 + 0x5c) & 0x1f0000) >> 0xb) + ((uVar9 & 0x7c0) >> 6)
                            + DAT_100362d0) | 0xffffe000) << 8 | uStack00000018 << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar5 + 0x60) & 0x1f0000) >> 0xb) + (uVar9 & 0x1f) +
                                DAT_100362d0)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar5 + 0x14)) {
              if (*(float *)(iVar5 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                (&DAT_10038b8c)[uVar6 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
              }
              else {
                (&DAT_10038b8c)[uStack00000004 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[uStack00000004 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[uVar6 * 8] = 0x3f800000;
            (&DAT_10038b94)[uVar6 * 8] = 0x3f800000;
            iVar4 = uStack00000004 + 1;
            (&DAT_10038b78)[iVar4 * 8] = (float)*(int *)(iVar15 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + iVar4 * 0x20) =
                 (float)*(int *)(iVar15 + 0x1c) * _DAT_10034610 + fVar3;
            in_stack_00000030 = ~(int)*(short *)(iVar15 + 0x22) & 0xffff;
            in_stack_00000034 = 0;
            (&DAT_10038b80)[iVar4 * 8] = (float)in_stack_00000030 * _DAT_10034614;
            (&DAT_10038b84)[iVar4 * 8] = 0x3f800000;
            uVar6 = *(uint *)(*in_stack_0000005c + 8);
            (&DAT_10038b88)[iVar4 * 8] =
                 ((*(byte *)(((*(uint *)(iVar15 + 0x5c) & 0x1f0000) >> 0xb) + ((uVar6 & 0x7c0) >> 6)
                            + DAT_100362d0) | 0xffffe000) << 8 |
                  (uint)*(byte *)(((*(uint *)(iVar15 + 0x58) & 0x1f0000) >> 0xb) +
                                  ((uVar6 & 0xf800) >> 0xb) + DAT_100362d0) << 0x10 |
                 (uint)*(byte *)(((*(uint *)(iVar15 + 0x60) & 0x1f0000) >> 0xb) + (uVar6 & 0x1f) +
                                DAT_100362d0)) << 3;
            uStack00000004 = iVar4;
            if (_DAT_1003607c <= *(float *)(iVar15 + 0x14)) {
              if (*(float *)(iVar15 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                (&DAT_10038b8c)[iVar4 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar4 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar4 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar4 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar4 * 8] = 0x3f800000;
            uStack00000004 = uStack00000004 + 1;
          }
          piStack00000010 = piStack00000010 + 1;
          iStack0000001c = iStack0000001c + 1;
          iVar15 = iVar5;
          bVar22 = bVar1;
        } while (iStack0000001c < (int)(uint)*(byte *)((int)in_stack_0000005c + 0x3a));
      }
      uVar6 = uStack00000004;
      iVar15 = uStack00000004 * 0x20;
      iStack00000020 = iStack00000020 + uStack00000004 * -0x20;
      iStack00000024 = iStack00000024 + (-0x1b - uStack00000004) * 4;
      if (((iStack00000020 < 1) || (iStack00000024 < 1)) &&
         (iVar5 = FUN_10001080(DAT_1003a024), iVar5 == 0)) {
        return 0;
      }
      if (0 < (int)uStack00000004) {
        puVar16 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar5 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar16 != &DAT_10038b78) {
          puVar18 = &DAT_10038b78;
          puVar20 = puVar16;
          for (iVar4 = (uVar6 & 0x7ffffff) << 3; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar20 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar20 = puVar20 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)puVar20 = *(undefined1 *)puVar18;
            puVar18 = (undefined4 *)((int)puVar18 + 1);
            puVar20 = (undefined4 *)((int)puVar20 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + iVar15;
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
        iVar15 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar15) {
          *(int *)(DAT_1003a024 + 0x98) = iVar15;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar15;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar15;
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
        sVar14 = (short)((uint)((int)puVar16 - iVar5) >> 5);
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar14;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar14;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack00000004;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)((int)uStack00000004 / 2);
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar11 = *(short **)(DAT_1003a024 + 0x30);
        iVar15 = 0;
        psVar10 = psVar11;
        if (0 < (int)uStack00000004) {
          do {
            sVar7 = sVar14 + (short)iVar15;
            psVar11 = psVar10 + 2;
            *psVar10 = sVar7;
            iVar15 = iVar15 + 2;
            psVar10[1] = sVar7 + 1;
            psVar10 = psVar11;
          } while (iVar15 < (int)uStack00000004);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar11;
      }
    }
  }
  return 0;
}


