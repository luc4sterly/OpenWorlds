// 004327df FUN_004327df [Global]
// program: sfmain.exe

char * __fastcall FUN_004327df(int param_1,char *param_2)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  int unaff_EBX;
  
  if ((param_1 == 0) && (unaff_EBX < 1)) {
    *in_EAX = '0';
    in_EAX[1] = '.';
    return in_EAX + 2;
  }
  for (; (0 < unaff_EBX && (*param_2 != '\0')); param_2 = param_2 + 1) {
    unaff_EBX = unaff_EBX + -1;
    *in_EAX = *param_2;
    in_EAX = in_EAX + 1;
  }
  for (; 0 < unaff_EBX; unaff_EBX = unaff_EBX + -1) {
    *in_EAX = '0';
    in_EAX = in_EAX + 1;
  }
  *in_EAX = '.';
  pcVar2 = in_EAX + 1;
  if (0 < param_1) {
    do {
      if (unaff_EBX == 0) break;
      unaff_EBX = unaff_EBX + 1;
      *pcVar2 = '0';
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  if (0 < param_1) {
    do {
      cVar1 = *param_2;
      if (cVar1 == '\0') break;
      param_2 = param_2 + 1;
      *pcVar2 = cVar1;
      pcVar2 = pcVar2 + 1;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    for (; param_1 != 0; param_1 = param_1 + -1) {
      *pcVar2 = '0';
      pcVar2 = pcVar2 + 1;
    }
  }
  return pcVar2;
}


