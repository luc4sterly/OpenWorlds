// 004418c0 FUN_004418c0 [Global]
// programa: gamma.dll

undefined4 FUN_004418c0(int param_1,undefined4 *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  lpCriticalSection = *(LPCRITICAL_SECTION *)(param_1 + 0x28);
  EnterCriticalSection(lpCriticalSection);
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


