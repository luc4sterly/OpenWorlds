// 00419890 FUN_00419890 [Global]
// program: gamma.dll

void __cdecl FUN_00419890(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwOrthoNormalizeMatrix(param_1,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


