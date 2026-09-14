// 0044aa90 FUN_0044aa90 [Global]
// programa: gamma.dll

undefined4 FUN_0044aa90(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  *param_2 = *(undefined4 *)(param_1 + 0xf8);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x74));
  return 0;
}


