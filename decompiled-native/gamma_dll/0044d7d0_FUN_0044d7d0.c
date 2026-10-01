// 0044d7d0 FUN_0044d7d0 [Global]
// program: gamma.dll

char * __cdecl FUN_0044d7d0(char *param_1,char param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = (char *)0x0;
  while( true ) {
    pcVar2 = param_1;
    if (*pcVar2 == '\0') break;
    param_1 = pcVar2 + 1;
    if (*pcVar2 == param_2) {
      pcVar1 = pcVar2;
    }
  }
  if (pcVar1 == (char *)0x0) {
    if (param_2 != '\0') {
      pcVar2 = (char *)0x0;
    }
    return pcVar2;
  }
  return pcVar1;
}


