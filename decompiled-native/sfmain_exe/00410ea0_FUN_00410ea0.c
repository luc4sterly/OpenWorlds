// 00410ea0 FUN_00410ea0 [Global]
// program: sfmain.exe

UINT_PTR __fastcall FUN_00410ea0(undefined4 param_1,LPCSTR param_2)

{
  HWND in_EAX;
  int iVar1;
  UINT_PTR UVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined8 uVar3;
  LONG local_2c;
  HWND local_28;
  LPCSTR local_24;
  LONG local_20;
  HFILE local_1c;
  undefined1 local_18 [4];
  
  local_1c = 0xffffffff;
  local_28 = in_EAX;
  local_24 = param_2;
  local_20 = GetWindowLongA(in_EAX,0);
  *(undefined4 *)(local_20 + 0x650) = 0;
  *(undefined4 *)(local_20 + 300) = 0xffffffff;
  if (0 < *(int *)(local_20 + 0x10)) {
    *(undefined4 *)(local_20 + 0x10) = 0;
  }
  *(undefined4 *)(local_20 + 0x130) = 0;
  local_1c = _lopen(local_24,0x20);
  if (local_1c == -1) {
    uVar3 = FUN_00429192(extraout_ECX,extraout_EDX);
    uVar3 = FUN_00429268(extraout_ECX_00,(int)((ulonglong)uVar3 >> 0x20),0x495,
                         s__GAMMA_speakfre_sfmain_CONNECT_c_00435dcc,6,local_28,0x10,(LPCSTR)uVar3);
    UVar2 = (UINT_PTR)uVar3;
    if (local_1c != -1) {
      UVar2 = _lclose(local_1c);
    }
  }
  else {
    _lread(local_1c,local_18,4);
    iVar1 = FUN_004080b5(extraout_ECX_01,&DAT_00435ded);
    if (iVar1 == 0) {
      _lclose(local_1c);
      iVar1 = FUN_00424715(extraout_ECX_03,local_20);
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      iVar1 = FUN_004080b5(extraout_ECX_02,&DAT_00435df2);
      if (iVar1 == 0) {
        _lread(local_1c,&local_2c,4);
        FUN_0042965d();
        _llseek(local_1c,local_2c,0);
      }
      else {
        _llseek(local_1c,0,0);
      }
      *(HFILE *)(local_20 + 300) = local_1c;
    }
    *(undefined1 *)(local_20 + 4) = 3;
    DAT_0043d628 = 1;
    if (0 < *(int *)(local_20 + 0x10)) {
      *(undefined4 *)(local_20 + 0x10) = 0;
    }
    DragAcceptFiles(local_28,0);
    UVar2 = SetTimer(local_28,2,200,(TIMERPROC)0x0);
    if (UVar2 == 0) {
      uVar3 = FUN_00429192(extraout_ECX_04,extraout_EDX_00);
      uVar3 = FUN_00429268(extraout_ECX_05,(int)((ulonglong)uVar3 >> 0x20),0x4c2,
                           s__GAMMA_speakfre_sfmain_CONNECT_c_00435df7,2,(HWND)0x0,0x10,
                           (LPCSTR)uVar3);
      UVar2 = (UINT_PTR)uVar3;
    }
  }
  return UVar2;
}


