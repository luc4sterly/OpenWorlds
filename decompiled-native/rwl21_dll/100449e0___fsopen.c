// 100449e0 __fsopen [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __fsopen
   
   Library: Visual Studio 1998 Release */

FILE * __cdecl __fsopen(char *_Filename,char *_Mode,int _ShFlag)

{
  FILE *_File;
  FILE *pFVar1;
  
  _File = __getstream();
  if (_File == (FILE *)0x0) {
    return (FILE *)0x0;
  }
  pFVar1 = __openfile(_Filename,_Mode,_ShFlag,_File);
  __unlock_file(_File);
  return pFVar1;
}


