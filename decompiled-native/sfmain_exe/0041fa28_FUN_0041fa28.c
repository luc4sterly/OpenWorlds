// 0041fa28 FUN_0041fa28 [Global]
// program: sfmain.exe

undefined4 __fastcall FUN_0041fa28(undefined4 param_1,LPSTR param_2)

{
  DWORD_PTR in_EAX;
  MMRESULT MVar1;
  MMRESULT MVar2;
  MMRESULT MVar3;
  MMRESULT MVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  UINT unaff_EBX;
  undefined4 local_14;
  
  MVar1 = FUN_004177c0(in_EAX,DAT_0043d5f4,0,0x10000);
  if (MVar1 == 0) {
    FUN_004176a3(extraout_ECX,extraout_EDX);
  }
  MVar2 = FUN_004177c0(in_EAX,DAT_0043d5f4,0,0x10000);
  if (MVar2 == 0) {
    FUN_004176a3(extraout_ECX_00,extraout_EDX_00);
  }
  MVar3 = FUN_004175c0(in_EAX,DAT_0043d5f0,0,0x10000);
  if (MVar3 == 0) {
    FUN_00417664(extraout_ECX_01,extraout_EDX_01);
  }
  MVar4 = FUN_004175c0(in_EAX,DAT_0043d5f0,0,0x10000);
  uVar5 = extraout_ECX_02;
  if (MVar4 == 0) {
    FUN_00417664(extraout_ECX_02,extraout_EDX_02);
    uVar5 = extraout_ECX_03;
  }
  if ((MVar1 == 4) || (MVar2 == 4)) {
    waveOutGetErrorTextA(4,param_2,unaff_EBX);
    local_14 = 1;
  }
  else if ((MVar3 == 4) || (MVar4 == 4)) {
    waveInGetErrorTextA(4,param_2,unaff_EBX);
    local_14 = 1;
  }
  else if ((MVar3 == 0) && (MVar1 == 0)) {
    local_14 = 0;
  }
  else if ((MVar4 == 0) && (MVar2 == 0)) {
    local_14 = 0;
  }
  else {
    FUN_0042cfa3(uVar5,s_Sound_card_doesn_t_support_requi_00436a93);
    local_14 = 1;
  }
  return local_14;
}


