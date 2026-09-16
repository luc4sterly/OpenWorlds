// 00444180 FUN_00444180 [Global]
// programa: gamma.dll

undefined4 FUN_00444180(int *param_1,char *param_2,undefined4 *param_3)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  
  if (param_3 == (undefined4 *)0x0) {
    return 0x80004003;
  }
  iVar4 = 0x10;
  pcVar5 = param_2;
  pcVar7 = &DAT_00467128;
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
  if (pcVar6[-1] != pcVar8[-1]) {
    iVar4 = 0x10;
    pcVar5 = "";
    do {
      pcVar7 = param_2;
      pcVar6 = pcVar5;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar6 = pcVar5 + 1;
      pcVar7 = param_2 + 1;
      cVar2 = *pcVar5;
      cVar1 = *param_2;
      param_2 = pcVar7;
      pcVar5 = pcVar6;
    } while (cVar1 == cVar2);
    if (pcVar7[-1] != pcVar6[-1]) {
      *param_3 = 0;
      return 0x80004002;
    }
  }
  uVar3 = FUN_00446530(param_1,param_3);
  return uVar3;
}


