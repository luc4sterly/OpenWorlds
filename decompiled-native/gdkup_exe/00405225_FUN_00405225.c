// 00405225 FUN_00405225 [Global]
// program: gdkup.exe

void FUN_00405225(void)

{
  HANDLE hObject;
  int in_EAX;
  LPVOID pvVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  if (DAT_00408b34 != 0xffffffff) {
    pvVar1 = TlsGetValue(DAT_00408b34);
    if (pvVar1 != (LPVOID)0x0) {
      hObject = *(HANDLE *)((int)pvVar1 + 0xde);
      FUN_0040688f(extraout_ECX,extraout_EDX);
      TlsSetValue(DAT_00408b34,(LPVOID)0x0);
      if ((hObject != (HANDLE)0x0) && (in_EAX != 0)) {
        CloseHandle(hObject);
      }
    }
  }
  return;
}


