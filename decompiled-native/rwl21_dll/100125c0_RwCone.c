// 100125c0 RwCone [Global]
// programa: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 RwCone(float param_1,float param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  undefined4 extraout_EDX_03;
  bool bVar11;
  float10 fVar12;
  undefined8 uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined4 uVar17;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
                    /* 0x125c0  34  RwCone */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return 0;
  }
  if ((param_3 < 3) || (ABS(param_2) == 0.0)) {
    iVar4 = 0xb;
LAB_1001296e:
    FUN_1000cba0(iVar4);
    return 0;
  }
  piVar1 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(param_3 * 4 + 4);
  if (piVar1 == (int *)0x0) {
    iVar4 = 3;
    goto LAB_1001296e;
  }
  puVar2 = RwCreateClump(param_3 + 1,param_3);
  if (puVar2 == (undefined4 *)0x0) goto LAB_10012955;
  fStack_10 = _DAT_10052120 / (float)param_3;
  puVar2[0x28] = puVar2[0x28] + 1;
  fStack_28 = 0.0;
  fStack_24 = param_1;
  fStack_20 = 0.0;
  pfVar3 = (float *)FUN_1001d770();
  RwTransformPoint(&fStack_28,pfVar3);
  uVar13 = FUN_10004a90((int)puVar2,fStack_28,fStack_24,fStack_20);
  iVar4 = (int)((ulonglong)uVar13 >> 0x20);
  iStack_c = (int)uVar13;
  uVar17 = extraout_ECX;
  if (iStack_c != 0) {
    iVar4 = FUN_10041c90(puVar2[0x22],iStack_c);
    *(byte *)(iVar4 + 0x48) = *(byte *)(iVar4 + 0x48) | 0x20;
    uVar17 = extraout_ECX_00;
    iVar4 = extraout_EDX;
  }
  *piVar1 = iStack_c;
  if ((iStack_c != 0) && (iVar4 = FUN_1001d760(uVar17,iVar4), iVar4 != 0)) {
    iVar4 = 0;
    bVar11 = param_3 == 0;
    piVar8 = piVar1;
    if (0 < param_3) {
      do {
        fStack_28 = param_2;
        fStack_24 = 0.0;
        fStack_20 = 0.0;
        pfVar3 = (float *)FUN_1001d770();
        RwTransformPoint(&fStack_28,pfVar3);
        iVar5 = FUN_10004a90((int)puVar2,fStack_28,fStack_24,fStack_20);
        if (iVar5 != 0) {
          iVar6 = FUN_10041c90(puVar2[0x22],iVar5);
          *(byte *)(iVar6 + 0x48) = *(byte *)(iVar6 + 0x48) | 0x20;
        }
        piVar8[1] = iVar5;
        if (iVar5 == 0) break;
        fStack_18 = param_2;
        fStack_1c = 0.0;
        uStack_14 = 0;
        fVar12 = rwLengthNormaliseVector(&fStack_1c,&fStack_1c);
        if (fVar12 <= (float10)_DAT_10052110) {
          FUN_1000cba0(0x20);
        }
        else {
          iVar5 = 2;
          fVar14 = fStack_1c;
          fVar15 = fStack_18;
          uVar17 = uStack_14;
          fVar16 = fStack_10;
          uVar7 = FUN_1001d770();
          FUN_1001cac0(uVar7,fVar14,fVar15,uVar17,fVar16,iVar5);
        }
        iVar4 = iVar4 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar4 < param_3);
      bVar11 = iVar4 == param_3;
    }
    if (bVar11) {
      FUN_1001d780();
      bVar11 = param_3 == 0;
      uVar17 = extraout_ECX_01;
      iVar4 = extraout_EDX_00;
      iVar5 = 0;
      if (0 < param_3) {
        while( true ) {
          iVar6 = iVar5 + 1;
          iStack_8 = piVar1[iVar5 % param_3 + 1];
          iStack_4 = piVar1[iVar6 % param_3 + 1];
          piVar8 = FUN_100037e0((uint)puVar2,3,&iStack_c);
          uVar17 = extraout_ECX_02;
          iVar4 = extraout_EDX_01;
          if (piVar8 == (int *)0x0) break;
          piVar9 = (int *)RwCurrentMaterial();
          puVar10 = RwSetPolygonMaterial(piVar8,piVar9);
          uVar17 = extraout_ECX_03;
          iVar4 = extraout_EDX_02;
          if ((puVar10 == (undefined4 *)0x0) || (iVar5 = iVar6, param_3 <= iVar6)) break;
        }
        bVar11 = iVar5 == param_3;
      }
      if ((bVar11) && (iVar4 = FUN_1001d760(uVar17,iVar4), iVar4 != 0)) {
        puVar10 = (undefined4 *)FUN_1001d770();
        FUN_1001c4a0(puVar10);
        if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
          iVar4 = 0x27;
LAB_1001290f:
          FUN_1000cba0(iVar4);
LAB_10012917:
          bVar11 = false;
        }
        else {
          if (puVar2 == (undefined4 *)0x0) {
            iVar4 = 1;
            goto LAB_1001290f;
          }
          uVar17 = 2;
          iVar4 = FUN_1001d770();
          RwTransformClump(extraout_ECX_04,extraout_EDX_03,(uint)puVar2,iVar4,uVar17);
          uVar17 = RwCurrentMaterial();
          iVar4 = RwForAllClumpsInHierarchyPointer((int)puVar2,&LAB_100112e0,uVar17);
          if (iVar4 == 0) goto LAB_10012917;
          iVar5 = *(int *)(DAT_1005dfcc + 0x1c);
          iVar6 = *(int *)(iVar5 + 0x9c) + 1;
          *(int *)(iVar5 + 0x9c) = iVar6;
          iVar4 = *(int *)(iVar5 + 0x98);
          if (iVar6 < iVar4) {
LAB_100128ea:
            iVar4 = *(int *)(iVar5 + 0x9c);
          }
          else {
            iVar4 = (iVar4 >> 1) + iVar4;
            iVar6 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*(undefined4 *)(iVar5 + 0x94),iVar4 * 4)
            ;
            if (iVar6 != 0) {
              *(int *)(iVar5 + 0x94) = iVar6;
              *(int *)(iVar5 + 0x98) = iVar4;
              goto LAB_100128ea;
            }
            *(int *)(iVar5 + 0x9c) = *(int *)(iVar5 + 0x9c) + -1;
            FUN_1000cba0(3);
            iVar4 = -1;
          }
          if (iVar4 == -1) goto LAB_10012917;
          bVar11 = true;
          *(undefined4 **)(*(int *)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94) + iVar4 * 4) = puVar2;
        }
        if (bVar11) {
          FUN_1001d780();
          (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar1);
          return 1;
        }
        FUN_1001d780();
      }
    }
    FUN_1001d780();
  }
  RwDestroyClump(puVar2);
LAB_10012955:
  (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar1);
  return 0;
}


