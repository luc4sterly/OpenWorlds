// 0044a350 FUN_0044a350 [Global]
// program: gamma.dll

void __fastcall FUN_0044a350(int param_1)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  
  DVar1 = timeGetTime();
  iVar2 = (DVar1 - *(int *)(param_1 + 0xd8)) * 10000;
  if ((iVar2 < *(int *)(param_1 + 0xd0) * 2) || (iVar2 < *(int *)(param_1 + 0xd4) * 2)) {
    iVar3 = *(int *)(param_1 + 0xd0) * 3 + iVar2;
    *(int *)(param_1 + 0xd0) = (int)(iVar3 + (iVar3 >> 0x1f & 3U)) >> 2;
  }
  *(int *)(param_1 + 0xd4) = iVar2;
  if (*(int *)(param_1 + 0xcc) < 1) {
    DVar1 = 0;
  }
  else {
    DVar1 = *(int *)(param_1 + 0xcc) / 10000;
  }
  Sleep(DVar1);
  return;
}


