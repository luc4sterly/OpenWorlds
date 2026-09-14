// 00418f00 FUN_00418f00 [Global]
// programa: gamma.dll

void __cdecl FUN_00418f00(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwCopyMatrix(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


