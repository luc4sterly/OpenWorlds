// 1000f8e0 RwClumpEnd [Global]
// programa: RWL21.DLL

undefined4 * RwClumpEnd(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
                    /* 0xf8e0  33  RwClumpEnd */
  puVar1 = FUN_1000f980();
  if (puVar1 == (undefined4 *)0x0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0;
    }
    return (undefined4 *)0x0;
  }
  iVar3 = 0;
  for (iVar2 = DAT_1005dfc8; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x60)) {
    iVar3 = iVar3 + 1;
  }
  if ((iVar3 < 3) && (*(int *)(DAT_1005dfcc + 0x1c) == 0)) {
    *(undefined4 *)(PTR_DAT_1005b69c + 0x2c8) = 0;
    RwForAllClumpsInHierarchy((int)puVar1,&LAB_10004870);
    iVar2 = RwForAllClumpsInHierarchy((int)puVar1,FUN_1000fc70);
    if (iVar2 == 0) {
      RwDestroyClump(puVar1);
      if (param_1 != (undefined4 *)0x0) {
        *param_1 = 0;
      }
      return (undefined4 *)0x0;
    }
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = puVar1;
  }
  return puVar1;
}


