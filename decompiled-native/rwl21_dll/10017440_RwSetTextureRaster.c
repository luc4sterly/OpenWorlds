// 10017440 RwSetTextureRaster [Global]
// programa: RWL21.DLL

int RwSetTextureRaster(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x17440  477  RwSetTextureRaster */
  if ((param_1 == 0) || (param_2 == 0)) {
    FUN_1000cba0(1);
    return 0;
  }
  if (*(int *)(param_2 + 0x3c) != 0) {
    if (*(int *)(param_2 + 0x3c) == param_1) {
      return param_1;
    }
    FUN_1000cba0(0x43);
    return 0;
  }
  iVar1 = *(int *)(param_2 + 0x1c);
  if ((*(int *)(PTR_DAT_1005b69c + 0x20) != iVar1) && (*(int *)(PTR_DAT_1005b69c + 700) != iVar1)) {
    FUN_1000cba0(0x16);
    return 0;
  }
  iVar3 = *(int *)(param_2 + 0x20) / iVar1;
  if (iVar3 < 1) {
    FUN_1000cba0(0x17);
    return 0;
  }
  iVar2 = *(int *)(param_1 + 0x1c);
  if ((iVar2 != 0) && (*(int *)(param_1 + 0xc) != iVar3)) {
    FUN_1000cba0(0x17);
    return 0;
  }
  if (*(int *)(PTR_DAT_1005b69c + 0x14) != *(int *)(param_2 + 0x24)) {
    FUN_1000cba0(0x18);
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x18);
  if (iVar3 == 0) {
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x1c) * 2 != iVar1)) {
      FUN_1000cba0(0x16);
      return 0;
    }
  }
  else {
    if (*(int *)(iVar3 + 0x1c) != iVar1) {
      FUN_1000cba0(0x16);
      return 0;
    }
    *(undefined4 *)(iVar3 + 0x3c) = 0;
    RwDestroyRaster(*(undefined4 **)(param_1 + 0x18));
  }
  *(int *)(param_2 + 0x3c) = param_1;
  *(int *)(param_1 + 0x18) = param_2;
  iVar1 = *(int *)(param_2 + 0x20);
  iVar3 = *(int *)(param_2 + 0x1c);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(int *)(param_1 + 0xc) = iVar1 / iVar3;
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 0x18);
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x18);
  }
  *(uint *)(param_2 + 0x40) = *(uint *)(param_2 + 0x40) | 1;
  return param_1;
}


