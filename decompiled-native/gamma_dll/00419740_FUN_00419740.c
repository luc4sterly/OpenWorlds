// 00419740 FUN_00419740 [Global]
// program: gamma.dll

void __cdecl FUN_00419740(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwGetMatrixElements(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


