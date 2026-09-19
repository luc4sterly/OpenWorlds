// 10060120 entry [Global]
// programa: RWDL6D21.DLL

int entry(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  if ((param_2 == 0) && (DAT_10079570 == 0)) {
    return 0;
  }
  if ((param_2 == 1) || (param_2 == 2)) {
    if (DAT_1007d424 != (code *)0x0) {
      iVar1 = (*DAT_1007d424)(param_1,param_2,param_3);
    }
    if ((iVar1 == 0) || (iVar1 = __CRT_INIT_12(param_1,param_2), iVar1 == 0)) {
      return 0;
    }
  }
  iVar1 = FUN_10004aa0(param_1,param_2);
  if ((param_2 == 1) && (iVar1 == 0)) {
    __CRT_INIT_12(param_1,0);
  }
  if ((param_2 == 0) || (param_2 == 3)) {
    iVar2 = __CRT_INIT_12(param_1,param_2);
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    if ((iVar1 != 0) && (DAT_1007d424 != (code *)0x0)) {
      iVar1 = (*DAT_1007d424)(param_1,param_2,param_3);
    }
  }
  return iVar1;
}


