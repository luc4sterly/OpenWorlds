// 0043e450 FUN_0043e450 [Global]
// programa: gamma.dll

undefined4 FUN_0043e450(int param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    return 0x80070057;
  }
  if (param_1 != 0) {
    param_1 = param_1 + 0x14;
  }
  *param_2 = param_1;
  (**(code **)(*(int *)*param_2 + 4))((int *)*param_2);
  return 0;
}


