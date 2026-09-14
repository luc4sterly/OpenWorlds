// 00417a50 FUN_00417a50 [Global]
// programa: gamma.dll

void __cdecl FUN_00417a50(undefined4 param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetMaterialModes(param_1,0x80);
  RwSetMaterialGeometrySampling(param_1,2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


