// 00422307 FUN_00422307 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall
FUN_00422307(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,undefined4 param_5)

{
  ULONG_PTR dwData;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar1;
  UINT uCommand;
  ushort local_1c;
  uint local_18;
  
  if (0x10f < param_4) {
    if (param_4 < 0x111) {
      CheckDlgButton(param_3,0x412,DAT_00462678);
      CheckDlgButton(param_3,0x413,DAT_00462788);
      local_18 = (uint)(DAT_0046267c == '\0');
      _DAT_004b2c00 = local_18;
      if (local_18 == 0) {
        SetDlgItemTextA(param_3,0x40d,&DAT_0046267c);
      }
      else {
        uVar1 = FUN_00429192(extraout_ECX,extraout_EDX);
        SetDlgItemTextA(param_3,0x40d,(LPCSTR)uVar1);
      }
      SetDlgItemTextA(param_3,0x40e,&DAT_0045e280);
      SetDlgItemTextA(param_3,0x40f,&DAT_0045e230);
      SetDlgItemTextA(param_3,0x410,&DAT_0045e2d0);
      SetDlgItemTextA(param_3,0x411,&DAT_0045e320);
    }
    else if (param_4 == 0x111) {
      local_1c = (ushort)param_5;
      if (local_1c < 2) {
        if (local_1c == 1) {
          if ((DAT_0043d610 != 0) && (DAT_0043d61c == 0)) {
            FUN_00421f22(param_1,1);
            DAT_0043d610 = 0;
          }
          DAT_00462678 = IsDlgButtonChecked(param_3,0x412);
          DAT_00462788 = IsDlgButtonChecked(param_3,0x413);
          if (_DAT_004b2c00 == 0) {
            GetDlgItemTextA(param_3,0x40d,&DAT_0046267c,0x104);
          }
          GetDlgItemTextA(param_3,0x40e,&DAT_0045e280,0x50);
          GetDlgItemTextA(param_3,0x40f,&DAT_0045e230,0x50);
          GetDlgItemTextA(param_3,0x410,&DAT_0045e2d0,0x50);
          GetDlgItemTextA(param_3,0x411,&DAT_0045e320,0x50);
          uVar1 = FUN_0042212e(extraout_ECX_00,extraout_EDX_00);
          if ((int)uVar1 != 0) {
            EndDialog(param_3,1);
          }
        }
      }
      else if (local_1c < 3) {
        EndDialog(param_3,0);
      }
      else if (0x40c < local_1c) {
        if (local_1c < 0x40e) {
          if ((short)((uint)param_5 >> 0x10) == 0x300) {
            _DAT_004b2c00 = 0;
          }
        }
        else if (local_1c == 0xfffd) {
          uVar1 = FUN_00429192(param_1,param_2);
          dwData = (ULONG_PTR)uVar1;
          uCommand = 0x101;
          uVar1 = FUN_00429192(extraout_ECX_01,(int)((ulonglong)uVar1 >> 0x20));
          WinHelpA(DAT_004627d0,(LPCSTR)uVar1,uCommand,dwData);
          DAT_0043d608 = 1;
        }
      }
    }
  }
  return 0;
}


