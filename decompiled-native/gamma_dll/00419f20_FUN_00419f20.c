// 00419f20 FUN_00419f20 [Global]
// program: gamma.dll

void __cdecl FUN_00419f20(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetMaterialTexture(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


