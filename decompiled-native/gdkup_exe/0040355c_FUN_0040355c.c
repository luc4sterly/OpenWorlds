// 0040355c FUN_0040355c [Global]
// program: gdkup.exe

undefined4 __fastcall FUN_0040355c(undefined4 param_1,byte *param_2)

{
  ushort *in_EAX;
  ushort uVar1;
  byte bVar2;
  uint unaff_EBX;
  
  if ((param_2 != (byte *)0x0) && (unaff_EBX != 0)) {
    bVar2 = *param_2;
    if (in_EAX != (ushort *)0x0) {
      *in_EAX = (ushort)bVar2;
    }
    if (bVar2 != 0) {
      if (((bVar2 < 0x81) || (0x9f < bVar2)) && ((bVar2 < 0xe0 || (0xfc < bVar2)))) {
        return 1;
      }
      if (unaff_EBX < 2) {
        uVar1 = (ushort)bVar2;
      }
      else {
        uVar1 = CONCAT11(param_2[1],bVar2);
      }
      bVar2 = (byte)(uVar1 >> 8);
      if (((0x3f < bVar2) && (bVar2 < 0xfd)) && (bVar2 != 0x7f)) {
        if (in_EAX != (ushort *)0x0) {
          *in_EAX = uVar1 * 0x100 + (ushort)bVar2;
        }
        return 2;
      }
      return 0xffffffff;
    }
  }
  return 0;
}


