// 00401ae0 _malloc [Global]
// programa: run.exe

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_0040bb94);
  return pvVar1;
}


