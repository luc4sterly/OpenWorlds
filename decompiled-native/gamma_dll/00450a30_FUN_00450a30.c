// 00450a30 FUN_00450a30 [Global]
// program: gamma.dll

char * __cdecl FUN_00450a30(char *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = 0;
  iVar2 = -1;
  pcVar4 = param_1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar2 = -3 - iVar2;
  if (0 < iVar2) {
    do {
      cVar1 = param_1[iVar3];
      param_1[iVar3] = param_1[iVar2];
      param_1[iVar2] = cVar1;
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar3 < iVar2);
  }
  return param_1;
}


