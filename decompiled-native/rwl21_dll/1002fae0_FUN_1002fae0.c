// 1002fae0 FUN_1002fae0 [Global]
// program: RWL21.DLL

void FUN_1002fae0(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = param_3[0x11];
  if (uVar1 == 1) {
    if (*(int *)(param_3[0x12] + 0x174) == 0) {
      param_2 = FUN_10008f30(param_3[0x12],param_2,param_1);
    }
  }
  else if (uVar1 == 2) {
    iVar2 = 0;
    iVar3 = 0;
    if (0 < (int)param_3[0x12]) {
      do {
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 1;
        param_2 = FUN_1002fae0(param_1,param_2,*(uint **)((param_3[0x13] - 4) + iVar2));
      } while (iVar3 < (int)param_3[0x12]);
    }
  }
  else if (uVar1 == 3) {
    iVar2 = FUN_1002fae0(param_1,param_2,(uint *)param_3[0x18]);
    param_2 = FUN_1002fae0(param_1,iVar2,(uint *)param_3[0x19]);
  }
  if (((*param_3 & 4) != 0) && ((uint *)param_3[4] != (uint *)0x0)) {
    FUN_1002fae0(param_1,param_2,(uint *)param_3[4]);
  }
  return;
}


