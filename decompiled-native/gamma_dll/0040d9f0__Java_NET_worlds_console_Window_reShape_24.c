// 0040d9f0 _Java_NET_worlds_console_Window_reShape@24 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_Window_reShape_24
               (int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  HWND hWnd;
  BOOL BVar2;
  tagPOINT *lpPoint;
  tagPOINT local_10;
  
                    /* 0xd9f0  110  _Java_NET_worlds_console_Window_reShape@24 */
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 400))(param_1,param_2,DAT_004891ac);
  if (DAT_004891cc != 0) {
    local_10.y = param_4;
    local_10.x = param_3;
    lpPoint = &local_10;
    hWnd = GetParent((HWND)*puVar1);
    BVar2 = ScreenToClient(hWnd,lpPoint);
    if (BVar2 != 0) {
      SetWindowPos((HWND)*puVar1,(HWND)0x0,local_10.x,local_10.y,param_5,param_6,4);
    }
  }
  return;
}


