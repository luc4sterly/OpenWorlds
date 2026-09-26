// 1002aff0 __setargv [Global]
// programa: RWDLDD21.DLL

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_100390c0,0x104);
  _DAT_100365b8 = &DAT_100390c0;
  pbVar2 = &DAT_100390c0;
  if (*DAT_10043570 != 0) {
    pbVar2 = DAT_10043570;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_100365a0 = puVar1;
  _DAT_1003659c = local_8 + -1;
  return local_8 + -1;
}


