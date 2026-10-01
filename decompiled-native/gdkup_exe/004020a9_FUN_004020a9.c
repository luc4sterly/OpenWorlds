// 004020a9 FUN_004020a9 [Global]
// program: gdkup.exe

undefined4 FUN_004020a9(HINSTANCE param_1,undefined4 param_2,char *param_3)

{
  char *pcVar1;
  undefined1 *puVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
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
  undefined4 uVar6;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar7;
  undefined8 uVar8;
  _PROCESS_INFORMATION local_1dbc;
  _STARTUPINFOA local_1dac;
  CHAR local_1d68 [1024];
  CHAR local_1968 [256];
  CHAR local_1868 [256];
  LPSTR local_1768;
  tagMSG local_1764;
  tagRECT local_1748;
  int local_1738;
  HDC local_1734;
  CHAR local_1730 [256];
  HWND local_1630;
  undefined4 local_162c [1024];
  undefined4 local_62c;
  char local_628 [512];
  int local_428;
  char local_224 [512];
  HANDLE local_24;
  DWORD local_20;
  int local_1c;
  char *local_14;
  
  FreeConsole();
  local_14 = FUN_00402a8f(extraout_ECX,' ');
  if (((local_14 == (char *)0x0) || (local_14 <= param_3)) || (local_14[1] == '\0')) {
    if (*param_3 == '\0') {
      MessageBoxA((HWND)0x0,s_Usage__gdkup_scriptFile_parentPr_004082ec,s_Error_004082e6,0);
    }
    else {
      local_1768 = (CHAR *)0x0;
      DVar4 = SearchPathA((LPCSTR)0x0,s_gdkup_exe_00408211,(LPCSTR)0x0,0x100,local_1868,&local_1768)
      ;
      if ((DVar4 != 0) && (local_1868 < local_1768)) {
        local_1768[-1] = '\0';
        FUN_00402828(extraout_ECX_10,local_1868);
        FUN_004028ea(extraout_ECX_11,s__jrew_exe_0040821b);
        local_1768 = FUN_00402a8f(extraout_ECX_12,'\\');
        if (local_1768 != (char *)0x0) {
          local_1768[1] = '\0';
          FUN_00402828(extraout_ECX_13,s__nojit__ms4m__cp___lib_gammacls__00408225);
          FUN_004028ea(extraout_ECX_14,s_NET_worlds_console_Gamma__home___0040824a);
          FUN_004028ea(extraout_ECX_15,s__dllpath_bin_0040826c);
          iVar5 = FUN_00403121(extraout_ECX_16,(byte *)s__Embedding_0040827a);
          if (((iVar5 == 0) ||
              (iVar5 = FUN_00403121(extraout_ECX_17,(byte *)s__Embedding_00408285), iVar5 == 0)) ||
             ((iVar5 = FUN_00403121(extraout_ECX_18,(byte *)s__Automation_00408290), iVar5 == 0 ||
              (iVar5 = FUN_00403121(extraout_ECX_19,(byte *)s__Automation_0040829c), iVar5 == 0))))
          {
            DAT_0040b034 = 0;
            FUN_004010a5();
            FUN_004028ea(extraout_ECX_21,&DAT_0040b034);
            uVar6 = extraout_ECX_22;
          }
          else {
            iVar5 = FUN_00403121(extraout_ECX_20,(byte *)s__RegServer_004082a8);
            uVar6 = extraout_ECX_23;
            if ((((iVar5 == 0) ||
                 (iVar5 = FUN_00403121(extraout_ECX_23,(byte *)s__RegServer_004082b3),
                 uVar6 = extraout_ECX_24, iVar5 == 0)) ||
                (iVar5 = FUN_00403121(extraout_ECX_24,(byte *)s__UnRegServer_004082be),
                uVar6 = extraout_ECX_25, iVar5 == 0)) ||
               (iVar5 = FUN_00403121(extraout_ECX_25,(byte *)s__UnRegServer_004082cb),
               uVar6 = extraout_ECX_26, iVar5 == 0)) {
              FUN_004028ea(uVar6,s_world_restart_004082d8);
              uVar6 = extraout_ECX_27;
            }
            else {
              FUN_004028ea(extraout_ECX_26,param_3);
              uVar6 = extraout_ECX_28;
            }
          }
          FUN_00402980(uVar6,0);
          local_1dac.cb = 0x44;
          CreateProcessA(local_1968,local_1d68,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0
                         ,0,0,(LPVOID)0x0,local_1868,&local_1dac,&local_1dbc);
        }
      }
    }
  }
  else {
    FUN_00402a6a(extraout_ECX_00,param_3);
    pcVar1 = local_14 + 1;
    local_14[(int)(local_224 + -(int)param_3)] = '\0';
    local_14 = pcVar1;
    FUN_00402828(extraout_ECX_01,pcVar1);
    local_24 = (HANDLE)0x0;
    local_20 = FUN_00402c0c(extraout_ECX_02,(undefined4 *)0x0);
    uVar6 = extraout_ECX_03;
    if (local_20 != 0) {
      local_24 = OpenProcess(0x1f0fff,0,local_20);
      uVar6 = extraout_ECX_04;
    }
    local_1c = FUN_00402e4a(uVar6,&DAT_00408134);
    if (local_1c == 0) {
      wsprintfA(local_628,s_Error_opening_script_file___s__004081ec,local_224);
      MessageBoxA((HWND)0x0,local_628,s_Error_0040820b,0);
    }
    else {
      local_428 = 0;
      do {
        puVar2 = FUN_00402f36();
        uVar6 = extraout_ECX_05;
        uVar7 = extraout_EDX;
        if (puVar2 == (undefined1 *)0x0) break;
        local_62c = FUN_00402847();
        uVar8 = thunk_FUN_004026f4(extraout_ECX_06,extraout_EDX_00);
        local_162c[local_428] = (int)uVar8;
        local_628[local_62c + -1] = '\0';
        local_428 = local_428 + 1;
        FUN_00402828(extraout_ECX_07,local_628);
        uVar6 = extraout_ECX_08;
        uVar7 = extraout_EDX_01;
      } while (local_428 < 0x400);
      FUN_00402fb1(uVar6,uVar7);
      if (local_428 < 1) {
        MessageBoxA((HWND)0x0,s_Script_file_is_not_valid_0040813c,s_Error_00408136,0);
      }
      else {
        local_1630 = CreateDialogParamA(param_1,(LPCSTR)0x65,(HWND)0x0,FUN_00401e75,0);
        if (local_1630 != (HWND)0x0) {
          GetPrivateProfileStringA
                    (s_Gamma_00408187,s_PRODUCT_NAME_0040817a,s_Worlds_Ultimate_3D_Chat_00408162,
                     local_1730,0x100,s___worlds_ini_00408155);
          GetPrivateProfileStringA
                    (s_Runtime_004081a8,s_PRODUCTNAME_0040819c,local_1730,local_1730,0x100,
                     s___override_ini_0040818d);
          SetWindowTextA(local_1630,local_1730);
          local_1734 = GetDC((HWND)0x0);
          local_1738 = GetDeviceCaps(local_1734,8);
          local_1738 = local_1738 >> 1;
          GetWindowRect(local_1630,&local_1748);
          SetWindowPos(local_1630,(HWND)0x0,local_1738 - (local_1748.right - local_1748.left >> 1),
                       0x14,0,0,0x45);
          UpdateWindow(local_1630);
          DAT_0040b020 = local_1630;
          DAT_0040b024 = local_24;
          DAT_0040b028 = local_428;
          DAT_0040b030 = local_162c;
          DAT_0040b02c = 0;
          if (local_24 == (HANDLE)0x0) {
            FUN_00401d52(extraout_ECX_09);
            FUN_00401c56();
          }
          else {
            FUN_00401ced();
          }
          while (BVar3 = GetMessageA(&local_1764,(HWND)0x0,0,0), BVar3 != 0) {
            TranslateMessage(&local_1764);
            DispatchMessageA(&local_1764);
          }
          return local_1764.wParam;
        }
        DVar4 = GetLastError();
        wsprintfA(local_628,s_System_error__couldn_t_create_ma_004081b0,DVar4);
        MessageBoxA((HWND)0x0,local_628,s_Error_004081e6,0);
      }
    }
  }
  return 0;
}


