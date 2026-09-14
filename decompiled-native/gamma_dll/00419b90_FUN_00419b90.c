// 00419b90 FUN_00419b90 [Global]
// programa: gamma.dll

void __cdecl FUN_00419b90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  if (DAT_00489578 == 0) {
    RwDeviceControl(7,param_3,0,0);
  }
  uVar1 = RwGetCameraData(param_2);
  RwBeginCameraUpdate(param_2,uVar1);
  RwRenderScene(param_1);
  RwEndCameraUpdate(param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


