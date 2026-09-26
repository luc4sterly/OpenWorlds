// 004190b8 FUN_004190b8 [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004190b8(undefined4 param_1,undefined4 param_2)

{
  short sVar1;
  HWND in_EAX;
  uint uVar2;
  HMENU hMenu;
  UINT_PTR UVar3;
  HGDIOBJ h;
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
  undefined4 extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  int iVar7;
  undefined4 uVar8;
  short *psVar9;
  short local_200 [196];
  ushort local_78;
  tagTEXTMETRICA local_70;
  HMENU local_38;
  undefined4 local_34;
  HWND local_30;
  int local_2c;
  HDC local_28;
  undefined4 local_24;
  HGDIOBJ local_20;
  uint local_1c;
  undefined4 local_18;
  
  psVar9 = local_200;
  uVar8 = 0x101;
  local_30 = in_EAX;
  local_24 = param_2;
  uVar5 = Ordinal_115(0x101,psVar9);
  iVar7 = (int)((ulonglong)uVar5 >> 0x20);
  local_2c = (int)uVar5;
  if (local_2c == 0) {
    if (local_200[0] == 0) {
      uVar5 = FUN_00429192(extraout_ECX,iVar7);
      FUN_00429268(extraout_ECX_02,(int)((ulonglong)uVar5 >> 0x20),0x6e3,
                   s__GAMMA_speakfre_sfmain_FRAME_c_0043643a,0xe,(HWND)0x0,0x10,(LPCSTR)uVar5);
      local_18 = 0xffffffff;
    }
    else {
      _DAT_0043d6d0 = (uint)local_78;
      uVar5 = FUN_00429192(extraout_ECX,iVar7);
      uVar2 = FUN_0042cc60(extraout_ECX_03,(uint *)uVar5);
      uVar2 = (uint)(uVar2 == 0);
      local_1c = uVar2;
      _DAT_004623e0 = GetTickCount();
      if ((DAT_0043d708 != 0) && (DAT_0043d564 != 0)) {
        DAT_0043d560 = 1;
        DAT_0043d564 = 0;
      }
      FUN_0041fe4c(extraout_ECX_04,extraout_EDX);
      sVar1 = Ordinal_9(0x81e,uVar8,psVar9,uVar2);
      Ordinal_8(0);
      local_2c = FUN_00429545(sVar1,2);
      if (local_2c == 0) {
        sVar1 = Ordinal_9(0x81f);
        Ordinal_8(0);
        local_2c = FUN_00429545(sVar1,2);
        if (local_2c == 0) {
          DAT_0043d54c = LoadCursorA(DAT_004627bc,(LPCSTR)0x66);
          DAT_0043d554 = LoadCursorA(DAT_004627bc,(LPCSTR)0x67);
          DAT_0043d550 = LoadCursorA(DAT_004627bc,(LPCSTR)0x73);
          DAT_004627b8 = RegisterWindowMessageA(s_commdlg_help_00436497);
          uVar5 = FUN_004078ca(extraout_ECX_11,extraout_EDX_02);
          DAT_0043d548 = (undefined4)uVar5;
          uVar5 = FUN_0040205c(extraout_ECX_12,(int)((ulonglong)uVar5 >> 0x20));
          uVar8 = (undefined4)((ulonglong)uVar5 >> 0x20);
          if ((int)uVar5 == 0) {
            uVar5 = FUN_00429192(extraout_ECX_13,uVar8);
            FUN_00429268(extraout_ECX_14,(int)((ulonglong)uVar5 >> 0x20),0x72a,
                         s__GAMMA_speakfre_sfmain_FRAME_c_004364a4,1,(HWND)0x0,0x10,(LPCSTR)uVar5);
            local_18 = 0xffffffff;
          }
          else {
            FUN_0040196c(extraout_ECX_13,uVar8);
            FUN_0040a948();
            FUN_00413aeb(extraout_ECX_15,1);
            FUN_004080a4(extraout_ECX_16,&DAT_00462e76);
            FUN_004080a4(extraout_ECX_17,&DAT_00462e7a);
            FUN_004080a4(extraout_ECX_18,&DAT_00462e7e);
            FUN_004080a4(extraout_ECX_19,&DAT_00462e80);
            iVar7 = 3;
            hMenu = GetMenu(local_30);
            local_38 = GetSubMenu(hMenu,iVar7);
            local_34 = 0x838;
            if (_DAT_004b2c70 == 0) {
              DAT_004627c8 = CreateWindowExA(0x80,_DAT_004b2be0,(LPCSTR)0x0,0x42300000,0,0,0,0,
                                             local_30,(HMENU)0x0,DAT_004627bc,&local_38);
            }
            else {
              DAT_004627c8 = CreateWindowExA(0,_DAT_004b2be0,(LPCSTR)0x0,0x42300000,0,0,0,0,local_30
                                             ,(HMENU)0x0,DAT_004627bc,&local_38);
            }
            if (DAT_004627c8 == (HWND)0x0) {
              local_18 = 0xffffffff;
            }
            else {
              ShowWindow(DAT_004627c8,5);
              uVar5 = FUN_00429192(extraout_ECX_20,extraout_EDX_03);
              FUN_0042c5c6(extraout_ECX_21,(char *)uVar5);
              DAT_0043d590 = DAT_0043d598;
              iVar7 = FUN_0041fa28(extraout_ECX_22,&DAT_00462e86);
              if (iVar7 == 0) {
                uVar5 = FUN_00417d56(extraout_ECX_23,extraout_EDX_04);
                DAT_0043d5f8 = (int)uVar5;
                if ((DAT_0043d5f8 == 0) && (DAT_0043d70c == 0)) {
                  UVar3 = SetTimer(local_30,1,1000,(TIMERPROC)0x0);
                  if (UVar3 == 0) {
                    uVar5 = FUN_00429192(extraout_ECX_25,extraout_EDX_05);
                    FUN_00429268(extraout_ECX_26,(int)((ulonglong)uVar5 >> 0x20),0x84c,
                                 s__GAMMA_speakfre_sfmain_FRAME_c_0043653a,2,(HWND)0x0,0x10,
                                 (LPCSTR)uVar5);
                    local_18 = 0xffffffff;
                  }
                  else {
                    UVar3 = SetTimer(local_30,9,10000,(TIMERPROC)0x0);
                    if (UVar3 == 0) {
                      FUN_00429268(extraout_ECX_27,extraout_EDX_06,0x854,
                                   s__GAMMA_speakfre_sfmain_FRAME_c_00436575,2,(HWND)0x0,0x10,
                                   s_Can_t_create_watchdog_timer_00436559);
                      local_18 = 0xffffffff;
                    }
                    else {
                      uVar5 = FUN_0041848a(extraout_ECX_27,extraout_EDX_06);
                      DAT_0046239c = (undefined4)uVar5;
                      uVar5 = FUN_004182e8(extraout_ECX_28,(int)((ulonglong)uVar5 >> 0x20));
                      DAT_004627ac = (undefined4)uVar5;
                      DAT_00462398 = DAT_0046239c;
                      local_28 = GetDC(local_30);
                      h = GetStockObject(0xc);
                      local_20 = SelectObject(local_28,h);
                      GetTextMetricsA(local_28,&local_70);
                      SelectObject(local_28,local_20);
                      ReleaseDC(local_30,local_28);
                      DAT_004627b4 = local_70.tmAveCharWidth;
                      DAT_004627c4 = local_70.tmHeight;
                      DAT_0043d638 = FUN_004155d1;
                      DAT_0043d644 = FUN_0040dc7e;
                      DragAcceptFiles(local_30,1);
                      uVar8 = extraout_ECX_29;
                      uVar4 = extraout_EDX_07;
                      if (DAT_0043929c != '\0') {
                        uVar5 = FUN_0040d772(extraout_ECX_29,extraout_EDX_07);
                        uVar4 = (undefined4)((ulonglong)uVar5 >> 0x20);
                        uVar8 = extraout_ECX_30;
                      }
                      uVar5 = FUN_004168f4(uVar8,uVar4);
                      FUN_0042212e(extraout_ECX_31,(int)((ulonglong)uVar5 >> 0x20));
                      uVar6 = Ordinal_101(DAT_0043d66c,local_30,0x464,1);
                      uVar5 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),local_2c);
                      uVar8 = extraout_ECX_32;
                      if ((int)uVar6 != 0) {
                        uVar5 = Ordinal_111();
                        uVar8 = extraout_ECX_33;
                      }
                      local_2c = (int)uVar5;
                      if (local_2c != 0) {
                        uVar5 = FUN_00429482(uVar8,(int)((ulonglong)uVar5 >> 0x20));
                        uVar5 = FUN_00429192(extraout_ECX_34,(int)((ulonglong)uVar5 >> 0x20));
                        FUN_00429268(extraout_ECX_35,(int)((ulonglong)uVar5 >> 0x20),0x88b,
                                     s__GAMMA_speakfre_sfmain_FRAME_c_00436594,3,(HWND)0x0,0x10,
                                     (LPCSTR)uVar5);
                      }
                      uVar6 = Ordinal_101(DAT_0043d670,local_30,0x467,1);
                      uVar5 = CONCAT44((int)((ulonglong)uVar6 >> 0x20),local_2c);
                      uVar8 = extraout_ECX_36;
                      if ((int)uVar6 != 0) {
                        uVar5 = Ordinal_111();
                        uVar8 = extraout_ECX_37;
                      }
                      local_2c = (int)uVar5;
                      if (local_2c != 0) {
                        uVar5 = FUN_00429482(uVar8,(int)((ulonglong)uVar5 >> 0x20));
                        uVar5 = FUN_00429192(extraout_ECX_38,(int)((ulonglong)uVar5 >> 0x20));
                        FUN_00429268(extraout_ECX_39,(int)((ulonglong)uVar5 >> 0x20),0x892,
                                     s__GAMMA_speakfre_sfmain_FRAME_c_004365b3,3,(HWND)0x0,0x10,
                                     (LPCSTR)uVar5);
                      }
                      DAT_0043d680 = 1;
                      local_18 = 1;
                    }
                  }
                }
                else {
                  FUN_00429268(extraout_ECX_24,(int)((ulonglong)uVar5 >> 0x20),0x844,
                               s__GAMMA_speakfre_sfmain_FRAME_c_0043651b,0xf,(HWND)0x0,0x10,
                               s_Device_driver_for_sound_card_doe_004364e2);
                  local_18 = 0xffffffff;
                }
              }
              else {
                FUN_00429268(extraout_ECX_23,extraout_EDX_04,0x837,
                             s__GAMMA_speakfre_sfmain_FRAME_c_004364c3,0x15,(HWND)0x0,0,
                             &DAT_00462e86);
                local_18 = 0xffffffff;
              }
            }
          }
        }
        else {
          uVar5 = FUN_00429482(extraout_ECX_08,extraout_EDX_01);
          uVar5 = FUN_00429192(extraout_ECX_09,(int)((ulonglong)uVar5 >> 0x20));
          FUN_00429268(extraout_ECX_10,(int)((ulonglong)uVar5 >> 0x20),0x714,
                       s__GAMMA_speakfre_sfmain_FRAME_c_00436478,3,(HWND)0x0,0x10,(LPCSTR)uVar5);
          local_18 = 0xffffffff;
        }
      }
      else {
        uVar5 = FUN_00429482(extraout_ECX_05,extraout_EDX_00);
        uVar5 = FUN_00429192(extraout_ECX_06,(int)((ulonglong)uVar5 >> 0x20));
        FUN_00429268(extraout_ECX_07,(int)((ulonglong)uVar5 >> 0x20),0x70d,
                     s__GAMMA_speakfre_sfmain_FRAME_c_00436459,3,(HWND)0x0,0x10,(LPCSTR)uVar5);
        local_18 = 0xffffffff;
      }
    }
  }
  else {
    uVar5 = FUN_00429482(extraout_ECX,iVar7);
    uVar5 = FUN_00429192(extraout_ECX_00,(int)((ulonglong)uVar5 >> 0x20));
    FUN_00429268(extraout_ECX_01,(int)((ulonglong)uVar5 >> 0x20),0x6dd,
                 s__GAMMA_speakfre_sfmain_FRAME_c_0043641b,2,(HWND)0x0,0x10,(LPCSTR)uVar5);
    local_18 = 0xffffffff;
  }
  return local_18;
}


