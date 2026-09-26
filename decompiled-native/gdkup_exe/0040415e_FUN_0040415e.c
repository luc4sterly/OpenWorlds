// 0040415e FUN_0040415e [Global]
// programa: gdkup.exe

void FUN_0040415e(void)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  DWORD nNumberOfBytesToWrite;
  DWORD local_14;
  
  nNumberOfBytesToWrite = 0;
  pcVar2 = in_EAX;
  while (cVar1 = *pcVar2, pcVar2 = pcVar2 + 1, cVar1 != '\0') {
    nNumberOfBytesToWrite = nNumberOfBytesToWrite + 1;
  }
  WriteFile(*(HANDLE *)(DAT_0040b478 + 8),in_EAX,nNumberOfBytesToWrite,&local_14,(LPOVERLAPPED)0x0);
  FUN_0040353b(extraout_ECX,extraout_EDX);
  return;
}


