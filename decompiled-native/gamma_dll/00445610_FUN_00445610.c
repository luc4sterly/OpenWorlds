// 00445610 FUN_00445610 [Global]
// programa: gamma.dll

undefined4 FUN_00445610(int param_1,undefined4 param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x20);
  EnterCriticalSection(lpCriticalSection);
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


