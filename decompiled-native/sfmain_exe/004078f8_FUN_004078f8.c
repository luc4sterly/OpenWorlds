// 004078f8 FUN_004078f8 [Global]
// program: sfmain.exe

void __fastcall FUN_004078f8(undefined4 param_1,ushort *param_2)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0xa0;
  uVar1 = (uint)*(ushort *)(in_EAX + 0x282);
  while( true ) {
    iVar3 = iVar3 + -1;
    if (iVar3 == -1) break;
    uVar1 = (int)(short)((short)uVar1 * 0x6e14 + 0x4000 >> 0xf) + (int)(short)*param_2;
    if (0xffff < uVar1 + 0x8000) {
      if ((int)uVar1 < 1) {
        uVar1 = 0xffff8000;
      }
      else {
        uVar1 = 0x7fff;
      }
    }
    iVar2 = (short)uVar1 * 2;
    if (0xffff < iVar2 + 0x8000U) {
      if (iVar2 < 1) {
        iVar2 = -0x8000;
      }
      else {
        iVar2 = 0x7fff;
      }
    }
    *param_2 = (ushort)iVar2 & 0xfff8;
    param_2 = param_2 + 1;
  }
  *(short *)(in_EAX + 0x282) = (short)uVar1;
  return;
}


