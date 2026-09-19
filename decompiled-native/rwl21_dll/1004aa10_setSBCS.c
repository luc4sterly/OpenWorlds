// 1004aa10 setSBCS [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 1998 Release */

void __cdecl setSBCS(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_1005c730;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)puVar2 = 0;
  DAT_1005c840 = 0;
  DAT_1005c834 = 0;
  DAT_1005c838 = 0;
  DAT_1005c844 = 0;
  DAT_1005c848 = 0;
  return;
}


