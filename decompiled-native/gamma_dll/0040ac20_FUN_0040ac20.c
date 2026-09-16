// 0040ac20 FUN_0040ac20 [Global]
// programa: gamma.dll

undefined4 FUN_0040ac20(int *param_1,char *param_2,undefined4 *param_3)

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
    pcVar4 = "\x01";
    do {
      pcVar6 = param_2;
      pcVar5 = pcVar4;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pcVar5 = pcVar4 + 1;
      pcVar6 = param_2 + 1;
      cVar2 = *pcVar4;
      cVar1 = *param_2;
      param_2 = pcVar6;
      pcVar4 = pcVar5;
    } while (cVar1 == cVar2);
    if (pcVar6[-1] != pcVar5[-1]) {
      *param_3 = 0;
      return 0x80004002;
    }
  }
  *param_3 = param_1;
  (**(code **)(*param_1 + 4))(param_1);
  return 0;
}


