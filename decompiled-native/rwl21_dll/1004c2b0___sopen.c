// 1004c2b0 __sopen [Global]
// programa: RWL21.DLL

/* Library Function - Single Match
    __sopen
   
   Library: Visual Studio 1998 Release */

int __cdecl __sopen(char *_Filename,int _OpenFlag,int _ShareFlag,...)

{
  byte *pbVar1;
  uint uVar2;
  int *piVar3;
  ulong *puVar4;
  HANDLE hFile;
  int iVar5;
  byte bVar6;
  DWORD DVar7;
  bool bVar8;
  uint in_stack_00000010;
  char local_19;
  DWORD local_18;
  uint local_14;
  DWORD local_10;
  _SECURITY_ATTRIBUTES local_c;
  
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  local_c.nLength = 0xc;
  bVar8 = (_OpenFlag & 0x80U) == 0;
  if (bVar8) {
    bVar6 = 0;
  }
  else {
    bVar6 = 0x10;
  }
  local_c.bInheritHandle = (BOOL)bVar8;
  if (((_OpenFlag & 0x8000U) == 0) && (((_OpenFlag & 0x4000U) != 0 || (DAT_1005cf34 != 0x8000)))) {
    bVar6 = bVar6 | 0x80;
  }
  uVar2 = _OpenFlag & 3;
  if (uVar2 == 0) {
    local_14 = 0x80000000;
  }
  else if (uVar2 == 1) {
    local_14 = 0x40000000;
  }
  else {
    if (uVar2 != 2) {
      piVar3 = FUN_100490e0();
      *piVar3 = 0x16;
      puVar4 = FUN_100490f0();
      *puVar4 = 0;
      return -1;
    }
    local_14 = 0xc0000000;
  }
  switch(_ShareFlag) {
  case 0x10:
    local_18 = 0;
    break;
  default:
    piVar3 = FUN_100490e0();
    *piVar3 = 0x16;
    puVar4 = FUN_100490f0();
    *puVar4 = 0;
    return -1;
  case 0x20:
    local_18 = 1;
    break;
  case 0x30:
    local_18 = 2;
    break;
  case 0x40:
    local_18 = 3;
  }
  uVar2 = _OpenFlag & 0x700;
  if (uVar2 < 0x101) {
    if (uVar2 == 0x100) {
      local_10 = 4;
      goto LAB_1004c451;
    }
    if (uVar2 != 0) goto LAB_1004c3fe;
LAB_1004c421:
    local_10 = 3;
    goto LAB_1004c451;
  }
  if (uVar2 < 0x301) {
    if (uVar2 == 0x300) {
      local_10 = 2;
      goto LAB_1004c451;
    }
    if (uVar2 != 0x200) goto LAB_1004c3fe;
LAB_1004c435:
    local_10 = 5;
  }
  else {
    if (uVar2 < 0x501) {
      if (uVar2 != 0x500) {
        if (uVar2 != 0x400) {
LAB_1004c3fe:
          piVar3 = FUN_100490e0();
          *piVar3 = 0x16;
          puVar4 = FUN_100490f0();
          *puVar4 = 0;
          return -1;
        }
        goto LAB_1004c421;
      }
    }
    else {
      if (uVar2 == 0x600) goto LAB_1004c435;
      if (uVar2 != 0x700) goto LAB_1004c3fe;
    }
    local_10 = 1;
  }
LAB_1004c451:
  DVar7 = 0x80;
  if (((_OpenFlag & 0x100U) != 0) && ((~DAT_1005be98 & in_stack_00000010 & 0x80) == 0)) {
    DVar7 = 1;
  }
  if ((_OpenFlag & 0x40U) != 0) {
    local_14 = local_14 | 0x10000;
    DVar7 = DVar7 | 0x4000000;
  }
  if ((_OpenFlag & 0x1000U) != 0) {
    DVar7 = DVar7 | 0x100;
  }
  if ((_OpenFlag & 0x20U) == 0) {
    if ((_OpenFlag & 0x10U) != 0) {
      DVar7 = DVar7 | 0x10000000;
    }
  }
  else {
    DVar7 = DVar7 | 0x8000000;
  }
  uVar2 = __alloc_osfhnd();
  if (uVar2 == 0xffffffff) {
    piVar3 = FUN_100490e0();
    *piVar3 = 0x18;
    puVar4 = FUN_100490f0();
    *puVar4 = 0;
    return -1;
  }
  hFile = CreateFileA(_Filename,local_14,local_18,&local_c,local_10,DVar7,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    DVar7 = GetLastError();
    __dosmaperr(DVar7);
    __unlock_fhandle(uVar2);
    return -1;
  }
  DVar7 = GetFileType(hFile);
  if (DVar7 == 0) {
    CloseHandle(hFile);
    DVar7 = GetLastError();
    __dosmaperr(DVar7);
    __unlock_fhandle(uVar2);
    return -1;
  }
  if (DVar7 == 2) {
    bVar6 = bVar6 | 0x40;
  }
  else if (DVar7 == 3) {
    bVar6 = bVar6 | 8;
  }
  __set_osfhnd(uVar2,(intptr_t)hFile);
  piVar3 = (int *)((int)&DAT_1005f6d0 + ((int)(uVar2 & 0xffffffe7) >> 3));
  local_14 = (uVar2 & 0x1f) * 0x24;
  *(byte *)(*piVar3 + 4 + local_14) = bVar6 | 1;
  local_18 = CONCAT31(local_18._1_3_,bVar6) & 0xffffff48;
  if ((((bVar6 & 0x48) == 0) && ((bVar6 & 0x80) != 0)) && ((_OpenFlag & 2U) != 0)) {
    DVar7 = __lseek_lk(uVar2,-1,2);
    if (DVar7 == 0xffffffff) {
      puVar4 = FUN_100490f0();
      if (*puVar4 != 0x83) {
        __close(uVar2);
        __unlock_fhandle(uVar2);
        return -1;
      }
    }
    else {
      local_19 = '\0';
      iVar5 = __read_lk(uVar2,&local_19,1);
      if (((iVar5 == 0) && (local_19 == '\x1a')) && (iVar5 = __chsize_lk(), iVar5 == -1)) {
        __close(uVar2);
        __unlock_fhandle(uVar2);
        return -1;
      }
      DVar7 = __lseek_lk(uVar2,0,0);
      if (DVar7 == 0xffffffff) {
        __close(uVar2);
        __unlock_fhandle(uVar2);
        return -1;
      }
    }
  }
  if (((char)local_18 == '\0') && ((_OpenFlag & 8U) != 0)) {
    pbVar1 = (byte *)(*piVar3 + 4 + local_14);
    *pbVar1 = *pbVar1 | 0x20;
  }
  __unlock_fhandle(uVar2);
  return uVar2;
}


