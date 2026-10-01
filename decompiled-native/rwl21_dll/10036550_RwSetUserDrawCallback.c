// 10036550 RwSetUserDrawCallback [Global]
// program: RWL21.DLL

int * RwSetUserDrawCallback(int *param_1,int param_2)

{
                    /* 0x36550  479  RwSetUserDrawCallback */
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    *param_1 = param_2;
    return param_1;
  }
  FUN_1000cba0(1);
  return (int *)0x0;
}


