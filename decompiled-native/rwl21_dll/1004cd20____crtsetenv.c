// 1004cd20 ___crtsetenv [Global]
// program: RWL21.DLL

/* Library Function - Single Match
    ___crtsetenv
   
   Library: Visual Studio 1998 Release */

int __cdecl ___crtsetenv(char **_POption,int _Primary)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  char **ppcVar4;
  int iVar5;
  int *piVar6;
  LPCSTR lpName;
  uint uVar7;
  uint uVar8;
  CHAR *pCVar9;
  char **ppcVar10;
  char **ppcVar11;
  LPCSTR pCVar12;
  bool bVar13;
  
  if (((_POption == (char **)0x0) ||
      (ppcVar4 = (char **)__mbschr((uchar *)_POption,0x3d), ppcVar4 == (char **)0x0)) ||
     (ppcVar4 == _POption)) {
    return -1;
  }
  bVar13 = *(uchar *)((int)ppcVar4 + 1) == '\0';
  if (DAT_1005beb8 == DAT_1005bebc) {
    DAT_1005beb8 = copy_environ(DAT_1005beb8);
  }
  if (DAT_1005beb8 == (int *)0x0) {
    if ((_Primary == 0) || (DAT_1005bec0 == (undefined4 *)0x0)) {
      if (bVar13) {
        return 0;
      }
      DAT_1005beb8 = _malloc(4);
      if (DAT_1005beb8 == (int *)0x0) {
        return -1;
      }
      *DAT_1005beb8 = 0;
      if (DAT_1005bec0 == (undefined4 *)0x0) {
        DAT_1005bec0 = _malloc(4);
        if (DAT_1005bec0 == (undefined4 *)0x0) {
          return -1;
        }
        *DAT_1005bec0 = 0;
      }
    }
    else {
      iVar5 = ___wtomb_environ();
      if (iVar5 != 0) {
        return -1;
      }
    }
  }
  piVar6 = DAT_1005beb8;
  iVar5 = findenv((uchar *)_POption,(int)ppcVar4 - (int)_POption);
  if ((iVar5 < 0) || (*piVar6 == 0)) {
    if (bVar13) {
      return 0;
    }
    if (iVar5 < 0) {
      iVar5 = -iVar5;
    }
    piVar6 = _realloc(piVar6,iVar5 * 4 + 8);
    if (piVar6 == (int *)0x0) {
      return -1;
    }
    piVar6[iVar5] = (int)_POption;
    (piVar6 + iVar5)[1] = 0;
  }
  else {
    if (!bVar13) {
      piVar6[iVar5] = (int)_POption;
      goto LAB_1004cee2;
    }
    piVar3 = piVar6 + iVar5;
    _free((void *)*piVar3);
    iVar2 = *piVar3;
    while (iVar2 != 0) {
      iVar5 = iVar5 + 1;
      *piVar3 = piVar3[1];
      iVar2 = piVar3[1];
      piVar3 = piVar3 + 1;
    }
    piVar6 = _realloc(piVar6,iVar5 << 2);
    if (piVar6 == (int *)0x0) goto LAB_1004cee2;
  }
  DAT_1005beb8 = piVar6;
LAB_1004cee2:
  if (_Primary != 0) {
    uVar7 = 0xffffffff;
    ppcVar10 = _POption;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *(char *)ppcVar10;
      ppcVar10 = (char **)((int)ppcVar10 + 1);
    } while (cVar1 != '\0');
    lpName = _malloc(~uVar7 + 1);
    if (lpName != (LPCSTR)0x0) {
      uVar7 = 0xffffffff;
      ppcVar10 = _POption;
      do {
        ppcVar11 = ppcVar10;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        ppcVar11 = (char **)((int)ppcVar10 + 1);
        cVar1 = *(char *)ppcVar10;
        ppcVar10 = ppcVar11;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pCVar9 = (CHAR *)((int)ppcVar11 - uVar7);
      pCVar12 = lpName;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pCVar12 = *(undefined4 *)pCVar9;
        pCVar9 = pCVar9 + 4;
        pCVar12 = pCVar12 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pCVar12 = *pCVar9;
        pCVar9 = pCVar9 + 1;
        pCVar12 = pCVar12 + 1;
      }
      lpName[(int)ppcVar4 - (int)_POption] = '\0';
      SetEnvironmentVariableA
                (lpName,(LPCSTR)(-(uint)!bVar13 &
                                (uint)(lpName + ((int)ppcVar4 - (int)_POption) + 1)));
      _free(lpName);
    }
  }
  return 0;
}


