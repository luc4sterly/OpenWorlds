// 1000b9c0 FUN_1000b9c0 [Global]
// program: rwdlmd21.dll

undefined4 FUN_1000b9c0(uint *param_1)

{
  if (param_1 != (uint *)0x0) {
    if ((*param_1 & 0xffffff00) + 0x100 == DAT_10087248) {
      DAT_10087248 = DAT_10089b80;
    }
    if ((param_1[1] & 0xffffff00) + 0x100 == DAT_10087244) {
      DAT_10087244 = DAT_10089b78;
    }
    if (*param_1 != 0) {
      (**(code **)(DAT_10089de0 + 0x358))(*param_1);
    }
    if (param_1[1] != 0) {
      (**(code **)(DAT_10089de0 + 0x358))(param_1[1]);
    }
    (**(code **)(DAT_10089de0 + 0x358))(param_1);
  }
  return 1;
}


