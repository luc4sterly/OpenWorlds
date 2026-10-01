// 00417715 FUN_00417715 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_00417715(undefined4 param_1,undefined4 param_2)

{
  HWAVEIN in_EAX;
  MMRESULT MVar1;
  
  FUN_004296b9(s_waveInReset___00436169);
  MVar1 = waveInReset(in_EAX);
  return CONCAT44(param_2,MVar1);
}


