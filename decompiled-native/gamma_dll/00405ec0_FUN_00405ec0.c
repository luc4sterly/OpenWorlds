// 00405ec0 FUN_00405ec0 [Global]
// programa: gamma.dll

int __fastcall FUN_00405ec0(int *param_1)

{
  if (*param_1 == 0) {
    DAT_0049fcf4 = DAT_0049fcf4 + 1;
    *param_1 = DAT_0049fcf4;
  }
  return *param_1;
}


