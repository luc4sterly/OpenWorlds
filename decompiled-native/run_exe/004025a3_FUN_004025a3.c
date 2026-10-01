// 004025a3 FUN_004025a3 [Global]
// program: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_004025a3(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  
  if (DAT_0040cf80 <= param_1) {
    DAT_0040ba3c = 0;
    _DAT_0040ba38 = 9;
    return 0xffffffff;
  }
  iVar5 = (param_1 & 0x1f) * 8;
  if ((*(byte *)((&DAT_0040ce80)[(int)param_1 >> 5] + 4 + iVar5) & 1) == 0) {
    _DAT_0040ba38 = 9;
    DAT_0040ba3c = 0;
    return 0xffffffff;
  }
  iVar1 = FUN_00405482(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_00405482(2);
      iVar2 = FUN_00405482(1);
      if (iVar2 == iVar1) goto LAB_0040261c;
    }
    hObject = (HANDLE)FUN_00405482(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_0040261e;
    }
  }
LAB_0040261c:
  DVar4 = 0;
LAB_0040261e:
  FUN_00405408(param_1);
  *(undefined1 *)((&DAT_0040ce80)[(int)param_1 >> 5] + 4 + iVar5) = 0;
  if (DVar4 == 0) {
    return 0;
  }
  FUN_00405295(DVar4);
  return 0xffffffff;
}


