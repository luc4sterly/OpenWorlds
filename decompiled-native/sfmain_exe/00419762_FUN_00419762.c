// 00419762 FUN_00419762 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00419762(undefined4 param_1,uint param_2)

{
  HWND in_EAX;
  HWND hWnd;
  code *pcVar1;
  LONG LVar2;
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
  undefined4 uVar3;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 extraout_ECX_14;
  undefined4 extraout_ECX_15;
  undefined4 extraout_EDX;
  undefined4 uVar4;
  undefined4 extraout_EDX_00;
  LPARAM unaff_EBX;
  undefined8 uVar5;
  UINT UVar6;
  ULONG_PTR UVar7;
  undefined *dwData;
  HWND local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  LPCSTR local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  
  if (param_2 < 0xb9) {
    if (param_2 < 0x96) {
      if (param_2 < 0x7f) {
        if (param_2 < 0x78) {
          if (param_2 < 0x72) {
            if (0x68 < param_2) {
              if (param_2 < 0x6a) {
                FUN_00418c25(param_1,0);
                return;
              }
              if (param_2 == 0x6a) {
                hWnd = (HWND)SendMessageA(DAT_004627c8,0x229,0,0);
                if (hWnd == (HWND)0x0) {
                  return;
                }
                PostMessageA(hWnd,0x10,0,0);
                return;
              }
            }
          }
          else {
            if (param_2 < 0x73) {
              UVar7 = 0;
              UVar6 = 3;
              uVar5 = FUN_00429192(param_1,param_2);
              WinHelpA(in_EAX,(LPCSTR)uVar5,UVar6,UVar7);
              DAT_0043d608 = 1;
              return;
            }
            if (param_2 < 0x74) {
              dwData = &DAT_00436610;
              UVar6 = 0x105;
              uVar5 = FUN_00429192(param_1,param_2);
              WinHelpA(in_EAX,(LPCSTR)uVar5,UVar6,(ULONG_PTR)dwData);
              DAT_0043d608 = 1;
              return;
            }
            if (param_2 == 0x75) {
              local_24 = (uint)(DAT_0043d600 == 0);
              DAT_0043d600 = local_24;
              if ((local_24 == 0) && (DAT_0043d5fc == 0)) {
                DAT_0043d6a4 = 2;
                _DAT_0043d6a8 = 0x10;
              }
              else {
                DAT_0043d6a4 = 1;
                _DAT_0043d6a8 = 8;
              }
              DAT_0043d6a0 = DAT_0043d69c * DAT_0043d6a4;
              FUN_004152eb(param_1,0x75);
              return;
            }
          }
        }
        else {
          if (param_2 < 0x79) {
            FUN_00417864(param_1,0);
            return;
          }
          if (param_2 < 0x7b) {
            if (0x79 < param_2) {
              FUN_00415c28();
              return;
            }
            local_88 = (uint)(DAT_0043d568 == 0);
            DAT_0043d568 = local_88;
            if (local_88 != 0) {
              DAT_0043d56c = 0;
              DAT_0043d570 = 0;
              DAT_0043d574 = 0;
              DAT_0043d57c = 0;
            }
            uVar5 = FUN_0041848a(param_1,param_2);
            DAT_0046239c = (undefined4)uVar5;
            uVar5 = FUN_004182e8(extraout_ECX_08,(int)((ulonglong)uVar5 >> 0x20));
            DAT_004627ac = (undefined4)uVar5;
            DAT_00462398 = DAT_0046239c;
            FUN_004152eb(extraout_ECX_09,(int)((ulonglong)uVar5 >> 0x20));
            return;
          }
          if (param_2 < 0x7c) {
            local_7c = (uint)(DAT_0043d56c == 0);
            DAT_0043d56c = local_7c;
            if (local_7c != 0) {
              DAT_0043d568 = 0;
              DAT_0043d570 = 0;
              DAT_0043d574 = 0;
              DAT_0043d57c = 0;
            }
            uVar5 = FUN_0041848a(param_1,param_2);
            DAT_0046239c = (undefined4)uVar5;
            uVar5 = FUN_004182e8(extraout_ECX_02,(int)((ulonglong)uVar5 >> 0x20));
            DAT_004627ac = (undefined4)uVar5;
            DAT_00462398 = DAT_0046239c;
            FUN_004152eb(extraout_ECX_03,(int)((ulonglong)uVar5 >> 0x20));
            return;
          }
          if (0x7c < param_2) {
            if (param_2 < 0x7e) {
              local_30 = (uint)(DAT_0043d58c == 0);
              DAT_0043d58c = local_30;
              return;
            }
            local_34 = (uint)(DAT_0043d594 == 0);
            if (local_34 == 0) {
              DAT_0043d594 = local_34;
              return;
            }
            DAT_0043d594 = local_34;
            DAT_0043d598 = 0;
            return;
          }
        }
      }
      else {
        if (param_2 < 0x80) {
          local_38 = (uint)(DAT_0043d598 == 0);
          DAT_0043d598 = local_38;
          DAT_0043d590 = local_38;
          if (local_38 != 0) {
            DAT_0043d594 = 0;
          }
          if (DAT_0043d634 == (HWND)0x0) {
            return;
          }
          if (local_38 == 0) {
            uVar5 = FUN_00429192(param_1,param_2);
            local_3c = (LPCSTR)uVar5;
          }
          else {
            uVar5 = FUN_00429192(param_1,param_2);
            local_3c = (LPCSTR)uVar5;
          }
          SetDlgItemTextA(DAT_0043d634,0x408,local_3c);
          return;
        }
        if (param_2 < 0x88) {
          if (param_2 < 0x82) {
            if (0x80 < param_2) {
              local_68 = (uint)(DAT_0043d5c8 == 0);
              DAT_0043d5c8 = local_68;
              uVar5 = FUN_00429192(param_1,param_2);
              FUN_00429268(extraout_ECX_01,(int)((ulonglong)uVar5 >> 0x20),0xaac,
                           s__GAMMA_speakfre_sfmain_FRAME_c_004365f1,2,in_EAX,0x40,(LPCSTR)uVar5);
              return;
            }
            local_64 = (uint)(DAT_0043d5c4 == 0);
            DAT_0043d5c4 = local_64;
            uVar5 = FUN_00429192(param_1,param_2);
            FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar5 >> 0x20),0xaa6,
                         s__GAMMA_speakfre_sfmain_FRAME_c_004365d2,2,in_EAX,0x40,(LPCSTR)uVar5);
            return;
          }
          if (param_2 < 0x83) {
            local_2c = (uint)(DAT_0043d60c == 0);
            DAT_0043d60c = local_2c;
            return;
          }
          if (0x83 < param_2) {
            if (param_2 < 0x85) {
              local_40 = (uint)(DAT_0043d59c == 0);
              DAT_0043d59c = local_40;
              return;
            }
            if (param_2 == 0x87) {
              DAT_0043d618 = 1;
              FUN_00423f2f();
              DAT_0043d618 = 0;
              return;
            }
          }
        }
        else {
          if (param_2 < 0x89) {
            DAT_0043d618 = 1;
            FUN_004225d3();
            DAT_0043d618 = 0;
            return;
          }
          if (param_2 < 0x8e) {
            if (param_2 < 0x8a) {
              local_80 = (uint)(DAT_0043d570 == 0);
              DAT_0043d570 = local_80;
              if (local_80 != 0) {
                DAT_0043d568 = 0;
                DAT_0043d56c = 0;
                DAT_0043d574 = 0;
                DAT_0043d57c = 0;
              }
              uVar5 = FUN_0041848a(param_1,param_2);
              DAT_0046239c = (undefined4)uVar5;
              uVar5 = FUN_004182e8(extraout_ECX_04,(int)((ulonglong)uVar5 >> 0x20));
              DAT_004627ac = (undefined4)uVar5;
              DAT_00462398 = DAT_0046239c;
              FUN_004152eb(extraout_ECX_05,(int)((ulonglong)uVar5 >> 0x20));
              return;
            }
            if (param_2 == 0x8b) {
              FUN_00416d8e(param_1,0x8b);
              return;
            }
          }
          else {
            if (param_2 < 0x92) {
              if (DAT_0043d558 == param_2) {
                return;
              }
              DAT_0043d558 = param_2;
              return;
            }
            if (param_2 < 0x93) {
              local_28 = (uint)(DAT_0043d55c == 0);
              DAT_0043d55c = local_28;
              return;
            }
            if (param_2 < 0x94) {
              FUN_0041679d(param_1,param_2);
              return;
            }
            if (param_2 == 0x94) {
              local_44 = (uint)(DAT_0043d5a0 == 0);
              DAT_0043d5a0 = local_44;
              return;
            }
          }
        }
      }
    }
    else {
      if (param_2 < 0x97) {
        local_48 = (uint)(DAT_0043d5a4 == 0);
        DAT_0043d5a4 = local_48;
        return;
      }
      if (param_2 < 0xa3) {
        if (param_2 < 0x9d) {
          if (param_2 < 0x9a) {
            if (param_2 < 0x98) {
              local_6c = (uint)(DAT_0043d5ec == 0);
              DAT_0043d5ec = local_6c;
              return;
            }
            if (param_2 != 0x99) goto LAB_0041aa74;
            DAT_0043d580 = 0;
          }
          else {
            if (param_2 < 0x9b) {
              DAT_0043d580 = 2;
            }
            else {
              if (0x9b < param_2) {
                local_4c = (uint)(DAT_0043d5ac == 0);
                DAT_0043d5a8 = local_4c;
                DAT_0043d5ac = local_4c;
                return;
              }
              DAT_0043d580 = 1;
            }
            DAT_0043d560 = 0;
            DAT_0043d564 = 0;
            if (DAT_0043d574 != 0) {
              DAT_0043d574 = 0;
              DAT_0043d570 = 1;
            }
          }
        }
        else if (0x9d < param_2) {
          if (param_2 < 0xa0) {
            if (0x9e < param_2) {
              local_54 = (uint)(DAT_0043d5b4 == 0);
              DAT_0043d5b4 = local_54;
              uVar5 = FUN_0041848a(param_1,param_2);
              DAT_0046239c = (undefined4)uVar5;
              uVar5 = FUN_004182e8(extraout_ECX,(int)((ulonglong)uVar5 >> 0x20));
              DAT_00462398 = DAT_0046239c;
              DAT_004627ac = (int)uVar5;
              return;
            }
            local_50 = (uint)(DAT_0043d5b0 == 0);
            DAT_0043d5b0 = local_50;
            return;
          }
          if (0xa0 < param_2) {
            if (0xa1 < param_2) {
              local_60 = (uint)(DAT_0043d5c0 == 0);
              DAT_0043d5c0 = local_60;
              return;
            }
            local_5c = (uint)(DAT_0043d5bc == 0);
            DAT_0043d5bc = local_5c;
            return;
          }
          local_58 = (uint)(DAT_0043d5b8 == 0);
          DAT_0043d5b8 = local_58;
          return;
        }
        DAT_0043d584 = DAT_0043d580;
        local_8c = GetWindow(DAT_004627c8,5);
        uVar3 = extraout_ECX_10;
        uVar4 = extraout_EDX;
        while (local_8c != (HWND)0x0) {
          pcVar1 = (code *)GetWindowLongA(local_8c,-4);
          if ((pcVar1 == FUN_004110e1) && (LVar2 = GetWindowLongA(local_8c,0), LVar2 != 0)) {
            *(undefined4 *)(LVar2 + 0x4e50) = 0;
          }
          local_8c = GetWindow(local_8c,2);
          uVar3 = extraout_ECX_11;
          uVar4 = extraout_EDX_00;
        }
        uVar5 = FUN_0041848a(uVar3,uVar4);
        DAT_0046239c = (undefined4)uVar5;
        uVar5 = FUN_004182e8(extraout_ECX_12,(int)((ulonglong)uVar5 >> 0x20));
        DAT_00462398 = DAT_0046239c;
        DAT_004627ac = (int)uVar5;
        return;
      }
      if (param_2 < 0xa4) {
        uVar5 = FUN_00429192(param_1,param_2);
        UVar7 = (ULONG_PTR)uVar5;
        UVar6 = 0x105;
        uVar5 = FUN_00429192(extraout_ECX_13,(int)((ulonglong)uVar5 >> 0x20));
        WinHelpA(in_EAX,(LPCSTR)uVar5,UVar6,UVar7);
        DAT_0043d608 = 1;
        return;
      }
      if (param_2 < 0xaa) {
        if (0xa6 < param_2) {
          if (param_2 < 0xa8) {
            DAT_0043d65c = 0;
            return;
          }
          if (0xa8 < param_2) {
            DAT_0043d65c = 0xfa;
            return;
          }
          DAT_0043d65c = 100;
          return;
        }
        if (0xa4 < param_2) {
          if (0xa5 < param_2) {
            uVar5 = FUN_00429192(param_1,param_2);
            UVar7 = (ULONG_PTR)uVar5;
            UVar6 = 0x105;
            uVar5 = FUN_00429192(extraout_ECX_15,(int)((ulonglong)uVar5 >> 0x20));
            WinHelpA(in_EAX,(LPCSTR)uVar5,UVar6,UVar7);
            DAT_0043d608 = 1;
            return;
          }
          uVar5 = FUN_00429192(param_1,param_2);
          UVar7 = (ULONG_PTR)uVar5;
          UVar6 = 0x105;
          uVar5 = FUN_00429192(extraout_ECX_14,(int)((ulonglong)uVar5 >> 0x20));
          WinHelpA(in_EAX,(LPCSTR)uVar5,UVar6,UVar7);
          DAT_0043d608 = 1;
          return;
        }
      }
      else {
        if (param_2 < 0xab) {
          DAT_0043d65c = 500;
          return;
        }
        if (param_2 < 0xad) {
          if (0xab < param_2) {
            DAT_0043d65c = 1000;
            return;
          }
          DAT_0043d65c = 0x2ee;
          return;
        }
        if (param_2 < 0xae) {
          DAT_0043d65c = 2000;
          return;
        }
        if (param_2 < 0xaf) {
          DAT_0043d65c = 3000;
          return;
        }
        if (param_2 < 0xb0) {
          FUN_0040f5f7();
          return;
        }
        if (param_2 == 0xb0) {
          local_84 = (uint)(DAT_0043d574 == 0);
          DAT_0043d574 = local_84;
          if (local_84 != 0) {
            DAT_0043d568 = 0;
            DAT_0043d56c = 0;
            DAT_0043d570 = 0;
            DAT_0043d57c = 0;
          }
          uVar5 = FUN_0041848a(param_1,0xb0);
          DAT_0046239c = (undefined4)uVar5;
          uVar5 = FUN_004182e8(extraout_ECX_06,(int)((ulonglong)uVar5 >> 0x20));
          DAT_004627ac = (undefined4)uVar5;
          DAT_00462398 = DAT_0046239c;
          FUN_004152eb(extraout_ECX_07,(int)((ulonglong)uVar5 >> 0x20));
          return;
        }
      }
    }
  }
  else {
    if (param_2 < 0xbd) {
      DAT_0043d578 = param_2 - 0xb8;
      return;
    }
    if (param_2 < 0xd6) {
      if (param_2 < 200) {
        if (param_2 < 0xc2) {
          if (param_2 < 0xbf) {
            if (0xbd < param_2) {
              DAT_0043d668 = 1;
              return;
            }
            DAT_0043d668 = 0;
            return;
          }
          if (0xbf < param_2) {
            if (0xc0 < param_2) {
              DAT_0043d668 = 4;
              return;
            }
            DAT_0043d668 = 3;
            return;
          }
          DAT_0043d668 = 2;
          return;
        }
        if (param_2 < 0xc3) {
          DAT_0043d668 = 5;
          return;
        }
        if (0xc4 < param_2) {
          if (param_2 < 0xc6) {
            DAT_0043d668 = 8;
            return;
          }
          if (0xc6 < param_2) {
            DAT_0043d668 = 10;
            return;
          }
          DAT_0043d668 = 9;
          return;
        }
        if (0xc3 < param_2) {
          DAT_0043d668 = 7;
          return;
        }
        DAT_0043d668 = 6;
        return;
      }
      if (param_2 < 0xc9) {
        DAT_0043d668 = 0xb;
        return;
      }
      if (param_2 < 0xce) {
        if (param_2 < 0xcb) {
          if (0xc9 < param_2) {
            DAT_0043d668 = 0xd;
            return;
          }
          DAT_0043d668 = 0xc;
          return;
        }
        if (0xcb < param_2) {
          if (0xcc < param_2) {
            DAT_0043d5e4 = 1;
            return;
          }
          DAT_0043d668 = 0xf;
          return;
        }
        DAT_0043d668 = 0xe;
        return;
      }
      if (param_2 < 0xcf) {
        DAT_0043d5e4 = 0;
        return;
      }
      if (0xd1 < param_2) {
        if (param_2 < 0xd3) {
          DAT_0043d700 = 1;
          return;
        }
        if (0xd3 < param_2) {
          if (0xd4 < param_2) {
            DAT_0043d700 = 4;
            return;
          }
          DAT_0043d700 = 3;
          return;
        }
        DAT_0043d700 = 2;
        return;
      }
      if (param_2 < 0xd0) {
        DAT_0043d5e8 = 1;
        return;
      }
      if (param_2 == 0xd0) {
        DAT_0043d5e8 = 0;
        return;
      }
    }
    else {
      if (param_2 < 0xd7) {
        DAT_0043d700 = 5;
        return;
      }
      if (param_2 < 0x834) {
        if (param_2 < 0xdc) {
          if (param_2 < 0xd9) {
            if (0xd7 < param_2) {
              DAT_0043d700 = 7;
              return;
            }
            DAT_0043d700 = 6;
            return;
          }
          if (0xd9 < param_2) {
            if (0xda < param_2) {
              DAT_0043d700 = 10;
              return;
            }
            DAT_0043d700 = 9;
            return;
          }
          DAT_0043d700 = 8;
          return;
        }
        if (param_2 < 0xdd) {
          DAT_0043d700 = 0xb;
          return;
        }
        if (param_2 < 0xdf) {
          if (0xdd < param_2) {
            DAT_0043d700 = 0xd;
            return;
          }
          DAT_0043d700 = 0xc;
          return;
        }
        if (param_2 < 0xe0) {
          DAT_0043d700 = 0xe;
          return;
        }
        if (param_2 < 0xe1) {
          DAT_0043d700 = 0xf;
          return;
        }
        if (param_2 == 0x7d3) {
          PostMessageA(in_EAX,0x10,0,0);
          return;
        }
      }
      else {
        if (param_2 < 0x835) {
          SendMessageA(DAT_004627c8,0x227,0,0);
          return;
        }
        if (param_2 < 0x1782) {
          if (param_2 < 0x837) {
            if (0x835 < param_2) {
              SendMessageA(DAT_004627c8,0x226,1,0);
              return;
            }
            SendMessageA(DAT_004627c8,0x226,0,0);
            return;
          }
          if (param_2 < 0x838) {
            SendMessageA(DAT_004627c8,0x228,0,0);
            return;
          }
          if (0x897 < param_2) {
            if (param_2 < 0x899) {
              FUN_004152ae();
              return;
            }
            if (param_2 == 0x1781) {
              DAT_0043d5d8 = 0;
              return;
            }
          }
        }
        else {
          if (param_2 < 0x1783) {
            DAT_0043d5d8 = 1;
            return;
          }
          if (param_2 < 0x178a) {
            if (0x1783 < param_2) {
              if (param_2 < 0x1785) {
                DAT_0043d65c = 4000;
                return;
              }
              if (param_2 == 0x1785) {
                DAT_0043d65c = 5000;
                return;
              }
            }
          }
          else {
            if (param_2 < 0x178b) {
              DAT_0043d5e0 = 1;
              return;
            }
            if (param_2 < 0x178c) {
              DAT_0043d5e0 = 0;
              return;
            }
            if (param_2 < 0x178d) {
              local_78 = (uint)(DAT_0043d564 == 0);
              FUN_00417864(param_1,local_78);
              return;
            }
            if (param_2 == 0x1792) {
              if (DAT_0043d724 != -1) {
                Ordinal_3(DAT_0043d724);
                DAT_0043d724 = 0xffffffff;
                return;
              }
              if (DAT_0043d720 == -1) {
                return;
              }
              Ordinal_3(DAT_0043d720);
              DAT_0043d720 = 0xffffffff;
              return;
            }
          }
        }
      }
    }
  }
LAB_0041aa74:
  FUN_0041736b(unaff_EBX,0x111);
  return;
}


