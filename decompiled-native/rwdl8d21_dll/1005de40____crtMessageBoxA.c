// 1005de40 ___crtMessageBoxA [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_10076724 != (FARPROC)0x0) {
LAB_1005de8f:
    if (DAT_10076728 != (FARPROC)0x0) {
      iVar1 = (*DAT_10076728)();
    }
    if ((iVar1 != 0) && (DAT_1007672c != (FARPROC)0x0)) {
      iVar1 = (*DAT_1007672c)(iVar1);
    }
    iVar1 = (*DAT_10076724)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_10076724 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_10076724 != (FARPROC)0x0) {
      DAT_10076728 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_1007672c = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_1005de8f;
    }
  }
  return 0;
}


