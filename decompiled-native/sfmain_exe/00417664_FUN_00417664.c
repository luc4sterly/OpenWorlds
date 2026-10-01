// 00417664 FUN_00417664 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_00417664(undefined4 param_1,undefined4 param_2)

{
  HWAVEIN in_EAX;
  MMRESULT MVar1;
  
  FUN_004296b9(s_waveInClose____waveHeadersAlloca_0043611e);
  MVar1 = waveInClose(in_EAX);
  return CONCAT44(param_2,MVar1);
}


