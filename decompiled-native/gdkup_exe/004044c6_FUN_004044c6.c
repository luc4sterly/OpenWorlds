// 004044c6 FUN_004044c6 [Global]
// program: gdkup.exe

void FUN_004044c6(void)

{
  undefined4 *in_EAX;
  uint uVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBX;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  
  if (in_EAX == (undefined4 *)0x0) {
    return;
  }
  puVar4 = in_EAX + -1;
  if ((*puVar4 & 1) == 0) {
    return;
  }
  uVar3 = *puVar4 & 0xfffffffe;
  puVar6 = (uint *)((int)puVar4 + uVar3);
  if ((*puVar6 & 1) == 0) {
    if (puVar6 == *(uint **)(unaff_EBX + 0xc)) {
      *(uint **)(unaff_EBX + 0xc) = puVar4;
    }
    *puVar4 = uVar3 + *puVar6;
    uVar3 = puVar6[1];
    puVar6 = (uint *)puVar6[2];
    *(uint **)(uVar3 + 8) = puVar6;
    puVar6[1] = uVar3;
    *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + -1;
  }
  else {
    *puVar4 = uVar3;
    puVar6 = *(uint **)(unaff_EBX + 0xc);
    if (puVar4 < puVar6) {
      if (((uint *)puVar6[1] < puVar4) || (puVar6 = *(uint **)(unaff_EBX + 0x28), puVar4 < puVar6))
      goto LAB_00404584;
    }
    else {
      puVar6 = (uint *)puVar6[2];
      if ((puVar4 < puVar6) ||
         (puVar6 = (uint *)(unaff_EBX + 0x20), *(uint **)(unaff_EBX + 0x24) < puVar4))
      goto LAB_00404584;
    }
    uVar3 = *(uint *)(unaff_EBX + 0x1c);
    uVar1 = *(uint *)(unaff_EBX + 0x18) / (uVar3 + 1);
    if (uVar1 < uVar3) {
      iVar2 = uVar1 * 2;
      if (*(int *)(unaff_EBX + 0x18) - uVar3 <= uVar3) {
        iVar2 = 0;
      }
      puVar6 = (uint *)((int)puVar4 + *puVar4);
      do {
        uVar3 = *puVar6;
        if ((uVar3 & 1) == 0) goto LAB_00404584;
        if (uVar3 == 0xffffffff) break;
        puVar6 = (uint *)((int)puVar6 + (uVar3 & 0xfffffffe));
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    puVar6 = *(uint **)(unaff_EBX + 0xc);
    if (puVar4 < puVar6) {
      puVar6 = *(uint **)(unaff_EBX + 0x28);
    }
    while (((puVar6 <= puVar4 && (puVar6 = (uint *)puVar6[2], puVar6 <= puVar4)) &&
           (puVar6 = (uint *)puVar6[2], puVar6 <= puVar4))) {
      puVar6 = (uint *)puVar6[2];
    }
  }
LAB_00404584:
  puVar5 = (uint *)puVar6[1];
  uVar3 = *puVar4;
  if ((uint *)((int)puVar5 + *puVar5) == puVar4) {
    uVar3 = uVar3 + *puVar5;
    *puVar5 = uVar3;
    if (puVar4 == *(uint **)(unaff_EBX + 0xc)) {
      *(uint **)(unaff_EBX + 0xc) = puVar5;
    }
  }
  else {
    *(int *)(unaff_EBX + 0x1c) = *(int *)(unaff_EBX + 0x1c) + 1;
    in_EAX[1] = puVar6;
    *in_EAX = puVar5;
    puVar5[2] = (uint)puVar4;
    puVar6[1] = (uint)puVar4;
    puVar5 = puVar4;
  }
  *(int *)(unaff_EBX + 0x18) = *(int *)(unaff_EBX + 0x18) + -1;
  if ((puVar5 < *(uint **)(unaff_EBX + 0xc)) && (*(uint *)(unaff_EBX + 0x10) < uVar3)) {
    *(uint *)(unaff_EBX + 0x10) = uVar3;
  }
  if (*(uint *)(unaff_EBX + 0x14) < uVar3) {
    *(uint *)(unaff_EBX + 0x14) = uVar3;
  }
  return;
}


