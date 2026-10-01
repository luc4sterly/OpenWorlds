// 10064790 __mtdeletelocks [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    __mtdeletelocks
   
   Library: Visual Studio 1998 Release */

void __cdecl __mtdeletelocks(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  iVar1 = 0;
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)(&DAT_10087dd0)[iVar1];
    if ((((lpCriticalSection != (LPCRITICAL_SECTION)0x0) && (iVar1 != 0x11)) && (iVar1 != 0xd)) &&
       ((iVar1 != 9 && (iVar1 != 1)))) {
      DeleteCriticalSection(lpCriticalSection);
      _free((void *)(&DAT_10087dd0)[iVar1]);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x30);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10087df4);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10087e04);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10087e14);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10087dd4);
  return;
}


