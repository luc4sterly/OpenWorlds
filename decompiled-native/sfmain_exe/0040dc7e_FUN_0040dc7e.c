// 0040dc7e FUN_0040dc7e [Global]
// program: sfmain.exe

undefined4 __fastcall
FUN_0040dc7e(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,void *param_5)

{
  void *pvVar1;
  HGLOBAL pvVar2;
  ULONG_PTR UVar3;
  int iVar4;
  DWORD DVar5;
  HWND pHVar6;
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
  undefined4 extraout_ECX_14;
  undefined4 extraout_ECX_15;
  undefined4 extraout_ECX_16;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined8 uVar7;
  UINT UVar8;
  uint uVar9;
  BOOL BVar10;
  uint local_2c4;
  uint local_2c0;
  uint local_2bc;
  int local_2b8;
  CHAR local_2b4 [24];
  undefined4 local_29c;
  undefined4 local_294;
  char local_290 [256];
  undefined4 local_190;
  int local_18c;
  DWORD local_188;
  uint local_184;
  BOOL local_180;
  BOOL local_17c;
  CHAR local_178 [260];
  tagOFNA local_74;
  uint local_1c;
  UINT local_18;
  
  if (param_4 < 0x110) {
    if (1 < param_4) {
      if (param_4 < 3) {
        if (DAT_00445b28 != 0) {
          KillTimer(param_3,5);
        }
        if (DAT_004393b0 != (LPCVOID)0x0) {
          pvVar2 = GlobalHandle(DAT_004393b0);
          GlobalUnlock(pvVar2);
          pvVar2 = GlobalHandle(DAT_004393b0);
          GlobalFree(pvVar2);
          DAT_004393b0 = (LPCVOID)0x0;
        }
        DAT_0043d640 = (HWND)0x0;
        return 0;
      }
      if (param_4 == 0x10) {
        DestroyWindow(param_3);
        return 1;
      }
    }
LAB_0040e807:
    if ((param_4 == DAT_004627b8) && (DAT_0043d64c != 0)) {
      UVar8 = 0x101;
      UVar3 = DAT_0043d64c;
      uVar7 = FUN_00429192(param_1,param_2);
      WinHelpA(DAT_004627d0,(LPCSTR)uVar7,UVar8,UVar3);
      DAT_0043d608 = 1;
    }
    return 0;
  }
  if (param_4 < 0x111) {
    DAT_00445b28 = 0;
    DAT_004393b4 = 0x32;
    pvVar2 = GlobalAlloc(0x40,200);
    DAT_004393b0 = GlobalLock(pvVar2);
    if (DAT_004393b0 == (LPVOID)0x0) {
      uVar7 = FUN_00429192(extraout_ECX,extraout_EDX);
      FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar7 >> 0x20),0xea,
                   s__GAMMA_speakfre_sfmain_ANSWER_c_00435ac4,1,param_3,0x30,(LPCSTR)uVar7);
      DestroyWindow(param_3);
    }
    DAT_0043d640 = param_3;
    FUN_0040dbe2();
    pvVar1 = local_74.pvReserved;
  }
  else {
    if (0x111 < param_4) {
      if (param_4 == 0x113) {
        local_188 = GetTickCount();
        local_18c = 0;
        if (DAT_00445b28 != 0) {
          local_190 = DAT_00445b20;
          iVar4 = FUN_0040daee(&DAT_00445b58,&local_294);
          if (iVar4 == 0) {
            DAT_00445b28 = 0;
            local_18c = 1;
          }
          else if ((DAT_00445b2c == 0) && ((DAT_00445b5b & 1) != 0)) {
            DAT_00445b20 = local_190;
            DAT_00445b28 = 0;
          }
          else {
            DAT_00445b2c = 0;
            FUN_004264cf(DAT_004627b0,0,DAT_0043d6b0);
            if (DAT_00445b30 == 0) {
              if (local_290[0] != '(') {
                DAT_00445b30 = 1;
                DAT_00445b34 = 0;
              }
              if (DAT_00445b34 == 0) {
                uVar7 = FUN_0042c9fc(extraout_ECX_14,extraout_EDX_07);
                local_29c = (undefined4)uVar7;
                uVar7 = FUN_00429192(extraout_ECX_15,(int)((ulonglong)uVar7 >> 0x20));
                uVar7 = FUN_00429192(extraout_ECX_16,(int)((ulonglong)uVar7 >> 0x20));
                FUN_0042ca26((int)local_2b4,(byte *)uVar7);
                SetDlgItemTextA(param_3,0x404,local_2b4);
                SetDlgItemTextA(param_3,0x405,local_290);
                DAT_00445b34 = 1;
              }
            }
            DVar5 = GetTickCount();
            local_2b8 = DAT_00445b6c * 0x7d + -30000 + (DVar5 - local_188) * -1000;
            if (local_2b8 < 1) {
              local_2b8 = 1;
            }
            SetTimer(param_3,5,local_2b8 / 1000,(TIMERPROC)0x0);
          }
        }
        if (DAT_00445b28 != 0) {
          return 0;
        }
        FUN_0040dbb9();
        KillTimer(param_3,5);
        local_2bc = (uint)(0 < DAT_00445b24);
        pHVar6 = GetDlgItem(param_3,0x409);
        EnableWindow(pHVar6,local_2bc);
        local_2c0 = (uint)(local_18c == 0);
        pHVar6 = GetDlgItem(param_3,0x408);
        EnableWindow(pHVar6,local_2c0);
        local_2c4 = (uint)(-1 < DAT_00445b24);
        pHVar6 = GetDlgItem(param_3,0x40e);
        EnableWindow(pHVar6,local_2c4);
        BVar10 = 1;
        pHVar6 = GetDlgItem(param_3,0x403);
        EnableWindow(pHVar6,BVar10);
        BVar10 = 1;
        pHVar6 = GetDlgItem(param_3,0x402);
        EnableWindow(pHVar6,BVar10);
        BVar10 = 1;
        pHVar6 = GetDlgItem(param_3,0x406);
        EnableWindow(pHVar6,BVar10);
        if (DAT_00445b38 != 0) {
          pHVar6 = GetDlgItem(param_3,DAT_00445b38);
          BVar10 = IsWindowEnabled(pHVar6);
          if (BVar10 == 0) {
            pHVar6 = GetDlgItem(param_3,0x408);
            BVar10 = IsWindowEnabled(pHVar6);
            if (BVar10 == 0) {
              pHVar6 = GetDlgItem(param_3,0x409);
              BVar10 = IsWindowEnabled(pHVar6);
              if (BVar10 == 0) {
                pHVar6 = GetDlgItem(param_3,0x40e);
                BVar10 = IsWindowEnabled(pHVar6);
                if (BVar10 == 0) {
                  DAT_00445b38 = 1;
                }
                else {
                  DAT_00445b38 = 0x40e;
                }
              }
              else {
                DAT_00445b38 = 0x409;
              }
            }
            else {
              DAT_00445b38 = 0x408;
            }
          }
        }
        pHVar6 = GetDlgItem(param_3,DAT_00445b38);
        SetFocus(pHVar6);
        return 0;
      }
      goto LAB_0040e807;
    }
    local_74.pvReserved = param_5;
    pvVar1 = local_74.pvReserved;
    local_74.pvReserved._0_2_ = (ushort)param_5;
    local_74.pvReserved = pvVar1;
    if (0x407 < (ushort)local_74.pvReserved) {
      if ((ushort)local_74.pvReserved < 0x409) {
        DAT_00445b24 = DAT_00445b24 + 1;
      }
      else if ((ushort)local_74.pvReserved < 0x40a) {
        DAT_00445b24 = DAT_00445b24 + -1;
      }
      else {
        if ((ushort)local_74.pvReserved < 0x40b) {
          DAT_004393a0 = IsDlgButtonChecked(param_3,0x40a);
          return 0;
        }
        if ((ushort)local_74.pvReserved < 0x40e) {
          return 0;
        }
        if (0x40e < (ushort)local_74.pvReserved) {
          if ((ushort)local_74.pvReserved != 0xfffd) {
            return 0;
          }
          uVar7 = FUN_00429192(param_1,param_2);
          UVar3 = (ULONG_PTR)uVar7;
          UVar8 = 0x101;
          uVar7 = FUN_00429192(extraout_ECX_13,(int)((ulonglong)uVar7 >> 0x20));
          WinHelpA(DAT_004627d0,(LPCSTR)uVar7,UVar8,UVar3);
          DAT_0043d608 = 1;
          return 0;
        }
      }
      FUN_0040d5fb(param_1,param_2);
      DAT_00445b38 = (uint)param_5 & 0xffff;
      uVar7 = FUN_0041aa9b(extraout_ECX_02,extraout_EDX_01);
      if ((int)uVar7 != 0) {
        FUN_0040daca(extraout_ECX_03,(int)((ulonglong)uVar7 >> 0x20));
        DAT_00445b20 = *(undefined4 *)(DAT_00445b24 * 4 + (int)DAT_004393b0);
        BVar10 = 0;
        pHVar6 = GetDlgItem(param_3,0x409);
        EnableWindow(pHVar6,BVar10);
        BVar10 = 0;
        pHVar6 = GetDlgItem(param_3,0x408);
        EnableWindow(pHVar6,BVar10);
        BVar10 = 0;
        pHVar6 = GetDlgItem(param_3,0x40e);
        EnableWindow(pHVar6,BVar10);
        BVar10 = 0;
        pHVar6 = GetDlgItem(param_3,0x402);
        EnableWindow(pHVar6,BVar10);
        BVar10 = 0;
        pHVar6 = GetDlgItem(param_3,0x403);
        EnableWindow(pHVar6,BVar10);
        BVar10 = 0;
        pHVar6 = GetDlgItem(param_3,0x406);
        EnableWindow(pHVar6,BVar10);
        DAT_00445b28 = 1;
        DAT_00445b2c = 1;
        DAT_00445b34 = 0;
        DAT_00445b30 = 0;
        SetTimer(param_3,5,1,(TIMERPROC)0x0);
      }
      return 0;
    }
    if ((ushort)local_74.pvReserved < 0x402) {
      if ((ushort)local_74.pvReserved != 1) {
        return 0;
      }
      DAT_004393a0 = IsDlgButtonChecked(param_3,0x40a);
      PostMessageA(param_3,0x10,0,0);
      return 0;
    }
    if ((ushort)local_74.pvReserved < 0x403) {
      FUN_0042c83b(param_1,param_2);
      DAT_004393a4 = FUN_0042c438(extraout_ECX_04,&DAT_00435ac0);
      DAT_004393b8 = 0;
      DAT_00445b1c = 0;
      pvVar1 = local_74.pvReserved;
    }
    else if (0x403 < (ushort)local_74.pvReserved) {
      if ((ushort)local_74.pvReserved != 0x406) {
        return 0;
      }
      FUN_00408098(param_1,0);
      local_74.lStructSize = 0x4c;
      local_74.hwndOwner = param_3;
      uVar7 = FUN_00429216(extraout_ECX_05,extraout_EDX_02);
      local_74.lpstrFilter = (LPCSTR)uVar7;
      local_74.lpstrCustomFilter = (LPSTR)0x0;
      FUN_0042c5c6(extraout_ECX_06,&DAT_0043929c);
      local_74.lpstrFile = local_178;
      local_74.nMaxFile = 0x104;
      local_74.lpstrInitialDir = (LPCSTR)0x0;
      uVar7 = FUN_00429192(extraout_ECX_07,extraout_EDX_03);
      local_74.lpstrTitle = (LPCSTR)uVar7;
      local_74.Flags = 0x8014;
      uVar7 = FUN_00429192(extraout_ECX_08,(int)((ulonglong)uVar7 >> 0x20));
      DAT_0043d64c = (ULONG_PTR)uVar7;
      BVar10 = GetOpenFileNameA(&local_74);
      if (BVar10 == 0) {
        return 0;
      }
      SetDlgItemTextA(param_3,0x407,local_178);
      FUN_0042c5c6(extraout_ECX_09,local_178);
      FUN_0040da98(extraout_ECX_10,extraout_EDX_04);
      FUN_0040d772(extraout_ECX_11,extraout_EDX_05);
      DAT_00445b24 = 0xffffffff;
      FUN_0040dbe2();
      BVar10 = 0;
      pHVar6 = GetDlgItem(param_3,0x409);
      EnableWindow(pHVar6,BVar10);
      BVar10 = 0;
      pHVar6 = GetDlgItem(param_3,0x403);
      EnableWindow(pHVar6,BVar10);
      BVar10 = 0;
      pHVar6 = GetDlgItem(param_3,0x40e);
      EnableWindow(pHVar6,BVar10);
      if ((DAT_004393a4 == 0) || (DAT_004393b8 < 1)) {
        local_17c = 0;
      }
      else {
        local_17c = 1;
      }
      BVar10 = local_17c;
      pHVar6 = GetDlgItem(param_3,0x408);
      EnableWindow(pHVar6,BVar10);
      if ((DAT_004393a4 == 0) || (DAT_00445b1c < 1)) {
        local_180 = 0;
      }
      else {
        local_180 = 1;
      }
      BVar10 = local_180;
      pHVar6 = GetDlgItem(param_3,0x402);
      EnableWindow(pHVar6,BVar10);
      local_184 = (uint)(DAT_004393a4 != 0);
      uVar9 = local_184;
      pHVar6 = GetDlgItem(param_3,0x40a);
      EnableWindow(pHVar6,uVar9);
      SetDlgItemTextA(param_3,0x405,&DAT_00435ae4);
      SetDlgItemTextA(param_3,0x404,&DAT_00435ae4);
      FUN_0040d5fb(extraout_ECX_12,extraout_EDX_06);
      return 0;
    }
  }
  local_74.pvReserved = pvVar1;
  BVar10 = 0;
  pHVar6 = GetDlgItem(param_3,0x409);
  EnableWindow(pHVar6,BVar10);
  BVar10 = 0;
  pHVar6 = GetDlgItem(param_3,0x40e);
  EnableWindow(pHVar6,BVar10);
  BVar10 = 0;
  pHVar6 = GetDlgItem(param_3,0x403);
  EnableWindow(pHVar6,BVar10);
  if ((DAT_004393a4 == 0) || (DAT_004393b8 < 1)) {
    local_74.dwReserved = 0;
  }
  else {
    local_74.dwReserved = 1;
  }
  DVar5 = local_74.dwReserved;
  pHVar6 = GetDlgItem(param_3,0x408);
  EnableWindow(pHVar6,DVar5);
  if ((DAT_004393a4 == 0) || (DAT_00445b1c < 1)) {
    local_74.FlagsEx = 0;
  }
  else {
    local_74.FlagsEx = 1;
  }
  DVar5 = local_74.FlagsEx;
  pHVar6 = GetDlgItem(param_3,0x402);
  EnableWindow(pHVar6,DVar5);
  local_1c = (uint)(DAT_004393a4 != 0);
  uVar9 = local_1c;
  pHVar6 = GetDlgItem(param_3,0x40a);
  EnableWindow(pHVar6,uVar9);
  if ((DAT_004393a4 == 0) || (DAT_004393a0 == 0)) {
    local_18 = 0;
  }
  else {
    local_18 = 1;
  }
  CheckDlgButton(param_3,0x40a,local_18);
  SetDlgItemTextA(param_3,0x407,&DAT_0043929c);
  SetDlgItemTextA(param_3,0x405,&DAT_00435ae4);
  SetDlgItemTextA(param_3,0x404,&DAT_00435ae4);
  DAT_00445b24 = 0xffffffff;
  DAT_00445b38 = 0;
  FUN_0040d5fb(extraout_ECX_01,extraout_EDX_00);
  return 1;
}


