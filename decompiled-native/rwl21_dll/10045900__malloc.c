// 10045900 _malloc [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 1998 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_1005c700);
  return pvVar1;
}


