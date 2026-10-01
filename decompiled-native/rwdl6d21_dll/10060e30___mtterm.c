// 10060e30 __mtterm [Global]
// program: RWDL6D21.DLL

/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 1998 Release */

void __cdecl __mtterm(void)

{
  __mtdeletelocks();
  if (DAT_100796d4 != 0xffffffff) {
    TlsFree(DAT_100796d4);
    DAT_100796d4 = 0xffffffff;
  }
  return;
}


