// 00418860 FUN_00418860 [Global]
// program: gamma.dll

void __cdecl FUN_00418860(undefined4 param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwSetClumpState(param_1,1);
  iVar1 = RwGetClumpNumChildren(param_1);
  if (0 < iVar1) {
    RwForAllClumpsInHierarchy(param_1,&LAB_00418600);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


