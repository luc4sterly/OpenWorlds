// 10049f80 __callnewh [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  __lock(9);
  if (DAT_1005e4e8 != (code *)0x0) {
    iVar1 = (*DAT_1005e4e8)(_Size);
    if (iVar1 != 0) {
      FUN_10047d00(9);
      return 1;
    }
  }
  FUN_10047d00(9);
  return 0;
}


