// 1001b050 FUN_1001b050 [Global]
// programa: RWL21.DLL

void FUN_1001b050(int param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  *(undefined4 *)(param_1 + 0xd8) = 0;
  piVar1 = *(int **)(param_1 + 0x98);
  *(undefined4 *)(param_1 + 0xdc) = 1;
  iVar5 = *piVar1;
  if (iVar5 == 0) {
    *(undefined4 *)(param_1 + 0xe0) = 0;
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(undefined4 *)(param_1 + 0xdc) = 1;
    return;
  }
  if (*(uint **)piVar1[2] == (uint *)0x0) {
    uVar7 = 0;
    FUN_1000cba0(1);
  }
  else {
    uVar7 = 2 - ((**(uint **)piVar1[2] & 1) == 0);
  }
  piVar6 = piVar1 + 3;
  iVar5 = iVar5 + -1;
  iVar2 = **(int **)piVar1[2];
  if (0 < iVar5) {
    do {
      piVar1 = (int *)*piVar6;
      piVar6 = piVar6 + 1;
      if (*(int *)*piVar1 != iVar2) {
        *(undefined4 *)(param_1 + 0xdc) = 0;
        puVar3 = (uint *)*piVar1;
        if (puVar3 == (uint *)0x0) {
          FUN_1000cba0(1);
          uVar4 = 0;
        }
        else {
          uVar4 = 2 - ((*puVar3 & 1) == 0);
        }
        uVar7 = uVar7 | uVar4;
      }
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (*(int *)(param_1 + 0xdc) != 0) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x98) + 8);
    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)*piVar1;
    puVar3 = (uint *)*piVar1;
    if (puVar3 == (uint *)0x0) {
      iVar5 = 1;
    }
    else {
      uVar4 = *puVar3;
      if (uVar4 < 0x40) {
        if (uVar4 < 4) {
          *(uint *)(param_1 + 0x8c) = uVar7;
          *(undefined4 *)(param_1 + 0x90) = 1;
          return;
        }
        if (uVar4 < 8) {
          *(uint *)(param_1 + 0x8c) = uVar7;
          *(undefined4 *)(param_1 + 0x90) = 2;
          return;
        }
        if (uVar4 < 0xc) {
          *(uint *)(param_1 + 0x8c) = uVar7;
          *(undefined4 *)(param_1 + 0x90) = 3;
          return;
        }
        *(uint *)(param_1 + 0x8c) = uVar7;
        *(undefined4 *)(param_1 + 0x90) = 4;
        return;
      }
      iVar5 = 0x67;
    }
    FUN_1000cba0(iVar5);
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  *(uint *)(param_1 + 0x8c) = uVar7;
  return;
}


