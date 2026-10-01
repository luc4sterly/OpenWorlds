// 1000ae20 RwSetCameraRenderOffset [Global]
// program: RWL21.DLL

int RwSetCameraRenderOffset(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0xae20  591  RwSetCameraRenderOffset */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x1c);
  if (iVar1 < *(int *)(param_1 + 0x54) + param_2) {
    *(int *)(param_1 + 0x54) = iVar1 - param_2;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x20);
  if (iVar1 < *(int *)(param_1 + 0x58) + param_3) {
    *(int *)(param_1 + 0x58) = iVar1 - param_3;
  }
  *(int *)(param_1 + 100) = param_2;
  *(int *)(param_1 + 0x68) = param_3;
  *(uint *)(param_1 + 0x228) = *(uint *)(param_1 + 0x228) | 2;
  if (param_1 != 0) {
    puVar2 = (undefined4 *)(param_1 + 0x118);
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    if ((*(uint *)(param_1 + 0x228) & 1) != 0) {
      puVar2 = (undefined4 *)(param_1 + 0x198);
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
      }
    }
    RwDamageCameraViewport(param_1,0,0,*(int *)(param_1 + 0x5c),*(int *)(param_1 + 0x60));
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


