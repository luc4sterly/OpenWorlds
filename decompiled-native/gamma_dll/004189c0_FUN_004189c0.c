// 004189c0 FUN_004189c0 [Global]
// program: gamma.dll

int __cdecl FUN_004189c0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = RwFindTaggedPolygon(param_1,param_2);
  if (iVar1 == 0) {
    local_14 = 1;
    RwForAllPolygonsInClumpPointer(param_1,&LAB_00418720,&local_14);
    iVar1 = RwFindTaggedPolygon(param_1,param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar1;
}


