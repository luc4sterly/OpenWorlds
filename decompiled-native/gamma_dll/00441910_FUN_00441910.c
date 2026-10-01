// 00441910 FUN_00441910 [Global]
// program: gamma.dll

undefined4 FUN_00441910(int param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  int *this;
  int *piVar1;
  DWORD DVar2;
  UINT Msg;
  WPARAM wParam;
  LPARAM lParam;
  tagMSG tStack_28;
  
  this = (int *)(param_1 + -0xc);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x68);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 8) == 0) {
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  if (*(int *)(*(int *)(param_1 + 100) + 0x18) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    LeaveCriticalSection(lpCriticalSection);
    return 0;
  }
  FUN_004439e0(this);
  piVar1 = *(int **)(*(int *)(param_1 + 100) + 0x98);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x18))(piVar1);
  }
  FUN_00449b50(this,1);
  (**(code **)(*this + 0x124))();
  (**(code **)(*this + 0xcc))(0);
  (**(code **)(*this + 0x108))();
  (**(code **)(*this + 0x110))();
  SetEvent(*(HANDLE *)(param_1 + 0x48));
  while (*(int *)(param_1 + 0xa0) != 0) {
    PeekMessageA(&tStack_28,(HWND)0x0,0,0,0);
    Sleep(1);
  }
  DVar2 = GetQueueStatus(8);
  if ((DVar2 >> 0x10 & 8) != 0) {
    lParam = 0;
    wParam = 0;
    Msg = 0;
    DVar2 = GetCurrentThreadId();
    PostThreadMessageA(DVar2,Msg,wParam,lParam);
  }
  *(undefined4 *)(param_1 + 0x4c) = 0;
  LeaveCriticalSection(lpCriticalSection);
  return 0;
}


