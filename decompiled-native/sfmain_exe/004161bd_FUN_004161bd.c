// 004161bd FUN_004161bd [Global]
// programa: sfmain.exe

INT_PTR __fastcall FUN_004161bd(undefined4 param_1,undefined4 param_2)

{
  HWND in_EAX;
  INT_PTR IVar1;
  undefined4 unaff_EBX;
  
  FUN_00408098(param_1,0);
  DAT_00459df8 = 0;
  DAT_00459dec = param_2;
  DAT_00459df0 = unaff_EBX;
  DAT_00459df4 = param_1;
  IVar1 = DialogBoxParamA(DAT_004627bc,(LPCSTR)0xc1c,in_EAX,FUN_004160b3,0);
  return IVar1;
}


