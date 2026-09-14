// 00453d80 FUN_00453d80 [Global]
// programa: gamma.dll

undefined4 FUN_00453d80(void)

{
  if (DAT_00482370 != -1) {
    return 1;
  }
  DAT_00482370 = TlsAlloc();
  if (DAT_00482370 == 0xffffffff) {
    return 0;
  }
  return 1;
}


