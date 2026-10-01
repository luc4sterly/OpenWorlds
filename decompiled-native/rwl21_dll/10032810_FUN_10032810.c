// 10032810 FUN_10032810 [Global]
// program: RWL21.DLL

void FUN_10032810(int param_1,int param_2,int param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = (*(int *)(*(int *)(param_1 + 0x3c) + 0x18) >> 0x10) - param_2;
  iVar2 = (*(int *)(*(int *)(param_1 + 0x3c) + 0x1c) >> 0x10) - param_3;
  uVar4 = (uint)*(byte *)(param_1 + 0x3a);
  iVar2 = iVar2 * iVar2 + iVar3 * iVar3;
  uVar1 = 0;
  while (uVar4 = uVar4 - 1, uVar4 != 0) {
    iVar3 = *(int *)(param_1 + 0x3c + uVar4 * 4);
    iVar5 = (*(int *)(iVar3 + 0x18) >> 0x10) - param_2;
    iVar3 = (*(int *)(iVar3 + 0x1c) >> 0x10) - param_3;
    iVar3 = iVar3 * iVar3 + iVar5 * iVar5;
    if (iVar3 < iVar2) {
      iVar2 = iVar3;
      uVar1 = uVar4;
    }
  }
  *param_4 = iVar2;
  FUN_10041c70(*(int *)(*(int *)(param_1 + 0x34) + 0x88),*(int *)(param_1 + 0x3c + uVar1 * 4));
  return;
}


