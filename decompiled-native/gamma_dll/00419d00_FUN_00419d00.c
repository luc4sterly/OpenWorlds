// 00419d00 FUN_00419d00 [Global]
// programa: gamma.dll

void __cdecl FUN_00419d00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetCameraViewwindow(param_1,param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


