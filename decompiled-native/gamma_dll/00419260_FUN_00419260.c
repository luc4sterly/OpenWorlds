// 00419260 FUN_00419260 [Global]
// programa: gamma.dll

void __cdecl FUN_00419260(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwGetCameraPosition(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


