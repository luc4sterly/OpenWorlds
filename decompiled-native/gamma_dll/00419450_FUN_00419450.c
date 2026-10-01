// 00419450 FUN_00419450 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_00419450(undefined4 param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwGetClumpNumChildren(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


