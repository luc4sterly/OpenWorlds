// 1004ea40 __strdup [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __strdup
   
   Library: Visual Studio 1998 Release */

char * __cdecl __strdup(char *_Src)

{
  size_t sVar1;
  char *_Dest;
  char *pcVar2;
  
  sVar1 = _strlen(_Src);
  _Dest = _malloc(sVar1 + 1);
  pcVar2 = (char *)0x0;
  if (_Dest != (char *)0x0) {
    pcVar2 = FID_conflict___mbscpy(_Dest,_Src);
  }
  return pcVar2;
}


