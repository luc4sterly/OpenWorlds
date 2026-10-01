// 1001b5a0 RwDuplicateMaterial [Global]
// program: RWL21.DLL

uint * RwDuplicateMaterial(uint *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  
                    /* 0x1b5a0  76  RwDuplicateMaterial */
  if (param_1 == (uint *)0x0) {
    FUN_1000cba0(1);
  }
  else {
    puVar5 = FUN_10037030(DAT_1005ac24);
    if (puVar5 == (uint *)0x0) {
      FUN_1000cba0(3);
    }
    else {
      puVar9 = puVar5;
      for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
      *puVar5 = 0xc;
      *(undefined1 *)(puVar5 + 0xc) = 0;
      puVar5[0x10] = 1;
      puVar6 = FUN_10020b70(1);
      puVar5[0xf] = (uint)puVar6;
      if (puVar5 == (uint *)0x0) {
        FUN_1000cba0(1);
        FUN_1000cba0(1);
      }
      else {
        puVar5[0xe] = 0;
        iVar7 = RwGetMaterialGeometrySampling(puVar5);
        puVar5[0xd] = 0;
        RwSetMaterialGeometrySampling(puVar5,iVar7);
        if (puVar5[0xd] != 0) {
          if (*(int *)(*(int *)(puVar5[0xd] + 0x18) + 0x1c) == *(int *)(PTR_DAT_1005b69c + 700)) {
            *(byte *)(puVar5 + 0xc) = (byte)puVar5[0xc] | 8;
          }
          else {
            *(byte *)(puVar5 + 0xc) = (byte)puVar5[0xc] & 0xf7;
          }
        }
      }
      if (puVar5 == (uint *)0x0) {
        FUN_1000cba0(1);
        FUN_1000cba0(1);
      }
      else {
        bVar4 = (byte)puVar5[0xc] & 0xe8;
        *(byte *)(puVar5 + 0xc) = bVar4;
        *(byte *)(puVar5 + 0xc) = bVar4 | 1;
        *(byte *)(puVar5 + 0xc) = (byte)puVar5[0xc] & 0x3f;
      }
      RwSetMaterialSurface((int)puVar5,0,0,0);
      RwSetMaterialColor((int)puVar5,0,0,0);
      if (puVar5 == (uint *)0x0) {
        FUN_1000cba0(1);
      }
      else {
        *(undefined1 *)(puVar5 + 1) = 0xff;
        uVar1 = *puVar5;
        if (uVar1 < 0x40) {
          if (uVar1 < 4) {
            iVar7 = 1;
          }
          else if (uVar1 < 8) {
            iVar7 = 2;
          }
          else {
            iVar7 = 4 - (uint)(uVar1 < 0xc);
          }
        }
        else {
          FUN_1000cba0(0x67);
          iVar7 = 0;
        }
        RwSetMaterialGeometrySampling(puVar5,iVar7);
      }
    }
    if (puVar5 != (uint *)0x0) {
      if ((param_1 != (uint *)0x0) && (puVar5 != (uint *)0x0)) {
        if (puVar5 != param_1) {
          puVar9 = puVar5;
          for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar9 = *param_1;
            param_1 = param_1 + 1;
            puVar9 = puVar9 + 1;
          }
          piVar2 = (int *)puVar5[0xf];
          iVar7 = 0;
          if (0 < *piVar2) {
            piVar8 = piVar2 + 2;
            do {
              iVar3 = *piVar8;
              if (*(int *)(iVar3 + 0x2c) == iVar3) {
                FUN_1001a2f0(iVar3);
              }
              piVar8 = piVar8 + 1;
              iVar7 = iVar7 + 1;
            } while (iVar7 < *piVar2);
          }
          piVar2 = (int *)puVar5[0xf];
          iVar7 = 0;
          if (0 < *piVar2) {
            piVar8 = piVar2 + 2;
            do {
              iVar3 = *piVar8;
              if (*(int *)(iVar3 + 0x2c) == iVar3) {
                FUN_1001a1e0(iVar3);
              }
              piVar8 = piVar8 + 1;
              iVar7 = iVar7 + 1;
            } while (iVar7 < *piVar2);
          }
        }
        return puVar5;
      }
      FUN_1000cba0(1);
      return (uint *)0x0;
    }
  }
  return (uint *)0x0;
}


