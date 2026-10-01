// 10007570 FUN_10007570 [Global]
// program: rwdlmd21.dll

uint FUN_10007570(byte param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)param_1;
  if (param_2 == 1) {
    iVar2 = (int)(uVar1 & 0xffffffe7) >> 3;
    *(uint *)(&DAT_10087210 + iVar2) = *(uint *)(&DAT_10087210 + iVar2) & ~(1 << (param_1 & 0x1f));
    return uVar1;
  }
  if (param_2 != 2) {
    return 0xffffffff;
  }
  iVar2 = (int)(uVar1 & 0xffffffe7) >> 3;
  *(uint *)(&DAT_10087210 + iVar2) = *(uint *)(&DAT_10087210 + iVar2) | 1 << (param_1 & 0x1f);
  return uVar1;
}


