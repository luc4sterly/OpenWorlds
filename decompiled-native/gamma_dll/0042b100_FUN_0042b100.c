// 0042b100 FUN_0042b100 [Global]
// programa: gamma.dll

uint * FUN_0042b100(void)

{
  uint *puVar1;
  
  puVar1 = DAT_0049ff28;
  if ((DAT_0049ff28 == (uint *)0x0) && (puVar1 = FUN_0044e010(0x10), puVar1 != (uint *)0x0)) {
    FUN_0042b140(puVar1);
  }
  DAT_0049ff28 = puVar1;
  return DAT_0049ff28;
}


