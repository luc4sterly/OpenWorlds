// 0044a180 FUN_0044a180 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_0044a180(int param_1)

{
  DWORD DVar1;
  
  DVar1 = timeGetTime();
  *(DWORD *)(param_1 + 0x130) = DVar1 - *(int *)(param_1 + 0x130);
  return 0;
}


