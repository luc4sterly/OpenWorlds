// 00443b10 FUN_00443b10 [Global]
// programa: gamma.dll

int FUN_00443b10(int *param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[0xd];
  EnterCriticalSection(lpCriticalSection);
  param_1[7] = param_2;
  param_1[8] = param_3;
  if ((param_1[5] == 0) && (iVar1 = (**(code **)(*param_1 + 0x90))(param_1), iVar1 < 0)) {
    LeaveCriticalSection(lpCriticalSection);
    return iVar1;
  }
  if (param_1[5] != 2) {
    iVar1 = (**(code **)(*param_1 + 0xb4))();
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        piVar2 = (int *)(**(code **)(*param_1 + 0xb8))(iVar4);
        if ((piVar2[6] != 0) && (iVar3 = (**(code **)(*piVar2 + 0xd0))(param_2,param_3), iVar3 < 0))
        {
          LeaveCriticalSection(lpCriticalSection);
          return iVar3;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  param_1[5] = 2;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


