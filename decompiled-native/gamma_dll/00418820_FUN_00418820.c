// 00418820 FUN_00418820 [Global]
// programa: gamma.dll

void __cdecl FUN_00418820(undefined4 param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetClumpState(param_1,2);
  iVar1 = RwGetClumpNumChildren(param_1);
  if (0 < iVar1) {
    RwForAllClumpsInHierarchy(param_1,&LAB_004185d0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


