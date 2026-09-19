// 1004e860 __set_errno [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __set_errno
   
   Library: Visual Studio 1998 Release */

errno_t __cdecl __set_errno(int _Value)

{
  int *piVar1;
  
  if (_Value == 1) {
    piVar1 = FUN_100490e0();
    *piVar1 = 0x21;
    return (errno_t)piVar1;
  }
  if (1 < _Value) {
    if (3 < _Value) {
      return _Value;
    }
    _Value = (int)FUN_100490e0();
    *(int *)_Value = 0x22;
  }
  return _Value;
}


