// 00443680 FUN_00443680 [Global]
// program: gamma.dll

void FUN_00443680(int *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  iVar3 = 0x10;
  pcVar4 = param_2;
  pcVar6 = &DAT_004670e8;
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
  if (pcVar5[-1] == pcVar7[-1]) {
    if (param_1 != (int *)0x0) {
      param_1 = param_1 + 3;
    }
    FUN_00446530(param_1,param_3);
    return;
  }
  iVar3 = 0x10;
  pcVar4 = param_2;
  pcVar6 = &DAT_004670f8;
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
  if (pcVar5[-1] == pcVar7[-1]) {
    if (param_1 != (int *)0x0) {
      param_1 = param_1 + 3;
    }
    FUN_00446530(param_1,param_3);
    return;
  }
  iVar3 = 0x10;
  pcVar4 = param_2;
  pcVar6 = "\f\x01";
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
  if (pcVar5[-1] == pcVar7[-1]) {
    if (param_1 != (int *)0x0) {
      param_1 = param_1 + 3;
    }
    FUN_00446530(param_1,param_3);
    return;
  }
  iVar3 = 0x10;
  pcVar4 = param_2;
  pcVar6 = &DAT_004670a8;
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
  if (pcVar5[-1] == pcVar7[-1]) {
    if (param_1 != (int *)0x0) {
      param_1 = param_1 + 4;
    }
    FUN_00446530(param_1,param_3);
    return;
  }
  FUN_00446430(param_1,param_2,param_3);
  return;
}


