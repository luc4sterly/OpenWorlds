// 004200af FUN_004200af [Global]
// program: sfmain.exe

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HGLOBAL __fastcall FUN_004200af(short param_1,int param_2)

{
  undefined2 uVar1;
  HWND in_EAX;
  HGLOBAL pvVar2;
  uint uVar3;
  char *pcVar4;
  LPCVOID pMem;
  HWND pHVar5;
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
  undefined4 uVar6;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 extraout_ECX_14;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 uVar7;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  int unaff_EBX;
  undefined8 uVar8;
  int local_34;
  uint local_30;
  int local_2c [4];
  HWND local_1c;
  int local_18;
  
  local_1c = in_EAX;
  local_18 = param_2;
  if (param_2 == DAT_0043d71c) {
    if (param_1 == 8) {
      local_2c[3] = 0x10;
      FUN_004296b9(s_connSock_FD_ACCEPT_00436d20);
      if (unaff_EBX == 0) {
        DAT_0043d720 = Ordinal_1(DAT_0043d71c,&DAT_0045e220,local_2c + 3);
        if (DAT_0043d720 == -1) {
          Ordinal_111();
          uVar8 = FUN_00429482(extraout_ECX_01,extraout_EDX_00);
          FUN_00429268(extraout_ECX_02,(int)((ulonglong)uVar8 >> 0x20),0x1b31,
                       s__GAMMA_speakfre_sfmain_FRAME_c_00436d93,3,(HWND)0x0,0x10,
                       s_accept___failure__error__d___s__00436d73);
          pvVar2 = (HGLOBAL)Ordinal_3(DAT_0043d71c);
          DAT_0043d71c = -1;
        }
        else {
          uVar1 = Ordinal_9(0x820);
          DAT_0045e220 = CONCAT22(uVar1,(undefined2)DAT_0045e220);
          local_2c[2] = 1;
          FUN_004296b9(s_Sending_version__d_00436db2);
          pvVar2 = (HGLOBAL)Ordinal_19(DAT_0043d720,local_2c + 2,4,0);
        }
      }
      else {
        uVar8 = FUN_00429482(extraout_ECX,extraout_EDX);
        uVar8 = FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar8 >> 0x20),0x1b24,
                             s__GAMMA_speakfre_sfmain_FRAME_c_00436d54,3,(HWND)0x0,0x10,
                             s_accept___failure__error__d___s__00436d34);
        pvVar2 = (HGLOBAL)uVar8;
      }
    }
    else if (param_1 == 0x20) {
      FUN_004296b9(s_connSock_FD_CLOSE_00436dc6);
      uVar8 = FUN_00429268(extraout_ECX_03,extraout_EDX_01,0x1b52,
                           s__GAMMA_speakfre_sfmain_FRAME_c_00436de9,0x16,local_1c,0,
                           s_Connection_lost_00436dd9);
      pvVar2 = (HGLOBAL)uVar8;
    }
    else {
      pvVar2 = (HGLOBAL)FUN_004296b9(s_connSock_got_unexpected_event__d_00436e08);
    }
  }
  else if (param_2 == DAT_0043d724) {
    if (param_1 == 0x10) {
      FUN_004296b9(s_connCallerSock_FD_CONNECT_00436e2a);
      if (unaff_EBX == 0) {
        local_2c[1] = 1;
        FUN_004296b9(s_Sending_version__d_00436db2);
        pvVar2 = (HGLOBAL)Ordinal_19(DAT_0043d724,local_2c + 1,4,0);
      }
      else {
        uVar8 = FUN_00429482(extraout_ECX_04,extraout_EDX_02);
        uVar8 = FUN_00429268(extraout_ECX_05,(int)((ulonglong)uVar8 >> 0x20),0x1b64,
                             s__GAMMA_speakfre_sfmain_FRAME_c_00436e66,3,(HWND)0x0,0x10,
                             s_connect___failure__error__d___s__00436e45);
        pvVar2 = (HGLOBAL)uVar8;
      }
    }
    else if (param_1 == 1) {
      FUN_004296b9(s_connCallerSock_FD_READ_00436e85);
      local_30 = Ordinal_16(DAT_0043d724,local_2c,4,0);
      if (local_30 < 4) {
        FUN_004296b9(s_Only_got__d_bytes_at_startup__00436e9d);
        local_2c[0] = 0;
      }
      FUN_004296b9(s_connCallerSock__Got_version__d_00436ebc);
      if (DAT_004623bc == 0) {
        DAT_004623bc = 1;
        if (local_2c[0] < 1) {
          DAT_004623cc = local_2c[0];
        }
        else {
          DAT_004623cc = 1;
        }
        FUN_004296b9(s_Other_side_is_version__d__using_v_00436eff);
        if (_DAT_004b2c6c == 0) {
          FUN_00429268(extraout_ECX_06,extraout_EDX_03,0x1b93,
                       s__GAMMA_speakfre_sfmain_FRAME_c_00436f3b,900,local_1c,0,
                       s_Connected_to__s_00436f2b);
        }
        pvVar2 = (HGLOBAL)GetTickCount();
        _DAT_004623e0 = pvVar2;
      }
      else {
        pvVar2 = (HGLOBAL)FUN_004296b9(s_connCallerSock_already_connected_00436edc);
      }
    }
    else if (param_1 == 0x20) {
      FUN_004296b9(s_connCallerSock_FD_CLOSE_00436f5a);
      uVar8 = FUN_00429268(extraout_ECX_07,extraout_EDX_04,0x1b9e,
                           s__GAMMA_speakfre_sfmain_FRAME_c_00436f73,0x16,local_1c,0,
                           s_Connection_lost_00436dd9);
      pvVar2 = (HGLOBAL)uVar8;
    }
    else {
      pvVar2 = (HGLOBAL)FUN_004296b9(s_connCallerSock_got_unexpected_ev_00436f92);
    }
  }
  else if (param_2 == DAT_0043d720) {
    if (param_1 == 1) {
      FUN_004296b9(s_connCliSock_FD_READ_00436fba);
      uVar3 = Ordinal_16(DAT_0043d720,&local_34,4,0);
      if (uVar3 < 4) {
        FUN_004296b9(s_Only_got__d_bytes_at_startup__00436fcf);
        local_34 = 0;
      }
      FUN_004296b9(s_connCliSock__Got_version__d_00436fee);
      if (DAT_004623bc == 0) {
        DAT_004623bc = 1;
        if (local_34 < 1) {
          DAT_004623cc = local_34;
        }
        else {
          DAT_004623cc = 1;
        }
        FUN_004296b9(s_Other_side_is_version__d__using_v_0043701f);
        pcVar4 = (char *)Ordinal_11(DAT_0045e224);
        FUN_0042cfa3(extraout_ECX_08,pcVar4);
        uVar6 = extraout_ECX_09;
        uVar7 = extraout_EDX_05;
        if (DAT_0043d634 != (HWND)0x0) {
          SetDlgItemTextA(DAT_0043d634,0x1772,&DAT_004623ec);
          uVar6 = extraout_ECX_10;
          uVar7 = extraout_EDX_06;
        }
        uVar8 = FUN_0041adf7(uVar6,uVar7,DAT_0045e220,DAT_0045e224,DAT_0045e228,DAT_0045e22c,0);
        pMem = (LPCVOID)uVar8;
        if (pMem == (LPCVOID)0x0) {
          uVar8 = FUN_00429268(extraout_ECX_11,(int)((ulonglong)uVar8 >> 0x20),0x1bdb,
                               s__GAMMA_speakfre_sfmain_FRAME_c_00437061,2,(HWND)0x0,0x10,
                               s_Error_creating_client_0043704b);
          pvVar2 = (HGLOBAL)uVar8;
        }
        else {
          FUN_004296b9(s_createNewConnection_TRUE___d__s__0043709f);
          pHVar5 = FUN_0041093b(extraout_ECX_12,1);
          if (pHVar5 == (HWND)0x0) {
            FUN_00429268(extraout_ECX_13,extraout_EDX_07,0x1be4,
                         s__GAMMA_speakfre_sfmain_FRAME_c_004370d9,2,(HWND)0x0,0x10,
                         s_unable_to_create_client_004370c1);
            pvVar2 = GlobalHandle(pMem);
            GlobalUnlock(pvVar2);
            pvVar2 = GlobalHandle(pMem);
            pvVar2 = GlobalFree(pvVar2);
          }
          else {
            *(undefined2 *)((int)pMem + 0x4e40) = 0;
            if (_DAT_004b2c6c == 0) {
              FUN_00429268(extraout_ECX_13,extraout_EDX_07,0x1bf1,
                           s__GAMMA_speakfre_sfmain_FRAME_c_0043710f,900,local_1c,0,
                           s_Got_connection_from__s_004370f8);
            }
            pvVar2 = (HGLOBAL)GetTickCount();
            _DAT_004623e0 = pvVar2;
          }
        }
      }
      else {
        pvVar2 = (HGLOBAL)FUN_004296b9(s_Already_connected__0043700b);
      }
    }
    else if (param_1 == 0x20) {
      FUN_004296b9(s_connCliSock_FD_CLOSE_0043712e);
      uVar8 = FUN_00429268(extraout_ECX_14,extraout_EDX_08,0x1bfc,
                           s__GAMMA_speakfre_sfmain_FRAME_c_00437144,0x16,local_1c,0,
                           s_Connection_lost_00436dd9);
      pvVar2 = (HGLOBAL)uVar8;
    }
    else {
      pvVar2 = (HGLOBAL)FUN_004296b9(s_connCliSock_got_unexpected_event_00437163);
    }
  }
  else {
    pvVar2 = (HGLOBAL)FUN_004296b9(s__s__d_Got_unexpected_connMonitor_004371a7);
  }
  return pvVar2;
}


