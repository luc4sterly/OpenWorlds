// 10002660 FUN_10002660 [Global]
// programa: RWDL6D21.DLL

undefined4 FUN_10002660(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  bool bVar11;
  
  puVar10 = (undefined4 *)0xdead;
  if ((DAT_10079084 != 0) &&
     (((param_2 * 2 - DAT_1007beb0 != 0 && DAT_1007beb0 <= param_2 * 2 || (DAT_1007bda0 < param_3))
      && (iVar1 = FUN_10008860(param_2,param_3), iVar1 == 0)))) {
    return 0;
  }
  *(uint *)(*(int *)(param_1 + 0x104) + 0x40) = *(uint *)(*(int *)(param_1 + 0x104) + 0x40) | 2;
  *(int *)(*(int *)(param_1 + 0x104) + 0x1c) = param_2;
  *(int *)(*(int *)(param_1 + 0x104) + 0x20) = param_3;
  *(int *)(*(int *)(param_1 + 0x104) + 0x28) = DAT_1007beb0;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x24) = DAT_100790ec;
  **(undefined4 **)(param_1 + 0x104) = 4;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 4) = DAT_100790ec;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 8) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0xc) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x10) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x104) + 0x14) = 0;
  iVar1 = (**(code **)(DAT_1007bda8 + 0x34c))(param_3 << 2);
  if (iVar1 == 0) {
    return 0;
  }
  *(int *)(param_1 + 0x220) = iVar1;
  if (*(int *)(param_1 + 0x10c) == 0) {
    *(uint *)(param_1 + 0x228) = *(uint *)(param_1 + 0x228) | 2;
    return 1;
  }
  uVar9 = param_2 + 3U & 0xfffffffc;
  puVar2 = (undefined4 *)(**(code **)(DAT_1007bda8 + 0x34c))(0x28);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0xffffffff;
  puVar2[6] = 0xffffffff;
  puVar2[7] = 0;
  puVar2[8] = 0;
  iVar3 = (int)(DAT_10079064 * uVar9 + ((int)(DAT_10079064 * uVar9) >> 0x1f & 7U)) >> 3;
  iVar4 = param_3 * iVar3;
  if (*(int *)(param_1 + 0x10c) == 0) goto LAB_100029c7;
  if (DAT_1007905c == 0) {
    iVar5 = iVar4 + 0x28;
  }
  else {
    iVar5 = iVar4 + 0x428;
  }
  puVar10 = (undefined4 *)(**(code **)(DAT_1007bda8 + 0x34c))(iVar5);
  if (puVar10 == (undefined4 *)0x0) {
    (**(code **)(DAT_1007bda8 + 0x358))(iVar1);
    (**(code **)(DAT_1007bda8 + 0x358))(puVar2);
    return 0;
  }
  if (DAT_1007905c == 0) {
    puVar6 = (undefined4 *)0x0;
    puVar7 = puVar10 + 10;
  }
  else {
    puVar7 = puVar10 + 0x10a;
    puVar6 = puVar10 + 10;
  }
  *puVar10 = 0x28;
  puVar10[1] = uVar9;
  puVar10[2] = param_3;
  *(undefined2 *)(puVar10 + 3) = 1;
  *(short *)((int)puVar10 + 0xe) = (short)DAT_10079064;
  puVar10[4] = 0;
  puVar10[5] = iVar4;
  puVar10[6] = 1;
  puVar10[7] = 1;
  if (DAT_1007905c == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = 0x100;
  }
  puVar10[8] = uVar8;
  puVar10[9] = uVar8;
  if (DAT_1007905c != 0) {
    if (DAT_10079058 == 0) {
      puVar6 = puVar6 + 10;
      iVar1 = 10;
      do {
        iVar4 = iVar1 + 1;
        *(undefined1 *)puVar6 = *(undefined1 *)((int)&DAT_1007bdb0 + iVar1);
        *(undefined1 *)((int)puVar6 + 1) = *(undefined1 *)((int)&DAT_1007bfc0 + iVar1);
        *(undefined1 *)((int)puVar6 + 2) = *(undefined1 *)((int)&DAT_1007bec0 + iVar1);
        *(undefined1 *)((int)puVar6 + 3) = 0;
        puVar6 = puVar6 + 1;
        iVar1 = iVar4;
      } while (iVar4 < 0xf6);
    }
    else {
      iVar1 = 0;
      do {
        *(short *)((int)puVar6 + iVar1 * 2) = (short)iVar1;
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0x100);
    }
  }
  puVar2[1] = puVar7;
  puVar2[2] = puVar10;
  puVar6 = *(undefined4 **)(param_1 + 0x100);
  puVar6[6] = (undefined4 *)((param_3 + -1) * iVar3 + (int)puVar7);
  puVar6[7] = uVar9;
  puVar6[10] = -iVar3;
  puVar6[8] = param_3;
  puVar6[9] = DAT_10079064;
  puVar6[0x10] = puVar6[0x10] | 2;
  iVar1 = DAT_10079064;
  bVar11 = DAT_10079064 == 0xf;
  puVar6[1] = DAT_10079064;
  if (bVar11) {
    *puVar6 = 2;
    puVar6[2] = 0x7c00;
    puVar6[3] = 0x3e0;
LAB_100029b6:
    puVar6[4] = 0x1f;
    puVar6[5] = 0;
  }
  else if (iVar1 == 0x10) {
    *puVar6 = 2;
    puVar6[2] = 0xf800;
    puVar6[3] = 0x7e0;
    goto LAB_100029b6;
  }
  puVar6[0xb] = puVar2;
LAB_100029c7:
  *(undefined4 **)(param_1 + 0x108) = puVar10;
  return 1;
}


