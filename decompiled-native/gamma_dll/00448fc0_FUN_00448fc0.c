// 00448fc0 FUN_00448fc0 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_00448fc0(int *param_1)

{
  if (param_1[5] == 0) {
    return 0;
  }
  param_1[0x1a] = 1;
  if (param_1[0x19] != 0) {
    return 0;
  }
  SetEvent((HANDLE)param_1[0x15]);
  if (param_1[0x17] != 0) {
    (**(code **)(*param_1 + 0x104))();
  }
  return 0;
}


