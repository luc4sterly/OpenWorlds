// 100688a0 __get_osfhandle [Global]
// programa: RWDL6D21.DLL

/* Library Function - Single Match
    __get_osfhandle
   
   Library: Visual Studio 1998 Release */

intptr_t __cdecl __get_osfhandle(int _FileHandle)

{
  intptr_t *piVar1;
  int *piVar2;
  ulong *puVar3;
  
  if (((uint)_FileHandle < DAT_1007d410) &&
     (piVar1 = (intptr_t *)
               (*(int *)((int)&DAT_1007d310 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) +
               (_FileHandle & 0x1fU) * 0x24), (*(byte *)(piVar1 + 1) & 1) != 0)) {
    return *piVar1;
  }
  piVar2 = FUN_100666e0();
  *piVar2 = 9;
  puVar3 = FUN_100666f0();
  *puVar3 = 0;
  return -1;
}


