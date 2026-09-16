// 00449400 FUN_00449400 [Global]
// programa: gamma.dll

bool __fastcall FUN_00449400(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x8c));
  iVar1 = *(int *)(param_1 + 100);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x8c));
  return iVar1 != 0;
}


