// 10062a60 _tolower [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 1998 Release */

int __cdecl _tolower(int _C)

{
  bool bVar1;
  
  if (DAT_10088740 == 0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      return _C + 0x20;
    }
  }
  else {
    bVar1 = DAT_1008b344 == 0;
    if (bVar1) {
      _DAT_1008b348 = _DAT_1008b348 + 1;
    }
    else {
      __lock(0x13);
    }
    _C = __tolower_lk(_C);
    if (!bVar1) {
      FUN_10064870(0x13);
      return _C;
    }
    _DAT_1008b348 = _DAT_1008b348 + -1;
  }
  return _C;
}


