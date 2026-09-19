// 10045a50 __CRT_INIT@12 [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __CRT_INIT@12
   
   Library: Visual Studio 1998 Release */

undefined4 __CRT_INIT_12(undefined4 param_1,int param_2)

{
  HMODULE hModule;
  FARPROC pFVar1;
  int iVar2;
  int unaff_retaddr;
  
  if (param_2 != 1) {
    if (param_2 != 0) {
      if (param_2 == 3) {
        __freeptd((_ptiddata)0x0);
      }
      return 1;
    }
    if (0 < DAT_1005bb60) {
      DAT_1005bb60 = DAT_1005bb60 + -1;
      if (DAT_1005bed4 == 0) {
        __cexit();
      }
      __ioterm();
      __mtterm();
      __heap_term();
      return 1;
    }
    return 0;
  }
  DAT_1005be9c = GetVersion();
  if (DAT_1005bb74 == 0) {
    if (((char)DAT_1005be9c == '\x03') && ((DAT_1005be9c & 0x80000000) != 0)) {
      FUN_1004abe0(2);
    }
    hModule = GetModuleHandleA("kernel32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"IsTNT");
      if (pFVar1 != (FARPROC)0x0) {
        FUN_1004abe0(1);
      }
    }
  }
  iVar2 = __heap_init();
  if (iVar2 == 0) {
    return 0;
  }
  _DAT_1005bea8 = DAT_1005be9c >> 8 & 0xff;
  _DAT_1005bea4 = DAT_1005be9c & 0xff;
  _DAT_1005bea0 = _DAT_1005bea4 * 0x100 + _DAT_1005bea8;
  DAT_1005be9c = DAT_1005be9c >> 0x10;
  iVar2 = __mtinit();
  if (iVar2 == 0) {
    __heap_term();
    return 0;
  }
  DAT_1005f7e0 = GetCommandLineA();
  DAT_1005bb64 = ___crtGetEnvironmentStringsA();
  if ((DAT_1005f7e0 != (LPSTR)0x0) && (DAT_1005bb64 != (LPVOID)0x0)) {
    __ioinit();
    ___initmbctable();
    __setargv();
    __setenvp();
    __cinit(unaff_retaddr);
    DAT_1005bb60 = DAT_1005bb60 + 1;
    return 1;
  }
  __mtterm();
  __heap_term();
  return 0;
}


