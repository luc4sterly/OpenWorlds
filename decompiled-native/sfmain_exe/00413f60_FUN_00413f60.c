// 00413f60 FUN_00413f60 [Global]
// program: sfmain.exe

undefined4 __fastcall
FUN_00413f60(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,short param_5)

{
  HWND pHVar1;
  uint uVar2;
  int iVar3;
  ULONG_PTR UVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_EDX;
  undefined8 uVar5;
  UINT UVar6;
  CHAR local_a4 [132];
  uint local_20;
  uint local_1c;
  int local_18;
  
  local_18 = DAT_00459de8;
  if (0x10f < param_4) {
    if (param_4 < 0x111) {
      GetWindowTextA(param_3,local_a4,0x84);
      FUN_0042caa9(extraout_ECX,&DAT_00435f9e);
      FUN_0042caa9(extraout_ECX_00,(char *)(local_18 + 0x2c));
      SetWindowTextA(param_3,local_a4);
      CheckDlgButton(param_3,0x3ef,*(UINT *)(local_18 + 0x4c44));
      CheckDlgButton(param_3,0x3f0,*(UINT *)(local_18 + 0x4c4c));
      SetDlgItemTextA(param_3,0x3e9,(LPCSTR)(local_18 + 0x684));
      SetDlgItemTextA(param_3,0x3ea,(LPCSTR)(local_18 + 0x79f));
      SetDlgItemTextA(param_3,0x3ec,(LPCSTR)(local_18 + 0xbea));
      SetDlgItemTextA(param_3,0x3ed,(LPCSTR)(local_18 + 0x9d5));
      CheckDlgButton(param_3,0x3f1,*(UINT *)(local_18 + 0x4c50));
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x421);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x3e9);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x422);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x3ea);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x425);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x3ec);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x423);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x3ed);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x424);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x3f1);
      ShowWindow(pHVar1,iVar3);
      iVar3 = 0;
      pHVar1 = GetDlgItem(param_3,0x3eb);
      ShowWindow(pHVar1,iVar3);
      uVar2 = Ordinal_14(*(undefined4 *)(local_18 + 0x18));
      local_20 = (uint)((uVar2 & 0xf0000000) == 0xe0000000);
      uVar2 = local_20;
      pHVar1 = GetDlgItem(param_3,0x3fd);
      EnableWindow(pHVar1,uVar2);
      uVar2 = Ordinal_14(*(undefined4 *)(local_18 + 0x18));
      local_1c = (uint)((uVar2 & 0xf0000000) == 0xe0000000);
      uVar2 = local_1c;
      pHVar1 = GetDlgItem(param_3,0x3fe);
      EnableWindow(pHVar1,uVar2);
      uVar2 = Ordinal_14(*(undefined4 *)(local_18 + 0x18));
      if ((uVar2 & 0xf0000000) != 0xe0000000) {
        return 0;
      }
      SetDlgItemInt(param_3,0x3fd,*(UINT *)(local_18 + 0x4c38),0);
      return 0;
    }
    if (param_4 == 0x111) {
      if (param_5 < 1) {
        if (param_5 != -3) {
          return 0;
        }
        uVar5 = FUN_00429192(param_1,param_2);
        UVar4 = (ULONG_PTR)uVar5;
        UVar6 = 0x101;
        uVar5 = FUN_00429192(extraout_ECX_04,(int)((ulonglong)uVar5 >> 0x20));
        WinHelpA(DAT_004627d0,(LPCSTR)uVar5,UVar6,UVar4);
        DAT_0043d608 = 1;
        return 0;
      }
      if (1 < param_5) {
        if (param_5 != 2) {
          return 0;
        }
        EndDialog(param_3,0);
        return 0;
      }
      UVar6 = GetDlgItemInt(param_3,0x3fd,(BOOL *)0x0,0);
      if (0xff < UVar6) {
        uVar5 = FUN_00429192(extraout_ECX_01,extraout_EDX);
        FUN_00429268(extraout_ECX_02,(int)((ulonglong)uVar5 >> 0x20),0x16a,
                     s__GAMMA_speakfre_sfmain_DIALOGS_c_00435fa2,8,param_3,0x30,(LPCSTR)uVar5);
        return 1;
      }
      UVar6 = IsDlgButtonChecked(param_3,0x3ef);
      *(UINT *)(local_18 + 0x4c44) = UVar6;
      UVar6 = IsDlgButtonChecked(param_3,0x3f0);
      *(UINT *)(local_18 + 0x4c4c) = UVar6;
      GetDlgItemTextA(param_3,0x3e9,(LPSTR)(local_18 + 0x684),0x100);
      GetDlgItemTextA(param_3,0x3ea,(LPSTR)(local_18 + 0x79f),0x100);
      GetDlgItemTextA(param_3,0x3ec,(LPSTR)(local_18 + 0xbea),0x104);
      GetDlgItemTextA(param_3,0x3ed,(LPSTR)(local_18 + 0x9d5),0x100);
      UVar6 = GetDlgItemInt(param_3,0x3fd,(BOOL *)0x0,0);
      *(UINT *)(local_18 + 0x4c38) = UVar6;
      UVar6 = IsDlgButtonChecked(param_3,0x3f1);
      iVar3 = local_18;
      *(UINT *)(local_18 + 0x4c50) = UVar6;
      GetParent(param_3);
      iVar3 = FUN_00413e00(extraout_ECX_03,iVar3);
      if (iVar3 == 0) {
        return 0;
      }
      EndDialog(param_3,1);
      return 0;
    }
  }
  if ((param_4 == DAT_004627b8) && (DAT_0043d64c != 0)) {
    UVar6 = 0x101;
    UVar4 = DAT_0043d64c;
    uVar5 = FUN_00429192(param_1,param_2);
    WinHelpA(DAT_004627d0,(LPCSTR)uVar5,UVar6,UVar4);
    DAT_0043d608 = 1;
  }
  return 0;
}


