// 0040c780 FUN_0040c780 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0040c780(void *this,uint param_1)

{
  int iVar1;
  int iVar2;
  HWND pHVar3;
  HMODULE hmod;
  DWORD dwThreadId;
  int local_2c;
  int local_28;
  tagRECT local_24;
  undefined4 local_14;
  undefined4 local_10;
  
  if ((param_1 & 1) == 0) {
    if ((param_1 & _DAT_0046e8a0) == 0) {
      GetWindowRect(*(HWND *)this,&local_24);
      SetCursorPos(DAT_004892b0,DAT_004892b4);
      *(int *)((int)this + 0x28) = DAT_004892b0;
      *(int *)((int)this + 0x2c) = DAT_004892b4;
      ShowCursor(1);
      DAT_00489278 = 0;
    }
    else {
      DAT_004892ac = 0;
    }
    if ((DAT_00489278 == 0) && (DAT_004892ac == 0)) {
      ReleaseCapture();
      UnhookWindowsHookEx(DAT_0049ff44);
      DAT_0049ff44 = (HHOOK)0x0;
    }
  }
  else {
    pHVar3 = GetCapture();
    if (pHVar3 != *(HWND *)this) {
      SetFocus(*(HWND *)this);
      if (DAT_0049ff44 == (HHOOK)0x0) {
        dwThreadId = 0;
        hmod = GetModuleHandleA((LPCSTR)0x0);
        DAT_0049ff44 = SetWindowsHookExA(0,(HOOKPROC)&LAB_0040c750,hmod,dwThreadId);
      }
      SetCapture(*(HWND *)this);
    }
    if ((param_1 & _DAT_0046e8a0) == 0) {
      DAT_00489278 = 1;
      ShowCursor(0);
      GetCursorPos((LPPOINT)&DAT_004892b0);
      iVar2 = DAT_004892b4;
      iVar1 = DAT_004892b0;
      local_28 = DAT_004892b4;
      local_2c = DAT_004892b0;
      SetCursorPos(DAT_004892b0,DAT_004892b4);
      if ((((iVar1 < 0xa0) || (0x1e0 < iVar1)) || (iVar2 < 0x78)) || (0x168 < iVar2)) {
        local_28 = 0xf0;
        local_2c = 0x140;
        local_10 = 0xf0;
        local_14 = 0x140;
        SetCursorPos(0x140,0xf0);
      }
      *(int *)((int)this + 0x28) = local_2c;
      *(int *)((int)this + 0x2c) = local_28;
    }
    else {
      DAT_004892ac = 1;
    }
  }
  return 0;
}


