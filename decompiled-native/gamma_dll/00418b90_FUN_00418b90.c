// 00418b90 FUN_00418b90 [Global]
// programa: gamma.dll

void __cdecl FUN_00418b90(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwTransformCamera(param_1,param_2,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


