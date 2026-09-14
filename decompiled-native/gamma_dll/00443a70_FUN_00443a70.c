// 00443a70 FUN_00443a70 [Global]
// programa: gamma.dll

int FUN_00443a70(int *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[0xd];
  EnterCriticalSection(lpCriticalSection);
  if (param_1[5] == 0) {
    iVar1 = (**(code **)(*param_1 + 0xb4))();
    iVar4 = 0;
    if (0 < iVar1) {
      do {
        piVar2 = (int *)(**(code **)(*param_1 + 0xb8))(iVar4);
        if (piVar2[6] != 0) {
          iVar3 = (**(code **)(*piVar2 + 200))();
          if (iVar3 < 0) {
            LeaveCriticalSection(lpCriticalSection);
            return iVar3;
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar1);
    }
  }
  param_1[5] = 1;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


