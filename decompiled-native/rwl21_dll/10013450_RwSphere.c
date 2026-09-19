// 10013450 RwSphere [Global]
// programa: RWL21.DLL

int RwSphere(float param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  float *pfVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar10;
  int extraout_ECX_02;
  undefined4 extraout_ECX_03;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int extraout_EDX_02;
  int extraout_EDX_03;
  int extraout_EDX_04;
  int extraout_EDX_05;
  int extraout_EDX_06;
  undefined4 extraout_EDX_07;
  int iVar11;
  int iVar12;
  bool bVar13;
  float fVar14;
  float fVar15;
  undefined4 uVar16;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int *piStack_8;
  int iStack_4;
  
                    /* 0x13450  493  RwSphere */
  if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
    FUN_1000cba0(0x27);
    return 0;
  }
  if ((param_2 < 0) || (ABS(param_1) == 0.0)) {
    FUN_1000cba0(0xb);
    return 0;
  }
  if (param_2 == 0) {
    iVar1 = RwBlock(param_1,param_1,param_1);
    return iVar1;
  }
  iVar1 = param_2 * param_2;
  piVar2 = (int *)(**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar1 * 0x10 + 8);
  if (piVar2 == (int *)0x0) {
    FUN_1000cba0(3);
    return 0;
  }
  puVar3 = RwCreateClump(iVar1 * 4 + 2,iVar1 * 8);
  iVar1 = 0;
  if (puVar3 == (undefined4 *)0x0) goto LAB_10013949;
  puVar3[0x28] = puVar3[0x28] + 1;
  iVar4 = FUN_1001d760(extraout_ECX,extraout_EDX);
  iVar1 = 0;
  if ((iVar4 != 0) != 0) {
    iVar1 = 2;
    fVar14 = param_1;
    fVar15 = param_1;
    pfVar5 = (float *)FUN_1001d770();
    FUN_1001c940(pfVar5,param_1,fVar14,fVar15,iVar1);
    uVar6 = FUN_100139a0((uint)(iVar4 != 0),(int)puVar3,param_2,piVar2);
    iVar1 = 0;
    if (uVar6 != 0) {
      iStack_2c = 1;
      iStack_24 = param_2;
      iVar4 = extraout_EDX_00;
      iVar11 = 0;
LAB_10013554:
      iVar1 = iStack_2c;
      if (iStack_24 != 0) {
        iStack_28 = 4;
        iStack_4 = iVar11;
        do {
          do {
            if ((uVar6 == 0) || (bVar13 = iStack_28 == 0, iStack_28 = iStack_28 + -1, bVar13))
            goto LAB_100136b7;
            iStack_10 = iStack_24;
          } while (uVar6 == 0);
          piStack_8 = piVar2 + iStack_2c;
          iVar10 = iVar11;
          do {
            iVar11 = iVar10;
            if (param_2 <= iStack_10) break;
            piStack_8 = piStack_8 + 1;
            iVar12 = iStack_2c + 1;
            iVar11 = iVar10 + 1;
            iStack_1c = piVar2[iVar10];
            iStack_18 = piVar2[iStack_2c];
            iStack_14 = *piStack_8;
            iStack_c = iVar10;
            piVar7 = FUN_100037e0((uint)puVar3,3,&iStack_1c);
            uVar6 = 0;
            iVar4 = extraout_EDX_01;
            if (piVar7 != (int *)0x0) {
              iVar4 = iVar11;
              if (iVar11 == iVar1) {
                iVar4 = iStack_4;
              }
              iStack_1c = piVar2[iVar4];
              iStack_18 = piVar2[iStack_c];
              iStack_14 = *piStack_8;
              piVar7 = FUN_100037e0((uint)puVar3,3,&iStack_1c);
              uVar6 = (uint)(piVar7 != (int *)0x0);
              iVar4 = extraout_EDX_02;
            }
            iStack_10 = iStack_10 + 1;
            iVar10 = iVar11;
            iStack_2c = iVar12;
          } while (uVar6 != 0);
          if (uVar6 == 0) goto LAB_100136b7;
          iVar4 = iVar11;
          if (iStack_28 == 0) {
            iVar4 = iStack_4;
          }
          iStack_1c = piVar2[iVar4];
          iStack_18 = piVar2[iStack_2c];
          iVar4 = iStack_2c + 1;
          if (iStack_28 == 0) {
            iVar4 = iVar1;
          }
          iStack_14 = piVar2[iVar4];
          piVar7 = FUN_100037e0((uint)puVar3,3,&iStack_1c);
          uVar6 = (uint)(piVar7 != (int *)0x0);
          iVar4 = extraout_EDX_03;
          iStack_2c = iStack_2c + 1;
        } while( true );
      }
      goto LAB_100136c3;
    }
    goto LAB_1001393a;
  }
  goto LAB_1001393f;
LAB_100136b7:
  iVar11 = iVar1;
  iStack_24 = iStack_24 + -1;
  if (uVar6 == 0) goto LAB_100136c3;
  goto LAB_10013554;
LAB_10013816:
  iStack_24 = iStack_24 + 1;
  iVar11 = iVar1;
  if (uVar6 == 0) goto LAB_1001382b;
  goto LAB_100136d3;
LAB_1001382b:
  iVar1 = 0;
  if (uVar6 != 0) {
    iVar4 = FUN_1001d760(iVar10,iVar4);
    iVar1 = 0;
    if (iVar4 != 0) {
      puVar9 = (undefined4 *)FUN_1001d770();
      FUN_1001c4a0(puVar9);
      if (*(int *)(DAT_1005dfcc + 0x1c) == 0) {
        iVar1 = 0x27;
LAB_1001392b:
        FUN_1000cba0(iVar1);
LAB_10013933:
        iVar1 = 0;
      }
      else {
        if (puVar3 == (undefined4 *)0x0) {
          iVar1 = 1;
          goto LAB_1001392b;
        }
        uVar16 = 2;
        iVar1 = FUN_1001d770();
        RwTransformClump(extraout_ECX_03,extraout_EDX_07,(uint)puVar3,iVar1,uVar16);
        uVar16 = RwCurrentMaterial();
        iVar1 = RwForAllClumpsInHierarchyPointer((int)puVar3,&LAB_100112e0,uVar16);
        if (iVar1 == 0) goto LAB_10013933;
        iVar4 = *(int *)(DAT_1005dfcc + 0x1c);
        iVar11 = *(int *)(iVar4 + 0x9c) + 1;
        *(int *)(iVar4 + 0x9c) = iVar11;
        iVar1 = *(int *)(iVar4 + 0x98);
        if (iVar11 < iVar1) {
LAB_10013906:
          iVar1 = *(int *)(iVar4 + 0x9c);
        }
        else {
          iVar1 = (iVar1 >> 1) + iVar1;
          iVar11 = (**(code **)(PTR_DAT_1005b69c + 0x354))(*(undefined4 *)(iVar4 + 0x94),iVar1 * 4);
          if (iVar11 != 0) {
            *(int *)(iVar4 + 0x94) = iVar11;
            *(int *)(iVar4 + 0x98) = iVar1;
            goto LAB_10013906;
          }
          *(int *)(iVar4 + 0x9c) = *(int *)(iVar4 + 0x9c) + -1;
          FUN_1000cba0(3);
          iVar1 = -1;
        }
        if (iVar1 == -1) goto LAB_10013933;
        *(undefined4 **)(*(int *)(*(int *)(DAT_1005dfcc + 0x1c) + 0x94) + iVar1 * 4) = puVar3;
        iVar1 = 1;
      }
      FUN_1001d780();
    }
  }
  goto LAB_1001393a;
LAB_100136c3:
  iStack_24 = 0;
  iVar1 = 0;
  if (uVar6 != 0) {
LAB_100136d3:
    iVar1 = iStack_2c;
    iVar10 = iStack_24;
    if (iStack_24 < param_2) {
      iStack_28 = 4;
      iStack_4 = iVar11;
      do {
        do {
          if ((uVar6 == 0) ||
             (bVar13 = iStack_28 == 0, iStack_28 = iStack_28 + -1, iVar10 = iStack_28, bVar13))
          goto LAB_10013816;
          iStack_10 = iStack_24 + 1;
        } while (uVar6 == 0);
        do {
          iVar10 = param_2;
          iVar12 = iVar11;
          if (param_2 <= iStack_10) break;
          iVar12 = iVar11 + 1;
          iStack_c = iStack_2c;
          iVar8 = iStack_2c + 1;
          iStack_1c = piVar2[iVar11];
          iStack_18 = piVar2[iStack_2c];
          iStack_14 = piVar2[iVar12];
          piVar7 = FUN_100037e0((uint)puVar3,3,&iStack_1c);
          uVar6 = 0;
          iVar10 = extraout_ECX_00;
          iVar4 = extraout_EDX_04;
          if (piVar7 != (int *)0x0) {
            iStack_1c = piVar2[iVar12];
            iStack_18 = piVar2[iStack_c];
            iVar4 = iVar8;
            if (iVar12 - iVar1 == -1) {
              iVar4 = iVar1;
            }
            iStack_14 = piVar2[iVar4];
            piVar7 = FUN_100037e0((uint)puVar3,3,&iStack_1c);
            uVar6 = (uint)(piVar7 != (int *)0x0);
            iVar10 = extraout_ECX_01;
            iVar4 = extraout_EDX_05;
          }
          iStack_10 = iStack_10 + 1;
          iVar11 = iVar12;
          iStack_2c = iVar8;
        } while (uVar6 != 0);
        if (uVar6 == 0) goto LAB_10013816;
        iStack_1c = piVar2[iVar12];
        iVar11 = iVar12 + 1;
        iVar4 = iStack_2c;
        if (iStack_28 == 0) {
          iVar4 = iVar1;
        }
        iStack_18 = piVar2[iVar4];
        iVar4 = iVar11;
        if (iStack_28 == 0) {
          iVar4 = iStack_4;
        }
        iStack_14 = piVar2[iVar4];
        piVar7 = FUN_100037e0((uint)puVar3,3,&iStack_1c);
        uVar6 = (uint)(piVar7 != (int *)0x0);
        iVar4 = extraout_EDX_06;
        iVar10 = extraout_ECX_02;
      } while( true );
    }
    goto LAB_1001382b;
  }
LAB_1001393a:
  FUN_1001d780();
LAB_1001393f:
  if (iVar1 == 0) {
    RwDestroyClump(puVar3);
  }
LAB_10013949:
  (**(code **)(PTR_DAT_1005b69c + 0x358))(piVar2);
  return iVar1;
}


