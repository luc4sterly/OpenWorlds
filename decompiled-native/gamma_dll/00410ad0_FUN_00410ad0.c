// 00410ad0 FUN_00410ad0 [Global]
// program: gamma.dll

int * __fastcall FUN_00410ad0(int *param_1)

{
  undefined *puVar1;
  
  *param_1 = (int)&PTR_LAB_0046f3ac;
  puVar1 = (undefined *)param_1[9];
  if (((puVar1 != &DAT_00482468) && (puVar1 != &DAT_004824bc)) && (puVar1 != &DAT_00482510)) {
    FUN_004118d0(param_1);
  }
  *param_1 = (int)&PTR_LAB_0046f370;
  FUN_00404dc0(param_1 + 7);
  return param_1;
}


