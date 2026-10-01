// 1004a370 __ioterm [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __ioterm
   
   Library: Visual Studio 1998 Release */

void __cdecl __ioterm(void)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = &DAT_1005f6d0;
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
  } while (puVar2 < &DAT_1005f7d0);
  return;
}


