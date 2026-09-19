// 100054d0 FUN_100054d0 [Global]
// programa: RWDL6D21.DLL

void FUN_100054d0(void)

{
  if (DAT_1007917c != (int *)0x0) {
    (**(code **)(*DAT_1007917c + 8))(DAT_1007917c);
    DAT_1007917c = (int *)0x0;
  }
  if (DAT_10079178 != (int *)0x0) {
    if (DAT_10079180 == 0) {
      (**(code **)(*DAT_10079178 + 8))(DAT_10079178);
      DAT_10079178 = (int *)0x0;
    }
    else {
      (**(code **)(*DAT_10079178 + 8))();
      DAT_10079178 = (int *)0x0;
      DAT_10079180 = 0;
      (**(code **)(*DAT_10079174 + 0x50))(DAT_10079174,0,8);
    }
  }
  if (DAT_10079170 != (HWND)0x0) {
    DestroyWindow(DAT_10079170);
    DAT_10079170 = (HWND)0x0;
    UnregisterClassA(s_RWDRVCLASS_100791a0,DAT_10079168);
  }
  if (DAT_10079174 != (int *)0x0) {
    (**(code **)(*DAT_10079174 + 8))(DAT_10079174);
    DAT_10079174 = (int *)0x0;
  }
  return;
}


