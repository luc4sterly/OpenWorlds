// 00405068 FUN_00405068 [Global]
// program: run.exe

byte __cdecl FUN_00405068(uint param_1)

{
  if (DAT_0040cf80 <= param_1) {
    return 0;
  }
  return *(byte *)((&DAT_0040ce80)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 0x40;
}


