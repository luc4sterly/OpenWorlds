// 00450a90 FUN_00450a90 [Global]
// programa: gamma.dll

void __cdecl FUN_00450a90(UINT param_1)

{
  if (DAT_0049f9fc == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee28);
    while (0 < DAT_0049ff60) {
      DAT_0049ff60 = DAT_0049ff60 + -1;
      (**(code **)(&DAT_0049f860 + DAT_0049ff60 * 4))();
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee28);
    FUN_00450860();
  }
  FUN_00450af0(param_1);
  return;
}


