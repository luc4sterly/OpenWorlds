// 0040c970 FUN_0040c970 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

LRESULT __cdecl FUN_0040c970(int param_1,HWND param_2,uint param_3,HWND param_4,HWND param_5)

{
  byte bVar1;
  char *pcVar2;
  bool bVar3;
  POINT pt;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  ushort uVar7;
  int *piVar8;
  HDC hdc;
  HPALETTE hPal;
  UINT UVar9;
  LONG LVar10;
  uint uVar11;
  BOOL BVar12;
  LRESULT LVar13;
  int iVar14;
  HWND pHVar15;
  uint extraout_EDX;
  int iVar16;
  byte *pbVar17;
  uint uVar18;
  longlong lVar19;
  BOOL BVar20;
  tagPOINT local_164;
  LPCRITICAL_SECTION local_15c;
  LPCRITICAL_SECTION local_158;
  tagPOINT local_154;
  tagRECT local_14c;
  byte local_13c [4];
  char acStack_138 [4];
  char acStack_134 [4];
  char acStack_130 [2];
  char cStack_12e;
  byte local_12c [4];
  char acStack_128 [4];
  char acStack_124 [4];
  char acStack_120 [4];
  char acStack_11c [4];
  byte local_118 [256];
  undefined4 local_18;
  undefined4 local_14;
  
  if (param_3 == DAT_0048924c) {
    return DAT_0049f960;
  }
  pHVar15 = param_4;
  if (param_3 == 8) {
    for (; pHVar15 != (HWND)0x0; pHVar15 = GetParent(pHVar15)) {
      GetClassNameA(pHVar15,(LPSTR)local_118,0x100);
      local_12c[0] = s_RenderCanvasOverlay_0046e94c[0];
      local_12c[1] = s_RenderCanvasOverlay_0046e94c[1];
      local_12c[2] = s_RenderCanvasOverlay_0046e94c[2];
      local_12c[3] = s_RenderCanvasOverlay_0046e94c[3];
      acStack_128[0] = s_RenderCanvasOverlay_0046e94c[4];
      acStack_128[1] = s_RenderCanvasOverlay_0046e94c[5];
      acStack_128[2] = s_RenderCanvasOverlay_0046e94c[6];
      acStack_128[3] = s_RenderCanvasOverlay_0046e94c[7];
      acStack_124[0] = s_RenderCanvasOverlay_0046e94c[8];
      acStack_124[1] = s_RenderCanvasOverlay_0046e94c[9];
      acStack_124[2] = s_RenderCanvasOverlay_0046e94c[10];
      acStack_124[3] = s_RenderCanvasOverlay_0046e94c[0xb];
      acStack_120[0] = s_RenderCanvasOverlay_0046e94c[0xc];
      acStack_120[1] = s_RenderCanvasOverlay_0046e94c[0xd];
      acStack_120[2] = s_RenderCanvasOverlay_0046e94c[0xe];
      acStack_120[3] = s_RenderCanvasOverlay_0046e94c[0xf];
      acStack_11c[0] = s_RenderCanvasOverlay_0046e94c[0x10];
      acStack_11c[1] = s_RenderCanvasOverlay_0046e94c[0x11];
      acStack_11c[2] = s_RenderCanvasOverlay_0046e94c[0x12];
      acStack_11c[3] = s_RenderCanvasOverlay_0046e94c[0x13];
      local_13c[0] = s_TextureSurface_0046e960[0];
      local_13c[1] = s_TextureSurface_0046e960[1];
      local_13c[2] = s_TextureSurface_0046e960[2];
      local_13c[3] = s_TextureSurface_0046e960[3];
      acStack_138[0] = s_TextureSurface_0046e960[4];
      acStack_138[1] = s_TextureSurface_0046e960[5];
      acStack_138[2] = s_TextureSurface_0046e960[6];
      acStack_138[3] = s_TextureSurface_0046e960[7];
      acStack_134[0] = s_TextureSurface_0046e960[8];
      acStack_134[1] = s_TextureSurface_0046e960[9];
      acStack_134[2] = s_TextureSurface_0046e960[10];
      acStack_134[3] = s_TextureSurface_0046e960[0xb];
      acStack_130[0] = s_TextureSurface_0046e960[0xc];
      acStack_130[1] = s_TextureSurface_0046e960[0xd];
      cStack_12e = s_TextureSurface_0046e960[0xe];
      iVar14 = -1;
      pbVar17 = local_12c;
      do {
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        bVar1 = *pbVar17;
        pbVar17 = pbVar17 + 1;
      } while (bVar1 != 0);
      iVar14 = FUN_0044d760(local_118,local_12c,-2 - iVar14);
      if (iVar14 == 0) {
        piVar8 = (int *)GetWindowLongA(pHVar15,-0x15);
        iVar14 = *piVar8;
        goto LAB_0040ca6a;
      }
      iVar14 = -1;
      pbVar17 = local_13c;
      do {
        if (iVar14 == 0) break;
        iVar14 = iVar14 + -1;
        bVar1 = *pbVar17;
        pbVar17 = pbVar17 + 1;
      } while (bVar1 != 0);
      iVar14 = FUN_0044d760(local_118,local_13c,-2 - iVar14);
      if (iVar14 == 0) {
        iVar14 = 0;
        goto LAB_0040ca6a;
      }
    }
    iVar14 = 1;
LAB_0040ca6a:
    piVar8 = DAT_0049ff1c;
    if (iVar14 == 0) {
      PostMessageA(param_2,0x8068,0,0);
    }
    else if ((param_4 != DAT_004891c0) && (param_4 != DAT_004a0008)) {
      if (DAT_0049ff1c == (int *)0x0) {
        pHVar15 = (HWND)0x0;
      }
      else {
        pHVar15 = (HWND)*DAT_0049ff1c;
      }
      if ((param_4 != pHVar15) && (DAT_0049ff1c != (int *)0x0)) {
        if ((char)DAT_0049ff1c[9] != '\0') {
          SendMessageA((HWND)*DAT_0049ff1c,0x8065,0,0);
          *(undefined1 *)(piVar8 + 9) = 0;
        }
        uVar18 = 0xff;
        do {
          if ((1 << ((byte)uVar18 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar18 >> 5) * 4)) != 0)
          {
            if (uVar18 < 0x100) {
              uVar11 = uVar18;
              if (((uVar18 < 0x30) || (0x39 < uVar18)) && ((uVar18 < 0x41 || (0x5a < uVar18)))) {
                if (uVar18 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040cb39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  LVar13 = (*(code *)PTR_DAT_0046ef38)();
                  return LVar13;
                }
                uVar11 = uVar18 | 0xe300;
              }
            }
            else {
              uVar11 = 0;
            }
            if (uVar11 != 0) {
              FUN_0040c2c0(piVar8,2,uVar11);
            }
          }
          uVar18 = uVar18 - 1;
        } while (-1 < (int)uVar18);
      }
    }
  }
  if (DAT_00489220 == 1) {
    if (((((param_3 == 0x202) || (param_3 == 0x208)) || (param_3 == 0x205)) || (param_3 == 0x200))
       && (((uint)param_4 & 0x13) == 0)) {
      DAT_00489220 = 0;
    }
    else {
      pHVar15 = GetCapture();
      if (pHVar15 != (HWND)0x0) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891f8);
        GetCursorPos((LPPOINT)&DAT_00489224);
        DAT_0048922c = DAT_00489224;
        DAT_00489230 = DAT_00489228;
        ShowCursor(0);
        DAT_00489220 = 2;
        DAT_00489234 = 0;
        DAT_00489238 = 0;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004891f8);
      }
    }
  }
  uVar7 = (ushort)param_4;
  if (param_3 == 0x20) {
    if (DAT_004892c0 == '\0') {
      DAT_004892c0 = '\x01';
      DAT_004892bc = (HWND)0x0;
    }
    if (param_2 != DAT_004892bc) {
      local_15c = (LPCRITICAL_SECTION)&DAT_004891d0;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891d0);
      piVar8 = FUN_0040f560((int)param_2);
      if ((piVar8 != (int *)0x0) && (DAT_0049ff1c == piVar8)) {
        FUN_0040c2c0(piVar8,8,0);
      }
      piVar8 = FUN_0040f560((int)DAT_004892bc);
      if ((piVar8 != (int *)0x0) && (DAT_0049ff1c == piVar8)) {
        FUN_0040c2c0(piVar8,9,0);
      }
      DAT_004892bc = param_2;
      LeaveCriticalSection(local_15c);
      return 0;
    }
    if ((DAT_004891c8 != (HCURSOR)0x0) && ((short)param_5 == 1)) {
      SetCursor(DAT_004891c8);
      return 0;
    }
  }
  else if (param_3 == 0x200) {
    if ((DAT_00489220 == 2) && (pHVar15 = GetCapture(), pHVar15 != (HWND)0x0)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891f8);
      GetCursorPos(&local_164);
      DAT_00489234 = DAT_00489234 + (local_164.x - DAT_0048922c);
      DAT_00489238 = DAT_00489238 + (local_164.y - DAT_00489230);
      DAT_0048922c = local_164.x;
      DAT_00489230 = local_164.y;
      if ((local_164.x < 0xa0) ||
         (((0x1e0 < local_164.x || (local_164.y < 0x78)) || (0x168 < local_164.y)))) {
        DAT_0048922c = 0x140;
        DAT_00489230 = 0xf0;
        local_14 = 0xf0;
        local_18 = 0x140;
        SetCursorPos(0x140,0xf0);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_004891f8);
    }
  }
  else if (param_3 == 0x201) {
    DAT_004892a0 = param_2;
    _DAT_004892a4 = param_4;
    _DAT_004892a8 = param_5;
    if ((param_2 != DAT_004891c0) || (DAT_004891cc != 0)) {
      DAT_00489244 = DAT_00489244 + 1;
    }
  }
  else if (param_3 == 0x202) {
    if (DAT_00489220 == 2) {
      SetCursorPos(DAT_00489224,DAT_00489228);
      ShowCursor(1);
      DAT_00489220 = 0;
    }
  }
  else if (param_3 == 0x210) {
    if (uVar7 == 1) {
      LVar10 = GetWindowLongA(param_5,-4);
      iVar14 = DAT_00489248;
      iVar16 = 0;
      if (0 < DAT_00489248) {
        do {
          if ((&DAT_00489254)[iVar16] == LVar10) break;
          iVar16 = iVar16 + 1;
        } while (iVar16 < DAT_00489248);
      }
      if (iVar16 == DAT_00489248) {
        if (7 < DAT_00489248) {
          FUN_00403350(0x49eda8,(byte *)s_No_more_window_procedures_for_su_0046e920);
          goto LAB_0040cf73;
        }
        DAT_00489248 = DAT_00489248 + 1;
        (&DAT_00489254)[iVar14] = LVar10;
      }
      SetWindowLongA(param_5,-4,(LONG)(&PTR_LAB_0046e900)[iVar16]);
    }
  }
  else if (param_3 == 0x30f) {
    hdc = GetDC(param_2);
    BVar20 = 0;
    hPal = FUN_0040d7a0();
    SelectPalette(hdc,hPal,BVar20);
    UVar9 = RealizePalette(hdc);
    if (UVar9 != 0) {
      InvalidateRect(param_2,(RECT *)0x0,1);
      UpdateWindow(param_2);
    }
    ReleaseDC(param_2,hdc);
    return 1;
  }
LAB_0040cf73:
  bVar3 = param_3 - 0x100 < 2;
  if ((bVar3) || (param_3 == 0x102)) {
    if (param_3 != 0x101) {
      DAT_00489244 = DAT_00489244 + 1;
    }
    if (DAT_0049ff1c == (int *)0x0) {
      pHVar15 = (HWND)0x0;
    }
    else {
      pHVar15 = (HWND)*DAT_0049ff1c;
    }
    if ((pHVar15 != (HWND)0x0) && (DAT_004a0008 != (HWND)0x0)) {
      bVar4 = false;
      bVar6 = false;
      bVar5 = false;
      if ((bVar3) && ((HWND)0x20 < param_4)) {
        bVar4 = true;
      }
      if ((bVar4) && (param_4 < (HWND)0x29)) {
        bVar5 = true;
      }
      if ((bVar5) && (param_4 != (HWND)0x23)) {
        bVar6 = true;
      }
      if ((bVar6) && ((param_2 == DAT_004891c0 || (param_2 == DAT_004a0008)))) {
        param_2 = pHVar15;
      }
    }
  }
  local_158 = (LPCRITICAL_SECTION)&DAT_004891d0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_004891d0);
  piVar8 = FUN_0040f560((int)param_2);
  LeaveCriticalSection(local_158);
  if (piVar8 == (int *)0x0) {
    if (param_2 == DAT_004891c0) {
      if (param_3 == 5) {
        if ((param_4 == (HWND)0x2) || (param_4 == (HWND)0x0)) {
          FUN_0040ef80(1,(uint)(param_4 == (HWND)0x2));
        }
      }
      else if (param_3 == 6) {
        iVar14 = 0;
        if ((uVar7 != 0) && ((short)((uint)param_4 >> 0x10) == 0)) {
          iVar14 = 1;
        }
        FUN_0040ef80(iVar14,0);
        piVar8 = DAT_0049ff1c;
        if (param_4 == (HWND)0x0) {
          DAT_0048929c = -1;
          if (DAT_0049ff1c != (int *)0x0) {
            if ((char)DAT_0049ff1c[9] != '\0') {
              SendMessageA((HWND)*DAT_0049ff1c,0x8065,0,0);
              *(undefined1 *)(piVar8 + 9) = 0;
            }
            uVar18 = 0xff;
            do {
              if ((1 << ((byte)uVar18 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar18 >> 5) * 4))
                  != 0) {
                if (uVar18 < 0x100) {
                  uVar11 = uVar18;
                  if (((uVar18 < 0x30) || (0x39 < uVar18)) && ((uVar18 < 0x41 || (0x5a < uVar18))))
                  {
                    if (uVar18 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d5ff. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                      LVar13 = (*(code *)PTR_DAT_0046ef24)();
                      return LVar13;
                    }
                    uVar11 = uVar18 | 0xe300;
                  }
                }
                else {
                  uVar11 = 0;
                }
                if (uVar11 != 0) {
                  FUN_0040c2c0(piVar8,2,uVar11);
                }
              }
              uVar18 = uVar18 - 1;
            } while (-1 < (int)uVar18);
          }
        }
        else {
          _DAT_0046e8a4 = 1;
        }
        if ((uVar7 != 0) && (DAT_0048929c < 0)) {
          DAT_0048929c = 0;
        }
      }
      else {
        if (param_3 == 0x4a) {
          pcVar2 = (char *)param_5[2].unused;
          ShowWindow(param_2,9);
          SetForegroundWindow(param_2);
          FUN_00416aa0(&DAT_0049f848,pcVar2);
          return 0;
        }
        if (param_3 == 0x8067) {
          BVar20 = GetCursorPos(&local_154);
          BVar12 = GetWindowRect(param_2,&local_14c);
          if ((BVar20 != 0) && (BVar12 != 0)) {
            local_154.y = local_154.y - local_14c.top;
            local_154.x = local_154.x - local_14c.left;
            DAT_004891c8 = (HCURSOR)param_4;
            pt.y = local_154.y;
            pt.x = local_154.x;
            pHVar15 = ChildWindowFromPointEx(param_2,pt,0);
            if ((pHVar15 != (HWND)0x0) || (pHVar15 = GetCapture(), pHVar15 != (HWND)0x0)) {
              SetCursor(DAT_004891c8);
              return 0;
            }
          }
        }
      }
    }
    goto LAB_0040d750;
  }
  if (param_3 == DAT_00489250) {
    DAT_0049f390 = param_4;
    DAT_0049f394 = param_5;
  }
  if (DAT_0049ff1c == piVar8) {
    uVar18 = extraout_EDX;
    if ((0xff < param_3) && (param_3 < 0x109)) {
      lVar19 = FUN_0040c440(piVar8,extraout_EDX,param_3,(uint)param_4,(int)param_5);
      uVar18 = (uint)((ulonglong)lVar19 >> 0x20);
      if ((int)lVar19 != 0) {
        return 0;
      }
    }
    if (param_3 == 8) {
      if ((char)piVar8[9] != '\0') {
        SendMessageA((HWND)*piVar8,0x8065,0,0);
        *(undefined1 *)(piVar8 + 9) = 0;
      }
      uVar18 = 0xff;
      do {
        if ((1 << ((byte)uVar18 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar18 >> 5) * 4)) != 0) {
          if (uVar18 < 0x100) {
            uVar11 = uVar18;
            if (((uVar18 < 0x30) || (0x39 < uVar18)) && ((uVar18 < 0x41 || (0x5a < uVar18)))) {
              if (uVar18 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d479. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                LVar13 = (*(code *)PTR_DAT_0046ef28)();
                return LVar13;
              }
              uVar11 = uVar18 | 0xe300;
            }
          }
          else {
            uVar11 = 0;
          }
          if (uVar11 != 0) {
            FUN_0040c2c0(piVar8,2,uVar11);
          }
        }
        uVar18 = uVar18 - 1;
      } while (-1 < (int)uVar18);
      goto LAB_0040d750;
    }
    if (param_3 == 0x111) {
      if ((99 < uVar7) && (uVar7 < 200)) {
        DAT_0049ff2c = (uint)param_4 & 0xffff;
        return 0;
      }
      goto LAB_0040d750;
    }
    if (param_3 == 0x200) {
      LVar13 = FUN_0040c2c0(piVar8,6,0);
      return LVar13;
    }
    if (param_3 == 0x201) {
      if (((uint)param_4 & 1) != 0) {
        FUN_0040c440(piVar8,uVar18,0x100,1,0);
      }
      return 0;
    }
    if (param_3 == 0x202) {
      FUN_0040c440(piVar8,uVar18,0x101,1,0);
      if (((uint)param_4 & 0x13) == 0) {
        if ((char)piVar8[9] != '\0') {
          SendMessageA((HWND)*piVar8,0x8065,0,0);
          *(undefined1 *)(piVar8 + 9) = 0;
        }
        uVar18 = 0xff;
        do {
          if ((1 << ((byte)uVar18 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar18 >> 5) * 4)) != 0)
          {
            if (uVar18 < 0x100) {
              uVar11 = uVar18;
              if (((uVar18 < 0x30) || (0x39 < uVar18)) && ((uVar18 < 0x41 || (0x5a < uVar18)))) {
                if (uVar18 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d1f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  LVar13 = (*(code *)PTR_DAT_0046ef34)();
                  return LVar13;
                }
                uVar11 = uVar18 | 0xe300;
              }
            }
            else {
              uVar11 = 0;
            }
            if (uVar11 != 0) {
              FUN_0040c2c0(piVar8,2,uVar11);
            }
          }
          uVar18 = uVar18 - 1;
        } while (-1 < (int)uVar18);
      }
      return 0;
    }
    if (param_3 == 0x204) {
      FUN_0040c440(piVar8,uVar18,0x100,2,0);
      return 0;
    }
    if (param_3 == 0x205) {
      FUN_0040c440(piVar8,uVar18,0x101,2,0);
      if (((uint)param_4 & 0x13) == 0) {
        if ((char)piVar8[9] != '\0') {
          SendMessageA((HWND)*piVar8,0x8065,0,0);
          *(undefined1 *)(piVar8 + 9) = 0;
        }
        uVar18 = 0xff;
        do {
          if ((1 << ((byte)uVar18 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar18 >> 5) * 4)) != 0)
          {
            if (uVar18 < 0x100) {
              uVar11 = uVar18;
              if (((uVar18 < 0x30) || (0x39 < uVar18)) && ((uVar18 < 0x41 || (0x5a < uVar18)))) {
                if (uVar18 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d2b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  LVar13 = (*(code *)PTR_DAT_0046ef30)();
                  return LVar13;
                }
                uVar11 = uVar18 | 0xe300;
              }
            }
            else {
              uVar11 = 0;
            }
            if (uVar11 != 0) {
              FUN_0040c2c0(piVar8,2,uVar11);
            }
          }
          uVar18 = uVar18 - 1;
        } while (-1 < (int)uVar18);
      }
      return 0;
    }
    if (param_3 == 0x207) {
      FUN_0040c440(piVar8,uVar18,0x100,4,0);
      return 0;
    }
    if (param_3 == 0x208) {
      FUN_0040c440(piVar8,uVar18,0x101,4,0);
      if (((uint)param_4 & 0x13) == 0) {
        if ((char)piVar8[9] != '\0') {
          SendMessageA((HWND)*piVar8,0x8065,0,0);
          *(undefined1 *)(piVar8 + 9) = 0;
        }
        uVar18 = 0xff;
        do {
          if ((1 << ((byte)uVar18 & 0x1f) & *(uint *)(&DAT_0048927c + ((int)uVar18 >> 5) * 4)) != 0)
          {
            if (uVar18 < 0x100) {
              uVar11 = uVar18;
              if (((uVar18 < 0x30) || (0x39 < uVar18)) && ((uVar18 < 0x41 || (0x5a < uVar18)))) {
                if (uVar18 == 0x20) {
                    /* WARNING: Could not recover jumptable at 0x0040d370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
                  LVar13 = (*(code *)PTR_DAT_0046ef2c)();
                  return LVar13;
                }
                uVar11 = uVar18 | 0xe300;
              }
            }
            else {
              uVar11 = 0;
            }
            if (uVar11 != 0) {
              FUN_0040c2c0(piVar8,2,uVar11);
            }
          }
          uVar18 = uVar18 - 1;
        } while (-1 < (int)uVar18);
      }
      return 0;
    }
    if (param_3 == 0x4c8) {
      LVar13 = FUN_00405670(param_2);
      return LVar13;
    }
    if (param_3 == 0x8065) {
      LVar13 = FUN_0040c780(piVar8,(uint)param_4);
      return LVar13;
    }
  }
  if (param_3 == 0x14) {
    return 1;
  }
  if (param_3 == 0x8068) {
    DAT_004892b8 = param_2;
    if (param_2 == (HWND)0x0) {
      if (DAT_0049ff1c == (int *)0x0) {
        pHVar15 = (HWND)0x0;
      }
      else {
        pHVar15 = (HWND)*DAT_0049ff1c;
      }
      SetFocus(pHVar15);
    }
    else {
      SetFocus(param_2);
      DAT_004892b8 = (HWND)0x0;
    }
    return 0;
  }
LAB_0040d750:
  LVar13 = CallWindowProcA((WNDPROC)(&DAT_00489254)[param_1],param_2,param_3,(WPARAM)param_4,
                           (LPARAM)param_5);
  return LVar13;
}


