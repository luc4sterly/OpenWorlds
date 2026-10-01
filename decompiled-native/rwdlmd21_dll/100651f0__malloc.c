// 100651f0 _malloc [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_10088ca4);
  return pvVar1;
}


