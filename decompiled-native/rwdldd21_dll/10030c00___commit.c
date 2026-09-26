// 10030c00 __commit [Global]
// programa: RWDLDD21.DLL

/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 1998 Release */

int __cdecl __commit(int _FileHandle)

{
  HANDLE hFile;
  BOOL BVar1;
  ulong *puVar2;
  int *piVar3;
  DWORD DVar4;
  int iVar5;
  
  if (DAT_10043560 <= (uint)_FileHandle) {
LAB_10030c8e:
    piVar3 = FUN_1002eb20();
    *piVar3 = 9;
    return -1;
  }
  piVar3 = (int *)((int)&DAT_10043460 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
  iVar5 = (_FileHandle & 0x1fU) * 0x24;
  if ((*(byte *)(*piVar3 + 4 + iVar5) & 1) == 0) goto LAB_10030c8e;
  __lock_fhandle(_FileHandle);
  if ((*(byte *)(*piVar3 + 4 + iVar5) & 1) != 0) {
    DVar4 = 0;
    hFile = (HANDLE)__get_osfhandle(_FileHandle);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar4 = GetLastError();
    }
    iVar5 = 0;
    if (DVar4 == 0) goto LAB_10030c7f;
    puVar2 = FUN_1002eb30();
    *puVar2 = DVar4;
  }
  iVar5 = -1;
  piVar3 = FUN_1002eb20();
  *piVar3 = 9;
LAB_10030c7f:
  __unlock_fhandle(_FileHandle);
  return iVar5;
}


