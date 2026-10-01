// 00419c80 FUN_00419c80 [Global]
// program: gamma.dll

void __cdecl FUN_00419c80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetCameraViewOffset(param_1,param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


