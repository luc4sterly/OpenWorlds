// 10047d90 __unlock_file [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __unlock_file
   
   Library: Visual Studio 1998 Release */

void __cdecl __unlock_file(FILE *_File)

{
  if (((FILE *)0x1005ca1f < _File) && (_File < (FILE *)0x1005cc81)) {
    FUN_10047d00(((int)(_File + -0x802e51) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(_File + 1));
  return;
}


