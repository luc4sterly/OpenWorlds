// 10047bf0 __mtinitlocks [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 1998 Release */

int __cdecl __mtinitlocks(void)

{
  int extraout_EAX;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005bbec);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005bbdc);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005bbcc);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_1005bbac);
  return extraout_EAX;
}


