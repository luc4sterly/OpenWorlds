// 004188d0 FUN_004188d0 [Global]
// program: gamma.dll

void __cdecl FUN_004188d0(undefined4 param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwForAllClumpsInHierarchy(param_1,&LAB_00418650);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


