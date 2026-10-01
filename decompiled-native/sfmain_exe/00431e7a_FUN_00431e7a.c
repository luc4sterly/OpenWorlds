// 00431e7a FUN_00431e7a [Global]
// program: sfmain.exe

void __fastcall FUN_00431e7a(undefined4 param_1,int param_2)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  
  if ((*(byte *)(param_2 + 0x14) & 1) == 0) {
    for (; ((*in_EAX != '\0' && (*in_EAX != 'e')) && (*in_EAX != 'E')); in_EAX = in_EAX + 1) {
    }
    pcVar2 = in_EAX + -1;
    if ((*(char *)(param_2 + 0x15) == 'G') || (*(char *)(param_2 + 0x15) == 'g')) {
      for (; *pcVar2 == '0'; pcVar2 = pcVar2 + -1) {
      }
    }
    if (*pcVar2 != '.') {
      pcVar2 = pcVar2 + 1;
    }
    do {
      cVar1 = *in_EAX;
      in_EAX = in_EAX + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
  }
  return;
}


