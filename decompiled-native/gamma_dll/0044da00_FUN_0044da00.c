// 0044da00 FUN_0044da00 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0044da00(int param_1)

{
  BOOL BVar1;
  
  if ((param_1 < 0x100) && ((undefined4 *)(&DAT_0049f448)[param_1] != (undefined4 *)0x0)) {
    BVar1 = CloseHandle(*(HANDLE *)(&DAT_0049f448)[param_1]);
    if (BVar1 != 0) {
      FUN_00454a60((undefined4 *)(&DAT_0049f448)[param_1]);
      (&DAT_0049f448)[param_1] = 0;
      return 0;
    }
    _DAT_0049ff4c = GetLastError();
    return 0xffffffff;
  }
  return 0xffffffff;
}


