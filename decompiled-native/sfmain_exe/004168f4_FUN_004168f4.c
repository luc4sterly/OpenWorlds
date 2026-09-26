// 004168f4 FUN_004168f4 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_004168f4(undefined4 param_1,undefined4 param_2)

{
  HWND in_EAX;
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 uVar2;
  undefined4 extraout_ECX_06;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 local_58 [12];
  short local_4c;
  short local_4a;
  int local_48;
  uint local_38;
  undefined1 local_30 [16];
  HWND local_20;
  undefined4 local_1c;
  
  local_20 = in_EAX;
  FUN_004168bf();
  if (DAT_0043d404 == '\0') {
    local_1c = 1;
    goto LAB_00416a40;
  }
  DAT_0043d50c = _lopen(&DAT_0043d404,0);
  if (DAT_0043d50c == -1) {
    uVar4 = FUN_00429192(extraout_ECX,extraout_EDX);
    FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar4 >> 0x20),0x21,
                 s_Y__GAMMA_speakfre_sfmain_FACE_c_0043608a + 2,6,local_20,0x10,(LPCSTR)uVar4);
  }
  else {
    _lread(DAT_0043d50c,local_30,0xe);
    iVar1 = FUN_0042cc34(extraout_ECX_01,(byte *)s_GIF87a_004360aa);
    if ((iVar1 == 0) ||
       (iVar1 = FUN_0042cc34(extraout_ECX_02,(byte *)s_GIF89a_004360b1), iVar1 == 0)) {
      local_1c = 1;
      goto LAB_00416a40;
    }
    iVar1 = FUN_0042cc34(extraout_ECX_03,&DAT_004360b8);
    uVar2 = extraout_ECX_04;
    uVar3 = extraout_EDX_00;
    if (((iVar1 == 0) &&
        (((_lread(DAT_0043d50c,local_58,0x28), uVar2 = extraout_ECX_05, uVar3 = extraout_EDX_01,
          local_4a == 8 && (local_48 == 0)) && (local_38 < 0x101)))) && (local_4c == 1)) {
      local_1c = 1;
      goto LAB_00416a40;
    }
    uVar4 = FUN_00429192(uVar2,uVar3);
    FUN_00429268(extraout_ECX_06,(int)((ulonglong)uVar4 >> 0x20),0x32,
                 s__GAMMA_speakfre_sfmain_FACE_c_004360bb,2,local_20,0x10,(LPCSTR)uVar4);
    FUN_004168bf();
  }
  local_1c = 0;
LAB_00416a40:
  return CONCAT44(param_2,local_1c);
}


