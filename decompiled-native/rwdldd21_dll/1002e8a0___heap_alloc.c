// 1002e8a0 __heap_alloc [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    __heap_alloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl __heap_alloc(size_t _Size)

{
  undefined *puVar1;
  LPVOID pvVar2;
  uint dwBytes;
  
  dwBytes = _Size + 0xf & 0xfffffff0;
  if (dwBytes <= DAT_10037884) {
    __lock(9);
    puVar1 = ___sbh_alloc_block(_Size + 0xf >> 4);
    FUN_1002deb0(9);
    if (puVar1 != (undefined *)0x0) {
      return puVar1;
    }
  }
  pvVar2 = HeapAlloc(DAT_10043564,0,dwBytes);
  return pvVar2;
}


