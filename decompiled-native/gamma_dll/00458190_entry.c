// 00458190 entry [Global]
// program: gamma.dll

int entry(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if ((param_2 == 0) && (DAT_0049eb68 == 0)) {
    return 0;
  }
  if (param_2 - 1U < 2) {
    if (DAT_004a0434 != (code *)0x0) {
      iVar1 = (*DAT_004a0434)(param_1,param_2,param_3);
    }
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = FUN_00458070(param_1,param_2);
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  iVar1 = FUN_0040f580(param_1);
  if ((param_2 == 1) && (iVar1 == 0)) {
    FUN_00458070(param_1,0);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar2 = FUN_00458070(param_1,param_2);
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    if ((iVar1 != 0) && (DAT_004a0434 != (code *)0x0)) {
      iVar1 = (*DAT_004a0434)(param_1,param_2,param_3);
    }
  }
  return iVar1;
}


