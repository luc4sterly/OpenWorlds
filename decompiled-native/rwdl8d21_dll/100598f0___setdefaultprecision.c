// 100598f0 __setdefaultprecision [Global]
// programa: RWDL8D21.DLL

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Release */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


