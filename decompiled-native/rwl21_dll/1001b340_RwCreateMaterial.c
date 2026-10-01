// 1001b340 RwCreateMaterial [Global]
// program: RWL21.DLL

uint * RwCreateMaterial(void)

{
  byte bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
                    /* 0x1b340  41  RwCreateMaterial */
  puVar2 = FUN_10037030(DAT_1005ac24);
  if (puVar2 == (uint *)0x0) {
    FUN_1000cba0(3);
    return (uint *)0x0;
  }
  puVar6 = puVar2;
  for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  *puVar2 = 0xc;
  *(undefined1 *)(puVar2 + 0xc) = 0;
  puVar2[0x10] = 1;
  puVar3 = FUN_10020b70(1);
  puVar2[0xf] = (uint)puVar3;
  if (puVar2 == (uint *)0x0) {
    FUN_1000cba0(1);
    FUN_1000cba0(1);
  }
  else {
    puVar2[0xe] = 0;
    uVar4 = *puVar2;
    if (uVar4 < 0x40) {
      if (uVar4 < 4) {
        iVar5 = 1;
      }
      else if (uVar4 < 8) {
        iVar5 = 2;
      }
      else {
        iVar5 = 4 - (uint)(uVar4 < 0xc);
      }
    }
    else {
      FUN_1000cba0(0x67);
      iVar5 = 0;
    }
    puVar2[0xd] = 0;
    RwSetMaterialGeometrySampling(puVar2,iVar5);
    if (puVar2[0xd] != 0) {
      if (*(int *)(*(int *)(puVar2[0xd] + 0x18) + 0x1c) == *(int *)(PTR_DAT_1005b69c + 700)) {
        *(byte *)(puVar2 + 0xc) = (byte)puVar2[0xc] | 8;
      }
      else {
        *(byte *)(puVar2 + 0xc) = (byte)puVar2[0xc] & 0xf7;
      }
    }
  }
  if (puVar2 == (uint *)0x0) {
    FUN_1000cba0(1);
    FUN_1000cba0(1);
  }
  else {
    bVar1 = (byte)puVar2[0xc] & 0xe8;
    *(byte *)(puVar2 + 0xc) = bVar1;
    *(byte *)(puVar2 + 0xc) = bVar1 | 1;
    *(byte *)(puVar2 + 0xc) = (byte)puVar2[0xc] & 0x3f;
  }
  RwSetMaterialSurface((int)puVar2,0,0,0);
  if (puVar2 != (uint *)0x0) {
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    uVar4 = (**(code **)(PTR_DAT_1005b69c + 0x260))(&local_c);
    puVar2[2] = uVar4;
    *(undefined1 *)(puVar2 + 1) = 0xff;
    uVar4 = *puVar2;
    if (uVar4 < 0x40) {
      if (uVar4 < 4) {
        iVar5 = 1;
      }
      else if (uVar4 < 8) {
        iVar5 = 2;
      }
      else {
        iVar5 = 4 - (uint)(uVar4 < 0xc);
      }
    }
    else {
      FUN_1000cba0(0x67);
      iVar5 = 0;
    }
    RwSetMaterialGeometrySampling(puVar2,iVar5);
    return puVar2;
  }
  FUN_1000cba0(1);
  FUN_1000cba0(1);
  return (uint *)0x0;
}


