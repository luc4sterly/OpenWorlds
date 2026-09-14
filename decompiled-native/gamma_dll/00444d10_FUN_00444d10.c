// 00444d10 FUN_00444d10 [Global]
// programa: gamma.dll

int FUN_00444d10(int *param_1,int *param_2,char *param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  if (param_2 == (int *)0x0) {
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
  iVar1 = FUN_00444fa0(param_1,param_2,param_3);
  if (iVar1 < 0) {
    (**(code **)(*param_1 + 0xe0))();
    LeaveCriticalSection(lpCriticalSection);
    return iVar1;
  }
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


