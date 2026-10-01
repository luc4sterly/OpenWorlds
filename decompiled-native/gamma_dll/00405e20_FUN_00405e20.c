// 00405e20 FUN_00405e20 [Global]
// program: gamma.dll

int __fastcall FUN_00405e20(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  if (*(int *)(param_1 + 4) != 0) {
    param_1 = 0;
  }
  return param_1;
}


