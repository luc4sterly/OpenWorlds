// 00432eea FUN_00432eea [Global]
// programa: sfmain.exe

int __fastcall FUN_00432eea(undefined4 param_1,undefined1 *param_2)

{
  byte bVar2;
  byte *in_EAX;
  uint uVar1;
  int unaff_EBX;
  
  while( true ) {
    if (unaff_EBX == 0) {
      return 0;
    }
    bVar2 = *in_EAX;
    uVar1 = (uint)CONCAT11(*param_2,bVar2);
    if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
      uVar1 = (uint)CONCAT11(*param_2,bVar2 + 0x20);
    }
    bVar2 = (byte)(uVar1 >> 8);
    if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
      uVar1 = (uint)CONCAT11(bVar2 + 0x20,(char)uVar1);
    }
    bVar2 = (byte)(uVar1 >> 8);
    if ((byte)uVar1 != bVar2) break;
    if (bVar2 == 0) {
      return 0;
    }
    in_EAX = in_EAX + 1;
    param_2 = param_2 + 1;
    unaff_EBX = unaff_EBX + -1;
  }
  return (uVar1 & 0xff) - (uint)bVar2;
}


