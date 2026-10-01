// 004190a0 FUN_004190a0 [Global]
// program: gamma.dll

void __cdecl FUN_004190a0(undefined4 param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwDestroyCamera(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


