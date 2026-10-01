// 0040e892 FUN_0040e892 [Global]
// program: sfmain.exe

undefined4 __fastcall
FUN_0040e892(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,undefined4 param_5)

{
  HWND pHVar1;
  HCURSOR pHVar2;
  DWORD DVar3;
  uint uVar4;
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
  undefined4 uVar5;
  undefined4 extraout_ECX_34;
  undefined4 extraout_ECX_35;
  undefined4 extraout_ECX_36;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar6;
  undefined8 uVar7;
  UINT uCommand;
  int iVar8;
  BOOL BVar9;
  undefined2 local_1ec [8];
  int local_1dc;
  int local_1d8;
  byte local_1d4 [36];
  short local_1b0 [160];
  int local_70;
  int local_6c;
  int local_68;
  short local_64 [2];
  uint local_60;
  byte *local_5c;
  byte *local_58;
  CHAR local_54 [20];
  int local_40;
  int local_3c;
  int local_38;
  DWORD local_34;
  int local_30;
  HCURSOR local_2c;
  byte *local_28;
  undefined *local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  
  if (0x10f < param_4) {
    if (param_4 < 0x111) {
      for (local_18 = 0x431; local_18 < 0x438; local_18 = local_18 + 1) {
        BVar9 = 0;
        pHVar1 = GetDlgItem(param_3,local_18);
        EnableWindow(pHVar1,BVar9);
      }
      BVar9 = 0;
      pHVar1 = GetDlgItem(param_3,0x449);
      EnableWindow(pHVar1,BVar9);
      BVar9 = 0;
      pHVar1 = GetDlgItem(param_3,0x44a);
      EnableWindow(pHVar1,BVar9);
      BVar9 = 0;
      pHVar1 = GetDlgItem(param_3,0x451);
      EnableWindow(pHVar1,BVar9);
      BVar9 = 0;
      pHVar1 = GetDlgItem(param_3,0x452);
      EnableWindow(pHVar1,BVar9);
      BVar9 = 0;
      pHVar1 = GetDlgItem(param_3,1099);
      EnableWindow(pHVar1,BVar9);
      BVar9 = 0;
      pHVar1 = GetDlgItem(param_3,0x44c);
      EnableWindow(pHVar1,BVar9);
      BVar9 = 0;
      pHVar1 = GetDlgItem(param_3,0x44d);
      EnableWindow(pHVar1,BVar9);
      BVar9 = 0;
      pHVar1 = GetDlgItem(param_3,0x44e);
      EnableWindow(pHVar1,BVar9);
      iVar8 = 0;
      pHVar1 = GetDlgItem(param_3,0x453);
      ShowWindow(pHVar1,iVar8);
      pHVar1 = GetDlgItem(param_3,0x430);
      SetFocus(pHVar1);
    }
    else if (param_4 == 0x111) {
      local_1c = param_5;
      uVar5 = local_1c;
      local_1c._0_2_ = (ushort)param_5;
      local_1c = uVar5;
      if ((ushort)local_1c < 0x430) {
        if (((ushort)local_1c != 0) && ((ushort)local_1c < 3)) {
          EndDialog(param_3,1);
        }
      }
      else if ((ushort)local_1c < 0x431) {
        iVar8 = 5;
        pHVar1 = GetDlgItem(param_3,0x453);
        ShowWindow(pHVar1,iVar8);
        iVar8 = 0;
        pHVar1 = GetDlgItem(param_3,0x430);
        ShowWindow(pHVar1,iVar8);
        BVar9 = 0;
        pHVar1 = GetDlgItem(param_3,1);
        EnableWindow(pHVar1,BVar9);
        pHVar1 = GetDlgItem(param_3,0x453);
        SetFocus(pHVar1);
        UpdateWindow(param_3);
        local_20 = FUN_0042ca56(extraout_ECX,0);
        if ((local_20 & 0x3f) != 0x3f) {
          FUN_00429268(extraout_ECX_00,extraout_EDX,0x4b,s__GAMMA_speakfre_sfmain_BENCH_c_00435b1e,2
                       ,param_3,0,s_Coprocessor_interrupt_mask_wrong_00435ae8);
          FUN_0042ca56(extraout_ECX_01,0x3f);
          local_20 = FUN_0042ca56(extraout_ECX_02,0);
          if ((local_20 & 0x3f) != 0x3f) {
            FUN_00429268(extraout_ECX_03,extraout_EDX_00,0x50,
                         s__GAMMA_speakfre_sfmain_BENCH_c_00435b76,2,param_3,0,
                         s_Could_not_reset_interrupt_mask__g_00435b3d);
          }
        }
        DAT_00445b3c = 0;
        local_24 = &DAT_00445b74;
        local_28 = &DAT_004461b4;
        pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
        local_2c = SetCursor(pHVar2);
        FUN_0042b966();
        uVar5 = extraout_ECX_04;
        uVar6 = extraout_EDX_01;
        for (local_30 = 0; local_30 < 0x640; local_30 = local_30 + 1) {
          uVar7 = FUN_0042b942(uVar5,uVar6);
          uVar6 = CONCAT31((int3)((ulonglong)uVar7 >> 0x28),(char)uVar7);
          local_24[local_30] = (char)uVar7;
          uVar5 = extraout_ECX_05;
        }
        local_34 = GetTickCount();
        local_38 = 0;
        local_3c = 1;
        uVar5 = extraout_ECX_06;
        while (local_3c != 0) {
          DVar3 = GetTickCount();
          uVar5 = extraout_ECX_07;
          if (3000 < DVar3 - local_34) {
            local_3c = 0;
            break;
          }
          for (local_40 = 0; local_40 < 800; local_40 = local_40 + 1) {
            local_28[local_40] = local_24[local_40 * 2];
          }
          local_38 = local_38 + 0x640;
        }
        uVar4 = (uint)(local_38 * 100) / 24000;
        uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
        wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
        SetDlgItemTextA(param_3,0x428,local_54);
        FUN_00424019();
        pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
        SetCursor(pHVar2);
        if (DAT_00445b3c == 0) {
          local_34 = GetTickCount();
          local_38 = 0;
          local_3c = 1;
          uVar5 = extraout_ECX_08;
          while (local_3c != 0) {
            DVar3 = GetTickCount();
            uVar5 = extraout_ECX_09;
            if (3000 < DVar3 - local_34) {
              local_3c = 0;
              break;
            }
            local_58 = local_28 + 800;
            local_5c = local_28;
            for (local_40 = 0; local_40 < 800; local_40 = local_40 + 1) {
              if (local_40 == 0) {
                local_60 = (uint)(char)*local_5c;
              }
              else {
                local_60 = (uint)(byte)(&DAT_00427192)
                                       [(int)(((*(int *)((uint)*local_5c * 2 + 0x426f90) >> 0x10) +
                                              (*(int *)((uint)local_5c[-1] * 2 + 0x426f90) >> 0x10))
                                              / 2 & 0xffffU) >> 3];
              }
              *local_58 = (byte)local_60;
              local_28[0x321] = *local_5c;
              local_5c = local_5c + 1;
            }
            local_38 = local_38 + 0x640;
          }
          uVar4 = (uint)(local_38 * 100) / 24000;
          uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
          wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
          SetDlgItemTextA(param_3,0x429,local_54);
          FUN_00424019();
          pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
          SetCursor(pHVar2);
          if (DAT_00445b3c == 0) {
            local_34 = GetTickCount();
            local_38 = 0;
            local_3c = 1;
            uVar5 = extraout_ECX_10;
            while (local_3c != 0) {
              DVar3 = GetTickCount();
              if (3000 < DVar3 - local_34) {
                local_3c = 0;
                uVar5 = extraout_ECX_11;
                break;
              }
              FUN_00401010(local_64,local_28);
              local_38 = local_38 + 0x640;
              uVar5 = extraout_ECX_12;
            }
            uVar4 = (uint)(local_38 * 100) / 24000;
            uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
            wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
            SetDlgItemTextA(param_3,0x42a,local_54);
            FUN_00424019();
            pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
            SetCursor(pHVar2);
            if (DAT_00445b3c == 0) {
              local_34 = GetTickCount();
              local_38 = 0;
              local_3c = 1;
              uVar5 = extraout_ECX_13;
              while (local_3c != 0) {
                DVar3 = GetTickCount();
                if (3000 < DVar3 - local_34) {
                  local_3c = 0;
                  uVar5 = extraout_ECX_14;
                  break;
                }
                FUN_00401170(local_64,local_24);
                local_38 = local_38 + 0x640;
                uVar5 = extraout_ECX_15;
              }
              uVar4 = (uint)(local_38 * 100) / 24000;
              uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
              wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
              SetDlgItemTextA(param_3,0x42b,local_54);
              FUN_00424019();
              pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
              SetCursor(pHVar2);
              if (DAT_00445b3c == 0) {
                local_34 = GetTickCount();
                local_38 = 0;
                local_3c = 1;
                uVar5 = extraout_ECX_16;
LAB_0040ef86:
                if (local_3c != 0) {
                  local_68 = 0;
                  for (local_6c = 0; local_6c < 0x640; local_6c = local_6c + 0xa0) {
                    DVar3 = GetTickCount();
                    if (3000 < DVar3 - local_34) {
                      local_3c = 0;
                      uVar5 = extraout_ECX_17;
                      break;
                    }
                    for (local_70 = 0; local_70 < 0xa0; local_70 = local_70 + 1) {
                      local_1b0[local_70] =
                           *(short *)(&DAT_00426f92 + (uint)(byte)local_24[local_6c + local_70] * 2)
                      ;
                    }
                    FUN_00406bbd(extraout_ECX_17,local_1b0);
                    local_38 = local_38 + 0xa0;
                    FUN_004080a4(extraout_ECX_18,local_1d4);
                    local_68 = local_68 + 0x21;
                    uVar5 = extraout_ECX_19;
                  }
                  goto LAB_0040ef86;
                }
                uVar4 = (uint)(local_38 * 100) / 24000;
                uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
                wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
                SetDlgItemTextA(param_3,0x42c,local_54);
                FUN_00424019();
                pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
                SetCursor(pHVar2);
                if (DAT_00445b3c == 0) {
                  local_34 = GetTickCount();
                  local_38 = 0;
                  local_3c = 1;
                  uVar5 = extraout_ECX_20;
LAB_0040f0cf:
                  if (local_3c != 0) {
                    for (local_6c = 0; local_6c < 10; local_6c = local_6c + 1) {
                      DVar3 = GetTickCount();
                      if (3000 < DVar3 - local_34) {
                        local_3c = 0;
                        uVar5 = extraout_ECX_21;
                        break;
                      }
                      FUN_0040718f(extraout_ECX_21,local_28 + local_6c * 0x21);
                      for (local_70 = 0; local_70 < 0xa0; local_70 = local_70 + 1) {
                        local_28[local_70 + 400] =
                             (&DAT_00427192)[(int)(uint)local_1d4[local_70] >> 3];
                      }
                      local_38 = local_38 + 0xa0;
                      uVar5 = extraout_ECX_22;
                    }
                    goto LAB_0040f0cf;
                  }
                  uVar4 = (uint)(local_38 * 100) / 24000;
                  uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
                  wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
                  SetDlgItemTextA(param_3,0x42d,local_54);
                  FUN_00424019();
                  pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
                  SetCursor(pHVar2);
                  if (DAT_00445b3c == 0) {
                    local_34 = GetTickCount();
                    local_38 = 0;
                    local_3c = 1;
                    uVar5 = extraout_ECX_23;
LAB_0040f1f2:
                    if (local_3c != 0) {
                      local_1d8 = 0;
                      for (local_1dc = 0; local_1dc < 0x640; local_1dc = local_1dc + 0xa0) {
                        DVar3 = GetTickCount();
                        if (3000 < DVar3 - local_34) {
                          local_3c = 0;
                          uVar5 = extraout_ECX_24;
                          break;
                        }
                        FUN_00401a6a(extraout_ECX_24,local_1ec);
                        local_38 = local_38 + 0xa0;
                        FUN_004080a4(extraout_ECX_25,(undefined1 *)local_1ec);
                        local_1d8 = local_1d8 + 0xe;
                        uVar5 = extraout_ECX_26;
                      }
                      goto LAB_0040f1f2;
                    }
                    uVar4 = (uint)(local_38 * 100) / 24000;
                    uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
                    wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
                    SetDlgItemTextA(param_3,0x42e,local_54);
                    FUN_00424019();
                    pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
                    SetCursor(pHVar2);
                    if (DAT_00445b3c == 0) {
                      local_34 = GetTickCount();
                      local_38 = 0;
                      local_3c = 1;
                      uVar5 = extraout_ECX_27;
LAB_0040f303:
                      if (local_3c != 0) {
                        for (local_1dc = 0; local_1dc < 10; local_1dc = local_1dc + 1) {
                          DVar3 = GetTickCount();
                          if (3000 < DVar3 - local_34) {
                            local_3c = 0;
                            uVar5 = extraout_ECX_28;
                            break;
                          }
                          FUN_00401c27(extraout_ECX_28,(ushort *)(local_28 + local_1dc * 0xe));
                          local_38 = local_38 + 0xa0;
                          uVar5 = extraout_ECX_29;
                        }
                        goto LAB_0040f303;
                      }
                      uVar4 = (uint)(local_38 * 100) / 24000;
                      uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
                      wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
                      SetDlgItemTextA(param_3,0x42f,local_54);
                      FUN_00424019();
                      pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
                      SetCursor(pHVar2);
                      if (DAT_00445b3c == 0) {
                        local_34 = GetTickCount();
                        local_38 = 0;
                        local_3c = 1;
                        uVar5 = extraout_ECX_30;
                        while (local_3c != 0) {
                          DVar3 = GetTickCount();
                          if (3000 < DVar3 - local_34) {
                            local_3c = 0;
                            uVar5 = extraout_ECX_31;
                            break;
                          }
                          FUN_0040a952(extraout_ECX_31,(int)local_28);
                          local_38 = local_38 + 0x5a0;
                          uVar5 = extraout_ECX_32;
                        }
                        uVar4 = (uint)(local_38 * 100) / 24000;
                        uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
                        wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
                        SetDlgItemTextA(param_3,0x438,local_54);
                        FUN_00424019();
                        pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
                        SetCursor(pHVar2);
                        if (DAT_00445b3c == 0) {
                          local_34 = GetTickCount();
                          local_38 = 0;
                          local_3c = 1;
                          uVar5 = extraout_ECX_33;
                          while (local_3c != 0) {
                            DVar3 = GetTickCount();
                            if (3000 < DVar3 - local_34) {
                              local_3c = 0;
                              uVar5 = extraout_ECX_34;
                              break;
                            }
                            iVar8 = FUN_0040aacc(extraout_ECX_34,local_28 + 100);
                            local_38 = local_38 + iVar8;
                            uVar5 = extraout_ECX_35;
                          }
                          uVar4 = (uint)(local_38 * 100) / 24000;
                          uVar7 = FUN_00429192(uVar5,(uint)(local_38 * 100) % 24000);
                          wsprintfA(local_54,(LPCSTR)uVar7,uVar4);
                          SetDlgItemTextA(param_3,0x439,local_54);
                          FUN_00424019();
                          pHVar2 = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f02);
                          SetCursor(pHVar2);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        SetCursor(local_2c);
        iVar8 = 0;
        pHVar1 = GetDlgItem(param_3,0x453);
        ShowWindow(pHVar1,iVar8);
        iVar8 = 5;
        pHVar1 = GetDlgItem(param_3,0x430);
        ShowWindow(pHVar1,iVar8);
        BVar9 = 1;
        pHVar1 = GetDlgItem(param_3,1);
        EnableWindow(pHVar1,BVar9);
        pHVar1 = GetDlgItem(param_3,1);
        SetFocus(pHVar1);
      }
      else if (0x452 < (ushort)local_1c) {
        if ((ushort)local_1c < 0x454) {
          DAT_00445b3c = 1;
        }
        else if ((ushort)local_1c == 0xfffd) {
          uVar7 = FUN_00429192(param_1,param_2);
          dwData = (ULONG_PTR)uVar7;
          uCommand = 0x101;
          uVar7 = FUN_00429192(extraout_ECX_36,(int)((ulonglong)uVar7 >> 0x20));
          WinHelpA(DAT_004627d0,(LPCSTR)uVar7,uCommand,dwData);
          DAT_0043d608 = 1;
        }
      }
    }
  }
  return 0;
}


