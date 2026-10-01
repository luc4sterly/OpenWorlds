// 0044c8b0 FUN_0044c8b0 [Global]
// program: gamma.dll

void __cdecl FUN_0044c8b0(int param_1,int param_2)

{
  bool bVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  
  if (-1 < param_2) {
    if ((int)(uint)*(byte *)(param_1 + 4) <= param_2) {
      return;
    }
    pcVar4 = (char *)(param_1 + param_2 + 5);
    if ((char)(*pcVar4 + -0x30) == '\x05') {
      pcVar2 = (char *)((uint)*(byte *)(param_1 + 4) + param_1 + 5);
      do {
        pcVar2 = pcVar2 + -1;
        if (pcVar2 <= pcVar4) break;
      } while (*pcVar2 == '0');
      if (param_2 == 0) {
        bVar1 = false;
      }
      else if (pcVar2 == pcVar4) {
        bVar1 = (bool)(*(byte *)(param_1 + param_2 + 4) & 1);
      }
      else {
        bVar1 = true;
      }
    }
    else {
      bVar1 = '\x05' < (char)(*pcVar4 + -0x30);
    }
    for (; param_2 != 0; param_2 = param_2 + -1) {
      pcVar4 = pcVar4 + -1;
      cVar3 = *pcVar4 + -0x30 + bVar1;
      bVar1 = '\t' < cVar3;
      if ((!bVar1) && (cVar3 != '\0')) {
        *pcVar4 = cVar3 + '0';
        break;
      }
    }
    if (bVar1 != false) {
      *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
      *(undefined1 *)(param_1 + 4) = 1;
      *(undefined1 *)(param_1 + 5) = 0x31;
      return;
    }
    if (param_2 != 0) {
      *(char *)(param_1 + 4) = (char)param_2;
      return;
    }
  }
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 4) = 1;
  *(undefined1 *)(param_1 + 5) = 0x30;
  return;
}


