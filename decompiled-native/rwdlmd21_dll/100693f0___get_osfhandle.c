// 100693f0 __get_osfhandle [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 1998 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  intptr_t *piVar1;
  int *piVar2;
  ulong *puVar3;
  
  if (((uint)_FileHandle < DAT_1008b450) &&
     (piVar1 = (intptr_t *)
               (*(int *)((int)&DAT_1008b350 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) +
               (_FileHandle & 0x1fU) * 0x24), (*(byte *)(piVar1 + 1) & 1) != 0)) {
    return *piVar1;
  }
  piVar2 = FUN_10067230();
  *piVar2 = 9;
  puVar3 = FUN_10067240();
  *puVar3 = 0;
  return -1;
}


