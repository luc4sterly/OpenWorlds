// 10012bd0 RwHemisphere [Global]
// program: RWL21.DLL

int RwHemisphere(float param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  float *pfVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  undefined4 extraout_ECX_03;
  int extraout_EDX;
  int extraout_EDX_00;
  int iVar10;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  undefined4 extraout_EDX_04;
  int iVar11;
  bool bVar12;
  float fVar13;
  float fVar14;
  undefined4 uVar15;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
                    /* 0x12bd0  272  RwHemisphere */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return 0;
  }
  if ((param_2 < 1) || (ABS(param_1) == 0.0)) {
    FUN_1000cba0(0xb);
    return 0;
  }
  iVar11 = param_2 * param_2 * 2 + param_2 * 2 + 1;
  piVar1 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar11 * 4);
  if (piVar1 == (int *)0x0) {
    FUN_1000cba0(3);
    return 0;
  }
  puVar2 = RwCreateClump(iVar11,param_2 * param_2 * 4);
  iVar11 = 0;
  if (puVar2 == (undefined4 *)0x0) goto LAB_10012f53;
  puVar2[0x28] = puVar2[0x28] + 1;
  iVar3 = FUN_1001d760(extraout_ECX,extraout_EDX);
  iVar11 = 0;
  if ((iVar3 != 0) != 0) {
    iVar11 = 2;
    fVar13 = param_1;
    fVar14 = param_1;
    pfVar4 = (float *)FUN_1001d770();
    FUN_1001c940(pfVar4,param_1,fVar13,fVar14,iVar11);
    uVar5 = FUN_10012fa0((uint)(iVar3 != 0),(int)puVar2,param_2,piVar1);
    iVar11 = 0;
    if (uVar5 != 0) {
      iStack_28 = 0;
      iStack_2c = 1;
      iStack_20 = param_2;
      iVar3 = extraout_EDX_00;
LAB_10012cc2:
      iVar9 = iStack_20 + -1;
      if (iStack_20 != 0) {
        iStack_24 = 4;
        iStack_c = iStack_2c;
        iStack_4 = iStack_28;
        iVar9 = iStack_28;
        do {
          do {
            if ((uVar5 == 0) ||
               (bVar12 = iStack_24 == 0, iStack_24 = iStack_24 + -1, iVar9 = iStack_24, bVar12))
            goto LAB_10012e25;
            iStack_10 = iStack_20;
          } while (uVar5 == 0);
          piVar7 = piVar1 + iStack_2c;
          do {
            iVar9 = param_2;
            if (param_2 <= iStack_10) break;
            piVar7 = piVar7 + 1;
            iStack_8 = iStack_28;
            iVar11 = iStack_2c + 1;
            iVar10 = iStack_28 + 1;
            iStack_1c = piVar1[iStack_28];
            iStack_18 = piVar1[iStack_2c];
            iStack_14 = *piVar7;
            piVar6 = FUN_100037e0((uint)puVar2,3,&iStack_1c);
            uVar5 = 0;
            iVar9 = extraout_ECX_00;
            iVar3 = extraout_EDX_01;
            if (piVar6 != (int *)0x0) {
              iVar3 = iVar10;
              if (iVar10 == iStack_c) {
                iVar3 = iStack_4;
              }
              iStack_1c = piVar1[iVar3];
              iStack_18 = piVar1[iStack_8];
              iStack_14 = *piVar7;
              piVar6 = FUN_100037e0((uint)puVar2,3,&iStack_1c);
              uVar5 = (uint)(piVar6 != (int *)0x0);
              iVar9 = extraout_ECX_01;
              iVar3 = extraout_EDX_02;
            }
            iStack_10 = iStack_10 + 1;
            iStack_2c = iVar11;
            iStack_28 = iVar10;
          } while (uVar5 != 0);
          if (uVar5 == 0) goto LAB_10012e25;
          iVar11 = iStack_28;
          if (iStack_24 == 0) {
            iVar11 = iStack_4;
          }
          iStack_1c = piVar1[iVar11];
          iStack_18 = piVar1[iStack_2c];
          iVar11 = iStack_2c + 1;
          if (iStack_24 == 0) {
            iVar11 = iStack_c;
          }
          iStack_14 = piVar1[iVar11];
          piVar7 = FUN_100037e0((uint)puVar2,3,&iStack_1c);
          uVar5 = (uint)(piVar7 != (int *)0x0);
          iVar3 = extraout_EDX_03;
          iStack_2c = iStack_2c + 1;
          iVar9 = extraout_ECX_02;
        } while( true );
      }
      goto LAB_10012e35;
    }
    goto LAB_10012f44;
  }
LAB_10012f49:
  if (iVar11 == 0) {
    RwDestroyClump(puVar2);
  }
LAB_10012f53:
  (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar1);
  return iVar11;
LAB_10012e25:
  iStack_28 = iStack_c;
  iStack_20 = iStack_20 + -1;
  if (uVar5 == 0) goto LAB_10012e35;
  goto LAB_10012cc2;
LAB_10012e35:
  iVar11 = 0;
  if (uVar5 != 0) {
    iVar3 = FUN_1001d760(iVar9,iVar3);
    iVar11 = 0;
    if (iVar3 != 0) {
      puVar8 = (undefined4 *)FUN_1001d770();
      FUN_1001c4a0(puVar8);
      if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
        iVar11 = 0x27;
LAB_10012f35:
        FUN_1000cba0(iVar11);
LAB_10012f3d:
        iVar11 = 0;
      }
      else {
        if (puVar2 == (undefined4 *)0x0) {
          iVar11 = 1;
          goto LAB_10012f35;
        }
        uVar15 = 2;
        iVar11 = FUN_1001d770();
        RwTransformClump(extraout_ECX_03,extraout_EDX_04,(uint)puVar2,iVar11,uVar15);
        uVar15 = RwCurrentMaterial();
        iVar11 = RwForAllClumpsInHierarchyPointer((int)puVar2,&LAB_100112e0,uVar15);
        if (iVar11 == 0) goto LAB_10012f3d;
        iVar3 = *(int *)(DAT_1005dfcc + 0x1c);
        iVar9 = *(int *)(iVar3 + 0x9c) + 1;
        *(int *)(iVar3 + 0x9c) = iVar9;
        iVar11 = *(int *)(iVar3 + 0x98);
        if (iVar9 < iVar11) {
LAB_10012f10:
          iVar11 = *(int *)(iVar3 + 0x9c);
        }
        else {
          iVar11 = (iVar11 >> 1) + iVar11;
          iVar9 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*(undefined4 *)(iVar3 + 0x94),iVar11 * 4);
          if (iVar9 != 0) {
            *(int *)(iVar3 + 0x94) = iVar9;
            *(int *)(iVar3 + 0x98) = iVar11;
            goto LAB_10012f10;
          }
          *(int *)(iVar3 + 0x9c) = *(int *)(iVar3 + 0x9c) + -1;
          FUN_1000cba0(3);
          iVar11 = -1;
        }
        if (iVar11 == -1) goto LAB_10012f3d;
        *(undefined4 **)(*(int *)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94) + iVar11 * 4) = puVar2;
        iVar11 = 1;
      }
      FUN_1001d780();
    }
  }
LAB_10012f44:
  FUN_1001d780();
  goto LAB_10012f49;
}


