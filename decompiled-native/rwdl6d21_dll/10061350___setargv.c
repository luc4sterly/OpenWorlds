// 10061350 __setargv [Global]
// program: RWDL6D21.DLL

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
  
  GetModuleFileNameA((HMODULE)0x0,&DAT_1007bb70,0x104);
  _DAT_100796c0 = &DAT_1007bb70;
  pbVar2 = &DAT_1007bb70;
  if (*DAT_1007d420 != 0) {
    pbVar2 = DAT_1007d420;
  }
  parse_cmdline(pbVar2,(undefined4 *)0x0,(byte *)0x0,&local_8,&local_4);
  puVar1 = _malloc(local_8 * 4 + local_4);
  if (puVar1 == (undefined4 *)0x0) {
    __amsg_exit(8);
  }
  parse_cmdline(pbVar2,puVar1,(byte *)(puVar1 + local_8),&local_8,&local_4);
  _DAT_100796a8 = puVar1;
  _DAT_100796a4 = local_8 + -1;
  return local_8 + -1;
}


