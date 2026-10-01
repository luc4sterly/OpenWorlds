// 00418f30 FUN_00418f30 [Global]
// program: gamma.dll

int __cdecl FUN_00418f30(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = RwCreateCamera(param_1,param_2,0);
  if (iVar1 != 0) {
    RwSetCameraData(iVar1,param_3);
    RwSetCameraNearClipping(iVar1,DAT_00470408);
    RwSetCameraFarClipping(iVar1,DAT_0047040c);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar1;
}


