// 00418f90 FUN_00418f90 [Global]
// programa: gamma.dll

undefined4 FUN_00418f90(void)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwCreateClump(0,0);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


