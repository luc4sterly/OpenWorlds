// 1000bc40 RwSetCameraPosition [Global]
// programa: RWL21.DLL

int RwSetCameraPosition(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
                    /* 0xbc40  377  RwSetCameraPosition */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = FUN_1001cd30(param_1 + 4,param_2,param_3,param_4);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
    *(undefined1 *)(param_1 + 0xfd) = 1;
    if (param_1 != 0) {
      return param_1;
    }
  }
  return 0;
}


