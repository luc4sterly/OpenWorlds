// 1000a630 RwGetCameraData [Global]
// program: RWL21.DLL

undefined4 RwGetCameraData(int param_1)

{
                    /* 0xa630  130  RwGetCameraData */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x21c);
  }
  FUN_1000cba0(1);
  return 0;
}


