// 00404ddd FUN_00404ddd [Global]
// programa: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

DWORD __cdecl FUN_00404ddd(uint param_1,LONG param_2,DWORD param_3)

{
  byte *pbVar1;
  HANDLE hFile;
  DWORD DVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 < DAT_0040cf80) {
    iVar4 = (param_1 & 0x1f) * 8;
    if ((*(byte *)((&DAT_0040ce80)[(int)param_1 >> 5] + 4 + iVar4) & 1) != 0) {
      hFile = (HANDLE)FUN_00405482(param_1);
      if (hFile == (HANDLE)0xffffffff) {
        _DAT_0040ba38 = 9;
        return 0xffffffff;
      }
      DVar2 = SetFilePointer(hFile,param_2,(PLONG)0x0,param_3);
      if (DVar2 == 0xffffffff) {
        uVar3 = GetLastError();
      }
      else {
        uVar3 = 0;
      }
      if (uVar3 != 0) {
        FUN_00405295(uVar3);
        return 0xffffffff;
      }
      pbVar1 = (byte *)((&DAT_0040ce80)[(int)param_1 >> 5] + 4 + iVar4);
      *pbVar1 = *pbVar1 & 0xfd;
      return DVar2;
    }
  }
  DAT_0040ba3c = 0;
  _DAT_0040ba38 = 9;
  return 0xffffffff;
}


