// 1004e980 __mbschr [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __mbschr
   
   Library: Visual Studio 1998 Release */

uchar * __cdecl __mbschr(uchar *_Str,uint _Ch)

{
  byte bVar1;
  uchar *puVar2;
  
  if (DAT_1005c834 == 0) {
    puVar2 = (uchar *)_strchr((char *)_Str,_Ch);
    return puVar2;
  }
  __lock(0x19);
  bVar1 = *_Str;
  while (bVar1 != 0) {
    if ((*(byte *)((int)&DAT_1005c730 + bVar1 + 1) & 4) == 0) {
      puVar2 = _Str;
      if ((ushort)bVar1 == _Ch) break;
    }
    else {
      if (_Str[1] == '\0') {
        FUN_10047d00(0x19);
        return (uchar *)0x0;
      }
      puVar2 = _Str + 1;
      if (CONCAT11(bVar1,_Str[1]) == _Ch) {
        FUN_10047d00(0x19);
        return _Str;
      }
    }
    _Str = puVar2 + 1;
    bVar1 = puVar2[1];
  }
  FUN_10047d00(0x19);
  return (uchar *)(-(uint)((ushort)bVar1 == _Ch) & (uint)_Str);
}


