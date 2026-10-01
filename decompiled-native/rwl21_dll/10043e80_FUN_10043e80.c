// 10043e80 FUN_10043e80 [Global]
// program: RWL21.DLL

void FUN_10043e80(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  
  pcVar2 = _strrchr(param_1,(int)DAT_1005a078);
  if (pcVar2 == (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar2 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if ((~uVar4 - 1 < 2) || (pcVar2 = param_1 + 2, param_1[1] != ':')) {
      pcVar2 = param_1;
    }
  }
  else {
    pcVar2 = pcVar2 + 1;
  }
  pcVar3 = _strrchr(param_1,0x2e);
  if ((pcVar3 == (char *)0x0) || (pcVar3 <= pcVar2)) {
    uVar4 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = param_1 + ((~uVar4 - 1) - (int)pcVar2);
  }
  else {
    pcVar3 = pcVar3 + -(int)pcVar2;
  }
  if (pcVar3 != (char *)0x0) {
    do {
      pcVar3 = pcVar3 + -1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
      *param_2 = cVar1;
      param_2 = param_2 + 1;
    } while (pcVar3 != (char *)0x0);
    *param_2 = '\0';
    return;
  }
  *param_2 = '\0';
  return;
}


