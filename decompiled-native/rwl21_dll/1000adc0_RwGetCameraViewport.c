// 1000adc0 RwGetCameraViewport [Global]
// programa: RWL21.DLL

int RwGetCameraViewport(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                       undefined4 *param_5)

{
                    /* 0xadc0  142  RwGetCameraViewport */
  if (param_1 == 0) {
    FUN_1000cba0(1);
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x54);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0x58);
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = *(undefined4 *)(param_1 + 0x5c);
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = *(undefined4 *)(param_1 + 0x60);
      return param_1;
    }
  }
  return param_1;
}


