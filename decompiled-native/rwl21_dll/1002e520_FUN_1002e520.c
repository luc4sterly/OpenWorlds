// 1002e520 FUN_1002e520 [Global]
// programa: RWL21.DLL

/* WARNING: Removing unreachable block (ram,0x1002e6ae) */
/* WARNING: Removing unreachable block (ram,0x1002e7e7) */
/* WARNING: Removing unreachable block (ram,0x1002e56d) */

uint * FUN_1002e520(uint *param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *puVar6;
  uint *extraout_ECX;
  uint *extraout_ECX_00;
  undefined4 extraout_EDX;
  uint *extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 uVar7;
  float *pfVar8;
  uint *puVar9;
  float *pfVar10;
  undefined8 uVar11;
  float local_14 [5];
  
  iVar2 = FUN_1002dde0(local_14,(int)param_1,(int)param_2);
  if (iVar2 == 1) {
    uVar5 = param_1[5];
    uVar1 = param_1[6];
    puVar6 = FUN_10037030(DAT_1005adac);
    if (puVar6 == (uint *)0x0) {
      FUN_1000cba0(3);
      return (uint *)0x0;
    }
    puVar6[0x11] = 3;
    puVar6[6] = uVar1;
    puVar6[5] = uVar5;
    *puVar6 = 0;
    puVar6[4] = 0;
    pfVar8 = local_14;
    pfVar10 = (float *)(puVar6 + 0x13);
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar10 = *pfVar8;
      pfVar8 = pfVar8 + 1;
      pfVar10 = pfVar10 + 1;
    }
    puVar6[0x18] = (uint)param_2;
    puVar6[0x19] = (uint)param_1;
    param_1[5] = (uint)puVar6;
    puVar3 = extraout_EDX_00;
  }
  else {
    if (iVar2 == 2) {
      if ((*param_1 & 4) != 0) {
        puVar6 = (uint *)param_1[4];
        if (puVar6 == (uint *)0x0) {
          param_2[5] = (uint)param_1;
          param_1[4] = (uint)param_2;
        }
        else {
          if (puVar6[0x11] == 3) {
            puVar6 = FUN_1002ea90(param_2,extraout_EDX,puVar6,param_2);
          }
          else {
            puVar6 = FUN_1002e520(puVar6,param_2);
          }
          *param_2 = *param_2 | 1;
          if (puVar6 == (uint *)0x0) {
            return (uint *)0x0;
          }
          param_1[4] = (uint)puVar6;
        }
        goto LAB_1002e880;
      }
      if ((*param_2 & 4) != 0) {
        param_2[5] = param_1[5];
        param_2[4] = (uint)param_1;
        param_1[5] = (uint)param_2;
        param_1 = param_2;
        goto LAB_1002e880;
      }
      *param_2 = *param_2 | 0x10;
      puVar6 = param_2;
      if (param_1[0x11] == 1) {
        *param_1 = *param_1 | 0x10;
        uVar5 = param_1[5];
        uVar1 = param_1[6];
        puVar3 = FUN_10037030(DAT_1005adac);
        if (puVar3 != (uint *)0x0) {
          puVar3[0x11] = 2;
          puVar3[6] = uVar1;
          puVar3[5] = uVar5;
          *puVar3 = 0;
          puVar3[4] = 0;
          puVar3[0x13] = 0;
          uVar11 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(8);
          uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
          puVar4 = (undefined4 *)uVar11;
          if (puVar4 == (undefined4 *)0x0) {
            FUN_1000cba0(3);
            puVar9 = (uint *)0x0;
            FUN_10037010(DAT_1005adac,puVar3);
            puVar6 = extraout_ECX_00;
            uVar7 = extraout_EDX_02;
          }
          else {
            param_1[5] = (uint)puVar3;
            *puVar4 = param_1;
            puVar4[1] = param_2;
            puVar3[0x13] = (uint)puVar4;
            puVar3[0x12] = 2;
            puVar9 = puVar3;
          }
          goto LAB_1002e7a2;
        }
        FUN_1000cba0(3);
        param_1 = puVar3;
      }
      else {
        if (param_1[0x11] == 2) {
          uVar1 = param_1[0x12];
          puVar3 = param_1 + 0x12;
          uVar5 = uVar1 + 1;
          *puVar3 = uVar5;
          uVar11 = (**(code **)(PTR_DAT_1005b69c + 0x354))(param_1[0x13],uVar5 * 4);
          uVar7 = (undefined4)((ulonglong)uVar11 >> 0x20);
          uVar5 = (uint)uVar11;
          puVar9 = (uint *)((uVar5 == 0) - 1 & (uint)param_1);
          if (puVar9 == (uint *)0x0) {
            FUN_1000cba0(3);
            uVar5 = *puVar3;
            *puVar3 = uVar5 - 1;
            puVar6 = (uint *)(uVar5 - 1);
            uVar7 = extraout_EDX_03;
          }
          else {
            *(uint **)(uVar5 + uVar1 * 4) = param_2;
            param_1[0x13] = uVar5;
          }
        }
        else {
          FUN_1000cba0(0x65);
          puVar6 = extraout_ECX;
          uVar7 = extraout_EDX_01;
          puVar9 = (uint *)0x0;
        }
LAB_1002e7a2:
        if (puVar9 == (uint *)0x0) {
          return (uint *)0x0;
        }
        FUN_1002e8a0(puVar6,uVar7,puVar9);
        param_1 = puVar9;
      }
      if (param_1 == (uint *)0x0) {
        return (uint *)0x0;
      }
      param_2[5] = (uint)param_1;
      goto LAB_1002e880;
    }
    if (iVar2 != 3) goto LAB_1002e880;
    uVar5 = param_1[5];
    puVar3 = param_1 + 5;
    uVar1 = param_1[6];
    puVar6 = FUN_10037030(DAT_1005adac);
    if (puVar6 == (uint *)0x0) {
      FUN_1000cba0(3);
      return (uint *)0x0;
    }
    puVar6[0x11] = 3;
    puVar6[6] = uVar1;
    puVar6[5] = uVar5;
    *puVar6 = 0;
    puVar6[4] = 0;
    pfVar8 = local_14;
    pfVar10 = (float *)(puVar6 + 0x13);
    for (iVar2 = 5; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar10 = *pfVar8;
      pfVar8 = pfVar8 + 1;
      pfVar10 = pfVar10 + 1;
    }
    puVar6[0x18] = (uint)param_1;
    puVar6[0x19] = (uint)param_2;
    *puVar3 = (uint)puVar6;
  }
  FUN_1002d8b0(param_2,puVar3,puVar6,param_1,param_2);
  param_2[5] = (uint)puVar6;
  *puVar6 = *puVar6 | *param_2 & *param_1 & 4;
  param_1 = puVar6;
LAB_1002e880:
  *param_2 = *param_2 | 1;
  return param_1;
}


