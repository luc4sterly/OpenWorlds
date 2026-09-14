// 00418180 FUN_00418180 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00418180(undefined4 param_1)

{
  undefined4 uVar1;
  int local_c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_c = 0;
  uVar1 = 0;
  RwGetDeviceInfo(0x44c,&local_c,4);
  if (local_c != 0) {
    uVar1 = RwGetCameraImage(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


