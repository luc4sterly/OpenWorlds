// 10067170 __callnewh [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 1998 Release */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  __lock(9);
  if (DAT_10089d08 != (code *)0x0) {
    iVar1 = (*DAT_10089d08)(_Size);
    if (iVar1 != 0) {
      FUN_10064870(9);
      return 1;
    }
  }
  FUN_10064870(9);
  return 0;
}


