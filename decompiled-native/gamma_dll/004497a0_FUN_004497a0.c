// 004497a0 FUN_004497a0 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_004497a0(int param_1)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x8c));
  piVar1 = *(int **)(param_1 + 100);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 100) = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x8c));
  return 0;
}


