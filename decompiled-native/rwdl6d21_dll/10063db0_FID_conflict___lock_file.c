// 10063db0 FID_conflict:__lock_file [Global]
// programa: RWDL6D21.DLL

/* Library Function - Multiple Matches With Different Base Names
    __lock_file
    __unlock_file
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lock_file(FILE *_File)

{
  if (((FILE *)0x1007a9ef < _File) && (_File < (FILE *)0x1007ac51)) {
    FUN_10063d20(((int)&_File[-0x803d50]._file >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


