// 100057e0 FUN_100057e0 [Global]
// program: rwdlmd21.dll

undefined4 FUN_100057e0(int param_1)

{
  ATOM AVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  WNDCLASSA WStack_28;
  
  DAT_10087174 = param_1;
  puVar3 = (undefined4 *)(DAT_1008716c * 0x14 + DAT_10087164);
  bVar4 = false;
  if (DAT_10087198 != (code *)0x0) {
    iVar2 = (*DAT_10087198)(0,&DAT_1008717c,0);
    bVar4 = iVar2 == 0;
  }
  if (!bVar4) {
    return 0;
  }
  if ((puVar3[4] & 2) == 0) {
    bVar4 = false;
    if ((DAT_10087174 == 0) && (DAT_10087178 == (HWND)0x0)) {
      WStack_28.cbClsExtra = 0;
      WStack_28.cbWndExtra = 0;
      WStack_28.hInstance = DAT_10087170;
      WStack_28.hIcon = (HICON)0x0;
      WStack_28.hCursor = (HCURSOR)0x0;
      WStack_28.hbrBackground = (HBRUSH)0x0;
      WStack_28.lpszMenuName = (LPCSTR)0x0;
      WStack_28.style = 0x2000;
      WStack_28.lpfnWndProc = (WNDPROC)&LAB_100054d0;
      WStack_28.lpszClassName = s_RWDRVCLASS_100871a8;
      AVar1 = RegisterClassA(&WStack_28);
      if (AVar1 != 0) {
        DAT_10087178 = CreateWindowExA(0,s_RWDRVCLASS_100871a8,s_RWDRVWND_1008719c,0xcf0000,0,0,100,
                                       100,(HWND)0x0,(HMENU)0x0,DAT_10087170,(LPVOID)0x0);
        bVar4 = DAT_10087178 != (HWND)0x0;
      }
      if (!bVar4) {
        if (DAT_1008717c != (int *)0x0) {
          (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
          DAT_1008717c = (int *)0x0;
        }
        return 0;
      }
    }
    if (DAT_10087174 == 0) {
      iVar2 = (**(code **)(*DAT_1008717c + 0x50))(DAT_1008717c,DAT_10087178,0x11);
      if (iVar2 != 0) {
        if (DAT_10087178 != (HWND)0x0) {
          DestroyWindow(DAT_10087178);
          DAT_10087178 = (HWND)0x0;
        }
        UnregisterClassA(s_RWDRVCLASS_100871a8,DAT_10087170);
        if (DAT_1008717c != (int *)0x0) {
          (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
          DAT_1008717c = (int *)0x0;
        }
        return 0;
      }
    }
    else {
      iVar2 = (**(code **)(*DAT_1008717c + 0x50))(DAT_1008717c,DAT_10087174);
      if (iVar2 != 0) {
        if (DAT_1008717c != (int *)0x0) {
          (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
          DAT_1008717c = (int *)0x0;
        }
        return 0;
      }
    }
    iVar2 = (**(code **)(*DAT_1008717c + 0x54))(DAT_1008717c,*puVar3,puVar3[1],puVar3[2]);
    if (iVar2 != 0) {
      (**(code **)(*DAT_1008717c + 0x50))(DAT_1008717c,0,8);
      if (DAT_10087178 != (HWND)0x0) {
        DestroyWindow(DAT_10087178);
        DAT_10087178 = (HWND)0x0;
      }
      UnregisterClassA(s_RWDRVCLASS_100871a8,DAT_10087170);
      if (DAT_1008717c != (int *)0x0) {
        (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
        DAT_1008717c = (int *)0x0;
      }
      return 0;
    }
    iVar2 = FUN_10005530(0x11);
    if (iVar2 == 0) {
      (**(code **)(*DAT_1008717c + 0x4c))(DAT_1008717c);
      (**(code **)(*DAT_1008717c + 0x50))(DAT_1008717c,0,8);
      if (DAT_10087178 != (HWND)0x0) {
        DestroyWindow(DAT_10087178);
        DAT_10087178 = (HWND)0x0;
      }
      UnregisterClassA(s_RWDRVCLASS_100871a8,DAT_10087170);
      if (DAT_1008717c != (int *)0x0) {
        (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
        DAT_1008717c = (int *)0x0;
      }
      return 0;
    }
  }
  else {
    iVar2 = (**(code **)(*DAT_1008717c + 0x50))(DAT_1008717c,0,8);
    if (iVar2 != 0) {
      if (DAT_1008717c != (int *)0x0) {
        (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
        DAT_1008717c = (int *)0x0;
      }
      return 0;
    }
    iVar2 = FUN_10005530(8);
    if (iVar2 == 0) {
      if (DAT_1008717c != (int *)0x0) {
        (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
        DAT_1008717c = (int *)0x0;
      }
      return 0;
    }
  }
  return 1;
}


