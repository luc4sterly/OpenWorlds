// 1002ac80 __heap_term [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    __heap_term
   
   Library: Visual Studio 1998 Release */

void __cdecl __heap_term(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_LOOP_10037068;
  do {
    if (ppuVar1[0x204] != (undefined *)0x0) {
      VirtualFree(ppuVar1[0x204],0,0x8000);
    }
    ppuVar1 = (undefined **)*ppuVar1;
  } while (ppuVar1 != &PTR_LOOP_10037068);
  HeapDestroy(DAT_10043564);
  return;
}


