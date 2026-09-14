// 00449ae0 FUN_00449ae0 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_00449ae0(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x23));
  param_1[0x1b] = 0;
  if (param_1[0x17] == 1) {
    param_1[0x17] = 0;
    (**(code **)(*param_1 + 0xe8))();
    timeEndPeriod(1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x23));
  return 0;
}


