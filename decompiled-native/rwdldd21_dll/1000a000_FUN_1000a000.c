// 1000a000 FUN_1000a000 [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000a000(int *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  float fVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  int *piVar10;
  float *pfVar11;
  float *pfVar12;
  undefined4 *puVar13;
  float *pfVar14;
  undefined4 *puVar15;
  short *psVar16;
  short *psVar17;
  undefined4 *puVar18;
  float *pfVar19;
  longlong lVar20;
  int iStack_14;
  uint uStack_10;
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    uVar9 = *(uint *)(*param_1 + 8);
    fVar6 = (float)(((*(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + ((uVar9 & 0x7c0) >> 6) +
                               DAT_100362d0) | 0xffffe000) << 8 |
                     (uint)*(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + ((uVar9 & 0xf800) >> 0xb) +
                                    DAT_100362d0) << 0x10 |
                    (uint)*(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + (uVar9 & 0x1f) +
                                   DAT_100362d0)) << 3);
    iVar3 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    iVar7 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    uVar9 = 0;
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      piVar10 = param_1 + 0xf;
      uStack_10 = 0;
      iStack_14 = *(byte *)((int)param_1 + 0x3a) - 1;
      if (0 < iStack_14) {
        pfVar11 = (float *)&DAT_10038b78;
        do {
          iVar4 = *piVar10;
          piVar10 = piVar10 + 1;
          pfVar12 = pfVar11;
          if ((*(byte *)(iVar4 + 0x48) & 0x3f) == 0) {
            fVar2 = (float)DAT_10042038;
            *pfVar11 = (float)*(int *)(iVar4 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            pfVar11[1] = (float)*(int *)(iVar4 + 0x1c) * _DAT_10034610 + fVar2;
            pfVar11[2] = (float)(ushort)~*(ushort *)(iVar4 + 0x22) * _DAT_10034614;
            pfVar11[3] = 1.0;
            pfVar11[4] = fVar6;
            if (_DAT_1003607c <= *(float *)(iVar4 + 0x14)) {
              if (*(float *)(iVar4 + 0x14) <= _DAT_10036080) {
                lVar20 = __ftol();
                pfVar11[5] = *(float *)(DAT_1003a020 + (int)lVar20 * 4);
              }
              else {
                pfVar11[5] = 0.0;
              }
            }
            else {
              pfVar11[5] = -1.7014118e+38;
            }
            pfVar1 = pfVar11 + 8;
            pfVar11[6] = 0.0;
            pfVar11[7] = 0.0;
            pfVar14 = pfVar1;
            for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
              *pfVar14 = *pfVar12;
              pfVar12 = pfVar12 + 1;
              pfVar14 = pfVar14 + 1;
            }
            pfVar12 = pfVar11 + 0x18;
            pfVar14 = pfVar11;
            pfVar19 = pfVar11 + 0x10;
            for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
              *pfVar19 = *pfVar14;
              pfVar14 = pfVar14 + 1;
              pfVar19 = pfVar19 + 1;
            }
            uStack_10 = uStack_10 + 3;
            *pfVar1 = *pfVar1 + _DAT_10034618;
            pfVar11[0x11] = pfVar11[0x11] + _DAT_10034618;
          }
          iStack_14 = iStack_14 + -1;
          pfVar11 = pfVar12;
        } while (iStack_14 != 0);
      }
      if ((((int)(iVar3 + uStack_10 * -0x20) < 1) || (iVar7 + ((int)uStack_10 / -3) * 8 + -0x6c < 1)
          ) && (iVar3 = FUN_10001080(DAT_1003a024), iVar3 == 0)) {
        return 0;
      }
      if (0 < (int)uStack_10) {
        puVar13 = *(undefined4 **)(DAT_1003a024 + 0x28);
        uVar9 = (uint)((int)puVar13 - *(int *)(DAT_1003a024 + 0x24)) >> 5;
        if (puVar13 != &DAT_10038b78) {
          puVar15 = &DAT_10038b78;
          for (iVar3 = (uStack_10 & 0x7ffffff) << 3; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar13 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar13 = puVar13 + 1;
          }
          for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
            *(undefined1 *)puVar13 = *(undefined1 *)puVar15;
            puVar15 = (undefined4 *)((int)puVar15 + 1);
            puVar13 = (undefined4 *)((int)puVar13 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack_10 * 0x20;
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
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack_10;
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
        iVar3 = (int)uStack_10 / 3;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)iVar3;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar17 = *(short **)(DAT_1003a024 + 0x30);
        psVar16 = psVar17;
        if (0 < iVar3) {
          do {
            sVar8 = (short)uVar9;
            *psVar16 = sVar8;
            psVar16[1] = sVar8 + 1;
            psVar16[2] = sVar8 + 2;
            psVar17 = psVar16 + 4;
            uVar9 = (uint)(ushort)(sVar8 + 3);
            iVar3 = iVar3 + -1;
            psVar16[3] = 0x700;
            psVar16 = psVar17;
          } while (iVar3 != 0);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar17;
      }
    }
    else {
      piVar10 = param_1 + 0xf;
      iStack_14 = *(byte *)((int)param_1 + 0x3a) - 1;
      if (0 < iStack_14) {
        puVar13 = &DAT_10038b8c;
        do {
          iVar4 = *piVar10;
          piVar10 = piVar10 + 1;
          puVar15 = puVar13;
          if ((*(byte *)(iVar4 + 0x48) & 0x3f) == 0) {
            fVar2 = (float)DAT_10042038;
            puVar13[-5] = (float)*(int *)(iVar4 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            puVar13[-4] = (float)*(int *)(iVar4 + 0x1c) * _DAT_10034610 + fVar2;
            puVar13[-3] = (float)(ushort)~*(ushort *)(iVar4 + 0x22) * _DAT_10034614;
            puVar13[-2] = 0x3f800000;
            puVar13[-1] = fVar6;
            if (_DAT_1003607c <= *(float *)(iVar4 + 0x14)) {
              if (*(float *)(iVar4 + 0x14) <= _DAT_10036080) {
                lVar20 = __ftol();
                *puVar13 = *(undefined4 *)(DAT_1003a020 + (int)lVar20 * 4);
              }
              else {
                *puVar13 = 0;
              }
            }
            else {
              *puVar13 = 0xff000000;
            }
            puVar13[1] = 0;
            puVar15 = puVar13 + 8;
            uVar9 = uVar9 + 1;
            puVar13[2] = 0;
          }
          iStack_14 = iStack_14 + -1;
          puVar13 = puVar15;
        } while (iStack_14 != 0);
      }
      if ((((int)(iVar3 + uVar9 * -0x20) < 1) || (iVar7 + -0x70 < 1)) &&
         (iVar3 = FUN_10001080(DAT_1003a024), iVar3 == 0)) {
        return 0;
      }
      if (0 < (int)uVar9) {
        puVar13 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar3 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar13 != &DAT_10038b78) {
          puVar15 = &DAT_10038b78;
          puVar18 = puVar13;
          for (iVar7 = (uVar9 & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar18 = *puVar15;
            puVar15 = puVar15 + 1;
            puVar18 = puVar18 + 1;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined1 *)puVar18 = *(undefined1 *)puVar15;
            puVar15 = (undefined4 *)((int)puVar15 + 1);
            puVar18 = (undefined4 *)((int)puVar18 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar9 * 0x20;
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
        uVar5 = (undefined2)((uint)((int)puVar13 - iVar3) >> 5);
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar5;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 6) = uVar5;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar9;
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
        **(undefined2 **)(DAT_1003a024 + 0x30) = (short)uVar9;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = uVar5;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      }
    }
  }
  return 0;
}


