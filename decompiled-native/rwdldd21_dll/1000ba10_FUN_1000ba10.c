// 1000ba10 FUN_1000ba10 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000ba10(int *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  short sVar8;
  float *pfVar9;
  float *pfVar10;
  uint uVar11;
  undefined4 *puVar12;
  float *pfVar13;
  undefined4 *puVar14;
  short *psVar15;
  short *psVar16;
  undefined4 *puVar17;
  float *pfVar18;
  longlong lVar19;
  uint uStack_1c;
  int *piStack_10;
  int iStack_c;
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    iVar4 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    iVar5 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      uStack_1c = 0;
      iStack_c = *(byte *)((int)param_1 + 0x3a) - 1;
      if (0 < iStack_c) {
        pfVar9 = (float *)&DAT_10038b78;
        piStack_10 = param_1 + 0xf;
        do {
          iVar6 = *piStack_10;
          pfVar10 = pfVar9;
          if ((*(byte *)(iVar6 + 0x48) & 0x3f) == 0) {
            fVar2 = (float)DAT_10042038;
            *pfVar9 = (float)*(int *)(iVar6 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            pfVar9[1] = (float)*(int *)(iVar6 + 0x1c) * _DAT_10034610 + fVar2;
            pfVar9[2] = (float)(ushort)~*(ushort *)(iVar6 + 0x22) * _DAT_10034614;
            pfVar9[3] = 1.0;
            uVar11 = *(uint *)(*param_1 + 8);
            pfVar9[4] = (float)(((*(byte *)(((*(uint *)(iVar6 + 0x5c) & 0x1f0000) >> 0xb) +
                                            ((uVar11 & 0x7c0) >> 6) + DAT_100362d0) | 0xffffe000) <<
                                 8 | (uint)*(byte *)(((*(uint *)(iVar6 + 0x58) & 0x1f0000) >> 0xb) +
                                                     ((uVar11 & 0xf800) >> 0xb) + DAT_100362d0) <<
                                     0x10 |
                                (uint)*(byte *)(((*(uint *)(iVar6 + 0x60) & 0x1f0000) >> 0xb) +
                                                (uVar11 & 0x1f) + DAT_100362d0)) << 3);
            if (_DAT_1003607c <= *(float *)(iVar6 + 0x14)) {
              if (*(float *)(iVar6 + 0x14) <= _DAT_10036080) {
                lVar19 = __ftol();
                pfVar9[5] = *(float *)(DAT_1003a020 + (int)lVar19 * 4);
              }
              else {
                pfVar9[5] = 0.0;
              }
            }
            else {
              pfVar9[5] = -1.7014118e+38;
            }
            pfVar1 = pfVar9 + 8;
            pfVar9[6] = 0.0;
            pfVar9[7] = 0.0;
            pfVar13 = pfVar1;
            for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
              *pfVar13 = *pfVar10;
              pfVar10 = pfVar10 + 1;
              pfVar13 = pfVar13 + 1;
            }
            pfVar10 = pfVar9 + 0x18;
            pfVar13 = pfVar9;
            pfVar18 = pfVar9 + 0x10;
            for (iVar6 = 8; iVar6 != 0; iVar6 = iVar6 + -1) {
              *pfVar18 = *pfVar13;
              pfVar13 = pfVar13 + 1;
              pfVar18 = pfVar18 + 1;
            }
            uStack_1c = uStack_1c + 3;
            *pfVar1 = *pfVar1 + _DAT_10034618;
            pfVar9[0x11] = pfVar9[0x11] + _DAT_10034618;
          }
          iStack_c = iStack_c + -1;
          pfVar9 = pfVar10;
          piStack_10 = piStack_10 + 1;
        } while (iStack_c != 0);
      }
      if ((((int)(iVar4 + uStack_1c * -0x20) < 1) || (iVar5 + ((int)uStack_1c / -3) * 8 + -0x6c < 1)
          ) && (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < (int)uStack_1c) {
        puVar12 = *(undefined4 **)(DAT_1003a024 + 0x28);
        uVar11 = (uint)((int)puVar12 - *(int *)(DAT_1003a024 + 0x24)) >> 5;
        if (puVar12 != &DAT_10038b78) {
          puVar14 = &DAT_10038b78;
          for (iVar4 = (uStack_1c & 0x7ffffff) << 3; iVar4 != 0; iVar4 = iVar4 + -1) {
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
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack_1c * 0x20;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = (short)uVar11;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = (short)uVar11;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack_1c;
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
        iVar4 = (int)uStack_1c / 3;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)iVar4;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar16 = *(short **)(DAT_1003a024 + 0x30);
        psVar15 = psVar16;
        if (0 < iVar4) {
          do {
            sVar8 = (short)uVar11;
            *psVar15 = sVar8;
            psVar15[1] = sVar8 + 1;
            psVar15[2] = sVar8 + 2;
            psVar16 = psVar15 + 4;
            uVar11 = (uint)(ushort)(sVar8 + 3);
            iVar4 = iVar4 + -1;
            psVar15[3] = 0x700;
            psVar15 = psVar16;
          } while (iVar4 != 0);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar16;
      }
    }
    else {
      uStack_1c = 0;
      iStack_c = *(byte *)((int)param_1 + 0x3a) - 1;
      if (0 < iStack_c) {
        puVar12 = &DAT_10038b8c;
        piStack_10 = param_1 + 0xf;
        do {
          iVar3 = DAT_100362d0;
          iVar6 = *piStack_10;
          puVar14 = puVar12;
          if ((*(byte *)(iVar6 + 0x48) & 0x3f) == 0) {
            fVar2 = (float)DAT_10042038;
            puVar12[-5] = (float)*(int *)(iVar6 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            puVar12[-4] = (float)*(int *)(iVar6 + 0x1c) * _DAT_10034610 + fVar2;
            puVar12[-3] = (float)(ushort)~*(ushort *)(iVar6 + 0x22) * _DAT_10034614;
            puVar12[-2] = 0x3f800000;
            uVar11 = *(uint *)(*param_1 + 8);
            puVar12[-1] = ((*(byte *)(((*(uint *)(iVar6 + 0x5c) & 0x1f0000) >> 0xb) +
                                      ((uVar11 & 0x7c0) >> 6) + iVar3) | 0xffffe000) << 8 |
                           (uint)*(byte *)(((*(uint *)(iVar6 + 0x58) & 0x1f0000) >> 0xb) +
                                           ((uVar11 & 0xf800) >> 0xb) + iVar3) << 0x10 |
                          (uint)*(byte *)(((*(uint *)(iVar6 + 0x60) & 0x1f0000) >> 0xb) +
                                          (uVar11 & 0x1f) + iVar3)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar6 + 0x14)) {
              if (*(float *)(iVar6 + 0x14) <= _DAT_10036080) {
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
            puVar14 = puVar12 + 8;
            uStack_1c = uStack_1c + 1;
            puVar12[1] = 0;
            puVar12[2] = 0;
          }
          iStack_c = iStack_c + -1;
          puVar12 = puVar14;
          piStack_10 = piStack_10 + 1;
        } while (iStack_c != 0);
      }
      if ((((int)(iVar4 + uStack_1c * -0x20) < 1) || (iVar5 + -0x70 < 1)) &&
         (iVar4 = FUN_10001080(DAT_1003a024), iVar4 == 0)) {
        return 0;
      }
      if (0 < (int)uStack_1c) {
        puVar12 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar4 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar12 != &DAT_10038b78) {
          puVar14 = &DAT_10038b78;
          puVar17 = puVar12;
          for (iVar5 = (uStack_1c & 0x7ffffff) << 3; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar17 = *puVar14;
            puVar14 = puVar14 + 1;
            puVar17 = puVar17 + 1;
          }
          for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
            *(undefined1 *)puVar17 = *(undefined1 *)puVar14;
            puVar14 = (undefined4 *)((int)puVar14 + 1);
            puVar17 = (undefined4 *)((int)puVar17 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uStack_1c * 0x20;
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
        uVar7 = (undefined2)((uint)((int)puVar12 - iVar4) >> 5);
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar7;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 6) = uVar7;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uStack_1c;
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
        **(undefined2 **)(DAT_1003a024 + 0x30) = (undefined2)uStack_1c;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = uVar7;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      }
    }
  }
  return 0;
}


