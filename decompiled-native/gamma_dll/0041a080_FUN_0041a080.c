// 0041a080 FUN_0041a080 [Global]
// programa: gamma.dll

void __cdecl FUN_0041a080(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwTransformPoint(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


