// 00419700 FUN_00419700 [Global]
// program: gamma.dll

float10 __cdecl FUN_00419700(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  float10 fVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  fVar1 = (float10)RwGetMatrixElement(param_1,param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return (float10)(float)fVar1;
}


