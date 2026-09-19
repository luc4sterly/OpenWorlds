// 100443f0 FUN_100443f0 [Global]
// programa: RWL21.DLL

char * FUN_100443f0(char *param_1,char *param_2)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *local_10c;
  char local_104 [260];
  
  uVar5 = 0xffffffff;
  do {
    pcVar3 = param_2;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar3 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar3;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar3 = pcVar3 + -uVar5;
  pcVar7 = local_104;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar7 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar7 = pcVar7 + 1;
  }
  pcVar3 = local_104;
  local_10c = pcVar3;
  while (local_104[0] != '\0') {
    if (*pcVar3 == '\\') {
      local_10c = pcVar3;
    }
    if (*pcVar3 == '.') {
      *pcVar3 = '\0';
    }
    pcVar7 = pcVar3 + 1;
    pcVar3 = pcVar3 + 1;
    local_104[0] = *pcVar7;
  }
  if (param_1 == (char *)0x0) {
    uVar5 = 0xffffffff;
    pcVar3 = local_10c;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    param_1 = (char *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(~uVar5);
    if (param_1 == (char *)0x0) {
      param_1 = (char *)0x0;
    }
    else {
      uVar5 = 0xffffffff;
      do {
        pcVar3 = local_10c;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar3 = local_10c + 1;
        cVar1 = *local_10c;
        local_10c = pcVar3;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar3 = pcVar3 + -uVar5;
      pcVar7 = param_1;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
        pcVar3 = pcVar3 + 4;
        pcVar7 = pcVar7 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar7 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar7 = pcVar7 + 1;
      }
    }
  }
  else {
    bVar2 = false;
    uVar5 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    iVar8 = 0;
    pcVar3 = param_1;
    if (~uVar5 != 0 && (int)uVar5 < 0) {
      do {
        if (bVar2) {
          return param_1;
        }
        cVar1 = param_1[iVar8];
        if ((cVar1 == ';') || (cVar1 == '\0')) {
          param_1[iVar8] = '\0';
          iVar4 = __strcmpi(pcVar3,local_10c);
          if (iVar4 == 0) {
            bVar2 = true;
          }
          pcVar3 = param_1 + iVar8 + 1;
          param_1[iVar8] = cVar1;
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)~uVar5);
    }
    if (!bVar2) {
      uVar5 = 0xffffffff;
      pcVar3 = local_10c;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      uVar6 = 0xffffffff;
      pcVar3 = param_1;
      do {
        if (uVar6 == 0) break;
        uVar6 = uVar6 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      pcVar3 = (char *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(~uVar6 + ~uVar5);
      if (pcVar3 != (char *)0x0) {
        uVar5 = 0xffffffff;
        pcVar7 = param_1;
        do {
          pcVar10 = pcVar7;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar10 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar10;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        pcVar7 = pcVar10 + -uVar5;
        pcVar10 = pcVar3;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar10 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar10 = pcVar10 + 1;
        }
        uVar5 = 0xffffffff;
        pcVar7 = (char *)&DAT_1005b918;
        do {
          pcVar10 = pcVar7;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar10 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar10;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        iVar8 = -1;
        pcVar7 = pcVar3;
        do {
          pcVar9 = pcVar7;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pcVar9 = pcVar7 + 1;
          cVar1 = *pcVar7;
          pcVar7 = pcVar9;
        } while (cVar1 != '\0');
        pcVar7 = pcVar10 + -uVar5;
        pcVar10 = pcVar9 + -1;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar10 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar10 = pcVar10 + 1;
        }
        uVar5 = 0xffffffff;
        do {
          pcVar7 = local_10c;
          if (uVar5 == 0) break;
          uVar5 = uVar5 - 1;
          pcVar7 = local_10c + 1;
          cVar1 = *local_10c;
          local_10c = pcVar7;
        } while (cVar1 != '\0');
        uVar5 = ~uVar5;
        iVar8 = -1;
        pcVar10 = pcVar3;
        do {
          pcVar9 = pcVar10;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pcVar9 = pcVar10 + 1;
          cVar1 = *pcVar10;
          pcVar10 = pcVar9;
        } while (cVar1 != '\0');
        pcVar7 = pcVar7 + -uVar5;
        pcVar10 = pcVar9 + -1;
        for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar7;
          pcVar7 = pcVar7 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
          *pcVar10 = *pcVar7;
          pcVar7 = pcVar7 + 1;
          pcVar10 = pcVar10 + 1;
        }
        (**(code **)(PTR_DAT_1005b69c + 0x358))(param_1);
        param_1 = pcVar3;
      }
    }
  }
  return param_1;
}


