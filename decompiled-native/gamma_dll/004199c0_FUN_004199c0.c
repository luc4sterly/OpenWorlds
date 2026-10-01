// 004199c0 FUN_004199c0 [Global]
// program: gamma.dll

int __cdecl FUN_004199c0(undefined4 param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = RwReadShape(param_1);
  if (iVar1 != 0) {
    if (DAT_00489578 == 0) {
      RwForAllClumpsInHierarchy(iVar1,&LAB_004187e0);
    }
    else {
      RwForAllClumpsInHierarchy(iVar1,&LAB_00418790);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar1;
}


