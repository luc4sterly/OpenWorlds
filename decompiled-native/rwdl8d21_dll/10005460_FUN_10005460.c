// 10005460 FUN_10005460 [Global]
// program: RWDL8D21.DLL

void FUN_10005460(void)

{
  if (DAT_1007517c != (int *)0x0) {
    (**(code **)(*DAT_1007517c + 8))(DAT_1007517c);
    DAT_1007517c = (int *)0x0;
  }
  if (DAT_10075178 != (int *)0x0) {
    if (DAT_10075180 == 0) {
      (**(code **)(*DAT_10075178 + 8))(DAT_10075178);
      DAT_10075178 = (int *)0x0;
    }
    else {
      (**(code **)(*DAT_10075178 + 8))();
      DAT_10075178 = (int *)0x0;
      DAT_10075180 = 0;
      (**(code **)(*DAT_10075174 + 0x50))(DAT_10075174,0,8);
    }
  }
  if (DAT_10075170 != (HWND)0x0) {
    DestroyWindow(DAT_10075170);
    DAT_10075170 = (HWND)0x0;
    UnregisterClassA(s_RWDRVCLASS_100751a0,DAT_10075168);
  }
  if (DAT_10075174 != (int *)0x0) {
    (**(code **)(*DAT_10075174 + 8))(DAT_10075174);
    DAT_10075174 = (int *)0x0;
  }
  return;
}


