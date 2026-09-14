// 004458c0 FUN_004458c0 [Global]
// programa: gamma.dll

HRESULT FUN_004458c0(int param_1,undefined4 *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  HRESULT HVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return -0x7fffbffd;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x20);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 0x98) == 0) {
    HVar1 = CoCreateInstance((IID *)&DAT_00477fec,(LPUNKNOWN)0x0,1,(IID *)&DAT_004670c8,
                             (LPVOID *)(param_1 + 0x98));
    if (HVar1 < 0) {
      LeaveCriticalSection(lpCriticalSection);
      return HVar1;
    }
  }
  *param_2 = *(undefined4 *)(param_1 + 0x98);
  (**(code **)(**(int **)(param_1 + 0x98) + 4))(*(int **)(param_1 + 0x98));
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


