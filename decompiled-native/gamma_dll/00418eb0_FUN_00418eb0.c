// 00418eb0 FUN_00418eb0 [Global]
// program: gamma.dll

void __cdecl
FUN_00418eb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetCameraBackColor(param_1,param_2,param_3,param_4);
  uVar1 = RwGetCameraData(param_1);
  RwBeginCameraUpdate(param_1,uVar1);
  RwClearCameraViewport(param_1);
  RwEndCameraUpdate(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


