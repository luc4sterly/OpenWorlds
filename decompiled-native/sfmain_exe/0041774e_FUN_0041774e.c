// 0041774e FUN_0041774e [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0041774e(undefined4 param_1,undefined4 param_2)

{
  HWAVEOUT in_EAX;
  MMRESULT MVar1;
  
  FUN_004296b9(s_waveOutPause___00436178);
  MVar1 = waveOutPause(in_EAX);
  return CONCAT44(param_2,MVar1);
}


