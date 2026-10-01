// 10047d20 __lock_file [Global]
// program: RWL21.DLL

/* Library Function - Multiple Matches With Different Base Names
    __lock_file
    __unlock_file
   
   Library: Visual Studio 1998 Release */

void __cdecl __lock_file(FILE *_File)

{
  if (((FILE *)0x1005ca1f < _File) && (_File < (FILE *)0x1005cc81)) {
    __lock(((int)(_File + -0x802e51) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


