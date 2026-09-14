// 004181d0 FUN_004181d0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_004181d0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  local_10 = param_1;
  local_c = param_2;
  uVar1 = RwOpenStream(3,1,&local_10);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


