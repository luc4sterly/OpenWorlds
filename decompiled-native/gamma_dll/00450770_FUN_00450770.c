// 00450770 FUN_00450770 [Global]
// programa: gamma.dll

uint FUN_00450770(uint param_1)

{
  if ((ushort)param_1 < 0x100) {
    param_1 = (uint)*(ushort *)(&DAT_004832e0 + (param_1 & 0xffff) * 2);
  }
  return param_1;
}


