// 00416adb FUN_00416adb [Global]
// programa: sfmain.exe

undefined4 __fastcall
FUN_00416adb(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,void *param_5)

{
  void *pvVar1;
  BOOL BVar2;
  ULONG_PTR UVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined8 uVar4;
  UINT UVar5;
  char local_26c [260];
  CHAR local_168 [260];
  DWORD local_64;
  HWND local_60;
  LPCSTR local_58;
  LPSTR local_54;
  CHAR *local_48;
  DWORD local_44;
  LPCSTR local_38;
  LPCSTR local_34;
  DWORD local_30;
  void *local_18;
  
  if (param_4 < 0x110) {
    if (param_4 == 0x10) {
      DestroyWindow(param_3);
      return 1;
    }
  }
  else {
    if (param_4 < 0x111) {
      SetDlgItemTextA(param_3,0x418,&DAT_0043d404);
      CheckDlgButton(param_3,0x41a,DAT_0043d508);
      return 1;
    }
    if (param_4 == 0x111) {
      local_18 = param_5;
      pvVar1 = local_18;
      local_18._0_2_ = (ushort)param_5;
      local_18 = pvVar1;
      if ((ushort)local_18 < 0x419) {
        if ((ushort)local_18 != 0) {
          if ((ushort)local_18 < 2) {
            FUN_0042c5c6(param_1,&DAT_0043d404);
            GetDlgItemTextA(param_3,0x418,&DAT_0043d404,0x104);
            uVar4 = FUN_004168f4(extraout_ECX_03,extraout_EDX_01);
            if ((int)uVar4 == 0) {
              FUN_0042c5c6(extraout_ECX_04,local_26c);
            }
            else {
              DAT_0043d508 = IsDlgButtonChecked(param_3,0x41a);
              EndDialog(param_3,1);
            }
          }
          else if ((ushort)local_18 == 2) {
            EndDialog(param_3,0);
          }
        }
      }
      else if ((ushort)local_18 < 0x41a) {
        FUN_00408098(param_1,0);
        local_64 = 0x4c;
        local_60 = param_3;
        uVar4 = FUN_00429216(extraout_ECX,extraout_EDX);
        local_58 = (LPCSTR)uVar4;
        local_54 = (LPSTR)0x0;
        FUN_0042c5c6(extraout_ECX_00,&DAT_0043d404);
        local_48 = local_168;
        local_44 = 0x104;
        local_38 = (LPCSTR)0x0;
        uVar4 = FUN_00429192(extraout_ECX_01,extraout_EDX_00);
        local_34 = (LPCSTR)uVar4;
        local_30 = 0x1014;
        uVar4 = FUN_00429192(extraout_ECX_02,(int)((ulonglong)uVar4 >> 0x20));
        DAT_0043d64c = (ULONG_PTR)uVar4;
        BVar2 = GetOpenFileNameA((LPOPENFILENAMEA)&local_64);
        if (BVar2 != 0) {
          SetDlgItemTextA(param_3,0x418,local_168);
        }
      }
      else if (0x41a < (ushort)local_18) {
        if ((ushort)local_18 < 0x41c) {
          SetDlgItemTextA(param_3,0x418,&DAT_004360d9);
        }
        else if ((ushort)local_18 == 0xfffd) {
          uVar4 = FUN_00429192(param_1,param_2);
          UVar3 = (ULONG_PTR)uVar4;
          UVar5 = 0x101;
          uVar4 = FUN_00429192(extraout_ECX_05,(int)((ulonglong)uVar4 >> 0x20));
          WinHelpA(DAT_004627d0,(LPCSTR)uVar4,UVar5,UVar3);
          DAT_0043d608 = 1;
        }
      }
      return 0;
    }
  }
  if ((param_4 == DAT_004627b8) && (DAT_0043d64c != 0)) {
    UVar5 = 0x101;
    UVar3 = DAT_0043d64c;
    uVar4 = FUN_00429192(param_1,param_2);
    WinHelpA(DAT_004627d0,(LPCSTR)uVar4,UVar5,UVar3);
    DAT_0043d608 = 1;
  }
  return 0;
}


