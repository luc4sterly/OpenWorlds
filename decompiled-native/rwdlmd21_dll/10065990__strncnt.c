// 10065990 _strncnt [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    _strncnt
   
   Library: Visual Studio 1998 Release */

size_t __cdecl _strncnt(char *_String,size_t _Cnt)

{
  size_t sVar1;
  char *pcVar2;
  
  pcVar2 = _String;
  sVar1 = _Cnt;
  while (sVar1 != 0) {
    sVar1 = sVar1 - 1;
    if (*pcVar2 == '\0') goto LAB_100659b5;
    pcVar2 = pcVar2 + 1;
  }
  if (*pcVar2 == '\0') {
LAB_100659b5:
    _Cnt = (int)pcVar2 - (int)_String;
  }
  return _Cnt;
}


