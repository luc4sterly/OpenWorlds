// 1005a500 __mtterm [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 1998 Release */

void __cdecl __mtterm(void)

{
  __mtdeletelocks();
  if (DAT_100756d4 != 0xffffffff) {
    TlsFree(DAT_100756d4);
    DAT_100756d4 = 0xffffffff;
  }
  return;
}


