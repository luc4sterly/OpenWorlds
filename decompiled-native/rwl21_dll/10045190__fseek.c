// 10045190 _fseek [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _fseek
   
   Library: Visual Studio 1998 Release */

int __cdecl _fseek(FILE *_File,long _Offset,int _Origin)

{
  int iVar1;
  
  __lock_file(_File);
  iVar1 = __fseek_lk(_File,_Offset,_Origin);
  __unlock_file(_File);
  return iVar1;
}


