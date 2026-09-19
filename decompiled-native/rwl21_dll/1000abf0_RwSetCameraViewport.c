// 1000abf0 RwSetCameraViewport [Global]
// programa: RWL21.DLL

int RwSetCameraViewport(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  
                    /* 0xabf0  380  RwSetCameraViewport */
  if (param_1 != 0) {
    if (param_4 < 0) {
      param_4 = 0;
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x1c);
      if (iVar1 < param_4) {
        param_4 = iVar1;
      }
    }
    if (param_5 < 0) {
      param_5 = 0;
    }
    else {
      iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x20);
      if (iVar1 < param_5) {
        param_5 = iVar1;
      }
    }
    if ((*(uint *)(param_1 + 0x228) & 1) == 0) {
      iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x1c);
      if (iVar1 < *(int *)(param_1 + 100) + param_4) {
        param_4 = iVar1 - *(int *)(param_1 + 100);
      }
      iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x20);
      if (iVar1 < *(int *)(param_1 + 0x68) + param_5) {
        param_5 = iVar1 - *(int *)(param_1 + 0x68);
      }
    }
    else {
      if (param_2 < 0) {
        param_2 = 0;
      }
      else {
        iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x1c);
        if (iVar1 <= param_2) {
          param_2 = iVar1 + -1;
        }
      }
      if (param_3 < 0) {
        param_3 = 0;
      }
      else {
        iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x20);
        if (iVar1 <= param_3) {
          param_3 = iVar1 + -1;
        }
      }
      iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x1c);
      if (iVar1 < param_2 + param_4) {
        param_4 = iVar1 - param_2;
      }
      if (param_4 < 0) {
        param_4 = 0;
      }
      iVar1 = *(int *)(*(int *)(param_1 + 0x100) + 0x20);
      if (iVar1 < param_3 + param_5) {
        param_5 = iVar1 - param_3;
      }
      if (param_5 < 0) {
        param_5 = 0;
      }
    }
    *(int *)(param_1 + 0x54) = param_2;
    *(int *)(param_1 + 0x58) = param_3;
    *(int *)(param_1 + 0x5c) = param_4;
    *(int *)(param_1 + 0x60) = param_5;
    lVar3 = __ftol();
    *(float *)(param_1 + 0x6c) = (float)(int)lVar3;
    lVar3 = __ftol();
    *(float *)(param_1 + 0x70) = (float)(int)lVar3;
    if (param_5 <= param_4) {
      param_5 = param_4;
    }
    *(undefined4 *)(param_1 + 0x114) = 0;
    for (; 0x400 < param_5; param_5 = param_5 >> 1) {
      *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
    }
    *(undefined1 *)(param_1 + 0xfd) = 1;
    *(int *)(param_1 + 0x224) = *(int *)(param_1 + 0x224) + 1;
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
  }
  FUN_1000cba0(1);
  return param_1;
}


