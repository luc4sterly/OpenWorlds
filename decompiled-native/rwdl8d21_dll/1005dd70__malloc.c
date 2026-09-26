// 1005dd70 _malloc [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_10076c74);
  return pvVar1;
}


