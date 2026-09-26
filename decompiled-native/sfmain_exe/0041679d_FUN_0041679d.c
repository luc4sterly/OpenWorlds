// 0041679d FUN_0041679d [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0041679d(undefined4 param_1,undefined4 param_2)

{
  HWND in_EAX;
  bool bVar1;
  uint local_1c;
  
  bVar1 = DAT_0043d3ec == (HWND)0x0;
  if (bVar1) {
    DAT_0043d3ec = CreateDialogParamA(DAT_004627bc,(LPCSTR)0x72,in_EAX,FUN_0041652c,0);
  }
  local_1c = (uint)bVar1;
  return CONCAT44(param_2,local_1c);
}


