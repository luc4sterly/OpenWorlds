// 00419040 FUN_00419040 [Global]
// program: gamma.dll

undefined4 FUN_00419040(void)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwCreateMatrix();
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


