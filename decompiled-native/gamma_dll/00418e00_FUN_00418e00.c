// 00418e00 FUN_00418e00 [Global]
// program: gamma.dll

void __cdecl FUN_00418e00(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwAddLightToScene(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


