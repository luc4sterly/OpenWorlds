// 0042f45e FUN_0042f45e [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_0042f45e(undefined4 param_1,undefined4 param_2)

{
  DWORD DVar1;
  undefined4 extraout_ECX;
  HANDLE hFile;
  undefined4 extraout_EDX;
  
  (*(code *)PTR_FUN_0043e7f0)(param_2,param_1);
  DVar1 = SetFilePointer(hFile,0,(PLONG)0x0,1);
  if (DVar1 == 0xffffffff) {
    FUN_00430d8f(extraout_ECX,0xffffffff);
  }
  (*(code *)PTR_FUN_0043e7f4)();
  return CONCAT44(param_2,extraout_EDX);
}


