// 004195b0 FUN_004195b0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_004195b0(undefined4 param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwGetClumpTag(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


