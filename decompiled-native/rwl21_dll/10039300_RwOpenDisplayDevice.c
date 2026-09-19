// 10039300 RwOpenDisplayDevice [Global]
// programa: RWL21.DLL

undefined * RwOpenDisplayDevice(char *param_1,char *param_2)

{
  FARPROC pFVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
                    /* 0x39300  297  RwOpenDisplayDevice */
  if (DAT_1005b754 == 0) {
    FUN_1000cba0(0x55);
    return (undefined *)0x0;
  }
  if (param_1 == (char *)0x0) {
LAB_10039335:
    bVar6 = param_2 == (char *)0x0;
    if (!bVar6) {
      iVar3 = 0xb;
      pcVar4 = param_2;
      pcVar5 = s_NullDevice_1005b778;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar6);
      if (bVar6) goto LAB_10039354;
    }
    if ((param_1 == (char *)0x0) && (param_1 = _getenv(s_RWDEVICE_1005b76c), param_1 == (char *)0x0)
       ) {
      FUN_1000cba0(0x52);
      return (undefined *)0x0;
    }
    DAT_1005e06c = FUN_100445f0(param_1);
    if (DAT_1005e06c == (undefined4 *)0x0) {
      FUN_1000cba0(0x4d);
      return (undefined *)0x0;
    }
    pFVar1 = FUN_100446f0(DAT_1005e06c,s__rwdev_1005b764);
    if (pFVar1 == (FARPROC)0x0) {
      FUN_100446a0(DAT_1005e06c);
      FUN_1000cba0(0x12);
      return (undefined *)0x0;
    }
    puVar2 = (undefined *)(*pFVar1)(param_2,0,PTR_DAT_1005b69c);
    if (puVar2 == (undefined *)0x0) {
      FUN_100446a0(DAT_1005e06c);
      FUN_1000cba0(0x12);
      return (undefined *)0x0;
    }
    FUN_100446e0();
    iVar3 = FUN_1000c9b0(puVar2);
    if (iVar3 != 0) {
      return PTR_DAT_1005b69c + 0x14;
    }
  }
  else {
    iVar3 = 0xb;
    bVar6 = false;
    pcVar4 = param_1;
    pcVar5 = s_NullDevice_1005b778;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar6 = *pcVar4 == *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar6);
    if (!bVar6) goto LAB_10039335;
LAB_10039354:
    DAT_1005e06c = (undefined4 *)0x0;
    iVar3 = FUN_1000c9b0(&LAB_100311b0);
    if (iVar3 != 0) {
      return PTR_DAT_1005b69c + 0x14;
    }
  }
  return (undefined *)0x0;
}


