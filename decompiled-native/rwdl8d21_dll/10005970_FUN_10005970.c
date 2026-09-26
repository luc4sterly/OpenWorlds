// 10005970 FUN_10005970 [Global]
// programa: RWDL8D21.DLL

void FUN_10005970(void)

{
  if (DAT_1007515c != 0) {
    (**(code **)(DAT_10077da8 + 0x358))(DAT_1007515c);
    DAT_1007515c = 0;
  }
  if (DAT_1007518c != (HMODULE)0x0) {
    DAT_10075190 = 0;
    FreeLibrary(DAT_1007518c);
    DAT_1007518c = (HMODULE)0x0;
  }
  return;
}


