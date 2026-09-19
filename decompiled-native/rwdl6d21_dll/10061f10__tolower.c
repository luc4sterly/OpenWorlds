// 10061f10 _tolower [Global]
// programa: RWDL6D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    _tolower
   
   Library: Visual Studio 1998 Release */

int __cdecl _tolower(int _C)

{
  bool bVar1;
  
  if (DAT_1007a710 == 0) {
    if ((0x40 < _C) && (_C < 0x5b)) {
      return _C + 0x20;
    }
  }
  else {
    bVar1 = DAT_1007d304 == 0;
    if (bVar1) {
      _DAT_1007d308 = _DAT_1007d308 + 1;
    }
    else {
      __lock(0x13);
    }
    _C = __tolower_lk(_C);
    if (!bVar1) {
      FUN_10063d20(0x13);
      return _C;
    }
    _DAT_1007d308 = _DAT_1007d308 + -1;
  }
  return _C;
}


