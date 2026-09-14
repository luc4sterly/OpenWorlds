// 00419ec0 FUN_00419ec0 [Global]
// programa: gamma.dll

void __cdecl FUN_00419ec0(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetMaterialOpacity(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


