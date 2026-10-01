// 10013ddb FUN_10013ddb [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10013ddb(void)

{
  float fVar1;
  float fVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte bVar8;
  short *psVar9;
  short *psVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  short sVar14;
  int iVar15;
  undefined4 *puVar16;
  float *pfVar17;
  undefined4 *puVar18;
  int *piVar19;
  float *pfVar20;
  undefined4 *puVar21;
  bool in_ZF;
  longlong lVar22;
  byte bVar23;
  byte bVar24;
  uint uStack00000004;
  uint uStack00000010;
  int *piStack00000018;
  int *piStack0000001c;
  int iStack00000020;
  int iStack00000024;
  uint uStack00000028;
  uint in_stack_00000030;
  undefined4 in_stack_00000034;
  int *in_stack_0000005c;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  iStack00000020 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  iStack00000024 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
  iVar15 = 1;
  uStack00000010 = (uint)*(byte *)((int)in_stack_0000005c + 0x3a);
  uStack00000004 = 0;
  iVar13 = in_stack_0000005c[0xf];
  bVar24 = *(byte *)(iVar13 + 0x48);
  if (1 < *(byte *)((int)in_stack_0000005c + 0x3a)) {
    piVar19 = in_stack_0000005c + 0x10;
    bVar8 = *(byte *)(in_stack_0000005c[uStack00000010 + 0xe] + 0x48);
    bVar23 = *(byte *)(iVar13 + 0x48);
    do {
      bVar24 = bVar23;
      if ((bVar23 & bVar8 & 0x3f) == 0) break;
      iVar13 = *piVar19;
      piVar19 = piVar19 + 1;
      iVar15 = iVar15 + 1;
      bVar24 = *(byte *)(iVar13 + 0x48);
      bVar8 = bVar23;
      bVar23 = bVar24;
    } while (iVar15 < (int)uStack00000010);
  }
  if (*(int *)(DAT_1003a024 + 0x74) == 0) {
    if (iVar15 < (int)uStack00000010) {
      piStack0000001c = (int *)(uStack00000010 - iVar15);
      piStack00000018 = in_stack_0000005c + iVar15 + 0xf;
      do {
        uVar5 = uStack00000004;
        iVar15 = *piStack00000018;
        bVar8 = *(byte *)(iVar15 + 0x48);
        if ((bVar8 & bVar24 & 0x3f) == 0) {
          fVar1 = (float)DAT_10042034;
          fVar2 = (float)DAT_10042038;
          (&DAT_10038b78)[uStack00000004 * 8] =
               (float)*(int *)(iVar15 + 0x18) * _DAT_10034610 + fVar1;
          iVar4 = uStack00000004 * 8;
          *(float *)(&DAT_10038b7c + uStack00000004 * 0x20) =
               (float)*(int *)(iVar15 + 0x1c) * _DAT_10034610 + fVar2;
          (&DAT_10038b80)[uStack00000004 * 8] =
               (float)(ushort)~*(ushort *)(iVar15 + 0x22) * _DAT_10034614;
          (&DAT_10038b84)[uStack00000004 * 8] = 0x3f800000;
          uVar7 = *(uint *)(*in_stack_0000005c + 8);
          uStack00000028 =
               (uint)*(byte *)(((*(uint *)(iVar15 + 0x5c) & 0x1f0000) >> 0xb) +
                               ((uVar7 & 0x7c0) >> 6) + DAT_100362d0);
          (&DAT_10038b88)[uStack00000004 * 8] =
               ((*(byte *)(((*(uint *)(iVar15 + 0x58) & 0x1f0000) >> 0xb) +
                           ((uVar7 & 0xf800) >> 0xb) + DAT_100362d0) | 0xffffffe0) << 0x10 |
                uStack00000028 << 8 |
               (uint)*(byte *)(((*(uint *)(iVar15 + 0x60) & 0x1f0000) >> 0xb) + (uVar7 & 0x1f) +
                              DAT_100362d0)) << 3;
          if (_DAT_1003607c <= *(float *)(iVar15 + 0x14)) {
            if (*(float *)(iVar15 + 0x14) <= _DAT_10036080) {
              lVar22 = __ftol();
              (&DAT_10038b8c)[uVar5 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar22 * 4);
            }
            else {
              (&DAT_10038b8c)[uStack00000004 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[uStack00000004 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[uVar5 * 8] = 0;
          (&DAT_10038b94)[uVar5 * 8] = 0;
          puVar16 = &DAT_10038b78 + iVar4;
          puVar18 = &DAT_10038bb8 + uVar5 * 8;
          for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar18 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar18 = puVar18 + 1;
          }
          iVar4 = uStack00000004 + 1;
          (&DAT_10038b78)[iVar4 * 8] = (float)*(int *)(iVar13 + 0x18) * _DAT_10034610 + fVar1;
          *(float *)(&DAT_10038b7c + iVar4 * 0x20) =
               (float)*(int *)(iVar13 + 0x1c) * _DAT_10034610 + fVar2;
          (&DAT_10038b80)[iVar4 * 8] = (float)(ushort)~*(ushort *)(iVar13 + 0x22) * _DAT_10034614;
          (&DAT_10038b84)[iVar4 * 8] = 0x3f800000;
          uVar5 = *(uint *)(*in_stack_0000005c + 8);
          uStack00000010 =
               (uint)*(byte *)(((*(uint *)(iVar13 + 0x5c) & 0x1f0000) >> 0xb) +
                               ((uVar5 & 0x7c0) >> 6) + DAT_100362d0);
          (&DAT_10038b88)[iVar4 * 8] =
               ((*(byte *)(((*(uint *)(iVar13 + 0x58) & 0x1f0000) >> 0xb) +
                           ((uVar5 & 0xf800) >> 0xb) + DAT_100362d0) | 0xffffffe0) << 0x10 |
                uStack00000010 << 8 |
               (uint)*(byte *)(((*(uint *)(iVar13 + 0x60) & 0x1f0000) >> 0xb) + (uVar5 & 0x1f) +
                              DAT_100362d0)) << 3;
          uStack00000004 = iVar4;
          if (_DAT_1003607c <= *(float *)(iVar13 + 0x14)) {
            if (*(float *)(iVar13 + 0x14) <= _DAT_10036080) {
              lVar22 = __ftol();
              (&DAT_10038b8c)[iVar4 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar22 * 4);
            }
            else {
              (&DAT_10038b8c)[iVar4 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[iVar4 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[iVar4 * 8] = 0;
          (&DAT_10038b94)[iVar4 * 8] = 0;
          pfVar17 = (float *)(&DAT_10038b78 + iVar4 * 8);
          pfVar20 = (float *)(&DAT_10038bb8 + iVar4 * 8);
          for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
            *pfVar20 = *pfVar17;
            pfVar17 = pfVar17 + 1;
            pfVar20 = pfVar20 + 1;
          }
          iVar4 = uStack00000004 + 1;
          uVar7 = *(int *)(iVar15 + 0x18) - *(int *)(iVar13 + 0x18);
          uVar11 = (int)uVar7 >> 0x1f;
          uVar5 = *(int *)(iVar15 + 0x1c) - *(int *)(iVar13 + 0x1c);
          uVar12 = (int)uVar5 >> 0x1f;
          if ((int)((uVar5 ^ uVar12) - uVar12) < (int)((uVar7 ^ uVar11) - uVar11)) {
            (&stack0x00000030)
            [(int)(uStack00000004 + -1 + ((int)(uStack00000004 + -1) >> 0x1f & 3U)) >> 2] =
                 (uint)(*(int *)(iVar15 + 0x18) < *(int *)(iVar13 + 0x18));
            *(float *)(&DAT_10038b7c + iVar4 * 0x20) =
                 *(float *)(&DAT_10038b7c + iVar4 * 0x20) + _DAT_10034618;
            (&DAT_10038b9c)[iVar4 * 8] = (float)(&DAT_10038b9c)[iVar4 * 8] + _DAT_10034618;
          }
          else {
            (&stack0x00000030)
            [(int)(uStack00000004 + -1 + ((int)(uStack00000004 + -1) >> 0x1f & 3U)) >> 2] =
                 (uint)(*(int *)(iVar13 + 0x1c) < *(int *)(iVar15 + 0x1c));
            (&DAT_10038b78)[iVar4 * 8] = (float)(&DAT_10038b78)[iVar4 * 8] + _DAT_10034618;
            (&DAT_10038b98)[iVar4 * 8] = (float)(&DAT_10038b98)[iVar4 * 8] + _DAT_10034618;
          }
          uStack00000004 = uStack00000004 + 3;
        }
        piStack0000001c = (int *)((int)piStack0000001c + -1);
        iVar13 = iVar15;
        bVar24 = bVar8;
        piStack00000018 = piStack00000018 + 1;
      } while (piStack0000001c != (int *)0x0);
    }
    uVar5 = uStack00000004;
    iVar15 = uStack00000004 * 0x20;
    iStack00000020 = iStack00000020 + uStack00000004 * -0x20;
    iVar13 = (int)uStack00000004 / 2;
    iStack00000024 = iStack00000024 - (iVar13 * 8 + 0x6c);
    if (((iStack00000020 < 1) || (iStack00000024 < 1)) &&
       (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
      return 0;
    }
    if (0 < (int)uStack00000004) {
      puVar16 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar4 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar16 != &DAT_10038b78) {
        puVar18 = &DAT_10038b78;
        puVar21 = puVar16;
        for (iVar6 = (uVar5 & 0x7ffffff) << 3; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar21 = *puVar18;
          puVar18 = puVar18 + 1;
          puVar21 = puVar21 + 1;
        }
        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
          *(undefined1 *)puVar21 = *(undefined1 *)puVar18;
          puVar18 = (undefined4 *)((int)puVar18 + 1);
          puVar21 = (undefined4 *)((int)puVar21 + 1);
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)iVar13;
      iVar13 = 0;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar10 = *(short **)(DAT_1003a024 + 0x30);
      if (0 < (int)uStack00000004) {
        do {
          sVar3 = sVar14 + (short)iVar13;
          *psVar10 = sVar3;
          if ((&stack0x00000030)[(int)(iVar13 + (iVar13 >> 0x1f & 3U)) >> 2] == 0) {
            psVar10[1] = sVar3 + 2;
            psVar10[2] = sVar3 + 1;
            psVar10[3] = 0x700;
            psVar10[4] = sVar3 + 1;
            psVar10[5] = sVar3 + 2;
            psVar10[6] = sVar3 + 3;
          }
          else {
            psVar10[1] = sVar3 + 1;
            psVar10[2] = sVar3 + 2;
            psVar10[3] = 0x700;
            psVar10[4] = sVar3 + 1;
            psVar10[5] = sVar3 + 3;
            psVar10[6] = sVar3 + 2;
          }
          psVar10[7] = 0x700;
          psVar10 = psVar10 + 8;
          iVar13 = iVar13 + 4;
        } while (iVar13 < (int)uStack00000004);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar10;
    }
  }
  else {
    if (iVar15 < (int)uStack00000010) {
      uStack00000010 = uStack00000010 - iVar15;
      piStack0000001c = in_stack_0000005c + iVar15 + 0xf;
      do {
        uVar5 = uStack00000004;
        iVar15 = *piStack0000001c;
        bVar8 = *(byte *)(iVar15 + 0x48);
        if ((bVar8 & bVar24 & 0x3f) == 0) {
          fVar1 = (float)DAT_10042034;
          fVar2 = (float)DAT_10042038;
          (&DAT_10038b78)[uStack00000004 * 8] =
               (float)*(int *)(iVar15 + 0x18) * _DAT_10034610 + fVar1;
          *(float *)(&DAT_10038b7c + uStack00000004 * 0x20) =
               (float)*(int *)(iVar15 + 0x1c) * _DAT_10034610 + fVar2;
          in_stack_00000030 = ~(int)*(short *)(iVar15 + 0x22) & 0xffff;
          in_stack_00000034 = 0;
          (&DAT_10038b80)[uStack00000004 * 8] = (float)in_stack_00000030 * _DAT_10034614;
          (&DAT_10038b84)[uStack00000004 * 8] = 0x3f800000;
          uVar7 = *(uint *)(*in_stack_0000005c + 8);
          piStack00000018 =
               (int *)(uint)*(byte *)(((*(uint *)(iVar15 + 0x5c) & 0x1f0000) >> 0xb) +
                                      ((uVar7 & 0x7c0) >> 6) + DAT_100362d0);
          (&DAT_10038b88)[uStack00000004 * 8] =
               ((*(byte *)(((*(uint *)(iVar15 + 0x58) & 0x1f0000) >> 0xb) +
                           ((uVar7 & 0xf800) >> 0xb) + DAT_100362d0) | 0xffffffe0) << 0x10 |
                (int)piStack00000018 << 8 |
               (uint)*(byte *)(((*(uint *)(iVar15 + 0x60) & 0x1f0000) >> 0xb) + (uVar7 & 0x1f) +
                              DAT_100362d0)) << 3;
          if (_DAT_1003607c <= *(float *)(iVar15 + 0x14)) {
            if (*(float *)(iVar15 + 0x14) <= _DAT_10036080) {
              lVar22 = __ftol();
              (&DAT_10038b8c)[uVar5 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar22 * 4);
            }
            else {
              (&DAT_10038b8c)[uStack00000004 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[uStack00000004 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[uVar5 * 8] = 0;
          (&DAT_10038b94)[uVar5 * 8] = 0;
          iVar4 = uStack00000004 + 1;
          (&DAT_10038b78)[iVar4 * 8] = (float)*(int *)(iVar13 + 0x18) * _DAT_10034610 + fVar1;
          *(float *)(&DAT_10038b7c + iVar4 * 0x20) =
               (float)*(int *)(iVar13 + 0x1c) * _DAT_10034610 + fVar2;
          in_stack_00000030 = ~(int)*(short *)(iVar13 + 0x22) & 0xffff;
          in_stack_00000034 = 0;
          (&DAT_10038b80)[iVar4 * 8] = (float)in_stack_00000030 * _DAT_10034614;
          (&DAT_10038b84)[iVar4 * 8] = 0x3f800000;
          uVar5 = *(uint *)(*in_stack_0000005c + 8);
          (&DAT_10038b88)[iVar4 * 8] =
               ((*(byte *)(((*(uint *)(iVar13 + 0x58) & 0x1f0000) >> 0xb) +
                           ((uVar5 & 0xf800) >> 0xb) + DAT_100362d0) | 0xffffffe0) << 0x10 |
                (uint)*(byte *)(((*(uint *)(iVar13 + 0x5c) & 0x1f0000) >> 0xb) +
                                ((uVar5 & 0x7c0) >> 6) + DAT_100362d0) << 8 |
               (uint)*(byte *)(((*(uint *)(iVar13 + 0x60) & 0x1f0000) >> 0xb) + (uVar5 & 0x1f) +
                              DAT_100362d0)) << 3;
          uStack00000004 = iVar4;
          if (_DAT_1003607c <= *(float *)(iVar13 + 0x14)) {
            if (*(float *)(iVar13 + 0x14) <= _DAT_10036080) {
              lVar22 = __ftol();
              (&DAT_10038b8c)[iVar4 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar22 * 4);
            }
            else {
              (&DAT_10038b8c)[iVar4 * 8] = 0;
            }
          }
          else {
            (&DAT_10038b8c)[iVar4 * 8] = 0xff000000;
          }
          (&DAT_10038b90)[iVar4 * 8] = 0;
          (&DAT_10038b94)[iVar4 * 8] = 0;
          uStack00000004 = uStack00000004 + 1;
        }
        uStack00000010 = uStack00000010 + -1;
        iVar13 = iVar15;
        bVar24 = bVar8;
        piStack0000001c = piStack0000001c + 1;
      } while (uStack00000010 != 0);
    }
    uVar5 = uStack00000004;
    iVar13 = uStack00000004 * 0x20;
    iStack00000020 = iStack00000020 + uStack00000004 * -0x20;
    iStack00000024 = iStack00000024 + (-0x1b - uStack00000004) * 4;
    if (((iStack00000020 < 1) || (iStack00000024 < 1)) &&
       (iVar15 = FUN_10001080(DAT_1003a024), iVar15 == 0)) {
      return 0;
    }
    if (0 < (int)uStack00000004) {
      puVar16 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar15 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar16 != &DAT_10038b78) {
        puVar18 = &DAT_10038b78;
        puVar21 = puVar16;
        for (iVar4 = (uVar5 & 0x7ffffff) << 3; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar21 = *puVar18;
          puVar18 = puVar18 + 1;
          puVar21 = puVar21 + 1;
        }
        for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
          *(undefined1 *)puVar21 = *(undefined1 *)puVar18;
          puVar18 = (undefined4 *)((int)puVar18 + 1);
          puVar21 = (undefined4 *)((int)puVar21 + 1);
        }
      }
      *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + iVar13;
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
      iVar13 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar13) {
        *(int *)(DAT_1003a024 + 0x98) = iVar13;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar13;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar13;
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
      sVar14 = (short)((uint)((int)puVar16 - iVar15) >> 5);
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
      iVar13 = 0;
      psVar10 = *(short **)(DAT_1003a024 + 0x30);
      psVar9 = psVar10;
      if (0 < (int)uStack00000004) {
        do {
          sVar3 = sVar14 + (short)iVar13;
          psVar10 = psVar9 + 2;
          *psVar9 = sVar3;
          iVar13 = iVar13 + 2;
          psVar9[1] = sVar3 + 1;
          psVar9 = psVar10;
        } while (iVar13 < (int)uStack00000004);
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar10;
    }
  }
  return 0;
}


