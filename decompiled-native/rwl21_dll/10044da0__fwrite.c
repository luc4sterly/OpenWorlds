// 10044da0 _fwrite [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    _fwrite
   
   Library: Visual Studio 1998 Release */

size_t __cdecl _fwrite(void *_Str,size_t _Size,size_t _Count,FILE *_File)

{
  uint uVar1;
  
  __lock_file(_File);
  uVar1 = __fwrite_lk(_Str,_Size,_Count,_File);
  __unlock_file(_File);
  return uVar1;
}


