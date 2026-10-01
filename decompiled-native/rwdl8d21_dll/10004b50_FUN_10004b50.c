// 10004b50 FUN_10004b50 [Global]
// program: RWDL8D21.DLL

undefined4 FUN_10004b50(int param_1)

{
  ATOM AVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  WNDCLASSA WStack_28;
  
  if ((param_1 < 0) || (DAT_10075160 <= param_1)) {
    return 0;
  }
  if (DAT_10075174 != (int *)0x0) {
    puVar3 = (undefined4 *)(param_1 * 0x14 + DAT_1007515c);
    if (DAT_1007517c != (int *)0x0) {
      (**(code **)(*DAT_1007517c + 8))(DAT_1007517c);
      DAT_1007517c = (int *)0x0;
    }
    if (DAT_10075178 != (int *)0x0) {
      if (DAT_10075180 == 0) {
        (**(code **)(*DAT_10075178 + 8))(DAT_10075178);
        DAT_10075178 = (int *)0x0;
      }
      else {
        (**(code **)(*DAT_10075178 + 8))();
        DAT_10075178 = (int *)0x0;
        DAT_10075180 = 0;
        (**(code **)(*DAT_10075174 + 0x50))(DAT_10075174,0,8);
        (**(code **)(*DAT_10075174 + 0x4c))(DAT_10075174);
      }
    }
    if ((puVar3[4] & 2) == 0) {
      bVar4 = false;
      if ((DAT_1007516c == 0) && (DAT_10075170 == (HWND)0x0)) {
        WStack_28.cbClsExtra = 0;
        WStack_28.cbWndExtra = 0;
        WStack_28.hInstance = DAT_10075168;
        WStack_28.hIcon = (HICON)0x0;
        WStack_28.hCursor = (HCURSOR)0x0;
        WStack_28.hbrBackground = (HBRUSH)0x0;
        WStack_28.lpszMenuName = (LPCSTR)0x0;
        WStack_28.style = 0x2000;
        WStack_28.lpfnWndProc = (WNDPROC)&LAB_10004e20;
        WStack_28.lpszClassName = s_RWDRVCLASS_100751a0;
        AVar1 = RegisterClassA(&WStack_28);
        if (AVar1 != 0) {
          DAT_10075170 = CreateWindowExA(0,s_RWDRVCLASS_100751a0,s_RWDRVWND_10075194,0xcf0000,0,0,
                                         100,100,(HWND)0x0,(HMENU)0x0,DAT_10075168,(LPVOID)0x0);
          bVar4 = DAT_10075170 != (HWND)0x0;
        }
        if (!bVar4) {
          return 0;
        }
      }
      iVar2 = (**(code **)(*DAT_10075174 + 0x54))(DAT_10075174,*puVar3,puVar3[1],puVar3[2]);
      if (iVar2 != 0) {
        if (DAT_10075170 != (HWND)0x0) {
          DestroyWindow(DAT_10075170);
          DAT_10075170 = (HWND)0x0;
        }
        UnregisterClassA(s_RWDRVCLASS_100751a0,DAT_10075168);
        return 0;
      }
      if (DAT_1007516c == 0) {
        iVar2 = (**(code **)(*DAT_10075174 + 0x50))(DAT_10075174,DAT_10075170,0x11);
        if (iVar2 != 0) {
          if (DAT_10075170 != (HWND)0x0) {
            DestroyWindow(DAT_10075170);
            DAT_10075170 = (HWND)0x0;
          }
          UnregisterClassA(s_RWDRVCLASS_100751a0,DAT_10075168);
          return 0;
        }
      }
      else {
        iVar2 = (**(code **)(*DAT_10075174 + 0x50))(DAT_10075174,DAT_1007516c);
        if (iVar2 != 0) {
          return 0;
        }
      }
      iVar2 = FUN_10004e80(0x11);
      if (iVar2 == 0) {
        if (DAT_10075170 != (HWND)0x0) {
          DestroyWindow(DAT_10075170);
          DAT_10075170 = (HWND)0x0;
        }
        UnregisterClassA(s_RWDRVCLASS_100751a0,DAT_10075168);
        return 0;
      }
    }
    else {
      iVar2 = (**(code **)(*DAT_10075174 + 0x50))(DAT_10075174,0,8);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = FUN_10004e80(8);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  DAT_10075164 = param_1;
  return 1;
}


