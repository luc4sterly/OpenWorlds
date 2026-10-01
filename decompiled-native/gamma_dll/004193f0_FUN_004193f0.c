// 004193f0 FUN_004193f0 [Global]
// program: gamma.dll

void __cdecl FUN_004193f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwGetClumpLocalBBox(param_1,param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


