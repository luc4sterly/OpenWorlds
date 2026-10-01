// 004028ea FUN_004028ea [Global]
// program: gdkup.exe

char * __fastcall FUN_004028ea(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = -1;
  pcVar3 = in_EAX;
  do {
    pcVar4 = pcVar3;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar4;
  } while (cVar1 != '\0');
  pcVar4 = pcVar4 + -1;
  do {
    cVar1 = *param_2;
    *pcVar4 = cVar1;
    if (cVar1 == '\0') {
      return in_EAX;
    }
    cVar1 = param_2[1];
    param_2 = param_2 + 2;
    pcVar4[1] = cVar1;
    pcVar4 = pcVar4 + 2;
  } while (cVar1 != '\0');
  return in_EAX;
}


