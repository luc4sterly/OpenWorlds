// 004160b3 FUN_004160b3 [Global]
// programa: sfmain.exe

undefined4 FUN_004160b3(HWND param_1,uint param_2,uint param_3,ushort param_4)

{
  HWND pHVar1;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  int iVar2;
  
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      lParam = 0;
      wParam = 0x100;
      Msg = 0xc5;
      pHVar1 = GetDlgItem(param_1,0xc1d);
      SendMessageA(pHVar1,Msg,wParam,lParam);
      iVar2 = 0;
      pHVar1 = GetDlgItem(param_1,0x3f4);
      ShowWindow(pHVar1,iVar2);
      iVar2 = 5;
      pHVar1 = GetDlgItem(param_1,0x3f7);
      ShowWindow(pHVar1,iVar2);
      iVar2 = 0;
      pHVar1 = GetDlgItem(param_1,0x3f6);
      ShowWindow(pHVar1,iVar2);
    }
  }
  else if (param_2 < 0x112) {
    FUN_00415dec(param_3 >> 0x10,(int)(short)param_3);
  }
  else if (param_2 == 0x465) {
    FUN_00415cfa((uint)param_4,param_3);
  }
  return 0;
}


