// 1001a5e0 RwSetMaterialDiffuseRGB [Global]
// program: RWL21.DLL

int RwSetMaterialDiffuseRGB(int param_1,uint param_2,uint param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  
                    /* 0x1a5e0  549  RwSetMaterialDiffuseRGB */
  if (param_1 != 0) {
    if (0x80000000 < param_2) {
      param_2 = 0;
    }
    if (0x80000000 < param_3) {
      param_3 = 0;
    }
    if (0x80000000 < param_4) {
      param_4 = 0;
    }
    uVar3 = 0x3f800000;
    if ((int)param_2 < 0x3f800000) {
      uVar3 = param_2;
    }
    *(uint *)(param_1 + 0x18) = uVar3;
    uVar3 = 0x3f800000;
    if ((int)param_3 < 0x3f800000) {
      uVar3 = param_3;
    }
    *(uint *)(param_1 + 0x1c) = uVar3;
    uVar3 = 0x3f800000;
    if ((int)param_4 < 0x3f800000) {
      uVar3 = param_4;
    }
    piVar1 = *(int **)(param_1 + 0x3c);
    iVar5 = 0;
    *(uint *)(param_1 + 0x20) = uVar3;
    if (0 < *piVar1) {
      piVar4 = piVar1 + 2;
      do {
        iVar2 = *piVar4;
        if (*(int *)(iVar2 + 0x2c) == iVar2) {
          FUN_1001a2f0(iVar2);
        }
        piVar4 = piVar4 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < *piVar1);
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


