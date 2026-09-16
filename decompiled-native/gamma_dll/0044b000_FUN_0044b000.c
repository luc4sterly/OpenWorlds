// 0044b000 FUN_0044b000 [Global]
// programa: gamma.dll

int * __thiscall FUN_0044b000(int *param_1,uint param_2)

{
  if (param_1 != (int *)0x0) {
    if ((param_2 & 2) == 0) {
      FUN_00448650(param_1);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,FUN_00448650);
    }
  }
  return param_1;
}


