// 00419950 FUN_00419950 [Global]
// programa: gamma.dll

undefined4 FUN_00419950(void)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  uVar1 = RwPushScratchMatrix();
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00489580);
  return uVar1;
}


