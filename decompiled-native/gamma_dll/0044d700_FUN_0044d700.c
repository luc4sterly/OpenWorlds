// 0044d700 FUN_0044d700 [Global]
// programa: gamma.dll

char * __cdecl FUN_0044d700(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = -1;
  pcVar4 = param_1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while (cVar1 != '\0');
  pcVar4 = pcVar3 + -1;
  do {
    cVar1 = *param_2;
    *pcVar4 = cVar1;
    param_2 = param_2 + 1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  return param_1;
}


