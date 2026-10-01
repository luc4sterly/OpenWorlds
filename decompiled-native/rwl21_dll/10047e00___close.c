// 10047e00 __close [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    __close
   
   Library: Visual Studio 1998 Release */

int __cdecl __close(int _FileHandle)

{
  int iVar1;
  int *piVar2;
  ulong *puVar3;
  
  if (((uint)_FileHandle < DAT_1005f7d0) &&
     ((*(byte *)(*(int *)((int)&DAT_1005f6d0 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                (_FileHandle & 0x1fU) * 0x24) & 1) != 0)) {
    __lock_fhandle(_FileHandle);
    iVar1 = __close_lk(_FileHandle);
    __unlock_fhandle(_FileHandle);
    return iVar1;
  }
  piVar2 = FUN_100490e0();
  *piVar2 = 9;
  puVar3 = FUN_100490f0();
  *puVar3 = 0;
  return -1;
}


