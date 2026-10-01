// 100246b0 FUN_100246b0 [Global]
// program: RWDLDD21.DLL

void FUN_100246b0(void)

{
  FUN_10027f60();
  if (DAT_100362d0 != 0) {
    (**(code **)(DAT_100394fc + 0x358))(DAT_10039080);
    DAT_10039080 = 0;
    DAT_100362d0 = 0;
  }
  if (DAT_100362cc != 0) {
    (**(code **)(DAT_100394fc + 0x358))(DAT_1003907c);
    DAT_1003907c = 0;
    DAT_100362cc = 0;
  }
  if (DAT_100362c0 != 0) {
    (**(code **)(DAT_100394fc + 0x358))(DAT_100362c0);
    DAT_100362c0 = 0;
  }
  if (DAT_100362c4 != 0) {
    (**(code **)(DAT_100394fc + 0x358))(DAT_100362c4);
    DAT_100362c4 = 0;
  }
  return;
}


