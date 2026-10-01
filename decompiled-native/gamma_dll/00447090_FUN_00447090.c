// 00447090 FUN_00447090 [Global]
// program: gamma.dll

int FUN_00447090(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  int *piStack_14;
  
  iStack_24 = DAT_0047a41c;
  uStack_20 = DAT_0047a420;
  uStack_1c = DAT_0047a424;
  iVar1 = (**(code **)(**(int **)(param_1 + 0x18) + 0x18))(*(int **)(param_1 + 0x18),&piStack_14);
  piVar2 = (int *)0x0;
  if (iVar1 < 0) {
    iVar1 = -0x7fffbfff;
  }
  else {
    iVar1 = (**(code **)*piStack_14)(piStack_14,&DAT_00467098,&piStack_18);
    (**(code **)(*piStack_14 + 8))(piStack_14);
    if (iVar1 < 0) {
      iVar1 = -0x7fffbfff;
    }
    else {
      iVar1 = 0;
      piVar2 = piStack_18;
    }
  }
  if (-1 < iVar1) {
    iVar1 = FUN_00457ff0(&iStack_24,(int)piVar2);
    (**(code **)(*piVar2 + 8))(piVar2,param_2);
  }
  return iVar1;
}


