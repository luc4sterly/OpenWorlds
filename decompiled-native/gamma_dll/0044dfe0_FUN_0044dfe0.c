// 0044dfe0 FUN_0044dfe0 [Global]
// programa: gamma.dll

char * __cdecl FUN_0044dfe0(int param_1,char param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  bool bVar4;
  char *pcVar3;
  
  pcVar1 = (char *)0x0;
  if (param_1 == 0) {
    return (char *)0x0;
  }
  bVar4 = false;
  pcVar3 = (char *)(param_1 + -1 + param_3);
  do {
    pcVar2 = pcVar3;
    if (param_3 == 0) break;
    param_3 = param_3 + -1;
    pcVar2 = pcVar3 + -1;
    bVar4 = param_2 == *pcVar3;
    pcVar3 = pcVar2;
  } while (!bVar4);
  if (bVar4) {
    pcVar1 = pcVar2 + 1;
  }
  return pcVar1;
}


