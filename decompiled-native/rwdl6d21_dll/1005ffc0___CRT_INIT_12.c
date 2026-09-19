// 1005ffc0 __CRT_INIT@12 [Global]
// programa: RWDL6D21.DLL

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
    if (0 < DAT_10079570) {
      DAT_10079570 = DAT_10079570 + -1;
      if (DAT_100796cc == 0) {
        __cexit();
      }
      __ioterm();
      __mtterm();
      __heap_term();
      return 1;
    }
    return 0;
  }
  DAT_10079694 = GetVersion();
  if (DAT_10079584 == 0) {
    if (((char)DAT_10079694 == '\x03') && ((DAT_10079694 & 0x80000000) != 0)) {
      FUN_10061a70(2);
    }
    hModule = GetModuleHandleA("kernel32.dll");
    if (hModule != (HMODULE)0x0) {
      pFVar1 = GetProcAddress(hModule,"IsTNT");
      if (pFVar1 != (FARPROC)0x0) {
        FUN_10061a70(1);
      }
    }
  }
  iVar2 = __heap_init();
  if (iVar2 == 0) {
    return 0;
  }
  _DAT_100796a0 = DAT_10079694 >> 8 & 0xff;
  _DAT_1007969c = DAT_10079694 & 0xff;
  _DAT_10079698 = _DAT_1007969c * 0x100 + _DAT_100796a0;
  DAT_10079694 = DAT_10079694 >> 0x10;
  iVar2 = __mtinit();
  if (iVar2 == 0) {
    __heap_term();
    return 0;
  }
  DAT_1007d420 = GetCommandLineA();
  DAT_10079574 = ___crtGetEnvironmentStringsA();
  if ((DAT_1007d420 != (LPSTR)0x0) && (DAT_10079574 != (LPVOID)0x0)) {
    __ioinit();
    ___initmbctable();
    __setargv();
    __setenvp();
    __cinit(unaff_retaddr);
    DAT_10079570 = DAT_10079570 + 1;
    return 1;
  }
  __mtterm();
  __heap_term();
  return 0;
}


