// 00422903 FUN_00422903 [Global]
// programa: sfmain.exe

void __fastcall FUN_00422903(undefined4 param_1)

{
  HWND in_EAX;
  int iVar1;
  undefined1 *puVar2;
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
  undefined4 uVar3;
  undefined4 extraout_ECX_22;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined8 uVar4;
  undefined1 *local_250;
  char local_23c [12];
  undefined1 local_230 [500];
  undefined2 local_3c;
  undefined2 local_3a;
  int local_38;
  HWND local_2c;
  char *local_28;
  undefined1 *local_24;
  int local_20;
  int local_1c;
  
  local_28 = local_23c;
  local_2c = in_EAX;
  FUN_0042287e(param_1,0);
  GetDlgItemTextA(local_2c,0x413,local_23c,0x200);
  if (local_23c[0] == '(') {
    local_28 = local_28 + 1;
    local_24 = (undefined1 *)FUN_0042cbb3(extraout_ECX,')');
    if (local_24 != (undefined1 *)0x0) {
      *local_24 = 0;
    }
  }
  local_3c = 2;
  local_3a = Ordinal_9(0x820);
  uVar4 = Ordinal_10(local_28);
  local_38 = (int)uVar4;
  uVar3 = extraout_ECX_00;
  if (local_38 == -1) {
    SendDlgItemMessageA(local_2c,0x416,0x184,0,0);
    uVar4 = FUN_00429192(extraout_ECX_01,extraout_EDX);
    SendDlgItemMessageA(local_2c,0x416,0x180,0,(LPARAM)uVar4);
    iVar1 = Ordinal_52(local_28);
    if (iVar1 == 0) {
      uVar4 = Ordinal_111();
      if ((int)uVar4 != 0x2714) {
        uVar4 = FUN_00429482(extraout_ECX_03,(int)((ulonglong)uVar4 >> 0x20));
        uVar4 = FUN_00429192(extraout_ECX_04,(int)((ulonglong)uVar4 >> 0x20));
        FUN_00429268(extraout_ECX_05,(int)((ulonglong)uVar4 >> 0x20),0x184,
                     s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,local_2c,0x10,(LPCSTR)uVar4);
      }
      SendDlgItemMessageA(local_2c,0x416,0x184,0,0);
      FUN_0042287e(extraout_ECX_06,1);
      return;
    }
    FUN_004080a4(extraout_ECX_02,(undefined1 *)**(undefined4 **)(iVar1 + 0xc));
    uVar4 = CONCAT44(extraout_EDX_00,local_38);
    uVar3 = extraout_ECX_07;
  }
  local_38 = (int)uVar4;
  uVar4 = FUN_00429192(uVar3,(int)((ulonglong)uVar4 >> 0x20));
  SendDlgItemMessageA(local_2c,0x416,0x180,0,(LPARAM)uVar4);
  local_20 = Ordinal_23(2,1,0);
  if (local_20 == -1) {
    Ordinal_111();
    uVar4 = FUN_00429482(extraout_ECX_08,extraout_EDX_01);
    uVar4 = FUN_00429192(extraout_ECX_09,(int)((ulonglong)uVar4 >> 0x20));
    FUN_00429268(extraout_ECX_10,(int)((ulonglong)uVar4 >> 0x20),0x199,
                 s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,local_2c,0x10,(LPCSTR)uVar4);
    SendDlgItemMessageA(local_2c,0x416,0x184,0,0);
    FUN_0042287e(extraout_ECX_11,1);
  }
  else {
    uVar4 = Ordinal_4(local_20,&local_3c,0x10);
    if ((int)uVar4 < 0) {
      Ordinal_111();
      uVar4 = FUN_00429482(extraout_ECX_13,extraout_EDX_02);
      uVar4 = FUN_00429192(extraout_ECX_14,(int)((ulonglong)uVar4 >> 0x20));
      FUN_00429268(extraout_ECX_15,(int)((ulonglong)uVar4 >> 0x20),0x1a3,
                   s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,local_2c,0x10,(LPCSTR)uVar4);
      Ordinal_3(local_20);
      SendDlgItemMessageA(local_2c,0x416,0x184,0,0);
      FUN_0042287e(extraout_ECX_16,1);
    }
    else {
      local_23c[0] = -0x34;
      local_23c[1] = -0x7f;
      local_23c[4] = '\0';
      local_23c[5] = '\0';
      local_23c[6] = '\0';
      local_23c[7] = '\0';
      uVar4 = FUN_00429192(extraout_ECX_12,(int)((ulonglong)uVar4 >> 0x20));
      FUN_004080a4(local_23c + 8,(undefined1 *)uVar4);
      local_23c[2] = '\x02';
      local_23c[3] = '\0';
      FUN_00429618();
      FUN_00429618();
      uVar4 = FUN_00429192(extraout_ECX_17,extraout_EDX_03);
      SendDlgItemMessageA(local_2c,0x416,0x180,0,(LPARAM)uVar4);
      iVar1 = FUN_00429725();
      if (iVar1 < 0) {
        SendDlgItemMessageA(local_2c,0x416,0x184,0,0);
        FUN_0042287e(extraout_ECX_19,1);
      }
      else {
        uVar4 = FUN_00429192(extraout_ECX_18,extraout_EDX_04);
        SendDlgItemMessageA(local_2c,0x416,0x180,0,(LPARAM)uVar4);
        local_1c = FUN_00429977();
        if (local_1c < 1) {
          SendDlgItemMessageA(local_2c,0x416,0x184,0,0);
          FUN_0042287e(extraout_ECX_20,1);
        }
        else {
          Ordinal_3(local_20);
          SendDlgItemMessageA(local_2c,0x416,0x184,0,0);
          DAT_0043d7e0 = 0xffffffff;
          FUN_004227fb();
          local_24 = local_230;
          uVar3 = extraout_ECX_21;
          while (local_24 != (undefined1 *)0x0) {
            puVar2 = (undefined1 *)FUN_0042cbb3(uVar3,'\n');
            local_250 = puVar2;
            if (puVar2 != (undefined1 *)0x0) {
              local_250 = puVar2 + 1;
              *puVar2 = 0;
            }
            SendDlgItemMessageA(local_2c,0x416,0x180,0,(LPARAM)local_24);
            uVar3 = extraout_ECX_22;
            local_24 = local_250;
          }
          FUN_0042287e(uVar3,1);
        }
      }
    }
  }
  return;
}


