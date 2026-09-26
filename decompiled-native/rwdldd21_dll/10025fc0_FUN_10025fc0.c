// 10025fc0 FUN_10025fc0 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_10025fc0(uint *param_1)

{
  if (param_1 != (uint *)0x0) {
    if ((*param_1 & 0xffffff00) + 0x100 == DAT_100362d0) {
      DAT_100362d0 = DAT_1003908c;
    }
    if ((param_1[1] & 0xffffff00) + 0x100 == DAT_100362cc) {
      DAT_100362cc = DAT_10039084;
    }
    if (*param_1 != 0) {
      (**(code **)(DAT_100394fc + 0x358))(*param_1);
    }
    if (param_1[1] != 0) {
      (**(code **)(DAT_100394fc + 0x358))(param_1[1]);
    }
    (**(code **)(DAT_100394fc + 0x358))(param_1);
  }
  return 1;
}


