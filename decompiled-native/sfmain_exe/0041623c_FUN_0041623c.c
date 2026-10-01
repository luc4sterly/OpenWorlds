// 0041623c FUN_0041623c [Global]
// program: sfmain.exe

void __fastcall FUN_0041623c(undefined4 param_1,int param_2)

{
  int iVar1;
  HWND in_EAX;
  HBRUSH pHVar2;
  float10 fVar3;
  tagRECT local_54;
  double local_44;
  double local_3c;
  HDC local_34;
  int local_30;
  HWND local_2c;
  int local_28;
  int local_24;
  int local_20;
  HBRUSH local_1c;
  HBRUSH local_18;
  
  iVar1 = DAT_0043d400;
  DAT_0043d400 = DAT_0043d400 + 1;
  if (iVar1 < 1) {
    local_30 = param_2;
    local_2c = in_EAX;
    if (param_2 != 0) {
      InvalidateRect(in_EAX,(RECT *)0x0,1);
      UpdateWindow(local_2c);
    }
    local_34 = GetDC(local_2c);
    GetClientRect(local_2c,&local_54);
    fVar3 = (float10)FUN_0042bd59();
    local_3c = (double)fVar3;
    if (DAT_0043d3f0 < 1) {
      local_44 = 0.0;
    }
    else {
      fVar3 = (float10)FUN_0042bd59();
      local_44 = (double)fVar3;
    }
    local_28 = local_54.bottom - local_54.top;
    fVar3 = FUN_0042b8ce();
    local_24 = local_28 - (int)ROUND(fVar3);
    local_1c = CreateSolidBrush(0xff00);
    if (local_30 == 0) {
      if (DAT_0043d3f8 < local_24) {
        local_54.bottom = local_24;
        local_54.top = DAT_0043d3f8;
        pHVar2 = GetStockObject(0);
        FillRect(local_34,&local_54,pHVar2);
      }
      else {
        local_54.bottom = DAT_0043d3f8;
        local_54.top = local_24;
        FillRect(local_34,&local_54,local_1c);
      }
    }
    else {
      pHVar2 = GetStockObject(0);
      FillRect(local_34,&local_54,pHVar2);
      local_54.top = local_24;
      FillRect(local_34,&local_54,local_1c);
    }
    DAT_0043d3f8 = local_24;
    local_18 = CreateSolidBrush(0xff);
    fVar3 = FUN_0042b8ce();
    local_20 = (int)ROUND(fVar3) + 1;
    if ((local_30 == 0) && (DAT_0043d3fc != local_20)) {
      local_54.top = DAT_0043d3fc;
      local_54.bottom = DAT_0043d3fc + -1;
      if (local_24 < DAT_0043d3fc) {
        FillRect(local_34,&local_54,local_1c);
      }
      else {
        pHVar2 = GetStockObject(0);
        FillRect(local_34,&local_54,pHVar2);
      }
    }
    local_54.top = local_20;
    local_54.bottom = local_20 + -1;
    FillRect(local_34,&local_54,local_18);
    DAT_0043d3fc = local_20;
    DeleteObject(local_18);
    DeleteObject(local_1c);
    ReleaseDC(local_2c,local_34);
    DAT_0043d400 = DAT_0043d400 + -1;
    iVar1 = DAT_0043d400;
  }
  DAT_0043d400 = iVar1;
  return;
}


