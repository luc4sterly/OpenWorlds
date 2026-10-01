// 004483c0 FUN_004483c0 [Global]
// program: gamma.dll

void FUN_004483c0(LPVOID param_1)

{
  if (param_1 == (LPVOID)0x0) {
    return;
  }
  FUN_004484d0((int)param_1);
  CoTaskMemFree(param_1);
  return;
}


