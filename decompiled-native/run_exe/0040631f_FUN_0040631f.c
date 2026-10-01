// 0040631f FUN_0040631f [Global]
// program: run.exe

int __cdecl FUN_0040631f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0040bbac == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_0040bbac = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_0040bbac != (FARPROC)0x0) {
        DAT_0040bbb0 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_0040bbb4 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_0040636e;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_0040636e:
    if (DAT_0040bbb0 != (FARPROC)0x0) {
      iVar1 = (*DAT_0040bbb0)();
      if ((iVar1 != 0) && (DAT_0040bbb4 != (FARPROC)0x0)) {
        iVar1 = (*DAT_0040bbb4)(iVar1);
      }
    }
    iVar1 = (*DAT_0040bbac)(iVar1,param_1,param_2,param_3);
  }
  return iVar1;
}


