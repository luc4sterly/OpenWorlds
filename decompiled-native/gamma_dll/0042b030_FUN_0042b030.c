// 0042b030 FUN_0042b030 [Global]
// program: gamma.dll

int * __thiscall FUN_0042b030(int *param_1,uint param_2)

{
  if (param_1 != (int *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = (int)&PTR_FUN_004744c4;
      FUN_0044e100((undefined4 *)param_1[0x13]);
      (**(code **)(*param_1 + 0xc))(param_1[10]);
      *param_1 = (int)&PTR_LAB_004744f4;
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,FUN_0042a960);
    }
  }
  return param_1;
}


