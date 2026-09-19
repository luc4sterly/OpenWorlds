// 10005a20 FUN_10005a20 [Global]
// programa: RWDL6D21.DLL

void FUN_10005a20(void)

{
  if (DAT_1007915c != 0) {
    (**(code **)(DAT_1007bda8 + 0x358))(DAT_1007915c);
    DAT_1007915c = 0;
  }
  if (DAT_1007918c != (HMODULE)0x0) {
    DAT_10079190 = 0;
    FreeLibrary(DAT_1007918c);
    DAT_1007918c = (HMODULE)0x0;
  }
  return;
}


