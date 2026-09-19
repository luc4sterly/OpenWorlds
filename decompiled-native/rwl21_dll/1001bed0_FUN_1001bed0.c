// 1001bed0 FUN_1001bed0 [Global]
// programa: RWL21.DLL

undefined4 * FUN_1001bed0(void)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  DAT_1005ac24 = FUN_100371c0(s_materiallist_1005ac28,0x44);
  if (DAT_1005ac24 != (undefined4 *)0x0) {
    DAT_1005dfdc = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x80);
    if (DAT_1005dfdc == 0) {
      FUN_1000cba0(3);
      return (undefined4 *)0x0;
    }
    iVar6 = 0;
    iVar2 = 0;
    DAT_1005dfd4 = 0x20;
    do {
      iVar2 = iVar2 + 4;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(DAT_1005dfdc + -4 + iVar2) = 0;
    } while (iVar6 < DAT_1005dfd4);
    DAT_1005dfd8 = 0;
    puVar3 = FUN_10037030((int)DAT_1005ac24);
    if (puVar3 == (uint *)0x0) {
      FUN_1000cba0(3);
    }
    else {
      puVar7 = puVar3;
      for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
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
            iVar2 = 1;
          }
          else if (uVar5 < 8) {
            iVar2 = 2;
          }
          else {
            iVar2 = 4 - (uint)(uVar5 < 0xc);
          }
        }
        else {
          FUN_1000cba0(0x67);
          iVar2 = 0;
        }
        puVar3[0xd] = 0;
        RwSetMaterialGeometrySampling(puVar3,iVar2);
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
        uStack_c = 0;
        uStack_8 = 0;
        uStack_4 = 0;
        uVar5 = (**(code **)(PTR_DAT_1005b69c + 0x260))(&uStack_c);
        puVar3[2] = uVar5;
        *(undefined1 *)(puVar3 + 1) = 0xff;
        uVar5 = *puVar3;
        if (uVar5 < 0x40) {
          if (uVar5 < 4) {
            iVar2 = 1;
          }
          else if (uVar5 < 8) {
            iVar2 = 2;
          }
          else {
            iVar2 = 4 - (uint)(uVar5 < 0xc);
          }
        }
        else {
          FUN_1000cba0(0x67);
          iVar2 = 0;
        }
        RwSetMaterialGeometrySampling(puVar3,iVar2);
      }
    }
    *(uint **)(DAT_1005dfdc + DAT_1005dfd8 * 4) = puVar3;
    if (*(int *)(DAT_1005dfdc + DAT_1005dfd8 * 4) == 0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(DAT_1005dfdc);
      return (undefined4 *)0x0;
    }
  }
  return DAT_1005ac24;
}


