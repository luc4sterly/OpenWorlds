// 00418d60 FUN_00418d60 [Global]
// programa: gamma.dll

void __cdecl
FUN_00418d60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwTranslateMatrix(param_1,param_2,param_3,param_4,3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


