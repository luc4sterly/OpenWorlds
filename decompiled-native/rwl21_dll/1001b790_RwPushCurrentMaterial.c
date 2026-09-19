// 1001b790 RwPushCurrentMaterial [Global]
// programa: RWL21.DLL

undefined4 RwPushCurrentMaterial(void)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  uint *puVar10;
  
                    /* 0x1b790  313  RwPushCurrentMaterial */
  DAT_1005dfd8 = DAT_1005dfd8 + 1;
  iVar7 = DAT_1005dfd4;
  if (DAT_1005dfd4 <= DAT_1005dfd8) {
    iVar7 = (DAT_1005dfd4 >> 1) + DAT_1005dfd4;
    iVar3 = (**(code **)(PTR_DAT_1005b69c + 0x354))(DAT_1005dfdc,iVar7 * 4);
    if (iVar3 == 0) {
      DAT_1005dfd8 = DAT_1005dfd8 + -1;
      FUN_1000cba0(3);
      return 0;
    }
    DAT_1005dfdc = iVar3;
    if (DAT_1005dfd4 < iVar7) {
      puVar5 = (undefined4 *)(iVar3 + DAT_1005dfd4 * 4);
      for (iVar6 = iVar7 - DAT_1005dfd4; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
    }
  }
  DAT_1005dfd4 = iVar7;
  puVar4 = *(uint **)(DAT_1005dfdc + DAT_1005dfd8 * 4);
  puVar9 = *(uint **)(DAT_1005dfdc + -4 + DAT_1005dfd8 * 4);
  if (puVar4 != (uint *)0x0) {
    if ((puVar9 == (uint *)0x0) || (puVar4 == (uint *)0x0)) {
      FUN_1000cba0(1);
    }
    else if (puVar9 != puVar4) {
      puVar10 = puVar4;
      for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      piVar1 = (int *)puVar4[0xf];
      iVar7 = 0;
      if (0 < *piVar1) {
        piVar8 = piVar1 + 2;
        do {
          iVar3 = *piVar8;
          if (*(int *)(iVar3 + 0x2c) == iVar3) {
            FUN_1001a2f0(iVar3);
          }
          piVar8 = piVar8 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *piVar1);
      }
      piVar1 = (int *)puVar4[0xf];
      iVar7 = 0;
      if (0 < *piVar1) {
        piVar8 = piVar1 + 2;
        do {
          iVar3 = *piVar8;
          if (*(int *)(iVar3 + 0x2c) == iVar3) {
            FUN_1001a1e0(iVar3);
          }
          piVar8 = piVar8 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *piVar1);
      }
    }
    goto LAB_1001b87f;
  }
  if (puVar9 == (uint *)0x0) {
LAB_1001b9c2:
    FUN_1000cba0(1);
LAB_1001b9cc:
    *(undefined4 *)(DAT_1005dfdc + DAT_1005dfd8 * 4) = 0;
  }
  else {
    puVar4 = FUN_10037030(DAT_1005ac24);
    if (puVar4 == (uint *)0x0) {
      FUN_1000cba0(3);
    }
    else {
      puVar10 = puVar4;
      for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar10 = 0;
        puVar10 = puVar10 + 1;
      }
      *puVar4 = 0xc;
      *(undefined1 *)(puVar4 + 0xc) = 0;
      puVar4[0x10] = 1;
      puVar5 = FUN_10020b70(1);
      puVar4[0xf] = (uint)puVar5;
      if (puVar4 == (uint *)0x0) {
        FUN_1000cba0(1);
      }
      else {
        puVar4[0xe] = 0;
      }
      RwSetMaterialTexture(puVar4,0);
      if (puVar4 == (uint *)0x0) {
        FUN_1000cba0(1);
      }
      else {
        bVar2 = (byte)puVar4[0xc] & 0xe8;
        *(byte *)(puVar4 + 0xc) = bVar2;
        *(byte *)(puVar4 + 0xc) = bVar2 | 1;
      }
      RwSetMaterialModes((int)puVar4,0);
      RwSetMaterialSurface((int)puVar4,0,0,0);
      RwSetMaterialColor((int)puVar4,0,0,0);
      RwSetMaterialOpacity(puVar4,0x3f800000);
    }
    if (puVar4 == (uint *)0x0) goto LAB_1001b9cc;
    if ((puVar9 == (uint *)0x0) || (puVar4 == (uint *)0x0)) goto LAB_1001b9c2;
    if (puVar4 != puVar9) {
      puVar10 = puVar4;
      for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      piVar1 = (int *)puVar4[0xf];
      iVar7 = 0;
      if (0 < *piVar1) {
        piVar8 = piVar1 + 2;
        do {
          iVar3 = *piVar8;
          if (*(int *)(iVar3 + 0x2c) == iVar3) {
            FUN_1001a2f0(iVar3);
          }
          piVar8 = piVar8 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *piVar1);
      }
      piVar1 = (int *)puVar4[0xf];
      iVar7 = 0;
      if (0 < *piVar1) {
        piVar8 = piVar1 + 2;
        do {
          iVar3 = *piVar8;
          if (*(int *)(iVar3 + 0x2c) == iVar3) {
            FUN_1001a1e0(iVar3);
          }
          piVar8 = piVar8 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *piVar1);
      }
    }
    *(uint **)(DAT_1005dfdc + DAT_1005dfd8 * 4) = puVar4;
  }
  if (*(int *)(DAT_1005dfdc + DAT_1005dfd8 * 4) == 0) {
    DAT_1005dfd8 = DAT_1005dfd8 + -1;
    return 0;
  }
LAB_1001b87f:
  return *(undefined4 *)(DAT_1005dfdc + DAT_1005dfd8 * 4);
}


