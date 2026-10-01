// 1000b280 FUN_1000b280 [Global]
// program: RWDL6D21.DLL

undefined4 FUN_1000b280(uint *param_1)

{
  if (param_1 != (uint *)0x0) {
    if ((*param_1 & 0xffffff00) + 0x100 == DAT_10079220) {
      DAT_10079220 = DAT_1007bb50;
    }
    if ((param_1[1] & 0xffffff00) + 0x100 == DAT_1007921c) {
      DAT_1007921c = DAT_1007bb48;
    }
    if (*param_1 != 0) {
      (**(code **)(DAT_1007bda8 + 0x358))(*param_1);
    }
    if (param_1[1] != 0) {
      (**(code **)(DAT_1007bda8 + 0x358))(param_1[1]);
    }
    (**(code **)(DAT_1007bda8 + 0x358))(param_1);
  }
  return 1;
}


