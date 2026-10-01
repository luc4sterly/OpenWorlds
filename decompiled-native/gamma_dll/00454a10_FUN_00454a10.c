// 00454a10 FUN_00454a10 [Global]
// program: gamma.dll

uint * __cdecl FUN_00454a10(uint param_1)

{
  uint *puVar1;
  
  if (param_1 == 0) {
    return (uint *)0x0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee40);
  if (param_1 < 0x45) {
    puVar1 = (uint *)FUN_004548e0(param_1);
  }
  else {
    puVar1 = FUN_00454710(param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0049ee40);
  return puVar1;
}


