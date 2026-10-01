// 1002e900 ___crtMessageBoxA [Global]
// program: RWDLDD21.DLL

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_100378a4 != (FARPROC)0x0) {
LAB_1002e94f:
    if (DAT_100378a8 != (FARPROC)0x0) {
      iVar1 = (*DAT_100378a8)();
    }
    if ((iVar1 != 0) && (DAT_100378ac != (FARPROC)0x0)) {
      iVar1 = (*DAT_100378ac)(iVar1);
    }
    iVar1 = (*DAT_100378a4)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_100378a4 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_100378a4 != (FARPROC)0x0) {
      DAT_100378a8 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_100378ac = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_1002e94f;
    }
  }
  return 0;
}


