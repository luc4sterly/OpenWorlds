// 1005d480 FID_conflict:__lock_file [Global]
// program: RWDL8D21.DLL

/* Library Function - Multiple Matches With Different Base Names
    __lock_file
    __unlock_file
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lock_file(FILE *_File)

{
  if (((FILE *)0x100769ef < _File) && (_File < (FILE *)0x10076c51)) {
    FUN_1005d3f0(((int)&_File[-0x803b50]._file >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


