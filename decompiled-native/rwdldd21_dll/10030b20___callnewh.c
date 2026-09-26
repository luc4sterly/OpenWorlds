// 10030b20 __callnewh [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  __lock(9);
  if (DAT_10039228 != (code *)0x0) {
    iVar1 = (*DAT_10039228)(_Size);
    if (iVar1 != 0) {
      FUN_1002deb0(9);
      return 1;
    }
  }
  FUN_1002deb0(9);
  return 0;
}


