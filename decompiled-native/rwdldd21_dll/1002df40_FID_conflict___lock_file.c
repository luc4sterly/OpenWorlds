// 1002df40 FID_conflict:__lock_file [Global]
// program: RWDLDD21.DLL

/* Library Function - Multiple Matches With Different Base Names
    __lock_file
    __unlock_file
   
   Library: Visual Studio 1998 Release */

void __cdecl FID_conflict___lock_file(FILE *_File)

{
  if (((FILE *)0x100368b7 < _File) && (_File < (FILE *)0x10036b19)) {
    FUN_1002deb0(((int)&_File[-0x801b46]._base >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


