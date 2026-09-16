// 004499b0 FUN_004499b0 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_004499b0(int param_1)

{
  FUN_00449a00(param_1);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x8c));
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined4 *)(param_1 + 0xb4) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x8c));
  return 0;
}


