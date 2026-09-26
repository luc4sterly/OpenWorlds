// 1000a080 FUN_1000a080 [Global]
// programa: rwdlmd21.dll

void FUN_1000a080(void)

{
  FUN_1000bfb0();
  if (DAT_10087248 != 0) {
    (**(code **)(DAT_10089de0 + 0x358))(DAT_10089b74);
    DAT_10089b74 = 0;
    DAT_10087248 = 0;
  }
  if (DAT_10087244 != 0) {
    (**(code **)(DAT_10089de0 + 0x358))(DAT_10089b70);
    DAT_10089b70 = 0;
    DAT_10087244 = 0;
  }
  if (DAT_10087238 != 0) {
    (**(code **)(DAT_10089de0 + 0x358))(DAT_10087238);
    DAT_10087238 = 0;
  }
  if (DAT_1008723c != 0) {
    (**(code **)(DAT_10089de0 + 0x358))(DAT_1008723c);
    DAT_1008723c = 0;
  }
  return;
}


