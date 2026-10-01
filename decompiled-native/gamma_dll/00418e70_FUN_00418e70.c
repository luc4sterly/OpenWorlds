// 00418e70 FUN_00418e70 [Global]
// program: gamma.dll

undefined4 __cdecl
FUN_00418e70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwAddVertexToClump(param_1,param_2,param_3,param_4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


