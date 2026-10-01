// 00449020 FUN_00449020 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00449020(int *param_1)

{
  DWORD DVar1;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  tagMSG tStack_28;
  
  if (param_1[5] == 1) {
    ResetEvent((HANDLE)param_1[0x15]);
  }
  (**(code **)(*param_1 + 0xcc))(0);
  (**(code **)(*param_1 + 0x110))();
  (**(code **)(*param_1 + 0x114))();
  while (param_1[0x2b] != 0) {
    PeekMessageA(&tStack_28,(HWND)0x0,0,0,0);
    Sleep(1);
  }
  DVar1 = GetQueueStatus(8);
  if ((DVar1 >> 0x10 & 8) != 0) {
    lParam = 0;
    wParam = 0;
    Msg = 0;
    DVar1 = GetCurrentThreadId();
    PostThreadMessageA(DVar1,Msg,wParam,lParam);
  }
  return 0;
}


