// 0040518c FUN_0040518c [Global]
// programa: gdkup.exe

undefined8 __fastcall FUN_0040518c(undefined4 param_1,undefined4 param_2)

{
  DAT_00408b34 = TlsAlloc();
  if ((DAT_00408ea5 >> 8 & 0x80) != 0) {
    while ((DAT_00408b34 != 0xffffffff && (DAT_00408b34 < 3))) {
      DAT_00408b34 = TlsAlloc();
    }
  }
  return CONCAT44(param_2,(uint)(DAT_00408b34 != 0xffffffff));
}


