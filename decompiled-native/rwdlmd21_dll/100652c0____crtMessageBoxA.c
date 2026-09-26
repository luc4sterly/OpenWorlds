// 100652c0 ___crtMessageBoxA [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_10088754 != (FARPROC)0x0) {
LAB_1006530f:
    if (DAT_10088758 != (FARPROC)0x0) {
      iVar1 = (*DAT_10088758)();
    }
    if ((iVar1 != 0) && (DAT_1008875c != (FARPROC)0x0)) {
      iVar1 = (*DAT_1008875c)(iVar1);
    }
    iVar1 = (*DAT_10088754)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_10088754 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_10088754 != (FARPROC)0x0) {
      DAT_10088758 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_1008875c = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_1006530f;
    }
  }
  return 0;
}


