// 004578f0 FUN_004578f0 [Global]
// programa: gamma.dll

undefined4 __cdecl FUN_004578f0(byte *param_1,undefined2 *param_2)

{
  byte bVar1;
  short sVar2;
  BOOL BVar3;
  HANDLE hFindFile;
  LPVOID pvVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  FILETIME *lpFileTime;
  _WIN32_FIND_DATAA local_1c0;
  DWORD local_80;
  DWORD local_7c;
  DWORD local_78;
  DWORD local_74;
  DWORD local_70;
  DWORD local_6c;
  FILETIME local_68;
  _SYSTEMTIME local_60;
  undefined2 *local_50 [3];
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  DWORD local_20;
  DWORD local_1c;
  DWORD local_18;
  DWORD local_14;
  
  uVar8 = 0;
  do {
    iVar7 = -1;
    pbVar9 = param_1;
    do {
      if (iVar7 == 0) break;
      iVar7 = iVar7 + -1;
      bVar1 = *pbVar9;
      pbVar9 = pbVar9 + 1;
    } while (bVar1 != 0);
    if (-iVar7 - 2U < uVar8) {
      iVar7 = -1;
      pbVar9 = param_1;
      break;
    }
    if ((param_1[uVar8] == 0x2a) || (param_1[uVar8] == 0x3f)) {
      pvVar4 = FUN_00453ed0();
      *(undefined4 *)((int)pvVar4 + 4) = 6;
      return 0xffffffff;
    }
    uVar8 = uVar8 + 1;
  } while( true );
  while( true ) {
    iVar7 = iVar7 + -1;
    bVar1 = *pbVar9;
    pbVar9 = pbVar9 + 1;
    if (bVar1 == 0) break;
    if (iVar7 == 0) break;
  }
  if (((-iVar7 - 2U < 4) && (param_1[1] == 0x3a)) && ((param_1[2] == 0x5c || (param_1[2] == 0x2f))))
  {
    if (*param_1 == 0xff) {
      uVar8 = 0xffffffff;
    }
    else {
      uVar8 = (uint)(byte)(&DAT_00482818)[*param_1];
    }
    *(uint *)(param_2 + 2) = uVar8 - 0x61;
    BVar3 = GetDiskFreeSpaceA((LPCSTR)param_1,&local_20,&local_1c,&local_18,&local_14);
    if (BVar3 == 0) {
      return 0xffffffff;
    }
    *(DWORD *)(param_2 + 8) = local_1c * local_20 * (local_14 - local_18);
    *param_2 = 0x4c00;
    param_2[1] = 0;
    *(uint *)(param_2 + 0xe) = (uint)(ushort)param_2[1];
    *(undefined4 *)(param_2 + 10) = *(undefined4 *)(param_2 + 0xe);
    param_2[1] = param_2[10];
    param_2[6] = param_2[1];
    param_2[5] = param_2[6];
    return 0;
  }
  if (param_1[1] == 0x3a) {
    if (*param_1 == 0xff) {
      uVar8 = 0xffffffff;
    }
    else {
      uVar8 = (uint)(byte)(&DAT_00482818)[*param_1];
    }
    iVar7 = uVar8 - 0x61;
  }
  else {
    iVar7 = FUN_00458880();
    iVar7 = iVar7 + -1;
  }
  *(int *)(param_2 + 2) = iVar7;
  hFindFile = FindFirstFileA((LPCSTR)param_1,&local_1c0);
  if (hFindFile == (HANDLE)0xffffffff) {
    pvVar4 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar4 + 4) = 6;
    return 0xffffffff;
  }
  local_50[0] = param_2 + 10;
  local_50[1] = param_2 + 0xc;
  local_50[2] = param_2 + 0xe;
  local_80 = local_1c0.ftLastAccessTime.dwLowDateTime;
  local_7c = local_1c0.ftLastAccessTime.dwHighDateTime;
  local_78 = local_1c0.ftLastWriteTime.dwLowDateTime;
  local_74 = local_1c0.ftLastWriteTime.dwHighDateTime;
  local_70 = local_1c0.ftCreationTime.dwLowDateTime;
  local_6c = local_1c0.ftCreationTime.dwHighDateTime;
  iVar7 = 3;
  lpFileTime = &local_68;
  do {
    lpFileTime = lpFileTime + -1;
    iVar7 = iVar7 + -1;
    BVar3 = FileTimeToLocalFileTime(lpFileTime,&local_68);
    if (BVar3 == 0) {
LAB_00457c17:
      local_50[2] = local_50[0];
    }
    else {
      BVar3 = FileTimeToSystemTime(&local_68,&local_60);
      if (BVar3 == 0) goto LAB_00457c17;
      local_44 = (uint)local_60.wSecond;
      local_40 = (uint)local_60.wMinute;
      local_3c = (uint)local_60.wHour;
      local_38 = (uint)local_60.wDay;
      local_34 = local_60.wMonth - 1;
      local_30 = local_60.wYear - 0x76c;
      local_2c = (uint)local_60.wDayOfWeek;
      iVar5 = FUN_004574d0(local_30);
      if (iVar5 == 0) {
        sVar2 = *(short *)(&DAT_00482a32 + local_34 * 2);
      }
      else {
        sVar2 = *(short *)(s_Sunday_00482a4c + local_34 * 2);
      }
      local_28 = (int)sVar2;
      local_24 = 0xffffffff;
      uVar6 = FUN_004578a0(&local_44);
      *(undefined4 *)local_50[iVar7] = uVar6;
    }
    if (iVar7 == 0) {
      *(DWORD *)(param_2 + 8) = local_1c0.nFileSizeLow;
      uVar8 = FUN_00457c90(local_1c0.dwFileAttributes,(char *)param_1,(HANDLE)0x0);
      *param_2 = (short)uVar8;
      param_2[4] = 1;
      param_2[1] = 0;
      param_2[6] = param_2[1];
      param_2[5] = param_2[6];
      if (hFindFile != (HANDLE)0x0) {
        FindClose(hFindFile);
      }
      return 0;
    }
  } while( true );
}


