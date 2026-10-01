// 1004bab0 _wctomb [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _wctomb
   
   Library: Visual Studio 1998 Release */

int __cdecl _wctomb(char *_MbCh,wchar_t _WCh)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = DAT_1005e6b4 == 0;
  if (bVar2) {
    _DAT_1005e6b8 = _DAT_1005e6b8 + 1;
  }
  else {
    __lock(0x13);
  }
  iVar1 = __wctomb_lk(_MbCh,_WCh);
  if (!bVar2) {
    FUN_10047d00(0x13);
    return iVar1;
  }
  _DAT_1005e6b8 = _DAT_1005e6b8 + -1;
  return iVar1;
}


