// 10031c50 RwSetClumpVertices [Global]
// programa: RWL21.DLL

int RwSetClumpVertices(int param_1,int param_2,int param_3,int param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined3 extraout_var;
  float *pfVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  bool bVar15;
  int iStack_30;
  int local_2c;
  int iStack_28;
  int *piStack_20;
  undefined4 *puStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
                    /* 0x31c50  394  RwSetClumpVertices */
  iVar13 = 0;
  local_2c = 0;
  if (((param_1 == 0) || (param_3 == 0)) || (param_4 == 0)) {
    iVar13 = 0x19;
  }
  else {
    iVar12 = param_4 + -1;
    if (0 < param_4) {
      piVar11 = (int *)(param_2 + iVar12 * 4);
      iVar4 = iVar12;
      do {
        iVar3 = *piVar11;
        if ((iVar3 < -7) || (*(int *)(*(int *)(param_1 + 0x88) + 8) + -7 <= iVar3)) {
          FUN_1000cba0(0x19);
          return 0;
        }
        piVar11 = piVar11 + -1;
        iVar3 = FUN_10041c90(*(int *)(param_1 + 0x88),iVar3);
        iVar13 = iVar13 + (uint)*(ushort *)(iVar3 + 0x6c);
        bVar15 = 0 < iVar4;
        iVar4 = iVar4 + -1;
      } while (bVar15);
    }
    iVar4 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar13 * 4);
    if ((iVar4 != 0) &&
       (local_2c = (**(code **)(PTR_DAT_1005b69c + 0x34c))(iVar13 * 4), local_2c != 0)) {
      iVar13 = RwAddHintToClump(param_1,4);
      if (iVar13 == 0) {
        (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar4);
        (**(code **)(PTR_DAT_1005b69c + 0x358))(local_2c);
        return 0;
      }
      iStack_30 = 0;
      if (0 < param_4) {
        piStack_20 = (int *)(param_2 + iVar12 * 4);
        puVar9 = (undefined4 *)(param_3 + iVar12 * 0xc);
        iStack_28 = iVar12;
        do {
          puVar5 = (undefined4 *)FUN_10041c90(*(int *)(param_1 + 0x88),*piStack_20);
          *puVar5 = *puVar9;
          puVar5[1] = puVar9[1];
          puVar5[2] = puVar9[2];
          uVar1 = *(ushort *)(puVar5 + 0x1b);
          puVar10 = (undefined4 *)puVar5[0x1c];
          puVar14 = (undefined4 *)(iVar4 + iStack_30 * 4);
          for (uVar8 = (uint)uVar1; uVar8 != 0; uVar8 = uVar8 - 1) {
            *puVar14 = *puVar10;
            puVar10 = puVar10 + 1;
            puVar14 = puVar14 + 1;
          }
          iStack_30 = iStack_30 + (uint)uVar1;
          puVar5[0x1a] = puVar5[0x1a] | 0x80000000;
          piStack_20 = piStack_20 + -1;
          bVar15 = 0 < iStack_28;
          puVar9 = puVar9 + -3;
          iStack_28 = iStack_28 + -1;
        } while (bVar15);
      }
      iVar13 = iStack_30 + -1;
      if (0 < iStack_30) {
        piVar11 = (int *)(iVar4 + iVar13 * 4);
        iVar3 = iVar13;
        puVar9 = (undefined4 *)(local_2c + iVar13 * 4);
        do {
          iVar6 = *piVar11;
          piVar11 = piVar11 + -1;
          *puVar9 = *(undefined4 *)(iVar6 + 0x28);
          bVar15 = 0 < iVar3;
          iVar3 = iVar3 + -1;
          puVar9 = puVar9 + -1;
        } while (bVar15);
      }
      if (0 < iStack_30) {
        piVar11 = (int *)(iVar4 + iVar13 * 4);
        iVar3 = iVar13;
        do {
          iVar6 = *piVar11;
          piVar11 = piVar11 + -1;
          *(undefined4 *)(iVar6 + 0x28) = 0;
          bVar15 = 0 < iVar3;
          iVar3 = iVar3 + -1;
        } while (bVar15);
      }
      iStack_28 = iStack_30;
      puStack_1c = (undefined4 *)(iVar4 + iStack_30 * 4);
      do {
        do {
          puStack_1c = puStack_1c + -1;
          bVar15 = iStack_28 == 0;
          iStack_28 = iStack_28 + -1;
          if (bVar15) {
            iVar3 = *(int *)(*(int *)(param_1 + 0x88) + 8);
            iVar6 = iVar3 + -1;
            if (0 < iVar3) {
              iVar3 = iVar6 * 0x74;
              do {
                uVar8 = *(uint *)(*(int *)(param_1 + 0x88) + 0x74 + iVar3);
                if ((int)uVar8 < 0) {
                  *(uint *)(*(int *)(param_1 + 0x88) + 0x74 + iVar3) = uVar8 & 0x7fffffff;
                  FUN_10041df0(*(int *)(param_1 + 0x88) + iVar3 + 0xc);
                  FUN_10041ec0(*(int *)(param_1 + 0x88) + iVar3 + 0xc);
                }
                iVar3 = iVar3 + -0x74;
                bVar15 = 0 < iVar6;
                iVar6 = iVar6 + -1;
              } while (bVar15);
            }
            if (0 < iStack_30) {
              puVar9 = (undefined4 *)(local_2c + iVar13 * 4);
              piVar11 = (int *)(iVar4 + iVar13 * 4);
              do {
                uVar2 = *puVar9;
                iVar3 = *piVar11;
                puVar9 = puVar9 + -1;
                piVar11 = piVar11 + -1;
                *(undefined4 *)(iVar3 + 0x28) = uVar2;
                bVar15 = 0 < iVar13;
                iVar13 = iVar13 + -1;
              } while (bVar15);
            }
            if (0 < param_4) {
              piVar11 = (int *)(param_2 + iVar12 * 4);
              do {
                iVar13 = *piVar11;
                iVar3 = *(int *)(param_1 + 0x88);
                piVar11 = piVar11 + -1;
                pfVar7 = (float *)FUN_10041c90(iVar3,iVar13);
                FUN_100421e0(iVar3,pfVar7);
                bVar15 = 0 < iVar12;
                iVar12 = iVar12 + -1;
              } while (bVar15);
            }
            *(undefined4 *)(param_1 + 0xc0) = 0;
            *(undefined4 *)(param_1 + 200) = 0;
            *(undefined4 *)(param_1 + 0xc4) = 0;
            (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar4);
            (**(code **)(PTR_DAT_1005b69c + 0x358))(local_2c);
            return param_1;
          }
          puVar9 = (undefined4 *)*puStack_1c;
        } while (puVar9[10] != 0);
        puVar9[10] = 1;
        iVar6 = FUN_100321a0((int)puVar9);
        FUN_10001100((int)puVar9,&fStack_18,&fStack_c);
        puVar9[7] = fStack_18;
        puVar9[8] = uStack_14;
        puVar9[9] = uStack_10;
        puVar9[4] = fStack_c;
        puVar9[5] = uStack_8;
        puVar9[6] = uStack_4;
        for (iVar3 = puVar9[0xc]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x30)) {
          FUN_10001100(iVar3,&fStack_18,&fStack_c);
          *(float *)(iVar3 + 0x1c) = fStack_18;
          *(undefined4 *)(iVar3 + 0x20) = uStack_14;
          *(undefined4 *)(iVar3 + 0x24) = uStack_10;
          *(float *)(iVar3 + 0x10) = fStack_c;
          *(undefined4 *)(iVar3 + 0x14) = uStack_8;
          *(undefined4 *)(iVar3 + 0x18) = uStack_4;
        }
      } while ((iVar6 == 0) ||
              (bVar15 = FUN_100320d0(param_1,puVar9), CONCAT31(extraout_var,bVar15) != 0));
      return 0;
    }
    if (iVar4 == 0) {
      FUN_1000cba0(3);
    }
    else {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(iVar4);
    }
    if (local_2c != 0) {
      (**(code **)(PTR_DAT_1005b69c + 0x358))(local_2c);
      return 0;
    }
    iVar13 = 3;
  }
  FUN_1000cba0(iVar13);
  return 0;
}


