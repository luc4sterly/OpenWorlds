// 10010ea0 RwBlock [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 RwBlock(float param_1,float param_2,float param_3)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  float *pfVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_EDX;
  int extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int **ppiVar9;
  uint uVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 uVar14;
  int *local_54;
  int *local_50;
  int *local_4c;
  int *local_48;
  int *local_44 [6];
  int *local_2c [8];
  int *local_c;
  int *local_8;
  int *local_4;
  
                    /* 0x10ea0  22  RwBlock */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return 0;
  }
  if (ABS(param_1) == 0.0) {
    return 0;
  }
  if (ABS(param_2) == 0.0) {
    return 0;
  }
  if (ABS(param_3) == 0.0) {
    return 0;
  }
  puVar3 = RwCreateClump(8,6);
  if (puVar3 == (undefined4 *)0x0) {
    return 0;
  }
  puVar3[0x28] = puVar3[0x28] + 1;
  iVar4 = FUN_1001d760(extraout_ECX,extraout_EDX);
  if (iVar4 == 0) goto LAB_100112c4;
  fVar13 = param_3 * _DAT_10052114;
  fVar12 = param_2 * _DAT_10052114;
  fVar11 = param_1 * _DAT_10052114;
  iVar4 = 2;
  uVar10 = 0;
  pfVar5 = (float *)FUN_1001d770();
  FUN_1001c940(pfVar5,fVar11,fVar12,fVar13,iVar4);
  do {
    local_44[2] = _DAT_1005211c;
    if ((uVar10 & 4) != 0) {
      local_44[2] = _DAT_10052118;
    }
    local_44[1] = _DAT_1005211c;
    if ((uVar10 & 2) != 0) {
      local_44[1] = _DAT_10052118;
    }
    local_44[0] = _DAT_1005211c;
    if ((uVar10 & 1) != 0) {
      local_44[0] = _DAT_10052118;
    }
    local_c = local_44[0];
    local_8 = local_44[1];
    local_4 = local_44[2];
    pfVar5 = (float *)FUN_1001d770();
    RwTransformPoint((float *)local_44,pfVar5);
    piVar6 = (int *)FUN_10004a90((int)puVar3,(float)local_44[0],(float)local_44[1],
                                 (float)local_44[2]);
    if (piVar6 != (int *)0x0) {
      iVar4 = FUN_10041c90(puVar3[0x22],(int)piVar6);
      *(byte *)(iVar4 + 0x48) = *(byte *)(iVar4 + 0x48) | 0x20;
    }
    local_2c[uVar10] = piVar6;
  } while ((piVar6 != (int *)0x0) && (uVar10 = uVar10 + 1, (int)uVar10 < 8));
  if (uVar10 == 8) {
    FUN_1001d780();
    local_54 = local_2c[1];
    local_50 = local_2c[0];
    local_4c = local_2c[2];
    local_48 = local_2c[3];
    local_44[0] = FUN_100037e0((uint)puVar3,4,(int *)&local_54);
    if (local_44[0] != (int *)0x0) {
      local_54 = local_2c[4];
      local_50 = local_2c[5];
      local_4c = local_2c[7];
      local_48 = local_2c[6];
      local_44[1] = FUN_100037e0((uint)puVar3,4,(int *)&local_54);
      if (local_44[1] != (int *)0x0) {
        local_54 = local_2c[2];
        local_50 = local_2c[6];
        local_4c = local_2c[7];
        local_48 = local_2c[3];
        local_44[2] = FUN_100037e0((uint)puVar3,4,(int *)&local_54);
        if (local_44[2] != (int *)0x0) {
          local_54 = local_2c[0];
          local_50 = local_2c[1];
          local_4c = local_2c[5];
          local_48 = local_2c[4];
          local_44[3] = FUN_100037e0((uint)puVar3,4,(int *)&local_54);
          if (local_44[3] != (int *)0x0) {
            local_54 = local_2c[0];
            local_50 = local_2c[4];
            local_4c = local_2c[6];
            local_48 = local_2c[2];
            local_44[4] = FUN_100037e0((uint)puVar3,4,(int *)&local_54);
            if (local_44[4] != (int *)0x0) {
              local_54 = local_2c[5];
              local_50 = local_2c[1];
              local_4c = local_2c[3];
              local_48 = local_2c[7];
              local_44[5] = FUN_100037e0((uint)puVar3,4,(int *)&local_54);
              if (local_44[5] != (int *)0x0) {
                iVar4 = 0;
                ppiVar9 = local_44;
                do {
                  piVar6 = (int *)RwCurrentMaterial();
                  puVar7 = RwSetPolygonMaterial(*ppiVar9,piVar6);
                  if (puVar7 == (undefined4 *)0x0) break;
                  ppiVar9 = ppiVar9 + 1;
                  iVar4 = iVar4 + 1;
                } while (ppiVar9 < local_2c);
                if ((iVar4 == 6) &&
                   (iVar4 = FUN_1001d760(extraout_ECX_00,extraout_EDX_00), iVar4 != 0)) {
                  puVar7 = (undefined4 *)FUN_1001d770();
                  FUN_1001c4a0(puVar7);
                  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
                    iVar4 = 0x27;
LAB_10011298:
                    FUN_1000cba0(iVar4);
LAB_100112a0:
                    bVar2 = false;
                  }
                  else {
                    if (puVar3 == (undefined4 *)0x0) {
                      iVar4 = 1;
                      goto LAB_10011298;
                    }
                    uVar14 = 2;
                    iVar4 = FUN_1001d770();
                    RwTransformClump(extraout_ECX_01,extraout_EDX_01,(uint)puVar3,iVar4,uVar14);
                    uVar14 = RwCurrentMaterial();
                    iVar4 = RwForAllClumpsInHierarchyPointer((int)puVar3,&LAB_100112e0,uVar14);
                    if (iVar4 == 0) goto LAB_100112a0;
                    iVar1 = *(int *)(DAT_1005dfcc + 0x1c);
                    iVar8 = *(int *)(iVar1 + 0x9c) + 1;
                    *(int *)(iVar1 + 0x9c) = iVar8;
                    iVar4 = *(int *)(iVar1 + 0x98);
                    if (iVar8 < iVar4) {
LAB_10011273:
                      iVar4 = *(int *)(iVar1 + 0x9c);
                    }
                    else {
                      iVar4 = (iVar4 >> 1) + iVar4;
                      iVar8 = (**(code **)(PTR_DAT_1005b69c + 0x354))
                                        (*(undefined4 *)(iVar1 + 0x94),iVar4 * 4);
                      if (iVar8 != 0) {
                        *(int *)(iVar1 + 0x94) = iVar8;
                        *(int *)(iVar1 + 0x98) = iVar4;
                        goto LAB_10011273;
                      }
                      *(int *)(iVar1 + 0x9c) = *(int *)(iVar1 + 0x9c) + -1;
                      FUN_1000cba0(3);
                      iVar4 = -1;
                    }
                    if (iVar4 == -1) goto LAB_100112a0;
                    bVar2 = true;
                    *(undefined4 **)(*(int *)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94) + iVar4 * 4) =
                         puVar3;
                  }
                  if (bVar2) {
                    FUN_1001d780();
                    return 1;
                  }
                  FUN_1001d780();
                }
              }
            }
          }
        }
      }
    }
  }
  FUN_1001d780();
LAB_100112c4:
  RwDestroyClump(puVar3);
  return 0;
}


