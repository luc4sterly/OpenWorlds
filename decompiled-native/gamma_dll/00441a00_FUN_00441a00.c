// 00441a00 FUN_00441a00 [Global]
// programa: gamma.dll

undefined4 FUN_00441a00(int param_1,undefined4 *param_2)

{
  if (param_2 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + -0x48));
  *param_2 = *(undefined4 *)(param_1 + 0x40);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + -0x48));
  return 0;
}


