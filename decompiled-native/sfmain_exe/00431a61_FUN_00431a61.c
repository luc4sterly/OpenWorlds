// 00431a61 FUN_00431a61 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_00431a61(undefined4 param_1,undefined4 param_2)

{
  DAT_0043e7e8 = TlsAlloc();
  if ((DAT_0043e875 >> 8 & 0x80) != 0) {
    while ((DAT_0043e7e8 != 0xffffffff && (DAT_0043e7e8 < 3))) {
      DAT_0043e7e8 = TlsAlloc();
    }
  }
  return CONCAT44(param_2,(uint)(DAT_0043e7e8 != 0xffffffff));
}


