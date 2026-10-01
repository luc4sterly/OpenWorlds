// 00415cfa FUN_00415cfa [Global]
// program: sfmain.exe

void __fastcall FUN_00415cfa(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  char *pcVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int unaff_EBX;
  undefined8 uVar2;
  
  if (unaff_EBX == 0) {
    FUN_0042c5c6(param_1,DAT_00459e00);
    FUN_004080a4(extraout_ECX_04,(undefined1 *)*DAT_00459e0c);
    EndDialog(in_EAX,1);
  }
  else if (DAT_00459dfc == -1) {
    uVar2 = FUN_00429482(param_1,param_2);
    uVar2 = FUN_00429192(extraout_ECX,(int)((ulonglong)uVar2 >> 0x20));
    FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar2 >> 0x20),0x492,
                 s__GAMMA_speakfre_sfmain_DIALOGS_c_0043600a,5,in_EAX,0x10,(LPCSTR)uVar2);
    FUN_00415c62(extraout_ECX_01,1);
  }
  else {
    pcVar1 = (char *)Ordinal_11(DAT_00459dfc);
    FUN_0042c5c6(extraout_ECX_02,pcVar1);
    FUN_004080a4(extraout_ECX_03,(undefined1 *)&DAT_00459dfc);
    EndDialog(in_EAX,1);
  }
  return;
}


