// 00419390 FUN_00419390 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_00419390(undefined4 param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwGetClumpData(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


