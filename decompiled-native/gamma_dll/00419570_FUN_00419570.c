// 00419570 FUN_00419570 [Global]
// programa: gamma.dll

bool __cdecl FUN_00419570(undefined4 param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  iVar1 = RwGetClumpState(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return iVar1 == 2;
}


