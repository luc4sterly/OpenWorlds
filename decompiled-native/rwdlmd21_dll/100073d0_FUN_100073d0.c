// 100073d0 FUN_100073d0 [Global]
// programa: rwdlmd21.dll

void FUN_100073d0(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int param_6)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar2 = 0;
  puVar3 = (undefined1 *)(*(int *)(param_1 + 0x28) * param_2 + *(int *)(param_1 + 0x18));
  if (0 < *(int *)(param_1 + 0x1c)) {
    iVar4 = param_6 + 0x80 >> 8;
    do {
      iVar1 = (*param_3 + 0x80 >> 8) * iVar4 >> 0x10;
      if (0xff < iVar1) {
        iVar1 = 0xff;
      }
      *puVar3 = (char)iVar1;
      iVar1 = (*param_4 + 0x80 >> 8) * iVar4 >> 0x10;
      if (0xff < iVar1) {
        iVar1 = 0xff;
      }
      puVar3[1] = (char)iVar1;
      iVar1 = (*param_5 + 0x80 >> 8) * iVar4 >> 0x10;
      if (0xff < iVar1) {
        iVar1 = 0xff;
      }
      puVar3[2] = (char)iVar1;
      puVar3 = puVar3 + 3;
      param_5 = param_5 + 1;
      param_4 = param_4 + 1;
      param_3 = param_3 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x1c));
  }
  return;
}


