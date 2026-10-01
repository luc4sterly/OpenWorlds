// 00419670 FUN_00419670 [Global]
// program: gamma.dll

void __cdecl
FUN_00419670(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetCameraNearClipping(param_2,DAT_00470414);
  RwGetClumpViewportRect(param_1,param_2,param_3,param_4,param_5,param_6);
  RwSetCameraNearClipping(param_2,DAT_00470408);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


