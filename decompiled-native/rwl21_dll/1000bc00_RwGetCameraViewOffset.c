// 1000bc00 RwGetCameraViewOffset [Global]
// program: RWL21.DLL

undefined4 * RwGetCameraViewOffset(int param_1,undefined4 *param_2)

{
                    /* 0xbc00  141  RwGetCameraViewOffset */
  if (param_1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(param_1 + 0x48);
      param_2[1] = *(undefined4 *)(param_1 + 0x4c);
      param_2[2] = *(undefined4 *)(param_1 + 0x50);
      return param_2;
    }
  }
  FUN_1000cba0(1);
  return (undefined4 *)0x0;
}


