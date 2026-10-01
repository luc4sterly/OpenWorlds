// 10009860 RwSetShapePath [Global]
// program: RWL21.DLL

bool RwSetShapePath(char *param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  
                    /* 0x9860  450  RwSetShapePath */
  if (param_1 == (char *)0x0) {
    FUN_1000cba0(1);
    return false;
  }
  iVar6 = 1;
  if ((char)DAT_10058070 != '\0') {
    iVar6 = param_2;
  }
  if (iVar6 == 1) {
    uVar4 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (~uVar4 - 1 < 0x1fff) {
      _sprintf((char *)&DAT_10058070,&DAT_1005a07c,param_1);
      return true;
    }
    FUN_1000cba0(9);
    return false;
  }
  if (iVar6 == 2) {
    uVar4 = 0xffffffff;
    pcVar3 = (char *)&DAT_10058070;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    uVar5 = 0xffffffff;
    pcVar3 = param_1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    bVar2 = (int)(~uVar5 + (~uVar4 - 1)) < 0x2000;
    if (!bVar2) {
      FUN_1000cba0(9);
      return bVar2;
    }
    pcVar3 = (char *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(~uVar4);
    bVar2 = pcVar3 != (char *)0x0;
    if (pcVar3 == (char *)0x0) {
      FUN_1000cba0(3);
      return bVar2;
    }
    uVar4 = 0xffffffff;
    pcVar7 = (char *)&DAT_10058070;
    do {
      pcVar8 = pcVar7;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar8 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar8;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    pcVar7 = pcVar8 + -uVar4;
    pcVar8 = pcVar3;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar8 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar8 = pcVar8 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar8 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    _sprintf((char *)&DAT_10058070,s__s_c_s_1005a070,param_1,(int)DAT_1005a079,pcVar3);
    (**(code **)(PTR_DAT_1005b69c + 0x358))(pcVar3);
    return bVar2;
  }
  if (iVar6 != 3) {
    FUN_1000cba0(2);
    return false;
  }
  uVar4 = 0xffffffff;
  pcVar3 = (char *)&DAT_10058070;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  uVar5 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  bVar2 = (int)(~uVar5 + (uVar4 - 1)) < 0x2000;
  if (!bVar2) {
    FUN_1000cba0(9);
    return bVar2;
  }
  uVar5 = 0xffffffff;
  *(char *)(uVar4 + 0x1005806f) = DAT_1005a079;
  *(undefined1 *)((int)&DAT_10058070 + uVar4) = 0;
  do {
    pcVar3 = param_1;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar3 = param_1 + 1;
    cVar1 = *param_1;
    param_1 = pcVar3;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  iVar6 = -1;
  pcVar7 = (char *)&DAT_10058070;
  do {
    pcVar8 = pcVar7;
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar3 = pcVar3 + -uVar5;
  pcVar7 = pcVar8 + -1;
  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar7 = *pcVar3;
    pcVar3 = pcVar3 + 1;
    pcVar7 = pcVar7 + 1;
  }
  return bVar2;
}


