// 1001ba80 FUN_1001ba80 [Global]
// program: RWL21.DLL

undefined4 FUN_1001ba80(void)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  int *piVar10;
  
  puVar8 = *(uint **)(DAT_1005dfdc + DAT_1005dfd8 * 4);
  if (puVar8[0x10] < 2) goto LAB_1001bc12;
  if (puVar8 == (uint *)0x0) {
LAB_1001bbb4:
    FUN_1000cba0(1);
LAB_1001bbbe:
    puVar4 = (uint *)0x0;
  }
  else {
    puVar4 = FUN_10037030(DAT_1005ac24);
    if (puVar4 == (uint *)0x0) {
      FUN_1000cba0(3);
    }
    else {
      puVar9 = puVar4;
      for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
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
        bVar3 = (byte)puVar4[0xc] & 0xe8;
        *(byte *)(puVar4 + 0xc) = bVar3;
        *(byte *)(puVar4 + 0xc) = bVar3 | 1;
      }
      RwSetMaterialModes((int)puVar4,0);
      RwSetMaterialSurface((int)puVar4,0,0,0);
      RwSetMaterialColor((int)puVar4,0,0,0);
      RwSetMaterialOpacity(puVar4,0x3f800000);
    }
    if (puVar4 == (uint *)0x0) goto LAB_1001bbbe;
    if ((puVar8 == (uint *)0x0) || (puVar4 == (uint *)0x0)) goto LAB_1001bbb4;
    if (puVar4 != puVar8) {
      puVar9 = puVar4;
      for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
      piVar1 = (int *)puVar4[0xf];
      iVar7 = 0;
      if (0 < *piVar1) {
        piVar10 = piVar1 + 2;
        do {
          iVar2 = *piVar10;
          if (*(int *)(iVar2 + 0x2c) == iVar2) {
            FUN_1001a2f0(iVar2);
          }
          piVar10 = piVar10 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *piVar1);
      }
      piVar1 = (int *)puVar4[0xf];
      iVar7 = 0;
      if (0 < *piVar1) {
        piVar10 = piVar1 + 2;
        do {
          iVar2 = *piVar10;
          if (*(int *)(iVar2 + 0x2c) == iVar2) {
            FUN_1001a1e0(iVar2);
          }
          piVar10 = piVar10 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *piVar1);
      }
    }
  }
  puVar5 = *(undefined4 **)(DAT_1005dfdc + DAT_1005dfd8 * 4);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
  }
  else if ((uint)puVar5[0x10] < 2) {
    uVar6 = FUN_10020be0((undefined4 *)puVar5[0xf]);
    puVar5[0xf] = uVar6;
    FUN_10037010(DAT_1005ac24,puVar5);
  }
  else {
    puVar5[0x10] = puVar5[0x10] - 1;
  }
  *(uint **)(DAT_1005dfdc + DAT_1005dfd8 * 4) = puVar4;
LAB_1001bc12:
  return *(undefined4 *)(DAT_1005dfdc + DAT_1005dfd8 * 4);
}


