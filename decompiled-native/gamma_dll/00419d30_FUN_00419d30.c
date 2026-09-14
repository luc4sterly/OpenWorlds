// 00419d30 FUN_00419d30 [Global]
// programa: gamma.dll

void __cdecl FUN_00419d30(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetClumpData(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


