// 10008f30 FUN_10008f30 [Global]
// programa: RWL21.DLL

int FUN_10008f30(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x178);
  if (iVar1 != 0) {
    do {
      param_2 = FUN_10008f30(iVar1,param_2,param_3);
      iVar1 = *(int *)(iVar1 + 0x184);
    } while (iVar1 != 0);
    *(int *)(param_3 + param_2 * 4) = param_1;
    return param_2 + 1;
  }
  *(int *)(param_3 + param_2 * 4) = param_1;
  return param_2 + 1;
}


