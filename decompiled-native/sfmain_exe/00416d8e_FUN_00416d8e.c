// 00416d8e FUN_00416d8e [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_00416d8e(undefined4 param_1,undefined4 param_2)

{
  HWND in_EAX;
  INT_PTR IVar1;
  
  IVar1 = DialogBoxParamA(DAT_004627bc,(LPCSTR)0xc21,in_EAX,FUN_00416adb,0);
  return CONCAT44(param_2,IVar1);
}


