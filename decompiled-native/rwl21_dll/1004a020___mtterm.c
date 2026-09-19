// 1004a020 __mtterm [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 1998 Release */

void __cdecl __mtterm(void)

{
  __mtdeletelocks();
  if (DAT_1005c704 != 0xffffffff) {
    TlsFree(DAT_1005c704);
    DAT_1005c704 = 0xffffffff;
  }
  return;
}


