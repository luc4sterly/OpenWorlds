// 00455020 FUN_00455020 [Global]
// programa: gamma.dll

int * __cdecl FUN_00455020(LPCSTR param_1,char *param_2)

{
  uint *puVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee58);
  puVar1 = FUN_00454b80();
  piVar2 = FUN_00455060(param_1,param_2,(int *)puVar1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee58);
  return piVar2;
}


