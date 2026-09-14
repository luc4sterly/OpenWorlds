// 004481e0 FUN_004481e0 [Global]
// programa: gamma.dll

undefined4 __thiscall FUN_004481e0(void *this,char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  iVar3 = 0x10;
  pcVar4 = param_1;
  pcVar6 = "";
  do {
    pcVar5 = pcVar4;
    pcVar7 = pcVar6;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar7 = pcVar6 + 1;
    pcVar5 = pcVar4 + 1;
    cVar2 = *pcVar6;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
    pcVar6 = pcVar7;
  } while (cVar1 == cVar2);
  if (pcVar5[-1] != pcVar7[-1]) {
    iVar3 = 0x10;
    pcVar4 = this;
    pcVar6 = param_1;
    do {
      pcVar5 = pcVar4;
      pcVar7 = pcVar6;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar7 = pcVar6 + 1;
      pcVar5 = pcVar4 + 1;
      cVar2 = *pcVar6;
      cVar1 = *pcVar4;
      pcVar4 = pcVar5;
      pcVar6 = pcVar7;
    } while (cVar1 == cVar2);
    if (pcVar5[-1] != pcVar7[-1]) {
      return 0;
    }
  }
  iVar3 = 0x10;
  pcVar4 = param_1 + 0x10;
  pcVar6 = "";
  do {
    pcVar5 = pcVar4;
    pcVar7 = pcVar6;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar7 = pcVar6 + 1;
    pcVar5 = pcVar4 + 1;
    cVar2 = *pcVar6;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
    pcVar6 = pcVar7;
  } while (cVar1 == cVar2);
  if (pcVar5[-1] != pcVar7[-1]) {
    iVar3 = 0x10;
    pcVar4 = (char *)((int)this + 0x10);
    pcVar6 = param_1 + 0x10;
    do {
      pcVar5 = pcVar4;
      pcVar7 = pcVar6;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar7 = pcVar6 + 1;
      pcVar5 = pcVar4 + 1;
      cVar2 = *pcVar6;
      cVar1 = *pcVar4;
      pcVar4 = pcVar5;
      pcVar6 = pcVar7;
    } while (cVar1 == cVar2);
    if (pcVar5[-1] != pcVar7[-1]) {
      return 0;
    }
  }
  iVar3 = 0x10;
  pcVar4 = param_1 + 0x2c;
  pcVar6 = "";
  do {
    pcVar5 = pcVar4;
    pcVar7 = pcVar6;
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    pcVar7 = pcVar6 + 1;
    pcVar5 = pcVar4 + 1;
    cVar2 = *pcVar6;
    cVar1 = *pcVar4;
    pcVar4 = pcVar5;
    pcVar6 = pcVar7;
  } while (cVar1 == cVar2);
  if (pcVar5[-1] != pcVar7[-1]) {
    iVar3 = 0x10;
    pcVar4 = (char *)((int)this + 0x2c);
    pcVar6 = param_1 + 0x2c;
    do {
      pcVar5 = pcVar4;
      pcVar7 = pcVar6;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar7 = pcVar6 + 1;
      pcVar5 = pcVar4 + 1;
      cVar2 = *pcVar6;
      cVar1 = *pcVar4;
      pcVar4 = pcVar5;
      pcVar6 = pcVar7;
    } while (cVar1 == cVar2);
    if (pcVar5[-1] != pcVar7[-1]) {
      return 0;
    }
    iVar3 = *(int *)((int)this + 0x40);
    if (iVar3 != *(int *)(param_1 + 0x40)) {
      return 0;
    }
    if (iVar3 != 0) {
      pcVar4 = *(char **)((int)this + 0x44);
      pcVar6 = *(char **)(param_1 + 0x44);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        do {
          pcVar5 = pcVar4;
          pcVar7 = pcVar6;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          pcVar7 = pcVar6 + 1;
          pcVar5 = pcVar4 + 1;
          cVar2 = *pcVar6;
          cVar1 = *pcVar4;
          pcVar4 = pcVar5;
          pcVar6 = pcVar7;
        } while (cVar1 == cVar2);
        iVar3 = (uint)(byte)pcVar5[-1] - (uint)(byte)pcVar7[-1];
      }
      if (iVar3 != 0) {
        return 0;
      }
    }
  }
  return 1;
}


