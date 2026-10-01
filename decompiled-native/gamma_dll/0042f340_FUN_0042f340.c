// 0042f340 FUN_0042f340 [Global]
// program: gamma.dll

void __cdecl FUN_0042f340(undefined4 *param_1)

{
  param_1[1] = param_1[1] + -1;
  if (((int)param_1[1] < 1) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(1);
  }
  return;
}


