// 00403f98 FUN_00403f98 [Global]
// program: gdkup.exe

DWORD FUN_00403f98(void)

{
  DWORD DVar1;
  LONG lDistanceToMove;
  undefined4 extraout_ECX;
  HANDLE hFile;
  int extraout_EDX;
  DWORD unaff_EBX;
  
  (*(code *)PTR_FUN_00408b3c)();
  DVar1 = SetFilePointer(hFile,lDistanceToMove,(PLONG)0x0,unaff_EBX);
  (*(code *)PTR_FUN_00408b40)();
  if (extraout_EDX == -1) {
    FUN_00405609(extraout_ECX,0xffffffff);
  }
  return DVar1;
}


