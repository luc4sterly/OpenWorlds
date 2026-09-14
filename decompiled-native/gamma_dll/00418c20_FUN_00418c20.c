// 00418c20 FUN_00418c20 [Global]
// programa: gamma.dll

void __cdecl FUN_00418c20(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwTransformClumpJoint(param_1,param_2,2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


