// 00418b50 FUN_00418b50 [Global]
// programa: gamma.dll

void __cdecl
FUN_00418b50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwScaleMatrix(param_1,param_2,param_3,param_4,3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


