// 0044b270 FUN_0044b270 [Global]
// program: gamma.dll

undefined4 * __fastcall FUN_0044b270(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    CloseHandle((HANDLE)*param_1);
  }
  return param_1;
}


