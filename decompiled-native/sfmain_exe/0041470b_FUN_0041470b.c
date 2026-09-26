// 0041470b FUN_0041470b [Global]
// programa: sfmain.exe

undefined4 __fastcall
FUN_0041470b(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,undefined4 param_5)

{
  char *pcVar1;
  undefined4 uVar2;
  HGLOBAL hMem;
  LRESULT LVar3;
  HWND pHVar4;
  int iVar5;
  LPCSTR pCVar6;
  uint uVar7;
  LRESULT LVar8;
  ULONG_PTR dwData;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar9;
  BOOL BVar10;
  UINT uCommand;
  undefined4 uVar11;
  WPARAM local_3a8;
  BOOL local_3a4;
  uint local_3a0;
  uint local_394;
  WPARAM local_38c;
  int local_37c;
  ushort local_374 [128];
  BOOL local_274;
  LPVOID local_270;
  undefined1 *local_26c;
  char *local_268;
  char local_264 [280];
  WPARAM local_14c;
  int local_148;
  undefined4 local_144;
  WPARAM local_140;
  uint local_13c;
  uint local_138;
  CHAR local_134 [280];
  int local_1c;
  HWND local_18;
  
  if (0x10f < param_4) {
    if (param_4 < 0x111) {
      local_18 = GetDlgItem(param_3,0x3fa);
      for (local_1c = 0; local_1c < DAT_0043d650; local_1c = local_1c + 1) {
        if (*(int *)(&DAT_0045e370 + local_1c * 4) == 0) {
          pcVar1 = (char *)Ordinal_11(*(undefined4 *)(&DAT_0045e3c0 + local_1c * 4));
          FUN_0042c5c6(extraout_ECX,pcVar1);
        }
        else {
          uVar9 = Ordinal_11(*(undefined4 *)(&DAT_0045e3c0 + local_1c * 4));
          uVar11 = (undefined4)uVar9;
          uVar2 = *(undefined4 *)(&DAT_0045e370 + local_1c * 4);
          uVar9 = FUN_00429192(extraout_ECX_00,(int)((ulonglong)uVar9 >> 0x20));
          wsprintfA(local_134,(LPCSTR)uVar9,uVar2,uVar11);
        }
        SendMessageA(local_18,0x180,0,(LPARAM)local_134);
      }
      if (DAT_0043d650 < 1) {
        local_140 = 0xffffffff;
      }
      else {
        local_140 = 0;
      }
      SendMessageA(local_18,0x186,local_140,0);
      CheckDlgButton(param_3,0x400,DAT_0043d654);
      local_13c = (uint)(DAT_0043d658 == 0);
      uVar7 = local_13c;
      pHVar4 = GetDlgItem(param_3,0x400);
      EnableWindow(pHVar4,uVar7);
      local_138 = (uint)(0 < DAT_0043d650);
      uVar7 = local_138;
      pHVar4 = GetDlgItem(param_3,0x3fd);
      EnableWindow(pHVar4,uVar7);
      BVar10 = 0;
      pHVar4 = GetDlgItem(param_3,0x3fc);
      EnableWindow(pHVar4,BVar10);
    }
    else if (param_4 == 0x111) {
      local_144 = param_5;
      uVar2 = local_144;
      local_144._0_2_ = (ushort)param_5;
      local_144 = uVar2;
      if ((ushort)local_144 < 0x3fc) {
        if ((ushort)local_144 != 0) {
          if ((ushort)local_144 < 2) {
            FUN_00417943(param_1,0);
            DAT_0043d654 = IsDlgButtonChecked(param_3,0x400);
            local_148 = SendDlgItemMessageA(param_3,0x3fa,0x18b,0,0);
            uVar2 = extraout_ECX_01;
            for (local_14c = 0; (int)local_14c < local_148; local_14c = local_14c + 1) {
              SendDlgItemMessageA(param_3,0x3fa,0x189,local_14c,(LPARAM)local_264);
              iVar5 = FUN_0042cbb3(extraout_ECX_02,'(');
              if (iVar5 == 0) {
                local_268 = local_264;
              }
              else {
                local_268 = (char *)(iVar5 + 1);
                local_26c = (undefined1 *)FUN_0042cbb3(extraout_ECX_03,')');
                if (local_26c != (undefined1 *)0x0) {
                  *local_26c = 0;
                }
              }
              uVar2 = Ordinal_10(local_268);
              *(undefined4 *)(&DAT_0045e3c0 + local_14c * 4) = uVar2;
              *(undefined4 *)(&DAT_0045e370 + local_14c * 4) = 0;
              uVar2 = extraout_ECX_04;
              if (local_264 < local_268) {
                local_268[-2] = '\0';
                iVar5 = FUN_0042c5ad();
                hMem = GlobalAlloc(0x40,iVar5 + 1);
                local_270 = GlobalLock(hMem);
                uVar2 = extraout_ECX_05;
                if (local_270 != (LPVOID)0x0) {
                  FUN_0042c5c6(extraout_ECX_05,local_264);
                  *(LPVOID *)(&DAT_0045e370 + local_14c * 4) = local_270;
                  uVar2 = extraout_ECX_06;
                }
              }
            }
            DAT_0043d650 = local_148;
            FUN_00417943(uVar2,1);
            EndDialog(param_3,1);
          }
          else if ((ushort)local_144 == 2) {
            EndDialog(param_3,0);
          }
        }
      }
      else if ((ushort)local_144 < 0x3fd) {
        local_374[0] = 0x100;
        LVar3 = SendDlgItemMessageA(param_3,0x3ff,0xc4,0,(LPARAM)local_374);
        *(undefined1 *)((int)local_374 + LVar3) = 0;
        local_37c = Ordinal_10(local_374);
        if (local_37c == -1) {
          iVar5 = Ordinal_52(local_374);
          if (iVar5 == 0) {
            Ordinal_111();
            uVar9 = FUN_00429482(extraout_ECX_07,extraout_EDX);
            uVar9 = FUN_00429192(extraout_ECX_08,(int)((ulonglong)uVar9 >> 0x20));
            FUN_00429268(extraout_ECX_09,(int)((ulonglong)uVar9 >> 0x20),0x338,
                         s__GAMMA_speakfre_sfmain_DIALOGS_c_00435fc3,8,param_3,0x10,(LPCSTR)uVar9);
            local_374[0] = local_374[0] & 0xff00;
          }
          else {
            local_37c = *(int *)**(undefined4 **)(iVar5 + 0xc);
            uVar9 = Ordinal_11(local_37c);
            uVar2 = (undefined4)uVar9;
            uVar9 = FUN_00429192(extraout_ECX_10,(int)((ulonglong)uVar9 >> 0x20));
            pCVar6 = (LPCSTR)uVar9;
            iVar5 = FUN_0042c5ad();
            wsprintfA((LPSTR)((int)local_374 + iVar5),pCVar6,uVar2);
          }
        }
        if (((char)local_374[0] != '\0') &&
           (uVar7 = Ordinal_14(local_37c), (uVar7 & 0xf0000000) != 0xe0000000)) {
          Ordinal_11(local_37c);
          uVar9 = FUN_00429192(extraout_ECX_11,extraout_EDX_00);
          FUN_00429268(extraout_ECX_12,(int)((ulonglong)uVar9 >> 0x20),0x344,
                       s__GAMMA_speakfre_sfmain_DIALOGS_c_00435fe4,8,param_3,0x10,(LPCSTR)uVar9);
          local_374[0] = local_374[0] & 0xff00;
        }
        if ((char)local_374[0] != '\0') {
          SetDlgItemTextA(param_3,0x3ff,&DAT_00436005);
          local_38c = SendDlgItemMessageA(param_3,0x3fa,0x1a2,0xffffffff,(LPARAM)local_374);
          if (local_38c == 0xffffffff) {
            local_38c = SendDlgItemMessageA(param_3,0x3fa,0x180,0,(LPARAM)local_374);
            LVar3 = SendDlgItemMessageA(param_3,0x3fa,0x18b,0,0);
            local_394 = (uint)(0 < LVar3);
            pHVar4 = GetDlgItem(param_3,0x3fd);
            EnableWindow(pHVar4,local_394);
            BVar10 = 0;
            pHVar4 = GetDlgItem(param_3,0x3fc);
            EnableWindow(pHVar4,BVar10);
          }
          if (local_38c != 0xffffffff) {
            SendDlgItemMessageA(param_3,0x3fa,0x186,local_38c,0);
          }
        }
        pHVar4 = GetDlgItem(param_3,0x3ff);
        SetFocus(pHVar4);
      }
      else if ((ushort)local_144 < 0x3ff) {
        if (((ushort)local_144 == 0x3fd) &&
           (local_3a8 = SendDlgItemMessageA(param_3,0x3fa,0x188,0,0), local_3a8 != 0xffffffff)) {
          SendDlgItemMessageA(param_3,0x3fa,0x182,local_3a8,0);
          LVar3 = SendDlgItemMessageA(param_3,0x3fa,0x18b,0,0);
          local_3a0 = (uint)(0 < LVar3);
          pHVar4 = GetDlgItem(param_3,0x3fd);
          EnableWindow(pHVar4,local_3a0);
          if ((LVar3 < 0x14) && (LVar8 = SendDlgItemMessageA(param_3,0x3ff,0xc1,0,0), 0 < LVar8)) {
            local_3a4 = 1;
          }
          else {
            local_3a4 = 0;
          }
          pHVar4 = GetDlgItem(param_3,0x3fc);
          EnableWindow(pHVar4,local_3a4);
          if (LVar3 <= (int)local_3a8) {
            local_3a8 = LVar3 - 1;
          }
          SendDlgItemMessageA(param_3,0x3fa,0x186,local_3a8,0);
        }
      }
      else if ((ushort)local_144 < 0x400) {
        if ((short)((uint)param_5 >> 0x10) == 0x300) {
          if ((DAT_0043d650 < 0x14) &&
             (LVar3 = SendDlgItemMessageA(param_3,0x3ff,0xc1,0,0), 0 < LVar3)) {
            local_274 = 1;
          }
          else {
            local_274 = 0;
          }
          BVar10 = local_274;
          pHVar4 = GetDlgItem(param_3,0x3fc);
          EnableWindow(pHVar4,BVar10);
        }
      }
      else if ((ushort)local_144 == 0xfffd) {
        uVar9 = FUN_00429192(param_1,param_2);
        dwData = (ULONG_PTR)uVar9;
        uCommand = 0x101;
        uVar9 = FUN_00429192(extraout_ECX_13,(int)((ulonglong)uVar9 >> 0x20));
        WinHelpA(DAT_004627d0,(LPCSTR)uVar9,uCommand,dwData);
        DAT_0043d608 = 1;
      }
    }
  }
  return 0;
}


