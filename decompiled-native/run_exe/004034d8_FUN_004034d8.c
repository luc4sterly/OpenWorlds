// 004034d8 FUN_004034d8 [Global]
// program: run.exe

void FUN_004034d8(void)

{
  if ((DAT_0040ba34 == 1) || ((DAT_0040ba34 == 0 && (DAT_004091a8 == 1)))) {
    FUN_00403511((undefined *)0xfc);
    if (DAT_0040bb90 != (code *)0x0) {
      (*DAT_0040bb90)();
    }
    FUN_00403511((undefined *)0xff);
  }
  return;
}


