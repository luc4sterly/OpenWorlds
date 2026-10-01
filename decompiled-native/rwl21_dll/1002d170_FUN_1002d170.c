// 1002d170 FUN_1002d170 [Global]
// program: RWL21.DLL

bool __fastcall FUN_1002d170(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  undefined3 extraout_var;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  float *pfVar8;
  uint uVar9;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 extraout_EDX_06;
  undefined4 extraout_EDX_07;
  undefined4 extraout_EDX_08;
  undefined4 extraout_EDX_09;
  undefined4 extraout_EDX_10;
  undefined4 uVar10;
  undefined4 extraout_EDX_11;
  uint *puVar11;
  bool bVar12;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  uint *local_14;
  uint local_10;
  uint local_c;
  int local_8;
  int local_4;
  
  bVar12 = true;
  FUN_1002cf80(param_1,param_2,(int)param_3);
  if ((param_3[7] == 0) && ((*param_3 & 1) == 0)) goto LAB_1002d4e4;
  if ((*param_3 & 1) == 0) {
LAB_1002d1b5:
    if ((uint *)param_3[1] == (uint *)0x0) goto LAB_1002d1bc;
    if ((*param_3 & 4) != 0) {
      puVar2 = FUN_1002be50((int)param_3,(uint *)param_3[1]);
      param_3[1] = (uint)puVar2;
      uVar3 = *param_3 & 0xfffffffb;
      *param_3 = uVar3;
      goto LAB_1002d1d8;
    }
  }
  else {
    if ((uint *)param_3[1] != (uint *)0x0) {
      puVar2 = FUN_1002be50((int)param_3,(uint *)param_3[1]);
      param_3[1] = (uint)puVar2;
      *param_3 = *param_3 | 2;
      goto LAB_1002d1b5;
    }
LAB_1002d1bc:
    uVar3 = *param_3;
LAB_1002d1d8:
    *param_3 = uVar3 | 2;
  }
  local_4 = 0;
  if (0 < (int)param_3[7]) {
    local_8 = 0;
    do {
      puVar2 = *(uint **)(param_3[3] + local_8);
      if ((*puVar2 & 2) != 0) {
        if (puVar2[0x11] == 1) {
          FUN_1002d500(puVar2);
        }
        else {
          FUN_1000cba0(0x65);
        }
        *puVar2 = *puVar2 & 0xfffffffd;
      }
      if ((puVar2 == (uint *)0x0) || (puVar2[0x11] != 1)) {
        puVar2 = (uint *)0x0;
      }
      if (puVar2 == (uint *)0x0) {
LAB_1002d2be:
        FUN_1000cba0(0x65);
      }
      else if ((*puVar2 & 8) == 0) {
        FUN_1002d500(puVar2);
        if (((puVar2 == (uint *)0x0) || (puVar2[0x11] == 0)) || ((*puVar2 & 8) != 0)) {
          puVar2 = (uint *)0x0;
        }
        if (puVar2 == (uint *)0x0) goto LAB_1002d2be;
        if ((puVar2[0x11] != 1) ||
           (pfVar8 = (float *)puVar2[0x12], *(char *)(pfVar8 + 0x10) != '\0')) {
          pfVar8 = (float *)0x0;
        }
        if (pfVar8 == (float *)0x0) {
          RwDotProduct(0,extraout_EDX);
          puVar2[0x10] = (uint)(float)extraout_ST0_00;
        }
        else {
          local_14 = (uint *)puVar2[0xd];
          local_10 = puVar2[0xe];
          local_c = puVar2[0xf];
          RwTransformVector((float *)&local_14,pfVar8);
          RwDotProduct(&local_14,extraout_EDX_00);
          puVar2[0x10] = (uint)(float)extraout_ST0;
        }
      }
      local_8 = local_8 + 4;
      local_4 = local_4 + 1;
    } while (local_4 < (int)param_3[7]);
  }
  _qsort((void *)param_3[3],param_3[7],4,(_PtFuncCompare *)&LAB_1002f0f0);
  uVar10 = extraout_EDX_01;
  do {
    if (param_3[7] == 0) break;
    uVar9 = param_3[7] - 1;
    param_3[7] = uVar9;
    puVar2 = *(uint **)(param_3[3] + uVar9 * 4);
    puVar2[5] = 0;
    uVar3 = *puVar2;
    uVar4 = uVar3 & 0xffffff0f;
    *puVar2 = uVar4;
    puVar11 = param_3;
    if ((uVar3 & 8) == 0) {
      puVar5 = (uint *)param_3[1];
      if (puVar5 == (uint *)0x0) {
        *puVar2 = uVar4 | 1;
        param_3[1] = (uint)puVar2;
      }
      else {
        if (puVar5[0x11] == 3) {
          local_14 = puVar5;
          cVar1 = FUN_1002d680(uVar9,uVar10,(float *)(puVar5 + 0x13),puVar2);
          iVar6 = CONCAT31(extraout_var,cVar1);
          if (iVar6 == 1) {
            FUN_1002d8b0(extraout_ECX,extraout_EDX_02,local_14,local_14,puVar2);
            puVar7 = FUN_1002eed0(puVar5[0x19],extraout_EDX_03,(uint *)puVar5[0x19],puVar2);
            uVar10 = extraout_EDX_04;
            if (puVar7 == (uint *)0x0) {
              puVar7 = (uint *)0x0;
            }
            else {
              puVar5[0x19] = (uint)puVar7;
              puVar7 = local_14;
            }
          }
          else {
            puVar7 = local_14;
            uVar10 = extraout_EDX_02;
            if (iVar6 == 2) {
              if ((*local_14 & 4) == 0) {
                uVar3 = *(uint *)local_14[6];
                if ((uVar3 & 2) == 0) {
                  *(uint *)local_14[6] = uVar3 | 1;
                }
                else {
                  iVar6 = FUN_1002da80((uint *)&local_14,puVar2);
                  uVar10 = extraout_EDX_06;
                  if (iVar6 == -1) {
                    puVar7 = (uint *)0x0;
                  }
                  else {
                    puVar7 = local_14;
                    if (iVar6 == 0) {
                      FUN_1002d8b0(extraout_ECX_00,extraout_EDX_06,local_14,local_14,puVar2);
                      *puVar2 = *puVar2 | 0x10;
                      *local_14 = *local_14 | 0x10;
                      puVar7 = (uint *)local_14[6];
                      *puVar7 = *puVar7 | 4;
                      puVar7 = FUN_1002eed0(puVar7,puVar5[0x18],(uint *)puVar5[0x18],puVar2);
                      uVar10 = extraout_EDX_07;
                      if (puVar7 == (uint *)0x0) {
                        puVar7 = (uint *)0x0;
                      }
                      else {
                        puVar5[0x18] = (uint)puVar7;
                        puVar7 = local_14;
                      }
                    }
                  }
                }
              }
              else if ((uint *)local_14[4] == (uint *)0x0) {
                puVar2[5] = (uint)local_14;
                local_14[4] = (uint)puVar2;
              }
              else {
                puVar5 = FUN_1002eed0(*local_14,extraout_EDX_02,(uint *)local_14[4],puVar2);
                uVar10 = extraout_EDX_05;
                if (puVar5 == (uint *)0x0) {
                  puVar7 = (uint *)0x0;
                }
                else {
                  local_14[4] = (uint)puVar5;
                  puVar7 = local_14;
                }
              }
            }
            else if (iVar6 == 3) {
              FUN_1002d8b0(extraout_ECX,extraout_EDX_02,local_14,local_14,puVar2);
              puVar7 = FUN_1002eed0(puVar5[0x18],extraout_EDX_08,(uint *)puVar5[0x18],puVar2);
              uVar10 = extraout_EDX_09;
              if (puVar7 == (uint *)0x0) {
                puVar7 = (uint *)0x0;
              }
              else {
                puVar5[0x18] = (uint)puVar7;
                puVar7 = local_14;
              }
            }
          }
        }
        else {
          puVar7 = FUN_1002e520(puVar5,puVar2);
          uVar10 = extraout_EDX_10;
        }
        *puVar2 = *puVar2 | 1;
        if (puVar7 == (uint *)0x0) {
          puVar11 = (uint *)0x0;
        }
        else {
          param_3[1] = (uint)puVar7;
        }
      }
    }
    else {
      puVar2[4] = param_3[2];
      param_3[2] = (uint)puVar2;
    }
    bVar12 = puVar11 != (uint *)0x0;
    if (((bVar12) && ((*param_3 & 1) != 0)) && ((*param_3 & 2) == 0)) {
      param_3[7] = param_3[7] + 1;
      puVar2 = FUN_1002be50((int)param_3,(uint *)param_3[1]);
      param_3[1] = (uint)puVar2;
      *param_3 = *param_3 | 2;
      uVar10 = extraout_EDX_11;
    }
  } while (bVar12);
LAB_1002d4e4:
  if (bVar12) {
    *param_3 = *param_3 & 0xfffffffc;
  }
  return bVar12;
}


