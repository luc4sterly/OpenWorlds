// 00401940 FUN_00401940 [Global]
// programa: gdkup.exe

undefined4 FUN_00401940(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  return *(undefined4 *)(param_1 + 4);
}


