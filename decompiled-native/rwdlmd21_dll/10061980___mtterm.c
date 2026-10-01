// 10061980 __mtterm [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 1998 Release */

void __cdecl __mtterm(void)

{
  __mtdeletelocks();
  if (DAT_10087704 != 0xffffffff) {
    TlsFree(DAT_10087704);
    DAT_10087704 = 0xffffffff;
  }
  return;
}


