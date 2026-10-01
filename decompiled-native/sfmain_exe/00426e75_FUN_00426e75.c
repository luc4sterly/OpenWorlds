// 00426e75 FUN_00426e75 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_00426e75(int param_1,LPWAVEHDR param_2)

{
  HWAVEOUT in_EAX;
  MMRESULT MVar1;
  undefined4 uVar2;
  HGLOBAL pvVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_EDX;
  UINT unaff_EBX;
  undefined8 uVar4;
  short local_10;
  
  MVar1 = waveOutWrite(in_EAX,param_2,unaff_EBX);
  local_10 = (short)MVar1;
  if (local_10 == 0) {
    DAT_0043d538 = DAT_0043d538 + 1;
    uVar2 = FUN_004173ab(extraout_ECX,DAT_0043d538);
    if (param_1 != 0) {
      DAT_004623a4 = DAT_004623a4 + 1;
      uVar2 = FUN_004173ab(extraout_ECX_00,DAT_004623a4);
    }
  }
  else {
    waveOutGetErrorTextA(MVar1 & 0xffff,(LPSTR)0x4c746a,0x100);
    waveOutUnprepareHeader(in_EAX,param_2,unaff_EBX);
    if (param_2->lpData != (LPSTR)0x0) {
      pvVar3 = GlobalHandle(param_2->lpData);
      GlobalUnlock(pvVar3);
      pvVar3 = GlobalHandle(param_2->lpData);
      GlobalFree(pvVar3);
    }
    pvVar3 = GlobalHandle(param_2);
    GlobalUnlock(pvVar3);
    pvVar3 = GlobalHandle(param_2);
    GlobalFree(pvVar3);
    uVar4 = FUN_00429192(extraout_ECX_01,extraout_EDX);
    uVar4 = FUN_00429268(extraout_ECX_02,(int)((ulonglong)uVar4 >> 0x20),0x21e,
                         s__GAMMA_speakfre_sfmain_SPEAKER_c_00437428,0xc,(HWND)0x0,0x30,
                         (LPCSTR)uVar4);
    uVar2 = (undefined4)uVar4;
  }
  return uVar2;
}


