// 10036770 RwSetUserDrawParentAlignment [Global]
// programa: RWL21.DLL

int RwSetUserDrawParentAlignment(int param_1,undefined4 param_2)

{
                    /* 0x36770  482  RwSetUserDrawParentAlignment */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((*(int *)(param_1 + 0x28) != 3) && (*(int *)(param_1 + 0x28) != 4)) {
    FUN_1000cba0(0x33);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return param_1;
}


