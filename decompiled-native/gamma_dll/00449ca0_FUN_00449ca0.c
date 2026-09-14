// 00449ca0 FUN_00449ca0 [Global]
// programa: gamma.dll

undefined4 FUN_00449ca0(int param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0xd0) + 0x74);
  EnterCriticalSection(lpCriticalSection_00);
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0xd0) + 0x8c);
  EnterCriticalSection(lpCriticalSection);
  FUN_00445d40(param_1);
  (**(code **)(**(int **)(param_1 + 0xd0) + 0x128))();
  LeaveCriticalSection(lpCriticalSection);
  uVar1 = (**(code **)(**(int **)(param_1 + 0xd0) + 0x108))();
  LeaveCriticalSection(lpCriticalSection_00);
  return uVar1;
}


