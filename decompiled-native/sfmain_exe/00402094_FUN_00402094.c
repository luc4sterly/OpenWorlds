// 00402094 FUN_00402094 [Global]
// program: sfmain.exe

void FUN_00402094(void)

{
  HGLOBAL pvVar1;
  
  if (DAT_004380fc != (LPCVOID)0x0) {
    pvVar1 = GlobalHandle(DAT_004380fc);
    GlobalUnlock(pvVar1);
    pvVar1 = GlobalHandle(DAT_004380fc);
    GlobalFree(pvVar1);
    DAT_004380fc = (LPCVOID)0x0;
  }
  return;
}


