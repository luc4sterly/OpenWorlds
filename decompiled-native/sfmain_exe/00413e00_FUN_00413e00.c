// 00413e00 FUN_00413e00 [Global]
// programa: sfmain.exe

undefined4 __fastcall FUN_00413e00(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  uint uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int extraout_EDX;
  undefined8 uVar3;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [4];
  HWND local_20;
  int local_1c;
  
  local_20 = in_EAX;
  local_1c = param_2;
  uVar1 = Ordinal_14(*(undefined4 *)(param_2 + 0x18));
  if ((uVar1 & 0xf0000000) == 0xe0000000) {
    if (DAT_0043d59c == 0) {
      local_2c = *(undefined4 *)(local_1c + 0x4c38);
      iVar2 = Ordinal_21(*(undefined4 *)(local_1c + 8),0,3,&local_2c,4);
      if ((iVar2 == -1) ||
         (iVar2 = Ordinal_21(*(undefined4 *)(local_1c + 0xc),0,3,&local_2c,4), iVar2 == -1)) {
        Ordinal_111();
        uVar3 = FUN_00429482(extraout_ECX_02,extraout_EDX);
        uVar3 = FUN_00429192(extraout_ECX_03,(int)((ulonglong)uVar3 >> 0x20));
        FUN_00429268(extraout_ECX_04,(int)((ulonglong)uVar3 >> 0x20),0x87,
                     s__GAMMA_speakfre_sfmain_DIALOGS_c_00435f7d,3,local_20,0x10,(LPCSTR)uVar3);
      }
    }
    else {
      local_24[0] = *(undefined1 *)(local_1c + 0x4c38);
      iVar2 = Ordinal_21(*(undefined4 *)(local_1c + 8),0,3,local_24,1);
      if ((iVar2 == -1) ||
         (iVar2 = Ordinal_21(*(undefined4 *)(local_1c + 0xc),0,3,local_24,1), iVar2 == -1)) {
        uVar3 = Ordinal_111();
        local_28 = (undefined4)uVar3;
        uVar3 = FUN_00429482(extraout_ECX,(int)((ulonglong)uVar3 >> 0x20));
        uVar3 = FUN_00429192(extraout_ECX_00,(int)((ulonglong)uVar3 >> 0x20));
        FUN_00429268(extraout_ECX_01,(int)((ulonglong)uVar3 >> 0x20),0x7b,
                     s__GAMMA_speakfre_sfmain_DIALOGS_c_00435f5c,3,local_20,0x10,(LPCSTR)uVar3);
      }
    }
  }
  *(undefined4 *)(local_1c + 0x4e50) = 0;
  return 1;
}


