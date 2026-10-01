// 00454b80 FUN_00454b80 [Global]
// program: gamma.dll

uint * FUN_00454b80(void)

{
  uint *puVar1;
  int iVar2;
  uint *unaff_EBP;
  uint *puVar3;
  
  for (puVar1 = (uint *)PTR_DAT_00482560; puVar1 != (uint *)0x0; puVar1 = (uint *)puVar1[0x14]) {
    if (((ushort)puVar1[1] >> 7 & 7) == 0) {
      return puVar1;
    }
    unaff_EBP = puVar1;
  }
  puVar1 = FUN_00454a10(0x54);
  if (puVar1 != (uint *)0x0) {
    puVar3 = puVar1;
    for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    *(undefined1 *)(puVar1 + 4) = 1;
    unaff_EBP[0x14] = (uint)puVar1;
    return puVar1;
  }
  return (uint *)0x0;
}


