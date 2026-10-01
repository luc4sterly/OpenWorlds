// 0041652c FUN_0041652c [Global]
// program: sfmain.exe

undefined4 __fastcall
FUN_0041652c(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,undefined4 param_5,
            ushort param_6)

{
  HWND hWnd;
  ULONG_PTR dwData;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined8 uVar1;
  int nBar;
  int nMinPos;
  int nMaxPos;
  UINT uCommand;
  BOOL bRedraw;
  short local_18;
  
  if (param_4 < 0x10) {
    if (1 < param_4) {
      if (param_4 < 3) {
        DAT_0043d3ec = 0;
        return 0;
      }
      if (param_4 == 0xf) {
        GetDlgItem(param_3,0x41b);
        FUN_0041623c(extraout_ECX_01,1);
        return 0;
      }
    }
  }
  else {
    if (param_4 < 0x11) {
      DestroyWindow(param_3);
      return 1;
    }
    if (param_4 < 0x111) {
      if (param_4 == 0x110) {
        bRedraw = 1;
        nMaxPos = 1000;
        nMinPos = 0;
        nBar = 2;
        hWnd = GetDlgItem(param_3,0x41c);
        SetScrollRange(hWnd,nBar,nMinPos,nMaxPos,bRedraw);
        DAT_0043d3f0 = 0;
        DAT_0043d3f4 = DAT_0043d710 - 1;
        FUN_00416495();
        return 1;
      }
    }
    else {
      if (param_4 < 0x112) {
        local_18 = (short)param_5;
        if (-4 < local_18) {
          if (local_18 < -2) {
            uVar1 = FUN_00429192(param_1,param_2);
            dwData = (ULONG_PTR)uVar1;
            uCommand = 0x101;
            uVar1 = FUN_00429192(extraout_ECX_00,(int)((ulonglong)uVar1 >> 0x20));
            WinHelpA(DAT_004627d0,(LPCSTR)uVar1,uCommand,dwData);
            DAT_0043d608 = 1;
          }
          else if (local_18 == 1) {
            PostMessageA(param_3,0x10,0,0);
          }
        }
        return 1;
      }
      if (param_4 == 0x115) {
        switch(param_5) {
        case 0:
          DAT_0043d710 = DAT_0043d710 - 10;
          break;
        case 1:
          DAT_0043d710 = DAT_0043d710 + 10;
          break;
        case 2:
          DAT_0043d710 = DAT_0043d710 - 100;
          break;
        case 3:
          DAT_0043d710 = DAT_0043d710 + 100;
          break;
        case 4:
        case 5:
          DAT_0043d710 = (uint)param_6;
          break;
        case 6:
          DAT_0043d710 = 1000;
          break;
        case 7:
          DAT_0043d710 = 0;
        }
        if ((int)DAT_0043d710 < 0) {
          DAT_0043d710 = 0;
        }
        else if (1000 < (int)DAT_0043d710) {
          DAT_0043d710 = 1000;
        }
        FUN_00416495();
        if (DAT_0043d520 == 0) {
          GetDlgItem(param_3,0x41b);
          FUN_0041623c(extraout_ECX,1);
        }
        return 1;
      }
    }
  }
  return 0;
}


