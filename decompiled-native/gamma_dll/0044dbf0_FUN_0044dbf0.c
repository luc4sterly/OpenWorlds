// 0044dbf0 FUN_0044dbf0 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0044dbf0(int param_1,uint *param_2,DWORD param_3)

{
  undefined4 *puVar1;
  HANDLE hFile;
  LPVOID pvVar2;
  uint uVar3;
  uint *lpBuffer;
  BOOL BVar4;
  uint *puVar5;
  int iVar6;
  uint *local_1c;
  DWORD local_14;
  
  local_1c = (uint *)0x0;
  if ((0xff < param_1) ||
     (puVar1 = (undefined4 *)(&DAT_0049f448)[param_1], puVar1 == (undefined4 *)0x0)) {
    pvVar2 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar2 + 4) = 3;
    return 0xffffffff;
  }
  hFile = (HANDLE)*puVar1;
  lpBuffer = param_2;
  if (*(char *)(puVar1 + 1) != '\0') {
    iVar6 = 0;
    for (uVar3 = 0; uVar3 < param_3; uVar3 = uVar3 + 1) {
      if (*(char *)(uVar3 + (int)param_2) == '\n') {
        iVar6 = iVar6 + 1;
      }
    }
    lpBuffer = FUN_00454a10(iVar6 + param_3);
    puVar5 = lpBuffer;
    for (uVar3 = 0; uVar3 < param_3; uVar3 = uVar3 + 1) {
      if (*(char *)(uVar3 + (int)param_2) == '\n') {
        *(undefined1 *)puVar5 = 0xd;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      *(undefined1 *)puVar5 = *(undefined1 *)(uVar3 + (int)param_2);
      puVar5 = (uint *)((int)puVar5 + 1);
    }
    param_3 = param_3 + iVar6;
    local_1c = lpBuffer;
  }
  if (*(char *)((&DAT_0049f448)[param_1] + 5) != '\0') {
    FUN_0044da60(param_1,0,2);
  }
  BVar4 = WriteFile(hFile,lpBuffer,param_3,&local_14,(LPOVERLAPPED)0x0);
  if (local_1c != (uint *)0x0) {
    FUN_00454a60(local_1c);
  }
  if (BVar4 != 0) {
    return local_14;
  }
  _DAT_0049ff4c = GetLastError();
  return 0;
}


