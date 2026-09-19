// 100169e0 FUN_100169e0 [Global]
// programa: RWL21.DLL

int FUN_100169e0(int *param_1,char *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  
  if (*param_3 != 0) {
    FUN_1000cba0(0x69);
    return -1;
  }
  if (param_2 == (char *)0x0) {
    pcVar3 = (char *)0x0;
  }
  else {
    uVar5 = 0xffffffff;
    pcVar3 = param_2;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = (char *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(~uVar5);
    uVar5 = 0xffffffff;
    if (pcVar3 == (char *)0x0) {
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *param_2;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
      FUN_1000cba0(3);
      return -1;
    }
    do {
      pcVar7 = param_2;
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      pcVar7 = param_2 + 1;
      cVar1 = *param_2;
      param_2 = pcVar7;
    } while (cVar1 != '\0');
    uVar5 = ~uVar5;
    pcVar7 = pcVar7 + -uVar5;
    pcVar8 = pcVar3;
    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
  }
  iVar2 = param_1[1];
  if (param_1[2] == iVar2) {
    iVar2 = (iVar2 >> 1) + iVar2;
    iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*param_1,iVar2 * 8);
    if (iVar4 == 0) {
      if (pcVar3 != (char *)0x0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(pcVar3);
      }
      FUN_1000cba0(3);
      return -1;
    }
    param_1[1] = iVar2;
    *param_1 = iVar4;
  }
  *(char **)(*param_1 + param_1[2] * 8) = pcVar3;
  *(int **)(*param_1 + 4 + param_1[2] * 8) = param_3;
  *param_3 = (int)param_1;
  iVar2 = param_1[2];
  param_1[2] = iVar2 + 1;
  return iVar2;
}


