// 00449480 FUN_00449480 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_00449480(int *param_1,int *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LPCRITICAL_SECTION lpCriticalSection_00;
  int *piVar1;
  int iVar2;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x1d);
  EnterCriticalSection(lpCriticalSection);
  param_1[0x2b] = 1;
  iVar2 = FUN_00445a30((int *)param_1[0x1c],param_2);
  if (iVar2 != 0) {
    param_1[0x2b] = 0;
    LeaveCriticalSection(lpCriticalSection);
    return 0x80004005;
  }
  piVar1 = (int *)param_1[0x1c];
  if (piVar1[0x31] != 0) {
    (**(code **)(*piVar1 + 0xd8))(piVar1[0x31]);
  }
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 0x23);
  EnterCriticalSection(lpCriticalSection_00);
  if (((param_1[0x19] == 0) && (param_1[0x1a] == 0)) && (param_1[0x16] == 0)) {
    if ((void *)param_1[0x12] != (void *)0x0) {
      FUN_00447b00((void *)param_1[0x12],param_2);
    }
    if (param_1[0x17] == 1) {
      iVar2 = (**(code **)(*param_1 + 0xf8))(param_2);
      if (iVar2 == 0) {
        param_1[0x2b] = 0;
        LeaveCriticalSection(lpCriticalSection_00);
        LeaveCriticalSection(lpCriticalSection);
        return 0x8004022b;
      }
    }
    iVar2 = *(int *)(param_1[0x1c] + 0xbc);
    param_1[0x2c] = *(int *)(param_1[0x1c] + 0xb8);
    param_1[0x2d] = iVar2;
    param_1[0x19] = (int)param_2;
    (**(code **)(*(int *)param_1[0x19] + 4))((int *)param_1[0x19]);
    if (param_1[0x17] == 0) {
      FUN_00449b50(param_1,1);
    }
    LeaveCriticalSection(lpCriticalSection_00);
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  SetEvent((HANDLE)param_1[0x15]);
  param_1[0x2b] = 0;
  LeaveCriticalSection(lpCriticalSection_00);
  LeaveCriticalSection(lpCriticalSection);
  return 0x8000ffff;
}


