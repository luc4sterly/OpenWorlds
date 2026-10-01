// 0044e130 FUN_0044e130 [Global]
// program: gamma.dll

undefined * FUN_0044e130(void)

{
  if (DAT_0049e1d4 == '\0') {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0049e1d8);
    FUN_00450830(&DAT_0049e1d8,&LAB_00406420,(undefined4 *)&DAT_0049e1c8);
    DAT_0049e1d4 = '\x01';
  }
  return &DAT_0049e1d8;
}


