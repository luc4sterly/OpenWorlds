// 0042c5c6 FUN_0042c5c6 [Global]
// program: sfmain.exe

char * __fastcall FUN_0042c5c6(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  
  pcVar2 = in_EAX;
  do {
    cVar1 = *param_2;
    *pcVar2 = cVar1;
    if (cVar1 == '\0') {
      return in_EAX;
    }
    cVar1 = param_2[1];
    param_2 = param_2 + 2;
    pcVar2[1] = cVar1;
    pcVar2 = pcVar2 + 2;
  } while (cVar1 != '\0');
  return in_EAX;
}


