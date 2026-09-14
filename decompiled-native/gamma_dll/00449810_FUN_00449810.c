// 00449810 FUN_00449810 [Global]
// programa: gamma.dll

void __fastcall FUN_00449810(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x23));
  if (param_1[0x2e] != 0) {
    param_1[0x2e] = 0;
    (**(code **)(*param_1 + 0x104))();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x23));
  return;
}


