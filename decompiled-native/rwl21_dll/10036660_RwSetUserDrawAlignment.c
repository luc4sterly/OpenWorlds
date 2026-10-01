// 10036660 RwSetUserDrawAlignment [Global]
// program: RWL21.DLL

int RwSetUserDrawAlignment(int param_1,uint param_2)

{
                    /* 0x36660  478  RwSetUserDrawAlignment */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return 0;
  }
  if ((((param_2 & 1) == 0) || (param_2 == 0)) && (((param_2 & 8) == 0 || (param_2 == 0)))) {
    *(uint *)(param_1 + 0x2c) = param_2;
    return param_1;
  }
  FUN_1000cba0(0x34);
  return 0;
}


