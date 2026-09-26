// 1002b540 setSBCS [Global]
// programa: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_10036600;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_10036710 = 0;
  DAT_10036704 = 0;
  _DAT_10036708 = 0;
  DAT_10036714 = 0;
  DAT_10036718 = 0;
  return;
}


