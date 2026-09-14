// 00447c10 FUN_00447c10 [Global]
// programa: gamma.dll

undefined4 __fastcall FUN_00447c10(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x1c));
  return 0;
}


