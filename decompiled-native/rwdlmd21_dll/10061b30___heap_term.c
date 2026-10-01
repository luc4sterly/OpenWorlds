// 10061b30 __heap_term [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    __heap_term
   
   Library: Visual Studio 1998 Release */

void __cdecl __heap_term(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_LOOP_10087f18;
  do {
    if (ppuVar1[0x204] != (undefined *)0x0) {
      VirtualFree(ppuVar1[0x204],0,0x8000);
    }
    ppuVar1 = (undefined **)*ppuVar1;
  } while (ppuVar1 != &PTR_LOOP_10087f18);
  HeapDestroy(DAT_1008b454);
  return;
}


