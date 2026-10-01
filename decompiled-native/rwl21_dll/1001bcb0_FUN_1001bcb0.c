// 1001bcb0 FUN_1001bcb0 [Global]
// program: RWL21.DLL

undefined4 FUN_1001bcb0(void)

{
  byte bVar1;
  undefined4 uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar7 = 0;
  if (0 < DAT_1005dfd4) {
    iVar6 = 0;
    do {
      puVar4 = *(undefined4 **)(DAT_1005dfdc + iVar6);
      if (puVar4 == (undefined4 *)0x0) break;
      if ((uint)puVar4[0x10] < 2) {
        uVar2 = FUN_10020be0((undefined4 *)puVar4[0xf]);
        puVar4[0xf] = uVar2;
        FUN_10037010(DAT_1005ac24,puVar4);
      }
      else {
        puVar4[0x10] = puVar4[0x10] - 1;
      }
      iVar6 = iVar6 + 4;
      iVar7 = iVar7 + 1;
      *(undefined4 *)(DAT_1005dfdc + -4 + iVar6) = 0;
    } while (iVar7 < DAT_1005dfd4);
  }
  DAT_1005dfd8 = 0;
  puVar3 = FUN_10037030(DAT_1005ac24);
  if (puVar3 == (uint *)0x0) {
    FUN_1000cba0(3);
  }
  else {
    puVar8 = puVar3;
    for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    *puVar3 = 0xc;
    *(undefined1 *)(puVar3 + 0xc) = 0;
    puVar3[0x10] = 1;
    puVar4 = FUN_10020b70(1);
    puVar3[0xf] = (uint)puVar4;
    if (puVar3 == (uint *)0x0) {
      FUN_1000cba0(1);
      FUN_1000cba0(1);
    }
    else {
      puVar3[0xe] = 0;
      uVar5 = *puVar3;
      if (uVar5 < 0x40) {
        if (uVar5 < 4) {
          iVar7 = 1;
        }
        else if (uVar5 < 8) {
          iVar7 = 2;
        }
        else {
          iVar7 = 4 - (uint)(uVar5 < 0xc);
        }
      }
      else {
        FUN_1000cba0(0x67);
        iVar7 = 0;
      }
      puVar3[0xd] = 0;
      RwSetMaterialGeometrySampling(puVar3,iVar7);
      if (puVar3[0xd] != 0) {
        if (*(int *)(*(int *)(puVar3[0xd] + 0x18) + 0x1c) == *(int *)(PTR_DAT_1005b69c + 700)) {
          *(byte *)(puVar3 + 0xc) = (byte)puVar3[0xc] | 8;
        }
        else {
          *(byte *)(puVar3 + 0xc) = (byte)puVar3[0xc] & 0xf7;
        }
      }
    }
    if (puVar3 == (uint *)0x0) {
      FUN_1000cba0(1);
      FUN_1000cba0(1);
    }
    else {
      bVar1 = (byte)puVar3[0xc] & 0xe8;
      *(byte *)(puVar3 + 0xc) = bVar1;
      *(byte *)(puVar3 + 0xc) = bVar1 | 1;
      *(byte *)(puVar3 + 0xc) = (byte)puVar3[0xc] & 0x3f;
    }
    RwSetMaterialSurface((int)puVar3,0,0,0);
    if (puVar3 == (uint *)0x0) {
      FUN_1000cba0(1);
      FUN_1000cba0(1);
    }
    else {
      local_c = 0;
      local_8 = 0;
      local_4 = 0;
      uVar5 = (**(code **)(PTR_DAT_1005b69c + 0x260))(&local_c);
      puVar3[2] = uVar5;
      *(undefined1 *)(puVar3 + 1) = 0xff;
      uVar5 = *puVar3;
      if (uVar5 < 0x40) {
        if (uVar5 < 4) {
          iVar7 = 1;
        }
        else if (uVar5 < 8) {
          iVar7 = 2;
        }
        else {
          iVar7 = 4 - (uint)(uVar5 < 0xc);
        }
      }
      else {
        FUN_1000cba0(0x67);
        iVar7 = 0;
      }
      RwSetMaterialGeometrySampling(puVar3,iVar7);
    }
  }
  *(uint **)(DAT_1005dfdc + DAT_1005dfd8 * 4) = puVar3;
  return 1;
}


