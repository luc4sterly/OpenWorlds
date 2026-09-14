// 00418c50 FUN_00418c50 [Global]
// programa: gamma.dll

void __cdecl FUN_00418c50(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwTransformClumpJoint(param_1,param_2,3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


