// 004453a0 FUN_004453a0 [Global]
// programa: gamma.dll

undefined4 FUN_004453a0(int param_1,undefined4 *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x20);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 0x18) != 0) {
    FUN_004483f0(param_2,(undefined4 *)(param_1 + 0x34));
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  FUN_00448150(param_2);
  LeaveCriticalSection(lpCriticalSection);
  return 0x80040209;
}


