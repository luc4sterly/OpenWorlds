// 10011a40 FUN_10011a40 [Global]
// programa: RWL21.DLL

undefined4 FUN_10011a40(FILE *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 extraout_ECX;
  undefined4 *puVar7;
  undefined4 extraout_EDX;
  bool bVar8;
  undefined4 uVar9;
  byte local_20 [32];
  
  iVar3 = FUN_100206d0(param_1,(char *)local_20,0x20);
  if ((iVar3 == 0) || (local_20[0] == 0x23)) {
    FUN_1000cba0(5);
    return 0;
  }
  for (puVar7 = *(undefined4 **)(DAT_1005dfcc + 0x14); puVar7 != (undefined4 *)0x0;
      puVar7 = (undefined4 *)puVar7[2]) {
    pbVar4 = (byte *)*puVar7;
    pbVar6 = local_20;
    do {
      bVar1 = *pbVar4;
      bVar8 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_10011a9e:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_10011aa3;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar8 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_10011a9e;
      pbVar4 = pbVar4 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_10011aa3:
    if (iVar3 == 0) goto LAB_10011ab0;
  }
  puVar7 = (undefined4 *)0x0;
LAB_10011ab0:
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
    iVar3 = 0x27;
LAB_10011bcd:
    FUN_1000cba0(iVar3);
  }
  else {
    if (puVar7 == (undefined4 *)0x0) {
      iVar3 = 1;
      goto LAB_10011bcd;
    }
    uVar9 = 2;
    iVar3 = FUN_1001d770();
    RwTransformClump(extraout_ECX,extraout_EDX,(uint)puVar7,iVar3,uVar9);
    iVar2 = *(int *)(DAT_1005dfcc + 0x1c);
    iVar5 = *(int *)(iVar2 + 0x9c) + 1;
    *(int *)(iVar2 + 0x9c) = iVar5;
    iVar3 = *(int *)(iVar2 + 0x98);
    if (iVar5 < iVar3) {
LAB_10011ba8:
      iVar3 = *(int *)(iVar2 + 0x9c);
    }
    else {
      iVar3 = (iVar3 >> 1) + iVar3;
      iVar5 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*(undefined4 *)(iVar2 + 0x94),iVar3 * 4);
      if (iVar5 != 0) {
        *(int *)(iVar2 + 0x94) = iVar5;
        *(int *)(iVar2 + 0x98) = iVar3;
        goto LAB_10011ba8;
      }
      *(int *)(iVar2 + 0x9c) = *(int *)(iVar2 + 0x9c) + -1;
      FUN_1000cba0(3);
      iVar3 = -1;
    }
    if (iVar3 != -1) {
      bVar8 = true;
      *(undefined4 **)(*(int *)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94) + iVar3 * 4) = puVar7;
      goto LAB_10011bd7;
    }
  }
  bVar8 = false;
LAB_10011bd7:
  if (!bVar8) {
    RwDestroyClump(puVar7);
    return 0;
  }
  return 1;
}


