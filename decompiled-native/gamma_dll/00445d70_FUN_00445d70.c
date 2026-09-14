// 00445d70 FUN_00445d70 [Global]
// programa: gamma.dll

undefined4 FUN_00445d70(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x20);
  EnterCriticalSection(lpCriticalSection);
  *(undefined1 *)(param_1 + 0x9d) = 0;
  *(undefined1 *)(param_1 + 0x24) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


