// 1001f9e0 FUN_1001f9e0 [Global]
// program: RWDLDD21.DLL

void FUN_1001f9e0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  short sVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  short sVar11;
  uint unaff_EBX;
  int unaff_ESI;
  uint *puVar12;
  short *psVar13;
  short *psVar14;
  uint unaff_EDI;
  uint *puVar15;
  undefined1 local_8 [4];
  undefined4 local_4;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar10 = param_1[3];
  uVar3 = param_1[4];
  iVar8 = (*(int *)(DAT_1003a024 + 0x34) - *(int *)(DAT_1003a024 + 0x30)) + uVar1 * -8;
  iVar6 = *(int *)(DAT_1003a024 + 0x2c) - *(int *)(DAT_1003a024 + 0x28);
  if (((iVar6 == uVar1 * 0x20 || (int)(iVar6 + uVar1 * -0x20) < 0) ||
      (iVar8 == 0x16c || iVar8 + -0x16c < 0)) && (iVar6 = FUN_10001080(DAT_1003a024), iVar6 == 0)) {
    return;
  }
  piVar7 = (int *)FUN_10001190(uVar3,uVar10,&local_4);
  if (piVar7 == (int *)0x0) {
    return;
  }
  iVar6 = (**(code **)(*piVar7 + 0x10))(piVar7,*(undefined4 *)(DAT_1003a024 + 8),local_8);
  if (iVar6 != 0) {
    return;
  }
  puVar4 = *(uint **)(DAT_1003a024 + 0x28);
  iVar6 = *(int *)(DAT_1003a024 + 0x24);
  if (param_1 + 5 != puVar4) {
    puVar12 = param_1 + 5;
    puVar15 = puVar4;
    for (uVar9 = unaff_EBX >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar15 = *puVar12;
      puVar12 = puVar12 + 1;
      puVar15 = puVar15 + 1;
    }
    for (uVar9 = unaff_EBX & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *(char *)puVar15 = (char)*puVar12;
      puVar12 = (uint *)((int)puVar12 + 1);
      puVar15 = (uint *)((int)puVar15 + 1);
    }
  }
  *(uint *)(DAT_1003a024 + 0x28) = *(int *)(DAT_1003a024 + 0x28) + uVar1 * 0x20;
  DAT_10039078 = *(undefined1 **)(DAT_1003a024 + 0x30);
  DAT_10038b70 = 0;
  **(undefined1 **)(DAT_1003a024 + 0x30) = 8;
  *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
  *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
  if (uVar10 == 0) {
    if (*(int *)(DAT_1003a024 + 0x84) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x84) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
      *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
      DAT_10038b70 = DAT_10038b70 + 1;
    }
  }
  else if (*(int *)(DAT_1003a024 + 0x84) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x84) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 9;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    DAT_10038b70 = DAT_10038b70 + 1;
  }
  if ((((unaff_EDI & 2) == 0) && (DAT_100362ac == 0)) || (DAT_10036068 == 0)) {
    if (*(int *)(DAT_1003a024 + 0x88) != 0) {
      *(undefined4 *)(DAT_1003a024 + 0x88) = 0;
      **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
      *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
      goto LAB_1001fc3a;
    }
  }
  else if (*(int *)(DAT_1003a024 + 0x88) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x88) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 4;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
LAB_1001fc3a:
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    DAT_10038b70 = DAT_10038b70 + 1;
  }
  if (*(int *)(DAT_1003a024 + 0x90) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x90) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 7;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 0xe;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 0x17;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    DAT_10038b70 = DAT_10038b70 + 3;
  }
  if (*(int *)(DAT_1003a024 + 0x94) != 0xff) {
    *(undefined4 *)(DAT_1003a024 + 0x94) = 0xff;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 0;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    DAT_10038b70 = DAT_10038b70 + 1;
  }
  if (*(int *)(DAT_1003a024 + 0x8c) == 0) {
    *(undefined4 *)(DAT_1003a024 + 0x8c) = 1;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 0x13;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 5;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    **(undefined4 **)(DAT_1003a024 + 0x30) = 0x14;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 6;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    if (*(int *)(DAT_1003a024 + 0x7c) == 0) {
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x1b;
    }
    else {
      **(undefined4 **)(DAT_1003a024 + 0x30) = 0x27;
    }
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 1;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
    DAT_10038b70 = DAT_10038b70 + 3;
  }
  if (((unaff_EDI & 4) == 0) && (DAT_100362b0 == 0)) {
    if (*(int *)(unaff_ESI + 0x1c) == 0) {
      uVar10 = *(uint *)(DAT_1003a024 + 100);
    }
    else if ((unaff_EDI & 0x10) == 0) {
      uVar10 = *(uint *)(DAT_1003a024 + 0x5c);
    }
    else {
      uVar10 = *(uint *)(DAT_1003a024 + 0x54);
    }
    if (*(uint *)(DAT_1003a024 + 0x98) == uVar10) goto LAB_1001fedc;
  }
  else {
    if (*(int *)(unaff_ESI + 0x1c) == 0) {
      uVar10 = *(uint *)(DAT_1003a024 + 0x60);
    }
    else if ((unaff_EDI & 0x10) == 0) {
      uVar10 = *(uint *)(DAT_1003a024 + 0x58);
    }
    else {
      uVar10 = *(uint *)(DAT_1003a024 + 0x50);
    }
    if ((*(int *)(DAT_1003a024 + 0x98) == 0) == uVar10) goto LAB_1001fedc;
  }
  *(uint *)(DAT_1003a024 + 0x98) = uVar10;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar10;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 0x12;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar10;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
LAB_1001fedc:
  **(undefined4 **)(DAT_1003a024 + 0x30) = 1;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 4) = uVar3;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  if (*(int *)(DAT_1003a024 + 0x80) == 0) {
    **(undefined4 **)(DAT_1003a024 + 0x30) = 0x15;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 2;
  }
  else {
    **(undefined4 **)(DAT_1003a024 + 0x30) = 0x15;
    *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 4) = 4;
  }
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 8;
  DAT_10038b70 = DAT_10038b70 + 2;
  *DAT_10039078 = 8;
  DAT_10039078[1] = 8;
  *(short *)(DAT_10039078 + 2) = (short)DAT_10038b70;
  DAT_10039078 = DAT_10039078 + 4;
  **(undefined1 **)(DAT_1003a024 + 0x30) = 9;
  *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 0x10;
  *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 1;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
  **(undefined4 **)(DAT_1003a024 + 0x30) = 10;
  sVar11 = (short)((uint)((int)puVar4 - iVar6) >> 5);
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 4) = sVar11;
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 6) = sVar11;
  *(uint *)(*(int *)(DAT_1003a024 + 0x30) + 8) = uVar1 & 0xffff;
  *(undefined4 *)(*(int *)(DAT_1003a024 + 0x30) + 0xc) = 0;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 0x10;
  if (((uint)*(undefined1 **)(DAT_1003a024 + 0x30) & 7) == 0) {
    **(undefined1 **)(DAT_1003a024 + 0x30) = 3;
    *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
    *(undefined2 *)(*(int *)(DAT_1003a024 + 0x30) + 2) = 0;
    *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
  }
  **(undefined1 **)(DAT_1003a024 + 0x30) = 3;
  *(undefined1 *)(*(int *)(DAT_1003a024 + 0x30) + 1) = 8;
  *(short *)(*(int *)(DAT_1003a024 + 0x30) + 2) = (short)uVar1 + -2;
  *(int *)(DAT_1003a024 + 0x30) = *(int *)(DAT_1003a024 + 0x30) + 4;
  uVar10 = 1;
  psVar14 = *(short **)(DAT_1003a024 + 0x30);
  psVar13 = psVar14;
  if (1 < uVar1 - 1) {
    do {
      *psVar13 = sVar11;
      sVar5 = (short)uVar10;
      if (uVar2 == 0) {
        psVar13[1] = sVar5 + 1 + sVar11;
        sVar5 = sVar5 + sVar11;
      }
      else {
        psVar13[1] = sVar5 + sVar11;
        sVar5 = sVar5 + sVar11 + 1;
      }
      psVar13[2] = sVar5;
      psVar14 = psVar13 + 4;
      psVar13[3] = 0x700;
      uVar10 = uVar10 + 1;
      psVar13 = psVar14;
    } while (uVar10 < uVar1 - 1);
  }
  *(short **)(DAT_1003a024 + 0x30) = psVar14;
  return;
}


