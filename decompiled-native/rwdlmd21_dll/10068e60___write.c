// 10068e60 __write [Global]
// program: rwdlmd21.dll

/* Library Function - Single Match
    __write
   
   Library: Visual Studio 1998 Release */

int __cdecl __write(int _FileHandle,void *_Buf,uint _MaxCharCount)

{
  int iVar1;
  int *piVar2;
  ulong *puVar3;
  
  if (((uint)_FileHandle < DAT_1008b450) &&
     ((*(byte *)(*(int *)((int)&DAT_1008b350 + ((int)(_FileHandle & 0xffffffe7U) >> 3)) + 4 +
                (_FileHandle & 0x1fU) * 0x24) & 1) != 0)) {
    __lock_fhandle(_FileHandle);
    iVar1 = __write_lk(_FileHandle,_Buf,_MaxCharCount);
    __unlock_fhandle(_FileHandle);
    return iVar1;
  }
  piVar2 = FUN_10067230();
  *piVar2 = 9;
  puVar3 = FUN_10067240();
  *puVar3 = 0;
  return -1;
}


