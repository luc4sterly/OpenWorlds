// 10009970 FUN_10009970 [Global]
// program: RWDL6D21.DLL

void FUN_10009970(void)

{
  FUN_1000b760();
  if (DAT_10079220 != 0) {
    (**(code **)(DAT_1007bda8 + 0x358))(DAT_1007bb44);
    DAT_1007bb44 = 0;
    DAT_10079220 = 0;
  }
  if (DAT_1007921c != 0) {
    (**(code **)(DAT_1007bda8 + 0x358))(DAT_1007bb40);
    DAT_1007bb40 = 0;
    DAT_1007921c = 0;
  }
  if (DAT_10079210 != 0) {
    (**(code **)(DAT_1007bda8 + 0x358))(DAT_10079210);
    DAT_10079210 = 0;
  }
  if (DAT_10079214 != 0) {
    (**(code **)(DAT_1007bda8 + 0x358))(DAT_10079214);
    DAT_10079214 = 0;
  }
  return;
}


