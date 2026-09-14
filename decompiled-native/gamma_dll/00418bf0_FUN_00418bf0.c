// 00418bf0 FUN_00418bf0 [Global]
// programa: gamma.dll

void __cdecl FUN_00418bf0(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwTransformClumpJoint(param_1,param_2,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


