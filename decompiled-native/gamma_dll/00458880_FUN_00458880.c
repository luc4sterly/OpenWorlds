// 00458880 FUN_00458880 [Global]
// program: gamma.dll

int FUN_00458880(void)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  byte local_404;
  char local_403;
  
  iVar2 = 0;
  DVar1 = GetCurrentDirectoryA(0x400,(LPSTR)&local_404);
  if ((DVar1 != 0) && (local_403 == ':')) {
    if (local_404 == 0xff) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = (uint)(byte)(&DAT_00482918)[local_404];
    }
    iVar2 = uVar3 - 0x42;
  }
  return iVar2;
}


