// 00454630 FUN_00454630 [Global]
// programa: gamma.dll

void __cdecl FUN_00454630(int *param_1)

{
  if (DAT_0049e768 == (int *)0x0) {
    DAT_0049e768 = param_1;
    *param_1 = (int)param_1;
    param_1[1] = (int)param_1;
  }
  else {
    *param_1 = *DAT_0049e768;
    *(int **)(*param_1 + 4) = param_1;
    param_1[1] = (int)DAT_0049e768;
    *DAT_0049e768 = (int)param_1;
    DAT_0049e768 = param_1;
  }
  return;
}


