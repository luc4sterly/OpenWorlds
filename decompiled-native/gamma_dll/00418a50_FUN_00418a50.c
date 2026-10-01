// 00418a50 FUN_00418a50 [Global]
// program: gamma.dll

void __cdecl
FUN_00418a50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwRotateMatrix(param_1,param_3,param_4,param_5,param_2,1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


