// 00445d40 FUN_00445d40 [Global]
// programa: gamma.dll

undefined4 FUN_00445d40(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x20);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x9d) = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


