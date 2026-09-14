// 00419290 FUN_00419290 [Global]
// programa: gamma.dll

void __cdecl FUN_00419290(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_1c = DAT_00489598;
  local_18 = DAT_0048959c;
  uStack_14 = DAT_004895a0;
  RwGetCameraViewOffset(param_1,&local_1c);
  *param_2 = local_1c;
  *param_3 = local_18;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


