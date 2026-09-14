// 0043f0d0 _Java_NET_worlds_console_RenderCanvasOverlay_nativeResizeChild@20 [Global]
// programa: gamma.dll

void _Java_NET_worlds_console_RenderCanvasOverlay_nativeResizeChild_20
               (undefined4 param_1,undefined4 param_2,HWND param_3,int param_4,int param_5)

{
  HWND hWnd;
  int iVar1;
  int iVar2;
  tagRECT local_20;
  
                    /* 0x3f0d0  57
                       _Java_NET_worlds_console_RenderCanvasOverlay_nativeResizeChild@20 */
  local_20.top = 0;
  local_20.left = 0;
  local_20.right = param_4;
  local_20.bottom = param_5;
  AdjustWindowRect(&local_20,0x40000000,0);
  iVar2 = local_20.bottom - local_20.top;
  iVar1 = local_20.right - local_20.left;
  hWnd = GetParent(param_3);
  if (hWnd == (HWND)0x0) {
    return;
  }
  GetClientRect(hWnd,&local_20);
  SetWindowPos(param_3,(HWND)0x0,(local_20.right - local_20.left) - iVar1,
               (local_20.bottom - local_20.top) - iVar2,param_4,param_5,4);
  return;
}


