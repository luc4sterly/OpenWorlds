// 004478b0 FUN_004478b0 [Global]
// programa: gamma.dll

int FUN_004478b0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *local_18;
  int *local_14;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x18))(*(int **)(param_1 + 0x18),&local_14);
  piVar2 = (int *)0x0;
  if (iVar1 < 0) {
    iVar1 = -0x7fffbfff;
  }
  else {
    iVar1 = (**(code **)*local_14)(local_14,&DAT_00467178,&local_18);
    (**(code **)(*local_14 + 8))(local_14);
    if (iVar1 < 0) {
      iVar1 = -0x7fffbfff;
    }
    else {
      iVar1 = 0;
      piVar2 = local_18;
    }
  }
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = (**(code **)(*piVar2 + 0x40))(piVar2,param_2);
  (**(code **)(*piVar2 + 8))(piVar2);
  return iVar1;
}


