// 004056c3 FUN_004056c3 [Global]
// program: gdkup.exe

undefined8 __fastcall FUN_004056c3(undefined4 param_1,undefined4 param_2)

{
  DWORD DVar1;
  undefined4 extraout_ECX;
  HANDLE hFile;
  undefined4 extraout_EDX;
  
  (*(code *)PTR_FUN_00408b3c)(param_2,param_1);
  DVar1 = SetFilePointer(hFile,0,(PLONG)0x0,1);
  if (DVar1 == 0xffffffff) {
    FUN_00405609(extraout_ECX,0xffffffff);
  }
  (*(code *)PTR_FUN_00408b40)();
  return CONCAT44(param_2,extraout_EDX);
}


