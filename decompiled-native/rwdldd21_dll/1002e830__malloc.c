// 1002e830 _malloc [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_10037cd0);
  return pvVar1;
}


