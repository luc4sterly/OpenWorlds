// 0040fee0 _Java_NET_worlds_console_WebBrowser_browse@36 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_WebBrowser_browse_36
               (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
               int param_6,int param_7,int param_8,int *param_9)

{
  char cVar1;
  int iVar2;
  LPCSTR lpMultiByteStr;
  LPWSTR lpWideCharStr;
  LPCSTR lpString;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined2 local_68;
  undefined2 uStack_66;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  int local_50;
  undefined4 uStack_4c;
  undefined4 *local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  HWND local_14;
  
                    /* 0xfee0  74  _Java_NET_worlds_console_WebBrowser_browse@36 */
  if (param_9 == (int *)0x0) {
    FUN_00402800(s_nWebBrowser_0046ef68,0x85);
  }
  bVar6 = false;
  if (param_5 != -1) {
    iVar2 = (**(code **)(*param_9 + 0x58))(param_9,param_5);
    if (iVar2 != 0) goto LAB_0041019f;
  }
  if (param_6 != -1) {
    iVar2 = (**(code **)(*param_9 + 0x60))(param_9,param_6);
    if (iVar2 != 0) goto LAB_0041019f;
  }
  if (param_7 != -1) {
    iVar2 = (**(code **)(*param_9 + 0x68))(param_9,param_7);
    if (iVar2 != 0) goto LAB_0041019f;
  }
  if (param_8 != -1) {
    iVar2 = (**(code **)(*param_9 + 0x70))(param_9,param_8);
    if (iVar2 != 0) goto LAB_0041019f;
  }
  lpMultiByteStr = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_3,0);
  iVar2 = MultiByteToWideChar(0,8,lpMultiByteStr,-1,(LPWSTR)0x0,0);
  if (iVar2 != 0) {
    lpWideCharStr = (LPWSTR)FUN_00450b60(iVar2 * 2);
    if (lpWideCharStr != (LPWSTR)0x0) {
      MultiByteToWideChar(0,8,lpMultiByteStr,-1,lpWideCharStr,iVar2);
      iVar2 = Ordinal_2(lpWideCharStr);
      if (iVar2 != 0) {
        if (param_4 == 0) {
          local_24 = DAT_00489330;
          uStack_20 = DAT_00489334;
          uStack_1c = DAT_00489338;
          uStack_18 = DAT_0048933c;
          uVar3 = (**(code **)(*param_9 + 0x2c))
                            (param_9,iVar2,&local_24,&local_24,&local_24,&local_24);
        }
        else {
          lpString = (LPCSTR)(**(code **)(*param_1 + 0x2a4))(param_1,param_4,0);
          uStack_64 = DAT_004892f4;
          local_60 = DAT_004892f8;
          uStack_5c = DAT_004892fc;
          _local_68 = CONCAT22((short)((uint)DAT_004892f0 >> 0x10),8);
          local_60 = Ordinal_2(u_Content_Type__application_x_www__0046efb8);
          local_58 = DAT_00489300;
          uStack_54 = DAT_00489304;
          local_50 = DAT_00489308;
          uStack_4c = DAT_0048930c;
          uVar3 = lstrlenA(lpString);
          iVar4 = Ordinal_411(0x11,0,uVar3);
          if (iVar4 == 0) {
            return;
          }
          Ordinal_23(iVar4,&local_48);
          FUN_0044df50(local_48,(undefined4 *)lpString,uVar3);
          Ordinal_24(iVar4);
          local_58 = CONCAT22(local_58._2_2_,0x2011);
          local_44 = DAT_00489310;
          uStack_40 = DAT_00489314;
          uStack_3c = DAT_00489318;
          uStack_38 = DAT_0048931c;
          local_34 = DAT_00489320;
          uStack_30 = DAT_00489324;
          uStack_2c = DAT_00489328;
          uStack_28 = DAT_0048932c;
          local_50 = iVar4;
          uVar3 = (**(code **)(*param_9 + 0x2c))
                            (param_9,iVar2,&local_44,&local_34,&local_58,&local_68);
          (**(code **)(*param_1 + 0x2a8))(param_1,param_4,lpString);
          Ordinal_9(&local_58);
        }
        if (uVar3 < 2) {
          iVar4 = (**(code **)(*param_9 + 0xa4))(param_9,0xffffffff);
          bVar6 = iVar4 == 0;
        }
        uVar5 = (**(code **)(*param_1 + 0x240))
                          (param_1,param_2,s__stayMinimized_0046efa8,&DAT_0046ef88);
        cVar1 = (**(code **)(*param_1 + 0x248))(param_1,param_2,uVar5);
        if (cVar1 == '\0') {
          local_14 = (HWND)0x0;
          iVar4 = (**(code **)(*param_9 + 0x94))(param_9,&local_14);
          if ((iVar4 == 0) && (local_14 != (HWND)0x0)) {
            ShowWindow(local_14,9);
            SetForegroundWindow(local_14);
          }
        }
        Ordinal_6(iVar2);
      }
      FUN_00451780((undefined4 *)lpWideCharStr);
    }
  }
  (**(code **)(*param_1 + 0x2a8))(param_1,param_3,lpMultiByteStr);
LAB_0041019f:
  if (!bVar6) {
    FUN_00402930(param_1,(byte *)s_java_io_IOException_0046ef74,s_nWebBrowser_0046ef68);
  }
  return;
}


