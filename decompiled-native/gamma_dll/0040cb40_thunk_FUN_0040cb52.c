// 0040cb40 thunk_FUN_0040cb52 [Global]
// program: gamma.dll

/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT thunk_FUN_0040cb52(void)

{
  char *pcVar1;
  bool bVar2;
  short sVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  ushort uVar7;
  HDC hdc;
  HPALETTE hPal;
  UINT UVar8;
  LONG LVar9;
  int *piVar10;
  uint uVar11;
  BOOL BVar12;
  LRESULT LVar13;
  HWND pHVar14;
  uint extraout_EDX;
  uint unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  int iVar15;
  void *unaff_EDI;
  int iVar16;
  uint uVar17;
  longlong lVar18;
  BOOL BVar19;
  
  do {
    if (unaff_EBX != 0) {
      FUN_0040c2c0(unaff_EDI,2,unaff_EBX);
    }
    do {
      uVar17 = unaff_ESI;
      unaff_ESI = uVar17 - 1;
      if ((int)unaff_ESI < 0) {
        if (DAT_00489220 == 1) {
          if (((((*(int *)(unaff_EBP + 0x10) == 0x202) || (*(int *)(unaff_EBP + 0x10) == 0x208)) ||
               (*(int *)(unaff_EBP + 0x10) == 0x205)) || (*(int *)(unaff_EBP + 0x10) == 0x200)) &&
             ((*(uint *)(unaff_EBP + 0x14) & 0x13) == 0)) {
            DAT_00489220 = 0;
          }
          else {
            pHVar14 = GetCapture();
            if (pHVar14 != (HWND)0x0) {
              *(undefined **)(unaff_EBP + -0x168) = &DAT_004891f8;
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891f8);
              GetCursorPos((LPPOINT)&DAT_00489224);
              DAT_0048922c = DAT_00489224;
              DAT_00489230 = DAT_00489228;
              ShowCursor(0);
              DAT_00489220 = 2;
              DAT_00489234 = 0;
              DAT_00489238 = 0;
              LeaveCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x168));
            }
          }
        }
        iVar16 = *(int *)(unaff_EBP + 0x10);
        if (iVar16 == 0x20) {
          if (DAT_004892c0 == '\0') {
            DAT_004892c0 = '\x01';
            DAT_004892bc = 0;
          }
          if (*(int *)(unaff_EBP + 0xc) != DAT_004892bc) {
            *(undefined **)(unaff_EBP + -0x158) = &DAT_004891d0;
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891d0);
            piVar10 = FUN_0040f560(*(int *)(unaff_EBP + 0xc));
            if ((piVar10 != (int *)0x0) && (DAT_0049ff1c == piVar10)) {
              FUN_0040c2c0(piVar10,8,0);
            }
            piVar10 = FUN_0040f560(DAT_004892bc);
            if ((piVar10 != (int *)0x0) && (DAT_0049ff1c == piVar10)) {
              FUN_0040c2c0(piVar10,9,0);
            }
            DAT_004892bc = *(undefined4 *)(unaff_EBP + 0xc);
            LeaveCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x158));
            return 0;
          }
          if ((DAT_004891c8 != (HCURSOR)0x0) && ((short)*(undefined4 *)(unaff_EBP + 0x18) == 1)) {
            SetCursor(DAT_004891c8);
            return 0;
          }
          goto LAB_0040cf73;
        }
        if (iVar16 == 0x200) {
          if ((DAT_00489220 == 2) && (pHVar14 = GetCapture(), pHVar14 != (HWND)0x0)) {
            *(undefined **)(unaff_EBP + -0x164) = &DAT_004891f8;
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891f8);
            GetCursorPos((LPPOINT)(unaff_EBP + -0x160));
            iVar16 = *(int *)(unaff_EBP + -0x15c);
            DAT_00489234 = DAT_00489234 + (*(int *)(unaff_EBP + -0x160) - DAT_0048922c);
            DAT_0048922c = *(int *)(unaff_EBP + -0x160);
            DAT_00489238 = DAT_00489238 + (iVar16 - DAT_00489230);
            if ((DAT_0048922c < 0xa0) ||
               (((0x1e0 < DAT_0048922c || (iVar16 < 0x78)) ||
                (DAT_00489230 = iVar16, 0x168 < iVar16)))) {
              DAT_0048922c = 0x140;
              DAT_00489230 = 0xf0;
              *(undefined4 *)(unaff_EBP + -0x10) = 0xf0;
              *(undefined4 *)(unaff_EBP + -0x14) = 0x140;
              SetCursorPos(0x140,0xf0);
            }
            LeaveCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x164));
          }
          goto LAB_0040cf73;
        }
        if (iVar16 == 0x201) {
          DAT_004892a0 = *(undefined4 *)(unaff_EBP + 0xc);
          _DAT_004892a4 = *(undefined4 *)(unaff_EBP + 0x14);
          _DAT_004892a8 = *(undefined4 *)(unaff_EBP + 0x18);
          if ((*(int *)(unaff_EBP + 0xc) != DAT_004891c0) || (DAT_004891cc != 0)) {
            DAT_00489244 = DAT_00489244 + 1;
          }
          goto LAB_0040cf73;
        }
        if (iVar16 == 0x202) {
          if (DAT_00489220 == 2) {
            SetCursorPos(DAT_00489224,DAT_00489228);
            ShowCursor(1);
            DAT_00489220 = 0;
          }
          goto LAB_0040cf73;
        }
        if (iVar16 != 0x210) {
          if (iVar16 == 0x30f) {
            hdc = GetDC(*(HWND *)(unaff_EBP + 0xc));
            BVar19 = 0;
            hPal = FUN_0040d7a0();
            SelectPalette(hdc,hPal,BVar19);
            UVar8 = RealizePalette(hdc);
            if (UVar8 != 0) {
              InvalidateRect(*(HWND *)(unaff_EBP + 0xc),(RECT *)0x0,1);
              UpdateWindow(*(HWND *)(unaff_EBP + 0xc));
            }
            ReleaseDC(*(HWND *)(unaff_EBP + 0xc),hdc);
            return 1;
          }
          goto LAB_0040cf73;
        }
        if ((short)*(undefined4 *)(unaff_EBP + 0x14) != 1) goto LAB_0040cf73;
        LVar9 = GetWindowLongA(*(HWND *)(unaff_EBP + 0x18),-4);
        iVar16 = DAT_00489248;
        iVar15 = 0;
        if (0 < DAT_00489248) goto LAB_0040cf10;
        goto LAB_0040cf22;
      }
    } while ((1 << ((byte)unaff_ESI & 0x1f) & *(uint *)(&DAT_0048927c + ((int)unaff_ESI >> 5) * 4))
             == 0);
    if (unaff_ESI < 0x100) {
      unaff_EBX = unaff_ESI;
      if (((unaff_ESI < 0x30) || (0x39 < unaff_ESI)) && ((unaff_ESI < 0x41 || (0x5a < unaff_ESI))))
      {
        if (uVar17 == 0x21) {
                    /* WARNING: Could not recover jumptable at 0x0040cb39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          LVar13 = (*(code *)PTR_thunk_FUN_0040cb52_0046ef38)();
          return LVar13;
        }
        unaff_EBX = unaff_ESI | 0xe300;
      }
    }
    else {
      unaff_EBX = 0;
    }
  } while( true );
  while (iVar15 = iVar15 + 1, iVar15 < DAT_00489248) {
LAB_0040cf10:
    if ((&DAT_00489254)[iVar15] == LVar9) break;
  }
LAB_0040cf22:
  if (iVar15 == DAT_00489248) {
    if (DAT_00489248 < 8) {
      DAT_00489248 = DAT_00489248 + 1;
      (&DAT_00489254)[iVar16] = LVar9;
      goto LAB_0040cf60;
    }
    FUN_00403350(0x49eda8,(byte *)s_No_more_window_procedures_for_su_0046e920);
  }
  else {
LAB_0040cf60:
    SetWindowLongA(*(HWND *)(unaff_EBP + 0x18),-4,(LONG)(&PTR_FUN_0046e900)[iVar15]);
  }
LAB_0040cf73:
  bVar2 = *(int *)(unaff_EBP + 0x10) - 0x100U < 2;
  if ((bVar2) || (*(int *)(unaff_EBP + 0x10) == 0x102)) {
    if (*(int *)(unaff_EBP + 0x10) != 0x101) {
      DAT_00489244 = DAT_00489244 + 1;
    }
    if (DAT_0049ff1c == (int *)0x0) {
      iVar16 = 0;
    }
    else {
      iVar16 = *DAT_0049ff1c;
    }
    if ((iVar16 != 0) && (DAT_004a0008 != 0)) {
      bVar4 = false;
      bVar6 = false;
      bVar5 = false;
      if ((bVar2) && (0x20 < *(uint *)(unaff_EBP + 0x14))) {
        bVar4 = true;
      }
      if ((bVar4) && (*(uint *)(unaff_EBP + 0x14) < 0x29)) {
        bVar5 = true;
      }
      if ((bVar5) && (*(int *)(unaff_EBP + 0x14) != 0x23)) {
        bVar6 = true;
      }
      if ((bVar6) &&
         ((*(int *)(unaff_EBP + 0xc) == DAT_004891c0 || (*(int *)(unaff_EBP + 0xc) == DAT_004a0008))
         )) {
        *(int *)(unaff_EBP + 0xc) = iVar16;
      }
    }
  }
  *(undefined **)(unaff_EBP + -0x154) = &DAT_004891d0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891d0);
  piVar10 = FUN_0040f560(*(int *)(unaff_EBP + 0xc));
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EBP + -0x154));
  if (piVar10 == (int *)0x0) {
    if (*(int *)(unaff_EBP + 0xc) == DAT_004891c0) {
      iVar16 = *(int *)(unaff_EBP + 0x10);
      if (iVar16 == 5) {
        if ((*(int *)(unaff_EBP + 0x14) == 2) || (*(int *)(unaff_EBP + 0x14) == 0)) {
          FUN_0040ef80(1,(uint)(*(int *)(unaff_EBP + 0x14) == 2));
        }
      }
      else if (iVar16 == 6) {
        iVar16 = 0;
        sVar3 = (short)*(undefined4 *)(unaff_EBP + 0x14);
        if ((sVar3 != 0) && ((short)((uint)*(undefined4 *)(unaff_EBP + 0x14) >> 0x10) == 0)) {
          iVar16 = 1;
        }
        FUN_0040ef80(iVar16,0);
        piVar10 = DAT_0049ff1c;
        if (*(int *)(unaff_EBP + 0x14) == 0) {
          DAT_0048929c = -1;
          if (DAT_0049ff1c != (int *)0x0) {
            if ((char)DAT_0049ff1c[9] != '\0') {
              SendMessageA((HWND)*DAT_0049ff1c,0x8065,0,0);
              *(undefined1 *)(piVar10 + 9) = 0;
            }
            uVar17 = 0xff;
            do {
              if ((1 << ((byte)uVar17 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar17 >> 5) * 4))
                  != 0) {
                if (uVar17 < 0x100) {
                  uVar11 = uVar17;
                  if (((uVar17 < 0x30) || (0x39 < uVar17)) && ((uVar17 < 0x41 || (0x5a < uVar17))))
                  {
                    if (uVar17 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d5ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                      LVar13 = (*(code *)PTR_thunk_FUN_0040d612_0046ef24)();
                      return LVar13;
                    }
                    uVar11 = uVar17 | 0xe300;
                  }
                }
                else {
                  uVar11 = 0;
                }
                if (uVar11 != 0) {
                  FUN_0040c2c0(piVar10,2,uVar11);
                }
              }
              uVar17 = uVar17 - 1;
            } while (-1 < (int)uVar17);
          }
        }
        else {
          _DAT_0046e8a4 = 1;
        }
        if ((sVar3 != 0) && (DAT_0048929c < 0)) {
          DAT_0048929c = 0;
        }
      }
      else {
        if (iVar16 == 0x4a) {
          pcVar1 = *(char **)(*(int *)(unaff_EBP + 0x18) + 8);
          ShowWindow(*(HWND *)(unaff_EBP + 0xc),9);
          SetForegroundWindow(*(HWND *)(unaff_EBP + 0xc));
          FUN_00416aa0(&DAT_0049f848,pcVar1);
          return 0;
        }
        if (iVar16 == 0x8067) {
          BVar19 = GetCursorPos((LPPOINT)(unaff_EBP + -0x150));
          BVar12 = GetWindowRect(*(HWND *)(unaff_EBP + 0xc),(LPRECT)(unaff_EBP + -0x148));
          if ((BVar19 != 0) && (BVar12 != 0)) {
            *(int *)(unaff_EBP + -0x14c) =
                 *(int *)(unaff_EBP + -0x14c) - *(int *)(unaff_EBP + -0x144);
            *(int *)(unaff_EBP + -0x150) =
                 *(int *)(unaff_EBP + -0x150) - *(int *)(unaff_EBP + -0x148);
            DAT_004891c8 = *(HCURSOR *)(unaff_EBP + 0x14);
            pHVar14 = ChildWindowFromPointEx
                                (*(HWND *)(unaff_EBP + 0xc),*(POINT *)(unaff_EBP + -0x150),0);
            if ((pHVar14 != (HWND)0x0) || (pHVar14 = GetCapture(), pHVar14 != (HWND)0x0)) {
              SetCursor(DAT_004891c8);
              return 0;
            }
          }
        }
      }
    }
    goto LAB_0040d750;
  }
  if (*(int *)(unaff_EBP + 0x10) == DAT_00489250) {
    DAT_0049f390 = *(undefined4 *)(unaff_EBP + 0x14);
    DAT_0049f394 = *(undefined4 *)(unaff_EBP + 0x18);
  }
  if (DAT_0049ff1c == piVar10) {
    uVar17 = extraout_EDX;
    if ((0xff < *(uint *)(unaff_EBP + 0x10)) && (*(uint *)(unaff_EBP + 0x10) < 0x109)) {
      lVar18 = FUN_0040c440(piVar10,extraout_EDX,*(int *)(unaff_EBP + 0x10),
                            *(uint *)(unaff_EBP + 0x14),*(int *)(unaff_EBP + 0x18));
      uVar17 = (uint)((ulonglong)lVar18 >> 0x20);
      if ((int)lVar18 != 0) {
        return 0;
      }
    }
    iVar16 = *(int *)(unaff_EBP + 0x10);
    if (iVar16 == 8) {
      if ((char)piVar10[9] != '\0') {
        SendMessageA((HWND)*piVar10,0x8065,0,0);
        *(undefined1 *)(piVar10 + 9) = 0;
      }
      uVar17 = 0xff;
      do {
        if ((1 << ((byte)uVar17 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar17 >> 5) * 4)) != 0) {
          if (uVar17 < 0x100) {
            uVar11 = uVar17;
            if (((uVar17 < 0x30) || (0x39 < uVar17)) && ((uVar17 < 0x41 || (0x5a < uVar17)))) {
              if (uVar17 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d479. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                LVar13 = (*(code *)PTR_thunk_FUN_0040d492_0046ef28)();
                return LVar13;
              }
              uVar11 = uVar17 | 0xe300;
            }
          }
          else {
            uVar11 = 0;
          }
          if (uVar11 != 0) {
            FUN_0040c2c0(piVar10,2,uVar11);
          }
        }
        uVar17 = uVar17 - 1;
      } while (-1 < (int)uVar17);
      goto LAB_0040d750;
    }
    if (iVar16 == 0x111) {
      uVar7 = (ushort)*(uint *)(unaff_EBP + 0x14);
      if ((99 < uVar7) && (uVar7 < 200)) {
        DAT_0049ff2c = *(uint *)(unaff_EBP + 0x14) & 0xffff;
        return 0;
      }
      goto LAB_0040d750;
    }
    if (iVar16 == 0x200) {
      LVar13 = FUN_0040c2c0(piVar10,6,0);
      return LVar13;
    }
    if (iVar16 == 0x201) {
      if ((*(uint *)(unaff_EBP + 0x14) & 1) != 0) {
        FUN_0040c440(piVar10,uVar17,0x100,1,0);
      }
      return 0;
    }
    if (iVar16 == 0x202) {
      FUN_0040c440(piVar10,uVar17,0x101,1,0);
      if ((*(uint *)(unaff_EBP + 0x14) & 0x13) == 0) {
        if ((char)piVar10[9] != '\0') {
          SendMessageA((HWND)*piVar10,0x8065,0,0);
          *(undefined1 *)(piVar10 + 9) = 0;
        }
        uVar17 = 0xff;
        do {
          if ((1 << ((byte)uVar17 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar17 >> 5) * 4)) != 0)
          {
            if (uVar17 < 0x100) {
              uVar11 = uVar17;
              if (((uVar17 < 0x30) || (0x39 < uVar17)) && ((uVar17 < 0x41 || (0x5a < uVar17)))) {
                if (uVar17 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d1f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  LVar13 = (*(code *)PTR_thunk_FUN_0040d20a_0046ef34)();
                  return LVar13;
                }
                uVar11 = uVar17 | 0xe300;
              }
            }
            else {
              uVar11 = 0;
            }
            if (uVar11 != 0) {
              FUN_0040c2c0(piVar10,2,uVar11);
            }
          }
          uVar17 = uVar17 - 1;
        } while (-1 < (int)uVar17);
      }
      return 0;
    }
    if (iVar16 == 0x204) {
      FUN_0040c440(piVar10,uVar17,0x100,2,0);
      return 0;
    }
    if (iVar16 == 0x205) {
      FUN_0040c440(piVar10,uVar17,0x101,2,0);
      if ((*(uint *)(unaff_EBP + 0x14) & 0x13) == 0) {
        if ((char)piVar10[9] != '\0') {
          SendMessageA((HWND)*piVar10,0x8065,0,0);
          *(undefined1 *)(piVar10 + 9) = 0;
        }
        uVar17 = 0xff;
        do {
          if ((1 << ((byte)uVar17 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar17 >> 5) * 4)) != 0)
          {
            if (uVar17 < 0x100) {
              uVar11 = uVar17;
              if (((uVar17 < 0x30) || (0x39 < uVar17)) && ((uVar17 < 0x41 || (0x5a < uVar17)))) {
                if (uVar17 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  LVar13 = (*(code *)PTR_thunk_FUN_0040d2ca_0046ef30)();
                  return LVar13;
                }
                uVar11 = uVar17 | 0xe300;
              }
            }
            else {
              uVar11 = 0;
            }
            if (uVar11 != 0) {
              FUN_0040c2c0(piVar10,2,uVar11);
            }
          }
          uVar17 = uVar17 - 1;
        } while (-1 < (int)uVar17);
      }
      return 0;
    }
    if (iVar16 == 0x207) {
      FUN_0040c440(piVar10,uVar17,0x100,4,0);
      return 0;
    }
    if (iVar16 == 0x208) {
      FUN_0040c440(piVar10,uVar17,0x101,4,0);
      if ((*(uint *)(unaff_EBP + 0x14) & 0x13) == 0) {
        if ((char)piVar10[9] != '\0') {
          SendMessageA((HWND)*piVar10,0x8065,0,0);
          *(undefined1 *)(piVar10 + 9) = 0;
        }
        uVar17 = 0xff;
        do {
          if ((1 << ((byte)uVar17 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar17 >> 5) * 4)) != 0)
          {
            if (uVar17 < 0x100) {
              uVar11 = uVar17;
              if (((uVar17 < 0x30) || (0x39 < uVar17)) && ((uVar17 < 0x41 || (0x5a < uVar17)))) {
                if (uVar17 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  LVar13 = (*(code *)PTR_thunk_FUN_0040d38a_0046ef2c)();
                  return LVar13;
                }
                uVar11 = uVar17 | 0xe300;
              }
            }
            else {
              uVar11 = 0;
            }
            if (uVar11 != 0) {
              FUN_0040c2c0(piVar10,2,uVar11);
            }
          }
          uVar17 = uVar17 - 1;
        } while (-1 < (int)uVar17);
      }
      return 0;
    }
    if (iVar16 == 0x4c8) {
      LVar13 = FUN_00405670(*(HWND *)(unaff_EBP + 0xc));
      return LVar13;
    }
    if (iVar16 == 0x8065) {
      LVar13 = FUN_0040c780(piVar10,*(uint *)(unaff_EBP + 0x14));
      return LVar13;
    }
  }
  if (*(int *)(unaff_EBP + 0x10) == 0x14) {
    return 1;
  }
  if (*(int *)(unaff_EBP + 0x10) == 0x8068) {
    DAT_004892b8 = *(HWND *)(unaff_EBP + 0xc);
    if (DAT_004892b8 == (HWND)0x0) {
      if (DAT_0049ff1c == (int *)0x0) {
        pHVar14 = (HWND)0x0;
      }
      else {
        pHVar14 = (HWND)*DAT_0049ff1c;
      }
      SetFocus(pHVar14);
    }
    else {
      SetFocus(DAT_004892b8);
      DAT_004892b8 = (HWND)0x0;
    }
    return 0;
  }
LAB_0040d750:
  LVar13 = CallWindowProcA((WNDPROC)(&DAT_00489254)[*(int *)(unaff_EBP + 8)],
                           *(HWND *)(unaff_EBP + 0xc),*(UINT *)(unaff_EBP + 0x10),
                           *(WPARAM *)(unaff_EBP + 0x14),*(LPARAM *)(unaff_EBP + 0x18));
  return LVar13;
}


