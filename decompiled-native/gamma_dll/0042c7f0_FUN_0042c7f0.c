// 0042c7f0 FUN_0042c7f0 [Global]
// program: gamma.dll

uint * FUN_0042c7f0(void)

{
  uint *puVar1;
  
  puVar1 = DAT_0049ff24;
  if ((DAT_0049ff24 == (uint *)0x0) && (puVar1 = FUN_0044e010(0xf8), puVar1 != (uint *)0x0)) {
    FUN_0042c830(puVar1);
  }
  DAT_0049ff24 = puVar1;
  return DAT_0049ff24;
}


