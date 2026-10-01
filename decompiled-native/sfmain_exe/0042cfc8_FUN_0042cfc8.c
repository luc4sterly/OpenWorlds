// 0042cfc8 FUN_0042cfc8 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0042cfc8(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  byte *in_EAX;
  int iVar3;
  
  while (((&DAT_00437bd8)[(byte)(*in_EAX + 1)] & 2) != 0) {
    in_EAX = in_EAX + 1;
  }
  bVar1 = *in_EAX;
  if ((bVar1 == 0x2b) || (bVar1 == 0x2d)) {
    in_EAX = in_EAX + 1;
  }
  iVar3 = 0;
  while (((&DAT_00437bd8)[(byte)(*in_EAX + 1)] & 0x20) != 0) {
    bVar2 = *in_EAX;
    in_EAX = in_EAX + 1;
    iVar3 = iVar3 * 10 + (uint)bVar2 + -0x30;
  }
  if (bVar1 == 0x2d) {
    iVar3 = -iVar3;
  }
  return CONCAT44(param_2,iVar3);
}


