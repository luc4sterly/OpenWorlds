// 0042fc50 FUN_0042fc50 [Global]
// program: gamma.dll

uint * FUN_0042fc50(void)

{
  if ((DAT_0049ff20 == (uint *)0x0) &&
     (DAT_0049ff20 = FUN_0044e010(0xc), DAT_0049ff20 != (uint *)0x0)) {
    *DAT_0049ff20 = 0;
    DAT_0049ff20[1] = 0;
    DAT_0049ff20[2] = 0;
  }
  return DAT_0049ff20;
}


