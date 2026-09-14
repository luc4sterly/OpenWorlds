// 004463b0 FUN_004463b0 [Global]
// programa: gamma.dll

HMODULE FUN_004463b0(void)

{
  if (DAT_0049fe10 == (HMODULE)0x0) {
    DAT_0049fe10 = LoadLibraryA(s_OleAut32_dll_0047a268);
  }
  return DAT_0049fe10;
}


