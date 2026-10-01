// 00448170 FUN_00448170 [Global]
// program: gamma.dll

undefined4 __fastcall FUN_00448170(char *param_1)

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
      return 0;
    }
  }
  return 1;
}


