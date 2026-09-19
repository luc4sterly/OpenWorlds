// 10044c10 _fread [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    _fread
   
   Library: Visual Studio 1998 Release */

size_t __cdecl _fread(void *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File)

{
  uint uVar1;
  
  __lock_file(_File);
  uVar1 = __fread_lk(_DstBuf,_ElementSize,_Count,_File);
  __unlock_file(_File);
  return uVar1;
}


