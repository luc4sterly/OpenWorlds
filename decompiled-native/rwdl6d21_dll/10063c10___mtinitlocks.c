// 10063c10 __mtinitlocks [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 1998 Release */

int __cdecl __mtinitlocks(void)

{
  int extraout_EAX;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10079de4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10079dd4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10079dc4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10079da4);
  return extraout_EAX;
}


