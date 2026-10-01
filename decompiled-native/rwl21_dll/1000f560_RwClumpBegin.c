// 1000f560 RwClumpBegin [Global]
// program: RWL21.DLL

undefined4 RwClumpBegin(void)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int *piVar10;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  int extraout_EDX_01;
  undefined4 extraout_EDX_02;
  int *piVar11;
  undefined8 uVar12;
  
                    /* 0xf560  31  RwClumpBegin */
  bVar1 = true;
  *(undefined4 *)(PTR_DAT_1005b69c + 0x2c8) = 1;
  piVar10 = DAT_1005dfcc;
  if ((*DAT_1005dfcc != 0) || (DAT_1005dfcc[7] != 0)) {
    bVar1 = false;
  }
  piVar11 = DAT_1005dfcc + 6;
  puVar2 = FUN_10037030(DAT_1005a0d0);
  if (puVar2 == (undefined4 *)0x0) {
LAB_1000f617:
    puVar2 = (undefined4 *)0x0;
    FUN_1000cba0(3);
  }
  else {
    iVar3 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x20);
    puVar2[0x25] = iVar3;
    if (iVar3 == 0) {
      FUN_10037010(DAT_1005a0d0,puVar2);
      goto LAB_1000f617;
    }
    puVar2[0x26] = 8;
    puVar2[0x27] = 0xffffffff;
    FUN_1001c4a0(puVar2);
    FUN_1001c4a0(puVar2 + 0x11);
    puVar2[0x22] = 0xffffffff;
    puVar2[0x23] = 0xffffffff;
    puVar2[0x24] = 0xffffffff;
    puVar2[0x28] = 0;
    puVar2[0x29] = 0;
  }
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else if (piVar10[7] == 0) {
    piVar10[7] = (int)puVar2;
    *piVar11 = (int)puVar2;
  }
  else {
    puVar2[0x28] = piVar10[7];
    piVar10[7] = (int)puVar2;
  }
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  uVar4 = FUN_10019b40();
  puVar2[0x24] = uVar4;
  iVar3 = RwPushCurrentMaterial();
  if (iVar3 == 0) {
    return 0;
  }
  if (bVar1) {
    puVar5 = (uint *)RwCurrentMaterial();
    puVar5 = FUN_1001b200(puVar5);
    if (puVar5 == (uint *)0x0) {
      return 0;
    }
  }
  uVar4 = FUN_1001d750();
  puVar2[0x22] = uVar4;
  if (bVar1) {
    FUN_1001c4a0(puVar2);
    uVar4 = extraout_ECX;
    iVar3 = extraout_EDX;
  }
  else {
    puVar6 = puVar2;
    puVar7 = (undefined4 *)FUN_1001d770();
    uVar12 = FUN_100510e0(extraout_ECX_00,extraout_EDX_00,puVar7,puVar6);
    iVar3 = (int)((ulonglong)uVar12 >> 0x20);
    uVar4 = extraout_ECX_01;
  }
  iVar3 = FUN_1001d760(uVar4,iVar3);
  if (iVar3 == 0) {
    RwPopCurrentMaterial();
    return 0;
  }
  puVar6 = (undefined4 *)FUN_1001d770();
  FUN_1001c4a0(puVar6);
  uVar4 = FUN_1001d740((int)DAT_1005dfd0);
  puVar2[0x23] = uVar4;
  puVar6 = puVar2 + 0x11;
  if (bVar1) {
    FUN_1001c4a0(puVar6);
    uVar4 = extraout_ECX_02;
    iVar3 = extraout_EDX_01;
  }
  else {
    puVar7 = (undefined4 *)FUN_1001d710(DAT_1005dfd0);
    uVar12 = FUN_100510e0(extraout_ECX_03,extraout_EDX_02,puVar7,puVar6);
    iVar3 = (int)((ulonglong)uVar12 >> 0x20);
    uVar4 = extraout_ECX_04;
  }
  iVar3 = FUN_1001d5c0(uVar4,iVar3,DAT_1005dfd0);
  if (iVar3 == 0) {
    FUN_1001d780();
    RwPopCurrentMaterial();
    return 0;
  }
  puVar6 = (undefined4 *)FUN_1001d710(DAT_1005dfd0);
  FUN_1001c4a0(puVar6);
  iVar9 = DAT_1005dfcc[7];
  iVar8 = *(int *)(iVar9 + 0x9c) + 1;
  *(int *)(iVar9 + 0x9c) = iVar8;
  iVar3 = *(int *)(iVar9 + 0x98);
  if (iVar3 <= iVar8) {
    iVar3 = (iVar3 >> 1) + iVar3;
    iVar8 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*(undefined4 *)(iVar9 + 0x94),iVar3 * 4);
    if (iVar8 == 0) {
      *(int *)(iVar9 + 0x9c) = *(int *)(iVar9 + 0x9c) + -1;
      FUN_1000cba0(3);
      goto LAB_1000f79f;
    }
    *(int *)(iVar9 + 0x94) = iVar8;
    *(int *)(iVar9 + 0x98) = iVar3;
  }
  if (*(int *)(iVar9 + 0x9c) == -1) {
LAB_1000f79f:
    puVar2 = (undefined4 *)DAT_1005dfcc[7];
    piVar10 = DAT_1005dfcc + 6;
    if (puVar2 == (undefined4 *)0x0) {
      FUN_1000cba0(0x22);
    }
    else {
      if ((undefined4 *)*piVar10 == puVar2) {
        DAT_1005dfcc[7] = 0;
        *piVar10 = 0;
      }
      else {
        DAT_1005dfcc[7] = puVar2[0x28];
      }
      FUN_1000f440(puVar2);
    }
    FUN_1001d780();
    RwPopCurrentMaterial();
    return 0;
  }
  puVar6 = RwCreateClump(0x100,8);
  *(undefined4 **)puVar2[0x25] = puVar6;
  iVar3 = *(int *)puVar2[0x25];
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0xa0) = *(int *)(iVar3 + 0xa0) + 1;
    return 1;
  }
  iVar3 = DAT_1005dfcc[7];
  iVar9 = *(int *)(iVar3 + 0x9c);
  if ((-1 < iVar9) && (iVar9 < *(int *)(iVar3 + 0x98))) {
    if (*(int *)(*(int *)(iVar3 + 0x94) + iVar9 * 4) != 0) {
      *(int *)(iVar3 + 0x9c) = iVar9 + -1;
      iVar9 = RwDestroyClump(*(undefined4 **)(*(int *)(iVar3 + 0x94) + iVar9 * 4));
      if (iVar9 == 0) goto LAB_1000f863;
    }
    *(int *)(iVar3 + 0x9c) = *(int *)(iVar3 + 0x9c) + -1;
  }
LAB_1000f863:
  puVar2 = (undefined4 *)DAT_1005dfcc[7];
  piVar10 = DAT_1005dfcc + 6;
  if (puVar2 == (undefined4 *)0x0) {
    FUN_1000cba0(0x22);
  }
  else {
    if ((undefined4 *)*piVar10 == puVar2) {
      DAT_1005dfcc[7] = 0;
      *piVar10 = 0;
    }
    else {
      DAT_1005dfcc[7] = puVar2[0x28];
    }
    FUN_1000f440(puVar2);
  }
  FUN_1001d780();
  RwPopCurrentMaterial();
  return 0;
}


