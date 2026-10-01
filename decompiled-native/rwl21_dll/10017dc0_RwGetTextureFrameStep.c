// 10017dc0 RwGetTextureFrameStep [Global]
// program: RWL21.DLL

undefined4 RwGetTextureFrameStep(int param_1)

{
                    /* 0x17dc0  257  RwGetTextureFrameStep */
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x14);
  }
  FUN_1000cba0(1);
  return 0;
}


