// 100365f0 RwSetUserDrawType [Global]
// program: RWL21.DLL

int RwSetUserDrawType(int param_1,int param_2)

{
                    /* 0x365f0  484  RwSetUserDrawType */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((0 < param_2) && (param_2 < 5)) {
    *(int *)(param_1 + 0x28) = param_2;
    if (param_2 == 2) {
      *(undefined4 *)(param_1 + 0x30) = 1;
      return param_1;
    }
    *(undefined4 *)(param_1 + 0x30) = 0;
    return param_1;
  }
  FUN_1000cba0(0x33);
  return 0;
}


