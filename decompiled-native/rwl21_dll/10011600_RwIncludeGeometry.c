// 10011600 RwIncludeGeometry [Global]
// programa: RWL21.DLL

undefined4 RwIncludeGeometry(undefined4 *param_1)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar5;
  undefined4 uVar6;
  
                    /* 0x11600  281  RwIncludeGeometry */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  puVar3 = (undefined4 *)FUN_10005130(param_1);
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    iVar5 = 0x27;
LAB_100116f9:
    FUN_1000cba0(iVar5);
  }
  else {
    if (puVar3 == (undefined4 *)0x0) {
      iVar5 = 1;
      goto LAB_100116f9;
    }
    uVar6 = 2;
    iVar5 = FUN_1001d770();
    RwTransformClump(extraout_ECX,extraout_EDX,(uint)puVar3,iVar5,uVar6);
    uVar6 = RwCurrentMaterial();
    iVar5 = RwForAllClumpsInHierarchyPointer((int)puVar3,&LAB_100112e0,uVar6);
    if (iVar5 != 0) {
      iVar1 = *(int *)(DAT_1005dfcc + 0x1c);
      iVar4 = *(int *)(iVar1 + 0x9c) + 1;
      *(int *)(iVar1 + 0x9c) = iVar4;
      iVar5 = *(int *)(iVar1 + 0x98);
      if (iVar4 < iVar5) {
LAB_100116d4:
        iVar5 = *(int *)(iVar1 + 0x9c);
      }
      else {
        iVar5 = (iVar5 >> 1) + iVar5;
        iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*(undefined4 *)(iVar1 + 0x94),iVar5 * 4);
        if (iVar4 != 0) {
          *(int *)(iVar1 + 0x94) = iVar4;
          *(int *)(iVar1 + 0x98) = iVar5;
          goto LAB_100116d4;
        }
        *(int *)(iVar1 + 0x9c) = *(int *)(iVar1 + 0x9c) + -1;
        FUN_1000cba0(3);
        iVar5 = -1;
      }
      if (iVar5 != -1) {
        bVar2 = true;
        *(undefined4 **)(*(int *)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94) + iVar5 * 4) = puVar3;
        goto LAB_10011703;
      }
    }
  }
  bVar2 = false;
LAB_10011703:
  if (bVar2) {
    return 1;
  }
  RwDestroyClump(puVar3);
  return 0;
}


