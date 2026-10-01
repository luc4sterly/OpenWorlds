// 00418bc0 FUN_00418bc0 [Global]
// program: gamma.dll

void __cdecl FUN_00418bc0(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwTransformClump(param_1,param_2,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


