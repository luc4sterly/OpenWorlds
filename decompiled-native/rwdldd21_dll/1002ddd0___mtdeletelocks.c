// 1002ddd0 __mtdeletelocks [Global]
// program: RWDLDD21.DLL

/* Library Function - Single Match
    __mtdeletelocks
   
   Library: Visual Studio 1998 Release */

void __cdecl __mtdeletelocks(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar1;
  
  iVar1 = 0;
  do {
    lpCriticalSection = (LPCRITICAL_SECTION)(&DAT_10036f20)[iVar1];
    if ((((lpCriticalSection != (LPCRITICAL_SECTION)0x0) && (iVar1 != 0x11)) && (iVar1 != 0xd)) &&
       ((iVar1 != 9 && (iVar1 != 1)))) {
      DeleteCriticalSection(lpCriticalSection);
      _free((void *)(&DAT_10036f20)[iVar1]);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x30);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10036f44);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10036f54);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10036f64);
  DeleteCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10036f24);
  return;
}


