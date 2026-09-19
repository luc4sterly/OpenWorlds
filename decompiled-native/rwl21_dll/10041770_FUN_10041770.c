// 10041770 FUN_10041770 [Global]
// programa: RWL21.DLL

float10 FUN_10041770(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 == 0) {
    return (float10)0.0;
  }
  uVar2 = *param_1 + 0x800;
  iVar1 = DAT_1005b8c4;
  if ((uVar2 & 0x800000) != 0) {
    iVar1 = DAT_1005b8c0;
  }
  return (float10)(float)(((uVar2 & 0x7f800000) >> 1) +
                         *(int *)(iVar1 + ((uVar2 & 0x7ff000) >> 0xc) * 4));
}


