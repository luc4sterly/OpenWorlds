// 1002aea0 __ioterm [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    __ioterm
   
   Library: Visual Studio 1998 Release */

void __cdecl __ioterm(void)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = &DAT_10043460;
  do {
    uVar1 = *puVar2;
    if (uVar1 != 0) {
      if (uVar1 < uVar1 + 0x480) {
        do {
          if (*(int *)(uVar1 + 8) != 0) {
            DeleteCriticalSection((LPCRITICAL_SECTION)(uVar1 + 0xc));
          }
          uVar1 = uVar1 + 0x24;
        } while (uVar1 < *puVar2 + 0x480);
      }
      _free((void *)*puVar2);
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 < &DAT_10043560);
  return;
}


