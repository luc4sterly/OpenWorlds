// 00410a50 FUN_00410a50 [Global]
// programa: gamma.dll

int * __thiscall FUN_00410a50(int *param_1,uint param_2)

{
  undefined *puVar1;
  
  if (param_1 != (int *)0x0) {
    if ((param_2 & 2) == 0) {
      *param_1 = (int)&PTR_FUN_0046f3ac;
      puVar1 = (undefined *)param_1[9];
      if (((puVar1 != &DAT_00482468) && (puVar1 != &DAT_004824bc)) && (puVar1 != &DAT_00482510)) {
        FUN_004118d0(param_1);
      }
      *param_1 = (int)&PTR_FUN_0046f370;
      FUN_00404dc0(param_1 + 7);
      if ((param_2 & 1) != 0) {
        FUN_0044e100(param_1);
      }
    }
    else {
      FUN_00451710((int)param_1,FUN_00410ad0);
    }
  }
  return param_1;
}


