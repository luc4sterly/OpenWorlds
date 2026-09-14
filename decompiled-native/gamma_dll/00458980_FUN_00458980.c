// 00458980 FUN_00458980 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00458980(int param_1)

{
  code *pcVar1;
  
  if ((param_1 < 1) || (6 < param_1)) {
    return 0xffffffff;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee88);
  pcVar1 = *(code **)(&DAT_0049eb74 + param_1 * 4);
  if (pcVar1 != (code *)0x1) {
    *(undefined4 *)(&DAT_0049eb74 + param_1 * 4) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee88);
  if ((pcVar1 != (code *)0x1) && ((pcVar1 != (code *)0x0 || (param_1 != 1)))) {
    if (pcVar1 == (code *)0x0) {
      FUN_00450a90(0);
    }
    (*pcVar1)(param_1);
    return 0;
  }
  return 0;
}


