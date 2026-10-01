// 10004bc0 FUN_10004bc0 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_10004bc0(int param_1)

{
  ATOM AVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  WNDCLASSA WStack_28;
  
  if ((param_1 < 0) || (DAT_10079160 <= param_1)) {
    return 0;
  }
  if (DAT_10079174 != (int *)0x0) {
    puVar3 = (undefined4 *)(param_1 * 0x14 + DAT_1007915c);
    if (DAT_1007917c != (int *)0x0) {
      (**(code **)(*DAT_1007917c + 8))(DAT_1007917c);
      DAT_1007917c = (int *)0x0;
    }
    if (DAT_10079178 != (int *)0x0) {
      if (DAT_10079180 == 0) {
        (**(code **)(*DAT_10079178 + 8))(DAT_10079178);
        DAT_10079178 = (int *)0x0;
      }
      else {
        (**(code **)(*DAT_10079178 + 8))();
        DAT_10079178 = (int *)0x0;
        DAT_10079180 = 0;
        (**(code **)(*DAT_10079174 + 0x50))(DAT_10079174,0,8);
        (**(code **)(*DAT_10079174 + 0x4c))(DAT_10079174);
      }
    }
    if ((puVar3[4] & 2) == 0) {
      bVar4 = false;
      if ((DAT_1007916c == 0) && (DAT_10079170 == (HWND)0x0)) {
        WStack_28.cbClsExtra = 0;
        WStack_28.cbWndExtra = 0;
        WStack_28.hInstance = DAT_10079168;
        WStack_28.hIcon = (HICON)0x0;
        WStack_28.hCursor = (HCURSOR)0x0;
        WStack_28.hbrBackground = (HBRUSH)0x0;
        WStack_28.lpszMenuName = (LPCSTR)0x0;
        WStack_28.style = 0x2000;
        WStack_28.lpfnWndProc = (WNDPROC)&LAB_10004e90;
        WStack_28.lpszClassName = s_RWDRVCLASS_100791a0;
        AVar1 = RegisterClassA(&WStack_28);
        if (AVar1 != 0) {
          DAT_10079170 = CreateWindowExA(0,s_RWDRVCLASS_100791a0,s_RWDRVWND_10079194,0xcf0000,0,0,
                                         100,100,(HWND)0x0,(HMENU)0x0,DAT_10079168,(LPVOID)0x0);
          bVar4 = DAT_10079170 != (HWND)0x0;
        }
        if (!bVar4) {
          return 0;
        }
      }
      iVar2 = (**(code **)(*DAT_10079174 + 0x54))(DAT_10079174,*puVar3,puVar3[1],puVar3[2]);
      if (iVar2 != 0) {
        if (DAT_10079170 != (HWND)0x0) {
          DestroyWindow(DAT_10079170);
          DAT_10079170 = (HWND)0x0;
        }
        UnregisterClassA(s_RWDRVCLASS_100791a0,DAT_10079168);
        return 0;
      }
      if (DAT_1007916c == 0) {
        iVar2 = (**(code **)(*DAT_10079174 + 0x50))(DAT_10079174,DAT_10079170,0x11);
        if (iVar2 != 0) {
          if (DAT_10079170 != (HWND)0x0) {
            DestroyWindow(DAT_10079170);
            DAT_10079170 = (HWND)0x0;
          }
          UnregisterClassA(s_RWDRVCLASS_100791a0,DAT_10079168);
          return 0;
        }
      }
      else {
        iVar2 = (**(code **)(*DAT_10079174 + 0x50))(DAT_10079174,DAT_1007916c);
        if (iVar2 != 0) {
          return 0;
        }
      }
      iVar2 = FUN_10004ef0(0x11);
      if (iVar2 == 0) {
        if (DAT_10079170 != (HWND)0x0) {
          DestroyWindow(DAT_10079170);
          DAT_10079170 = (HWND)0x0;
        }
        UnregisterClassA(s_RWDRVCLASS_100791a0,DAT_10079168);
        return 0;
      }
    }
    else {
      iVar2 = (**(code **)(*DAT_10079174 + 0x50))(DAT_10079174,0,8);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_10004ef0(8);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  DAT_10079164 = param_1;
  return 1;
}


