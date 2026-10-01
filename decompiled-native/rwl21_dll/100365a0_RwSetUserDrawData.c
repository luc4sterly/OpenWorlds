// 100365a0 RwSetUserDrawData [Global]
// program: RWL21.DLL

int RwSetUserDrawData(int param_1,undefined4 param_2)

{
                    /* 0x365a0  480  RwSetUserDrawData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 4) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


