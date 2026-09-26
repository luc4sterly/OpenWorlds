// 10064760 __mtinitlocks [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    __mtinitlocks
   
   Library: Visual Studio 1998 Release */

int __cdecl __mtinitlocks(void)

{
  int extraout_EAX;
  
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10087e14);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10087e04);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10087df4);
  InitializeCriticalSection((LPCRITICAL_SECTION)PTR_DAT_10087dd4);
  return extraout_EAX;
}


