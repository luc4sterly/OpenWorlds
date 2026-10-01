// 00419af0 FUN_00419af0 [Global]
// program: gamma.dll

int __cdecl FUN_00419af0(undefined4 param_1)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_18 = 0;
  RwReadStreamChunkType(param_1,&local_18);
  if (local_18 == 0x5a5a5a5b) {
    iVar1 = RwReadStreamChunkHeader(param_1);
    if (0 < iVar1 + -8) {
      local_10 = 0;
      local_14 = 0;
      RwReadStreamInt(param_1,&local_14,8);
      if ((local_14 == 0x13765342) && (local_10 == 1)) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
        return iVar1 + -8;
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return 0;
}


