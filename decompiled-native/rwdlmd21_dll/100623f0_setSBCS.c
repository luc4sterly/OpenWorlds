// 100623f0 setSBCS [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_10087738;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_10087848 = 0;
  DAT_1008783c = 0;
  _DAT_10087840 = 0;
  DAT_1008784c = 0;
  DAT_10087850 = 0;
  return;
}


