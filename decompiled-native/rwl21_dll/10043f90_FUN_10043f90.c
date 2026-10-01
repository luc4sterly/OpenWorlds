// 10043f90 FUN_10043f90 [Global]
// program: RWL21.DLL

undefined4 FUN_10043f90(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    DAT_1005b8f8 = DAT_1005b8f8 + -1;
    return 1;
  }
  if (param_2 != 1) {
    return 1;
  }
  if (DAT_1005b8f8 != 0) {
    return 0;
  }
  DAT_1005b8f8 = 1;
  return 1;
}


