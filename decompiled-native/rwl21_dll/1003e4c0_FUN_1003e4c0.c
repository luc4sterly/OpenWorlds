// 1003e4c0 FUN_1003e4c0 [Global]
// programa: RWL21.DLL

undefined4 FUN_1003e4c0(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int local_4;
  
  iVar1 = *(int *)(DAT_1005b798[3] + 8);
  uVar7 = 1;
  if (0 < iVar1) {
    do {
      if (((uint)((int *)DAT_1005b798[3])[2] < uVar7) || (uVar7 == 0)) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(*(int *)DAT_1005b798[3] + -4 + uVar7 * 4);
      }
      uVar7 = uVar7 + 1;
      RwForAllClumpsInHierarchyPointer(iVar4,&LAB_1003e6f0,DAT_1005b798[2]);
    } while ((int)uVar7 <= iVar1);
  }
  uVar7 = 1;
  iVar1 = *(int *)(DAT_1005b798[2] + 8);
  if (0 < iVar1) {
    do {
      if (((uint)((int *)DAT_1005b798[2])[2] < uVar7) || (uVar7 == 0)) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(*(int *)DAT_1005b798[2] + -4 + uVar7 * 4);
      }
      iVar4 = RwGetMaterialTexture(iVar4);
      if (iVar4 != 0) {
        piVar2 = (int *)DAT_1005b798[1];
        piVar5 = (int *)(*piVar2 + piVar2[2] * 4);
        iVar6 = piVar2[2];
        do {
          piVar5 = piVar5 + -1;
          if (iVar6 == 0) {
            uVar3 = piVar2[1];
            if (uVar3 <= (uint)piVar2[2]) {
              iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*piVar2,uVar3 * 4 + 0xa0);
              if (iVar6 == 0) break;
              *piVar2 = iVar6;
              piVar2[1] = uVar3 + 0x28;
            }
            *(int *)(*piVar2 + piVar2[2] * 4) = iVar4;
            piVar2[2] = piVar2[2] + 1;
            break;
          }
          iVar6 = iVar6 + -1;
        } while (*piVar5 != iVar4);
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 <= iVar1);
  }
  uVar7 = 1;
  iVar1 = *(int *)(DAT_1005b798[1] + 8);
  if (0 < iVar1) {
    do {
      if (((uint)((int *)DAT_1005b798[1])[2] < uVar7) || (uVar7 == 0)) {
        local_4 = 0;
      }
      else {
        local_4 = *(int *)(*(int *)DAT_1005b798[1] + -4 + uVar7 * 4);
      }
      iVar6 = RwGetTextureRaster(local_4);
      piVar2 = (int *)*DAT_1005b798;
      piVar5 = (int *)(*piVar2 + piVar2[2] * 4);
      iVar4 = piVar2[2];
      do {
        piVar5 = piVar5 + -1;
        if (iVar4 == 0) {
          uVar3 = piVar2[1];
          if (uVar3 <= (uint)piVar2[2]) {
            iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*piVar2,uVar3 * 4 + 0xa0);
            if (iVar4 == 0) break;
            *piVar2 = iVar4;
            piVar2[1] = uVar3 + 0x28;
          }
          *(int *)(*piVar2 + piVar2[2] * 4) = iVar6;
          piVar2[2] = piVar2[2] + 1;
          break;
        }
        iVar4 = iVar4 + -1;
      } while (*piVar5 != iVar6);
      iVar4 = RwGetTextureMipmapRaster(local_4);
      if (iVar4 != 0) {
        piVar2 = (int *)*DAT_1005b798;
        piVar5 = (int *)(*piVar2 + piVar2[2] * 4);
        iVar6 = piVar2[2];
        do {
          piVar5 = piVar5 + -1;
          if (iVar6 == 0) {
            uVar3 = piVar2[1];
            if (uVar3 <= (uint)piVar2[2]) {
              iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*piVar2,uVar3 * 4 + 0xa0);
              if (iVar6 == 0) break;
              *piVar2 = iVar6;
              piVar2[1] = uVar3 + 0x28;
            }
            *(int *)(*piVar2 + piVar2[2] * 4) = iVar4;
            piVar2[2] = piVar2[2] + 1;
            break;
          }
          iVar6 = iVar6 + -1;
        } while (*piVar5 != iVar4);
      }
      uVar7 = uVar7 + 1;
    } while ((int)uVar7 <= iVar1);
  }
  return 1;
}


