// 00417a10 FUN_00417a10 [Global]
// program: gamma.dll

void __cdecl FUN_00417a10(undefined4 param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetMaterialLightSampling(param_1,2);
  RwAddTextureModeToMaterial(param_1,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


