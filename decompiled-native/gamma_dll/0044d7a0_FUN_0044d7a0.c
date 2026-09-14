// 0044d7a0 FUN_0044d7a0 [Global]
// programa: gamma.dll

char * __cdecl FUN_0044d7a0(char *param_1,char param_2)

{
  char cVar1;
  
  do {
    cVar1 = *param_1;
    if (cVar1 == param_2) {
      return param_1;
    }
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return (char *)0x0;
}


