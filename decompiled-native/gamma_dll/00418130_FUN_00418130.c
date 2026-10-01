// 00418130 FUN_00418130 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_00418130(undefined4 param_1)

{
  undefined4 uVar1;
  int local_c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_c = 0;
  uVar1 = 0;
  RwGetDeviceInfo(0x3ec,&local_c,4);
  if (local_c != 0) {
    uVar1 = RwGetCameraImage(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


