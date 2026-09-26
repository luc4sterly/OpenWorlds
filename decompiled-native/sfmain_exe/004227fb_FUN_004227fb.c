// 004227fb FUN_004227fb [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004227fb(void)

{
  while (_DAT_004b2bf8 != (undefined4 *)0x0) {
    _DAT_004b2bf8 = (undefined4 *)*_DAT_004b2bf8;
    FUN_00422689();
  }
  return;
}


