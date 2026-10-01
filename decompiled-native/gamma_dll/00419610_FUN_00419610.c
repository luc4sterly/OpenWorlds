// 00419610 FUN_00419610 [Global]
// program: gamma.dll

void __cdecl
FUN_00419610(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 local_14;
  undefined4 local_10;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_14 = DAT_004895a4;
  local_10 = DAT_004895a8;
  RwGetClumpVertexUV(param_1,param_2,&local_14);
  *param_3 = local_14;
  *param_4 = local_10;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


