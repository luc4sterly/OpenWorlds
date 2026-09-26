// 0041aa9b FUN_0041aa9b [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0041aa9b(undefined4 param_1,undefined4 param_2)

{
  HWND in_EAX;
  MMRESULT mmrError;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined8 uVar1;
  MMRESULT local_24;
  undefined4 local_1c;
  
  DAT_0043d534 = 0;
  if (DAT_0043d51c == 0) {
    if (((DAT_0043d5f8 != 0) && (DAT_0043d520 != 0)) && (DAT_0043d55c == 0)) {
      DAT_0043d6bc = DAT_0043d6bc + 1;
      FUN_004173ab(param_1,DAT_0043d6bc);
      local_1c = 0;
      goto LAB_0041adeb;
    }
    if (((DAT_0043d5f8 != 0) && (DAT_0043d520 != 0)) && (DAT_0043d55c != 0)) {
      FUN_00418bb7(param_1,param_2);
      DAT_0043d524 = 1;
      if (DAT_0043d520 != 0) {
        DAT_0043d6bc = DAT_0043d6bc + 1;
        FUN_004173ab(extraout_ECX,DAT_0043d6bc);
        local_1c = 0;
        goto LAB_0041adeb;
      }
    }
    while( true ) {
      local_24 = FUN_004177c0(0,DAT_0043d5f4,0,1);
      if ((8 < _DAT_0043d6a8) && (local_24 == 0x20)) {
        DAT_0043d5fc = 1;
      }
      if (((DAT_0043d600 != 0) || (local_24 == 0x20)) && (8 < _DAT_0043d6a8)) {
        _DAT_0043d6a8 = _DAT_0043d6a8 / 2;
        DAT_0043d6a4 = DAT_0043d6a4 / 2;
        DAT_0043d6a0 = DAT_0043d6a0 / 2;
        local_24 = FUN_004177c0(0,DAT_0043d5f4,0,1);
      }
      if ((local_24 != 0x20) || (DAT_0043d69c != 8000)) break;
      DAT_0043d69c = 0x2b11;
      _DAT_0043d6a8 = 0x10;
      DAT_0043d6a4 = 2;
      DAT_0043d6a0 = 0x5622;
    }
    if (local_24 != 0) {
      waveOutGetErrorTextA(local_24,&DAT_00462eea,0x100);
      uVar1 = FUN_00429192(extraout_ECX_00,extraout_EDX);
      FUN_00429268(extraout_ECX_01,(int)((ulonglong)uVar1 >> 0x20),0xc02,
                   s__GAMMA_speakfre_sfmain_FRAME_c_00436611,0xb,in_EAX,0x30,s__s___s_00436211);
      local_1c = 0;
      goto LAB_0041adeb;
    }
    mmrError = FUN_004177c0((DWORD_PTR)in_EAX,DAT_0043d5f4,0,0x10000);
    if (mmrError != 0) {
      if (((mmrError == 4) || (mmrError == 8)) && (DAT_0043d520 != 0)) {
        DAT_0043d6bc = DAT_0043d6bc + 1;
        FUN_004173ab(extraout_ECX_02,DAT_0043d6bc);
        local_1c = 0;
      }
      else {
        waveOutGetErrorTextA(mmrError,&DAT_00462fea,0x100);
        uVar1 = FUN_00429192(extraout_ECX_03,extraout_EDX_01);
        FUN_00429268(extraout_ECX_04,(int)((ulonglong)uVar1 >> 0x20),0xc1f,
                     s__GAMMA_speakfre_sfmain_FRAME_c_00436630,0xc,in_EAX,0x30,s__s___s_00436211);
        local_1c = 0;
      }
      goto LAB_0041adeb;
    }
    DAT_0043d51c = 1;
    DAT_0043d6b0 = DAT_0043d69c;
    DAT_004627b0 = _DAT_0043d6a8;
    FUN_004152eb(extraout_ECX_02,extraout_EDX_00);
  }
  local_1c = 1;
LAB_0041adeb:
  return CONCAT44(param_2,local_1c);
}


