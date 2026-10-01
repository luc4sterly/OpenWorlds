// 00419070 FUN_00419070 [Global]
// program: gamma.dll

undefined4 FUN_00419070(void)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwCreateScene();
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


