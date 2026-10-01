// 004475c0 FUN_004475c0 [Global]
// program: gamma.dll

int FUN_004475c0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piStack_18;
  int *piStack_14;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x18))(*(int **)(param_1 + 0x18),&piStack_14);
  piVar2 = (int *)0x0;
  if (iVar1 < 0) {
    iVar1 = -0x7fffbfff;
  }
  else {
    iVar1 = (**(code **)*piStack_14)(piStack_14,&DAT_00467178,&piStack_18);
    (**(code **)(*piStack_14 + 8))(piStack_14);
    if (iVar1 < 0) {
      iVar1 = -0x7fffbfff;
    }
    else {
      iVar1 = 0;
      piVar2 = piStack_18;
    }
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = (**(code **)(*piVar2 + 0x2c))(piVar2,param_2,param_3);
  (**(code **)(*piVar2 + 8))(piVar2);
  return iVar1;
}


