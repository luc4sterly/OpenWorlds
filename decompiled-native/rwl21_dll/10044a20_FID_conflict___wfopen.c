// 10044a20 FID_conflict:__wfopen [Global]
// programa: RWL21.DLL

/* Library Function - Multiple Matches With Different Base Names
    __wfopen
    _fopen
   
   Library: Visual Studio 1998 Release */

FILE * __cdecl FID_conflict___wfopen(char *_Filename,char *_Mode)

{
  FILE *pFVar1;
  
  pFVar1 = __fsopen(_Filename,_Mode,0x40);
  return pFVar1;
}


