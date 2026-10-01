// 004296b9 FUN_004296b9 [Global]
// program: sfmain.exe

void __cdecl FUN_004296b9(LPCSTR param_1)

{
  DWORD nNumberOfBytesToWrite;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  DWORD local_420;
  CHAR local_41c [1024];
  va_list local_1c;
  
  local_1c = &stack0x00000008;
  wvsprintfA(local_41c,param_1,local_1c);
  local_1c = (va_list)0x0;
  if (DAT_0043d6d8 != (HANDLE)0xffffffff) {
    lpOverlapped = (LPOVERLAPPED)0x0;
    lpNumberOfBytesWritten = &local_420;
    nNumberOfBytesToWrite = FUN_0042c5ad();
    WriteFile(DAT_0043d6d8,local_41c,nNumberOfBytesToWrite,lpNumberOfBytesWritten,lpOverlapped);
  }
  return;
}


