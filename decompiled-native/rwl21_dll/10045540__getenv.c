// 10045540 _getenv [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    _getenv
   
   Library: Visual Studio 1998 Release */

char * __cdecl _getenv(char *_VarName)

{
  char *pcVar1;
  
  __lock(0xc);
  pcVar1 = (char *)__getenv_lk((uchar *)_VarName);
  FUN_10047d00(0xc);
  return pcVar1;
}


