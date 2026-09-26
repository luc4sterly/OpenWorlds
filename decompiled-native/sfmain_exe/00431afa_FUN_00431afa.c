// 00431afa FUN_00431afa [Global]
// programa: sfmain.exe

void FUN_00431afa(void)

{
  HANDLE hObject;
  int in_EAX;
  LPVOID pvVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  if (DAT_0043e7e8 != 0xffffffff) {
    pvVar1 = TlsGetValue(DAT_0043e7e8);
    if (pvVar1 != (LPVOID)0x0) {
      hObject = *(HANDLE *)((int)pvVar1 + 0xde);
      FUN_004326a6(extraout_ECX,extraout_EDX);
      TlsSetValue(DAT_0043e7e8,(LPVOID)0x0);
      if ((hObject != (HANDLE)0x0) && (in_EAX != 0)) {
        CloseHandle(hObject);
      }
    }
  }
  return;
}


