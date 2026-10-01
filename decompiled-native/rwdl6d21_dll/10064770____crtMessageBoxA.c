// 10064770 ___crtMessageBoxA [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    ___crtMessageBoxA
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtMessageBoxA(LPCSTR _LpText,LPCSTR _LpCaption,UINT _UType)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_1007a724 != (FARPROC)0x0) {
LAB_100647bf:
    if (DAT_1007a728 != (FARPROC)0x0) {
      iVar1 = (*DAT_1007a728)();
    }
    if ((iVar1 != 0) && (DAT_1007a72c != (FARPROC)0x0)) {
      iVar1 = (*DAT_1007a72c)(iVar1);
    }
    iVar1 = (*DAT_1007a724)(iVar1,_LpText,_LpCaption,_UType);
    return iVar1;
  }
  hModule = LoadLibraryA("user32.dll");
  if (hModule != (HMODULE)0x0) {
    DAT_1007a724 = GetProcAddress(hModule,"MessageBoxA");
    if (DAT_1007a724 != (FARPROC)0x0) {
      DAT_1007a728 = GetProcAddress(hModule,"GetActiveWindow");
      DAT_1007a72c = GetProcAddress(hModule,"GetLastActivePopup");
      goto LAB_100647bf;
    }
  }
  return 0;
}


