// 00418b10 FUN_00418b10 [Global]
// programa: gamma.dll

void __cdecl
FUN_00418b10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwScaleMatrix(param_1,param_2,param_3,param_4,2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


