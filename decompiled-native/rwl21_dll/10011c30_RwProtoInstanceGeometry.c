// 10011c30 RwProtoInstanceGeometry [Global]
// programa: RWL21.DLL

undefined4 RwProtoInstanceGeometry(byte *param_1)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 *puVar7;
  bool bVar8;
  undefined4 uVar9;
  
                    /* 0x11c30  312  RwProtoInstanceGeometry */
  for (puVar7 = *(undefined4 **)(DAT_1005dfcc + 0x14); puVar7 != (undefined4 *)0x0;
      puVar7 = (undefined4 *)puVar7[2]) {
    pbVar3 = (byte *)*puVar7;
    pbVar6 = param_1;
    do {
      bVar1 = *pbVar3;
      bVar8 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_10011c68:
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_10011c6d;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar8 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_10011c68;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_10011c6d:
    if (iVar4 == 0) goto LAB_10011c7a;
  }
  puVar7 = (undefined4 *)0x0;
LAB_10011c7a:
  if (puVar7 == (undefined4 *)0x0) {
    FUN_1000cba0(0x1f);
    return 0;
  }
  if ((undefined4 *)puVar7[1] == (undefined4 *)0x0) {
    FUN_1000cba0(0x26);
    return 0;
  }
  puVar7 = (undefined4 *)FUN_10005130((undefined4 *)puVar7[1]);
  if (puVar7 == (undefined4 *)0x0) {
    return 0;
  }
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    iVar4 = 0x27;
LAB_10011d96:
    FUN_1000cba0(iVar4);
  }
  else {
    if (puVar7 == (undefined4 *)0x0) {
      iVar4 = 1;
      goto LAB_10011d96;
    }
    uVar9 = 2;
    iVar4 = FUN_1001d770();
    RwTransformClump(extraout_ECX,extraout_EDX,(uint)puVar7,iVar4,uVar9);
    uVar9 = RwCurrentMaterial();
    iVar4 = RwForAllClumpsInHierarchyPointer((int)puVar7,&LAB_100112e0,uVar9);
    if (iVar4 != 0) {
      iVar2 = *(int *)(DAT_1005dfcc + 0x1c);
      iVar5 = *(int *)(iVar2 + 0x9c) + 1;
      *(int *)(iVar2 + 0x9c) = iVar5;
      iVar4 = *(int *)(iVar2 + 0x98);
      if (iVar5 < iVar4) {
LAB_10011d71:
        iVar4 = *(int *)(iVar2 + 0x9c);
      }
      else {
        iVar4 = (iVar4 >> 1) + iVar4;
        iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*(undefined4 *)(iVar2 + 0x94),iVar4 * 4);
        if (iVar5 != 0) {
          *(int *)(iVar2 + 0x94) = iVar5;
          *(int *)(iVar2 + 0x98) = iVar4;
          goto LAB_10011d71;
        }
        *(int *)(iVar2 + 0x9c) = *(int *)(iVar2 + 0x9c) + -1;
        FUN_1000cba0(3);
        iVar4 = -1;
      }
      if (iVar4 != -1) {
        bVar8 = true;
        *(undefined4 **)(*(int *)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94) + iVar4 * 4) = puVar7;
        goto LAB_10011da0;
      }
    }
  }
  bVar8 = false;
LAB_10011da0:
  if (!bVar8) {
    RwDestroyClump(puVar7);
    return 0;
  }
  return 1;
}


