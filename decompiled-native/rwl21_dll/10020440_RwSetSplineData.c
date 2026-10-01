// 10020440 RwSetSplineData [Global]
// program: RWL21.DLL

int RwSetSplineData(int param_1,undefined4 param_2)

{
                    /* 0x20440  451  RwSetSplineData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 8) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


