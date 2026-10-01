// 00432296 FUN_00432296 [Global]
// program: sfmain.exe

longlong __fastcall FUN_00432296(undefined4 param_1,uint param_2)

{
  DWORD DVar1;
  HANDLE hFile;
  
  (*(code *)PTR_FUN_0043e7f0)(param_2,param_1);
  DVar1 = GetFileType(hFile);
  if (DVar1 == 2) {
    (*(code *)PTR_FUN_0043e7f4)();
    return CONCAT44(param_2,1);
  }
  (*(code *)PTR_FUN_0043e7f4)();
  return (ulonglong)param_2 << 0x20;
}


