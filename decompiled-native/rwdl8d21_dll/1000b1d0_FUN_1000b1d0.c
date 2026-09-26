// 1000b1d0 FUN_1000b1d0 [Global]
// programa: RWDL8D21.DLL

undefined4 FUN_1000b1d0(uint *param_1)

{
  if (param_1 != (uint *)0x0) {
    if ((*param_1 & 0xffffff00) + 0x100 == DAT_10075220) {
      DAT_10075220 = DAT_10077b50;
    }
    if ((param_1[1] & 0xffffff00) + 0x100 == DAT_1007521c) {
      DAT_1007521c = DAT_10077b48;
    }
    if (*param_1 != 0) {
      (**(code **)(DAT_10077da8 + 0x358))(*param_1);
    }
    if (param_1[1] != 0) {
      (**(code **)(DAT_10077da8 + 0x358))(param_1[1]);
    }
    (**(code **)(DAT_10077da8 + 0x358))(param_1);
  }
  return 1;
}


