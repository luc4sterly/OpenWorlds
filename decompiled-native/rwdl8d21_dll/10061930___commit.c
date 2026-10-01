// 10061930 __commit [Global]
// program: RWDL8D21.DLL

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
  
  if (DAT_10079410 <= (uint)_FileHandle) {
LAB_100619be:
    piVar3 = FUN_1005fdb0();
    *piVar3 = 9;
    return -1;
  }
  piVar3 = (int *)((int)&DAT_10079310 + ((int)(_FileHandle & 0xffffffe7U) >> 3));
  iVar5 = (_FileHandle & 0x1fU) * 0x24;
  if ((*(byte *)(*piVar3 + 4 + iVar5) & 1) == 0) goto LAB_100619be;
  __lock_fhandle(_FileHandle);
  if ((*(byte *)(*piVar3 + 4 + iVar5) & 1) != 0) {
    DVar4 = 0;
    hFile = (HANDLE)__get_osfhandle(_FileHandle);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      DVar4 = GetLastError();
    }
    iVar5 = 0;
    if (DVar4 == 0) goto LAB_100619af;
    puVar2 = FUN_1005fdc0();
    *puVar2 = DVar4;
  }
  iVar5 = -1;
  piVar3 = FUN_1005fdb0();
  *piVar3 = 9;
LAB_100619af:
  __unlock_fhandle(_FileHandle);
  return iVar5;
}


