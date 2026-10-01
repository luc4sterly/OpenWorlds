// 004152eb FUN_004152eb [Global]
// program: sfmain.exe

void __fastcall FUN_004152eb(undefined4 param_1,undefined4 param_2)

{
  LPCSTR pCVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 uVar3;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 uVar4;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined8 uVar5;
  int iVar6;
  BOOL bSigned;
  LPCSTR local_80;
  char *local_7c;
  char *local_78;
  char *local_74;
  char *local_70;
  CHAR local_6c [80];
  int local_1c;
  
  if (DAT_0043d634 != (HWND)0x0) {
    if (DAT_0043d6ac == 0) {
      uVar5 = FUN_00429192(param_1,param_2);
      SetDlgItemTextA(DAT_0043d634,0x402,(LPCSTR)uVar5);
      uVar3 = extraout_ECX_03;
      uVar4 = extraout_EDX_01;
    }
    else {
      if (DAT_0043d520 == 0) {
        uVar5 = FUN_00429192(param_1,param_2);
        local_70 = (char *)uVar5;
        uVar3 = extraout_ECX_00;
      }
      else {
        uVar5 = FUN_00429192(param_1,param_2);
        local_70 = (char *)uVar5;
        uVar3 = extraout_ECX;
      }
      FUN_0042c5c6(uVar3,local_70);
      uVar3 = DAT_004627a8;
      iVar6 = DAT_0043d6ac;
      uVar5 = FUN_00429192(extraout_ECX_01,extraout_EDX);
      pCVar1 = (LPCSTR)uVar5;
      iVar2 = FUN_0042c5ad();
      wsprintfA(local_6c + iVar2,pCVar1,uVar3,iVar6);
      SetDlgItemTextA(DAT_0043d634,0x402,local_6c);
      uVar3 = extraout_ECX_02;
      uVar4 = extraout_EDX_00;
    }
    if (DAT_0043d6b0 == 0) {
      uVar5 = FUN_00429192(uVar3,uVar4);
      SetDlgItemTextA(DAT_0043d634,0x401,(LPCSTR)uVar5);
      uVar3 = extraout_ECX_10;
      uVar4 = extraout_EDX_04;
    }
    else {
      if (DAT_0043d544 == 0) {
        if (DAT_0043d540 == 0) {
          if (DAT_0043d51c == 0) {
            uVar5 = FUN_00429192(uVar3,uVar4);
            local_74 = (char *)uVar5;
            uVar3 = extraout_ECX_07;
          }
          else {
            uVar5 = FUN_00429192(uVar3,uVar4);
            local_74 = (char *)uVar5;
            uVar3 = extraout_ECX_06;
          }
          local_78 = local_74;
        }
        else {
          uVar5 = FUN_00429192(uVar3,uVar4);
          local_78 = (char *)uVar5;
          uVar3 = extraout_ECX_05;
        }
        local_7c = local_78;
      }
      else {
        uVar5 = FUN_00429192(uVar3,uVar4);
        local_7c = (char *)uVar5;
        uVar3 = extraout_ECX_04;
      }
      FUN_0042c5c6(uVar3,local_7c);
      uVar3 = DAT_004627b0;
      iVar6 = DAT_0043d6b0;
      uVar5 = FUN_00429192(extraout_ECX_08,extraout_EDX_02);
      pCVar1 = (LPCSTR)uVar5;
      iVar2 = FUN_0042c5ad();
      wsprintfA(local_6c + iVar2,pCVar1,uVar3,iVar6);
      SetDlgItemTextA(DAT_0043d634,0x401,local_6c);
      SetDlgItemInt(DAT_0043d634,0x403,DAT_0043d538,1);
      SetDlgItemInt(DAT_0043d634,0x177f,DAT_0043d53c,1);
      uVar3 = extraout_ECX_09;
      uVar4 = extraout_EDX_03;
    }
    if (DAT_0043d5f8 == 0) {
      uVar5 = FUN_00429192(uVar3,uVar4);
      local_80 = (LPCSTR)uVar5;
    }
    else {
      uVar5 = FUN_00429192(uVar3,uVar4);
      local_80 = (LPCSTR)uVar5;
    }
    SetDlgItemTextA(DAT_0043d634,0x3fc,local_80);
    SetDlgItemInt(DAT_0043d634,0x406,DAT_0043d528,0);
    bSigned = 0;
    uVar5 = FUN_004182e8(extraout_ECX_11,extraout_EDX_05);
    SetDlgItemInt(DAT_0043d634,0x404,(UINT)uVar5,bSigned);
    if ((DAT_0043d568 == 0) && (DAT_0043d57c == 0)) {
      if (DAT_0043d56c == 0) {
        if (DAT_0043d574 == 0) {
          if (DAT_0043d570 != 0) {
            local_1c = 0xc;
          }
        }
        else {
          local_1c = 9;
        }
      }
      else {
        local_1c = 6;
      }
    }
    else {
      local_1c = 3;
    }
    if (DAT_0043d560 == 0) {
      if (DAT_0043d564 != 0) {
        local_1c = local_1c + 2;
      }
    }
    else {
      local_1c = local_1c + 1;
    }
    uVar5 = FUN_00429192(extraout_ECX_12,extraout_EDX_06);
    SetDlgItemTextA(DAT_0043d634,0x405,(LPCSTR)uVar5);
    SetDlgItemTextA(DAT_0043d634,0x1772,&DAT_004623ec);
  }
  return;
}


