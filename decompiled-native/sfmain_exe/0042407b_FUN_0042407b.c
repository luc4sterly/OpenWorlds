// 0042407b FUN_0042407b [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

WPARAM FUN_0042407b(undefined4 param_1,undefined4 param_2,char *param_3)

{
  byte bVar1;
  HWND pHVar2;
  BOOL BVar3;
  int iVar4;
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
  undefined4 uVar5;
  undefined4 extraout_ECX_24;
  undefined4 extraout_ECX_25;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined8 uVar6;
  undefined4 uStack00000010;
  char *local_58;
  int local_54;
  uint local_4c;
  char *local_48;
  undefined4 local_44;
  int local_40;
  char *local_3c;
  HWND local_38;
  tagMSG local_34;
  char *local_18;
  WPARAM local_14;
  
  pHVar2 = FindWindowA(s_GammaPhoneFrameClass_00437248,(LPCSTR)0x0);
  if (pHVar2 != (HWND)0x0) {
    local_38 = FindWindowA(s_GammaPhoneFrameClass_00437248,(LPCSTR)0x0);
    local_44 = 0;
    local_40 = FUN_0042c5ad();
    local_40 = local_40 + 1;
    local_3c = param_3;
    SendMessageA(local_38,0x4a,(WPARAM)local_38,(LPARAM)&local_44);
    if (_DAT_004b2c6c != 0) {
      BVar3 = IsIconic(local_38);
      if (BVar3 == 0) {
        SetFocus(local_38);
      }
      else {
        PostMessageA(local_38,0x112,0xf120,0);
      }
    }
    return 0;
  }
  FUN_0042ca56(extraout_ECX,0x3f);
  uStack00000010 = 0;
  uVar6 = FUN_0042cadc(extraout_ECX_00,&DAT_0043725d);
  local_18 = (char *)uVar6;
  uVar5 = extraout_ECX_01;
  if (local_18 == (char *)0x0) {
    uVar6 = FUN_0042cadc(extraout_ECX_01,&DAT_00437260);
    local_18 = (char *)uVar6;
    uVar5 = extraout_ECX_02;
    if (local_18 != (char *)0x0) goto LAB_00424171;
  }
  else {
LAB_00424171:
    if (((local_18 == param_3) || (((&DAT_00437bd8)[(byte)(local_18[-1] + 1)] & 2) != 0)) &&
       ((local_18[2] == '\0' || (((&DAT_00437bd8)[(byte)(local_18[2] + 1)] & 2) != 0)))) {
      local_48 = local_18 + 2;
      FUN_004080a4(uVar5,&DAT_00437263);
      while (((&DAT_00437bd8)[(byte)(*local_48 + 1)] & 2) != 0) {
        local_48 = local_48 + 1;
      }
      local_4c = 0;
      while ((*local_48 != '\0' && (((&DAT_00437bd8)[(byte)(*local_48 + 1)] & 2) == 0))) {
        if ((DAT_0043d6d8 == (HANDLE)0xffffffff) && (local_4c < 99)) {
          *(char *)(local_4c + 0x4b2c08) = *local_48;
          local_4c = local_4c + 1;
        }
        *local_48 = ' ';
        local_48 = local_48 + 1;
      }
      if (DAT_0043d6d8 == (HANDLE)0xffffffff) {
        *(undefined1 *)(local_4c + 0x4b2c08) = 0;
        DAT_0043d6d8 = CreateFileA((LPCSTR)0x4b2c08,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,0,
                                   (HANDLE)0x0);
        FUN_004296b9(s_Opened__s_00437266);
      }
    }
  }
  FUN_004296b9(s_Command_line_____s__00437271);
  uVar6 = FUN_0042cadc(extraout_ECX_03,&DAT_00437286);
  local_18 = (char *)uVar6;
  uVar5 = extraout_ECX_04;
  if (local_18 == (char *)0x0) {
    uVar6 = FUN_0042cadc(extraout_ECX_04,&DAT_00437289);
    local_18 = (char *)uVar6;
    uVar5 = extraout_ECX_05;
    if (local_18 != (char *)0x0) goto LAB_004242f5;
    uVar6 = FUN_0042cadc(extraout_ECX_05,&DAT_0043728c);
    local_18 = (char *)uVar6;
    uVar5 = extraout_ECX_06;
    if (local_18 != (char *)0x0) goto LAB_004242f5;
    uVar6 = FUN_0042cadc(extraout_ECX_06,&DAT_0043728f);
    local_18 = (char *)uVar6;
    uVar5 = extraout_ECX_07;
    if (local_18 != (char *)0x0) goto LAB_004242f5;
  }
  else {
LAB_004242f5:
    if (((local_18 == param_3) || (((&DAT_00437bd8)[(byte)(local_18[-1] + 1)] & 2) != 0)) &&
       ((local_18[2] == '\0' || (((&DAT_00437bd8)[(byte)(local_18[2] + 1)] & 2) != 0)))) {
      FUN_004080a4(uVar5,&DAT_00437263);
      _DAT_004b2c6c = 1;
      _DAT_004b2c70 = 1;
      uVar5 = extraout_ECX_08;
    }
  }
  uVar6 = FUN_0042cadc(uVar5,&DAT_00437292);
  local_18 = (char *)uVar6;
  uVar5 = extraout_ECX_09;
  if (local_18 == (char *)0x0) {
    uVar6 = FUN_0042cadc(extraout_ECX_09,&DAT_00437295);
    local_18 = (char *)uVar6;
    uVar5 = extraout_ECX_10;
    if (local_18 == (char *)0x0) {
      uVar6 = FUN_0042cadc(extraout_ECX_10,&DAT_00437298);
      local_18 = (char *)uVar6;
      uVar5 = extraout_ECX_11;
      if (local_18 == (char *)0x0) {
        uVar6 = FUN_0042cadc(extraout_ECX_11,&DAT_0043729b);
        iVar4 = (int)((ulonglong)uVar6 >> 0x20);
        uVar5 = extraout_ECX_12;
        if ((int)uVar6 == 0) goto LAB_00424415;
      }
    }
  }
  iVar4 = (int)((ulonglong)uVar6 >> 0x20);
  local_18 = (char *)uVar6;
  if (((local_18 == param_3) || (((&DAT_00437bd8)[(byte)(local_18[-1] + 1)] & 2) != 0)) &&
     ((local_18[2] == '\0' || (((&DAT_00437bd8)[(byte)(local_18[2] + 1)] & 2) != 0)))) {
    FUN_004080a4(uVar5,&DAT_00437263);
    _DAT_004b2c70 = 1;
    uVar5 = extraout_ECX_13;
    iVar4 = extraout_EDX;
  }
LAB_00424415:
  local_18 = param_3;
  while ((uVar6 = CONCAT44(iVar4,local_18), local_18 != (char *)0x0 && (*local_18 != '\0'))) {
    uVar6 = FUN_0042cadc(uVar5,&DAT_0043729e);
    local_18 = (char *)uVar6;
    uVar5 = extraout_ECX_14;
    if (local_18 == (char *)0x0) {
      uVar6 = FUN_0042cadc(extraout_ECX_14,&DAT_004372a1);
      local_18 = (char *)uVar6;
      uVar5 = extraout_ECX_15;
      if (local_18 == (char *)0x0) {
        uVar6 = FUN_0042cadc(extraout_ECX_15,&DAT_004372a4);
        local_18 = (char *)uVar6;
        uVar5 = extraout_ECX_16;
        if (local_18 == (char *)0x0) {
          uVar6 = FUN_0042cadc(extraout_ECX_16,&DAT_004372a7);
          local_18 = (char *)uVar6;
          uVar5 = extraout_ECX_17;
          if (local_18 == (char *)0x0) {
            uVar6 = FUN_0042cadc(extraout_ECX_17,&DAT_004372aa);
            local_18 = (char *)uVar6;
            uVar5 = extraout_ECX_18;
            if ((local_18 == (char *)0x0) &&
               (uVar6 = FUN_0042cadc(extraout_ECX_18,&DAT_004372ad), uVar5 = extraout_ECX_19,
               (int)uVar6 == 0)) break;
          }
        }
      }
    }
    iVar4 = (int)((ulonglong)uVar6 >> 0x20);
    local_18 = (char *)uVar6;
    if ((local_18 == param_3) || (((&DAT_00437bd8)[(byte)(local_18[-1] + 1)] & 2) != 0)) {
      local_54 = 0;
      local_58 = local_18 + 2;
      while (((&DAT_00437bd8)[(byte)(*local_58 + 1)] & 0x20) != 0) {
        iVar4 = local_54 * 10;
        local_54 = *local_58 + iVar4 + -0x30;
        local_58 = local_58 + 1;
      }
      bVar1 = local_18[1];
      if (bVar1 < 0x38) {
        if (bVar1 == 0x36) {
          DAT_0043d5d0 = 1;
        }
      }
      else if (bVar1 < 0x39) {
        DAT_0043d5cc = 1;
      }
      else if (bVar1 == 0x67) {
        while (((&DAT_00437bd8)[(byte)(*local_58 + 1)] & 2) != 0) {
          local_58 = local_58 + 1;
        }
        local_54 = 0;
        while ((*local_58 != '\0' && (((&DAT_00437bd8)[(byte)(*local_58 + 1)] & 2) == 0))) {
          if (((&DAT_00437bd8)[(byte)(*local_58 + 1)] & 0x20) != 0) {
            local_54 = (int)*local_58 + local_54 * 10 + -0x30;
          }
          *local_58 = ' ';
          local_58 = local_58 + 1;
        }
        FUN_004296b9(s_Got_Gamma_HWND_val__d_004372b0);
        uVar5 = extraout_ECX_20;
        iVar4 = extraout_EDX_00;
        if ((0 < local_54) && (DAT_004623b0 == 0)) {
          FUN_004296b9(s_Opening_Gamma_comm_at_ID__d_004372c7);
          uVar6 = FUN_0042b068(extraout_ECX_21,extraout_EDX_01);
          DAT_004623b0 = (int)uVar6;
          FUN_0042b0bf(extraout_ECX_22,0x385);
          uVar5 = extraout_ECX_23;
          iVar4 = extraout_EDX_02;
        }
      }
      while ((*local_18 != '0' && (((&DAT_00437bd8)[(byte)(*local_18 + 1)] & 2) == 0))) {
        *local_18 = ' ';
        local_18 = local_18 + 1;
      }
    }
    else {
      local_18 = local_18 + 2;
    }
  }
  local_18 = (char *)uVar6;
  if (_DAT_004b2c70 != 0) {
    uStack00000010 = 2;
  }
  uVar6 = FUN_0042189d(uVar5,(int)((ulonglong)uVar6 >> 0x20));
  if ((int)uVar6 == 0) {
    local_14 = 0;
  }
  else {
    iVar4 = FUN_004219d3(extraout_ECX_24,(int)param_3);
    if (iVar4 == 0) {
      local_14 = 0;
    }
    else {
      while (BVar3 = GetMessageA(&local_34,(HWND)0x0,0,0), BVar3 != 0) {
        FUN_00423f69(extraout_ECX_25,extraout_EDX_03);
        if ((DAT_0043d5a4 == 0) && (BVar3 = PeekMessageA(&local_34,(HWND)0x0,0,0,2), BVar3 == 0)) {
          _DAT_0043d7e4 = GetTickCount();
        }
      }
      local_14 = local_34.wParam;
    }
  }
  return local_14;
}


