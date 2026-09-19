// 100035a0 FUN_100035a0 [Global]
// programa: RWL21.DLL

int FUN_100035a0(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  uVar1 = *(uint *)(param_1 + 0x34);
  if (uVar1 != 0) {
    if (*(uint *)(uVar1 + 0xb8) != uVar1) {
      if ((*(int *)(param_1 + 0x2c) == param_1) && (*(int *)(param_1 + 0x30) != 0)) {
        FUN_10020cf0(*(int **)(uVar1 + 0x9c),param_1);
      }
      FUN_10020d30(*(int **)(uVar1 + 0x98),param_1);
      FUN_100329b0(uVar1);
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      FUN_100035a0(*(int *)(param_1 + 0x30));
      RwDestroyPolygon(*(int **)(param_1 + 0x30));
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    if (*(int *)(param_1 + 0x2c) == param_1) {
      if ((*(uint *)(uVar1 + 0xb8) != uVar1) && (iVar4 = 0, *(char *)(param_1 + 0x3a) != '\0')) {
        piVar3 = (int *)(param_1 + 0x3c);
        do {
          iVar2 = *piVar3;
          piVar3 = piVar3 + 1;
          iVar4 = iVar4 + 1;
          FUN_10042180(iVar2,param_1);
        } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x3a));
      }
      *(int *)(uVar1 + 0x94) = *(int *)(uVar1 + 0x94) + -1;
    }
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return param_1;
}


