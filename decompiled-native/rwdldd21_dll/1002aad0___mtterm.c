// 1002aad0 __mtterm [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    __mtterm
   
   Library: Visual Studio 1998 Release */

void __cdecl __mtterm(void)

{
  __mtdeletelocks();
  if (DAT_100365cc != 0xffffffff) {
    TlsFree(DAT_100365cc);
    DAT_100365cc = 0xffffffff;
  }
  return;
}


