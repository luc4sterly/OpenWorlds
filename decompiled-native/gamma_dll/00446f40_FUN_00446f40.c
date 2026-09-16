// 00446f40 FUN_00446f40 [Global]
// programa: gamma.dll

int FUN_00446f40(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int *piStack_18;
  int *piStack_14;
  
  iVar1 = (**(code **)(*param_1 + 0xc0))(param_2,0);
  if (iVar1 < 0) {
    iStack_24 = DAT_0047a404;
    uStack_20 = DAT_0047a408;
    uStack_1c = DAT_0047a40c;
    iVar1 = (**(code **)(*(int *)param_1[6] + 0x18))((int *)param_1[6],&piStack_14);
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
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


