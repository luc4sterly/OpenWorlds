// 0041757d FUN_0041757d [Global]
// program: sfmain.exe

MMRESULT __fastcall FUN_0041757d(undefined4 param_1,LPWAVEHDR param_2)

{
  HWAVEIN in_EAX;
  MMRESULT MVar1;
  UINT unaff_EBX;
  
  FUN_004296b9(s_waveInUnprepareHeader___004360f7);
  MVar1 = waveInUnprepareHeader(in_EAX,param_2,unaff_EBX);
  return MVar1;
}


