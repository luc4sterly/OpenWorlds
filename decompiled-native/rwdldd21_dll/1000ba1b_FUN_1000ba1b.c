// 1000ba1b FUN_1000ba1b [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000ba1b(void)

{
  float *pfVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  short sVar7;
  float *pfVar8;
  float *pfVar9;
  uint uVar10;
  undefined4 *puVar11;
  float *pfVar12;
  undefined4 *puVar13;
  short *psVar14;
  short *psVar15;
  undefined4 *puVar16;
  float *pfVar17;
  bool in_ZF;
  longlong lVar18;
  uint uVar19;
  int *piStack0000000c;
  int iStack00000010;
  int iStack00000014;
  int iStack00000018;
  int *in_stack_00000020;
  int in_stack_00000024;
  
  if (!in_ZF) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*in_stack_00000020 + 0x30) & 0x80) != 0) || (in_stack_00000024 == 0)) {
    iStack00000014 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    iStack00000018 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      piStack0000000c = in_stack_00000020 + 0xf;
      uVar19 = 0;
      iStack00000010 = *(byte *)((int)in_stack_00000020 + 0x3a) - 1;
      if (0 < iStack00000010) {
        pfVar8 = (float *)&DAT_10038b78;
        do {
          piVar3 = piStack0000000c + 1;
          iVar4 = *piStack0000000c;
          pfVar9 = pfVar8;
          piStack0000000c = piVar3;
          if ((*(byte *)(iVar4 + 0x48) & 0x3f) == 0) {
            fVar2 = (float)DAT_10042038;
            *pfVar8 = (float)*(int *)(iVar4 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            pfVar8[1] = (float)*(int *)(iVar4 + 0x1c) * _DAT_10034610 + fVar2;
            pfVar8[2] = (float)(ushort)~*(ushort *)(iVar4 + 0x22) * _DAT_10034614;
            pfVar8[3] = 1.0;
            uVar10 = *(uint *)(*in_stack_00000020 + 8);
            pfVar8[4] = (float)(((*(byte *)(((*(uint *)(iVar4 + 0x5c) & 0x1f0000) >> 0xb) +
                                            ((uVar10 & 0x7c0) >> 6) + DAT_100362d0) | 0xffffe000) <<
                                 8 | (uint)*(byte *)(((*(uint *)(iVar4 + 0x58) & 0x1f0000) >> 0xb) +
                                                     ((uVar10 & 0xf800) >> 0xb) + DAT_100362d0) <<
                                     0x10 |
                                (uint)*(byte *)(((*(uint *)(iVar4 + 0x60) & 0x1f0000) >> 0xb) +
                                                (uVar10 & 0x1f) + DAT_100362d0)) << 3);
            if (_DAT_1003607c <= *(float *)(iVar4 + 0x14)) {
              if (*(float *)(iVar4 + 0x14) <= _DAT_10036080) {
                lVar18 = __ftol();
                pfVar8[5] = *(float *)(DAT_1003a020 + (int)lVar18 * 4);
              }
              else {
                pfVar8[5] = 0.0;
              }
            }
            else {
              pfVar8[5] = -1.7014118e+38;
            }
            pfVar1 = pfVar8 + 8;
            pfVar8[6] = 0.0;
            pfVar8[7] = 0.0;
            pfVar12 = pfVar1;
            for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
              *pfVar12 = *pfVar9;
              pfVar9 = pfVar9 + 1;
              pfVar12 = pfVar12 + 1;
            }
            pfVar9 = pfVar8 + 0x18;
            pfVar12 = pfVar8;
            pfVar17 = pfVar8 + 0x10;
            for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
              *pfVar17 = *pfVar12;
              pfVar12 = pfVar12 + 1;
              pfVar17 = pfVar17 + 1;
            }
            uVar19 = uVar19 + 3;
            *pfVar1 = *pfVar1 + _DAT_10034618;
            pfVar8[0x11] = pfVar8[0x11] + _DAT_10034618;
          }
          iStack00000010 = iStack00000010 + -1;
          pfVar8 = pfVar9;
        } while (iStack00000010 != 0);
      }
      iStack00000014 = iStack00000014 + uVar19 * -0x20;
      iStack00000018 = iStack00000018 + ((int)uVar19 / -3) * 8 + -0x6c;
      if (((iStack00000014 < 1) || (iStack00000018 < 1)) &&
         (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < (int)uVar19) {
        puVar11 = *(undefined4 **)(DAT_1003a024 + 0x28);
        uVar10 = (uint)((int)puVar11 - *(int *)(DAT_1003a024 + 0x24)) >> 5;
        if (puVar11 != &DAT_10038b78) {
          puVar13 = &DAT_10038b78;
          for (iVar4 = (uVar19 & 0x7ffffff) << 3; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar11 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar11 = puVar11 + 1;
          }
          for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
            *(undefined1 *)puVar11 = *(undefined1 *)puVar13;
            puVar13 = (undefined4 *)((int)puVar13 + 1);
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar19 * 0x20;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = (short)uVar10;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = (short)uVar10;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar19;
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
        iVar4 = (int)uVar19 / 3;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)iVar4;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar15 = *(short **)(DAT_1003a024 + 0x30);
        psVar14 = psVar15;
        if (0 < iVar4) {
          do {
            sVar7 = (short)uVar10;
            *psVar14 = sVar7;
            psVar14[1] = sVar7 + 1;
            psVar14[2] = sVar7 + 2;
            psVar15 = psVar14 + 4;
            uVar10 = (uint)(ushort)(sVar7 + 3);
            iVar4 = iVar4 + -1;
            psVar14[3] = 0x700;
            psVar14 = psVar15;
          } while (iVar4 != 0);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar15;
      }
    }
    else {
      piStack0000000c = in_stack_00000020 + 0xf;
      uVar19 = 0;
      iStack00000010 = *(byte *)((int)in_stack_00000020 + 0x3a) - 1;
      if (0 < iStack00000010) {
        puVar11 = &DAT_10038b8c;
        do {
          iVar5 = DAT_100362d0;
          piVar3 = piStack0000000c + 1;
          iVar4 = *piStack0000000c;
          puVar13 = puVar11;
          piStack0000000c = piVar3;
          if ((*(byte *)(iVar4 + 0x48) & 0x3f) == 0) {
            fVar2 = (float)DAT_10042038;
            puVar11[-5] = (float)*(int *)(iVar4 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            puVar11[-4] = (float)*(int *)(iVar4 + 0x1c) * _DAT_10034610 + fVar2;
            puVar11[-3] = (float)(ushort)~*(ushort *)(iVar4 + 0x22) * _DAT_10034614;
            puVar11[-2] = 0x3f800000;
            uVar10 = *(uint *)(*in_stack_00000020 + 8);
            puVar11[-1] = ((*(byte *)(((*(uint *)(iVar4 + 0x5c) & 0x1f0000) >> 0xb) +
                                      ((uVar10 & 0x7c0) >> 6) + iVar5) | 0xffffe000) << 8 |
                           (uint)*(byte *)(((*(uint *)(iVar4 + 0x58) & 0x1f0000) >> 0xb) +
                                           ((uVar10 & 0xf800) >> 0xb) + iVar5) << 0x10 |
                          (uint)*(byte *)(((*(uint *)(iVar4 + 0x60) & 0x1f0000) >> 0xb) +
                                          (uVar10 & 0x1f) + iVar5)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar4 + 0x14)) {
              if (*(float *)(iVar4 + 0x14) <= _DAT_10036080) {
                lVar18 = __ftol();
                *puVar11 = *(undefined4 *)(DAT_1003a020 + (int)lVar18 * 4);
              }
              else {
                *puVar11 = 0;
              }
            }
            else {
              *puVar11 = 0xff000000;
            }
            puVar13 = puVar11 + 8;
            uVar19 = uVar19 + 1;
            puVar11[1] = 0;
            puVar11[2] = 0;
          }
          iStack00000010 = iStack00000010 + -1;
          puVar11 = puVar13;
        } while (iStack00000010 != 0);
      }
      iStack00000014 = iStack00000014 + uVar19 * -0x20;
      iStack00000018 = iStack00000018 + -0x70;
      if (((iStack00000014 < 1) || (iStack00000018 < 1)) &&
         (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < (int)uVar19) {
        puVar11 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar4 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar11 != &DAT_10038b78) {
          puVar13 = &DAT_10038b78;
          puVar16 = puVar11;
          for (iVar5 = (uVar19 & 0x7ffffff) << 3; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar16 = *puVar13;
            puVar13 = puVar13 + 1;
            puVar16 = puVar16 + 1;
          }
          for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined1 *)puVar16 = *(undefined1 *)puVar13;
            puVar13 = (undefined4 *)((int)puVar13 + 1);
            puVar16 = (undefined4 *)((int)puVar16 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar19 * 0x20;
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
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 10;
        uVar6 = (undefined2)((uint)((int)puVar11 - iVar4) >> 5);
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar6;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 6) = uVar6;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar19;
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
        **(undefined2 **)(DAT_1003a024 + 0x30) = (short)uVar19;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = uVar6;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      }
    }
  }
  return 0;
}


