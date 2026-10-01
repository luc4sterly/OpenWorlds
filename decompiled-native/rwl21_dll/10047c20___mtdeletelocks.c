// 10047c20 __mtdeletelocks [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __mtdeletelocks
   
   Library: Visual Studio 1998 Release */

void __cdecl __mtdeletelocks(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  iVar1 = 0;
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)(&DAT_1005bba8)[iVar1];
    if ((((lpCriticalSection != (LPCRITICAL_SECTION)0x0) && (iVar1 != 0x11)) && (iVar1 != 0xd)) &&
       ((iVar1 != 9 && (iVar1 != 1)))) {
      DeleteCriticalSection(lpCriticalSection);
      _free((void *)(&DAT_1005bba8)[iVar1]);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x30);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005bbcc);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005bbdc);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005bbec);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005bbac);
  return;
}


