// 00418210 FUN_00418210 [Global]
// program: gamma.dll

void __cdecl FUN_00418210(undefined4 param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_c = 0;
  local_8 = 0;
  RwCloseStream(param_1,&local_c);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


