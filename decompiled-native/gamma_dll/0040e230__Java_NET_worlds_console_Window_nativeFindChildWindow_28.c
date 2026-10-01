// 0040e230 _Java_NET_worlds_console_Window_nativeFindChildWindow@28 [Global]
// program: gamma.dll

HWND _Java_NET_worlds_console_Window_nativeFindChildWindow_28
               (undefined4 param_1,undefined4 param_2,HWND param_3,int param_4,int param_5,
               int param_6,int param_7)

{
  POINT Point;
  void *pvVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  HWND pHVar9;
  byte *pbVar10;
  HWND local_30;
  HWND local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  
                    /* 0xe230  103  _Java_NET_worlds_console_Window_nativeFindChildWindow@28 */
  if (DAT_004892cc != 0) {
    pbVar10 = &DAT_0046e9ec;
    pbVar7 = &DAT_0046ea10;
    pbVar5 = &DAT_0046ea14;
    pbVar3 = &DAT_0046ea10;
    iVar2 = param_4;
    iVar4 = param_5;
    iVar6 = param_6;
    iVar8 = param_7;
    pvVar1 = (void *)FUN_00403350(0x49eda8,(byte *)s_Looking_for_0046ea18);
    iVar2 = FUN_00409ee0(pvVar1,iVar2);
    pvVar1 = (void *)FUN_00403350(iVar2,pbVar3);
    iVar2 = FUN_00409ee0(pvVar1,iVar4);
    pvVar1 = (void *)FUN_00403350(iVar2,pbVar5);
    iVar2 = FUN_00409ee0(pvVar1,iVar6);
    pvVar1 = (void *)FUN_00403350(iVar2,pbVar7);
    iVar2 = FUN_00409ee0(pvVar1,iVar8);
    FUN_00403350(iVar2,pbVar10);
  }
  local_2c = (HWND)0x0;
  local_30 = param_3;
  local_28 = param_4;
  local_24 = param_5;
  local_1c = param_7;
  local_20 = param_6;
  EnumChildWindows(param_3,(WNDENUMPROC)&LAB_0040e060,(LPARAM)&local_30);
  if ((local_2c == (HWND)0x0) && (DAT_004891cc != 0)) {
    local_14 = (param_7 >> 1) + param_5;
    local_18 = (param_6 >> 1) + param_4;
    Point.y = local_14;
    Point.x = local_18;
    local_2c = WindowFromPoint(Point);
  }
  if (DAT_004892cc != 0) {
    pbVar3 = &DAT_0046e9ec;
    pHVar9 = local_2c;
    pvVar1 = (void *)FUN_00403350(0x49eda8,(byte *)s_Returning_window_handle_0046ea28);
    iVar2 = FUN_0040f5a0(pvVar1,pHVar9);
    FUN_00403350(iVar2,pbVar3);
  }
  return local_2c;
}


