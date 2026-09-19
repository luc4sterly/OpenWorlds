// 100367d0 RwRemoveUserDrawFromClump [Global]
// programa: RWL21.DLL

undefined8 __fastcall RwRemoveUserDrawFromClump(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int iVar3;
  
                    /* 0x367d0  344  RwRemoveUserDrawFromClump */
  if (param_3 == 0) {
    FUN_1000cba0(1);
    param_3 = 0;
    param_2 = extraout_EDX;
  }
  else {
    iVar2 = *(int *)(param_3 + 0x34);
    if (iVar2 != 0) {
      iVar3 = *(int *)(iVar2 + 0xe4);
      if (iVar3 == param_3) {
        uVar1 = *(undefined4 *)(iVar3 + 0x38);
        *(undefined4 *)(iVar2 + 0xe4) = uVar1;
        *(undefined4 *)(param_3 + 0x34) = 0;
        return CONCAT44(uVar1,param_3);
      }
      if (*(int *)(iVar3 + 0x38) != 0) {
        param_2 = 0;
        do {
          iVar2 = *(int *)(iVar3 + 0x38);
          if (iVar2 == param_3) goto LAB_1003681e;
          iVar3 = iVar2;
        } while (*(int *)(iVar2 + 0x38) != 0);
      }
      iVar2 = *(int *)(iVar3 + 0x38);
      if (iVar2 == param_3) {
LAB_1003681e:
        *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar2 + 0x38);
        *(undefined4 *)(param_3 + 0x34) = 0;
        return CONCAT44(param_2,param_3);
      }
    }
  }
  return CONCAT44(param_2,param_3);
}


