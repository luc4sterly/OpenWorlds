// 1000a4b0 RwInvalidateCameraViewport [Global]
// program: RWL21.DLL

int RwInvalidateCameraViewport(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
                    /* 0xa4b0  283  RwInvalidateCameraViewport */
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


