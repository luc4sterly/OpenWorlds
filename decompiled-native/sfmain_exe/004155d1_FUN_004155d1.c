// 004155d1 FUN_004155d1 [Global]
// programa: sfmain.exe

undefined4 __fastcall
FUN_004155d1(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,short param_5)

{
  ULONG_PTR dwData;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar1;
  UINT uCommand;
  CHAR local_68 [80];
  LPCSTR local_18;
  
  if (param_4 < 0x10) {
    if (param_4 == 2) {
      DAT_0043d634 = (HWND)0x0;
      return 0;
    }
  }
  else {
    if (param_4 < 0x11) {
      DestroyWindow(param_3);
      return 1;
    }
    if (0x10f < param_4) {
      if (param_4 < 0x111) {
        wsprintfA(local_68,&DAT_00436006,DAT_0043d704);
        SetDlgItemTextA(param_3,0x3fb,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6b4);
        SetDlgItemTextA(param_3,0x3fd,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6b8);
        SetDlgItemTextA(param_3,0x3fe,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004623a8);
        SetDlgItemTextA(param_3,0x1779,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004623ac);
        SetDlgItemTextA(param_3,0x177a,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004623b4);
        SetDlgItemTextA(param_3,0x177b,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004623b8);
        SetDlgItemTextA(param_3,0x177c,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_00462568);
        SetDlgItemTextA(param_3,0x1783,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004623c4);
        SetDlgItemTextA(param_3,0x1787,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004623d0);
        SetDlgItemTextA(param_3,0x1789,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004623d4);
        SetDlgItemTextA(param_3,0x1786,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004623c8);
        SetDlgItemTextA(param_3,0x1788,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6bc);
        SetDlgItemTextA(param_3,0x400,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6c4);
        SetDlgItemTextA(param_3,0x177d,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004627a4);
        SetDlgItemTextA(param_3,0x177e,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6c0);
        SetDlgItemTextA(param_3,0x3ff,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6cc);
        SetDlgItemTextA(param_3,0x407,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6c8);
        SetDlgItemTextA(param_3,0x409,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_00462554);
        SetDlgItemTextA(param_3,6000,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_00462558);
        SetDlgItemTextA(param_3,0x1771,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6dc);
        SetDlgItemTextA(param_3,0x1773,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6e8);
        SetDlgItemTextA(param_3,0x1774,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6ec);
        SetDlgItemTextA(param_3,0x1775,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6f4);
        SetDlgItemTextA(param_3,0x1776,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6f0);
        SetDlgItemTextA(param_3,0x1777,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d6f8);
        SetDlgItemTextA(param_3,0x1778,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_004623a4);
        SetDlgItemTextA(param_3,0x1780,local_68);
        wsprintfA(local_68,&DAT_00436006,DAT_0043d65c);
        SetDlgItemTextA(param_3,0x1793,local_68);
        if (DAT_0043d590 == 0) {
          uVar1 = FUN_00429192(extraout_ECX,extraout_EDX);
          local_18 = (LPCSTR)uVar1;
        }
        else {
          uVar1 = FUN_00429192(extraout_ECX,extraout_EDX);
          local_18 = (LPCSTR)uVar1;
        }
        SetDlgItemTextA(param_3,0x408,local_18);
        DAT_0043d634 = param_3;
        FUN_004152eb(extraout_ECX_00,extraout_EDX_00);
        return 1;
      }
      if (param_4 == 0x111) {
        if (-4 < param_5) {
          if (param_5 < -2) {
            uVar1 = FUN_00429192(param_1,param_2);
            dwData = (ULONG_PTR)uVar1;
            uCommand = 0x101;
            uVar1 = FUN_00429192(extraout_ECX_01,(int)((ulonglong)uVar1 >> 0x20));
            WinHelpA(DAT_004627d0,(LPCSTR)uVar1,uCommand,dwData);
            DAT_0043d608 = 1;
          }
          else if (param_5 == 1) {
            PostMessageA(param_3,0x10,0,0);
          }
        }
        return 1;
      }
    }
  }
  return 0;
}


