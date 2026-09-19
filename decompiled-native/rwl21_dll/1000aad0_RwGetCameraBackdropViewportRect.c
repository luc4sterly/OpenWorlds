// 1000aad0 RwGetCameraBackdropViewportRect [Global]
// programa: RWL21.DLL

int RwGetCameraBackdropViewportRect
              (int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
              undefined4 *param_5)

{
                    /* 0xaad0  129  RwGetCameraBackdropViewportRect */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    param_1 = 0;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0xa4);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0xa8);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(param_1 + 0xac);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(param_1 + 0xb0);
      return param_1;
    }
  }
  return param_1;
}


