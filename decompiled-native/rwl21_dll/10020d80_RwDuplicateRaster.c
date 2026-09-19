// 10020d80 RwDuplicateRaster [Global]
// programa: RWL21.DLL

undefined4 * RwDuplicateRaster(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  
                    /* 0x20d80  78  RwDuplicateRaster */
  if (param_1 == 0) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  uVar3 = *(undefined4 *)(param_1 + 0x1c);
  puVar4 = FUN_10037030(DAT_1005acdc);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4[0xc] = 0;
    puVar4[0xf] = 0;
    puVar4[0xd] = 0;
    puVar4[0xe] = 0;
    puVar4[7] = uVar3;
    puVar4[8] = uVar2;
    puVar4[9] = uVar1;
    puVar4[1] = 0;
    iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x2a0))(puVar4);
    if (iVar6 == 0) {
      FUN_10037010(DAT_1005acdc,puVar4);
      puVar4 = (undefined4 *)0x0;
    }
  }
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[0xc] = *(undefined4 *)(param_1 + 0x30);
    puVar4[0xf] = 0;
    puVar4[0xe] = *(undefined4 *)(param_1 + 0x38);
    if ((*(int *)(param_1 + 0x38) == 0) || (*(int *)(param_1 + 0x34) == 0)) {
      puVar4[0xd] = *(int *)(param_1 + 0x34);
    }
    else {
      puVar5 = (undefined4 *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(*(int *)(param_1 + 0x38));
      puVar4[0xd] = puVar5;
      if (puVar5 == (undefined4 *)0x0) {
        RwDestroyRaster(puVar4);
        FUN_1000cba0(3);
        return (undefined4 *)0x0;
      }
      uVar8 = *(uint *)(param_1 + 0x38);
      puVar9 = *(undefined4 **)(param_1 + 0x34);
      for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar5 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar5 = puVar5 + 1;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
      }
    }
    puVar5 = (undefined4 *)0x0;
    puVar4[0xb] = 0;
    if (param_1 == 0) {
      puVar5 = (undefined4 *)0x0;
      FUN_1000cba0(1);
    }
    else if ((((*(uint *)(param_1 + 0x40) & 2) == 0) ||
             (*(code **)(PTR_DAT_1005b69c + 0x298) == (code *)0x0)) ||
            (iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x298))(param_1), iVar6 != 0)) {
      puVar5 = *(undefined4 **)(param_1 + 0x18);
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 1;
    }
    else {
      FUN_1000cba0(1);
    }
    if ((puVar4 == (undefined4 *)0x0) ||
       ((((puVar4[0x10] & 2) != 0 && (*(code **)(PTR_DAT_1005b69c + 0x298) != (code *)0x0)) &&
        (iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x298))(puVar4), iVar6 == 0)))) {
      puVar9 = (undefined4 *)0x0;
      FUN_1000cba0(1);
    }
    else {
      puVar4[0x10] = puVar4[0x10] | 1;
      puVar9 = (undefined4 *)puVar4[6];
    }
    if ((puVar5 != (undefined4 *)0x0) && (puVar9 != (undefined4 *)0x0)) {
      uVar8 = *(int *)(param_1 + 0x28) * *(int *)(param_1 + 0x20);
      for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar9 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar9 = puVar9 + 1;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar9 = *(undefined1 *)puVar5;
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        puVar9 = (undefined4 *)((int)puVar9 + 1);
      }
    }
    if ((((*(uint *)(param_1 + 0x40) & 2) != 0) &&
        (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
       (iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(param_1), iVar6 == 0)) {
      FUN_1000cba0(1);
    }
    if ((((puVar4[0x10] & 2) != 0) && (*(code **)(PTR_DAT_1005b69c + 0x29c) != (code *)0x0)) &&
       (iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x29c))(puVar4), iVar6 == 0)) {
      FUN_1000cba0(1);
    }
    return puVar4;
  }
  return (undefined4 *)0x0;
}


