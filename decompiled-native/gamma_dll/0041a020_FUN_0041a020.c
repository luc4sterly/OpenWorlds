// 0041a020 FUN_0041a020 [Global]
// program: gamma.dll

void __cdecl FUN_0041a020(undefined4 param_1)

{
  HWND hWnd;
  HDC hDC;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  hWnd = (HWND)RwGetCameraData(param_1);
  hDC = GetDC(hWnd);
  if (hDC != (HDC)0x0) {
    RwInvalidateCameraViewport(param_1);
    RwShowCameraImage(param_1,hDC);
    ReleaseDC(hWnd,hDC);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


