// 1004d040 ___crtMessageBoxA [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_1005cda0 != (FARPROC)0x0) {
LAB_1004d08f:
    if (DAT_1005cda4 != (FARPROC)0x0) {
      iVar1 = (*DAT_1005cda4)();
    }
    if ((iVar1 != 0) && (DAT_1005cda8 != (FARPROC)0x0)) {
      iVar1 = (*DAT_1005cda8)(iVar1);
    }
    iVar1 = (*DAT_1005cda0)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_1005cda0 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_1005cda0 != (FARPROC)0x0) {
      DAT_1005cda4 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_1005cda8 = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_1004d08f;
    }
  }
  return 0;
}


