// 10043de0 FUN_10043de0 [Global]
// program: RWL21.DLL

char * FUN_10043de0(char *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  
  pcVar2 = _strrchr(param_1,(int)DAT_1005a078);
  pcVar3 = _strrchr(param_1,(int)*param_2);
  if (pcVar3 != (char *)0x0) {
    if (pcVar2 == (char *)0x0) {
      return (char *)0x0;
    }
    if (pcVar2 < pcVar3) {
      return (char *)0x0;
    }
  }
  uVar4 = 0xffffffff;
  do {
    pcVar2 = param_1;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar2 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar2;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar2 = pcVar2 + -uVar4;
  pcVar3 = param_3;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  uVar4 = 0xffffffff;
  do {
    pcVar2 = param_2;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar2 = param_2 + 1;
    cVar1 = *param_2;
    param_2 = pcVar2;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  iVar6 = -1;
  pcVar3 = param_3;
  do {
    pcVar7 = pcVar3;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar7 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar7;
  } while (cVar1 != '\0');
  pcVar2 = pcVar2 + -uVar4;
  pcVar3 = pcVar7 + -1;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar3 = *pcVar2;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  }
  return param_3;
}


