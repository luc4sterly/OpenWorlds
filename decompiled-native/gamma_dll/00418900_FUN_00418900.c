// 00418900 FUN_00418900 [Global]
// program: gamma.dll

void __cdecl FUN_00418900(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = RwGetClumpOrigin(param_1,&local_34);
  if (iVar1 == 0) {
    param_2[2] = 0;
    param_2[1] = param_2[2];
    *param_2 = param_2[1];
    param_3[2] = 0;
    param_3[1] = param_3[2];
    *param_3 = param_3[1];
  }
  else {
    local_1c = local_34;
    local_28 = local_34;
    local_18 = local_30;
    local_24 = local_30;
    local_14 = local_2c;
    local_20 = local_2c;
    RwForAllClumpsInHierarchyPointer(param_1,&LAB_00418670,&local_28);
    *param_2 = local_28;
    param_2[1] = local_24;
    param_2[2] = local_20;
    *param_3 = local_1c;
    param_3[1] = local_18;
    param_3[2] = local_14;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


