// 00421e6f FUN_00421e6f [Global]
// program: sfmain.exe

LRESULT FUN_00421e6f(HWND param_1,UINT param_2,WPARAM param_3,uint param_4)

{
  uint uVar1;
  HWND hWnd;
  UINT Msg;
  HWND lParam;
  undefined4 local_14;
  
  if (param_2 == 0x87) {
    local_14 = 4;
  }
  else if (((param_2 == 0x100) && (param_3 == 9)) || ((param_2 == 0x100 && (param_3 == 0xd)))) {
    if ((param_4 & 0x80000000) == 0) {
      lParam = param_1;
      uVar1 = GetWindowLongA(param_1,-0xc);
      uVar1 = uVar1 & 0xffff | 0x7ea0000;
      Msg = 0x111;
      hWnd = GetParent(param_1);
      SendMessageA(hWnd,Msg,uVar1,(LPARAM)lParam);
    }
    local_14 = 0;
  }
  else {
    local_14 = CallWindowProcA(DAT_0043d7d8,param_1,param_2,param_3,param_4);
  }
  return local_14;
}


