// 1005fcf0 __callnewh [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  __lock(9);
  if (DAT_10077cd8 != (code *)0x0) {
    iVar1 = (*DAT_10077cd8)(_Size);
    if (iVar1 != 0) {
      FUN_1005d3f0(9);
      return 1;
    }
  }
  FUN_1005d3f0(9);
  return 0;
}


