// 00445110 FUN_00445110 [Global]
// programa: gamma.dll

int FUN_00445110(int *param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  if (param_2 == 0) {
    return -0x7fffbffd;
  }
  if (param_3 == 0) {
    return -0x7fffbffd;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[8];
  EnterCriticalSection(lpCriticalSection);
  if (param_1[6] != 0) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7ffbfdfc;
  }
  if ((*(int *)(param_1[10] + 0x14) != 0) && (*(char *)((int)param_1 + 0x25) == '\0')) {
    LeaveCriticalSection(lpCriticalSection);
    return -0x7ffbfddc;
  }
  iVar1 = (**(code **)(*param_1 + 0xdc))(param_2);
  if (iVar1 < 0) {
    (**(code **)(*param_1 + 0xe0))();
    LeaveCriticalSection(lpCriticalSection);
    return iVar1;
  }
  iVar1 = (**(code **)(*param_1 + 0xd4))(param_3);
  if (iVar1 != 0) {
    (**(code **)(*param_1 + 0xe0))();
    if (((-1 < iVar1) || (iVar1 == -0x7fffbffb)) || (iVar1 == -0x7ff8ffa9)) {
      iVar1 = -0x7ffbfdd6;
    }
    LeaveCriticalSection(lpCriticalSection);
    return iVar1;
  }
  param_1[6] = param_2;
  (**(code **)(*(int *)param_1[6] + 4))((int *)param_1[6]);
  (**(code **)(*param_1 + 0xd8))(param_3);
  iVar1 = (**(code **)(*param_1 + 0xe4))(param_2);
  if (iVar1 < 0) {
    (**(code **)(*(int *)param_1[6] + 8))((int *)param_1[6]);
    param_1[6] = 0;
    (**(code **)(*param_1 + 0xe0))();
    LeaveCriticalSection(lpCriticalSection);
    return iVar1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


