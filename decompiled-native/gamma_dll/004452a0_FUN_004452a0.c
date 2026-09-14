// 004452a0 FUN_004452a0 [Global]
// programa: gamma.dll

int FUN_004452a0(int *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[8];
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1[10] + 0x14) != 0) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7ffbfddc;
  }
  iVar1 = FUN_00445300(param_1);
  LeaveCriticalSection(lpCriticalSection);
  return iVar1;
}


