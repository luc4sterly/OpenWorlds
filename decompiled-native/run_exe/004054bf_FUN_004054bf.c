// 004054bf FUN_004054bf [Global]
// programa: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_004054bf(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD DVar2;
  
  DVar2 = DAT_0040ba3c;
  if ((param_1 < DAT_0040cf80) &&
     ((*(byte *)((&DAT_0040ce80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    hFile = (HANDLE)FUN_00405482(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = 0;
    }
    if (DVar2 == 0) {
      return 0;
    }
  }
  DAT_0040ba3c = DVar2;
  _DAT_0040ba38 = 9;
  return 0xffffffff;
}


