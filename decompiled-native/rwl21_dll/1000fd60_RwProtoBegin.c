// 1000fd60 RwProtoBegin [Global]
// programa: RWL21.DLL

undefined4 RwProtoBegin(char *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  char *pcVar8;
  
                    /* 0xfd60  309  RwProtoBegin */
  if (*DAT_1005dfcc == 0) {
    FUN_1000cba0(0x25);
    return 0;
  }
  if (DAT_1005dfcc[7] != 0) {
    FUN_1000cba0(0x24);
    return 0;
  }
  if (param_1 == (char *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  piVar7 = DAT_1005dfcc + 5;
  puVar2 = FUN_10037030(DAT_1005a0d8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
    FUN_1000cba0(3);
  }
  else {
    uVar5 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = (char *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(~uVar5);
    *puVar2 = pcVar3;
    if (pcVar3 == (char *)0x0) {
      FUN_10037010(DAT_1005a0d8,puVar2);
      iVar4 = -1;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        cVar1 = *param_1;
        param_1 = param_1 + 1;
      } while (cVar1 != '\0');
      puVar2 = (undefined4 *)0x0;
      FUN_1000cba0(3);
    }
    else {
      uVar5 = 0xffffffff;
      do {
        pcVar8 = param_1;
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        pcVar8 = param_1 + 1;
        cVar1 = *param_1;
        param_1 = pcVar8;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar8 = pcVar8 + -uVar5;
      for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
        *(undefined4 *)pcVar3 = *(undefined4 *)pcVar8;
        pcVar8 = pcVar8 + 4;
        pcVar3 = pcVar3 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar3 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        pcVar3 = pcVar3 + 1;
      }
      puVar2[1] = 0;
      puVar2[2] = 0;
    }
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  puVar2[2] = *piVar7;
  *piVar7 = (int)puVar2;
  iVar4 = RwClumpBegin();
  if (iVar4 == 0) {
    return 0;
  }
  DAT_1005dfcc[1] = 1;
  return 1;
}


