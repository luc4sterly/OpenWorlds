// 10006e20 FUN_10006e20 [Global]
// program: RWDL6D21.DLL

int FUN_10006e20(byte param_1)

{
  return 2 - (uint)((*(uint *)(&DAT_100791e8 + (param_1 >> 3 & 0xfffffffc)) & 1 << (param_1 & 0x1f))
                   == 0);
}


