// 1002dda0 __mtinitlocks [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 1998 Release */

int __cdecl __mtinitlocks(void)

{
  int extraout_EAX;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10036f64);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10036f54);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10036f44);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10036f24);
  return extraout_EAX;
}


