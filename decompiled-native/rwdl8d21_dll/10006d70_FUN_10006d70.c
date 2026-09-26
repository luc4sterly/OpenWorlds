// 10006d70 FUN_10006d70 [Global]
// programa: RWDL8D21.DLL

int FUN_10006d70(byte param_1)

{
  return 2 - (uint)((*(uint *)(&DAT_100751e8 + (param_1 >> 3 & 0xfffffffc)) & 1 << (param_1 & 0x1f))
                   == 0);
}


