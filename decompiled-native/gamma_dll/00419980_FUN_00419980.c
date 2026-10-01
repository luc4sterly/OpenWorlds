// 00419980 FUN_00419980 [Global]
// program: gamma.dll

void __cdecl
FUN_00419980(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwQueryRotateMatrix(param_1,param_2,param_3,param_4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


