// 0043cd80 FUN_0043cd80 [Global]
// program: gamma.dll

undefined4 FUN_0043cd80(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if (param_2 == 0x66) {
    FUN_0043dc20(piVar1);
  }
  else if (param_2 == 0x68) {
    FUN_0043dc90(piVar1);
  }
  else if (param_2 == 0x69) {
    FUN_0043dcf0(piVar1);
  }
  else if (param_2 == 0x6a) {
    FUN_0043dc40(piVar1);
  }
  else if (param_2 != 0x6c) {
    if (param_2 == 0x70) {
      FUN_0043dce0(piVar1);
    }
    else if (param_2 == 0x71) {
      FUN_0043dc30(piVar1);
    }
  }
  return 0;
}


