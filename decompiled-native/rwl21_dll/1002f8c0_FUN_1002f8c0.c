// 1002f8c0 FUN_1002f8c0 [Global]
// programa: RWL21.DLL

void FUN_1002f8c0(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = param_3[0x11];
  if (uVar1 == 1) {
    if (param_1 == 0) {
      param_2 = param_2 + 1;
    }
    else {
      param_2 = param_2 + 1;
      *(uint *)(param_1 + -4 + param_2 * 4) = param_3[0x12];
    }
  }
  else if (uVar1 == 2) {
    iVar3 = 0;
    iVar2 = 0;
    if (0 < (int)param_3[0x12]) {
      do {
        iVar3 = iVar3 + 4;
        iVar2 = iVar2 + 1;
        param_2 = FUN_1002f8c0(param_1,param_2,*(uint **)((param_3[0x13] - 4) + iVar3));
      } while (iVar2 < (int)param_3[0x12]);
    }
  }
  else if (uVar1 == 3) {
    iVar2 = FUN_1002f8c0(param_1,param_2,(uint *)param_3[0x18]);
    param_2 = FUN_1002f8c0(param_1,iVar2,(uint *)param_3[0x19]);
  }
  if (((*param_3 & 4) != 0) && ((uint *)param_3[4] != (uint *)0x0)) {
    FUN_1002f8c0(param_1,param_2,(uint *)param_3[4]);
  }
  return;
}


