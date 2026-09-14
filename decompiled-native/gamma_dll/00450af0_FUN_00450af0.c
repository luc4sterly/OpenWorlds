// 00450af0 FUN_00450af0 [Global]
// programa: gamma.dll

void __cdecl FUN_00450af0(UINT param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee28);
  while (0 < DAT_0049e420) {
    DAT_0049e420 = DAT_0049e420 + -1;
    (**(code **)(&DAT_0049e424 + DAT_0049e420 * 4))();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee28);
  FUN_004587c0();
  if (DAT_0049ff50 != (code *)0x0) {
    (*DAT_0049ff50)();
    DAT_0049ff50 = (code *)0x0;
  }
                    /* WARNING: Subroutine does not return */
  ExitProcess(param_1);
}


