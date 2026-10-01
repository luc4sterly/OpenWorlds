// 1000a980 RwGetCameraBackdrop [Global]
// program: RWL21.DLL

undefined4 RwGetCameraBackdrop(int param_1)

{
                    /* 0xa980  126  RwGetCameraBackdrop */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0xa0);
  }
  FUN_1000cba0(1);
  return 0;
}


