// 100262d0 FUN_100262d0 [Global]
// programa: RWDLDD21.DLL

undefined4 FUN_100262d0(void)

{
  if (DAT_100362bc != 0) {
    DAT_100362bc = DAT_100362bc + -0x8000;
    (**(code **)(DAT_100394fc + 0x358))(DAT_100362bc);
    DAT_100362bc = 0;
  }
  return 1;
}


