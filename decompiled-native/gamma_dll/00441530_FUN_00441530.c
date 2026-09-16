// 00441530 FUN_00441530 [Global]
// programa: gamma.dll

void __thiscall FUN_00441530(int param_1,undefined4 param_2)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  
  bVar2 = true;
  if ((*(int *)(param_1 + 8) != 1) && (*(int *)(param_1 + 8) != 2)) {
    bVar2 = false;
  }
  if ((bVar2) && (piVar1 = *(int **)(param_1 + 0x10), piVar1 != (int *)0x0)) {
    iVar3 = (**(code **)(*piVar1 + 0x1c))(piVar1);
    if (iVar3 < 0) {
      FUN_0044d5a0(s_Could_not_run_the_DirectShow_gra_00478540);
      FUN_0044d5a0(&DAT_004780c8);
      return;
    }
    *(undefined4 *)(param_1 + 8) = 3;
    *(undefined4 *)(param_1 + 4) = param_2;
  }
  return;
}


