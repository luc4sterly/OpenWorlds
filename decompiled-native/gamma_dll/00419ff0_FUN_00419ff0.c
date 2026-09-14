// 00419ff0 FUN_00419ff0 [Global]
// programa: gamma.dll

void __cdecl FUN_00419ff0(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetSceneData(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


