// 100098c0 FUN_100098c0 [Global]
// programa: RWDL8D21.DLL

void FUN_100098c0(void)

{
  FUN_1000b6b0();
  if (DAT_10075220 != 0) {
    (**(code **)(DAT_10077da8 + 0x358))(DAT_10077b44);
    DAT_10077b44 = 0;
    DAT_10075220 = 0;
  }
  if (DAT_1007521c != 0) {
    (**(code **)(DAT_10077da8 + 0x358))(DAT_10077b40);
    DAT_10077b40 = 0;
    DAT_1007521c = 0;
  }
  if (DAT_10075210 != 0) {
    (**(code **)(DAT_10077da8 + 0x358))(DAT_10075210);
    DAT_10075210 = 0;
  }
  if (DAT_10075214 != 0) {
    (**(code **)(DAT_10077da8 + 0x358))(DAT_10075214);
    DAT_10075214 = 0;
  }
  return;
}


