// 1000d58b FUN_1000d58b [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000d58b(void)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  uint uVar7;
  uint uVar8;
  short *psVar9;
  short *psVar10;
  uint uVar11;
  uint uVar12;
  short sVar13;
  int iVar14;
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
  undefined2 uStack00000008;
  int iStack00000010;
  int *piStack00000014;
  int iStack00000018;
  int iStack0000001c;
  int iStack00000024;
  int *piStack00000028;
  uint uStack0000002c;
  undefined4 in_stack_00000030;
  int *in_stack_00000058;
  int in_stack_0000005c;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*in_stack_00000058 + 0x30) & 0x80) != 0) || (in_stack_0000005c == 0)) {
    iStack00000018 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    uVar7 = *(uint *)(*in_stack_00000058 + 8);
    iStack0000001c = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    iStack00000024 =
         ((*(byte *)(((in_stack_00000058[2] & 0x1f0000U) >> 0xb) + ((uVar7 & 0x7c0) >> 6) +
                    DAT_100362d0) | 0xffffe000) << 8 |
          (uint)*(byte *)(((in_stack_00000058[1] & 0x1f0000U) >> 0xb) + ((uVar7 & 0xf800) >> 0xb) +
                         DAT_100362d0) << 0x10 |
         (uint)*(byte *)(((in_stack_00000058[3] & 0x1f0000U) >> 0xb) + (uVar7 & 0x1f) + DAT_100362d0
                        )) << 3;
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      uStack00000004 = 0;
      iStack00000010 = 0;
      if (*(byte *)((int)in_stack_00000058 + 0x3a) != 0) {
        piStack00000028 = in_stack_00000058 + 0xf;
        iVar14 = in_stack_00000058[*(byte *)((int)in_stack_00000058 + 0x3a) + 0xe];
        bVar22 = *(byte *)(in_stack_00000058[*(byte *)((int)in_stack_00000058 + 0x3a) + 0xe] + 0x48)
        ;
        do {
          uVar7 = uStack00000004;
          iVar4 = *piStack00000028;
          bVar1 = *(byte *)(iVar4 + 0x48);
          if ((bVar1 & bVar22 & 0x3f) == 0) {
            fVar2 = (float)DAT_10042034;
            fVar3 = (float)DAT_10042038;
            (&DAT_10038b78)[uStack00000004 * 8] =
                 (float)*(int *)(iVar4 + 0x18) * _DAT_10034610 + fVar2;
            iVar5 = uStack00000004 * 8;
            *(float *)(&DAT_10038b7c + uStack00000004 * 0x20) =
                 (float)*(int *)(iVar4 + 0x1c) * _DAT_10034610 + fVar3;
            (&DAT_10038b80)[uStack00000004 * 8] =
                 (float)(ushort)~*(ushort *)(iVar4 + 0x22) * _DAT_10034614;
            (&DAT_10038b84)[uStack00000004 * 8] = 0x3f800000;
            (&DAT_10038b88)[uStack00000004 * 8] = iStack00000024;
            if (_DAT_1003607c <= *(float *)(iVar4 + 0x14)) {
              if (*(float *)(iVar4 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                (&DAT_10038b8c)[uVar7 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
              }
              else {
                (&DAT_10038b8c)[uStack00000004 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[uStack00000004 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[uVar7 * 8] = 0x3f800000;
            (&DAT_10038b94)[uVar7 * 8] = 0x3f800000;
            puVar16 = &DAT_10038b78 + iVar5;
            puVar18 = &DAT_10038bb8 + uVar7 * 8;
            for (iVar15 = 8; iVar15 != 0; iVar15 = iVar15 + -1) {
              *puVar18 = *puVar16;
              puVar16 = puVar16 + 1;
              puVar18 = puVar18 + 1;
            }
            iVar5 = uStack00000004 + 1;
            (&DAT_10038b78)[iVar5 * 8] = (float)*(int *)(iVar14 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + iVar5 * 0x20) =
                 (float)*(int *)(iVar14 + 0x1c) * _DAT_10034610 + fVar3;
            (&DAT_10038b80)[iVar5 * 8] = (float)(ushort)~*(ushort *)(iVar14 + 0x22) * _DAT_10034614;
            (&DAT_10038b84)[iVar5 * 8] = 0x3f800000;
            (&DAT_10038b88)[iVar5 * 8] = iStack00000024;
            uStack00000004 = iVar5;
            if (_DAT_1003607c <= *(float *)(iVar14 + 0x14)) {
              if (*(float *)(iVar14 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                (&DAT_10038b8c)[iVar5 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar5 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar5 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar5 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar5 * 8] = 0x3f800000;
            pfVar17 = (float *)(&DAT_10038b78 + iVar5 * 8);
            pfVar19 = (float *)(&DAT_10038bb8 + iVar5 * 8);
            for (iVar15 = 8; iVar15 != 0; iVar15 = iVar15 + -1) {
              *pfVar19 = *pfVar17;
              pfVar17 = pfVar17 + 1;
              pfVar19 = pfVar19 + 1;
            }
            iVar5 = uStack00000004 + 1;
            uVar8 = *(int *)(iVar4 + 0x18) - *(int *)(iVar14 + 0x18);
            uVar11 = (int)uVar8 >> 0x1f;
            uVar7 = *(int *)(iVar4 + 0x1c) - *(int *)(iVar14 + 0x1c);
            uVar12 = (int)uVar7 >> 0x1f;
            if ((int)((uVar7 ^ uVar12) - uVar12) < (int)((uVar8 ^ uVar11) - uVar11)) {
              *(uint *)((int)&stack0x0000002c +
                       ((int)(uStack00000004 + -1 + ((int)(uStack00000004 + -1) >> 0x1f & 3U)) >> 2)
                       * 4) = (uint)(*(int *)(iVar4 + 0x18) < *(int *)(iVar14 + 0x18));
              *(float *)(&DAT_10038b7c + iVar5 * 0x20) =
                   *(float *)(&DAT_10038b7c + iVar5 * 0x20) + _DAT_10034618;
              (&DAT_10038b9c)[iVar5 * 8] = (float)(&DAT_10038b9c)[iVar5 * 8] + _DAT_10034618;
            }
            else {
              *(uint *)((int)&stack0x0000002c +
                       ((int)(uStack00000004 + -1 + ((int)(uStack00000004 + -1) >> 0x1f & 3U)) >> 2)
                       * 4) = (uint)(*(int *)(iVar14 + 0x1c) < *(int *)(iVar4 + 0x1c));
              (&DAT_10038b78)[iVar5 * 8] = (float)(&DAT_10038b78)[iVar5 * 8] + _DAT_10034618;
              (&DAT_10038b98)[iVar5 * 8] = (float)(&DAT_10038b98)[iVar5 * 8] + _DAT_10034618;
            }
            uStack00000004 = uStack00000004 + 3;
          }
          piStack00000028 = piStack00000028 + 1;
          iStack00000010 = iStack00000010 + 1;
          iVar14 = iVar4;
          bVar22 = bVar1;
        } while (iStack00000010 < (int)(uint)*(byte *)((int)in_stack_00000058 + 0x3a));
      }
      uVar7 = uStack00000004;
      iVar14 = uStack00000004 * 0x20;
      iStack00000018 = iStack00000018 + uStack00000004 * -0x20;
      uStack00000008 = (undefined2)((int)uStack00000004 / 2);
      iStack0000001c = iStack0000001c - (((int)uStack00000004 / 2) * 8 + 0x6c);
      if (((iStack00000018 < 1) || (iStack0000001c < 1)) &&
         (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < (int)uStack00000004) {
        puVar16 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar4 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar16 != &DAT_10038b78) {
          puVar18 = &DAT_10038b78;
          puVar20 = puVar16;
          for (iVar5 = (uVar7 & 0x7ffffff) << 3; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar20 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar20 = puVar20 + 1;
          }
          for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined1 *)puVar20 = *(undefined1 *)puVar18;
            puVar18 = (undefined4 *)((int)puVar18 + 1);
            puVar20 = (undefined4 *)((int)puVar20 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + iVar14;
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
        iVar14 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar14) {
          *(int *)(DAT_1003a024 + 0x98) = iVar14;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar14;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar14;
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
        sVar13 = (short)((uint)((int)puVar16 - iVar4) >> 5);
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar13;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar13;
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
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = uStack00000008;
        iVar14 = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar10 = *(short **)(DAT_1003a024 + 0x30);
        if (0 < (int)uStack00000004) {
          do {
            iVar4 = *(int *)((int)&stack0x0000002c +
                            ((int)(iVar14 + (iVar14 >> 0x1f & 3U)) >> 2) * 4);
            sVar6 = sVar13 + (short)iVar14;
            *psVar10 = sVar6;
            if (iVar4 == 0) {
              psVar10[1] = sVar6 + 2;
              psVar10[2] = sVar6 + 1;
              psVar10[3] = 0x700;
              psVar10[4] = sVar6 + 1;
              psVar10[5] = sVar6 + 2;
              psVar10[6] = sVar6 + 3;
            }
            else {
              psVar10[1] = sVar6 + 1;
              psVar10[2] = sVar6 + 2;
              psVar10[3] = 0x700;
              psVar10[4] = sVar6 + 1;
              psVar10[5] = sVar6 + 3;
              psVar10[6] = sVar6 + 2;
            }
            psVar10[7] = 0x700;
            psVar10 = psVar10 + 8;
            iVar14 = iVar14 + 4;
          } while (iVar14 < (int)uStack00000004);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar10;
      }
    }
    else {
      iVar14 = 0;
      iStack00000010 = 0;
      if (*(byte *)((int)in_stack_00000058 + 0x3a) != 0) {
        piStack00000014 = in_stack_00000058 + 0xf;
        iVar4 = in_stack_00000058[*(byte *)((int)in_stack_00000058 + 0x3a) + 0xe];
        bVar22 = *(byte *)(in_stack_00000058[*(byte *)((int)in_stack_00000058 + 0x3a) + 0xe] + 0x48)
        ;
        do {
          iVar5 = *piStack00000014;
          bVar1 = *(byte *)(iVar5 + 0x48);
          if ((bVar1 & bVar22 & 0x3f) == 0) {
            fVar2 = (float)DAT_10042034;
            fVar3 = (float)DAT_10042038;
            (&DAT_10038b78)[iVar14 * 8] = (float)*(int *)(iVar5 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + iVar14 * 0x20) =
                 (float)*(int *)(iVar5 + 0x1c) * _DAT_10034610 + fVar3;
            uStack0000002c = ~(int)*(short *)(iVar5 + 0x22) & 0xffff;
            in_stack_00000030 = 0;
            (&DAT_10038b80)[iVar14 * 8] = (float)uStack0000002c * _DAT_10034614;
            (&DAT_10038b84)[iVar14 * 8] = 0x3f800000;
            (&DAT_10038b88)[iVar14 * 8] = iStack00000024;
            if (_DAT_1003607c <= *(float *)(iVar5 + 0x14)) {
              if (*(float *)(iVar5 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                (&DAT_10038b8c)[iVar14 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar14 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar14 * 8] = 0xff000000;
            }
            iVar15 = iVar14 + 1;
            (&DAT_10038b90)[iVar14 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar14 * 8] = 0x3f800000;
            (&DAT_10038b78)[iVar15 * 8] = (float)*(int *)(iVar4 + 0x18) * _DAT_10034610 + fVar2;
            *(float *)(&DAT_10038b7c + iVar15 * 0x20) =
                 (float)*(int *)(iVar4 + 0x1c) * _DAT_10034610 + fVar3;
            uStack0000002c = ~(int)*(short *)(iVar4 + 0x22) & 0xffff;
            in_stack_00000030 = 0;
            (&DAT_10038b80)[iVar15 * 8] = (float)uStack0000002c * _DAT_10034614;
            (&DAT_10038b84)[iVar15 * 8] = 0x3f800000;
            (&DAT_10038b88)[iVar15 * 8] = iStack00000024;
            if (_DAT_1003607c <= *(float *)(iVar4 + 0x14)) {
              if (*(float *)(iVar4 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                (&DAT_10038b8c)[iVar15 * 8] = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
              }
              else {
                (&DAT_10038b8c)[iVar15 * 8] = 0;
              }
            }
            else {
              (&DAT_10038b8c)[iVar15 * 8] = 0xff000000;
            }
            (&DAT_10038b90)[iVar15 * 8] = 0x3f800000;
            (&DAT_10038b94)[iVar15 * 8] = 0x3f800000;
            iVar14 = iVar14 + 2;
          }
          piStack00000014 = piStack00000014 + 1;
          iStack00000010 = iStack00000010 + 1;
          iVar4 = iVar5;
          bVar22 = bVar1;
        } while (iStack00000010 < (int)(uint)*(byte *)((int)in_stack_00000058 + 0x3a));
      }
      uStack0000002c = iVar14 * 0x20;
      iStack00000018 = iStack00000018 + iVar14 * -0x20;
      iStack0000001c = iStack0000001c + (-0x1b - iVar14) * 4;
      if (((iStack00000018 < 1) || (iStack0000001c < 1)) &&
         (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < iVar14) {
        puVar16 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar4 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar16 != &DAT_10038b78) {
          puVar18 = &DAT_10038b78;
          puVar20 = puVar16;
          for (uVar7 = uStack0000002c >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar20 = *puVar18;
            puVar18 = puVar18 + 1;
            puVar20 = puVar20 + 1;
          }
          for (uVar7 = uStack0000002c & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined1 *)puVar20 = *(undefined1 *)puVar18;
            puVar18 = (undefined4 *)((int)puVar18 + 1);
            puVar20 = (undefined4 *)((int)puVar20 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack0000002c;
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
        sVar13 = (short)((uint)((int)puVar16 - iVar4) >> 5);
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar13;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar13;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 8) = iVar14;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)(iVar14 / 2);
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar10 = *(short **)(DAT_1003a024 + 0x30);
        iVar4 = 0;
        psVar9 = psVar10;
        if (0 < iVar14) {
          do {
            sVar6 = sVar13 + (short)iVar4;
            psVar10 = psVar9 + 2;
            *psVar9 = sVar6;
            iVar4 = iVar4 + 2;
            psVar9[1] = sVar6 + 1;
            psVar9 = psVar10;
          } while (iVar4 < iVar14);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar10;
      }
    }
  }
  return 0;
}


