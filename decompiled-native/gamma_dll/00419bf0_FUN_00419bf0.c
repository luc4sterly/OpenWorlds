// 00419bf0 FUN_00419bf0 [Global]
// program: gamma.dll

void __cdecl
FUN_00419bf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetCameraLookAt(param_1,param_2,param_3,param_4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


