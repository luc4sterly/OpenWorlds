// 0041fe4c FUN_0041fe4c [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0041fe4c(undefined4 param_1,undefined4 param_2)

{
  undefined4 in_EAX;
  int iVar1;
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
  undefined8 uVar2;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_34;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  
  local_28 = in_EAX;
  DAT_0043d71c = Ordinal_23(2,1,0);
  if (DAT_0043d71c == -1) {
    uVar2 = Ordinal_111();
    local_24 = (undefined4)uVar2;
    uVar2 = FUN_00429482(extraout_ECX,(int)((ulonglong)uVar2 >> 0x20));
    FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar2 >> 0x20),0x1acd,
                 s__GAMMA_speakfre_sfmain_FRAME_c_00436bdb,3,(HWND)0x0,0x10,
                 s_Couldn_t_create_socket__error__d_00436bb5);
    local_1c = 1;
  }
  else {
    local_20 = 1;
    local_1e = 0;
    iVar1 = Ordinal_21(DAT_0043d71c,0xffff,0x80,&local_20,4);
    if (iVar1 == 0) {
      local_38 = 2;
      local_34 = 0;
      local_36 = Ordinal_9(0x820);
      iVar1 = Ordinal_2(DAT_0043d71c,&local_38,0x10);
      if (iVar1 == 0) {
        iVar1 = Ordinal_13(DAT_0043d71c,1);
        if (iVar1 == 0) {
          iVar1 = Ordinal_101(DAT_0043d71c,local_28,0x469,0x2d);
          if (iVar1 == 0) {
            FUN_004296b9(s_Set_up_connSock_00436d0f);
            local_1c = 0;
          }
          else {
            uVar2 = Ordinal_111();
            local_24 = (undefined4)uVar2;
            uVar2 = FUN_00429482(extraout_ECX_07,(int)((ulonglong)uVar2 >> 0x20));
            FUN_00429268(extraout_ECX_08,(int)((ulonglong)uVar2 >> 0x20),0x1b05,
                         s__GAMMA_speakfre_sfmain_FRAME_c_00436cf0,3,(HWND)0x0,0x10,
                         s_WSAAsyncSelect___failure__error___00436cc8);
            Ordinal_3(DAT_0043d71c);
            DAT_0043d71c = -1;
            local_1c = 1;
          }
        }
        else {
          uVar2 = Ordinal_111();
          local_24 = (undefined4)uVar2;
          uVar2 = FUN_00429482(extraout_ECX_05,(int)((ulonglong)uVar2 >> 0x20));
          FUN_00429268(extraout_ECX_06,(int)((ulonglong)uVar2 >> 0x20),0x1af6,
                       s__GAMMA_speakfre_sfmain_FRAME_c_00436ca9,3,(HWND)0x0,0x10,
                       s_Couldn_t_listen_on_socket__error_00436c80);
          Ordinal_3(DAT_0043d71c);
          DAT_0043d71c = -1;
          local_1c = 1;
        }
      }
      else {
        uVar2 = Ordinal_111();
        local_24 = (undefined4)uVar2;
        uVar2 = FUN_00429482(extraout_ECX_03,(int)((ulonglong)uVar2 >> 0x20));
        FUN_00429268(extraout_ECX_04,(int)((ulonglong)uVar2 >> 0x20),0x1ae9,
                     s__GAMMA_speakfre_sfmain_FRAME_c_00436c61,3,(HWND)0x0,0x10,
                     s_Couldn_t_bind_socket__error__d___00436c3d);
        Ordinal_3(DAT_0043d71c);
        DAT_0043d71c = -1;
        local_1c = 1;
      }
    }
    else {
      uVar2 = Ordinal_111();
      local_24 = (undefined4)uVar2;
      uVar2 = FUN_00429482(extraout_ECX_01,(int)((ulonglong)uVar2 >> 0x20));
      FUN_00429268(extraout_ECX_02,(int)((ulonglong)uVar2 >> 0x20),0x1adb,
                   s__GAMMA_speakfre_sfmain_FRAME_c_00436c1e,3,(HWND)0x0,0x10,
                   s_setsockopt___failure__error__d___00436bfa);
      Ordinal_3(DAT_0043d71c);
      DAT_0043d71c = -1;
      local_1c = 1;
    }
  }
  return CONCAT44(param_2,local_1c);
}


