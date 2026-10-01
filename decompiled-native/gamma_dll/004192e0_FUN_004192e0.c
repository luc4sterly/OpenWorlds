// 004192e0 FUN_004192e0 [Global]
// program: gamma.dll

void __cdecl
FUN_004192e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 local_10 [4];
  undefined1 local_c [4];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwGetCameraRenderOffset(param_1,param_2,param_3);
  RwGetCameraViewport(param_1,local_10,local_c,param_4,param_5);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


