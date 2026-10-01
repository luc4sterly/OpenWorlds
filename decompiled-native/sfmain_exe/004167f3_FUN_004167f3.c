// 004167f3 FUN_004167f3 [Global]
// program: sfmain.exe

undefined8 __fastcall FUN_004167f3(undefined4 param_1,undefined4 param_2)

{
  LPMSG in_EAX;
  undefined4 local_1c;
  
  if (DAT_0043d3ec == (HWND)0x0) {
    local_1c = 0;
  }
  else {
    local_1c = IsDialogMessageA(DAT_0043d3ec,in_EAX);
  }
  return CONCAT44(param_2,local_1c);
}


