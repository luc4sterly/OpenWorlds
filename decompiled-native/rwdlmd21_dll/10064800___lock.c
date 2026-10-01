// 10064800 __lock [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    __lock
   
   Library: Visual Studio 1998 Release */

void __cdecl __lock(int _File)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = &DAT_10087dd0 + _File;
  if (*piVar1 == 0) {
    lpCriticalSection = _malloc(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    __lock(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      _free(lpCriticalSection);
    }
    FUN_10064870(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}


