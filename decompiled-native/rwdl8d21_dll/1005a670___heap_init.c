// 1005a670 __heap_init [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    __heap_init
   
   Library: Visual Studio 1998 Release */

int __cdecl __heap_init(void)

{
  undefined **ppuVar1;
  
  DAT_10079414 = HeapCreate(0,0x1000,0);
  if (DAT_10079414 == (HANDLE)0x0) {
    return 0;
  }
  ppuVar1 = ___sbh_new_region();
  if (ppuVar1 == (undefined **)0x0) {
    HeapDestroy(DAT_10079414);
    return 0;
  }
  return 1;
}


