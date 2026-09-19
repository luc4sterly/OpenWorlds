// 1000f980 FUN_1000f980 [Global]
// programa: RWL21.DLL

undefined4 * FUN_1000f980(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 *puVar8;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar9;
  undefined4 extraout_EDX_01;
  int extraout_EDX_02;
  undefined4 extraout_EDX_03;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_8;
  void *local_4;
  
  iVar7 = *(int *)(DAT_1005dfcc + 0x1c);
  if (iVar7 == 0) {
    FUN_1000cba0(0x22);
    return (undefined4 *)0x0;
  }
  iVar11 = 0;
  iVar10 = 0;
  local_8 = 0;
  if (-1 < *(int *)(iVar7 + 0x9c)) {
    iVar12 = 0;
    do {
      iVar12 = iVar12 + 4;
      iVar11 = iVar11 + 1;
      iVar2 = RwGetClumpNumVertices(*(int *)(*(int *)(iVar7 + 0x94) + -4 + iVar12));
      iVar10 = iVar10 + iVar2;
      iVar2 = RwGetClumpNumPolygons(*(int *)(*(int *)(iVar7 + 0x94) + -4 + iVar12));
      local_8 = local_8 + iVar2;
    } while (iVar11 <= *(int *)(iVar7 + 0x9c));
  }
  iVar11 = 0;
  puVar3 = RwCreateClump(iVar10,local_8);
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[0x28] = puVar3[0x28] + 1;
    uVar5 = extraout_ECX;
    uVar9 = extraout_EDX;
    if (-1 < *(int *)(iVar7 + 0x9c)) {
      iVar10 = 0;
      do {
        uVar4 = FUN_10004bc0((uint)puVar3,*(float **)(*(int *)(iVar7 + 0x94) + iVar10));
        if (uVar4 == 0) {
          RwDestroyClump(puVar3);
          return (undefined4 *)0x0;
        }
        iVar10 = iVar10 + 4;
        iVar11 = iVar11 + 1;
        uVar5 = extraout_ECX_00;
        uVar9 = extraout_EDX_00;
      } while (iVar11 <= *(int *)(iVar7 + 0x9c));
    }
    if (puVar3 != (undefined4 *)0x0) {
      RwTransformClump(uVar5,uVar9,(uint)puVar3,iVar7,1);
      RwTransformClumpJoint(extraout_ECX_01,extraout_EDX_01,(uint)puVar3,iVar7 + 0x44,1);
      uVar5 = RwGetClumpTag(**(int **)(iVar7 + 0x94));
      RwSetClumpTag((int)puVar3,uVar5);
      uVar5 = RwGetClumpData(**(int **)(iVar7 + 0x94));
      RwSetClumpData((int)puVar3,uVar5);
      uVar4 = RwGetClumpHints(**(int **)(iVar7 + 0x94));
      RwSetClumpHints((int)puVar3,uVar4);
      iVar10 = RwGetClumpAxisAlignment(**(int **)(iVar7 + 0x94));
      RwSetClumpAxisAlignment((int)puVar3,iVar10);
      local_8 = 0;
      iVar10 = *(int *)(iVar7 + 0x9c);
      if (-1 < iVar10) {
        local_4 = (void *)0x0;
        iVar11 = extraout_EDX_02;
        do {
          FUN_1001d760(iVar10,iVar11);
          puVar6 = (undefined4 *)FUN_1001d770();
          RwGetClumpLTM(local_4,*(undefined4 **)(*(int *)(iVar7 + 0x94) + (int)local_4),puVar6);
          uVar4 = *(uint *)(*(int *)(*(int *)(iVar7 + 0x94) + (int)local_4) + 0x178);
          while (uVar4 != 0) {
            uVar5 = 3;
            iVar10 = FUN_1001d770();
            RwTransformClump(extraout_ECX_02,extraout_EDX_03,uVar4,iVar10,uVar5);
            uVar1 = *(uint *)(uVar4 + 0x184);
            iVar10 = RwAddChildToClump((int)puVar3,uVar4);
            uVar4 = uVar1;
            if (iVar10 == 0) {
              puVar6 = *(undefined4 **)(DAT_1005dfcc + 0x1c);
              puVar8 = (undefined4 *)(DAT_1005dfcc + 0x18);
              if (puVar6 == (undefined4 *)0x0) {
                FUN_1000cba0(0x22);
              }
              else {
                if ((undefined4 *)*puVar8 == puVar6) {
                  *(undefined4 *)(DAT_1005dfcc + 0x1c) = 0;
                  *puVar8 = 0;
                }
                else {
                  *(undefined4 *)(DAT_1005dfcc + 0x1c) = puVar6[0x28];
                }
                FUN_1000f440(puVar6);
              }
              RwDestroyClump(puVar3);
              return (undefined4 *)0x0;
            }
          }
          FUN_1001d780();
          local_4 = (void *)((int)local_4 + 4);
          iVar10 = local_8 + 1;
          iVar11 = *(int *)(iVar7 + 0x9c);
          local_8 = iVar10;
        } while (iVar10 <= iVar11);
      }
      puVar6 = *(undefined4 **)(DAT_1005dfcc + 0x1c);
      puVar8 = (undefined4 *)(DAT_1005dfcc + 0x18);
      if (puVar6 == (undefined4 *)0x0) {
        FUN_1000cba0(0x22);
      }
      else {
        if ((undefined4 *)*puVar8 == puVar6) {
          *(undefined4 *)(DAT_1005dfcc + 0x1c) = 0;
          *puVar8 = 0;
        }
        else {
          *(undefined4 *)(DAT_1005dfcc + 0x1c) = puVar6[0x28];
        }
        iVar7 = FUN_1000f440(puVar6);
        if (iVar7 != 0) {
          if (*(int *)(DAT_1005dfcc + 0x1c) != 0) {
            iVar7 = RwAddChildToClump(**(int **)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94),(uint)puVar3)
            ;
            if (iVar7 != 0) {
              return puVar3;
            }
            RwDestroyClump(puVar3);
            return (undefined4 *)0x0;
          }
          if (*(int *)(DAT_1005dfcc + 4) == 0) {
            return puVar3;
          }
          RwDestroyClump(puVar3);
          FUN_1000cba0(0x23);
          return (undefined4 *)0x0;
        }
      }
      RwDestroyClump(puVar3);
      return (undefined4 *)0x0;
    }
  }
  return puVar3;
}


