// 00449bf0 FUN_00449bf0 [Global]
// program: gamma.dll

int FUN_00449bf0(int *param_1)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1[0x34] + 0x74);
  EnterCriticalSection(lpCriticalSection_00);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1[0x34] + 0x8c);
  EnterCriticalSection(lpCriticalSection);
  iVar1 = (**(code **)(*param_1 + 0x138))();
  if (iVar1 != 0) {
    LeaveCriticalSection(lpCriticalSection);
    LeaveCriticalSection(lpCriticalSection_00);
    return iVar1;
  }
  iVar1 = (**(code **)(*(int *)param_1[0x34] + 0x10c))();
  if (-1 < iVar1) {
    iVar1 = FUN_00445600();
  }
  LeaveCriticalSection(lpCriticalSection);
  LeaveCriticalSection(lpCriticalSection_00);
  return iVar1;
}


