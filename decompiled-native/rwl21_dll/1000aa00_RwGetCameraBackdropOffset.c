// 1000aa00 RwGetCameraBackdropOffset [Global]
// program: RWL21.DLL

int RwGetCameraBackdropOffset(int param_1,undefined4 *param_2,undefined4 *param_3)

{
                    /* 0xaa00  127  RwGetCameraBackdropOffset */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    param_1 = 0;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0xb4);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_1 + 0xb8);
      return param_1;
    }
  }
  return param_1;
}


