// 00402a8f FUN_00402a8f [Global]
// program: gdkup.exe

char * __fastcall FUN_00402a8f(undefined4 param_1,char param_2)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  
  pcVar2 = (char *)0x0;
  do {
    if (param_2 == *in_EAX) {
      pcVar2 = in_EAX;
    }
    cVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
  } while (cVar1 != '\0');
  return pcVar2;
}


