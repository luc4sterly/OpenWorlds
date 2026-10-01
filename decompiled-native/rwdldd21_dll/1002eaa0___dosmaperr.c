// 1002eaa0 __dosmaperr [Global]
// program: RWDLDD21.DLL

/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 1998 Release */

void __cdecl __dosmaperr(ulong param_1)

{
  ulong *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = FUN_1002eb30();
  iVar3 = 0;
  *puVar1 = param_1;
  puVar1 = &DAT_100378b0;
  do {
    if (*puVar1 == param_1) {
      piVar2 = FUN_1002eb20();
      *piVar2 = *(int *)(iVar3 * 8 + 0x100378b4);
      return;
    }
    puVar1 = puVar1 + 2;
    iVar3 = iVar3 + 1;
  } while (puVar1 < &DAT_10037a18);
  if ((0x12 < param_1) && (param_1 < 0x25)) {
    piVar2 = FUN_1002eb20();
    *piVar2 = 0xd;
    return;
  }
  if ((0xbb < param_1) && (param_1 < 0xcb)) {
    piVar2 = FUN_1002eb20();
    *piVar2 = 8;
    return;
  }
  piVar2 = FUN_1002eb20();
  *piVar2 = 0x16;
  return;
}


