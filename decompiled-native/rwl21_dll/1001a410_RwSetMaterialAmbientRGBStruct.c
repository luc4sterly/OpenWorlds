// 1001a410 RwSetMaterialAmbientRGBStruct [Global]
// programa: RWL21.DLL

int RwSetMaterialAmbientRGBStruct(int param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint local_c;
  uint local_8;
  uint local_4;
  
                    /* 0x1a410  548  RwSetMaterialAmbientRGBStruct */
  local_4 = param_2[2];
  local_8 = param_2[1];
  local_c = *param_2;
  if (param_1 != 0) {
    if (0x80000000 < local_c) {
      local_c = 0;
    }
    if (0x80000000 < local_8) {
      local_8 = 0;
    }
    if (0x80000000 < local_4) {
      local_4 = 0;
    }
    uVar3 = 0x3f800000;
    if ((int)local_c < 0x3f800000) {
      uVar3 = local_c;
    }
    *(uint *)(param_1 + 0xc) = uVar3;
    uVar3 = 0x3f800000;
    if ((int)local_8 < 0x3f800000) {
      uVar3 = local_8;
    }
    *(uint *)(param_1 + 0x10) = uVar3;
    uVar3 = 0x3f800000;
    if ((int)local_4 < 0x3f800000) {
      uVar3 = local_4;
    }
    piVar1 = *(int **)(param_1 + 0x3c);
    iVar5 = 0;
    *(uint *)(param_1 + 0x14) = uVar3;
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


