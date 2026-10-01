// 100362a0 RwAddUserDrawToClump [Global]
// program: RWL21.DLL

int RwAddUserDrawToClump(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x362a0  16  RwAddUserDrawToClump */
  if ((param_1 == 0) || (param_2 == 0)) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = *(int *)(param_2 + 0x34);
  if (iVar1 != 0) {
    if (param_1 == iVar1) {
      return param_1;
    }
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0xe4);
      if (iVar2 == param_2) {
        *(undefined4 *)(iVar1 + 0xe4) = *(undefined4 *)(iVar2 + 0x38);
      }
      else {
        iVar1 = *(int *)(iVar2 + 0x38);
        while (iVar1 != 0) {
          iVar3 = *(int *)(iVar2 + 0x38);
          if (iVar3 == param_2) goto LAB_100362f6;
          iVar2 = iVar3;
          iVar1 = *(int *)(iVar3 + 0x38);
        }
        iVar3 = *(int *)(iVar2 + 0x38);
        if (iVar3 != param_2) goto LAB_10036303;
LAB_100362f6:
        *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar3 + 0x38);
      }
      *(undefined4 *)(param_2 + 0x34) = 0;
    }
  }
LAB_10036303:
  *(int *)(param_2 + 0x34) = param_1;
  *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 0xe4);
  *(int *)(param_1 + 0xe4) = param_2;
  return param_1;
}


