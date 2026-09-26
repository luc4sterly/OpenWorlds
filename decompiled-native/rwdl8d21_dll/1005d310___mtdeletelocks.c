// 1005d310 __mtdeletelocks [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    __mtdeletelocks
   
   Library: Visual Studio 1998 Release */

void __cdecl __mtdeletelocks(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  iVar1 = 0;
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)(&DAT_10075da0)[iVar1];
    if ((((lpCriticalSection != (LPCRITICAL_SECTION)0x0) && (iVar1 != 0x11)) && (iVar1 != 0xd)) &&
       ((iVar1 != 9 && (iVar1 != 1)))) {
      DeleteCriticalSection(lpCriticalSection);
      _free((void *)(&DAT_10075da0)[iVar1]);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x30);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10075dc4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10075dd4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10075de4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10075da4);
  return;
}


