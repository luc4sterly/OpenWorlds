// 10002d20 RwSetClumpData [Global]
// program: RWL21.DLL

int RwSetClumpData(int param_1,undefined4 param_2)

{
                    /* 0x2d20  383  RwSetClumpData */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0xb0) = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


