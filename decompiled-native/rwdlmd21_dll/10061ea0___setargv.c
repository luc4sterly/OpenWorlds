// 10061ea0 __setargv [Global]
// programa: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __setargv
   
   Library: Visual Studio 1998 Release */

int __cdecl __setargv(void)

{
  undefined4 *puVar1;
  byte *pbVar2;
  int local_8;
  int local_4;
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_10089ba0,0x104);
  _DAT_100876f0 = &DAT_10089ba0;
  pbVar2 = &DAT_10089ba0;
  if (*DAT_1008b460 != 0) {
    pbVar2 = DAT_1008b460;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_100876d8 = puVar1;
  _DAT_100876d4 = local_8 + -1;
  return local_8 + -1;
}


