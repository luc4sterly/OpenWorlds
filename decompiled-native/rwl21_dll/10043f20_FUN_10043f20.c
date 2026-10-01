// 10043f20 FUN_10043f20 [Global]
// program: RWL21.DLL

undefined4 FUN_10043f20(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  if (*param_1 != '\0') {
    do {
      cVar2 = *param_2;
      if (cVar2 == '\0') break;
      cVar3 = *param_1;
      if ((cVar3 < 'a') || ('z' < cVar3)) {
        iVar5 = (int)cVar3;
      }
      else {
        iVar5 = cVar3 + -0x20;
      }
      if ((cVar2 < 'a') || ('z' < cVar2)) {
        iVar4 = (int)cVar2;
      }
      else {
        iVar4 = cVar2 + -0x20;
      }
      if (iVar5 != iVar4) break;
      pcVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (*pcVar1 != '\0');
    if (*param_1 != '\0') {
      return 0;
    }
  }
  if (*param_2 != '\0') {
    return 0;
  }
  return 1;
}


