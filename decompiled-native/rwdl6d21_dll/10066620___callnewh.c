// 10066620 __callnewh [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  __lock(9);
  if (DAT_1007bcd8 != (code *)0x0) {
    iVar1 = (*DAT_1007bcd8)(_Size);
    if (iVar1 != 0) {
      FUN_10063d20(9);
      return 1;
    }
  }
  FUN_10063d20(9);
  return 0;
}


