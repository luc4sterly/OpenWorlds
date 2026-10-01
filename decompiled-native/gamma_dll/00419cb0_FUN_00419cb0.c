// 00419cb0 FUN_00419cb0 [Global]
// program: gamma.dll

void __cdecl
FUN_00419cb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetCameraRenderOffset(param_1,param_2,param_3);
  RwSetCameraViewport(param_1,0,0,param_4,param_5);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


