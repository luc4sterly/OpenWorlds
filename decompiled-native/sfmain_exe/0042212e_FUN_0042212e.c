// 0042212e FUN_0042212e [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0042212e(undefined4 param_1,undefined4 param_2)

{
  HWND in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar2;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int extraout_EDX;
  undefined8 uVar3;
  undefined4 local_1c;
  
  DAT_0043d610 = 0;
  if ((DAT_0046267c == '\0') || (DAT_0045e280 == '\0')) {
    DAT_00462678 = 0;
  }
  if (DAT_0043d624 != 0) {
    FUN_0042b9b8();
    DAT_0043d624 = 0;
  }
  if (DAT_0045e280 != '\0') {
    DAT_00462564 = FUN_00425757(DAT_00462788,DAT_00462780,0);
  }
  if (DAT_0043d630 != 0) {
    FUN_0042b9b8();
    DAT_0043d630 = 0;
  }
  DAT_00462560 = FUN_00425757(0,DAT_00462780,1);
  uVar2 = extraout_ECX;
  if (DAT_0043d62c != 0) {
    FUN_0042b9b8();
    DAT_0043d62c = 0;
    uVar2 = extraout_ECX_00;
  }
  DAT_0046256c = FUN_0042a16d(uVar2,0);
  if (DAT_00462678 != 0) {
    _DAT_004b2be8 = 2;
    _DAT_004b2bea = Ordinal_9(0x820);
    _DAT_004b2bec = Ordinal_10(&DAT_0046267c);
    if (_DAT_004b2bec == -1) {
      iVar1 = Ordinal_52(&DAT_0046267c);
      if (iVar1 == 0) {
        Ordinal_111();
        uVar3 = FUN_00429482(extraout_ECX_02,extraout_EDX);
        uVar3 = FUN_00429192(extraout_ECX_03,(int)((ulonglong)uVar3 >> 0x20));
        FUN_00429268(extraout_ECX_04,(int)((ulonglong)uVar3 >> 0x20),0x8f,
                     s__GAMMA_speakfre_sfmain_LWL_c_00437228,0x13,in_EAX,0x10,(LPCSTR)uVar3);
        local_1c = 0;
        goto LAB_004222fb;
      }
      FUN_004080a4(extraout_ECX_01,(undefined1 *)**(undefined4 **)(iVar1 + 0xc));
    }
    if (DAT_0043d61c == 0) {
      DAT_0043d614 = 2;
    }
    else {
      DAT_0043d61c = 2;
    }
    DAT_0043d610 = DAT_00462678;
  }
  local_1c = 1;
LAB_004222fb:
  return CONCAT44(param_2,local_1c);
}


