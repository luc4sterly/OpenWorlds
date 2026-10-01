// 0042f424 FUN_0042f424 [Global]
// program: sfmain.exe

DWORD FUN_0042f424(void)

{
  DWORD DVar1;
  LONG lDistanceToMove;
  undefined4 extraout_ECX;
  HANDLE hFile;
  int extraout_EDX;
  DWORD unaff_EBX;
  
  (*(code *)PTR_FUN_0043e7f0)();
  DVar1 = SetFilePointer(hFile,lDistanceToMove,(PLONG)0x0,unaff_EBX);
  (*(code *)PTR_FUN_0043e7f4)();
  if (extraout_EDX == -1) {
    FUN_00430d8f(extraout_ECX,0xffffffff);
  }
  return DVar1;
}


