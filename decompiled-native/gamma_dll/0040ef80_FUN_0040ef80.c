// 0040ef80 FUN_0040ef80 [Global]
// program: gamma.dll

void __cdecl FUN_0040ef80(int param_1,int param_2)

{
  bool bVar1;
  HDC pHVar2;
  DWORD DVar3;
  DWORD DVar4;
  
  if (DAT_0048923c != (DEVMODEA *)0x0) {
    if (param_1 == 0) {
      ShowWindow(DAT_004891c0,7);
      if (DAT_00489240 != 0) {
        ChangeDisplaySettingsA((DEVMODEA *)0x0,0);
        DAT_00489240 = 0;
      }
    }
    else {
      pHVar2 = GetDC((HWND)0x0);
      DVar3 = GetDeviceCaps(pHVar2,8);
      DVar4 = GetDeviceCaps(pHVar2,10);
      ReleaseDC((HWND)0x0,pHVar2);
      bVar1 = true;
      if ((DVar3 == DAT_0048923c->dmPelsWidth) && (DVar4 == DAT_0048923c->dmPelsHeight)) {
        bVar1 = false;
      }
      if (bVar1) {
        ChangeDisplaySettingsA(DAT_0048923c,0);
        pHVar2 = GetDC((HWND)0x0);
        DVar3 = GetDeviceCaps(pHVar2,8);
        DVar4 = GetDeviceCaps(pHVar2,10);
        ReleaseDC((HWND)0x0,pHVar2);
        bVar1 = true;
        if ((DVar3 == DAT_0048923c->dmPelsWidth) && (DVar4 == DAT_0048923c->dmPelsHeight)) {
          bVar1 = false;
        }
        if (bVar1) {
          FUN_0044e100((undefined4 *)DAT_0048923c);
          DAT_0048923c = (DEVMODEA *)0x0;
          return;
        }
        DAT_00489240 = 1;
      }
      if (param_2 == 0) {
        ShowWindow(DAT_004891c0,3);
      }
    }
  }
  return;
}


