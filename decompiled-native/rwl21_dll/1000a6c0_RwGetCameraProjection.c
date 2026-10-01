// 1000a6c0 RwGetCameraProjection [Global]
// program: RWL21.DLL

undefined4 RwGetCameraProjection(int param_1)

{
                    /* 0xa6c0  139  RwGetCameraProjection */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x218);
  }
  FUN_1000cba0(1);
  return 0;
}


