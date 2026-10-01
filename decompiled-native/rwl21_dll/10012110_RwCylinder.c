// 10012110 RwCylinder [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 RwCylinder(float param_1,float param_2,float param_3,float param_4)

{
  bool bVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  undefined4 extraout_EDX_03;
  float fVar12;
  float10 fVar13;
  float fVar14;
  float fVar15;
  undefined4 uVar16;
  float fStack_44;
  int *piStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
                    /* 0x12110  54  RwCylinder */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return 0;
  }
  if (((((int)param_4 < 3) || (ABS(param_2) == 0.0)) || (ABS(param_3) == 0.0)) ||
     ((((uint)param_2 < 0x80000001 || ((uint)param_3 < 0x80000001)) &&
      (((int)param_2 < 1 || ((int)param_3 < 1)))))) {
    FUN_1000cba0(0xb);
    return 0;
  }
  piVar2 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))((int)param_4 * 8);
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(3);
    return 0;
  }
  puVar3 = RwCreateClump((int)param_4 * 2,(int)param_4);
  if (puVar3 == (undefined4 *)0x0) goto LAB_10012512;
  puVar3[0x28] = puVar3[0x28] + 1;
  fStack_38 = param_4;
  fStack_14 = _DAT_10052120 / (float)(int)param_4;
  iVar4 = FUN_1001d760(extraout_ECX,extraout_EDX);
  if (iVar4 != 0) {
    fStack_44 = 0.0;
    if (0 < (int)param_4) {
      piVar8 = piVar2 + (int)param_4;
      piStack_3c = piVar2;
      do {
        fStack_38 = param_2;
        fStack_34 = 0.0;
        fStack_30 = 0.0;
        pfVar5 = (float *)FUN_1001d770();
        RwTransformPoint(&fStack_38,pfVar5);
        iVar4 = FUN_10004a90((int)puVar3,fStack_38,fStack_34,fStack_30);
        if (iVar4 != 0) {
          iVar6 = FUN_10041c90(puVar3[0x22],iVar4);
          *(byte *)(iVar6 + 0x48) = *(byte *)(iVar6 + 0x48) | 0x20;
        }
        *piStack_3c = iVar4;
        if (iVar4 == 0) break;
        fStack_20 = param_3;
        fStack_1c = param_1;
        fStack_18 = 0.0;
        pfVar5 = (float *)FUN_1001d770();
        RwTransformPoint(&fStack_20,pfVar5);
        iVar4 = FUN_10004a90((int)puVar3,fStack_20,fStack_1c,fStack_18);
        if (iVar4 != 0) {
          iVar6 = FUN_10041c90(puVar3[0x22],iVar4);
          *(byte *)(iVar6 + 0x48) = *(byte *)(iVar6 + 0x48) | 0x20;
        }
        *piVar8 = iVar4;
        if (iVar4 == 0) break;
        fStack_28 = param_2;
        fStack_2c = 0.0;
        uStack_24 = 0;
        fVar13 = rwLengthNormaliseVector(&fStack_2c,&fStack_2c);
        if (fVar13 <= (float10)_DAT_10052110) {
          FUN_1000cba0(0x20);
        }
        else {
          iVar4 = 2;
          fVar12 = fStack_2c;
          fVar14 = fStack_28;
          uVar16 = uStack_24;
          fVar15 = fStack_14;
          uVar7 = FUN_1001d770();
          FUN_1001cac0(uVar7,fVar12,fVar14,uVar16,fVar15,iVar4);
        }
        piVar8 = piVar8 + 1;
        piStack_3c = piStack_3c + 1;
        fStack_44 = (float)((int)fStack_44 + 1);
      } while ((int)fStack_44 < (int)param_4);
    }
    if (param_4 == fStack_44) {
      FUN_1001d780();
      fStack_44 = 0.0;
      uVar16 = extraout_ECX_00;
      iVar4 = extraout_EDX_00;
      if (0 < (int)param_4) {
        while( true ) {
          fVar12 = (float)((int)fStack_44 + 1);
          iStack_10 = piVar2[(int)fStack_44 % (int)param_4];
          iStack_c = piVar2[(int)fVar12 % (int)param_4];
          iStack_8 = piVar2[(int)fVar12 % (int)param_4 + (int)param_4];
          iStack_4 = piVar2[(int)fStack_44 % (int)param_4 + (int)param_4];
          piVar8 = FUN_100037e0((uint)puVar3,4,&iStack_10);
          uVar16 = extraout_ECX_01;
          iVar4 = extraout_EDX_01;
          if (piVar8 == (int *)0x0) break;
          piVar9 = (int *)RwCurrentMaterial();
          puVar10 = RwSetPolygonMaterial(piVar8,piVar9);
          uVar16 = extraout_ECX_02;
          iVar4 = extraout_EDX_02;
          if ((puVar10 == (undefined4 *)0x0) || (fStack_44 = fVar12, (int)param_4 <= (int)fVar12))
          break;
        }
      }
      if ((param_4 == fStack_44) && (iVar4 = FUN_1001d760(uVar16,iVar4), iVar4 != 0)) {
        puVar10 = (undefined4 *)FUN_1001d770();
        FUN_1001c4a0(puVar10);
        if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
          iVar4 = 0x27;
LAB_100124cd:
          FUN_1000cba0(iVar4);
LAB_100124d5:
          bVar1 = false;
        }
        else {
          if (puVar3 == (undefined4 *)0x0) {
            iVar4 = 1;
            goto LAB_100124cd;
          }
          uVar16 = 2;
          iVar4 = FUN_1001d770();
          RwTransformClump(extraout_ECX_03,extraout_EDX_03,(uint)puVar3,iVar4,uVar16);
          uVar16 = RwCurrentMaterial();
          iVar4 = RwForAllClumpsInHierarchyPointer((int)puVar3,&LAB_100112e0,uVar16);
          if (iVar4 == 0) goto LAB_100124d5;
          iVar6 = *(int *)(DAT_1005dfcc + 0x1c);
          iVar11 = *(int *)(iVar6 + 0x9c) + 1;
          *(int *)(iVar6 + 0x9c) = iVar11;
          iVar4 = *(int *)(iVar6 + 0x98);
          if (iVar11 < iVar4) {
LAB_100124a8:
            iVar4 = *(int *)(iVar6 + 0x9c);
          }
          else {
            iVar4 = (iVar4 >> 1) + iVar4;
            iVar11 = (**(code **)(PTR_DAT_1005b69c + 0x354))
                               (*(undefined4 *)(iVar6 + 0x94),iVar4 * 4);
            if (iVar11 != 0) {
              *(int *)(iVar6 + 0x94) = iVar11;
              *(int *)(iVar6 + 0x98) = iVar4;
              goto LAB_100124a8;
            }
            *(int *)(iVar6 + 0x9c) = *(int *)(iVar6 + 0x9c) + -1;
            FUN_1000cba0(3);
            iVar4 = -1;
          }
          if (iVar4 == -1) goto LAB_100124d5;
          bVar1 = true;
          *(undefined4 **)(*(int *)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94) + iVar4 * 4) = puVar3;
        }
        if (bVar1) {
          FUN_1001d780();
          (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar2);
          return 1;
        }
        FUN_1001d780();
      }
    }
    FUN_1001d780();
  }
  RwDestroyClump(puVar3);
LAB_10012512:
  (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar2);
  return 0;
}


