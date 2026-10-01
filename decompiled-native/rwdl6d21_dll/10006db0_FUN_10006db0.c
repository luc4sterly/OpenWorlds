// 10006db0 FUN_10006db0 [Global]
// program: RWDL6D21.DLL

uint FUN_10006db0(byte param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)param_1;
  if (param_2 == 1) {
    iVar2 = (int)(uVar1 & 0xffffffe7) >> 3;
    *(uint *)(&DAT_100791e8 + iVar2) = *(uint *)(&DAT_100791e8 + iVar2) & ~(1 << (param_1 & 0x1f));
    return uVar1;
  }
  if (param_2 != 2) {
    return 0xffffffff;
  }
  iVar2 = (int)(uVar1 & 0xffffffe7) >> 3;
  *(uint *)(&DAT_100791e8 + iVar2) = *(uint *)(&DAT_100791e8 + iVar2) | 1 << (param_1 & 0x1f);
  return uVar1;
}


