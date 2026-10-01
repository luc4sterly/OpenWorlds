// 1002cf80 FUN_1002cf80 [Global]
// program: RWL21.DLL

int __fastcall FUN_1002cf80(undefined4 param_1,undefined4 param_2,int param_3)

{
  float *pfVar1;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 == 0) {
    param_3 = 0;
    FUN_1000cba0(1);
  }
  else if (*(int *)(param_3 + 0x20) != 0) {
    iVar3 = 0;
    FUN_1002d030(param_1,param_2,*(uint **)(param_3 + 4),0);
    iVar2 = extraout_EDX;
    if (0 < *(int *)(param_3 + 0x1c)) {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(*(int *)(*(int *)(param_3 + 0xc) + iVar4) + 0x44);
        if ((iVar2 == 1) &&
           (pfVar1 = *(float **)(*(int *)(iVar4 + *(int *)(param_3 + 0xc)) + 0x48),
           pfVar1[0x5d] == 0.0)) {
          FUN_10008eb0(0,1,pfVar1);
          iVar2 = extraout_EDX_00;
        }
        iVar4 = iVar4 + 4;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_3 + 0x1c));
    }
    iVar3 = *(int *)(param_3 + 8);
    if (iVar3 != 0) {
      do {
        if ((*(int *)(iVar3 + 0x44) == 1) && ((*(float **)(iVar3 + 0x48))[0x5d] == 0.0)) {
          FUN_10008eb0(0,iVar2,*(float **)(iVar3 + 0x48));
          iVar2 = extraout_EDX_01;
        }
        iVar3 = *(int *)(iVar3 + 0x10);
      } while (iVar3 != 0);
      return param_3;
    }
  }
  return param_3;
}


