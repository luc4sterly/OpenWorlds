// 0044bad0 FUN_0044bad0 [Global]
// programa: gamma.dll

DWORD FUN_0044bad0(HANDLE param_1,uint param_2,HWND param_3,UINT param_4,int param_5)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  UINT UVar6;
  uint nCount;
  WPARAM wParam;
  LPARAM lParam;
  DWORD local_64;
  DWORD local_5c;
  uint local_58;
  HANDLE local_50;
  int local_4c;
  tagMSG local_48;
  tagMSG local_2c;
  
  bVar1 = false;
  if (DAT_0049df8c == '\0') {
    DAT_0049df8c = '\x01';
    DAT_0049df88 = 0;
  }
  local_50 = param_1;
  local_4c = param_5;
  if ((param_2 != 0xffffffff) && (param_2 != 0)) {
    local_5c = GetTickCount();
  }
  while( true ) {
    if (param_5 == 0) {
      nCount = 1;
    }
    else {
      nCount = 2;
    }
    DVar2 = WaitForMultipleObjects(nCount,&local_50,0,0);
    if (DVar2 < nCount) {
      return DVar2;
    }
    local_64 = param_2;
    if (10 < param_2) {
      local_64 = 10;
    }
    if (param_3 == (HWND)0x0) {
      DVar2 = 0x40;
    }
    else {
      DVar2 = 0x48;
    }
    DVar2 = MsgWaitForMultipleObjects(nCount,&local_50,0,local_64,DVar2);
    if ((DVar2 != nCount) && ((DVar2 != 0x102 || (local_64 == param_2)))) break;
    if (param_3 != (HWND)0x0) {
      iVar3 = PeekMessageA(&local_48,param_3,param_4,param_4,1);
      while (iVar3 != 0) {
        DispatchMessageA(&local_48);
        iVar3 = PeekMessageA(&local_48,param_3,param_4,param_4,1);
      }
    }
    PeekMessageA(&local_48,(HWND)0x0,0,0,0);
    if ((param_2 != 0xffffffff) && (param_2 != 0)) {
      DVar2 = GetTickCount();
      if (param_2 < DVar2 - local_5c) {
        param_2 = 0;
        local_5c = DVar2;
      }
      else {
        param_2 = param_2 - (DVar2 - local_5c);
        local_5c = DVar2;
      }
    }
    if (!bVar1) {
      pvVar4 = GetCurrentThread();
      local_58 = GetThreadPriority(pvVar4);
      if (local_58 < 2) {
        iVar3 = 2;
        pvVar4 = GetCurrentThread();
        SetThreadPriority(pvVar4,iVar3);
      }
      bVar1 = true;
    }
  }
  if (bVar1) {
    pvVar4 = GetCurrentThread();
    SetThreadPriority(pvVar4,local_58);
    DVar5 = GetQueueStatus(8);
    if ((DVar5 >> 0x10 & 8) != 0) {
      UVar6 = DAT_0049df88;
      if (DAT_0049df88 == 0) {
        DAT_0049df88 = RegisterWindowMessageA(s_AMUnblock_004805b8);
        UVar6 = DAT_0049df88;
      }
      while (UVar6 != 0) {
        UVar6 = PeekMessageA(&local_2c,(HWND)0xffffffff,DAT_0049df88,DAT_0049df88,1);
      }
      lParam = 0;
      wParam = 0;
      UVar6 = DAT_0049df88;
      DVar5 = GetCurrentThreadId();
      PostThreadMessageA(DVar5,UVar6,wParam,lParam);
    }
  }
  return DVar2;
}


