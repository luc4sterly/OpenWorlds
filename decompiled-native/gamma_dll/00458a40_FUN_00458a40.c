// 00458a40 FUN_00458a40 [Global]
// program: gamma.dll

/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_00458a40(void)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  LPCH pCVar6;
  uint *puVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  LPCH pCVar11;
  LPCRITICAL_SECTION lpCriticalSection;
  uint *puVar12;
  char *pcVar13;
  HANDLE local_14;
  
  iVar10 = 0;
  piVar3 = (int *)FUN_00458a30();
  iVar8 = *piVar3;
  *piVar3 = *piVar3 + 1;
  if (iVar8 != 0) {
    return;
  }
  iVar8 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)&DAT_0049ee28;
  do {
    InitializeCriticalSection(lpCriticalSection);
    lpCriticalSection = lpCriticalSection + 1;
    iVar8 = iVar8 + 1;
  } while (iVar8 < 6);
  DAT_0049f448 = FUN_00454a10(8);
  if (DAT_0049f448 != (uint *)0x0) {
    pvVar4 = GetStdHandle(0xfffffff6);
    DVar5 = FUN_00458830(pvVar4,&local_14);
    if (DVar5 == 0) {
      *DAT_0049f448 = (uint)local_14;
    }
    else {
      *DAT_0049f448 = 0xffffffff;
    }
    *(undefined1 *)(DAT_0049f448 + 1) = 1;
    *(undefined1 *)((int)DAT_0049f448 + 5) = 0;
  }
  DAT_0049f44c = FUN_00454a10(8);
  if (DAT_0049f44c != (uint *)0x0) {
    pvVar4 = GetStdHandle(0xfffffff5);
    DVar5 = FUN_00458830(pvVar4,&local_14);
    if (DVar5 == 0) {
      *DAT_0049f44c = (uint)local_14;
    }
    else {
      *DAT_0049f44c = 0xffffffff;
    }
    *(undefined1 *)(DAT_0049f44c + 1) = 1;
    *(undefined1 *)((int)DAT_0049f44c + 5) = 0;
  }
  DAT_0049f450 = FUN_00454a10(8);
  if (DAT_0049f450 != (uint *)0x0) {
    pvVar4 = GetStdHandle(0xfffffff4);
    DVar5 = FUN_00458830(pvVar4,&local_14);
    if (DVar5 == 0) {
      *DAT_0049f450 = (uint)local_14;
    }
    else {
      *DAT_0049f450 = 0xffffffff;
    }
    *(undefined1 *)(DAT_0049f450 + 1) = 1;
    *(undefined1 *)((int)DAT_0049f450 + 5) = 0;
  }
  DAT_0049fb98 = 3;
  pCVar6 = GetEnvironmentStrings();
  for (pCVar11 = pCVar6; pcVar9 = pCVar11, *pCVar11 == '='; pCVar11 = pCVar11 + (-1 - iVar8)) {
    iVar8 = -1;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
  }
  for (; *pcVar9 != '\0'; pcVar9 = pcVar9 + (-1 - iVar8)) {
    iVar8 = -1;
    pcVar13 = pcVar9;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
  }
  DAT_0049eb94 = FUN_00454a10((uint)(pcVar9 + (1 - (int)pCVar11)));
  if (DAT_0049eb94 != (uint *)0x0) {
    FUN_0044df50(DAT_0049eb94,(undefined4 *)pCVar11,(uint)(pcVar9 + (1 - (int)pCVar11)));
  }
  DAT_0049fa04 = &DAT_0049eb94;
  for (puVar7 = DAT_0049eb94; (char)*puVar7 != '\0'; puVar7 = (uint *)((int)puVar7 + (-1 - iVar8)))
  {
    iVar10 = iVar10 + 1;
    iVar8 = -1;
    puVar12 = puVar7;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      uVar2 = *puVar12;
      puVar12 = (uint *)((int)puVar12 + 1);
    } while ((char)uVar2 != '\0');
  }
  DAT_0049fba8 = FUN_00454a10((iVar10 + 1) * 4);
  pcVar9 = (char *)*DAT_0049fa04;
  iVar8 = 0;
  do {
    if (*pcVar9 == '\0') {
      DAT_0049fba8[iVar8] = 0;
      FreeEnvironmentStringsA(pCVar6);
      return;
    }
    DAT_0049fba8[iVar8] = (uint)pcVar9;
    iVar8 = iVar8 + 1;
    iVar10 = -1;
    pcVar13 = pcVar9;
    do {
      if (iVar10 == 0) break;
      iVar10 = iVar10 + -1;
      cVar1 = *pcVar13;
      pcVar13 = pcVar13 + 1;
    } while (cVar1 != '\0');
    pcVar9 = pcVar9 + (-1 - iVar10);
  } while( true );
}


