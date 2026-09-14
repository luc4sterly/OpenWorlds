// 0043e960 FUN_0043e960 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_0043e960(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x24);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 4))(piVar1);
  return *(undefined4 *)(param_1 + 0x24);
}


