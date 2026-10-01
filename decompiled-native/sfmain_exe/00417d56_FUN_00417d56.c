// 00417d56 FUN_00417d56 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_00417d56(undefined4 param_1,undefined4 param_2)

{
  HWND in_EAX;
  MMRESULT MVar1;
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
  undefined4 uVar2;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 uVar3;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined8 uVar4;
  MMRESULT local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  if (DAT_0043d5c8 != 0) {
    DAT_0043d69c = 0x2b11;
    DAT_0043d6a0 = 0x5622;
  }
  while( true ) {
    local_24 = FUN_004175c0(0,DAT_0043d5f0,0,1);
    if ((8 < _DAT_0043d6a8) && (local_24 == 0x20)) {
      DAT_0043d5fc = 1;
    }
    uVar2 = extraout_ECX;
    uVar3 = extraout_EDX;
    if (((DAT_0043d600 != 0) || (local_24 == 0x20)) && (8 < _DAT_0043d6a8)) {
      _DAT_0043d6a8 = _DAT_0043d6a8 / 2;
      DAT_0043d6a4 = DAT_0043d6a4 / 2;
      DAT_0043d6a0 = DAT_0043d6a0 / 2;
      local_24 = FUN_004175c0(0,DAT_0043d5f0,0,1);
      uVar2 = extraout_ECX_00;
      uVar3 = extraout_EDX_00;
    }
    if ((local_24 != 0x20) || (DAT_0043d69c != 8000)) break;
    DAT_0043d69c = 0x2b11;
    _DAT_0043d6a8 = 0x10;
    DAT_0043d6a4 = 2;
    DAT_0043d6a0 = 0x5622;
  }
  if (local_24 != 0) {
    uVar4 = FUN_00429192(uVar2,uVar3);
    FUN_00429268(extraout_ECX_01,(int)((ulonglong)uVar4 >> 0x20),0x347,
                 s__GAMMA_speakfre_sfmain_FRAME_c_004361f2,9,in_EAX,0x30,s_2___s___d__004361e7);
    local_1c = 0xffffffff;
    goto LAB_00418281;
  }
  MVar1 = FUN_004175c0((DWORD_PTR)in_EAX,DAT_0043d5f0,0,0x10000);
  if (MVar1 != 0) {
    waveInGetErrorTextA(MVar1,&DAT_00462826,0x100);
    uVar4 = FUN_00429192(extraout_ECX_03,extraout_EDX_02);
    FUN_00429268(extraout_ECX_04,(int)((ulonglong)uVar4 >> 0x20),0x352,
                 s__GAMMA_speakfre_sfmain_FRAME_c_00436218,10,in_EAX,0x30,s__s___s_00436211);
    local_1c = 0xffffffff;
    goto LAB_00418281;
  }
  DAT_004627a8 = _DAT_0043d6a8;
  DAT_0043d6ac = DAT_0043d69c;
  if (DAT_0043d5c4 != 0) {
    FUN_00417664(extraout_ECX_02,extraout_EDX_01);
    DAT_0043d5f8 = 1;
    local_20 = 1;
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
  if (local_24 == 0) {
    MVar1 = FUN_004177c0((DWORD_PTR)in_EAX,DAT_0043d5f4,0,0x10000);
    if (MVar1 == 0) {
      DAT_004627b0 = _DAT_0043d6a8;
      DAT_0043d6b0 = DAT_0043d69c;
      uVar4 = FUN_004176a3(extraout_ECX_08,extraout_EDX_04);
      uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
      uVar2 = extraout_ECX_13;
      goto LAB_00418268;
    }
    if ((DAT_0043d5c4 != 0) || ((MVar1 != 4 && (MVar1 != 8)))) {
      waveOutGetErrorTextA(MVar1,&DAT_00462a26,0x100);
      uVar4 = FUN_00429192(extraout_ECX_10,extraout_EDX_06);
      uVar4 = FUN_00429268(extraout_ECX_11,(int)((ulonglong)uVar4 >> 0x20),0x3ac,
                           s__GAMMA_speakfre_sfmain_FRAME_c_00436256,0xc,in_EAX,0x30,
                           s__s___s_00436211);
      uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
      local_20 = 0xffffffff;
      uVar2 = extraout_ECX_12;
      goto LAB_00418268;
    }
    DAT_0043d5f8 = 1;
    local_20 = 1;
    FUN_00417664(extraout_ECX_08,extraout_EDX_04);
    MVar1 = FUN_004177c0((DWORD_PTR)in_EAX,DAT_0043d5f4,0,0x10000);
    uVar2 = extraout_ECX_09;
    uVar3 = extraout_EDX_05;
    if (MVar1 != 0) goto LAB_00418268;
    DAT_004627b0 = _DAT_0043d6a8;
    DAT_0043d6b0 = DAT_0043d69c;
    FUN_004176a3(extraout_ECX_09,extraout_EDX_05);
  }
  else {
    waveOutGetErrorTextA(local_24,&DAT_00462926,0x100);
    uVar4 = FUN_00429192(extraout_ECX_05,extraout_EDX_03);
    uVar4 = FUN_00429268(extraout_ECX_06,(int)((ulonglong)uVar4 >> 0x20),0x38e,
                         s__GAMMA_speakfre_sfmain_FRAME_c_00436237,0xb,in_EAX,0x30,s__s___s_00436211
                        );
    uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
    local_20 = 0xffffffff;
    uVar2 = extraout_ECX_07;
LAB_00418268:
    if (DAT_0043d5c4 == 0) {
      FUN_00417664(uVar2,uVar3);
    }
  }
  local_1c = local_20;
LAB_00418281:
  return CONCAT44(param_2,local_1c);
}


