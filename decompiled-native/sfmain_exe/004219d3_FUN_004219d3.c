// 004219d3 FUN_004219d3 [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_004219d3(undefined4 param_1,int param_2)

{
  HINSTANCE in_EAX;
  HWND hWnd;
  undefined4 extraout_ECX;
  int unaff_EBX;
  tagRECT *lpRect;
  tagRECT local_30;
  HINSTANCE local_20;
  undefined4 local_14;
  
  lpRect = &local_30;
  local_20 = in_EAX;
  hWnd = GetDesktopWindow();
  GetWindowRect(hWnd,lpRect);
  if (_DAT_004b2c70 == 0) {
    DAT_004627d0 = CreateWindowExA(0x80,_DAT_004b2bdc,DAT_004627c0,0xcf0000,-0x80000000,-0x80000000,
                                   (local_30.right - local_30.left) / 2,
                                   (local_30.bottom - local_30.top) / 2,(HWND)0x0,(HMENU)0x0,
                                   local_20,(LPVOID)0x0);
  }
  else {
    DAT_004627d0 = CreateWindowExA(0,_DAT_004b2bdc,DAT_004627c0,0xcf0000,-0x80000000,-0x80000000,
                                   (local_30.right - local_30.left) / 2,
                                   (local_30.bottom - local_30.top) / 2,(HWND)0x0,(HMENU)0x0,
                                   local_20,(LPVOID)0x0);
  }
  if (DAT_004627d0 == (HWND)0x0) {
    local_14 = 0;
  }
  else {
    DAT_004627cc = LoadAcceleratorsA(DAT_004627bc,(LPCSTR)0xfa0);
    if (DAT_004627cc == (HACCEL)0x0) {
      local_14 = 0;
    }
    else {
      ShowWindow(DAT_004627d0,unaff_EBX);
      UpdateWindow(DAT_004627d0);
      FindWindowA(s_GammaPhoneFrameClass_004371f0,(LPCSTR)0x0);
      FUN_0041c220(extraout_ECX,param_2);
      local_14 = 1;
    }
  }
  return local_14;
}


