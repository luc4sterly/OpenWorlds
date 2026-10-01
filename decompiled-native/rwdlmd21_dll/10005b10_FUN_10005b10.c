// 10005b10 FUN_10005b10 [Global]
// program: rwdlmd21.dll

void FUN_10005b10(void)

{
  if (DAT_10087184 != (int *)0x0) {
    (**(code **)(*DAT_10087184 + 8))(DAT_10087184);
    DAT_10087184 = (int *)0x0;
  }
  if (DAT_10087180 != (int *)0x0) {
    if (DAT_10087188 == 0) {
      (**(code **)(*DAT_10087180 + 8))(DAT_10087180);
      DAT_10087180 = (int *)0x0;
    }
    else {
      (**(code **)(*DAT_10087180 + 8))();
      DAT_10087180 = (int *)0x0;
      DAT_10087188 = 0;
      (**(code **)(*DAT_1008717c + 0x50))(DAT_1008717c,0,8);
    }
  }
  if (DAT_10087178 != (HWND)0x0) {
    DestroyWindow(DAT_10087178);
    DAT_10087178 = (HWND)0x0;
    UnregisterClassA(s_RWDRVCLASS_100871a8,DAT_10087170);
  }
  if (DAT_1008717c != (int *)0x0) {
    (**(code **)(*DAT_1008717c + 8))(DAT_1008717c);
    DAT_1008717c = (int *)0x0;
  }
  return;
}


