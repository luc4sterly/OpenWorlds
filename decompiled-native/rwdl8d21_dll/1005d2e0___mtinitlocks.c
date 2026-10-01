// 1005d2e0 __mtinitlocks [Global]
// program: RWDL8D21.DLL

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 1998 Release */

int __cdecl __mtinitlocks(void)

{
  int extraout_EAX;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10075de4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10075dd4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10075dc4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10075da4);
  return extraout_EAX;
}


