// 10019140 RwSetTextureData [Global]
// program: RWL21.DLL

int RwSetTextureData(int param_1,undefined4 param_2)

{
                    /* 0x19140  470  RwSetTextureData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x20) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


