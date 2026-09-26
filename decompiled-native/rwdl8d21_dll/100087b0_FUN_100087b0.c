// 100087b0 FUN_100087b0 [Global]
// programa: RWDL8D21.DLL

void FUN_100087b0(int param_1,int param_2)

{
  if (DAT_10075210 != 0) {
    (**(code **)(DAT_10077da8 + 0x358))(DAT_10075210);
  }
  DAT_10075210 = 0;
  DAT_10077eb0 = param_1 * 2;
  DAT_10077da0 = param_2;
  DAT_10075210 = (**(code **)(DAT_10077da8 + 0x34c))(DAT_10077eb0 * param_2);
  return;
}


