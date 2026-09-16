// 004466c0 FUN_004466c0 [Global]
// programa: gamma.dll

void FUN_004466c0(int *param_1,char *param_2,undefined4 *param_3)

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
  pcVar6 = &DAT_00467178;
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
    FUN_00446430(param_1 + 1,param_2,param_3);
    return;
  }
  FUN_00446530(param_1,param_3);
  return;
}


