// 1001d7e0 RwSetMatrixElement [Global]
// program: RWL21.DLL

int RwSetMatrixElement(int param_1,int param_2,int param_3,undefined4 param_4)

{
                    /* 0x1d7e0  427  RwSetMatrixElement */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + (param_3 + param_2 * 4) * 4) = param_4;
    *(undefined1 *)(param_1 + 0x40) = 0;
    *(undefined1 *)(param_1 + 0x41) = 1;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


