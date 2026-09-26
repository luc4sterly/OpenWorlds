// 100263d0 FUN_100263d0 [Global]
// programa: RWDLDD21.DLL

int FUN_100263d0(byte param_1)

{
  return 2 - (uint)((*(uint *)(&DAT_100363f0 + (param_1 >> 3 & 0xfffffffc)) & 1 << (param_1 & 0x1f))
                   == 0);
}


