// 00405670 FUN_00405670 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00405670(HWND param_1)

{
  byte bVar1;
  BOOL BVar2;
  DWORD DVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  tagPOINT local_38;
  int local_30 [2];
  undefined1 local_25;
  
  BVar2 = GetCursorPos(&local_38);
  if (BVar2 == 0) {
    FUN_00402800(s_nRightMenu_0046d7c8,0x4b);
  }
  BVar2 = TrackPopupMenu(DAT_004890b0,2,local_38.x,local_38.y,0,param_1,(RECT *)0x0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
    pvVar4 = (void *)FUN_00403350(0x49eda8,(byte *)s_Error_from_TrackPopupMenu__0046d7d4);
    pvVar4 = (void *)FUN_00405750(pvVar4,DVar3);
    FUN_004049b0(*(void **)((int)pvVar4 + 4),local_30);
    local_25 = DAT_004890b4;
    piVar5 = (int *)FUN_00404a00(local_30);
    bVar1 = (**(code **)(*piVar5 + 0x14))(10);
    FUN_00404dc0(local_30);
    iVar6 = FUN_00404b40(pvVar4,bVar1);
    FUN_00403ac0(iVar6);
    FUN_00402800(s_nRightMenu_0046d7c8,0x4e);
  }
  return 0;
}


