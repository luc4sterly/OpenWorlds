// 1000b4e0 FUN_1000b4e0 [Global]
// programa: RWDL8D21.DLL

undefined4 FUN_1000b4e0(void)

{
  if (DAT_1007520c != 0) {
    DAT_1007520c = DAT_1007520c + -0x8000;
    (**(code **)(DAT_10077da8 + 0x358))(DAT_1007520c);
    DAT_1007520c = 0;
  }
  return 1;
}


