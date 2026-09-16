// 004415a0 FUN_004415a0 [Global]
// programa: gamma.dll

void __fastcall FUN_004415a0(int param_1)

{
  int *piVar1;
  bool bVar2;
  
  bVar2 = true;
  if ((*(int *)(param_1 + 8) != 3) && (*(int *)(param_1 + 8) != 1)) {
    bVar2 = false;
  }
  if ((bVar2) && (piVar1 = *(int **)(param_1 + 0x10), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x20))(piVar1);
    *(undefined4 *)(param_1 + 8) = 2;
  }
  return;
}


