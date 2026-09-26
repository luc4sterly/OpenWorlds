// 10019600 FUN_10019600 [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10019600(int *param_1,int param_2)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  short *psVar10;
  short *psVar11;
  undefined4 *puVar12;
  longlong lVar13;
  uint uStack_1c;
  uint uStack_18;
  int *piStack_c;
  
  if (DAT_1003606c != 0) {
    FUN_10029ab0();
    DAT_1003606c = 0;
  }
  if (((*(byte *)(*param_1 + 0x30) & 0x80) != 0) || (param_2 == 0)) {
    uStack_1c = 0;
    uStack_18 = (uint)*(byte *)((int)param_1 + 0x3a);
    if (uStack_18 != 0) {
      fVar2 = (float)DAT_10042034;
      fVar3 = (float)DAT_10042038;
      puVar8 = &DAT_10038b8c;
      piStack_c = param_1 + 0xf;
      do {
        iVar7 = DAT_100362d0;
        uStack_18 = uStack_18 - 1;
        iVar5 = *piStack_c;
        puVar8[-5] = (float)*(int *)(iVar5 + 0x18) * _DAT_10034610 + fVar2;
        puVar8[-4] = (float)*(int *)(iVar5 + 0x1c) * _DAT_10034610 + fVar3;
        puVar8[-3] = (float)(ushort)~*(ushort *)(iVar5 + 0x22) * _DAT_10034614;
        puVar8[-2] = 0x3f800000;
        uVar1 = *(uint *)(*param_1 + 8);
        puVar8[-1] = ((*(byte *)(((*(uint *)(iVar5 + 0x58) & 0x1f0000) >> 0xb) +
                                 ((uVar1 & 0xf800) >> 0xb) + iVar7) | 0xffffffe0) << 0x10 |
                      (uint)*(byte *)(((*(uint *)(iVar5 + 0x5c) & 0x1f0000) >> 0xb) +
                                      ((uVar1 & 0x7c0) >> 6) + iVar7) << 8 |
                     (uint)*(byte *)(((*(uint *)(iVar5 + 0x60) & 0x1f0000) >> 0xb) + (uVar1 & 0x1f)
                                    + iVar7)) << 3;
        if (_DAT_1003607c <= *(float *)(iVar5 + 0x14)) {
          if (*(float *)(iVar5 + 0x14) <= _DAT_10036080) {
            lVar13 = __ftol();
            *puVar8 = *(undefined4 *)(DAT_1003a020 + (int)lVar13 * 4);
          }
          else {
            *puVar8 = 0;
          }
        }
        else {
          *puVar8 = 0xff000000;
        }
        uStack_1c = uStack_1c + 1;
        puVar8[1] = 0;
        puVar8[2] = 0;
        puVar8 = puVar8 + 8;
        piStack_c = piStack_c + 1;
      } while (0 < (int)uStack_18);
    }
    iVar7 = (*(int *)(DAT_1003a024 + 0x34) + uStack_1c * -8) - *(int *)(DAT_1003a024 + 0x30);
    iVar5 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
    if (((iVar5 == uStack_1c * 0x20 || (int)(iVar5 + uStack_1c * -0x20) < 0) ||
        (iVar7 == 0x6c || iVar7 + -0x6c < 0)) && (iVar5 = FUN_10001080(DAT_1003a024), iVar5 == 0)) {
      return 0;
    }
    if (0 < (int)uStack_1c) {
      puVar8 = *(undefined4 **)(DAT_1003a024 + 0x28);
      iVar5 = *(int *)(DAT_1003a024 + 0x24);
      if (puVar8 != &DAT_10038b78) {
        puVar9 = &DAT_10038b78;
        puVar12 = puVar8;
        for (iVar7 = (uStack_1c & 0x7ffffff) << 3; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar12 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar12 = puVar12 + 1;
        }
        for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
          *(undefined1 *)puVar12 = *(undefined1 *)puVar9;
          puVar9 = (undefined4 *)((int)puVar9 + 1);
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
      sVar6 = (short)((uint)((int)puVar8 - iVar5) >> 5);
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar6;
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar6;
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
      *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uStack_1c + -2;
      iVar5 = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
      psVar11 = *(short **)(DAT_1003a024 + 0x30);
      psVar10 = psVar11;
      if (1 < (int)(uStack_1c - 1)) {
        do {
          *psVar10 = sVar6;
          sVar4 = sVar6 + (short)iVar5;
          if (param_2 == 0) {
            psVar10[1] = sVar4 + 1;
          }
          else {
            psVar10[1] = sVar4;
            sVar4 = sVar4 + 1;
          }
          psVar10[2] = sVar4;
          psVar11 = psVar10 + 4;
          psVar10[3] = 0x700;
          iVar5 = iVar5 + 1;
          psVar10 = psVar11;
        } while (iVar5 < (int)(uStack_1c - 1));
      }
      *(short **)(DAT_1003a024 + 0x30) = psVar11;
    }
  }
  return 0;
}


