// 10064900 FID_conflict:__lock_file [Global]
// program: rwdlmd21.dll

/* Library Function - Multiple Matches With Different Base Names
    __lock_file
    __unlock_file
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lock_file(FILE *_File)

{
  if (((FILE *)0x10088a1f < _File) && (_File < (FILE *)0x10088c81)) {
    FUN_10064870(((int)(_File + -0x804451) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


