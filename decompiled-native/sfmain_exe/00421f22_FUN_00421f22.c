// 00421f22 FUN_00421f22 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_00421f22(undefined4 param_1,int param_2)

{
  HWND in_EAX;
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  undefined8 uVar3;
  undefined4 local_18;
  
  iVar1 = Ordinal_23(2,1,0);
  if (iVar1 == -1) {
    Ordinal_111();
    uVar3 = FUN_00429482(extraout_ECX,extraout_EDX);
    uVar3 = FUN_00429192(extraout_ECX_00,(int)((ulonglong)uVar3 >> 0x20));
    FUN_00429268(extraout_ECX_01,(int)((ulonglong)uVar3 >> 0x20),0x3b,
                 s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,in_EAX,0x10,(LPCSTR)uVar3);
    local_18 = 0;
  }
  else {
    uVar3 = Ordinal_4(iVar1,&DAT_004b2be8,0x10);
    if ((int)uVar3 < 0) {
      Ordinal_111();
      uVar3 = FUN_00429482(extraout_ECX_09,extraout_EDX_02);
      uVar3 = FUN_00429192(extraout_ECX_10,(int)((ulonglong)uVar3 >> 0x20));
      FUN_00429268(extraout_ECX_11,(int)((ulonglong)uVar3 >> 0x20),0x5a,
                   s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,in_EAX,0x10,(LPCSTR)uVar3);
      Ordinal_3(iVar1);
      local_18 = 0;
    }
    else {
      if (param_2 == 0) {
        iVar2 = FUN_00429725();
        if (iVar2 < 0) {
          Ordinal_111();
          uVar3 = FUN_00429482(extraout_ECX_06,extraout_EDX_01);
          uVar3 = FUN_00429192(extraout_ECX_07,(int)((ulonglong)uVar3 >> 0x20));
          FUN_00429268(extraout_ECX_08,(int)((ulonglong)uVar3 >> 0x20),0x51,
                       s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,in_EAX,0x10,(LPCSTR)uVar3);
          Ordinal_3(iVar1);
          return 0;
        }
      }
      else {
        FUN_00429192(0,(int)((ulonglong)uVar3 >> 0x20));
        FUN_00425b92(extraout_ECX_02,DAT_00462780);
        iVar2 = FUN_00429725();
        if (iVar2 < 0) {
          Ordinal_111();
          uVar3 = FUN_00429482(extraout_ECX_03,extraout_EDX_00);
          uVar3 = FUN_00429192(extraout_ECX_04,(int)((ulonglong)uVar3 >> 0x20));
          FUN_00429268(extraout_ECX_05,(int)((ulonglong)uVar3 >> 0x20),0x48,
                       s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,in_EAX,0x10,(LPCSTR)uVar3);
          Ordinal_3(iVar1);
          return 0;
        }
      }
      Ordinal_3(iVar1);
      local_18 = 1;
    }
  }
  return local_18;
}


