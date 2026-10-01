// 00415dec FUN_00415dec [Global]
// program: sfmain.exe

void __fastcall FUN_00415dec(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  ULONG_PTR dwData;
  HWND hWnd;
  undefined1 *puVar1;
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
  undefined4 uVar2;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_EDX;
  int extraout_EDX_00;
  undefined8 uVar3;
  UINT uCommand;
  char *lpString;
  int nMaxCount;
  undefined1 *local_2c;
  int local_28;
  int local_14;
  
  if (param_2 < 1) {
    if (param_2 == -3) {
      uVar3 = FUN_00429192(param_1,0xfffffffd);
      dwData = (ULONG_PTR)uVar3;
      uCommand = 0x101;
      uVar3 = FUN_00429192(extraout_ECX,(int)((ulonglong)uVar3 >> 0x20));
      WinHelpA(DAT_004627d0,(LPCSTR)uVar3,uCommand,dwData);
      DAT_0043d608 = 1;
    }
  }
  else if (param_2 < 2) {
    nMaxCount = 0x100;
    lpString = DAT_00459dec;
    hWnd = GetDlgItem(in_EAX,0xc1d);
    GetWindowTextA(hWnd,lpString,nMaxCount);
    if (*DAT_00459dec != '\0') {
      local_2c = (undefined1 *)FUN_0042cbb3(extraout_ECX_00,'/');
      uVar2 = extraout_ECX_01;
      if ((local_2c == (undefined1 *)0x0) &&
         (local_2c = (undefined1 *)FUN_0042cbb3(extraout_ECX_01,':'), uVar2 = extraout_ECX_02,
         local_2c == (undefined1 *)0x0)) {
        local_28 = 0x81e;
      }
      else {
        FUN_0042c5c6(uVar2,local_2c + 1);
        uVar3 = FUN_0042cbc7(extraout_ECX_03,extraout_EDX);
        local_28 = (int)uVar3;
        if (local_28 == 0) {
          uVar3 = FUN_00429192(extraout_ECX_04,(int)((ulonglong)uVar3 >> 0x20));
          FUN_00429268(extraout_ECX_05,(int)((ulonglong)uVar3 >> 0x20),0x519,
                       s__GAMMA_speakfre_sfmain_DIALOGS_c_0043602b,2,in_EAX,0x10,(LPCSTR)uVar3);
          return;
        }
        *local_2c = 0;
      }
      *DAT_00459df4 = (short)local_28;
      DAT_00459dfc = Ordinal_10(DAT_00459dec);
      if (DAT_00459dfc == -1) {
        local_14 = Ordinal_103(in_EAX,0x465,DAT_00459dec,&DAT_00459e00,0x400);
        uVar2 = extraout_ECX_06;
      }
      else {
        if (DAT_0043d5ac != 0) {
          puVar1 = (undefined1 *)Ordinal_51(&DAT_00459dfc,4,2);
          if (puVar1 == (undefined1 *)0x0) {
            Ordinal_111();
          }
          else {
            FUN_004080a4(extraout_ECX_08,puVar1);
          }
          FUN_00415cfa(0,0);
          return;
        }
        local_14 = Ordinal_102(in_EAX,0x465,&DAT_00459dfc,4,2,&DAT_00459e00,0x400);
        uVar2 = extraout_ECX_07;
      }
      if ((local_14 == 0) && (DAT_0043d5ac == 0)) {
        Ordinal_111();
        uVar3 = FUN_00429482(extraout_ECX_09,extraout_EDX_00);
        uVar3 = FUN_00429192(extraout_ECX_10,(int)((ulonglong)uVar3 >> 0x20));
        FUN_00429268(extraout_ECX_11,(int)((ulonglong)uVar3 >> 0x20),0x559,
                     s__GAMMA_speakfre_sfmain_DIALOGS_c_0043604c,5,in_EAX,0x10,(LPCSTR)uVar3);
      }
      else {
        FUN_00415c62(uVar2,0);
      }
    }
  }
  else if (param_2 == 2) {
    if (DAT_00459df8 != 0) {
      Ordinal_108(DAT_00459df8);
      DAT_00459df8 = 0;
    }
    EndDialog(in_EAX,0);
  }
  return;
}


