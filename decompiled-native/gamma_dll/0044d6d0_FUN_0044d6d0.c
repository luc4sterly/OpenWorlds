// 0044d6d0 FUN_0044d6d0 [Global]
// programa: gamma.dll

char * __cdecl FUN_0044d6d0(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = param_1;
  do {
    if (param_1 + param_3 <= pcVar3) {
      return param_1;
    }
    cVar1 = *param_2;
    pcVar4 = pcVar3 + 1;
    *pcVar3 = cVar1;
    param_2 = param_2 + 1;
    pcVar3 = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = (int)(param_1 + param_3) - (int)pcVar4;
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pcVar4 = '\0';
    pcVar4 = pcVar4 + 1;
  }
  return param_1;
}


