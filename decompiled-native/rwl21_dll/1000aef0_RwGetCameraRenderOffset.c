// 1000aef0 RwGetCameraRenderOffset [Global]
// programa: RWL21.DLL

int RwGetCameraRenderOffset(int param_1,undefined4 *param_2,undefined4 *param_3)

{
                    /* 0xaef0  592  RwGetCameraRenderOffset */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    param_1 = 0;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 100);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0x68);
      return param_1;
    }
  }
  return param_1;
}


