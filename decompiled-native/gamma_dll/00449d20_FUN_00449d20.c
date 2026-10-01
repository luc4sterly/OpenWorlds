// 00449d20 FUN_00449d20 [Global]
// program: gamma.dll

int FUN_00449d20(int param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0xd0) + 0x74);
  EnterCriticalSection(lpCriticalSection_00);
  lpCriticalSection = (LPCRITICAL_SECTION)(*(int *)(param_1 + 0xd0) + 0x8c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(**(int **)(param_1 + 0xd0) + 300))();
  if (-1 < iVar1) {
    iVar1 = FUN_00445d70(param_1);
  }
  LeaveCriticalSection(lpCriticalSection);
  LeaveCriticalSection(lpCriticalSection_00);
  return iVar1;
}


