// 0041753a FUN_0041753a [Global]
// programa: sfmain.exe

MMRESULT __fastcall FUN_0041753a(undefined4 param_1,LPWAVEHDR param_2)

{
  HWAVEIN in_EAX;
  MMRESULT MVar1;
  UINT unaff_EBX;
  
  FUN_004296b9(s_waveInPrepareHeader___004360e0);
  MVar1 = waveInPrepareHeader(in_EAX,param_2,unaff_EBX);
  return MVar1;
}


