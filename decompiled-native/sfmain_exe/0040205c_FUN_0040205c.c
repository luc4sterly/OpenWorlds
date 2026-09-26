// 0040205c FUN_0040205c [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0040205c(undefined4 param_1,undefined4 param_2)

{
  HGLOBAL hMem;
  
  if (DAT_004380fc == (LPVOID)0x0) {
    hMem = GlobalAlloc(0x40,16000);
    DAT_004380fc = GlobalLock(hMem);
  }
  return CONCAT44(param_2,(uint)(DAT_004380fc != (LPVOID)0x0));
}


