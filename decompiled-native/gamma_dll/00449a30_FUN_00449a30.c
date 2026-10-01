// 00449a30 FUN_00449a30 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00449a30(int *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  int iVar2;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x23);
  EnterCriticalSection(lpCriticalSection);
  if (param_1[0x17] == 1) {
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  param_1[0x17] = 1;
  timeBeginPeriod(1);
  (**(code **)(*param_1 + 0xe4))();
  if (param_1[0x19] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x104))();
    LeaveCriticalSection(lpCriticalSection);
    return uVar1;
  }
  iVar2 = (**(code **)(*param_1 + 0xf8))(param_1[0x19]);
  if (iVar2 == 0) {
    SetEvent((HANDLE)param_1[0x13]);
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


