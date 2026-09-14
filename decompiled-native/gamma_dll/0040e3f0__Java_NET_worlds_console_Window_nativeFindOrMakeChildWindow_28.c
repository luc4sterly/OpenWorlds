// 0040e3f0 _Java_NET_worlds_console_Window_nativeFindOrMakeChildWindow@28 [Global]
// programa: gamma.dll

HWND _Java_NET_worlds_console_Window_nativeFindOrMakeChildWindow_28
               (undefined4 param_1,undefined4 param_2,HWND param_3,int param_4,int param_5,
               int param_6,int param_7)

{
  HMENU hMenu;
  void *pvVar1;
  int iVar2;
  LRESULT LVar3;
  HWND pHVar4;
  LONG LVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  HWND local_30;
  HWND local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagPOINT local_18;
  
                    /* 0xe3f0  104  _Java_NET_worlds_console_Window_nativeFindOrMakeChildWindow@28
                        */
  if (DAT_004892cc != 0) {
    pbVar12 = &DAT_0046e9ec;
    pbVar10 = &DAT_0046ea10;
    pbVar8 = &DAT_0046ea14;
    pbVar7 = &DAT_0046ea10;
    iVar2 = param_4;
    iVar6 = param_5;
    iVar9 = param_6;
    iVar11 = param_7;
    pvVar1 = (void *)FUN_00403350(0x49eda8,(byte *)s_Looking_for_0046ea18);
    iVar2 = FUN_00409ee0(pvVar1,iVar2);
    pvVar1 = (void *)FUN_00403350(iVar2,pbVar7);
    iVar2 = FUN_00409ee0(pvVar1,iVar6);
    pvVar1 = (void *)FUN_00403350(iVar2,pbVar8);
    iVar2 = FUN_00409ee0(pvVar1,iVar9);
    pvVar1 = (void *)FUN_00403350(iVar2,pbVar10);
    iVar2 = FUN_00409ee0(pvVar1,iVar11);
    FUN_00403350(iVar2,pbVar12);
  }
  local_30 = param_3;
  local_28 = param_4;
  local_1c = param_7;
  local_2c = (HWND)0x0;
  local_20 = param_6;
  local_24 = param_5;
  EnumChildWindows(param_3,(WNDENUMPROC)&LAB_0040e060,(LPARAM)&local_30);
  if (DAT_004892cc != 0) {
    pbVar7 = &DAT_0046e9ec;
    pHVar4 = local_2c;
    pvVar1 = (void *)FUN_00403350(0x49eda8,(byte *)s_Returning_window_handle_0046ea28);
    iVar2 = FUN_0040f5a0(pvVar1,pHVar4);
    FUN_00403350(iVar2,pbVar7);
  }
  if (((local_2c == (HWND)0x0) && (DAT_004891cc != 0)) &&
     (LVar3 = SendMessageTimeoutA(param_3,0x8000,0,0,2,10,(PDWORD_PTR)0x0), LVar3 != 0)) {
    if (DAT_004892cc != 0) {
      FUN_0044d5a0(s_Creating_child_window__d_x__d_0046ea50);
    }
    FUN_0040dfc0();
    local_18.y = param_5;
    local_18.x = param_4;
    MapWindowPoints((HWND)0x0,param_3,&local_18,1);
    hMenu = DAT_004892d4;
    DAT_004892d4 = (HMENU)((int)&DAT_004892d4->unused + 1);
    pHVar4 = CreateWindowExA(0,s_TempClass_0046e9c8,&DAT_0046e9c4,0x50000000,local_18.x,local_18.y,
                             param_6,param_7,param_3,hMenu,DAT_004891bc,(LPVOID)0x0);
    local_2c = pHVar4;
    LVar5 = GetWindowLongA(pHVar4,-4);
    iVar2 = DAT_00489248;
    iVar6 = 0;
    if (0 < DAT_00489248) {
      do {
        if ((&DAT_00489254)[iVar6] == LVar5) break;
        iVar6 = iVar6 + 1;
      } while (iVar6 < DAT_00489248);
    }
    if (iVar6 == DAT_00489248) {
      if (7 < DAT_00489248) {
        FUN_00403350(0x49eda8,(byte *)s_No_more_window_procedures_for_su_0046e920);
        return local_2c;
      }
      DAT_00489248 = DAT_00489248 + 1;
      (&DAT_00489254)[iVar2] = LVar5;
    }
    SetWindowLongA(pHVar4,-4,(LONG)(&PTR_LAB_0046e900)[iVar6]);
  }
  return local_2c;
}


