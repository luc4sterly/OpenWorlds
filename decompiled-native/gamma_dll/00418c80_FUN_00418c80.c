// 00418c80 FUN_00418c80 [Global]
// program: gamma.dll

void __cdecl FUN_00418c80(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwTransformMatrix(param_1,param_2,2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


