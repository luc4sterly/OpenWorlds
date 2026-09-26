// 0041b0af FUN_0041b0af [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort * __fastcall FUN_0041b0af(undefined4 param_1,int param_2)

{
  UINT UVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  HWND in_EAX;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  DWORD DVar10;
  uint uVar11;
  uint uVar12;
  DWORD DVar13;
  BOOL BVar14;
  HGLOBAL pvVar15;
  undefined4 uVar16;
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
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  int unaff_EBX;
  undefined8 uVar17;
  ushort *local_bc;
  ushort *local_b8;
  int local_ac;
  int local_98;
  int local_7c;
  int local_70;
  int local_54;
  uint local_50;
  undefined4 local_4c;
  ushort *local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  int local_3c;
  HWND local_34;
  uint local_2c;
  int local_28;
  int local_24;
  LPCVOID local_20;
  uint local_1c;
  ushort *local_18;
  int local_14;
  undefined4 local_10;
  
  local_20 = (LPCVOID)0x0;
  local_18 = (ushort *)&DAT_0045e418;
  local_50 = (uint)(param_2 == -1);
  local_1c = local_50;
  local_14 = 0;
  if (_DAT_004b24be == (undefined1 *)0x0) {
    for (local_54 = 0; local_54 < 0x14; local_54 = local_54 + 1) {
      *(undefined **)(&DAT_004b24be + local_54 * 0x24) = &DAT_004630ee + local_54 * 0x3f64;
    }
  }
  local_10._0_2_ = (short)param_1;
  local_3c = param_2;
  local_10 = param_1;
  if ((short)local_10 == 1) {
    if (unaff_EBX == 0) {
LAB_0041b189:
      while (local_2c = 0x10, local_1c == 0) {
        if ((short)local_10 == 1) {
          local_28 = FUN_00429a76();
          uVar16 = extraout_ECX_00;
          goto LAB_0041b21a;
        }
        FUN_004296b9(s__s__d_Got_weird_event__d_004366ec);
      }
      local_28 = FUN_00421cb2(&local_4c,&local_2c);
      uVar16 = extraout_ECX;
LAB_0041b21a:
      if (local_28 != 0) {
        if ((local_28 != -1) &&
           (((DAT_0043d6d4 == (ushort *)0xffffffff || (local_48 == DAT_0043d6d4)) &&
            (DAT_0043d5e8 == 0)))) {
          uVar11 = DAT_0043d72c;
          DVar13 = _DAT_004b278e;
          uVar12 = _DAT_004b2792;
          if (DAT_0043d718 != 0) {
            iVar8 = Ordinal_14(*(undefined4 *)(local_18 + 10));
            iVar9 = Ordinal_14(*(undefined4 *)(local_18 + 0xc));
            DVar10 = GetTickCount();
            uVar11 = iVar8 >> 0xc & 0xfff;
            uVar12 = iVar9 >> 0x14 & 0x1f;
            uVar16 = extraout_ECX_01;
            DVar13 = _DAT_004b278e;
            if (((uVar11 != DAT_0043d72c) && (DVar13 = DVar10, (DAT_0043d72c + 1 & 0xfff) == uVar11)
                ) && (uVar12 == _DAT_004b2792)) {
              iVar8 = DVar10 - _DAT_004b278e;
              _DAT_004b27b2 = _DAT_004b27b2 + 1;
              if (_DAT_004b2796 == 0) {
                _DAT_004b279e = _DAT_004b279e + iVar8;
                _DAT_004b27a2 = _DAT_004b27a2 + 1;
                if (_DAT_004b279a < iVar8) {
                  _DAT_004b279a = iVar8;
                }
              }
              else {
                _DAT_004b27aa = _DAT_004b27aa + iVar8;
                _DAT_004b27ae = _DAT_004b27ae + 1;
                if (_DAT_004b27a6 < iVar8) {
                  _DAT_004b27a6 = iVar8;
                }
              }
              if (_DAT_004b27a6 < _DAT_004b279a) {
                local_70 = _DAT_004b279a;
              }
              else {
                local_70 = _DAT_004b27a6;
              }
              local_7c = local_70 -
                         (_DAT_004b279e + _DAT_004b27aa) / (_DAT_004b27a2 + _DAT_004b27ae);
              if (3000 < local_7c) {
                local_7c = 3000;
              }
              if (local_7c < 0) {
                FUN_004296b9(s_How_could_we_get_desiredJitter___00436726);
                local_7c = 0;
                uVar16 = extraout_ECX_02;
              }
              UVar1 = (local_7c + 0x32) - (local_7c + 0x32) % 100;
              if ((0x27 < _DAT_004b27a2 + _DAT_004b27ae) && (UVar1 != DAT_0043d65c)) {
                DAT_0043d65c = UVar1;
                FUN_004296b9(s_Auto_adjusting_jitter_to__d_ms_0043674c);
                FUN_004173ab(extraout_ECX_03,DAT_0043d65c);
                uVar16 = extraout_ECX_04;
              }
              if (0x31 < _DAT_004b27b2) {
                _DAT_004b27b2 = 0;
                if (_DAT_004b2796 == 0) {
                  _DAT_004b27a6 = 0;
                  _DAT_004b27aa = 0;
                  _DAT_004b27ae = 0;
                  _DAT_004b2796 = 1;
                }
                else {
                  _DAT_004b279a = 0;
                  _DAT_004b279e = 0;
                  _DAT_004b27a2 = 0;
                  _DAT_004b2796 = 0;
                }
              }
            }
          }
          _DAT_004b2792 = uVar12;
          _DAT_004b278e = DVar13;
          DAT_0043d72c = uVar11;
          if (0x13 < DAT_00462568) {
            DAT_0043d6bc = DAT_0043d6bc + 1;
            puVar7 = (ushort *)FUN_004173ab(uVar16,DAT_0043d6bc);
            return puVar7;
          }
          FUN_004080a4(uVar16,(undefined1 *)local_18);
          *(int *)(&DAT_004b24c2 + DAT_00462568 * 0x24) = local_28;
          iVar8 = DAT_00462568 * 0x24;
          *(uint *)(&DAT_004b24c6 + iVar8) = local_4c;
          *(ushort **)(&DAT_004b24ca + iVar8) = local_48;
          *(undefined4 *)(&DAT_004b24ce + iVar8) = uStack_44;
          *(undefined4 *)(&DAT_004b24d2 + iVar8) = uStack_40;
          *(uint *)(&DAT_004b24d6 + DAT_00462568 * 0x24) = local_2c;
          *(int *)(&DAT_004b24da + DAT_00462568 * 0x24) = local_3c;
          DVar13 = GetTickCount();
          *(uint *)(&DAT_004b24de + DAT_00462568 * 0x24) = (DVar13 - _DAT_004623e0) / 100;
          DAT_00462568 = DAT_00462568 + 1;
          FUN_004173ab(extraout_ECX_05,DAT_00462568);
        }
        goto LAB_0041b189;
      }
      puVar7 = (ushort *)0x0;
      if (DAT_004630ea == 0) {
        DAT_004630ea = 1;
        local_28 = 0;
LAB_0041b57b:
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                if (DAT_00462568 < 1) {
                  DAT_004630ea = 0;
                  return puVar7;
                }
                bVar4 = false;
                if ((DAT_0043d5a4 == 0) && (local_1c == 0)) {
                  puVar7 = (ushort *)FUN_00424019();
                  uVar16 = extraout_ECX_06;
                }
                if ((DAT_0043d68c == 0) && (DAT_0043d618 == 0)) break;
                DAT_00462568 = 0;
              }
              local_28 = _DAT_004b24c2;
              FUN_004080a4(uVar16,_DAT_004b24be);
              puVar5 = _DAT_004b24be;
              local_4c = _DAT_004b24c6;
              local_48 = _DAT_004b24ca;
              uStack_44 = _DAT_004b24ce;
              uStack_40 = _DAT_004b24d2;
              local_2c = _DAT_004b24d6;
              local_3c = _DAT_004b24da;
              local_24 = _DAT_004b24de;
              DAT_00462568 = DAT_00462568 + -1;
              FUN_004080a4(extraout_ECX_07,(undefined1 *)0x4b24e2);
              *(undefined1 **)(&DAT_004b24be + DAT_00462568 * 0x24) = puVar5;
              FUN_004173ab(extraout_ECX_08,DAT_00462568);
              uVar17 = FUN_0041b01c(extraout_ECX_09,extraout_EDX);
              uVar6 = Ordinal_9((uint)uVar17 & 0xffff);
              local_4c = CONCAT22(uVar6,(undefined2)local_4c);
              uVar17 = FUN_00417400(extraout_ECX_10,extraout_EDX_00);
              local_34 = (HWND)uVar17;
              if (local_34 != (HWND)0x0) break;
              if ((DAT_0043d690 == local_48) && (0 < DAT_0043d694)) {
                DAT_00462568 = 0;
                puVar7 = DAT_0043d690;
                uVar16 = extraout_ECX_11;
              }
              else {
                uVar6 = Ordinal_15(local_4c >> 0x10);
                Ordinal_11(local_48,uVar6);
                uVar17 = FUN_00429268(extraout_ECX_13,extraout_EDX_02,0xdfd,
                                      s__GAMMA_speakfre_sfmain_FRAME_c_00436788,2,in_EAX,0x10,
                                      s_Didn_t_find_client___s__d__0043676c);
                puVar7 = (ushort *)uVar17;
                uVar16 = extraout_ECX_14;
              }
            }
            local_20 = (LPCVOID)GetWindowLongA(local_34,0);
            if (0 < *(int *)((int)local_20 + 0x10)) {
              *(undefined4 *)((int)local_20 + 0x10) = 0;
            }
            DAT_0043d534 = 0;
            uVar17 = FUN_0041aa9b(extraout_ECX_12,extraout_EDX_01);
            if (((ushort *)uVar17 == (ushort *)0x0) && (bVar4 = true, DAT_0043d530 == 0)) {
              DAT_00462568 = 0;
              DAT_004630ea = 0;
              return (ushort *)0x0;
            }
            if (local_20 == (LPCVOID)0x0) {
              if (local_34 == (HWND)0x0) {
                DAT_00462568 = 0;
                DAT_004630ea = 0;
                return (ushort *)uVar17;
              }
              puVar7 = (ushort *)SendMessageA(DAT_004627c8,0x221,(WPARAM)local_34,0);
              DAT_00462568 = 0;
              DAT_004630ea = 0;
              return puVar7;
            }
            uVar16 = extraout_ECX_15;
            if (*(char *)((int)local_20 + 4) == '\0') {
              BVar14 = IsIconic(in_EAX);
              if ((BVar14 != 0) && (DAT_0043d60c != 0)) {
                ShowWindow(in_EAX,1);
              }
              FUN_004296b9(s_createNewConnection_FALSE___d__s_004367c6);
              local_34 = FUN_0041093b(extraout_ECX_16,0);
              uVar16 = extraout_ECX_17;
            }
            if (local_34 != (HWND)0x0) break;
            puVar7 = (ushort *)FUN_004296b9(s_Unable_to_create_connection_wind_004367e9);
            uVar16 = extraout_ECX_18;
            if (local_20 != (LPCVOID)0x0) {
              pvVar15 = GlobalHandle(local_20);
              GlobalUnlock(pvVar15);
              pvVar15 = GlobalHandle(local_20);
              puVar7 = GlobalFree(pvVar15);
              uVar16 = extraout_ECX_19;
            }
            DAT_00462568 = 0;
          }
          *(int *)((int)local_20 + 0x134) = *(int *)((int)local_20 + 0x134) + local_28;
          if (0 < *(int *)((int)local_20 + 0x10)) {
            *(undefined4 *)((int)local_20 + 0x10) = 0;
          }
          if (((*(short *)((int)local_20 + 0x4e40) == 1) ||
              (*(short *)((int)local_20 + 0x4e40) == 3)) && ((int)(uint)(byte)*local_18 >> 6 == 1))
          {
            *(undefined2 *)((int)local_20 + 0x4e40) = 0;
            InvalidateRect(local_34,(RECT *)0x0,1);
            uVar16 = extraout_ECX_20;
          }
          if (((*(short *)((int)local_20 + 0x4e40) == 1) &&
              (iVar8 = FUN_004080b5(uVar16,(char *)((int)local_20 + 0x4e4c)),
              uVar16 = extraout_ECX_21, iVar8 == 0)) &&
             (iVar8 = FUN_00429b7d(extraout_ECX_21,local_28), uVar16 = extraout_ECX_22, iVar8 != 0))
          goto LAB_0041b87f;
          if (((*(short *)((int)local_20 + 0x4e40) != 2) ||
              (iVar8 = FUN_004080b5(uVar16,(char *)((int)local_20 + 0x4e4c)),
              uVar16 = extraout_ECX_23, iVar8 != 0)) ||
             (iVar8 = FUN_00424e52(extraout_ECX_23,local_28), uVar16 = extraout_ECX_24, iVar8 == 0))
          break;
          puVar7 = local_18;
          if (*(int *)(local_18 + 10) != 0) {
            local_14 = 1;
            break;
          }
        }
        goto LAB_0041b8e6;
      }
    }
    else {
      puVar7 = (ushort *)FUN_004296b9(s__s__d_Got_socket_error__d_004366b1);
    }
  }
  else {
    puVar7 = (ushort *)FUN_004296b9(s__s__d_Got_unexpected_event__d_00436672);
  }
  return puVar7;
LAB_0041b87f:
  puVar7 = local_18;
  if (*(int *)(local_18 + 10) == 0) goto LAB_0041b57b;
  local_14 = 1;
LAB_0041b8e6:
  if (local_14 == 0) {
    uVar16 = Ordinal_14(*(undefined4 *)local_18);
    *(undefined4 *)local_18 = uVar16;
    uVar16 = Ordinal_14(*(undefined4 *)(local_18 + 10));
    *(undefined4 *)(local_18 + 10) = uVar16;
    uVar16 = Ordinal_14(*(undefined4 *)(local_18 + 0xc));
    *(undefined4 *)(local_18 + 0xc) = uVar16;
    uVar16 = extraout_ECX_25;
    if ((*(byte *)((int)local_18 + 3) & 0x40) != 0) {
      DAT_0043d6dc = (ushort *)(*(int *)(local_18 + 10) >> 0xc & 0xfff);
      DAT_004623d4 = *(int *)(local_18 + 10) >> 0x18 & 0xff;
      if ((*(int *)(local_18 + 10) >> 0x18 & 0x80U) != 0) {
        DAT_004623d4 = DAT_004623d4 | 0xffffff00;
      }
      *(uint *)(local_18 + 10) = *(uint *)(local_18 + 10) & 0xfff;
      DAT_0043d6e4 = DAT_0043d6e0;
      DAT_004623c4 = *(int *)(local_18 + 0xc) >> 0x19 & 0x3f;
      DAT_0043d6e0 = *(int *)(local_18 + 0xc) >> 0x14 & 0x1f;
      DAT_004623e4 = *(int *)(local_18 + 0xc) >> 0x10 & 0xf;
      _DAT_004623dc = *(uint *)(local_18 + 0xc) & 0xffff;
      FUN_004173ab(extraout_ECX_25,DAT_0043d6dc);
      FUN_004173ab(extraout_ECX_26,DAT_004623d4);
      FUN_004173ab(extraout_ECX_27,DAT_004623c4);
      uVar16 = extraout_ECX_28;
      if ((DAT_004623a0 == 0) && (DAT_0043d5dc != 0)) {
        if (DAT_0043d708 == 0) {
          if (((DAT_0043d560 == 0) && (DAT_0043d564 == 0)) || (1 < (int)DAT_004623c4)) {
            if ((DAT_0043d564 == 0) || (0xb < (int)DAT_004623c4)) {
              if ((int)DAT_004623c4 < 0xf) {
                if ((DAT_0043d560 == 0) && (DAT_0043d564 == 0)) {
                  bVar2 = true;
                }
                else {
                  bVar2 = false;
                }
                if ((bVar2) && (2 < (int)DAT_004623c4)) {
                  FUN_004296b9(s_Auto_changed_from_1X_to_2X_00436821);
                  FUN_00417864(extraout_ECX_40,0);
                  uVar16 = extraout_ECX_41;
                }
              }
              else {
                if (DAT_0043d560 == 0) {
                  FUN_004296b9(s_Auto_changed_from_1X_to_3X_00436875);
                  uVar16 = extraout_ECX_38;
                }
                else {
                  FUN_004296b9(s_Auto_changed_from_2X_to_3X_00436859);
                  uVar16 = extraout_ECX_37;
                }
                FUN_00417864(uVar16,1);
                uVar16 = extraout_ECX_39;
              }
            }
            else {
              FUN_004296b9(s_Auto_changed_from_3X_to_2X_0043683d);
              FUN_00417864(extraout_ECX_35,0);
              uVar16 = extraout_ECX_36;
            }
          }
          else {
            FUN_004296b9(s_Auto_changed_to_1X_0043680d);
            FUN_00417864(extraout_ECX_33,0);
            uVar16 = extraout_ECX_34;
          }
        }
        else if (((DAT_0043d560 == 0) && (DAT_0043d564 == 0)) || (1 < (int)DAT_004623c4)) {
          if ((DAT_0043d560 == 0) && (DAT_0043d564 == 0)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if ((bVar2) && (2 < (int)DAT_004623c4)) {
            FUN_004296b9(s_Auto_changed_from_1X_to_2X_00436821);
            FUN_00417864(extraout_ECX_31,0);
            uVar16 = extraout_ECX_32;
          }
        }
        else {
          FUN_004296b9(s_Auto_changed_to_1X_0043680d);
          FUN_00417864(extraout_ECX_29,0);
          uVar16 = extraout_ECX_30;
        }
      }
      if (((int)DAT_004623e4 < 1) || (100 < (int)DAT_004623e4)) {
        FUN_004296b9(s_In_packet_redundancy____d__00436891);
        DAT_004623e4 = 1;
        uVar16 = extraout_ECX_42;
      }
      uVar11 = (int)DAT_0043d6dc - (int)DAT_0043d6fc & 0xfff;
      if (uVar11 < 0x800) {
        for (local_98 = 0; local_98 < (int)uVar11; local_98 = local_98 + 1) {
          uVar12 = (uint)((int)DAT_0043d6fc + local_98 + 1) & 0xfff;
          if (*(int *)(&DAT_0045a220 + uVar12 * 4) == 0) {
            *(undefined4 *)(&DAT_0045a220 + uVar12 * 4) = 1;
            if (DAT_0046237c == 0) {
              DAT_00462384 = DAT_00462384 + DAT_004623e4;
            }
            else {
              _DAT_00462380 = _DAT_00462380 + DAT_004623e4;
            }
            DAT_00462388 = DAT_00462388 + 1;
          }
          *(undefined4 *)(&DAT_0045a220 + (uVar12 + 0x800 & 0xfff) * 4) = 0;
        }
      }
      if (DAT_0046237c == 0) {
        DAT_0045e410 = DAT_0045e410 + 1;
      }
      else {
        _DAT_0045e414 = _DAT_0045e414 + 1;
      }
      DAT_004623d0 = 100 - ((DAT_0045e410 + _DAT_0045e414) * 100) / (DAT_00462384 + _DAT_00462380);
      FUN_004173ab(uVar16,DAT_004623d0);
      iVar8 = local_24 - _DAT_004623dc;
      if (DAT_0046237c == 0) {
        if (DAT_0043d734 < iVar8) {
          DAT_0043d734 = iVar8;
        }
      }
      else if (DAT_0043d730 < iVar8) {
        DAT_0043d730 = iVar8;
      }
      if (DAT_0043d734 < DAT_0043d730) {
        DAT_004623c8 = DAT_0043d730;
      }
      else {
        DAT_004623c8 = DAT_0043d734;
      }
      if (DAT_004623c8 < 0x80) {
        if (DAT_004623c8 < -0x80) {
          DAT_004623c8 = -0x80;
        }
      }
      else {
        DAT_004623c8 = 0x7f;
      }
      uVar16 = extraout_ECX_43;
      if (100 < DAT_00462388) {
        if (DAT_0046237c == 0) {
          _DAT_0045e414 = 0;
          _DAT_00462380 = 0;
          DAT_0043d730 = -1000000;
        }
        else {
          DAT_0045e410 = 0;
          DAT_00462384 = 0;
          DAT_0043d734 = -1000000;
        }
        DAT_0046237c = (uint)(DAT_0046237c == 0);
        DAT_00462388 = 0;
      }
    }
    uVar11 = *(uint *)(local_18 + 10);
    if ((*local_18 & 0x540) != 0) {
      uVar11 = *(int *)(local_18 + 10) + 7U & 0xfffffff8;
    }
    local_ac = uVar11 + 0x1c;
    if (((local_18[1] & 2) != 0) && (0x10 < *(int *)(local_18 + 10))) {
      local_ac = uVar11 + 0xc;
    }
    if (local_ac != local_28) {
      FUN_004296b9(s_Not_a_GammaPhone_packet_____igno_004368ad);
      *(undefined2 *)((int)local_20 + 0x4e40) = 4;
      puVar7 = (ushort *)InvalidateRect(local_34,(RECT *)0x0,1);
      uVar16 = extraout_ECX_44;
      goto LAB_0041b57b;
    }
    if (*(short *)((int)local_20 + 0x4e40) != 0) {
      *(undefined2 *)((int)local_20 + 0x4e40) = 0;
      InvalidateRect(local_34,(RECT *)0x0,1);
      uVar16 = extraout_ECX_45;
    }
  }
  if (((local_18[1] & 2) != 0) && (0x10 < *(int *)(local_18 + 10))) {
    FUN_004080a4(uVar16,(undefined1 *)(local_18 + 2));
    local_28 = local_28 + 0x10;
    uVar16 = extraout_ECX_46;
  }
  bVar2 = false;
  if ((ushort *)((uint)((int)DAT_0043d6fc + 1) & 0xfff) != DAT_0043d6dc) {
    bVar3 = false;
    if (((int)DAT_0043d6dc < 0x400) || (0xc00 < (int)DAT_0043d6dc)) {
      local_b8 = (ushort *)((uint)(DAT_0043d6dc + 0x400) & 0xfff);
      local_bc = (ushort *)((uint)(DAT_0043d6fc + 0x400) & 0xfff);
    }
    else {
      local_b8 = DAT_0043d6dc;
      local_bc = DAT_0043d6fc;
    }
    if ((int)local_b8 < (int)local_bc) {
      DAT_0043d6f0 = DAT_0043d6f0 + 1;
      FUN_004173ab(uVar16,DAT_0043d6f0);
      bVar2 = true;
      bVar3 = true;
      uVar16 = extraout_ECX_47;
    }
    else if (local_b8 == local_bc) {
      DAT_0043d6f4 = DAT_0043d6f4 + 1;
      FUN_004173ab(uVar16,DAT_0043d6f4);
      bVar2 = true;
      uVar16 = extraout_ECX_48;
    }
    else {
      DAT_0043d6ec = DAT_0043d6ec + 1;
      FUN_004173ab(uVar16,DAT_0043d6ec);
      uVar16 = extraout_ECX_49;
    }
    if (bVar3) {
      FUN_004296b9(s_Got__d__expected__d_004368d3);
      uVar16 = extraout_ECX_50;
    }
  }
  DAT_0043d6f8 = ((DAT_0043d6f0 + DAT_0043d6ec) * 1000) / DAT_0043d6b4;
  FUN_004173ab(uVar16,DAT_0043d6f8);
  DAT_0043d6fc = DAT_0043d6dc;
  puVar7 = DAT_0043d6dc;
  uVar16 = extraout_ECX_51;
  if ((!bVar2) &&
     (((puVar7 = local_18, (*local_18 & 0x800) == 0 || (DAT_0043d530 != 0)) && (!bVar4)))) {
    if ((((DAT_0043d538 < 3) && (DAT_0043d65c != 0)) && (DAT_0043d664 == 0)) &&
       ((DAT_0043d6e0 != DAT_0043d6e4 &&
        (DAT_0043d664 = SetTimer(in_EAX,6,DAT_0043d65c,(TIMERPROC)0x0), DAT_0043d664 != 0)))) {
      FUN_0041774e(extraout_ECX_52,extraout_EDX_03);
      DAT_0043d660 = 1;
    }
    *(undefined1 *)((int)local_20 + 4) = 4;
    puVar7 = (ushort *)FUN_004264cf(_DAT_0043d6a8,(int)local_20,DAT_0043d69c);
    uVar16 = extraout_ECX_53;
  }
  goto LAB_0041b57b;
}


