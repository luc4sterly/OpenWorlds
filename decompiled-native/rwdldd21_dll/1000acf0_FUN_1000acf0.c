// 1000acf0 FUN_1000acf0 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000acf0(int *param_1,int param_2)

{
  float *pfVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined2 uVar9;
  float fVar10;
  short sVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  float *pfVar17;
  float *pfVar18;
  float *pfVar19;
  short *psVar20;
  short *psVar21;
  undefined4 *puVar22;
  float *pfVar23;
  longlong lVar24;
  int local_18;
  uint local_14;
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar5 = FUN_1000a000(param_1,param_2);
    return uVar5;
  }
  bVar2 = *(byte *)(*param_1 + 0x30);
  if (((bVar2 & 0x80) != 0) || (param_2 == 0)) {
    fVar3 = _DAT_1003461c;
    if ((bVar2 & 0x40) != 0) {
      fVar3 = _DAT_10034620;
    }
    iVar6 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    iVar7 = *(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30);
    uVar14 = *(uint *)(*param_1 + 8);
    uVar12 = 0;
    fVar10 = (float)(((*(byte *)(((param_1[2] & 0x1f0000U) >> 0xb) + ((uVar14 & 0x7c0) >> 6) +
                                DAT_100362d0) | 0xffffe000) << 8 |
                      (uint)*(byte *)(((param_1[1] & 0x1f0000U) >> 0xb) + ((uVar14 & 0xf800) >> 0xb)
                                     + DAT_100362d0) << 0x10 |
                     (uint)*(byte *)(((param_1[3] & 0x1f0000U) >> 0xb) + (uVar14 & 0x1f) +
                                    DAT_100362d0)) << 3);
    if (*(int *)(DAT_1003a024 + 0x74) == 0) {
      piVar13 = param_1 + 0xf;
      local_14 = 0;
      local_18 = *(byte *)((int)param_1 + 0x3a) - 1;
      if (0 < local_18) {
        pfVar17 = (float *)&DAT_10038b78;
        do {
          iVar8 = *piVar13;
          piVar13 = piVar13 + 1;
          pfVar18 = pfVar17;
          if ((*(byte *)(iVar8 + 0x48) & 0x3f) == 0) {
            fVar4 = (float)DAT_10042038;
            *pfVar17 = (float)*(int *)(iVar8 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            pfVar17[1] = (float)*(int *)(iVar8 + 0x1c) * _DAT_10034610 + fVar4;
            pfVar17[2] = (float)(ushort)~*(ushort *)(iVar8 + 0x22) * _DAT_10034614 - fVar3;
            pfVar17[3] = 1.0;
            pfVar17[4] = fVar10;
            if (_DAT_1003607c <= *(float *)(iVar8 + 0x14)) {
              if (*(float *)(iVar8 + 0x14) <= _DAT_10036080) {
                lVar24 = __ftol();
                pfVar17[5] = *(float *)(DAT_1003a020 + (int)lVar24 * 4);
              }
              else {
                pfVar17[5] = 0.0;
              }
            }
            else {
              pfVar17[5] = -1.7014118e+38;
            }
            pfVar1 = pfVar17 + 8;
            pfVar17[6] = 0.0;
            pfVar17[7] = 0.0;
            pfVar19 = pfVar1;
            for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
              *pfVar19 = *pfVar18;
              pfVar18 = pfVar18 + 1;
              pfVar19 = pfVar19 + 1;
            }
            pfVar18 = pfVar17 + 0x18;
            pfVar19 = pfVar17;
            pfVar23 = pfVar17 + 0x10;
            for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
              *pfVar23 = *pfVar19;
              pfVar19 = pfVar19 + 1;
              pfVar23 = pfVar23 + 1;
            }
            local_14 = local_14 + 3;
            *pfVar1 = *pfVar1 + _DAT_10034618;
            pfVar17[0x11] = pfVar17[0x11] + _DAT_10034618;
          }
          local_18 = local_18 + -1;
          pfVar17 = pfVar18;
        } while (local_18 != 0);
      }
      if ((((int)(iVar6 + local_14 * -0x20) < 1) || (iVar7 + ((int)local_14 / -3) * 8 + -0x6c < 1))
         && (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
        return 0;
      }
      if (0 < (int)local_14) {
        puVar15 = *(undefined4 **)(DAT_1003a024 + 0x28);
        uVar14 = (uint)((int)puVar15 - *(int *)(DAT_1003a024 + 0x24)) >> 5;
        if (puVar15 != &DAT_10038b78) {
          puVar16 = &DAT_10038b78;
          for (iVar6 = (local_14 & 0x7ffffff) << 3; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar15 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar15 = puVar15 + 1;
          }
          for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
            *(undefined1 *)puVar15 = *(undefined1 *)puVar16;
            puVar16 = (undefined4 *)((int)puVar16 + 1);
            puVar15 = (undefined4 *)((int)puVar15 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + local_14 * 0x20;
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
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = (short)uVar14;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = (short)uVar14;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = local_14;
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
        iVar6 = (int)local_14 / 3;
        *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)iVar6;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
        psVar21 = *(short **)(DAT_1003a024 + 0x30);
        psVar20 = psVar21;
        if (0 < iVar6) {
          do {
            sVar11 = (short)uVar14;
            *psVar20 = sVar11;
            psVar20[1] = sVar11 + 1;
            psVar20[2] = sVar11 + 2;
            psVar21 = psVar20 + 4;
            uVar14 = (uint)(ushort)(sVar11 + 3);
            iVar6 = iVar6 + -1;
            psVar20[3] = 0x700;
            psVar20 = psVar21;
          } while (iVar6 != 0);
        }
        *(short **)(DAT_1003a024 + 0x30) = psVar21;
      }
    }
    else {
      piVar13 = param_1 + 0xf;
      local_18 = *(byte *)((int)param_1 + 0x3a) - 1;
      if (0 < local_18) {
        puVar15 = &DAT_10038b8c;
        do {
          iVar8 = *piVar13;
          piVar13 = piVar13 + 1;
          puVar16 = puVar15;
          if ((*(byte *)(iVar8 + 0x48) & 0x3f) == 0) {
            fVar4 = (float)DAT_10042038;
            puVar15[-5] = (float)*(int *)(iVar8 + 0x18) * _DAT_10034610 + (float)DAT_10042034;
            puVar15[-4] = (float)*(int *)(iVar8 + 0x1c) * _DAT_10034610 + fVar4;
            puVar15[-3] = (float)(ushort)~*(ushort *)(iVar8 + 0x22) * _DAT_10034614 - fVar3;
            puVar15[-2] = 0x3f800000;
            puVar15[-1] = fVar10;
            if (_DAT_1003607c <= *(float *)(iVar8 + 0x14)) {
              if (*(float *)(iVar8 + 0x14) <= _DAT_10036080) {
                lVar24 = __ftol();
                *puVar15 = *(undefined4 *)(DAT_1003a020 + (int)lVar24 * 4);
              }
              else {
                *puVar15 = 0;
              }
            }
            else {
              *puVar15 = 0xff000000;
            }
            puVar15[1] = 0;
            puVar16 = puVar15 + 8;
            uVar12 = uVar12 + 1;
            puVar15[2] = 0;
          }
          local_18 = local_18 + -1;
          puVar15 = puVar16;
        } while (local_18 != 0);
      }
      if ((((int)(iVar6 + uVar12 * -0x20) < 1) || (iVar7 + -0x70 < 1)) &&
         (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
        return 0;
      }
      if (0 < (int)uVar12) {
        puVar15 = *(undefined4 **)(DAT_1003a024 + 0x28);
        iVar6 = *(int *)(DAT_1003a024 + 0x24);
        if (puVar15 != &DAT_10038b78) {
          puVar16 = &DAT_10038b78;
          puVar22 = puVar15;
          for (iVar7 = (uVar12 & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar22 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar22 = puVar22 + 1;
          }
          for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
            *(undefined1 *)puVar22 = *(undefined1 *)puVar16;
            puVar16 = (undefined4 *)((int)puVar16 + 1);
            puVar22 = (undefined4 *)((int)puVar22 + 1);
          }
        }
        *(int *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar12 * 0x20;
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
        uVar9 = (undefined2)((uint)((int)puVar15 - iVar6) >> 5);
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar9;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 6) = uVar9;
        *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar12;
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
        **(undefined2 **)(DAT_1003a024 + 0x30) = (short)uVar12;
        *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = uVar9;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      }
    }
  }
  return 0;
}


