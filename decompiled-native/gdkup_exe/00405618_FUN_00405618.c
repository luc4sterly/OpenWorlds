// 00405618 FUN_00405618 [Global]
// programa: gdkup.exe

longlong __fastcall FUN_00405618(undefined4 param_1,uint param_2)

{
  DWORD DVar1;
  HANDLE hFile;
  
  (*(code *)PTR_FUN_00408b3c)(param_2,param_1);
  DVar1 = GetFileType(hFile);
  if (DVar1 == 2) {
    (*(code *)PTR_FUN_00408b40)();
    return CONCAT44(param_2,1);
  }
  (*(code *)PTR_FUN_00408b40)();
  return (ulonglong)param_2 << 0x20;
}


