// 00445960 FUN_00445960 [Global]
// program: gamma.dll

undefined4 FUN_00445960(int param_1,int *param_2,undefined1 param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  
  if (param_2 == (int *)0x0) {
    return 0x80004003;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x20);
  EnterCriticalSection(lpCriticalSection);
  piVar1 = *(int **)(param_1 + 0x98);
  (**(code **)(*param_2 + 4))(param_2);
  *(int **)(param_1 + 0x98) = param_2;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined1 *)(param_1 + 0x9c) = param_3;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


