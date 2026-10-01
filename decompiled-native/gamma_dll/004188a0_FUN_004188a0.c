// 004188a0 FUN_004188a0 [Global]
// program: gamma.dll

void __cdecl FUN_004188a0(undefined4 param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwForAllClumpsInHierarchy(param_1,&LAB_00418630);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


