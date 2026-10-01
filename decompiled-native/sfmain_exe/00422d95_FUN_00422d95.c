// 00422d95 FUN_00422d95 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall
FUN_00422d95(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,undefined4 param_5)

{
  short sVar1;
  CHAR *pCVar2;
  HWND pHVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  LPCSTR pCVar7;
  HGLOBAL pvVar8;
  undefined4 uVar9;
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
  undefined4 extraout_ECX_14;
  undefined4 extraout_ECX_15;
  undefined4 extraout_ECX_16;
  undefined4 extraout_ECX_17;
  undefined4 extraout_ECX_18;
  undefined4 extraout_ECX_19;
  undefined4 extraout_ECX_20;
  undefined4 extraout_ECX_21;
  undefined4 extraout_ECX_22;
  undefined4 extraout_ECX_23;
  undefined4 extraout_ECX_24;
  undefined4 extraout_ECX_25;
  undefined4 extraout_ECX_26;
  undefined4 extraout_ECX_27;
  undefined4 extraout_ECX_28;
  undefined4 extraout_ECX_29;
  undefined4 extraout_ECX_30;
  undefined4 extraout_ECX_31;
  undefined4 extraout_ECX_32;
  undefined4 extraout_ECX_33;
  undefined4 extraout_ECX_34;
  undefined4 extraout_ECX_35;
  undefined4 extraout_ECX_36;
  undefined4 extraout_ECX_37;
  undefined4 extraout_ECX_38;
  undefined4 extraout_ECX_39;
  undefined4 extraout_ECX_40;
  undefined4 extraout_ECX_41;
  undefined4 extraout_ECX_42;
  undefined4 extraout_ECX_43;
  undefined4 extraout_ECX_44;
  undefined4 extraout_ECX_45;
  undefined4 extraout_ECX_46;
  undefined4 extraout_ECX_47;
  undefined4 extraout_ECX_48;
  undefined4 extraout_ECX_49;
  undefined4 extraout_ECX_50;
  undefined4 extraout_ECX_51;
  undefined4 extraout_ECX_52;
  undefined4 extraout_ECX_53;
  undefined4 extraout_ECX_54;
  undefined4 extraout_ECX_55;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 uVar10;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  undefined4 extraout_EDX_10;
  undefined4 extraout_EDX_11;
  undefined4 extraout_EDX_12;
  undefined8 uVar11;
  undefined8 uVar12;
  BOOL BVar13;
  UINT UVar14;
  code *pcVar15;
  CHAR local_568 [256];
  char *local_468;
  undefined4 local_460;
  LPCVOID local_454;
  char *local_43c;
  undefined1 local_438;
  int local_434;
  undefined4 *local_430;
  int local_42c;
  undefined4 local_428;
  int local_424;
  undefined4 local_420;
  undefined4 local_41c;
  undefined4 local_418;
  int local_414;
  int local_410;
  int local_40c;
  undefined2 local_408;
  undefined2 local_406;
  int local_404;
  CHAR *local_3f8;
  byte *local_3f4;
  byte local_3f0 [2];
  short local_3ee;
  undefined4 local_3ec [2];
  CHAR local_3e4 [500];
  CHAR local_1f0 [44];
  undefined4 local_1c4;
  LPCSTR local_1b8;
  int local_1b4;
  uint local_1b0;
  CHAR local_1ac [44];
  undefined4 local_180;
  int local_174;
  CHAR local_170 [256];
  undefined4 local_70;
  CHAR local_6c [84];
  int local_18;
  
  if (0x10f < param_4) {
    if (param_4 < 0x111) {
      CheckDlgButton(param_3,0x415,DAT_00462674);
      if (DAT_00462570 == '\0') {
        if (DAT_0046267c == '\0') {
          uVar12 = FUN_00429192(extraout_ECX,extraout_EDX);
          uVar9 = (undefined4)uVar12;
          uVar12 = FUN_00429192(extraout_ECX_00,(int)((ulonglong)uVar12 >> 0x20));
          wsprintfA(local_6c,(LPCSTR)uVar12,uVar9);
        }
        else {
          pcVar5 = &DAT_0046267c;
          uVar12 = FUN_00429192(extraout_ECX,extraout_EDX);
          wsprintfA(local_6c,(LPCSTR)uVar12,pcVar5);
        }
        SetDlgItemTextA(param_3,0x413,local_6c);
      }
      else {
        SetDlgItemTextA(param_3,0x413,&DAT_00462570);
      }
      DAT_0043d7e0 = -1;
      if (DAT_0043d7dc == (code *)0x0) {
        DAT_0043d7dc = FUN_00421e6f;
      }
      iVar4 = -4;
      pHVar3 = GetDlgItem(param_3,0x413);
      DAT_0043d7d8 = GetWindowLongA(pHVar3,iVar4);
      iVar4 = -4;
      pcVar15 = DAT_0043d7dc;
      pHVar3 = GetDlgItem(param_3,0x413);
      SetWindowLongA(pHVar3,iVar4,(LONG)pcVar15);
      iVar4 = -4;
      pcVar15 = DAT_0043d7dc;
      pHVar3 = GetDlgItem(param_3,0x414);
      SetWindowLongA(pHVar3,iVar4,(LONG)pcVar15);
      BVar13 = 0;
      pHVar3 = GetDlgItem(param_3,3);
      EnableWindow(pHVar3,BVar13);
      _DAT_004b2bf8 = (undefined4 *)0x0;
      FUN_00422903(extraout_ECX_01);
    }
    else if (param_4 == 0x111) {
      local_70 = param_5;
      uVar9 = local_70;
      local_70._0_2_ = (ushort)param_5;
      local_70 = uVar9;
      if ((ushort)local_70 < 4) {
        if ((ushort)local_70 < 2) {
          if ((ushort)local_70 == 1) {
            DAT_00462674 = IsDlgButtonChecked(param_3,0x415);
            GetDlgItemTextA(param_3,0x413,&DAT_00462570,0x104);
            if (DAT_00462570 == '(') {
              DAT_00462570 = '\0';
            }
            FUN_004227fb();
            EndDialog(param_3,1);
          }
        }
        else if ((ushort)local_70 < 3) {
          FUN_004227fb();
          EndDialog(param_3,0);
        }
        else if (-1 < DAT_0043d7e0) {
          uVar12 = FUN_00422837(param_1,param_2);
          local_174 = (int)uVar12;
          if (local_174 != 0) {
            local_180 = *(undefined4 *)(local_174 + 0xc);
            uVar12 = Ordinal_11(local_180,*(undefined2 *)(local_174 + 0x10));
            uVar9 = (undefined4)uVar12;
            uVar12 = FUN_00429192(extraout_ECX_02,(int)((ulonglong)uVar12 >> 0x20));
            wsprintfA(local_1ac,(LPCSTR)uVar12,uVar9);
            FUN_00418c25(extraout_ECX_03,0);
            PostMessageA(param_3,0x111,1,0);
          }
        }
      }
      else if ((ushort)local_70 < 5) {
        local_3f4 = local_3f0;
        SendDlgItemMessageA(param_3,0x416,0x184,0,0);
        uVar12 = FUN_00429192(extraout_ECX_07,extraout_EDX_02);
        SendDlgItemMessageA(param_3,0x416,0x180,0,(LPARAM)uVar12);
        GetDlgItemTextA(param_3,0x413,(LPSTR)local_3f0,0x200);
        if (local_3f0[0] == 0x28) {
          local_3f4 = local_3f4 + 1;
          local_3f8 = (CHAR *)FUN_0042cbb3(extraout_ECX_08,')');
          if (local_3f8 != (undefined1 *)0x0) {
            *local_3f8 = 0;
          }
        }
        local_408 = 2;
        local_406 = Ordinal_9(0x820);
        local_404 = Ordinal_10(local_3f4);
        FUN_0042287e(extraout_ECX_09,0);
        uVar9 = extraout_ECX_10;
        uVar10 = extraout_EDX_03;
        if (local_404 == -1) {
          local_40c = Ordinal_52(local_3f4);
          if (local_40c == 0) {
            uVar12 = Ordinal_111();
            local_410 = (int)uVar12;
            if (local_410 != 0x2714) {
              uVar12 = FUN_00429482(extraout_ECX_12,(int)((ulonglong)uVar12 >> 0x20));
              uVar12 = FUN_00429192(extraout_ECX_13,(int)((ulonglong)uVar12 >> 0x20));
              FUN_00429268(extraout_ECX_14,(int)((ulonglong)uVar12 >> 0x20),0x2a8,
                           s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,param_3,0x10,(LPCSTR)uVar12)
              ;
            }
            SendDlgItemMessageA(param_3,0x416,0x184,0,0);
            FUN_0042287e(extraout_ECX_15,1);
            return 0;
          }
          FUN_004080a4(extraout_ECX_11,(undefined1 *)**(undefined4 **)(local_40c + 0xc));
          uVar9 = extraout_ECX_16;
          uVar10 = extraout_EDX_04;
        }
        uVar12 = FUN_00429192(uVar9,uVar10);
        SendDlgItemMessageA(param_3,0x416,0x180,0,(LPARAM)uVar12);
        local_414 = Ordinal_23(2,1,0);
        if (local_414 == -1) {
          uVar12 = Ordinal_111();
          local_418 = (undefined4)uVar12;
          uVar12 = FUN_00429482(extraout_ECX_17,(int)((ulonglong)uVar12 >> 0x20));
          uVar12 = FUN_00429192(extraout_ECX_18,(int)((ulonglong)uVar12 >> 0x20));
          FUN_00429268(extraout_ECX_19,(int)((ulonglong)uVar12 >> 0x20),0x2bd,
                       s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,param_3,0x10,(LPCSTR)uVar12);
          SendDlgItemMessageA(param_3,0x416,0x184,0,0);
          FUN_0042287e(extraout_ECX_20,1);
        }
        else {
          uVar12 = Ordinal_4(local_414,&local_408,0x10);
          if ((int)uVar12 < 0) {
            uVar12 = Ordinal_111();
            local_41c = (undefined4)uVar12;
            uVar12 = FUN_00429482(extraout_ECX_22,(int)((ulonglong)uVar12 >> 0x20));
            uVar12 = FUN_00429192(extraout_ECX_23,(int)((ulonglong)uVar12 >> 0x20));
            FUN_00429268(extraout_ECX_24,(int)((ulonglong)uVar12 >> 0x20),0x2c7,
                         s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,param_3,0x10,(LPCSTR)uVar12);
            Ordinal_3(local_414);
            SendDlgItemMessageA(param_3,0x416,0x184,0,0);
            FUN_0042287e(extraout_ECX_25,1);
          }
          else {
            local_3f0[0] = 0xcc;
            local_3f0[1] = 0x81;
            local_3ec[0] = 0;
            uVar12 = FUN_00429192(extraout_ECX_21,(int)((ulonglong)uVar12 >> 0x20));
            FUN_004080a4(extraout_ECX_26,(undefined1 *)uVar12);
            local_3f8 = local_3e4;
            UVar14 = IsDlgButtonChecked(param_3,0x415);
            if (UVar14 != 0) {
              pCVar2 = local_3f8 + 1;
              *local_3f8 = '*';
              local_3f8 = pCVar2;
            }
            GetDlgItemTextA(param_3,0x414,local_3f8,0x200 - ((int)local_3f8 - (int)local_3f0));
            iVar4 = FUN_0042c5ad();
            local_3f8 = local_3f8 + iVar4 + 1;
            while (((uint)local_3f8 & 3) != 0) {
              *local_3f8 = '\0';
              local_3f8 = local_3f8 + 1;
            }
            iVar4 = (int)local_3f8 - (int)local_3f0 >> 0x1f;
            local_3ee = (short)((int)((((int)local_3f8 - (int)local_3f0) + iVar4 * -4) -
                                     (uint)(iVar4 << 1 < 0)) >> 2) + -1;
            FUN_00429618();
            FUN_00429618();
            uVar12 = FUN_00429192(extraout_ECX_27,extraout_EDX_05);
            SendDlgItemMessageA(param_3,0x416,0x180,0,(LPARAM)uVar12);
            FUN_0042c5ad();
            iVar4 = FUN_00429725();
            if (iVar4 < 0) {
              uVar12 = Ordinal_111();
              local_420 = (undefined4)uVar12;
              uVar12 = FUN_00429482(extraout_ECX_29,(int)((ulonglong)uVar12 >> 0x20));
              uVar12 = FUN_00429192(extraout_ECX_30,(int)((ulonglong)uVar12 >> 0x20));
              FUN_00429268(extraout_ECX_31,(int)((ulonglong)uVar12 >> 0x20),0x2e2,
                           s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,param_3,0x10,(LPCSTR)uVar12)
              ;
              Ordinal_3(local_414);
              SendDlgItemMessageA(param_3,0x416,0x184,0,0);
              FUN_0042287e(extraout_ECX_32,1);
            }
            else {
              uVar12 = FUN_00429192(extraout_ECX_28,extraout_EDX_06);
              SendDlgItemMessageA(param_3,0x416,0x180,0,(LPARAM)uVar12);
              local_424 = FUN_00429977();
              if (local_424 < 1) {
                uVar12 = Ordinal_111();
                local_428 = (undefined4)uVar12;
                uVar12 = FUN_00429482(extraout_ECX_33,(int)((ulonglong)uVar12 >> 0x20));
                uVar12 = FUN_00429192(extraout_ECX_34,(int)((ulonglong)uVar12 >> 0x20));
                FUN_00429268(extraout_ECX_35,(int)((ulonglong)uVar12 >> 0x20),0x2ee,
                             s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,param_3,0x10,
                             (LPCSTR)uVar12);
                Ordinal_3(local_414);
                SendDlgItemMessageA(param_3,0x416,0x184,0,0);
                FUN_0042287e(extraout_ECX_36,1);
              }
              else {
                Ordinal_3(local_414);
                FUN_0042287e(extraout_ECX_37,1);
                local_42c = (int)(char)(local_3f0[0] & 0x1f);
                SendDlgItemMessageA(param_3,0x416,0x184,0,0);
                FUN_004227fb();
                DAT_0043d7e0 = -1;
                for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
                  SetDlgItemTextA(param_3,local_18 + 0x417,&DAT_00437245);
                }
                BVar13 = 0;
                pHVar3 = GetDlgItem(param_3,3);
                EnableWindow(pHVar3,BVar13);
                local_3f8 = (CHAR *)local_3ec;
                while (0 < local_42c) {
                  local_42c = local_42c + -1;
                  pvVar8 = GlobalAlloc(0x40,0x2c);
                  local_430 = GlobalLock(pvVar8);
                  if (local_430 != (undefined4 *)0x0) {
                    local_434 = 1;
                    FUN_004080a4(extraout_ECX_38,local_3f8);
                    uVar12 = CONCAT44(extraout_EDX_07,local_43c);
                    local_3f8 = (CHAR *)((int)local_3f8 + 4);
                    uVar9 = extraout_ECX_39;
                    while( true ) {
                      uVar10 = (undefined4)((ulonglong)uVar12 >> 0x20);
                      local_43c = (char *)uVar12;
                      if (local_434 == 0) break;
                      local_438 = *local_3f8;
                      switch(local_438) {
                      case 0:
                        do {
                          local_3f8 = (CHAR *)((int)local_3f8 + 1);
                          uVar12 = CONCAT44((int)local_3f8 - (int)local_3f0,local_43c);
                        } while (((int)local_3f8 - (int)local_3f0 & 3U) != 0);
                        local_434 = 0;
                        break;
                      case 1:
                        uVar11 = FUN_0042260d(uVar9,uVar10);
                        uVar12 = CONCAT44((int)uVar11,local_43c);
                        local_430[5] = (int)uVar11;
                        uVar9 = extraout_ECX_40;
                        break;
                      case 2:
                        uVar11 = FUN_0042260d(uVar9,uVar10);
                        uVar12 = CONCAT44((int)uVar11,local_43c);
                        local_430[6] = (int)uVar11;
                        uVar9 = extraout_ECX_41;
                        break;
                      case 3:
                        uVar11 = FUN_0042260d(uVar9,uVar10);
                        uVar12 = CONCAT44((int)uVar11,local_43c);
                        local_430[7] = (int)uVar11;
                        uVar9 = extraout_ECX_42;
                        break;
                      case 4:
                        uVar11 = FUN_0042260d(uVar9,uVar10);
                        uVar12 = CONCAT44((int)uVar11,local_43c);
                        local_430[8] = (int)uVar11;
                        uVar9 = extraout_ECX_43;
                        break;
                      case 5:
                        uVar11 = FUN_0042260d(uVar9,uVar10);
                        uVar12 = CONCAT44((int)uVar11,local_43c);
                        local_430[9] = (int)uVar11;
                        uVar9 = extraout_ECX_44;
                        break;
                      case 6:
                        uVar11 = FUN_0042260d(uVar9,uVar10);
                        uVar12 = CONCAT44((int)uVar11,local_43c);
                        local_430[10] = (int)uVar11;
                        uVar9 = extraout_ECX_45;
                        break;
                      default:
                        uVar11 = FUN_0042260d(uVar9,uVar10);
                        uVar12 = CONCAT44((int)((ulonglong)uVar11 >> 0x20),local_43c);
                        local_454 = (LPCVOID)uVar11;
                        uVar9 = extraout_ECX_50;
                        if (local_454 != (LPCVOID)0x0) {
                          pvVar8 = GlobalHandle(local_454);
                          GlobalUnlock(pvVar8);
                          pvVar8 = GlobalHandle(local_454);
                          GlobalFree(pvVar8);
                          uVar12 = CONCAT44(extraout_EDX_11,local_43c);
                          uVar9 = extraout_ECX_51;
                        }
                        break;
                      case 8:
                        uVar12 = FUN_0042260d(uVar9,uVar10);
                        local_43c = (char *)uVar12;
                        uVar9 = extraout_ECX_46;
                        if (*local_43c != '\0') {
                          if ((*local_43c == '\x01') && (local_43c[1] == 'P')) {
                            FUN_0042c5c6(extraout_ECX_46,local_43c + 2);
                            uVar12 = FUN_0042cfc8(extraout_ECX_47,extraout_EDX_08);
                            *(short *)(local_430 + 4) = (short)uVar12;
                          }
                          else if ((*local_43c == '\x01') && (local_43c[1] == 'I')) {
                            uVar9 = Ordinal_10(local_43c + 2);
                            local_430[3] = uVar9;
                          }
                          else if ((*local_43c == '\x01') && (local_43c[1] == 'T')) {
                            FUN_0042c5c6(extraout_ECX_46,local_43c + 2);
                            uVar12 = FUN_0042cbc7(extraout_ECX_48,extraout_EDX_09);
                            local_430[1] = (int)uVar12;
                          }
                          pvVar8 = GlobalHandle(local_43c);
                          GlobalUnlock(pvVar8);
                          pvVar8 = GlobalHandle(local_43c);
                          GlobalFree(pvVar8);
                          uVar12 = CONCAT44(extraout_EDX_10,local_43c);
                          uVar9 = extraout_ECX_49;
                        }
                      }
                    }
                    local_460 = local_430[3];
                    if ((local_430[5] == 0) && (local_430[7] == 0)) {
                      FUN_00422689();
                    }
                    else {
                      if (local_430[7] == 0) {
                        local_468 = (char *)local_430[5];
                      }
                      else {
                        local_468 = (char *)local_430[7];
                      }
                      FUN_0042c5c6(uVar9,local_468);
                      uVar9 = extraout_ECX_52;
                      if (local_430[6] != 0) {
                        uVar9 = local_430[6];
                        uVar12 = FUN_00429192(extraout_ECX_52,extraout_EDX_12);
                        pCVar7 = (LPCSTR)uVar12;
                        iVar4 = FUN_0042c5ad();
                        wsprintfA(local_568 + iVar4,pCVar7,uVar9);
                        uVar9 = extraout_ECX_53;
                      }
                      if (local_430[9] != 0) {
                        FUN_0042caa9(uVar9,&DAT_00437246);
                        FUN_0042caa9(extraout_ECX_54,(char *)local_430[9]);
                      }
                      SendDlgItemMessageA(param_3,0x416,0x180,0,(LPARAM)local_568);
                      *local_430 = 0;
                      if (_DAT_004b2bf8 == (undefined4 *)0x0) {
                        _DAT_004b2bf8 = local_430;
                      }
                      else {
                        *_DAT_004b2bfc = local_430;
                      }
                      _DAT_004b2bfc = local_430;
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        sVar1 = (short)((uint)param_5 >> 0x10);
        if ((ushort)local_70 < 0x414) {
          if ((ushort)local_70 == 0x413) {
            if (sVar1 == 0x100) {
              _DAT_004b2c04 = 0;
            }
            else if (sVar1 == 0x300) {
              _DAT_004b2c04 = 1;
            }
            else if ((sVar1 == 0x7ea) || ((sVar1 == 0x200 && (_DAT_004b2c04 != 0)))) {
              _DAT_004b2c04 = 0;
              FUN_00422903(param_1);
            }
          }
        }
        else if ((ushort)local_70 < 0x415) {
          if (sVar1 == 0x100) {
            _DAT_004b2c04 = 0;
          }
          else if (sVar1 == 0x300) {
            _DAT_004b2c04 = 1;
          }
          else if ((sVar1 == 0x7ea) || ((sVar1 == 0x200 && (_DAT_004b2c04 != 0)))) {
            GetDlgItemTextA(param_3,0x414,local_170,0x100);
            iVar4 = FUN_0042c5ad();
            if (iVar4 != 0) {
              GetDlgItemTextA(param_3,0x413,local_170,0x100);
              iVar4 = FUN_0042c5ad();
              if (iVar4 != 0) {
                PostMessageA(param_3,0x111,4,0);
              }
            }
            _DAT_004b2c04 = 0;
          }
        }
        else if (0x415 < (ushort)local_70) {
          if ((ushort)local_70 < 0x417) {
            for (local_18 = 0; local_18 < 5; local_18 = local_18 + 1) {
              SetDlgItemTextA(param_3,local_18 + 0x417,&DAT_00437245);
            }
            if (sVar1 == 1) {
              if (_DAT_004b2bf8 == (undefined4 *)0x0) {
                DAT_0043d7e0 = -1;
                SendDlgItemMessageA(param_3,0x416,0x186,0xffffffff,0);
              }
              else {
                DAT_0043d7e0 = SendDlgItemMessageA(param_3,0x416,0x188,0,0);
              }
              if (DAT_0043d7e0 == -1) {
                DAT_0043d7e0 = -1;
              }
            }
            else if (sVar1 == 3) {
              DAT_0043d7e0 = -1;
            }
            local_1b0 = (uint)(-1 < DAT_0043d7e0);
            uVar6 = local_1b0;
            pHVar3 = GetDlgItem(param_3,3);
            EnableWindow(pHVar3,uVar6);
            if (-1 < DAT_0043d7e0) {
              uVar12 = FUN_00422837(extraout_ECX_04,extraout_EDX_00);
              local_1b4 = (int)uVar12;
              if (local_1b4 != 0) {
                local_18 = 0;
                if (*(int *)(local_1b4 + 0x18) != 0) {
                  local_18 = 1;
                  SetDlgItemTextA(param_3,0x417,*(LPCSTR *)(local_1b4 + 0x18));
                }
                if (*(int *)(local_1b4 + 0x1c) == 0) {
                  local_1b8 = *(LPCSTR *)(local_1b4 + 0x14);
                }
                else {
                  local_1b8 = *(LPCSTR *)(local_1b4 + 0x1c);
                }
                iVar4 = local_18 + 0x417;
                local_18 = local_18 + 1;
                SetDlgItemTextA(param_3,iVar4,local_1b8);
                if (*(int *)(local_1b4 + 0x24) != 0) {
                  iVar4 = local_18 + 0x417;
                  local_18 = local_18 + 1;
                  SetDlgItemTextA(param_3,iVar4,*(LPCSTR *)(local_1b4 + 0x24));
                }
                if (*(int *)(local_1b4 + 0x20) != 0) {
                  iVar4 = local_18 + 0x417;
                  local_18 = local_18 + 1;
                  SetDlgItemTextA(param_3,iVar4,*(LPCSTR *)(local_1b4 + 0x20));
                }
                local_1c4 = *(undefined4 *)(local_1b4 + 0xc);
                pcVar5 = (char *)Ordinal_11(local_1c4);
                FUN_0042c5c6(extraout_ECX_05,pcVar5);
                uVar6 = (uint)*(ushort *)(local_1b4 + 0x10);
                uVar12 = FUN_00429192(extraout_ECX_06,extraout_EDX_01);
                pCVar7 = (LPCSTR)uVar12;
                iVar4 = FUN_0042c5ad();
                wsprintfA(local_1f0 + iVar4,pCVar7,uVar6);
                iVar4 = local_18 + 0x417;
                local_18 = local_18 + 1;
                SetDlgItemTextA(param_3,iVar4,local_1f0);
              }
            }
          }
          else if ((ushort)local_70 == 0xfffd) {
            uVar12 = FUN_00429192(param_1,param_2);
            dwData = (ULONG_PTR)uVar12;
            UVar14 = 0x101;
            uVar12 = FUN_00429192(extraout_ECX_55,(int)((ulonglong)uVar12 >> 0x20));
            WinHelpA(DAT_004627d0,(LPCSTR)uVar12,UVar14,dwData);
            DAT_0043d608 = 1;
          }
        }
      }
    }
  }
  return 0;
}


