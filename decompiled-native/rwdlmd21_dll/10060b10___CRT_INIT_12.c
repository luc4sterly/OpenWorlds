// 10060b10 __CRT_INIT@12 [Global]
// program: rwdlmd21.dll

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
    if (0 < DAT_100875a0) {
      DAT_100875a0 = DAT_100875a0 + -1;
      if (DAT_100876fc == 0) {
        __cexit();
      }
      __ioterm();
      __mtterm();
      __heap_term();
      return 1;
    }
    return 0;
  }
  DAT_100876c4 = GetVersion();
  if (DAT_100875b4 == 0) {
    if (((char)DAT_100876c4 == '\x03') && ((DAT_100876c4 & 0x80000000) != 0)) {
      FUN_100625c0(2);
    }
    hModule = GetModuleHandleA("kernel32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"IsTNT");
      if (pFVar1 != (FARPROC)0x0) {
        FUN_100625c0(1);
      }
    }
  }
  iVar2 = __heap_init();
  if (iVar2 == 0) {
    return 0;
  }
  _DAT_100876d0 = DAT_100876c4 >> 8 & 0xff;
  _DAT_100876cc = DAT_100876c4 & 0xff;
  _DAT_100876c8 = _DAT_100876cc * 0x100 + _DAT_100876d0;
  DAT_100876c4 = DAT_100876c4 >> 0x10;
  iVar2 = __mtinit();
  if (iVar2 == 0) {
    __heap_term();
    return 0;
  }
  DAT_1008b460 = GetCommandLineA();
  DAT_100875a4 = ___crtGetEnvironmentStringsA();
  if ((DAT_1008b460 != (LPSTR)0x0) && (DAT_100875a4 != (LPVOID)0x0)) {
    __ioinit();
    ___initmbctable();
    __setargv();
    __setenvp();
    __cinit(unaff_retaddr);
    DAT_100875a0 = DAT_100875a0 + 1;
    return 1;
  }
  __mtterm();
  __heap_term();
  return 0;
}


