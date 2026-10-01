// 00403121 FUN_00403121 [Global]
// program: gdkup.exe

int __fastcall FUN_00403121(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  byte *in_EAX;
  
  while( true ) {
    bVar1 = *in_EAX;
    bVar2 = *param_2;
    if ((0x40 < bVar1) && (bVar1 < 0x5b)) {
      bVar1 = bVar1 + 0x20;
    }
    if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
      bVar2 = bVar2 + 0x20;
    }
    if ((bVar1 != bVar2) || (bVar2 == 0)) break;
    in_EAX = in_EAX + 1;
    param_2 = param_2 + 1;
  }
  return (uint)bVar1 - (uint)bVar2;
}


