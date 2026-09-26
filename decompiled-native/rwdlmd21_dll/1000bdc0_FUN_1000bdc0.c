// 1000bdc0 FUN_1000bdc0 [Global]
// programa: rwdlmd21.dll

undefined4 FUN_1000bdc0(void)

{
  if (DAT_10087234 != 0) {
    DAT_10087234 = DAT_10087234 + -0x8000;
    (**(code **)(DAT_10089de0 + 0x358))(DAT_10087234);
    DAT_10087234 = 0;
  }
  return 1;
}


