// 1002d3f0 _tolower [Global]
// program: RWDLDD21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 1998 Release */

int __cdecl _tolower(int _C)

{
  bool bVar1;
  
  if (DAT_10037890 == 0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      return _C + 0x20;
    }
  }
  else {
    bVar1 = DAT_10042440 == 0;
    if (bVar1) {
      _DAT_10042444 = _DAT_10042444 + 1;
    }
    else {
      __lock(0x13);
    }
    _C = __tolower_lk(_C);
    if (!bVar1) {
      FUN_1002deb0(0x13);
      return _C;
    }
    _DAT_10042444 = _DAT_10042444 + -1;
  }
  return _C;
}


