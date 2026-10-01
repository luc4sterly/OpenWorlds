// 00405482 FUN_00405482 [Global]
// program: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_00405482(uint param_1)

{
  if ((param_1 < DAT_0040cf80) &&
     ((*(byte *)((&DAT_0040ce80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    return *(undefined4 *)((&DAT_0040ce80)[(int)param_1 >> 5] + (param_1 & 0x1f) * 8);
  }
  DAT_0040ba3c = 0;
  _DAT_0040ba38 = 9;
  return 0xffffffff;
}


