// 10064e40 _strncnt [Global]
// program: RWDL6D21.DLL

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
    if (*pcVar2 == '\0') goto LAB_10064e65;
    pcVar2 = pcVar2 + 1;
  }
  if (*pcVar2 == '\0') {
LAB_10064e65:
    _Cnt = (int)pcVar2 - (int)_String;
  }
  return _Cnt;
}


