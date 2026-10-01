// 00415033 FUN_00415033 [Global]
// program: sfmain.exe

undefined4 __fastcall
FUN_00415033(undefined4 param_1,undefined4 param_2,HWND param_3,uint param_4,short param_5)

{
  LPCSTR pCVar1;
  int iVar2;
  HWND pHVar3;
  ULONG_PTR dwData;
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
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 uVar4;
  undefined4 extraout_EDX_03;
  undefined8 uVar5;
  UINT uCommand;
  undefined4 uVar6;
  int iVar7;
  int local_70;
  char *local_6c;
  char *local_68;
  CHAR local_64 [84];
  
  if (0x10f < param_4) {
    if (param_4 < 0x111) {
      uVar6 = 0x20;
      uVar5 = FUN_00429192(param_1,param_2);
      wsprintfA(local_64,(LPCSTR)uVar5,uVar6);
      SetDlgItemTextA(param_3,0x427,local_64);
      if (DAT_0043d6ac == 0) {
        uVar5 = FUN_00429192(extraout_ECX,extraout_EDX);
        SetDlgItemTextA(param_3,0x3f8,(LPCSTR)uVar5);
        uVar6 = extraout_ECX_04;
        uVar4 = extraout_EDX_02;
      }
      else {
        if (DAT_0043d520 == 0) {
          uVar5 = FUN_00429192(extraout_ECX,extraout_EDX);
          local_68 = (char *)uVar5;
          uVar6 = extraout_ECX_01;
        }
        else {
          uVar5 = FUN_00429192(extraout_ECX,extraout_EDX);
          local_68 = (char *)uVar5;
          uVar6 = extraout_ECX_00;
        }
        FUN_0042c5c6(uVar6,local_68);
        iVar7 = DAT_0043d6ac;
        uVar6 = DAT_004627a8;
        uVar5 = FUN_00429192(extraout_ECX_02,extraout_EDX_00);
        pCVar1 = (LPCSTR)uVar5;
        iVar2 = FUN_0042c5ad();
        wsprintfA(local_64 + iVar2,pCVar1,iVar7,uVar6);
        SetDlgItemTextA(param_3,0x3f8,local_64);
        uVar6 = extraout_ECX_03;
        uVar4 = extraout_EDX_01;
      }
      if (DAT_0043d6b0 == 0) {
        uVar5 = FUN_00429192(uVar6,uVar4);
        SetDlgItemTextA(param_3,0x3f7,(LPCSTR)uVar5);
      }
      else {
        if (DAT_0043d51c == 0) {
          uVar5 = FUN_00429192(uVar6,uVar4);
          local_6c = (char *)uVar5;
          uVar6 = extraout_ECX_06;
        }
        else {
          uVar5 = FUN_00429192(uVar6,uVar4);
          local_6c = (char *)uVar5;
          uVar6 = extraout_ECX_05;
        }
        FUN_0042c5c6(uVar6,local_6c);
        iVar7 = DAT_0043d6b0;
        uVar6 = DAT_004627b0;
        uVar5 = FUN_00429192(extraout_ECX_07,extraout_EDX_03);
        pCVar1 = (LPCSTR)uVar5;
        iVar2 = FUN_0042c5ad();
        wsprintfA(local_64 + iVar2,pCVar1,iVar7,uVar6);
        SetDlgItemTextA(param_3,0x3f7,local_64);
      }
      if (DAT_0043d5f8 == 0) {
        local_70 = 0;
      }
      else {
        local_70 = 5;
      }
      pHVar3 = GetDlgItem(param_3,0x3f9);
      ShowWindow(pHVar3,local_70);
      iVar7 = 5;
      pHVar3 = GetDlgItem(param_3,0x421);
      ShowWindow(pHVar3,iVar7);
      iVar7 = 0;
      pHVar3 = GetDlgItem(param_3,0x420);
      ShowWindow(pHVar3,iVar7);
    }
    else if ((param_4 == 0x111) && (-4 < param_5)) {
      if (param_5 < -2) {
        uVar5 = FUN_00429192(param_1,param_2);
        dwData = (ULONG_PTR)uVar5;
        uCommand = 0x101;
        uVar5 = FUN_00429192(extraout_ECX_08,(int)((ulonglong)uVar5 >> 0x20));
        WinHelpA(DAT_004627d0,(LPCSTR)uVar5,uCommand,dwData);
        DAT_0043d608 = 1;
      }
      else if (param_5 == 1) {
        EndDialog(param_3,1);
      }
    }
  }
  return 0;
}


