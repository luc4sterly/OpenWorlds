// 10044f70 _ungetc [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    _ungetc
   
   Library: Visual Studio 1998 Release */

int __cdecl _ungetc(int _Ch,FILE *_File)

{
  uint uVar1;
  
  __lock_file(_File);
  uVar1 = __ungetc_lk(_Ch,_File);
  __unlock_file(_File);
  return uVar1;
}


