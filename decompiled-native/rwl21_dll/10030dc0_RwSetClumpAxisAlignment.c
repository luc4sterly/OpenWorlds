// 10030dc0 RwSetClumpAxisAlignment [Global]
// programa: RWL21.DLL

int RwSetClumpAxisAlignment(int param_1,int param_2)

{
                    /* 0x30dc0  382  RwSetClumpAxisAlignment */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  *(undefined1 *)(param_1 + 0x12d) = 1;
  if ((0 < param_2) && (param_2 < 5)) {
    *(int *)(param_1 + 0x18c) = param_2;
    return param_1;
  }
  FUN_1000cba0(0x32);
  return 0;
}


