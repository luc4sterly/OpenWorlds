// 004507a0 FUN_004507a0 [Global]
// programa: gamma.dll

uint FUN_004507a0(uint param_1)

{
  if ((ushort)param_1 < 0x100) {
    param_1 = (uint)*(ushort *)(&DAT_004834e0 + (param_1 & 0xffff) * 2);
  }
  return param_1;
}


