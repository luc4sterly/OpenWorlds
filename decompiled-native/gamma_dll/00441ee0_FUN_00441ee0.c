// 00441ee0 FUN_00441ee0 [Global]
// program: gamma.dll

uint * FUN_00441ee0(void)

{
  uint *puVar1;
  
  puVar1 = FUN_0044e010(0xc);
  if (puVar1 != (uint *)0x0) {
    *puVar1 = (uint)&DAT_00477514;
    *puVar1 = (uint)&DAT_004774f0;
    *puVar1 = (uint)&PTR_FUN_00478d28;
    puVar1[1] = 1;
    FUN_0040aac0();
  }
  return puVar1;
}


