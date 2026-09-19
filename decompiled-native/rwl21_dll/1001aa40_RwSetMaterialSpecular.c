// 1001aa40 RwSetMaterialSpecular [Global]
// programa: RWL21.DLL

int RwSetMaterialSpecular(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  uint local_8;
  uint local_4;
  
                    /* 0x1aa40  423  RwSetMaterialSpecular */
  local_4 = param_2;
  local_8 = param_2;
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((0x80000000 < param_2) && (local_8 = 0, 0x80000000 < param_2)) {
    local_4 = 0;
  }
  uVar3 = 0x3f800000;
  if ((int)local_8 < 0x3f800000) {
    uVar3 = local_8;
  }
  *(uint *)(param_1 + 0x24) = uVar3;
  uVar3 = 0x3f800000;
  if ((int)local_8 < 0x3f800000) {
    uVar3 = local_8;
  }
  *(uint *)(param_1 + 0x28) = uVar3;
  uVar3 = 0x3f800000;
  if ((int)local_4 < 0x3f800000) {
    uVar3 = local_4;
  }
  piVar1 = *(int **)(param_1 + 0x3c);
  iVar4 = 0;
  *(uint *)(param_1 + 0x2c) = uVar3;
  if (0 < *piVar1) {
    piVar5 = piVar1 + 2;
    do {
      iVar2 = *piVar5;
      if (*(int *)(iVar2 + 0x2c) == iVar2) {
        FUN_1001a2f0(iVar2);
      }
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *piVar1);
  }
  return param_1;
}


