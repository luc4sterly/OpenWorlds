// 1002f7b0 __set_errno [Global]
// program: RWDLDD21.DLL

/* Library Function - Single Match
    __set_errno
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __set_errno(int _Value)

{
  int *piVar1;
  
  if (_Value == 1) {
    piVar1 = FUN_1002eb20();
    *piVar1 = 0x21;
    return (errno_t)piVar1;
  }
  if (1 < _Value) {
    if (3 < _Value) {
      return _Value;
    }
    _Value = (int)FUN_1002eb20();
    *(int *)_Value = 0x22;
  }
  return _Value;
}


