// 00419190 FUN_00419190 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00419190(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwFindTaggedClump(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


