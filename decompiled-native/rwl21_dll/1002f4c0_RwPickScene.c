// 1002f4c0 RwPickScene [Global]
// programa: RWL21.DLL

int * RwPickScene(uint *param_1,int param_2,int param_3,int param_4,int *param_5)

{
  undefined4 uVar1;
  uint *puVar2;
  bool bVar3;
  bool bVar4;
  uint *puVar5;
  undefined3 extraout_var;
  undefined4 *puVar6;
  undefined4 extraout_ECX;
  int iVar7;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  int iVar8;
  int *piVar9;
  int *piVar10;
  bool bVar11;
  int local_34;
  int local_2c;
  int local_28;
  int aiStack_20 [8];
  
                    /* 0x2f4c0  303  RwPickScene */
  bVar11 = false;
  local_2c = 0;
  bVar3 = false;
  DAT_1005addc = param_4;
  DAT_1005ade0 = param_2;
  DAT_1005ade4 = param_3;
  if (((param_1 == (uint *)0x0) || (param_4 == 0)) || (param_5 == (int *)0x0)) {
    FUN_1000cba0(1);
    param_5 = (int *)0x0;
  }
  else {
    *param_5 = 0;
    if (param_1[8] != 0) {
      uVar1 = *(undefined4 *)(PTR_DAT_1005b69c + 0x10);
      *(int *)(PTR_DAT_1005b69c + 0x10) = DAT_1005addc;
      rwupdateViewMatrix(DAT_1005addc);
      if (*(int *)(DAT_1005addc + 0x8c) == 2) {
        FUN_10041b80(DAT_1005addc,(float *)(DAT_1005addc + 0x74));
        FUN_10041c10();
        *(undefined4 *)(PTR_DAT_1005b69c + 0x2e4) = 0;
        puVar5 = FUN_1002be50((int)param_1,(uint *)param_1[1]);
        param_1[1] = (uint)puVar5;
        FUN_1002cf80(extraout_ECX,extraout_EDX_00,(int)param_1);
        local_34 = 0;
        if (0 < (int)param_1[7]) {
          iVar8 = 0;
          do {
            if ((*(int *)(*(int *)(param_1[3] + iVar8) + 0x44) == 1) &&
               (FUN_10006ff0(*(float **)(*(int *)(param_1[3] + iVar8) + 0x48),DAT_1005ade0,
                             DAT_1005ade4,DAT_1005addc,aiStack_20), aiStack_20[0] != 0)) {
              piVar9 = aiStack_20;
              piVar10 = param_5;
              for (iVar7 = 8; iVar7 != 0; iVar7 = iVar7 + -1) {
                *piVar10 = *piVar9;
                piVar9 = piVar9 + 1;
                piVar10 = piVar10 + 1;
              }
            }
            iVar8 = iVar8 + 4;
            local_34 = local_34 + 1;
          } while (local_34 < (int)param_1[7]);
        }
        FUN_10041c20();
        return param_5;
      }
      bVar4 = FUN_1002d170(DAT_1005addc,extraout_EDX,param_1);
      if (CONCAT31(extraout_var,bVar4) != 0) {
        FUN_1002cae0(extraout_ECX_00,extraout_EDX_01,(uint *)param_1[1]);
        local_34 = param_1[7] - 1;
        if (0 < (int)param_1[7]) {
          local_28 = local_34 * 4;
          do {
            puVar5 = *(uint **)(param_1[3] + local_28);
            if (((*puVar5 & 0x30) == 0) || ((*puVar5 & 0x80) != 0)) {
              if (local_2c != 0) {
                if ((bVar3) || (*param_5 != 0)) {
                  bVar3 = true;
                }
                else {
                  bVar3 = false;
                }
                local_2c = 0;
              }
              FUN_10041c20();
            }
            if ((*puVar5 & 0x80) != 0) {
              puVar2 = (uint *)puVar5[3];
              local_2c = local_2c + 1;
              if ((!bVar3) && (!bVar11)) {
                FUN_10041c40((undefined4 *)puVar2[3]);
                FUN_10041b80(*(int *)(PTR_DAT_1005b69c + 0x10),(float *)(puVar2 + 1));
                FUN_10041c10();
              }
              FUN_1001ec00((undefined4 *)puVar2[3]);
              *puVar2 = *puVar2 & 0xffffff9f;
              *puVar5 = *puVar5 & 0xffffff7f;
            }
            if ((!bVar3) && (!bVar11)) {
              bVar11 = puVar5[0x11] == 1;
              if (bVar11) {
                puVar6 = FUN_10006ff0((float *)puVar5[0x12],DAT_1005ade0,DAT_1005ade4,DAT_1005addc,
                                      aiStack_20);
                bVar11 = puVar6 != (undefined4 *)0x0;
              }
              else {
                FUN_1000cba0(0x65);
              }
              bVar11 = !bVar11;
              if (aiStack_20[0] != 0) {
                piVar9 = aiStack_20;
                piVar10 = param_5;
                for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
                  *piVar10 = *piVar9;
                  piVar9 = piVar9 + 1;
                  piVar10 = piVar10 + 1;
                }
                if (local_2c == 0) {
                  bVar3 = true;
                }
                else {
                  bVar3 = false;
                }
              }
            }
            local_28 = local_28 + -4;
            bVar4 = 0 < local_34;
            local_34 = local_34 + -1;
          } while (bVar4);
        }
        param_1[7] = 0;
        *(undefined4 *)(PTR_DAT_1005b69c + 0x10) = uVar1;
        if (bVar11) {
          param_5 = (int *)0x0;
        }
        FUN_10041c20();
        return param_5;
      }
      return (int *)0x0;
    }
  }
  return param_5;
}


