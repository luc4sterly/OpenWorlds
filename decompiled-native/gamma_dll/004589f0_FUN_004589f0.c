// 004589f0 FUN_004589f0 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_004589f0(undefined4 param_1)

{
  if (DAT_0049ff60 == 0x40) {
    return 0xffffffff;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee28);
  *(undefined4 *)(&DAT_0049f860 + DAT_0049ff60 * 4) = param_1;
  DAT_0049ff60 = DAT_0049ff60 + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee28);
  return 0;
}


