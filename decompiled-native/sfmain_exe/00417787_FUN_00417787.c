// 00417787 FUN_00417787 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_00417787(undefined4 param_1,undefined4 param_2)

{
  HWAVEOUT in_EAX;
  MMRESULT MVar1;
  
  FUN_004296b9(s_waveOutRestart___00436188);
  MVar1 = waveOutRestart(in_EAX);
  return CONCAT44(param_2,MVar1);
}


