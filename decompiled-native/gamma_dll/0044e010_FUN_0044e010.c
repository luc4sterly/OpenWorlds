// 0044e010 FUN_0044e010 [Global]
// program: gamma.dll

uint * __cdecl FUN_0044e010(uint param_1)

{
  uint *puVar1;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    while( true ) {
      puVar1 = FUN_00454a10(param_1);
      if (puVar1 != (uint *)0x0) {
        return puVar1;
      }
      if (PTR_FUN_00483080 == (undefined *)0x0) break;
      (*(code *)PTR_FUN_00483080)();
    }
    if (DAT_004830d8 == '\0') break;
    FUN_00451670();
  }
  return (uint *)0x0;
}


