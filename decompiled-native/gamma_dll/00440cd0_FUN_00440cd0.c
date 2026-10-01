// 00440cd0 FUN_00440cd0 [Global]
// program: gamma.dll

undefined4 FUN_00440cd0(char *param_1)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  iVar4 = 0x10;
  pcVar5 = param_1 + 0x2c;
  pcVar7 = &DAT_00477ffc;
  do {
    pcVar6 = pcVar5;
    pcVar8 = pcVar7;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar8 = pcVar7 + 1;
    pcVar6 = pcVar5 + 1;
    cVar2 = *pcVar7;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
    pcVar7 = pcVar8;
  } while (cVar1 == cVar2);
  uVar3 = 0x80004005;
  if (pcVar6[-1] != pcVar8[-1]) {
    return 0x80070057;
  }
  iVar4 = 0x10;
  pcVar5 = param_1;
  pcVar7 = &DAT_00477f2c;
  do {
    pcVar6 = pcVar5;
    pcVar8 = pcVar7;
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar8 = pcVar7 + 1;
    pcVar6 = pcVar5 + 1;
    cVar2 = *pcVar7;
    cVar1 = *pcVar5;
    pcVar5 = pcVar6;
    pcVar7 = pcVar8;
  } while (cVar1 == cVar2);
  if (pcVar6[-1] == pcVar8[-1]) {
    iVar4 = 0x10;
    pcVar5 = param_1 + 0x10;
    pcVar7 = &DAT_00477f8c;
    do {
      pcVar6 = pcVar5;
      pcVar8 = pcVar7;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar8 = pcVar7 + 1;
      pcVar6 = pcVar5 + 1;
      cVar2 = *pcVar7;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
      pcVar7 = pcVar8;
    } while (cVar1 == cVar2);
    if (pcVar6[-1] == pcVar8[-1]) {
      uVar3 = 0;
    }
  }
  return uVar3;
}


