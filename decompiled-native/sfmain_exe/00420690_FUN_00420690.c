// 00420690 FUN_00420690 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_00420690(undefined4 param_1,undefined4 param_2)

{
  byte in_AL;
  byte bVar1;
  
  if ((in_AL & 0x80) == 0) {
    bVar1 = (&DAT_0043d738)[in_AL ^ 0x55] ^ 0x7f;
  }
  else {
    bVar1 = (&DAT_0043d738)[in_AL ^ 0xd5] ^ 0xff;
  }
  return CONCAT44(param_2,(uint)bVar1);
}


