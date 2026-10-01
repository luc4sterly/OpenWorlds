// 004193c0 FUN_004193c0 [Global]
// program: gamma.dll

void __cdecl FUN_004193c0(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwGetClumpLTM(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


