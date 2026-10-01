// 004176dc FUN_004176dc [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_004176dc(undefined4 param_1,undefined4 param_2)

{
  HWAVEOUT in_EAX;
  MMRESULT MVar1;
  
  FUN_004296b9(s_waveOutReset___00436159);
  MVar1 = waveOutReset(in_EAX);
  return CONCAT44(param_2,MVar1);
}


