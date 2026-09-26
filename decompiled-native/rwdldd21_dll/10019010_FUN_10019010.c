// 10019010 FUN_10019010 [Global]
// programa: RWDLDD21.DLL

void FUN_10019010(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  short sVar8;
  uint *puVar9;
  short *psVar10;
  short *psVar11;
  uint *puVar12;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar7 = param_1[2];
  iVar6 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + uVar1 * -8;
  iVar5 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  if (((iVar5 != uVar1 * 0x20 && -1 < (int)(iVar5 + uVar1 * -0x20)) &&
      (iVar6 != 0x16c && -1 < iVar6 + -0x16c)) || (iVar5 = FUN_10001080(DAT_1003a024), iVar5 != 0))
  {
    puVar3 = *(uint **)(DAT_1003a024 + 0x28);
    iVar5 = *(int *)(DAT_1003a024 + 0x24);
    if (param_1 + 3 != puVar3) {
      puVar9 = param_1 + 3;
      puVar12 = puVar3;
      for (iVar6 = (uVar1 & 0x7ffffff) << 3; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar12 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar12 = puVar12 + 1;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(char *)puVar12 = (char)*puVar9;
        puVar9 = (uint *)((int)puVar9 + 1);
        puVar12 = (uint *)((int)puVar12 + 1);
      }
    }
    *(uint *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar1 * 0x20;
    DAT_10039078 = *(undefined1 **)(DAT_1003a024 + 0x30);
    DAT_10038b70 = 0;
    **(undefined1 **)(DAT_1003a024 + 0x30) = 8;
    *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
    *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
    if (uVar7 == 0) {
      if (*(int *)(DAT_1003a024 + 0x84) != 0) {
        *(undefined4 *)(DAT_1003a024 + 0x84) = 0;
        **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
        *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
        *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
        DAT_10038b70 = DAT_10038b70 + 1;
      }
    }
    else if (*(int *)(DAT_1003a024 + 0x84) == 0) {
      *(undefined4 *)(DAT_1003a024 + 0x84) = 1;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
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
    if (*(int *)(DAT_1003a024 + 0x8c) == 0) {
      *(undefined4 *)(DAT_1003a024 + 0x8c) = 1;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x13;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 5;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x14;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 6;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      if (*(int *)(DAT_1003a024 + 0x7c) == 0) {
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x1b;
      }
      else {
        **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
      }
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      DAT_10038b70 = DAT_10038b70 + 3;
    }
    if (*(int *)(DAT_1003a024 + 0x88) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
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
    sVar8 = (short)((uint)((int)puVar3 - iVar5) >> 5);
    *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar8;
    *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar8;
    *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar1 & 0xffff;
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
    *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar1 + -2;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
    uVar7 = 1;
    psVar11 = *(short **)(DAT_1003a024 + 0x30);
    psVar10 = psVar11;
    if (1 < uVar1 - 1) {
      do {
        *psVar10 = sVar8;
        sVar4 = (short)uVar7;
        if (uVar2 == 0) {
          psVar10[1] = sVar8 + 1 + sVar4;
          sVar4 = sVar8 + sVar4;
        }
        else {
          psVar10[1] = sVar8 + sVar4;
          sVar4 = sVar8 + sVar4 + 1;
        }
        psVar10[2] = sVar4;
        psVar11 = psVar10 + 4;
        psVar10[3] = 0x700;
        uVar7 = uVar7 + 1;
        psVar10 = psVar11;
      } while (uVar7 < uVar1 - 1);
    }
    *(short **)(DAT_1003a024 + 0x30) = psVar11;
  }
  return;
}


