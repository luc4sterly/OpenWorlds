// 004176a3 FUN_004176a3 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_004176a3(undefined4 param_1,undefined4 param_2)

{
  HWAVEOUT in_EAX;
  MMRESULT MVar1;
  
  FUN_004296b9(s_waveOutClose___00436149);
  MVar1 = waveOutClose(in_EAX);
  return CONCAT44(param_2,MVar1);
}


