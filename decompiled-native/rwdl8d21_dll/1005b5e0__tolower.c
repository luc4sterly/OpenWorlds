// 1005b5e0 _tolower [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 1998 Release */

int __cdecl _tolower(int _C)

{
  bool bVar1;
  
  if (DAT_10076710 == 0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      return _C + 0x20;
    }
  }
  else {
    bVar1 = DAT_10079304 == 0;
    if (bVar1) {
      _DAT_10079308 = _DAT_10079308 + 1;
    }
    else {
      __lock(0x13);
    }
    _C = __tolower_lk(_C);
    if (!bVar1) {
      FUN_1005d3f0(0x13);
      return _C;
    }
    _DAT_10079308 = _DAT_10079308 + -1;
  }
  return _C;
}


