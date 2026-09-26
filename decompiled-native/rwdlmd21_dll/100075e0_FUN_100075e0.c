// 100075e0 FUN_100075e0 [Global]
// programa: rwdlmd21.dll

int FUN_100075e0(byte param_1)

{
  return 2 - (uint)((*(uint *)(&DAT_10087210 + (param_1 >> 3 & 0xfffffffc)) & 1 << (param_1 & 0x1f))
                   == 0);
}


