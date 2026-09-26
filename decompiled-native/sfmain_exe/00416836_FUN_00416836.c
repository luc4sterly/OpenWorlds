// 00416836 FUN_00416836 [Global]
// programa: sfmain.exe

void FUN_00416836(void)

{
  undefined4 in_EAX;
  undefined4 extraout_ECX;
  
  if (DAT_0043d3ec != (HWND)0x0) {
    DAT_0043d3f0 = in_EAX;
    GetDlgItem(DAT_0043d3ec,0x41b);
    FUN_0041623c(extraout_ECX,0);
    FUN_00416495();
  }
  return;
}


