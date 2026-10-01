// 004138b3 FUN_004138b3 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_004138b3(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int iVar1;
  char *pcVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 uVar3;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined2 local_44;
  undefined2 local_42;
  undefined4 local_40;
  undefined2 local_34;
  undefined2 local_32;
  undefined4 local_30;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  
  local_24 = in_EAX;
  DAT_0043d724 = Ordinal_23(2,1,0);
  if (DAT_0043d724 == -1) {
    uVar4 = Ordinal_111();
    local_20 = (int)uVar4;
    uVar4 = FUN_00429482(extraout_ECX,(int)((ulonglong)uVar4 >> 0x20));
    FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar4 >> 0x20),0xb16,
                 s__GAMMA_speakfre_sfmain_CONNECT_c_00435e61,3,(HWND)0x0,0x10,
                 s__Couldn_t_create_socket__error___00435e3a + 1);
    local_1c = 1;
  }
  else {
    local_44 = 2;
    local_40 = 0;
    local_42 = 0;
    iVar1 = Ordinal_2(DAT_0043d724,&local_44,0x10);
    if (iVar1 == 0) {
      local_32 = Ordinal_9(0x820);
      local_34 = 2;
      local_30 = local_24;
      iVar1 = Ordinal_101(DAT_0043d724,DAT_004627d0,0x469,0x35);
      if (iVar1 == 0) {
        local_20 = 0;
        uVar5 = Ordinal_4(DAT_0043d724,&local_34,0x10);
        uVar4 = CONCAT44((int)((ulonglong)uVar5 >> 0x20),local_20);
        uVar3 = extraout_ECX_05;
        if ((int)uVar5 != 0) {
          uVar4 = Ordinal_111();
          local_20 = (int)uVar4;
          uVar3 = extraout_ECX_06;
          if (local_20 == 0x2733) {
            pcVar2 = (char *)Ordinal_11(local_24);
            FUN_0042c5c6(extraout_ECX_08,pcVar2);
            if (DAT_0043d634 != (HWND)0x0) {
              SetDlgItemTextA(DAT_0043d634,0x1772,&DAT_004623ec);
            }
            local_1c = 0;
            goto LAB_00413adf;
          }
        }
        local_20 = (int)uVar4;
        uVar4 = FUN_00429482(uVar3,(int)((ulonglong)uVar4 >> 0x20));
        FUN_00429268(extraout_ECX_07,(int)((ulonglong)uVar4 >> 0x20),0xb4a,
                     s__GAMMA_speakfre_sfmain_CONNECT_c_00435f3b,3,(HWND)0x0,0x10,
                     s_connect___failure__error__d___s__00435f10);
        Ordinal_3(DAT_0043d724);
        DAT_0043d724 = -1;
        local_1c = 1;
      }
      else {
        uVar4 = Ordinal_111();
        local_20 = (int)uVar4;
        uVar4 = FUN_00429482(extraout_ECX_03,(int)((ulonglong)uVar4 >> 0x20));
        FUN_00429268(extraout_ECX_04,(int)((ulonglong)uVar4 >> 0x20),0xb38,
                     s__GAMMA_speakfre_sfmain_CONNECT_c_00435eef,3,(HWND)0x0,0x10,
                     s_WSAAsyncSelect___failure__error___00435ec7);
        Ordinal_3(DAT_0043d724);
        DAT_0043d724 = -1;
        local_1c = 1;
      }
    }
    else {
      uVar4 = Ordinal_111();
      local_20 = (int)uVar4;
      uVar4 = FUN_00429482(extraout_ECX_01,(int)((ulonglong)uVar4 >> 0x20));
      FUN_00429268(extraout_ECX_02,(int)((ulonglong)uVar4 >> 0x20),0xb25,
                   s__GAMMA_speakfre_sfmain_CONNECT_c_00435ea6,3,(HWND)0x0,0x10,
                   s_Couldn_t_bind_socket__error__d___00435e82);
      Ordinal_3(DAT_0043d724);
      DAT_0043d724 = -1;
      local_1c = 1;
    }
  }
LAB_00413adf:
  return CONCAT44(param_2,local_1c);
}


