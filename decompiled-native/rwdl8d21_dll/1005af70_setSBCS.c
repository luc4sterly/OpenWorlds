// 1005af70 setSBCS [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_10075708;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_10075818 = 0;
  DAT_1007580c = 0;
  _DAT_10075810 = 0;
  DAT_1007581c = 0;
  DAT_10075820 = 0;
  return;
}


