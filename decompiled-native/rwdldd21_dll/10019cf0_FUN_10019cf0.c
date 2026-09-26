// 10019cf0 FUN_10019cf0 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10019cf0(int *param_1,int param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  short sVar5;
  undefined4 uVar6;
  int iVar7;
  short sVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  short *psVar12;
  short *psVar13;
  undefined4 *puVar14;
  longlong lVar15;
  uint local_20;
  uint local_1c;
  int *local_10;
  
  if (*(int *)(DAT_1003a024 + 4) == 0) {
    uVar6 = FUN_10019600(param_1,param_2);
    return uVar6;
  }
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    fVar2 = _DAT_1003461c;
    if ((*(byte *)(*param_1 + 0x30) & 0x40) != 0) {
      fVar2 = _DAT_10034620;
    }
    local_20 = 0;
    local_1c = (uint)*(byte *)((int)param_1 + 0x3a);
    if (local_1c != 0) {
      fVar3 = (float)DAT_10042034;
      fVar4 = (float)DAT_10042038;
      puVar10 = &DAT_10038b8c;
      local_10 = param_1 + 0xf;
      do {
        iVar9 = DAT_100362d0;
        local_1c = local_1c - 1;
        iVar7 = *local_10;
        puVar10[-5] = (float)*(int *)(iVar7 + 0x18) * _DAT_10034610 + fVar3;
        puVar10[-4] = (float)*(int *)(iVar7 + 0x1c) * _DAT_10034610 + fVar4;
        puVar10[-3] = (float)(ushort)~*(ushort *)(iVar7 + 0x22) * _DAT_10034614 - fVar2;
        puVar10[-2] = 0x3f800000;
        uVar1 = *(uint *)(*param_1 + 8);
        puVar10[-1] = ((*(byte *)(((*(uint *)(iVar7 + 0x5c) & 0x1f0000) >> 0xb) +
                                  ((uVar1 & 0x7c0) >> 6) + iVar9) | 0xffffe000) << 8 |
                       (uint)*(byte *)(((*(uint *)(iVar7 + 0x58) & 0x1f0000) >> 0xb) +
                                       ((uVar1 & 0xf800) >> 0xb) + iVar9) << 0x10 |
                      (uint)*(byte *)(((*(uint *)(iVar7 + 0x60) & 0x1f0000) >> 0xb) + (uVar1 & 0x1f)
                                     + iVar9)) << 3;
        if (_DAT_1003607c <= *(float *)(iVar7 + 0x14)) {
          if (*(float *)(iVar7 + 0x14) <= _DAT_10036080) {
            lVar15 = __ftol();
            *puVar10 = *(undefined4 *)(DAT_1003a020 + (int)lVar15 * 4);
          }
          else {
            *puVar10 = 0;
          }
        }
        else {
          *puVar10 = 0xff000000;
        }
        local_20 = local_20 + 1;
        puVar10[1] = 0;
        puVar10[2] = 0;
        puVar10 = puVar10 + 8;
        local_10 = local_10 + 1;
      } while (0 < (int)local_1c);
    }
    iVar9 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + local_20 * -8;
    iVar7 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    if (((iVar7 == local_20 * 0x20 || (int)(iVar7 + local_20 * -0x20) < 0) ||
        (iVar9 == 0x6c || iVar9 + -0x6c < 0)) && (iVar7 = FUN_10001080(DAT_1003a024), iVar7 == 0)) {
      return 0;
    }
    if (0 < (int)local_20) {
      puVar10 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar7 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar10 != &DAT_10038b78) {
        puVar11 = &DAT_10038b78;
        puVar14 = puVar10;
        for (iVar9 = (local_20 & 0x7ffffff) << 3; iVar9 != 0; iVar9 = iVar9 + -1) {
          *puVar14 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar14 = puVar14 + 1;
        }
        for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
          *(undefined1 *)puVar14 = *(undefined1 *)puVar11;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
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
      iVar9 = *(int *)(DAT_1003a024 + 100);
      if (*(int *)(DAT_1003a024 + 0x98) != iVar9) {
        *(int *)(DAT_1003a024 + 0x98) = iVar9;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar9;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
        *(int *)(*(int *)(DAT_1003a024 + 0x30) + 4) = iVar9;
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
      sVar8 = (short)((uint)((int)puVar10 - iVar7) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar8;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar8;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)local_20 + -2;
      iVar7 = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar13 = *(short **)(DAT_1003a024 + 0x30);
      psVar12 = psVar13;
      if (1 < (int)(local_20 - 1)) {
        do {
          *psVar12 = sVar8;
          sVar5 = sVar8 + (short)iVar7;
          if (param_2 == 0) {
            psVar12[1] = sVar5 + 1;
          }
          else {
            psVar12[1] = sVar5;
            sVar5 = sVar5 + 1;
          }
          psVar12[2] = sVar5;
          psVar13 = psVar12 + 4;
          psVar12[3] = 0x700;
          iVar7 = iVar7 + 1;
          psVar12 = psVar13;
        } while (iVar7 < (int)(local_20 - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar13;
    }
  }
  return 0;
}


