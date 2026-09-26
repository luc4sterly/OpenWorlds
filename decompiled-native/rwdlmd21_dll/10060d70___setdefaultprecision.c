// 10060d70 __setdefaultprecision [Global]
// programa: rwdlmd21.dll

/* Library Function - Single Match
    __setdefaultprecision
   
   Library: Visual Studio 1998 Release */

void __setdefaultprecision(void)

{
  __controlfp(0x10000,0x30000);
  return;
}


