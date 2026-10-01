// 0040d6c0 FUN_0040d6c0 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_0040d6c0(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  HGLOBAL pvVar1;
  SIZE_T dwBytes;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined8 uVar2;
  UINT uFlags;
  
  if (DAT_004393b4 <= param_2) {
    DAT_004393b4 = DAT_004393b4 + 0x32;
    pvVar1 = GlobalHandle(DAT_004393b0);
    GlobalUnlock(pvVar1);
    uFlags = 0;
    dwBytes = DAT_004393b4 << 2;
    pvVar1 = GlobalHandle(DAT_004393b0);
    pvVar1 = GlobalReAlloc(pvVar1,dwBytes,uFlags);
    DAT_004393b0 = GlobalLock(pvVar1);
    if (DAT_004393b0 == (LPVOID)0x0) {
      uVar2 = FUN_00429192(extraout_ECX,extraout_EDX);
      FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar2 >> 0x20),0x3f,
                   s__GAMMA_speakfre_sfmain_ANSWER_c_00435a9c,1,in_EAX,0x30,(LPCSTR)uVar2);
      return 0;
    }
  }
  return 1;
}


