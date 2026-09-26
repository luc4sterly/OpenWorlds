// 0042189d FUN_0042189d [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0042189d(undefined4 param_1,undefined4 param_2)

{
  ATOM AVar1;
  HINSTANCE in_EAX;
  DWORD color;
  WNDCLASSA local_48;
  HINSTANCE local_20;
  undefined4 local_1c;
  
  DAT_004627c0 = s_Gamma_Phone_004371e4;
  _DAT_004b2bdc = s_GammaPhoneFrameClass_004371f0;
  _DAT_004b2be0 = s_MDICLIENT_00437205;
  _DAT_004b2be4 = s_GammaPhoneClientClass_0043720f;
  local_48.style = 3;
  local_48.lpfnWndProc = FUN_0041ca04;
  local_48.cbClsExtra = 0;
  local_48.cbWndExtra = 0;
  DAT_004627bc = in_EAX;
  local_20 = in_EAX;
  local_48.hIcon = LoadIconA(in_EAX,(LPCSTR)0x3e8);
  local_48.hCursor = LoadCursorA((HINSTANCE)0x0,(LPCSTR)0x7f00);
  local_48.hbrBackground = GetStockObject(0);
  local_48.lpszMenuName = (LPCSTR)0x7d0;
  local_48.lpszClassName = _DAT_004b2bdc;
  AVar1 = RegisterClassA(&local_48);
  if (AVar1 == 0) {
    local_1c = 0;
  }
  else {
    local_48.style = local_48.style | 8;
    local_48.lpfnWndProc = FUN_004110e1;
    local_48.cbWndExtra = 4;
    local_48.hCursor = (HCURSOR)0x0;
    local_48.hIcon = LoadIconA(local_20,(LPCSTR)0x3e9);
    local_48.lpszMenuName = (LPCSTR)0x0;
    local_48.lpszClassName = _DAT_004b2be4;
    color = GetSysColor(4);
    local_48.hbrBackground = CreateSolidBrush(color);
    AVar1 = RegisterClassA(&local_48);
    if (AVar1 == 0) {
      local_1c = 0;
    }
    else {
      local_1c = 1;
    }
  }
  return CONCAT44(param_2,local_1c);
}


