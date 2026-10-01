// 004195e0 FUN_004195e0 [Global]
// program: gamma.dll

void __cdecl FUN_004195e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwGetClumpVertex(param_1,param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


