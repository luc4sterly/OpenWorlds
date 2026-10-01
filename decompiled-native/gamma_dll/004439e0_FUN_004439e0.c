// 004439e0 FUN_004439e0 [Global]
// program: gamma.dll

int FUN_004439e0(int *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  lpCriticalSection = (LPCRITICAL_SECTION)param_1[0xd];
  EnterCriticalSection(lpCriticalSection);
  iVar4 = 0;
  if (param_1[5] != 0) {
    iVar1 = (**(code **)(*param_1 + 0xb4))();
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        piVar2 = (int *)(**(code **)(*param_1 + 0xb8))(iVar5);
        if (piVar2[6] != 0) {
          iVar3 = (**(code **)(*piVar2 + 0xcc))();
          if ((iVar3 < 0) && (-1 < iVar4)) {
            iVar4 = iVar3;
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
  }
  param_1[5] = 0;
  LeaveCriticalSection(lpCriticalSection);
  return iVar4;
}


