// 0043ef30 _Java_NET_worlds_console_RenderCanvasOverlay_nativeMakeChild@28 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

HWND _Java_NET_worlds_console_RenderCanvasOverlay_nativeMakeChild_28
               (int *param_1,undefined4 param_2,HWND param_3,undefined4 param_4,int param_5,
               int param_6,byte param_7)

{
  HMENU hMenu;
  int nWidth;
  int nHeight;
  HINSTANCE hInstance;
  HWND hWnd;
  undefined4 uVar1;
  uint uVar2;
  uint *dwNewLong;
  uint uVar3;
  LPVOID lpParam;
  tagRECT local_30;
  tagRECT local_20;
  
                    /* 0x3ef30  56  _Java_NET_worlds_console_RenderCanvasOverlay_nativeMakeChild@28
                        */
  FUN_0043ee90();
  GetWindowRect(param_3,&local_30);
  local_20.top = 0;
  local_20.right = (LONG)ROUND((double)((local_30.right - local_30.left) * param_5) * _DAT_00477c68)
  ;
  local_20.left = 0;
  local_20.bottom =
       (LONG)ROUND((double)((local_30.bottom - local_30.top) * param_6) * _DAT_00477c68);
  AdjustWindowRect(&local_20,0x40000000,0);
  nWidth = local_20.right - local_20.left;
  nHeight = local_20.bottom - local_20.top;
  lpParam = (LPVOID)0x0;
  hInstance = (HINSTANCE)FUN_0040c110();
  hMenu = DAT_00477c3c;
  DAT_00477c3c = (HMENU)((int)&DAT_00477c3c->unused + 1);
  hWnd = CreateWindowExA(4,s_RenderCanvasOverlay_00477c28,&DAT_00477c70,0x50000000,
                         (local_30.right - local_30.left) - nWidth,
                         (local_30.bottom - local_30.top) - nHeight,nWidth,nHeight,param_3,hMenu,
                         hInstance,lpParam);
  uVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  uVar2 = (**(code **)(*param_1 + 0x84))(param_1,uVar1,s_handleCommand_00477c48,&DAT_00477c40);
  if (uVar2 == 0) {
    FUN_00402800(s_nRenderCanvas_00477c58,0x79);
  }
  dwNewLong = FUN_0044e010(0x10);
  *dwNewLong = (uint)param_7;
  dwNewLong[1] = (uint)param_1;
  uVar3 = (**(code **)(*param_1 + 0x54))(param_1,param_2);
  dwNewLong[2] = uVar3;
  dwNewLong[3] = uVar2;
  SetWindowLongA(hWnd,-0x15,(LONG)dwNewLong);
  ShowWindow(hWnd,1);
  UpdateWindow(hWnd);
  SetFocus(param_3);
  return hWnd;
}


