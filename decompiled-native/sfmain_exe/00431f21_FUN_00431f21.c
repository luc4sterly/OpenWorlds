// 00431f21 FUN_00431f21 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00431f21(void)

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
  WriteFile(*(HANDLE *)(_DAT_004e57c8 + 8),in_EAX,nNumberOfBytesToWrite,&local_14,(LPOVERLAPPED)0x0)
  ;
  FUN_0042d40e(extraout_ECX,extraout_EDX);
  return;
}


