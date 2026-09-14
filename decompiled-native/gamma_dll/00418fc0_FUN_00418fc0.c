// 00418fc0 FUN_00418fc0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_00418fc0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwCreateLight(1,param_1,param_2,param_3,DAT_00470410);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


