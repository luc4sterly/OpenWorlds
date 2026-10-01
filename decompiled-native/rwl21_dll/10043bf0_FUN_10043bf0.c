// 10043bf0 FUN_10043bf0 [Global]
// program: RWL21.DLL

void FUN_10043bf0(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int param_6)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  puVar1 = (undefined1 *)(*(int *)(param_1 + 0x28) * param_2 + *(int *)(param_1 + 0x18));
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar4 = param_6 + 0x80 >> 8;
    do {
      iVar2 = (*param_3 + 0x80 >> 8) * iVar4 >> 0x10;
      if (0xff < iVar2) {
        iVar2 = 0xff;
      }
      *puVar1 = (char)iVar2;
      iVar2 = (*param_4 + 0x80 >> 8) * iVar4 >> 0x10;
      if (0xff < iVar2) {
        iVar2 = 0xff;
      }
      puVar1[1] = (char)iVar2;
      iVar2 = (*param_5 + 0x80 >> 8) * iVar4 >> 0x10;
      if (0xff < iVar2) {
        iVar2 = 0xff;
      }
      puVar1[2] = (char)iVar2;
      puVar1 = puVar1 + 3;
      param_5 = param_5 + 1;
      param_4 = param_4 + 1;
      param_3 = param_3 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x1c));
  }
  return;
}


