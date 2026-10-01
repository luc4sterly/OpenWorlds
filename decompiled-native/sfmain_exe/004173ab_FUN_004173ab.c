// 004173ab FUN_004173ab [Global]
// program: sfmain.exe

void __fastcall FUN_004173ab(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  
  if (DAT_0043d634 != (HWND)0x0) {
    wsprintfA(&DAT_004627d6,&DAT_004360dc,param_2);
    SetDlgItemTextA(DAT_0043d634,in_EAX,&DAT_004627d6);
  }
  return;
}


