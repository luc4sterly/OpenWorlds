// 1000c7b0 FUN_1000c7b0 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000c7b0(int *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  short sVar10;
  float *pfVar11;
  float *pfVar12;
  uint uVar13;
  undefined4 *puVar14;
  float *pfVar15;
  undefined4 *puVar16;
  short *psVar17;
  short *psVar18;
  undefined4 *puVar19;
  float *pfVar20;
  longlong lVar21;
  uint local_20;
  int *local_14;
  int local_10;
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar5 = FUN_1000ba10(param_1,param_2);
    return uVar5;
  }
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    fVar2 = _DAT_1003461c;
    if ((*(byte *)(*param_1 + 0x30) & 0x40) != 0) {
      fVar2 = _DAT_10034620;
    }
    iVar6 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    iVar7 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      local_20 = 0;
      local_10 = *(byte *)((int)param_1 + 0x3a) - 1;
      if (0 < local_10) {
        pfVar11 = (float *)&DAT_10038b78;
        local_14 = param_1 + 0xf;
        do {
          iVar8 = *local_14;
          pfVar12 = pfVar11;
          if ((*(byte *)(iVar8 + 0x48) & 0x3f) == 0) {
            fVar3 = (float)DAT_10042038;
            *pfVar11 = (float)*(int *)(iVar8 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            pfVar11[1] = (float)*(int *)(iVar8 + 0x1c) * _DAT_10034610 + fVar3;
            pfVar11[2] = (float)(ushort)~*(ushort *)(iVar8 + 0x22) * _DAT_10034614 - fVar2;
            pfVar11[3] = 1.0;
            uVar13 = *(uint *)(*param_1 + 8);
            pfVar11[4] = (float)(((*(byte *)(((*(uint *)(iVar8 + 0x5c) & 0x1f0000) >> 0xb) +
                                             ((uVar13 & 0x7c0) >> 6) + DAT_100362d0) | 0xffffe000)
                                  << 8 | (uint)*(byte *)(((*(uint *)(iVar8 + 0x58) & 0x1f0000) >>
                                                         0xb) + ((uVar13 & 0xf800) >> 0xb) +
                                                        DAT_100362d0) << 0x10 |
                                 (uint)*(byte *)(((*(uint *)(iVar8 + 0x60) & 0x1f0000) >> 0xb) +
                                                 (uVar13 & 0x1f) + DAT_100362d0)) << 3);
            if (_DAT_1003607c <= *(float *)(iVar8 + 0x14)) {
              if (*(float *)(iVar8 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                pfVar11[5] = *(float *)(DAT_1003a020 + (int)lVar21 * 4);
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
            pfVar15 = pfVar1;
            for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
              *pfVar15 = *pfVar12;
              pfVar12 = pfVar12 + 1;
              pfVar15 = pfVar15 + 1;
            }
            pfVar12 = pfVar11 + 0x18;
            pfVar15 = pfVar11;
            pfVar20 = pfVar11 + 0x10;
            for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
              *pfVar20 = *pfVar15;
              pfVar15 = pfVar15 + 1;
              pfVar20 = pfVar20 + 1;
            }
            local_20 = local_20 + 3;
            *pfVar1 = *pfVar1 + _DAT_10034618;
            pfVar11[0x11] = pfVar11[0x11] + _DAT_10034618;
          }
          local_10 = local_10 + -1;
          pfVar11 = pfVar12;
          local_14 = local_14 + 1;
        } while (local_10 != 0);
      }
      if ((((int)(iVar6 + local_20 * -0x20) < 1) || (iVar7 + ((int)local_20 / -3) * 8 + -0x6c < 1))
         && (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
        return 0;
      }
      if (0 < (int)local_20) {
        puVar14 = *(undefined4 **)(DAT_1003a024 + 0x28);
        uVar13 = (uint)((int)puVar14 - *(int *)(DAT_1003a024 + 0x24)) >> 5;
        if (puVar14 != &DAT_10038b78) {
          puVar16 = &DAT_10038b78;
          for (iVar6 = (local_20 & 0x7ffffff) << 3; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar14 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar14 = puVar14 + 1;
          }
          for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined1 *)puVar14 = *(undefined1 *)puVar16;
            puVar16 = (undefined4 *)((int)puVar16 + 1);
            puVar14 = (undefined4 *)((int)puVar14 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + local_20 * 0x20;
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
        if (*(int *)(DAT_1003a024 + 0x90) == 0) {
          *(undefined4 *)(DAT_1003a024 + 0x90) = 1;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 7;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0xe;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x17;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = (short)uVar13;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = (short)uVar13;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = local_20;
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
        iVar6 = (int)local_20 / 3;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)iVar6;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar18 = *(short **)(DAT_1003a024 + 0x30);
        psVar17 = psVar18;
        if (0 < iVar6) {
          do {
            sVar10 = (short)uVar13;
            *psVar17 = sVar10;
            psVar17[1] = sVar10 + 1;
            psVar17[2] = sVar10 + 2;
            psVar18 = psVar17 + 4;
            uVar13 = (uint)(ushort)(sVar10 + 3);
            iVar6 = iVar6 + -1;
            psVar17[3] = 0x700;
            psVar17 = psVar18;
          } while (iVar6 != 0);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar18;
      }
    }
    else {
      local_20 = 0;
      local_10 = *(byte *)((int)param_1 + 0x3a) - 1;
      if (0 < local_10) {
        puVar14 = &DAT_10038b8c;
        local_14 = param_1 + 0xf;
        do {
          iVar4 = DAT_100362d0;
          iVar8 = *local_14;
          puVar16 = puVar14;
          if ((*(byte *)(iVar8 + 0x48) & 0x3f) == 0) {
            fVar3 = (float)DAT_10042038;
            puVar14[-5] = (float)*(int *)(iVar8 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            puVar14[-4] = (float)*(int *)(iVar8 + 0x1c) * _DAT_10034610 + fVar3;
            puVar14[-3] = (float)(ushort)~*(ushort *)(iVar8 + 0x22) * _DAT_10034614 - fVar2;
            puVar14[-2] = 0x3f800000;
            uVar13 = *(uint *)(*param_1 + 8);
            puVar14[-1] = ((*(byte *)(((*(uint *)(iVar8 + 0x5c) & 0x1f0000) >> 0xb) +
                                      ((uVar13 & 0x7c0) >> 6) + iVar4) | 0xffffe000) << 8 |
                           (uint)*(byte *)(((*(uint *)(iVar8 + 0x58) & 0x1f0000) >> 0xb) +
                                           ((uVar13 & 0xf800) >> 0xb) + iVar4) << 0x10 |
                          (uint)*(byte *)(((*(uint *)(iVar8 + 0x60) & 0x1f0000) >> 0xb) +
                                          (uVar13 & 0x1f) + iVar4)) << 3;
            if (_DAT_1003607c <= *(float *)(iVar8 + 0x14)) {
              if (*(float *)(iVar8 + 0x14) <= _DAT_10036080) {
                lVar21 = __ftol();
                *puVar14 = *(undefined4 *)(DAT_1003a020 + (int)lVar21 * 4);
              }
              else {
                *puVar14 = 0;
              }
            }
            else {
              *puVar14 = 0xff000000;
            }
            puVar16 = puVar14 + 8;
            local_20 = local_20 + 1;
            puVar14[1] = 0;
            puVar14[2] = 0;
          }
          local_10 = local_10 + -1;
          puVar14 = puVar16;
          local_14 = local_14 + 1;
        } while (local_10 != 0);
      }
      if ((((int)(iVar6 + local_20 * -0x20) < 1) || (iVar7 + -0x70 < 1)) &&
         (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
        return 0;
      }
      if (0 < (int)local_20) {
        puVar14 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar6 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar14 != &DAT_10038b78) {
          puVar16 = &DAT_10038b78;
          puVar19 = puVar14;
          for (iVar7 = (local_20 & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar19 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar19 = puVar19 + 1;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined1 *)puVar19 = *(undefined1 *)puVar16;
            puVar16 = (undefined4 *)((int)puVar16 + 1);
            puVar19 = (undefined4 *)((int)puVar19 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + local_20 * 0x20;
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
        if (*(int *)(DAT_1003a024 + 0x90) == 0) {
          *(undefined4 *)(DAT_1003a024 + 0x90) = 1;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 7;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0xe;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
          *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
          **(undefined4 **)(DAT_1003a024 + 0x30) = 0x17;
          *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
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
        uVar9 = (undefined2)((uint)((int)puVar14 - iVar6) >> 5);
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar9;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 6) = uVar9;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = local_20;
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
        **(undefined2 **)(DAT_1003a024 + 0x30) = (undefined2)local_20;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = uVar9;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      }
    }
  }
  return 0;
}


