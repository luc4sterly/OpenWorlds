// 00449440 FUN_00449440 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_00449440(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x8c));
  piVar1 = *(int **)(param_1 + 100);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  uVar2 = *(undefined4 *)(param_1 + 100);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x8c));
  return uVar2;
}


