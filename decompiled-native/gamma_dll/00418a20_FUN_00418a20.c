// 00418a20 FUN_00418a20 [Global]
// program: gamma.dll

void __cdecl FUN_00418a20(undefined4 param_1,undefined4 param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  RwForAllPolygonsInClumpPointer(param_1,&LAB_00418750,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return;
}


