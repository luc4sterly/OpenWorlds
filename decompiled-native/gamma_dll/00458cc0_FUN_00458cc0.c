// 00458cc0 FUN_00458cc0 [Global]
// program: gamma.dll

undefined4 __cdecl FUN_00458cc0(char *param_1,char *param_2,int *param_3)

{
  char cVar1;
  undefined4 in_EAX;
  undefined3 uVar5;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  uint3 uVar6;
  char *pcVar7;
  char *pcVar8;
  
  *param_3 = 0;
  uVar5 = (undefined3)((uint)in_EAX >> 8);
  if (param_2 == (char *)0x0) {
    return CONCAT31(uVar5,1);
  }
  if (((*param_2 == 'P') && (param_2[2] == 'X')) && ((*param_1 == 'P' || (*param_1 == '*')))) {
    return CONCAT31(uVar5,1);
  }
  iVar2 = *param_1 + -0x21;
  switch(iVar2) {
  case 0:
  case 9:
    break;
  default:
    while( true ) {
      cVar1 = *param_1;
      uVar6 = (uint3)((uint)iVar2 >> 8);
      if (((cVar1 != 'P') && (cVar1 != 'Q')) || (cVar1 != *param_2)) break;
      pcVar8 = param_1 + 1;
      param_1 = param_1 + 2;
      pcVar7 = param_2 + 1;
      param_2 = param_2 + 2;
      uVar4 = ~((int)*pcVar7 - 0x41U) & (int)*pcVar8 - 0x41U;
      iVar2 = 0;
      if (uVar4 != 0) {
        return uVar4 & 0xffffff00;
      }
    }
    while( true ) {
      if (*param_1 != *param_2) {
        return (uint)uVar6 << 8;
      }
      if (*param_1 == '\0') break;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    return CONCAT31(uVar6,1);
  }
  pcVar8 = param_1 + 1;
  pcVar7 = param_2 + 1;
  if (*param_1 != *param_2) {
    return (uint)param_2 & 0xffffff00;
  }
  while( true ) {
    while (pcVar3 = pcVar8, *pcVar3 == *pcVar7) {
      pcVar8 = pcVar3 + 1;
      pcVar7 = pcVar7 + 1;
      if (*pcVar3 == '!') {
        pcVar7 = (char *)0x0;
        while( true ) {
          if (*pcVar8 == '!') break;
          pcVar3 = (char *)(int)*pcVar8;
          pcVar7 = pcVar3 + (int)pcVar7 * 10 + -0x30;
          pcVar8 = pcVar8 + 1;
        }
        *param_3 = (int)pcVar7;
        return CONCAT31((int3)((uint)pcVar3 >> 8),1);
      }
    }
    do {
      cVar1 = *pcVar3;
      pcVar8 = pcVar3 + 1;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '!');
    do {
      pcVar7 = pcVar8;
      pcVar8 = pcVar7 + 1;
    } while (*pcVar7 != '!');
    if (*pcVar8 == '\0') break;
    pcVar7 = param_2 + 1;
  }
  return (uint)pcVar7 & 0xffffff00;
}


