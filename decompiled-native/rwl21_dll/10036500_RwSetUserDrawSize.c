// 10036500 RwSetUserDrawSize [Global]
// programa: RWL21.DLL

int RwSetUserDrawSize(int param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x36500  483  RwSetUserDrawSize */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x10) = param_2;
    *(undefined4 *)(param_1 + 0x14) = param_3;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


