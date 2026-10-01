// 10036490 RwSetUserDrawOffset [Global]
// program: RWL21.DLL

int RwSetUserDrawOffset(int param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x36490  481  RwSetUserDrawOffset */
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 8) = param_2;
    *(undefined4 *)(param_1 + 0xc) = param_3;
    return param_1;
  }
  FUN_1000cba0(1);
  return 0;
}


