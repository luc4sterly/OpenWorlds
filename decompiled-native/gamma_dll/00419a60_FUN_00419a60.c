// 00419a60 FUN_00419a60 [Global]
// program: gamma.dll

int __cdecl FUN_00419a60(undefined4 param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_c = 0;
  local_10 = 0;
  RwReadStreamChunkType(param_1,&local_c);
  if (local_c == 0x434c554d) {
    RwReadStreamChunk(param_1,0x434c554d,&local_10,0);
  }
  if (local_10 != 0) {
    if (DAT_00489578 == 0) {
      RwForAllClumpsInHierarchy(local_10,&LAB_004187e0);
    }
    else {
      RwForAllClumpsInHierarchy(local_10,&LAB_00418790);
    }
  }
  iVar1 = local_10;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar1;
}


