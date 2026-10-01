// 10006060 FUN_10006060 [Global]
// program: rwdlmd21.dll

void FUN_10006060(void)

{
  if (DAT_10087164 != 0) {
    (**(code **)(DAT_10089de0 + 0x358))(DAT_10087164);
    DAT_10087164 = 0;
  }
  if (DAT_10087194 != (HMODULE)0x0) {
    DAT_10087198 = 0;
    FreeLibrary(DAT_10087194);
    DAT_10087194 = (HMODULE)0x0;
  }
  return;
}


