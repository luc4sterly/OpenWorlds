// 1000a00b FUN_1000a00b [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000a00b(void)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  short sVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  undefined4 *puVar12;
  float *pfVar13;
  undefined4 *puVar14;
  short *psVar15;
  short *psVar16;
  undefined4 *puVar17;
  float *pfVar18;
  bool in_ZF;
  longlong lVar19;
  int iStack00000008;
  uint uStack0000000c;
  int iStack00000010;
  int iStack00000014;
  float fStack00000018;
  int *in_stack_00000020;
  int in_stack_00000024;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*in_stack_00000020 + 0x30) & 0x80) != 0) || (in_stack_00000024 == 0)) {
    uVar7 = *(uint *)(*in_stack_00000020 + 8);
    fStack00000018 =
         (float)(((*(byte *)(((in_stack_00000020[2] & 0x1f0000U) >> 0xb) + ((uVar7 & 0x7c0) >> 6) +
                            DAT_100362d0) | 0xffffe000) << 8 |
                  (uint)*(byte *)(((in_stack_00000020[1] & 0x1f0000U) >> 0xb) +
                                  ((uVar7 & 0xf800) >> 0xb) + DAT_100362d0) << 0x10 |
                 (uint)*(byte *)(((in_stack_00000020[3] & 0x1f0000U) >> 0xb) + (uVar7 & 0x1f) +
                                DAT_100362d0)) << 3);
    iStack00000010 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    iStack00000014 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    uVar7 = 0;
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      piVar8 = in_stack_00000020 + 0xf;
      uStack0000000c = 0;
      iStack00000008 = *(byte *)((int)in_stack_00000020 + 0x3a) - 1;
      if (0 < iStack00000008) {
        pfVar10 = (float *)&DAT_10038b78;
        do {
          iVar3 = *piVar8;
          piVar8 = piVar8 + 1;
          pfVar11 = pfVar10;
          if ((*(byte *)(iVar3 + 0x48) & 0x3f) == 0) {
            fVar2 = (float)DAT_10042038;
            *pfVar10 = (float)*(int *)(iVar3 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            pfVar10[1] = (float)*(int *)(iVar3 + 0x1c) * _DAT_10034610 + fVar2;
            pfVar10[2] = (float)(ushort)~*(ushort *)(iVar3 + 0x22) * _DAT_10034614;
            pfVar10[3] = 1.0;
            pfVar10[4] = fStack00000018;
            if (_DAT_1003607c <= *(float *)(iVar3 + 0x14)) {
              if (*(float *)(iVar3 + 0x14) <= _DAT_10036080) {
                lVar19 = __ftol();
                pfVar10[5] = *(float *)(DAT_1003a020 + (int)lVar19 * 4);
              }
              else {
                pfVar10[5] = 0.0;
              }
            }
            else {
              pfVar10[5] = -1.7014118e+38;
            }
            pfVar1 = pfVar10 + 8;
            pfVar10[6] = 0.0;
            pfVar10[7] = 0.0;
            pfVar13 = pfVar1;
            for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
              *pfVar13 = *pfVar11;
              pfVar11 = pfVar11 + 1;
              pfVar13 = pfVar13 + 1;
            }
            pfVar11 = pfVar10 + 0x18;
            pfVar13 = pfVar10;
            pfVar18 = pfVar10 + 0x10;
            for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
              *pfVar18 = *pfVar13;
              pfVar13 = pfVar13 + 1;
              pfVar18 = pfVar18 + 1;
            }
            uStack0000000c = uStack0000000c + 3;
            *pfVar1 = *pfVar1 + _DAT_10034618;
            pfVar10[0x11] = pfVar10[0x11] + _DAT_10034618;
          }
          iStack00000008 = iStack00000008 + -1;
          pfVar10 = pfVar11;
        } while (iStack00000008 != 0);
      }
      uVar7 = uStack0000000c;
      iVar3 = uStack0000000c * 0x20;
      iStack00000010 = iStack00000010 + uStack0000000c * -0x20;
      iStack00000014 = iStack00000014 + ((int)uStack0000000c / -3) * 8 + -0x6c;
      if (((iStack00000010 < 1) || (iStack00000014 < 1)) &&
         (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < (int)uStack0000000c) {
        puVar12 = *(undefined4 **)(DAT_1003a024 + 0x28);
        uVar9 = (uint)((int)puVar12 - *(int *)(DAT_1003a024 + 0x24)) >> 5;
        if (puVar12 != &DAT_10038b78) {
          puVar14 = &DAT_10038b78;
          for (iVar4 = (uVar7 & 0x7ffffff) << 3; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar12 = *puVar14;
            puVar14 = puVar14 + 1;
            puVar12 = puVar12 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar14;
            puVar14 = (undefined4 *)((int)puVar14 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + iVar3;
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
        iVar3 = *(int *)(DAT_1003a024 + 100);
        if (*(int *)(DAT_1003a024 + 0x98) != iVar3) {
          *(int *)(DAT_1003a024 + 0x98) = iVar3;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar3;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
          *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar3;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = (short)uVar9;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = (short)uVar9;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack0000000c;
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
        iVar3 = (int)uStack0000000c / 3;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)iVar3;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar16 = *(short **)(DAT_1003a024 + 0x30);
        psVar15 = psVar16;
        if (0 < iVar3) {
          do {
            sVar6 = (short)uVar9;
            *psVar15 = sVar6;
            psVar15[1] = sVar6 + 1;
            psVar15[2] = sVar6 + 2;
            psVar16 = psVar15 + 4;
            uVar9 = (uint)(ushort)(sVar6 + 3);
            iVar3 = iVar3 + -1;
            psVar15[3] = 0x700;
            psVar15 = psVar16;
          } while (iVar3 != 0);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar16;
      }
    }
    else {
      piVar8 = in_stack_00000020 + 0xf;
      iStack00000008 = *(byte *)((int)in_stack_00000020 + 0x3a) - 1;
      if (0 < iStack00000008) {
        puVar12 = &DAT_10038b8c;
        do {
          iVar3 = *piVar8;
          piVar8 = piVar8 + 1;
          puVar14 = puVar12;
          if ((*(byte *)(iVar3 + 0x48) & 0x3f) == 0) {
            fVar2 = (float)DAT_10042038;
            puVar12[-5] = (float)*(int *)(iVar3 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            puVar12[-4] = (float)*(int *)(iVar3 + 0x1c) * _DAT_10034610 + fVar2;
            puVar12[-3] = (float)(ushort)~*(ushort *)(iVar3 + 0x22) * _DAT_10034614;
            puVar12[-2] = 0x3f800000;
            puVar12[-1] = fStack00000018;
            if (_DAT_1003607c <= *(float *)(iVar3 + 0x14)) {
              if (*(float *)(iVar3 + 0x14) <= _DAT_10036080) {
                lVar19 = __ftol();
                *puVar12 = *(undefined4 *)(DAT_1003a020 + (int)lVar19 * 4);
              }
              else {
                *puVar12 = 0;
              }
            }
            else {
              *puVar12 = 0xff000000;
            }
            puVar12[1] = 0;
            puVar14 = puVar12 + 8;
            uVar7 = uVar7 + 1;
            puVar12[2] = 0;
          }
          iStack00000008 = iStack00000008 + -1;
          puVar12 = puVar14;
        } while (iStack00000008 != 0);
      }
      iStack00000010 = iStack00000010 + uVar7 * -0x20;
      iStack00000014 = iStack00000014 + -0x70;
      if (((iStack00000010 < 1) || (iStack00000014 < 1)) &&
         (iVar3 = FUN_10001080(DAT_1003a024), iVar3 == 0)) {
        return 0;
      }
      if (0 < (int)uVar7) {
        puVar12 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar3 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar12 != &DAT_10038b78) {
          puVar14 = &DAT_10038b78;
          puVar17 = puVar12;
          for (iVar4 = (uVar7 & 0x7ffffff) << 3; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar17 = *puVar14;
            puVar14 = puVar14 + 1;
            puVar17 = puVar17 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)puVar17 = *(undefined1 *)puVar14;
            puVar14 = (undefined4 *)((int)puVar14 + 1);
            puVar17 = (undefined4 *)((int)puVar17 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar7 * 0x20;
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
        uVar5 = (undefined2)((uint)((int)puVar12 - iVar3) >> 5);
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar5;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 6) = uVar5;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar7;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 0xc) = 0;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 0x10;
        if (((uint)*(undefined1 **)(DAT_1003a024 + 0x30) & 7) == 0) {
          **(undefined1 **)(DAT_1003a024 + 0x30) = 3;
          *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
          *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 0;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        }
        **(undefined1 **)(DAT_1003a024 + 0x30) = 1;
        *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 4;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        **(undefined2 **)(DAT_1003a024 + 0x30) = (short)uVar7;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = uVar5;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      }
    }
  }
  return 0;
}


