// 10043fd0 FUN_10043fd0 [Global]
// program: RWL21.DLL

char * FUN_10043fd0(void)

{
  char cVar1;
  bool bVar2;
  DWORD DVar3;
  char *pcVar4;
  UINT UVar5;
  undefined3 extraout_var;
  HANDLE hFindFile;
  undefined3 extraout_var_00;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 local_a54;
  CHAR local_a50 [272];
  _WIN32_FIND_DATAA local_940;
  char local_800 [1022];
  char acStack_402 [1026];
  
  pcVar9 = (char *)0x0;
  local_800[0] = '\0';
  DVar3 = GetModuleFileNameA((HMODULE)0x0,local_a50,0x104);
  if (DVar3 != 0) {
    uVar6 = 0xffffffff;
    pcVar4 = local_a50;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    iVar8 = ~uVar6 - 1;
    if (iVar8 != 0) {
      uVar6 = 0xffffffff;
      pcVar4 = local_a50;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      for (pcVar4 = local_a50 + (~uVar6 - 2); (0 < iVar8 && (*pcVar4 != '\\')); pcVar4 = pcVar4 + -1
          ) {
        iVar8 = iVar8 + -1;
      }
      if (iVar8 != 0) {
        uVar6 = 0xffffffff;
        *pcVar4 = '\0';
        pcVar4 = local_800;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        uVar7 = 0xffffffff;
        pcVar4 = local_a50;
        do {
          if (uVar7 == 0) break;
          uVar7 = uVar7 - 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        if (~uVar7 + ~uVar6 < 0x400) {
          uVar6 = 0xffffffff;
          pcVar4 = local_a50;
          do {
            pcVar11 = pcVar4;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar11 = pcVar4 + 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar11;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar8 = -1;
          pcVar4 = local_800;
          do {
            pcVar10 = pcVar4;
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            pcVar10 = pcVar4 + 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar10;
          } while (cVar1 != '\0');
          pcVar4 = pcVar11 + -uVar6;
          pcVar11 = pcVar10 + -1;
          for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
            pcVar4 = pcVar4 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar11 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            pcVar11 = pcVar11 + 1;
          }
          uVar6 = 0xffffffff;
          pcVar4 = (char *)&DAT_1005b918;
          do {
            pcVar11 = pcVar4;
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            pcVar11 = pcVar4 + 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar11;
          } while (cVar1 != '\0');
          uVar6 = ~uVar6;
          iVar8 = -1;
          pcVar4 = local_800;
          do {
            pcVar10 = pcVar4;
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            pcVar10 = pcVar4 + 1;
            cVar1 = *pcVar4;
            pcVar4 = pcVar10;
          } while (cVar1 != '\0');
          pcVar4 = pcVar11 + -uVar6;
          pcVar11 = pcVar10 + -1;
          for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
            pcVar4 = pcVar4 + 4;
            pcVar11 = pcVar11 + 4;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *pcVar11 = *pcVar4;
            pcVar4 = pcVar4 + 1;
            pcVar11 = pcVar11 + 1;
          }
        }
      }
    }
  }
  UVar5 = GetSystemDirectoryA(local_a50,0x104);
  if (UVar5 != 0) {
    uVar6 = 0xffffffff;
    pcVar4 = local_800;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar7 = 0xffffffff;
    pcVar4 = local_a50;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (~uVar7 + ~uVar6 < 0x400) {
      uVar6 = 0xffffffff;
      pcVar4 = local_a50;
      do {
        pcVar11 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar4 = local_800;
      do {
        pcVar10 = pcVar4;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      pcVar4 = pcVar11 + -uVar6;
      pcVar11 = pcVar10 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar4 = (char *)&DAT_1005b918;
      do {
        pcVar11 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar4 = local_800;
      do {
        pcVar10 = pcVar4;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      pcVar4 = pcVar11 + -uVar6;
      pcVar11 = pcVar10 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar11 = pcVar11 + 1;
      }
    }
  }
  pcVar4 = _getenv(&DAT_1005b910);
  if (pcVar4 != (char *)0x0) {
    uVar6 = 0xffffffff;
    pcVar11 = pcVar4;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    uVar7 = 0xffffffff;
    pcVar11 = local_800;
    do {
      if (uVar7 == 0) break;
      uVar7 = uVar7 - 1;
      cVar1 = *pcVar11;
      pcVar11 = pcVar11 + 1;
    } while (cVar1 != '\0');
    if (~uVar7 + ~uVar6 < 0x400) {
      uVar6 = 0xffffffff;
      do {
        pcVar11 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar4 = local_800;
      do {
        pcVar10 = pcVar4;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      pcVar4 = pcVar11 + -uVar6;
      pcVar11 = pcVar10 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar4 = (char *)&DAT_1005b918;
      do {
        pcVar11 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar4 = local_800;
      do {
        pcVar10 = pcVar4;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      pcVar4 = pcVar11 + -uVar6;
      pcVar11 = pcVar10 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar11 = pcVar11 + 1;
      }
    }
  }
  local_a54 = 1;
  bVar2 = RwExtract(local_800,1,acStack_402 + 2,0x400);
  iVar8 = CONCAT31(extraout_var,bVar2);
  do {
    if (iVar8 == 0) {
      return pcVar9;
    }
    iVar8 = -1;
    pcVar4 = acStack_402 + 2;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar8 != -2) {
      uVar6 = 0xffffffff;
      pcVar4 = acStack_402 + 2;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      if (acStack_402[~uVar6] != '\\') {
        uVar6 = 0xffffffff;
        pcVar4 = &DAT_1005b90c;
        do {
          pcVar11 = pcVar4;
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          pcVar11 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar11;
        } while (cVar1 != '\0');
        uVar6 = ~uVar6;
        iVar8 = -1;
        pcVar4 = acStack_402 + 2;
        do {
          pcVar10 = pcVar4;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pcVar10 = pcVar4 + 1;
          cVar1 = *pcVar4;
          pcVar4 = pcVar10;
        } while (cVar1 != '\0');
        pcVar4 = pcVar11 + -uVar6;
        pcVar11 = pcVar10 + -1;
        for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
          pcVar4 = pcVar4 + 4;
          pcVar11 = pcVar11 + 4;
        }
        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
          *pcVar11 = *pcVar4;
          pcVar4 = pcVar4 + 1;
          pcVar11 = pcVar11 + 1;
        }
      }
      uVar6 = 0xffffffff;
      pcVar4 = &DAT_1005b904;
      do {
        pcVar11 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar4 = acStack_402 + 2;
      do {
        pcVar10 = pcVar4;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      pcVar4 = pcVar11 + -uVar6;
      pcVar11 = pcVar10 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar11 = pcVar11 + 1;
      }
      uVar6 = 0xffffffff;
      pcVar4 = (char *)&DAT_1005b8fc;
      do {
        pcVar11 = pcVar4;
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        pcVar11 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar11;
      } while (cVar1 != '\0');
      uVar6 = ~uVar6;
      iVar8 = -1;
      pcVar4 = acStack_402 + 2;
      do {
        pcVar10 = pcVar4;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar10 = pcVar4 + 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar10;
      } while (cVar1 != '\0');
      pcVar4 = pcVar11 + -uVar6;
      pcVar11 = pcVar10 + -1;
      for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined4 *)pcVar11 = *(undefined4 *)pcVar4;
        pcVar4 = pcVar4 + 4;
        pcVar11 = pcVar11 + 4;
      }
      for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
        *pcVar11 = *pcVar4;
        pcVar4 = pcVar4 + 1;
        pcVar11 = pcVar11 + 1;
      }
      hFindFile = FindFirstFileA(acStack_402 + 2,&local_940);
      if (hFindFile != (HANDLE)0xffffffff) {
        pcVar9 = FUN_100443f0(pcVar9,local_940.cFileName);
        iVar8 = FindNextFileA(hFindFile,&local_940);
        while (iVar8 != 0) {
          pcVar9 = FUN_100443f0(pcVar9,local_940.cFileName);
          iVar8 = FindNextFileA(hFindFile,&local_940);
        }
        FindClose(hFindFile);
      }
    }
    local_a54 = local_a54 + 1;
    bVar2 = RwExtract(local_800,local_a54,acStack_402 + 2,0x400);
    iVar8 = CONCAT31(extraout_var_00,bVar2);
  } while( true );
}


