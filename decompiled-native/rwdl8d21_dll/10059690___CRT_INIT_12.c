// 10059690 __CRT_INIT@12 [Global]
// program: RWDL8D21.DLL

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
    if (0 < DAT_10075570) {
      DAT_10075570 = DAT_10075570 + -1;
      if (DAT_100756cc == 0) {
        __cexit();
      }
      __ioterm();
      __mtterm();
      __heap_term();
      return 1;
    }
    return 0;
  }
  DAT_10075694 = GetVersion();
  if (DAT_10075584 == 0) {
    if (((char)DAT_10075694 == '\x03') && ((DAT_10075694 & 0x80000000) != 0)) {
      FUN_1005b140(2);
    }
    hModule = GetModuleHandleA("kernel32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"IsTNT");
      if (pFVar1 != (FARPROC)0x0) {
        FUN_1005b140(1);
      }
    }
  }
  iVar2 = __heap_init();
  if (iVar2 == 0) {
    return 0;
  }
  _DAT_100756a0 = DAT_10075694 >> 8 & 0xff;
  _DAT_1007569c = DAT_10075694 & 0xff;
  _DAT_10075698 = _DAT_1007569c * 0x100 + _DAT_100756a0;
  DAT_10075694 = DAT_10075694 >> 0x10;
  iVar2 = __mtinit();
  if (iVar2 == 0) {
    __heap_term();
    return 0;
  }
  DAT_10079420 = GetCommandLineA();
  DAT_10075574 = ___crtGetEnvironmentStringsA();
  if ((DAT_10079420 != (LPSTR)0x0) && (DAT_10075574 != (LPVOID)0x0)) {
    __ioinit();
    ___initmbctable();
    __setargv();
    __setenvp();
    __cinit(unaff_retaddr);
    DAT_10075570 = DAT_10075570 + 1;
    return 1;
  }
  __mtterm();
  __heap_term();
  return 0;
}


