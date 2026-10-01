// 00405295 FUN_00405295 [Global]
// program: run.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00405295(uint param_1)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_0040ba3c = param_1;
  puVar1 = &DAT_0040b7c0;
  do {
    if (param_1 == *puVar1) {
      _DAT_0040ba38 = *(undefined4 *)(iVar2 * 8 + 0x40b7c4);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 1;
  } while (puVar1 < &DAT_0040b928);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    _DAT_0040ba38 = 0xd;
    return;
  }
  if ((param_1 < 0xbc) || (_DAT_0040ba38 = 8, 0xca < param_1)) {
    _DAT_0040ba38 = 0x16;
  }
  return;
}


