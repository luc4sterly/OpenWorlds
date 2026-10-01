// 0043fca0 FUN_0043fca0 [Global]
// program: gamma.dll

void __cdecl FUN_0043fca0(HWND param_1,uint param_2,int param_3)

{
  POINT pt;
  HWND hWnd;
  uint lParam;
  tagPOINT local_1c;
  tagPOINT local_14;
  
  pt.y = param_3;
  pt.x = param_2;
  hWnd = ChildWindowFromPointEx(param_1,pt,0);
  if (hWnd == (HWND)0x0) {
    return;
  }
  if (hWnd == param_1) {
    PostMessageA(param_1,7,0,0);
    lParam = param_3 << 0x10 | param_2 & 0xffff;
    PostMessageA(param_1,0x201,0,lParam);
    PostMessageA(param_1,0x202,0,lParam);
    return;
  }
  local_1c.y = 0;
  local_1c.x = 0;
  ClientToScreen(param_1,&local_1c);
  local_14.y = 0;
  local_14.x = 0;
  ClientToScreen(hWnd,&local_14);
  FUN_0043fca0(hWnd,param_2 - (local_14.x - local_1c.x),param_3 - (local_14.y - local_1c.y));
  return;
}


